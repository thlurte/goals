# Month 4 — Dec (Weeks 13–16)

> Part of the [28-week curriculum](../README.md). Research: [`research/`](../../research/README.md).

| | |
|:---|:---|
| [← Month 3 — Nov](month-03-nov.md) | [Month 5 — Jan →](month-05-jan.md) |

---

# BLOCK I (cont.): GPU VECTOR SEARCH — close the 4-month spine (Weeks 13–16)

---

# 📅 MONTH 4: Pure Probability Theory, FlashAttention Kernel & Tensor Cores (Dec 2026)

> **🔬 Empirical Systems & Benchmarking Focus**: *Multimodal Late Interaction & Baseline GPU Kernel Profiling* · folder `research/2026-12-flashattn-vamana/`

---


### 📚 Master Reference Textbooks (Month 4)
* **GPU Architecture & Programming**: David B. Kirk & Wen-mei W. Hwu, *Programming Massively Parallel Processors: A Hands-on Approach* (4th ed, Morgan Kaufmann 2022) — Ch 1–4 (CUDA Hardware Execution Model, Warps, Block Scheduling, Shared Memory Tiling).
* **High-Dimensional Probability**: Roman Vershynin, *High-Dimensional Probability* (CUP 2018) — Ch 6–8 (Non-asymptotic Random Matrix Theory, Covering Numbers, Metric Entropy, Dudley's Chaining).
* **Computer Architecture & IO**: John L. Hennessy & David A. Patterson, *Computer Architecture* (6th ed) — Ch 5 (Thread-Level Parallelism) & Brendan Gregg, *Systems Performance* (2nd ed) — Ch 7 (Memory) & Ch 9 (Disks & NVMe `io_uring`).

---

### Week 13 (Sat Nov 28 – Fri Dec 4): Axiomatic Probability, Combinatorics, CUDA Model & Naive Kernels

**Theme**: Sample spaces, probability axioms, combinatorics, and the massively parallel GPU SIMT execution model.

* **Pure Probability (Blitzstein & Hwang Ch 1–2)**:
  * Sample spaces $\Omega$, events, Kolmogorov's 3 probability axioms.
  * Combinatorics: Multiplication rule, permutations $n!$, combinations $\binom{n}{k}$, inclusion-exclusion principle.
  * Conditional probability: $P(A|B) = \frac{P(A \cap B)}{P(B)}$, Law of Total Probability $P(A) = \sum P(A|B_i) P(B_i)$, Bayes' Theorem.
  * Independence of events: $P(A \cap B) = P(A)P(B)$. Conditional independence.
* **C++ Engine (`secan`)**: CUDA CMake integration, `compute-sanitizer` memory checker harness, `GpuBuffer<T>` RAII wrapper, naive GPU L2 distance kernel.

| Day | Pure Probability (90 min) | GPU / CUDA Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Nov 30** | **PROB §1.1–1.4**: Sample spaces, events, Kolmogorov's axioms. Proof of basic probability properties ($P(A^c) = 1 - P(A)$, Boole's inequality). | **PMPP Ch 1–2**: Heterogeneous computing, SIMT execution model, latency hiding via massive hardware multithreading. | **secan**: Add CUDA to CMakeLists.txt (`enable_language(CUDA)`). Create `src/gpu/`. Configure `compute-sanitizer` test script. |
| **Tue Dec 1** | **PROB §1.5–1.6**: Combinatorics: Counting techniques, permutations, combinations $\binom{n}{k}$, binomial theorem, inclusion-exclusion principle. | **PMPP Ch 3 + 🔗 GPU NUMERIC FORMATS**: Grid/Block/Thread hierarchy. Computing linear indices. **Also**: BFloat16 vs Float16 vs TF32 bit layouts; why BF16 has same exponent range as FP32 but only 7 mantissa bits; mixed-precision training: loss scaling, master weights in FP32; when FP16 gradients underflow to zero. | **secan**: Implement RAII `GpuBuffer<T>` class for device memory allocation (`cudaMalloc`, `cudaFree`, `cudaMemcpy`). |
| **Wed Dec 2** | **PROB §2.1–2.3**: Conditional probability definition and properties. Law of Total Probability. Gambler's ruin problem. | **PMPP Ch 4**: Compute Architecture: Streaming Multiprocessors (SMs), warps (32 threads), warp divergence, occupancy. | **secan**: Implement naive GPU L2 distance kernel: 1 thread per vector pair. Benchmark against CPU AVX2 on single query. |
| **Thu Dec 3** | **PROB §2.4–2.5**: Bayes' Rule: prior and posterior probabilities. Base rate fallacy. Medical testing false positive mathematics. | **CUDA-GUIDE Memory Hierarchy**: Global memory (HBM/GDDR), Shared memory (SRAM), Registers, Constant memory. | **secan**: Implement dataset upload: store SIFT1M in GPU global memory. Implement batch brute-force scan kernel (1 block per query). |
| **Fri Dec 4** | **PROB §2.6–2.7**: Independence of events: pairwise vs mutual independence. Conditional independence. Simpson's Paradox. | **PMPP Ch 5**: Memory architecture, shared memory tiling, bank conflicts, memory coalescing principles. | **secan**: Implement **shared memory tiled** L2 kernel: load query and dataset tiles into shared memory. Benchmark tiled vs naive. |

