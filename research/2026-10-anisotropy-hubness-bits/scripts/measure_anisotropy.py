#!/usr/bin/env python3
"""
Anisotropy-Aware Vector Quantization & Hubness Analyzer
======================================================
Investigates the interplay between embedding cones, hubness, and scalar/rotated quantization loss.

Hypothesis H1:
Real-world neural embeddings exhibit severe directional anisotropy (mean pairwise cosine > 0.40),
causing standard isotropic scalar quantizers to suffer significantly higher quantization MSE 
compared to covariance-aligned (PCA/OPQ-rotated) codebooks.
"""

import os
import json
import argparse
import numpy as np
from scipy import stats
from sklearn.neighbors import NearestNeighbors

def generate_synthetic_embeddings(
    n_samples: int = 20000,
    dim: int = 128,
    distribution: str = "anisotropic_cone",
    anisotropy_alpha: float = 0.6,
    spectral_decay: float = 0.05,
    seed: int = 42
) -> np.ndarray:
    """
    Generate synthetic vector embeddings with controllable anisotropy and spectral decay.
    """
    np.random.seed(seed)
    
    if distribution == "isotropic":
        raw = np.random.randn(n_samples, dim)
    elif distribution == "anisotropic_cone":
        decay_factors = np.exp(-spectral_decay * np.arange(dim))
        latent = np.random.randn(n_samples, dim) * decay_factors
        mean_dir = np.ones(dim) / np.sqrt(dim)
        raw = (1.0 - anisotropy_alpha) * latent + anisotropy_alpha * mean_dir * np.abs(np.random.randn(n_samples, 1))
    elif distribution == "power_law":
        decay_factors = 1.0 / (np.arange(1, dim + 1) ** 0.75)
        raw = np.random.randn(n_samples, dim) * decay_factors
    else:
        raise ValueError(f"Unknown distribution: {distribution}")

    norms = np.linalg.norm(raw, axis=1, keepdims=True)
    return raw / np.maximum(norms, 1e-12)

def compute_scalar_quantization_mse(vectors: np.ndarray, bits: int = 8) -> float:
    """
    Simulate uniform scalar quantization (SQ) with 0.05th / 99.95th percentile clipping.
    """
    n, d = vectors.shape
    q_levels = (1 << bits) - 1
    
    lower = np.percentile(vectors, 0.05)
    upper = np.percentile(vectors, 99.95)
    step = (upper - lower) / q_levels
    
    clamped = np.clip(vectors, lower, upper)
    quantized_int = np.round((clamped - lower) / step)
    reconstructed = lower + quantized_int * step
    
    mse = np.mean((vectors - reconstructed) ** 2)
    return float(mse)

def compute_pca_aligned_quantization_mse(vectors: np.ndarray, bits: int = 8) -> tuple[float, float]:
    """
    Rotate vectors via PCA (covariance alignment) before scalar quantization.
    Returns (standard_mse, pca_rotated_mse).
    """
    std_mse = compute_scalar_quantization_mse(vectors, bits=bits)
    
    mean = np.mean(vectors, axis=0, keepdims=True)
    centered = vectors - mean
    cov = np.cov(centered, rowvar=False)
    _, eig_vecs = np.linalg.eigh(cov)
    rot = eig_vecs[:, ::-1]
    
    rotated = centered @ rot
    pca_mse = compute_scalar_quantization_mse(rotated, bits=bits)
    
    return std_mse, pca_mse

