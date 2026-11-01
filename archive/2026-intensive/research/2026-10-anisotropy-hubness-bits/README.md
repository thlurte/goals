# 🔬 Anisotropy-Aware Vector Quantization: Embedding Cones, Hubness, and Quantization Loss Functions

> **Research Track**: Day 034 (Week 05) — Deep Systems & Neural Embedding Geometry  
> **Target Focus**: Dissecting the interplay between anisotropic embedding cones, hubness skewness ($N_k$), and scalar/rotated quantization loss.

---

## 📌 Executive Summary & Hypothesis Testing

### 1. Falsifiable Hypothesis ($H_1$)
> **Hypothesis $H_1$**: Real-world neural embeddings (e.g., CLIP, OpenAI text-embedding, Llama attention representations) exhibit severe directional anisotropy and power-law spectral decay, concentrating $>75\%$ of variance in top-10 principal components. This creates severe **hubness asymmetry** (where $1\%$ of vectors appear in $>100\times$ more top-$k$ candidate sets than expected), causing naive isotropic scalar quantizers to waste dynamic range on degenerate low-variance dimensions.

---

## 📊 Quantitative Benchmark Results

From our benchmark sweep across $N=25,000$ 128-dimensional vectors:

| Distribution Configuration | Mean Pairwise Cosine $\mathbb{E}[\cos(\mathbf{x}_i, \mathbf{x}_j)]$ | Top-10 SVD Energy Ratio $\sum_{i=1}^{10} \sigma_i^2 / \sum \sigma^2$ | Hubness Skewness ($S_{N_{10}}$) | Max Hub Appearance Frequency | SQ8 Baseline MSE | SQ4 Baseline MSE |
|:---|:---:|:---:|:---:|:---:|:---:|:---:|
| **Isotropic Baseline** | $+0.0002 \pm 0.088$ | **$8.77\%$** | $0.300$ | $23\times$ | $1.00 \times 10^{-6}$ | $1.22 \times 10^{-4}$ |
| **Moderate Anisotropy ($\lambda=0.03$)** | $+0.0130 \pm 0.170$ | **$43.60\%$** | $0.942$ | $42\times$ | $5.00 \times 10^{-6}$ | $4.60 \times 10^{-4}$ |
| **Severe Neural Cone ($\lambda=0.08$)** | **$+0.1974 \pm 0.267$** | **$76.32\%$** | **$1.628$** | **$64\times$** | $9.00 \times 10^{-6}$ | $5.56 \times 10^{-4}$ |
| **Power-Law Spectrum (Transformer)** | $+0.0074 \pm 0.362$ | **$76.01\%$** | **$2.515$** | **$107\times$** | $8.00 \times 10^{-6}$ | $1.28 \times 10^{-3}$ |

---

## 📈 Visualizations & Empirical Plots

![Anisotropy Hubness Analysis](plots/anisotropy_hubness_analysis.png)

### Key Insights from the Plots:
1. **Embedding Cone Emergence**: In neural embeddings, the variance decays exponentially. In power-law transformer representations, top-10 dimensions carry **$76.01\%$** of the entire representational energy.
2. **The Hubness Trap**: Under high dimensionality and power-law spectra, certain central "hub" vectors appear in the top-10 neighbors of **107 different queries** (a $10.7\times$ skew over random expectation).
3. **Implications for Quantization in `secan`**:
   - Uniform global scalar quantization on anisotropic embeddings results in unequal noise distribution: low-variance dimensions suffer large relative quantization noise.
   - For high-recall 4-bit quantization (`SQ4`), covariance-alignment or subspace bit-allocation provides higher fidelity for dominant dimensions.

---

## 🛠️ Reproduction & Scripts

```bash
# 1. Run the benchmark sweep
python3 scripts/measure_anisotropy.py --out-dir results/

# 2. Generate publication-quality visualization
python3 scripts/plot_anisotropy.py
```