#### 📋 Daily Action Items & Optional Activities (Week 13)
* **Mon Nov 30**:
  * `[ ]` **Core**: Configure CMake for CUDA (`enable_language(CUDA)`); set up `compute-sanitizer` automated memory checker in CI.
  * `⭐ Optional / Stretch`: Write a CMake check that validates GPU compute capability (e.g. `sm_80`, `sm_89`, `sm_90`) and enables target-specific PTX generation.
* **Tue Dec 1**:
  * `[ ]` **Core**: Implement RAII `GpuBuffer<T>` wrapper managing device memory (`cudaMalloc`, `cudaFree`, `cudaMemcpyAsync`).
  * `⭐ Optional / Stretch`: Implement CUDA pinned host memory allocator (`cudaHostAlloc`) and compare host-to-device transfer bandwidth.
* **Wed Dec 2**:
  * `[ ]` **Core**: Implement naive GPU L2 distance kernel (1 thread per vector pair); benchmark latency against single-threaded CPU AVX2.
  * `⭐ Optional / Stretch`: Profile kernel with Nsight Compute (`ncu`) to observe warp execution stalls due to memory latency.
* **Thu Dec 3**:
  * `[ ]` **Core**: Upload full SIFT1M dataset to GPU VRAM; implement batch scan kernel assigning 1 thread block per query vector.
  * `⭐ Optional / Stretch`: Measure PCIe bus upload bandwidth as a function of batch buffer size ($1\text{MB}$ to $1\text{GB}$).
* **Fri Dec 4**:
  * `[ ]` **Core**: Implement shared memory tiled L2 distance kernel loading query and dataset chunks into SRAM; measure speedup over naive kernel.
  * `⭐ Optional / Stretch`: Benchmark shared memory bank conflicts with varying tile dimension padding strategies.

#### ⛔ What NOT to Overspend Time On (Time Traps)
* ❌ **Do NOT** optimize single-query latency on GPU—GPUs require batched queries ($B \ge 32$) to hide launch and PCIe latency.
* ❌ **Do NOT** use CUDA dynamic parallelism (launching kernels from inside kernels)—keep control flow on host CPU.
* ❌ **Do NOT** hand-write complex combinatorial counting proofs on paper—master permutations and combinations, then move to probability rules.

> **📝 Essay 13 (Fri Dec 4)**: *"The SIMT Execution Model: Why Naive GPU Distance Kernels Lose to CPU AVX2"*  

---

