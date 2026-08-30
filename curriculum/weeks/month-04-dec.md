# Month 4 — Dec (Weeks 13–16)

> Part of the [28-week curriculum](../README.md). Research: [`research/`](../../research/README.md).

| | |
|:---|:---|
| [← Month 3 — Nov](month-03-nov.md) | [Month 5 — Jan →](month-05-jan.md) |

---

# BLOCK I (cont.): GPU VECTOR SEARCH — close the 4-month spine (Weeks 13–16)

---

# 📅 MONTH 4: Pure Probability Theory, FlashAttention Kernel & Tensor Cores (Dec 2026)

> **🔬 Monthly research**: *One Engine, Three Paths: GPU IVF, DiskANN `io_uring`, and Hybrid Block-Max WAND* → publish **Sun Dec 27** · folder `research/2026-12-three-paths-spine/`

---

### Week 13 (Nov 24–28): Axiomatic Probability, Combinatorics, CUDA Model & Naive Kernels

**Theme**: Sample spaces, probability axioms, combinatorics, and the massively parallel GPU SIMT execution model.

* **Pure Probability (Blitzstein & Hwang Ch 1–2)**:
  * Sample spaces $\Omega$, events, Kolmogorov's 3 probability axioms.
  * Combinatorics: Multiplication rule, permutations $n!$, combinations $\binom{n}{k}$, inclusion-exclusion principle.
  * Conditional probability: $P(A|B) = \frac{P(A \cap B)}{P(B)}$, Law of Total Probability $P(A) = \sum P(A|B_i) P(B_i)$, Bayes' Theorem.
  * Independence of events: $P(A \cap B) = P(A)P(B)$. Conditional independence.
* **C++ Engine (`secan`)**: CUDA CMake integration, `compute-sanitizer` memory checker harness, `GpuBuffer<T>` RAII wrapper, naive GPU L2 distance kernel.

| Day | Pure Probability (90 min) | GPU / CUDA Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Nov 24** | **PROB §1.1–1.4**: Sample spaces, events, Kolmogorov's axioms. Proof of basic probability properties ($P(A^c) = 1 - P(A)$, Boole's inequality). | **PMPP Ch 1–2**: Heterogeneous computing, SIMT execution model, latency hiding via massive hardware multithreading. | **secan**: Add CUDA to CMakeLists.txt (`enable_language(CUDA)`). Create `src/gpu/`. Configure `compute-sanitizer` test script. |
| **Tue Nov 25** | **PROB §1.5–1.6**: Combinatorics: Counting techniques, permutations, combinations $\binom{n}{k}$, binomial theorem, inclusion-exclusion principle. | **PMPP Ch 3**: Grid, Block, Thread hierarchy. Computing linear memory indices from `threadIdx`, `blockIdx`, `blockDim`. | **secan**: Implement RAII `GpuBuffer<T>` class for device memory allocation (`cudaMalloc`, `cudaFree`, `cudaMemcpy`). |
| **Wed Nov 26** | **PROB §2.1–2.3**: Conditional probability definition and properties. Law of Total Probability. Gambler's ruin problem. | **PMPP Ch 4**: Compute Architecture: Streaming Multiprocessors (SMs), warps (32 threads), warp divergence, occupancy. | **secan**: Implement naive GPU L2 distance kernel: 1 thread per vector pair. Benchmark against CPU AVX2 on single query. |
| **Thu Nov 27** | **PROB §2.4–2.5**: Bayes' Rule: prior and posterior probabilities. Base rate fallacy. Medical testing false positive mathematics. | **CUDA-GUIDE Memory Hierarchy**: Global memory (HBM/GDDR), Shared memory (SRAM), Registers, Constant memory. | **secan**: Implement dataset upload: store SIFT1M in GPU global memory. Implement batch brute-force scan kernel (1 block per query). |
| **Fri Nov 28** | **PROB §2.6–2.7**: Independence of events: pairwise vs mutual independence. Conditional independence. Simpson's Paradox. | **PMPP Ch 5**: Memory architecture, shared memory tiling, bank conflicts, memory coalescing principles. | **secan**: Implement **shared memory tiled** L2 kernel: load query and dataset tiles into shared memory. Benchmark tiled vs naive. |

> **📝 Essay 13 (Sat Nov 29)**: *"GPU Architecture for Vector Search: Why Naive CUDA Kernels Lose to CPU AVX2"*  
> **🚀 Month 3 research PUBLISH (Sun Nov 29)**: freeze `research/2026-11-late-interaction-lsm/paper.md` + public post.

---

### Week 14 (Dec 1–5): Discrete Random Variables, PMF, Expectation, Variance & Warp Shuffles

**Theme**: Discrete random variables, expectation, variance, discrete distributions, and CUDA warp-level reductions.

