#!/usr/bin/env python3
"""
Plotting Script for Anisotropy, Hubness & Quantization Loss Study
"""

import os
import json
import matplotlib.pyplot as plt
import numpy as np

def main():
    json_path = "/home/ahmed/personal/goals/research/2026-10-anisotropy-hubness-bits/results/anisotropy_benchmark.json"
    plot_dir = "/home/ahmed/personal/goals/research/2026-10-anisotropy-hubness-bits/plots"
    os.makedirs(plot_dir, exist_ok=True)
    
    if not os.path.exists(json_path):
        print(f"Error: {json_path} not found. Run measure_anisotropy.py first.")
        return

    with open(json_path, "r") as f:
        data = json.load(f)

    # Styling
    plt.style.use("seaborn-v0_8-whitegrid" if "seaborn-v0_8-whitegrid" in plt.style.available else "default")
    fig, axes = plt.subplots(2, 2, figsize=(14, 10))
    fig.suptitle("Anisotropy-Aware Vector Quantization: Embedding Cones, Hubness & Distortion", fontsize=15, fontweight="bold")

    datasets = list(data.keys())
    colors = ["#2b5c8f", "#d95f02", "#7570b3", "#e7298a"]

    # 1. Top-10 SVD Variance Explained vs Mean Pairwise Cosine
    ax1 = axes[0, 0]
    cosines = [data[k]["mean_pairwise_cosine"] for k in datasets]
    svd_ratios = [data[k]["top10_singular_variance_ratio"] * 100 for k in datasets]
    bars = ax1.bar(range(len(datasets)), svd_ratios, color=colors, alpha=0.85, edgecolor="black", width=0.55)
    ax1.set_xticks(range(len(datasets)))
    ax1.set_xticklabels([k.split("(")[0].strip() for k in datasets], rotation=15, ha="right", fontsize=9)
    ax1.set_ylabel("Top-10 SVD Variance Explained (%)", fontsize=11, fontweight="bold")
    ax1.set_title("1. Embedding Cone Concentration (Spectral Decay)", fontsize=12, fontweight="bold")
    ax1.set_ylim(0, 100)
    for bar, cos in zip(bars, cosines):
        yval = bar.get_height()
        ax1.text(bar.get_x() + bar.get_width()/2.0, yval + 2, f"{yval:.1f}%\n(cos={cos:+.2f})", ha="center", va="bottom", fontsize=8, fontweight="bold")

    # 2. Singular Value Spectrum Decay
    ax2 = axes[0, 1]
    for i, (k, col) in enumerate(zip(datasets, colors)):
        sv = data[k]["singular_values_sample"]
        ax2.plot(range(1, len(sv) + 1), sv, marker="o", markersize=4, label=k.split("(")[0].strip(), color=col, linewidth=2)
    ax2.set_xlabel("Singular Value Rank $i$", fontsize=11, fontweight="bold")
    ax2.set_ylabel("Singular Value $\\sigma_i$", fontsize=11, fontweight="bold")
    ax2.set_title("2. Singular Value Spectrum (Energy Concentration)", fontsize=12, fontweight="bold")
    ax2.set_yscale("log")
    ax2.legend(fontsize=9, loc="upper right")

    # 3. Hubness Skewness Comparison
    ax3 = axes[1, 0]
    skewness = [data[k]["hubness_skewness"] for k in datasets]
    max_hubs = [data[k]["max_hub_occurrences"] for k in datasets]
    bars3 = ax3.bar(range(len(datasets)), skewness, color=colors, alpha=0.85, edgecolor="black", width=0.55)
    ax3.set_xticks(range(len(datasets)))
    ax3.set_xticklabels([k.split("(")[0].strip() for k in datasets], rotation=15, ha="right", fontsize=9)
    ax3.set_ylabel("Hubness Skewness $S_{N_k}$", fontsize=11, fontweight="bold")
    ax3.set_title("3. Nearest Neighbor Asymmetry (Hubness Skewness)", fontsize=12, fontweight="bold")
    for bar, mh in zip(bars3, max_hubs):
        yval = bar.get_height()
        ax3.text(bar.get_x() + bar.get_width()/2.0, yval + 0.1, f"Skew={yval:.2f}\n(Max {mh}x)", ha="center", va="bottom", fontsize=8, fontweight="bold")

    # 4. Quantization MSE: Standard SQ vs PCA-Rotated SQ
    ax4 = axes[1, 1]
    x_indices = np.arange(len(datasets))
    width = 0.35
    
    sq8_reductions = [data[k]["quantization"]["sq8_mse_reduction_pct"] for k in datasets]
    sq4_reductions = [data[k]["quantization"]["sq4_mse_reduction_pct"] for k in datasets]
    
    b1 = ax4.bar(x_indices - width/2, sq8_reductions, width, label="SQ8 (8-bit) Gain", color="#1b9e77", edgecolor="black")
    b2 = ax4.bar(x_indices + width/2, sq4_reductions, width, label="SQ4 (4-bit) Gain", color="#d95f02", edgecolor="black")
    
    ax4.set_xticks(x_indices)
    ax4.set_xticklabels([k.split("(")[0].strip() for k in datasets], rotation=15, ha="right", fontsize=9)
    ax4.set_ylabel("MSE Reduction via Covariance Alignment (%)", fontsize=11, fontweight="bold")
    ax4.set_title("4. Quantization Gain from Rotation (Hypothesis $H_1$)", fontsize=12, fontweight="bold")
    ax4.axhline(0, color="gray", linestyle="--", linewidth=1)
    ax4.legend(fontsize=9, loc="upper left")
    
    for bar in list(b1) + list(b2):
        yval = bar.get_height()
        if abs(yval) > 0.5:
            ax4.text(bar.get_x() + bar.get_width()/2.0, yval + (0.5 if yval > 0 else -1.5), f"{yval:+.1f}%", ha="center", va="bottom", fontsize=8, fontweight="bold")

    plt.tight_layout()
    plot_file = os.path.join(plot_dir, "anisotropy_hubness_analysis.png")
    plt.savefig(plot_file, dpi=300)
    plt.close()
    print(f"📊 Visualization plot successfully generated at: {plot_file}")

if __name__ == "__main__":
    main()