### Week 14 (Sat Dec 5 – Fri Dec 11): Discrete Random Variables, PMF, Expectation, Variance & Warp Shuffles

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
| **Mon Dec 7** | **PROB §3.1–3.4**: Discrete random variables, PMF, CDF properties. Bernoulli and Binomial distributions: derivations of mean and variance. | **PMPP Ch 6**: Performance considerations: memory coalescing patterns, maximizing global memory bus utilization. | **secan**: Implement **coalesced GPU distance kernel**: ensure adjacent threads in a warp access consecutive memory addresses. |
| **Tue Dec 8** | **PROB §3.5–3.7**: Hypergeometric distribution, Geometric and Negative Binomial distributions. Memoryless property of Geometric distribution. | **PMPP Ch 10**: Parallel reductions, warp shuffle primitives (`__shfl_down_sync`), eliminating shared memory bank conflicts. | **secan**: Implement **warp-level reduction**: use `__shfl_down_sync` to reduce 32 partial sums inside a warp with zero shared memory overhead. |
| **Wed Dec 9** | **PROB §4.1–4.3**: Expectation from first principles. Rigorous proof of Linearity of Expectation. Solving complex counting problems with indicator variables. | **CUDA-GUIDE Warp Primitives**: `__shfl_sync`, `__shfl_xor_sync`, `__ballot_sync`, `__any_sync`, Cooperative Groups. | **secan**: Implement batched GPU scanner: process $B=256$ queries simultaneously. Each block processes a query; warps scan dataset chunks. |
| **Thu Dec 10** | **PROB §4.4–4.6**: Law of the Unconscious Statistician (LOTUS). Variance and Standard Deviation properties: $\text{Var}(aX + b) = a^2 \text{Var}(X)$. | **PMPP Ch 7**: Tiling patterns, halo cells, constant memory for read-only query parameters. | **secan**: Implement fused Cosine similarity GPU kernel: dot product + norms in a single pass. Add inner-product kernel. |
| **Fri Dec 11** | **PROB §4.7–4.9**: The Poisson Distribution $\text{Pois}(\lambda)$: Poisson limit theorem (law of rare events), derivation from $\text{Bin}(n, \lambda/n)$ as $n \to \infty$. | **PMPP Ch 11–12**: Parallel merge and sorting on GPU: partial bitonic sort, warp-cooperative top-$k$ selection. | **secan**: Implement **GPU top-k selection**: warp-cooperative partial bitonic sort extracting top-$k$ without sorting all $N$ distances. |

#### 📋 Daily Action Items & Optional Activities (Week 14)
* **Mon Dec 7**:
  * `[ ]` **Core**: Implement coalesced memory layout for database vectors in GPU global memory; achieve $>85\%$ theoretical global memory bus utilization in `ncu`.
  * `⭐ Optional / Stretch`: Compare AOS (Array-of-Structures) vs SOA (Structure-of-Arrays) memory layouts for high-dimensional vector embeddings on GPU.
* **Tue Dec 8**:
  * `[ ]` **Core**: Implement warp-level horizontal tree reduction using `__shfl_down_sync(0xffffffff, sum, offset)` in registers without shared memory.
  * `⭐ Optional / Stretch`: Benchmark latency of register warp shuffle vs shared-memory atomic reduction across varying thread block sizes.
* **Wed Dec 9**:
  * `[ ]` **Core**: Implement batched GPU scanner processing $B=256$ queries in parallel; utilize CUDA Cooperative Groups for grid synchronization.
  * `⭐ Optional / Stretch`: Implement asynchronous CUDA streams interleaving kernel execution for batch chunk $i$ with data transfer for chunk $i+1$.
* **Thu Dec 10**:
  * `[ ]` **Core**: Implement fused GPU Cosine similarity and Inner Product kernels computing dot products and norms in a single memory pass.
  * `⭐ Optional / Stretch`: Use fast math compiler flag (`--use_fast_math`) and measure reciprocal square root (`rsqrtf`) speedup vs precision impact.