* **Pure Probability (Blitzstein & Hwang Ch 3–4)**:
  * Random variables $X: \Omega \to \mathbb{R}$, Probability Mass Functions (PMF) $p_X(x)$, Cumulative Distribution Functions (CDF) $F_X(x)$.
  * Expectation $\mathbb{E}[X] = \sum x p(x)$, Linearity of Expectation $\mathbb{E}[aX + bY] = a\mathbb{E}[X] + b\mathbb{E}[Y]$.
  * Law of the Unconscious Statistician (LOTUS): $\mathbb{E}[g(X)] = \sum g(x) p(x)$.
  * Variance $\text{Var}(X) = \mathbb{E}[(X - \mu)^2] = \mathbb{E}[X^2] - (\mathbb{E}[X])^2$, Standard Deviation.
  * Standard Discrete Distributions: Bernoulli, Binomial $\text{Bin}(n, p)$, Geometric $\text{Geom}(p)$, Poisson $\text{Pois}(\lambda)$, Hypergeometric.
* **C++ Engine (`secan`)**: Coalesced GPU distance kernel, warp shuffle reductions (`__shfl_down_sync`), GPU top-$k$ selection using partial bitonic sort.

| Day | Pure Probability (90 min) | GPU / CUDA Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Dec 1** | **PROB §3.1–3.4**: Discrete random variables, PMF, CDF properties. Bernoulli and Binomial distributions: derivations of mean and variance. | **PMPP Ch 6**: Performance considerations: memory coalescing patterns, maximizing global memory bus utilization. | **secan**: Implement **coalesced GPU distance kernel**: ensure adjacent threads in a warp access consecutive memory addresses. |
| **Tue Dec 2** | **PROB §3.5–3.7**: Hypergeometric distribution, Geometric and Negative Binomial distributions. Memoryless property of Geometric distribution. | **PMPP Ch 10**: Parallel reductions, warp shuffle primitives (`__shfl_down_sync`), eliminating shared memory bank conflicts. | **secan**: Implement **warp-level reduction**: use `__shfl_down_sync` to reduce 32 partial sums inside a warp with zero shared memory overhead. |
| **Wed Dec 3** | **PROB §4.1–4.3**: Expectation from first principles. Rigorous proof of Linearity of Expectation. Solving complex counting problems with indicator variables. | **CUDA-GUIDE Warp Primitives**: `__shfl_sync`, `__shfl_xor_sync`, `__ballot_sync`, `__any_sync`, Cooperative Groups. | **secan**: Implement batched GPU scanner: process $B=256$ queries simultaneously. Each block processes a query; warps scan dataset chunks. |
| **Thu Dec 4** | **PROB §4.4–4.6**: Law of the Unconscious Statistician (LOTUS). Variance and Standard Deviation properties: $\text{Var}(aX + b) = a^2 \text{Var}(X)$. | **PMPP Ch 7**: Tiling patterns, halo cells, constant memory for read-only query parameters. | **secan**: Implement fused Cosine similarity GPU kernel: dot product + norms in a single pass. Add inner-product kernel. |
| **Fri Dec 5** | **PROB §4.7–4.9**: The Poisson Distribution $\text{Pois}(\lambda)$: Poisson limit theorem (law of rare events), derivation from $\text{Bin}(n, \lambda/n)$ as $n \to \infty$. | **PMPP Ch 11–12**: Parallel merge and sorting on GPU: partial bitonic sort, warp-cooperative top-$k$ selection. | **secan**: Implement **GPU top-k selection**: warp-cooperative partial bitonic sort extracting top-$k$ without sorting all $N$ distances. |

> **📝 Essay 14 (Sat Dec 6)**: *"Warp Shuffles and Memory Coalescing: Saturating GPU Memory Bandwidth in Vector Search"*

---

### Week 15 (Dec 8–12): Continuous Distributions, PDF, Gaussians & FlashAttention Scaffold

**Theme**: Continuous RVs, Gaussians, and a **correct** FlashAttention-1 **CUDA** path. Online softmax Python = **Sat Dec 13**. **FA-2 = Week 25**.

* **Implementation**:
  * **Weekdays**: CUDA FA-1 scaffold through expose.
  * **Sat Dec 13**: Online Softmax in Python.
  * **Deferred (required Week 25)**: FA-2 loop order / Nsight.