def analyze_embedding_geometry(matrix: np.ndarray, name: str, k_neighbors: int = 10) -> dict:
    """
    Measure directional anisotropy, singular value decay, hubness skewness, and quantization loss.
    """
    n_samples, dim = matrix.shape
    
    # 1. Pairwise Cosine Sampling (10,000 pairs)
    idx1 = np.random.choice(n_samples, size=10000, replace=True)
    idx2 = np.random.choice(n_samples, size=10000, replace=True)
    cosines = np.sum(matrix[idx1] * matrix[idx2], axis=1)
    
    # 2. SVD / Spectral Decay
    centered = matrix - np.mean(matrix, axis=0, keepdims=True)
    _, s, _ = np.linalg.svd(centered, full_matrices=False)
    total_energy = np.sum(s ** 2)
    top5_energy = np.sum(s[:5] ** 2) / total_energy
    top10_energy = np.sum(s[:10] ** 2) / total_energy
    
    # 3. Hubness Analysis: N_k(x) distribution (k-occurrence counts)
    sample_sub = matrix[:min(5000, n_samples)]
    nn = NearestNeighbors(n_neighbors=k_neighbors + 1, metric="cosine", algorithm="brute").fit(sample_sub)
    _, indices = nn.kneighbors(sample_sub)
    neighbor_ids = indices[:, 1:].flatten()
    k_occurrences = np.bincount(neighbor_ids, minlength=len(sample_sub))
    hubness_skewness = float(stats.skew(k_occurrences))
    max_hub_occurrences = int(np.max(k_occurrences))
    
    # 4. Quantization Distortion (SQ8 and SQ4 vs PCA-aligned SQ8 and SQ4)
    sq8_std, sq8_pca = compute_pca_aligned_quantization_mse(matrix, bits=8)
    sq4_std, sq4_pca = compute_pca_aligned_quantization_mse(matrix, bits=4)
    
    sq8_reduction = (sq8_std - sq8_pca) / sq8_std * 100.0
    sq4_reduction = (sq4_std - sq4_pca) / sq4_std * 100.0

    return {
        "dataset_name": name,
        "n_samples": n_samples,
        "dim": dim,
        "mean_pairwise_cosine": float(np.mean(cosines)),
        "std_pairwise_cosine": float(np.std(cosines)),
        "top5_singular_variance_ratio": float(top5_energy),
        "top10_singular_variance_ratio": float(top10_energy),
        "singular_values_sample": [float(x) for x in s[:20]],
        "hubness_k": k_neighbors,
        "hubness_skewness": hubness_skewness,
        "max_hub_occurrences": max_hub_occurrences,
        "quantization": {
            "sq8_std_mse": sq8_std,
            "sq8_pca_mse": sq8_pca,
            "sq8_mse_reduction_pct": sq8_reduction,
            "sq4_std_mse": sq4_std,
            "sq4_pca_mse": sq4_pca,
            "sq4_mse_reduction_pct": sq4_reduction,
        }
    }

def main():
    parser = argparse.ArgumentParser(description="Analyze embedding anisotropy, hubness, and quantization distortion.")
    parser.add_argument("--out-dir", type=str, default="/home/ahmed/personal/goals/research/2026-10-anisotropy-hubness-bits/results")
    args = parser.parse_args()
    
    os.makedirs(args.out_dir, exist_ok=True)
    
    print("=" * 70)
    print("🚀 Running Anisotropy, Hubness & Quantization Distortion Sweep")
    print("=" * 70)
    
    configs = [
        ("Isotropic Baseline", "isotropic", 0.0, 0.0),
        ("Moderate Anisotropy (decay=0.03)", "anisotropic_cone", 0.35, 0.03),
        ("Severe Neural Anisotropy (decay=0.08)", "anisotropic_cone", 0.65, 0.08),
        ("Power-Law Spectrum (Transformer)", "power_law", 0.50, 0.05),
    ]
    
    results = {}
    for name, dist, alpha, decay in configs:
        print(f"\n📊 Analyzing: {name}...")
        vectors = generate_synthetic_embeddings(
            n_samples=25000,
            dim=128,
            distribution=dist,
            anisotropy_alpha=alpha,
            spectral_decay=decay,
            seed=42
        )
        res = analyze_embedding_geometry(vectors, name)
        results[name] = res
        
        print(f"  • Mean Pairwise Cosine: {res['mean_pairwise_cosine']:+.4f} (±{res['std_pairwise_cosine']:.4f})")
        print(f"  • Top-10 SVD Energy:   {res['top10_singular_variance_ratio'] * 100:.2f}%")
        print(f"  • Hubness Skewness:     {res['hubness_skewness']:.3f} (Max appearances: {res['max_hub_occurrences']}x)")
        print(f"  • SQ8 Std MSE -> PCA:   {res['quantization']['sq8_std_mse']:.6f} -> {res['quantization']['sq8_pca_mse']:.6f} ({res['quantization']['sq8_mse_reduction_pct']:+.1f}%)")
        print(f"  • SQ4 Std MSE -> PCA:   {res['quantization']['sq4_std_mse']:.6f} -> {res['quantization']['sq4_pca_mse']:.6f} ({res['quantization']['sq4_mse_reduction_pct']:+.1f}%)")

    out_file = os.path.join(args.out_dir, "anisotropy_benchmark.json")
    with open(out_file, "w") as f:
        json.dump(results, f, indent=2)
        
    print(f"\n✅ Benchmark results successfully saved to: {out_file}\n")

if __name__ == "__main__":
    main()