* **Fri Dec 11**:
  * `[ ]` **Core**: Implement GPU warp-cooperative top-$k$ selection using partial bitonic sort; extract top-$k$ without sorting full dataset distance array.
  * `⭐ Optional / Stretch`: Benchmark top-$k$ throughput against NVIDIA CUB `BlockRadixSort` / `DeviceSegmentedRadixSort`.

#### ⛔ What NOT to Overspend Time On (Time Traps)
* ❌ **Do NOT** sort the entire 1,000,000 distances on GPU—use partial bitonic sort or warp priority queues to maintain only the top-$k$ ($k \le 100$).
* ❌ **Do NOT** use atomic operations in global memory for distance reductions—warp shuffles (`__shfl_down_sync`) in registers are zero-overhead.
* ❌ **Do NOT** implement complex thread block dynamic grid sizing—stick to 128 or 256 threads per block.

> **📝 Essay 14 (Fri Dec 11)**: *"Warp Shuffles and Parallel Reductions: Saturating GPU Memory Bandwidth in Batch Vector Scanning"*

---

### Week 15 (Sat Dec 12 – Fri Dec 18): Continuous Distributions, PDF, Gaussians & FlashAttention Scaffold

**Theme**: Continuous RVs, Gaussians, and a **correct** FlashAttention-1 **CUDA** path. Online softmax Python = **Sat Dec 13**. **FA-2 = Week 25**.

* **Implementation**:
  * **Weekdays**: CUDA FA-1 scaffold through expose.
  * **Tue/Wed**: Online Softmax reference in Python.
  * **Deferred (required Week 25)**: FA-2 loop order / Nsight.