| Day | Pure Probability & FlashAttention Math (90 min) | GPU / CUDA Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Dec 8** | **PROB §5.1–5.3**: Continuous RVs: PDF vs probability, CDF properties ($F' = f$), Uniform and Exponential. | FlashAttention paper §1–3: HBM vs SRAM cost model; why materializing $S$ is the bottleneck. | **CUDA**: FA-1 grid ($B \times H$); shared mem tiles. *(Online softmax Python: Sat Dec 13.)* |
| **Tue Dec 9** | **PROB §5.4–5.5**: The Normal / Gaussian $\mathcal{N}(\mu, \sigma^2)$: PDF, standardization $Z = (X-\mu)/\sigma$. | **PMPP Ch 16 / NVIDIA Docs**: Tensor Core / WMMA overview (context for GEMM tiles). | **CUDA**: FlashAttention kernel scaffold: grid ($B \times H$), shared mem for $Q_{block}, K_{block}, V_{block}, O_{block}$. |
| **Wed Dec 10** | **PROB §6.1–6.3**: Moments, MGFs $M_X(t) = \mathbb{E}[e^{tX}]$. Finding moments via derivatives. | CUDA Shared Memory banking: avoiding bank conflicts when loading $Q, K^T$ tiles. | **CUDA**: Block GEMM $S_{ij} = Q_i K_j^T / \sqrt{d}$ in shared memory. Check tiles vs PyTorch. |
| **Thu Dec 11** | **PROB §6.4–6.5**: MGF of Normal; sums of independent Normals via MGF multiplication. | **CUDA-GUIDE Warp Primitives**: `__shfl_sync` for warp-level row max and row sum. | **CUDA**: Online Softmax update in registers: block max $\tilde{m}$, $m_{new}$, update $\ell$, rescale $O$. |
| **Fri Dec 12** | **PROB §6.6**: Gamma, Beta, Cauchy (undefined moments) — skim. | Profile with `ncu` if kernel runs; else debug correctness first. | **CUDA**: Expose FA-1 via `torch.utils.cpp_extension`. Bench vs SDPA on small shapes. FA-2 → Week 25. |

> **📝 Essay 15 (Sat Dec 13)**: *"Building FlashAttention from Scratch in CUDA: IO-Aware Tiling and Online Softmax"*  
> **🧠 DL weekend**: Online softmax reference vs `torch.softmax`.

---

### Week 16 (Dec 15–19): VS Spine Capstone — GPU IVF + DiskANN + Hybrid WAND

**Theme**: Close the **4-month vector-search spine**: GPU IVF (Mon–Wed), then **Week 11 DiskANN catch-up (Thu)** and **Week 10 WAND catch-up (Fri)**.

* **Pure Probability (Blitzstein & Hwang Ch 7)**: Joint distributions, covariance, correlation (same math load; afternoons are catch-up-heavy).
* **C++ Engine (`secan`)** — required landings this week:
  1. `GpuIVFIndex` + warp cell scan + stream pipeline (Mon–Wed)
  2. **Vamana prune + DiskANN `io_uring` `O_DIRECT`** (Thu)
  3. **BM25 + Block-Max WAND + RRF + linear $\alpha$** (Fri); SPLADE = stretch

| Day | Pure Probability (90 min) | Systems Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Dec 15** | **PROB §7.1–7.2**: Joint, marginal, and conditional discrete distributions. Multinomial distribution. | Faiss GPU 2019 §1–3: billion-scale GPU similarity search. | **secan**: GPU IVF memory layout: coarse centroids; cell vectors + offset table. |
| **Tue Dec 16** | **PROB §7.3–7.4**: Joint continuous distributions; marginals by integration. | Faiss GPU §4–5: GPU $k$-selection, warp-cooperative list scanning. | **secan**: GPU coarse quantizer + top-`nprobe` cell select; warp-cooperative cell scan. |
| **Wed Dec 17** | **PROB §7.5**: 2D change of variables / Jacobian; Box-Muller. | **CUDA-GUIDE Streams & Events**. | **secan**: CUDA stream pipelining for IVF batches; quick SQ8-in-cell stretch if time. Tag `v1.1-gpu-ivf`. |
| **Thu Dec 18** | **PROB §7.6–7.7**: Covariance and Correlation; Cauchy-Schwarz bound on $\rho$. | DiskANN: **Vamana graph construction** (α-prune) + `io_uring` fetch. | **secan (required)**: Implement **Vamana prune** (build graph, not only SSD fetch); compressed vectors in RAM; FP32 via `io_uring`. Recall vs in-RAM. |
| **Fri Dec 19** | **PROB §7.8**: Multivariate Normal $\mathcal{N}(\boldsymbol{\mu}, \boldsymbol{\Sigma})$. | Ding & Suel WAND; **RRF** (Cormack et al.). | **secan (required)**: BM25 + Block-Max WAND; fuse via **RRF** *and* linear $\alpha$. Query-time $\alpha$ / k sweep. SPLADE = stretch. Tag `v1.2-vs-spine-complete`. |

> **📝 Essay 16 (Sat Dec 20)**: *"Closing the Vector Search Spine: GPU IVF, Vamana/DiskANN, and Hybrid RRF/WAND"*

---