| Day | Pure Probability & FlashAttention Math (90 min) | GPU / CUDA Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Dec 14** | **PROB §5.1–5.3**: Continuous RVs: PDF vs probability, CDF properties ($F' = f$), Uniform and Exponential. | FlashAttention paper §1–3: HBM vs SRAM cost model; why materializing $S$ is the bottleneck. | **CUDA**: FA-1 grid ($B \times H$); shared mem tiles. |
| **Tue Dec 15** | **PROB §5.4–5.5**: The Normal / Gaussian $\mathcal{N}(\mu, \sigma^2)$: PDF, standardization $Z = (X-\mu)/\sigma$. | **PMPP Ch 16 / NVIDIA Docs**: Tensor Core / WMMA overview (context for GEMM tiles). | **CUDA**: FlashAttention kernel scaffold: grid ($B \times H$), shared mem for $Q_{block}, K_{block}, V_{block}, O_{block}$. |
| **Wed Dec 16** | **PROB §6.1–6.3**: Moments, MGFs $M_X(t) = \mathbb{E}[e^{tX}]$. Finding moments via derivatives. | CUDA Shared Memory banking: avoiding bank conflicts when loading $Q, K^T$ tiles. | **CUDA**: Block GEMM $S_{ij} = Q_i K_j^T / \sqrt{d}$ in shared memory. Check tiles vs PyTorch. |
| **Thu Dec 17** | **PROB §6.4–6.5**: MGF of Normal; sums of independent Normals via MGF multiplication. | **CUDA-GUIDE Warp Primitives**: `__shfl_sync` for warp-level row max and row sum. | **CUDA**: Online Softmax update in registers: block max $\tilde{m}$, $m_{new}$, update $\ell$, rescale $O$. |
| **Fri Dec 18** | **PROB §6.6**: Gamma, Beta, Cauchy (undefined moments) — skim. | Profile with `ncu` if kernel runs; else debug correctness first. | **CUDA**: Expose FA-1 via `torch.utils.cpp_extension`. Bench vs SDPA on small shapes. FA-2 → Week 25. |

#### 📋 Daily Action Items & Optional Activities (Week 15)
* **Mon Dec 14**:
  * `[ ]` **Core**: Implement CUDA thread grid configuration for FlashAttention ($B \times H$ blocks); allocate shared memory tiles for $Q, K, V$.
  * `⭐ Optional / Stretch`: Derive the exact IO complexity reduction of FlashAttention ($O(N^2 d^2 / M)$ HBM accesses vs standard attention $O(N d + N^2)$).
* **Tue Dec 15**:
  * `[ ]` **Core**: Scaffold shared memory layout for $Q_{block}, K_{block}, V_{block}, O_{block}$; implement coalesced global-to-shared memory staging loop.
  * `⭐ Optional / Stretch`: Implement double-buffered shared memory loading (`cuda::memcpy_async` in CUDA 11+) to overlap GMEM loads with computation.
* **Wed Dec 16**:
  * `[ ]` **Core**: Implement block GEMM tile multiplication $S_{ij} = Q_i K_j^T / \sqrt{d}$ in shared memory; verify numerical parity against `torch.matmul`.
  * `⭐ Optional / Stretch`: Apply shared memory swizzling (XOR indexing) to eliminate bank conflicts during matrix transpose $K^T$ lookups.
* **Thu Dec 17**:
  * `[ ]` **Core**: Implement register online softmax algorithm: track running row max $\tilde{m}$, running normalizer $\ell$, and dynamically rescale accumulator $O$.
  * `⭐ Optional / Stretch`: Verify numerical overflow protection of online softmax on inputs containing extreme logits ($> 10^4$).
* **Fri Dec 18**:
  * `[ ]` **Core**: Package FlashAttention-1 kernel via `torch.utils.cpp_extension`; benchmark forward latency against `torch.nn.functional.scaled_dot_product_attention`.
  * `⭐ Optional / Stretch`: Profile kernel memory throughput in Nsight Compute (`ncu --metrics dram__bytes_read.sum,dram__bytes_write.sum`).

#### ⛔ What NOT to Overspend Time On (Time Traps)
* ❌ **Do NOT** implement backward pass for FlashAttention—this week is strictly forward attention execution.
* ❌ **Do NOT** attempt FlashAttention-2 loop inversion this week—FA-2 is specifically scheduled for Month 7 (Week 25).
* ❌ **Do NOT** write inline PTX for Tensor Cores (`mma.sync`)—standard FP32/FP16 shared memory arithmetic is the foundation.

> **📝 Essay 15 (Fri Dec 18)**: *"IO-Aware Tiling and Online Softmax: Constructing a FlashAttention-1 CUDA Kernel from First Principles"*  
> **🧠 DL Builder Track (Tue/Wed)**: Online softmax reference vs `torch.softmax`.

---

### Week 16 (Sat Dec 19 – Fri Dec 25): VS Spine Capstone — GPU IVF + DiskANN + Hybrid WAND

**Theme**: Close the **4-month vector-search spine**: GPU IVF (Mon–Wed), then **Week 11 DiskANN catch-up (Thu)** and **Week 10 WAND catch-up (Fri)**.

* **Pure Probability (Blitzstein & Hwang Ch 7)**: Joint distributions, covariance, correlation (same math load; afternoons are catch-up-heavy).
* **C++ Engine (`secan`)** — required landings this week:
  1. `GpuIVFIndex` + warp cell scan + stream pipeline (Mon–Wed)
  2. **Vamana prune + DiskANN `io_uring` `O_DIRECT`** (Thu)
  3. **BM25 + Block-Max WAND + RRF + linear $\alpha$** (Fri); SPLADE = stretch

| Day | Pure Probability (90 min) | Systems Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Dec 21** | **PROB §7.1–7.2**: Joint, marginal, and conditional discrete distributions. Multinomial distribution. | Faiss GPU 2019 §1–3: billion-scale GPU similarity search. | **secan**: GPU IVF memory layout: coarse centroids; cell vectors + offset table. |
| **Tue Dec 22** | **PROB §7.3–7.4**: Joint continuous distributions; marginals by integration. | Faiss GPU §4–5: GPU $k$-selection, warp-cooperative list scanning. | **secan**: GPU coarse quantizer + top-`nprobe` cell select; warp-cooperative cell scan. |
| **Wed Dec 23** | **PROB §7.5**: 2D change of variables / Jacobian; Box-Muller. | **CUDA-GUIDE Streams & Events**. | **secan**: CUDA stream pipelining for IVF batches; quick SQ8-in-cell stretch if time. Tag `v1.1-gpu-ivf`. |
| **Thu Dec 24** | **PROB §7.6–7.7**: Covariance and Correlation; Cauchy-Schwarz bound on $\rho$. | DiskANN: **Vamana graph construction** (α-prune) + `io_uring` fetch. | **secan (required)**: Implement **Vamana prune** (build graph, not only SSD fetch); compressed vectors in RAM; FP32 via `io_uring`. Recall vs in-RAM. |
| **Fri Dec 25** | **PROB §7.8**: Multivariate Normal $\mathcal{N}(\boldsymbol{\mu}, \boldsymbol{\Sigma})$. | Ding & Suel WAND; **RRF** (Cormack et al.). | **secan (required)**: BM25 + Block-Max WAND; fuse via **RRF** *and* linear $\alpha$. Query-time $\alpha$ / k sweep. SPLADE = stretch. Tag `v1.2-vs-spine-complete`. |

#### 📋 Daily Action Items & Optional Activities (Week 16)
* **Mon Dec 21**:
  * `[ ]` **Core**: Implement GPU IVF memory layout: store coarse centroids and jagged inverted list arrays with prefix sum offset table in device memory.
  * `⭐ Optional / Stretch`: Implement zero-copy unified memory (`cudaMallocManaged`) coarse centroid lookup.
* **Tue Dec 22**:
  * `[ ]` **Core**: Implement GPU coarse cell routing kernel finding top-`nprobe` nearest centroids followed by warp-cooperative inverted list scanning.
  * `⭐ Optional / Stretch`: Profile warp divergence when inverted lists have non-uniform lengths; implement dynamic warp-balancing scheduler.
* **Wed Dec 23**:
  * `[ ]` **Core**: Implement CUDA stream pipelining overlapping query upload, cell scan, and top-$k$ download. Tag `v1.1-gpu-ivf`.
  * `⭐ Optional / Stretch`: Implement SQ8 integer quantization inside GPU IVF lists to double effective VRAM vector capacity.
* **Thu Dec 24**:
  * `[ ]` **Core**: Implement Vamana graph construction ($\alpha$-pruning heuristic); implement asynchronous out-of-core SSD vector fetch via Linux `io_uring` with `O_DIRECT`.
  * `⭐ Optional / Stretch`: Benchmark random NVMe read IOPS and latency under varying `io_uring` queue depths ($QD \in [1, 128]$).
* **Fri Dec 25**:
  * `[ ]` **Core**: Implement BM25 inverted index + Block-Max WAND early termination; fuse dense ANN candidates with sparse BM25 scores via Reciprocal Rank Fusion (RRF). Tag `v1.2-vs-spine-complete`.
  * `⭐ Optional / Stretch`: Compare retrieval quality (NDCG@10) of RRF rank fusion vs linear weighted score interpolation ($\alpha \cdot S_{\text{dense}} + (1-\alpha) \cdot S_{\text{sparse}}$).

#### ⛔ What NOT to Overspend Time On (Time Traps)
* ❌ **Do NOT** implement SPLADE sparse neural models—BM25 + Block-Max WAND is the required sparse baseline.
* ❌ **Do NOT** run multi-billion scale benchmarks—DiskANN on a 1M to 10M vector subset proves out-of-core `io_uring` execution.
* ❌ **Do NOT** build complex C++ REST server wrappers—keep `secan` exposed via `nanobind` and CLI.

> **📝 Essay 16 (Fri Dec 25)**: *"Closing the Vector Search Spine: GPU IVF Streaming, Vamana Graph Pruning, and Out-of-Core `io_uring`"*
> **🚀 Month 4 Builder Milestone (Fri Dec 25)**: End-to-end FlashAttention & Vamana GPU kernel benchmark verification.

---

---
