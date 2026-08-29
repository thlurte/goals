# Vector Search Engine & AI Systems: 24-Week Master Curriculum (Architect & Systems Edition)

**Start Date**: Monday, September 1, 2026  
**End Date**: Friday, February 19, 2027  
**Schedule**: 5 Days/Week (Mon–Fri), Weekends for Reflection, Overflow & Essay Writing  
**Approach**: *"Take it slow, but go extremely deep."*

---

## 🏛️ Comprehensive Architecture & Systems Integration

This curriculum integrates every layer of the vector retrieval stack—from high-dimensional linear algebra and information retrieval theory to database storage engines (LSM-Trees, WAL), handcrafted CPU SIMD, CUDA GPU kernels (FlashAttention, Tensor Cores), and PyTorch models.

```
 ┌──────────────────────────────────────────────────────────────────────────────────────────────────┐
 │                               PILLAR 1: MATHEMATICS & HIGH-D ANALYTICS                           │
 │ • Gilbert Strang's Linear Algebra (Vector Spaces, Orthogonality, QR, SVD, Eigenvalues, Graphs)   │
 │ • High-D Geometry: Measure Concentration, Curse of Dimensionality, Hubness & Anisotropic Cones   │
 │ • ScaNN Theory: Anisotropic Vector Quantization Loss (Directional Error Weighting for MIPS)      │
 │ • IR Analytics: NDCG@K, MRR, MAP, and Poisson Process p95/p99 Tail Latency Queueing Theory       │
 └────────────────────────┬─────────────────────────────────────────┬───────────────────────────────┘
                          │                                         │
                          ▼                                         ▼
 ┌────────────────────────────────────────┐     ┌───────────────────────────────────────────────────┐
 │      PILLAR 2: DEEP LEARNING (Py)      │     │      PILLAR 3: DATABASE & C++/GPU ENGINE (secan)  │
 │ • Transformers from Scratch            │     │ • Storage Engine: LSM-Tree, WAL, MemTable, Segs   │
 │ • Online Softmax & FlashAttention-1/2  │────►│ • Columnar Formats: Zero-Copy Apache Arrow Layout │
 │ • Vision Transformer (ViT)             │     │ • Handcrafted SIMD: AVX2, AVX-512, ARM NEON       │
 │ • BERT & Matryoshka Embeddings (MRL)   │     │ • Quantization: SQ8 (Outliers), Anisotropic PQ, BQ│
 │ • ColBERT Late Interaction & MaxSim    │     │ • Graph ANN: HNSW & DiskANN (io_uring Async SSD)  │
 │ • ColPali Multimodal Retrieval         │     │ • CUDA: FlashAttention, CUTLASS GEMM, CAGRA Graph │
 │ • PagedAttention & KV Cache Paging     │     │ • Zero-Copy nanobind Python Engine Architecture   │
 └────────────────────────────────────────┘     └───────────────────────────────────────────────────┘
```

---

## 🔬 In-Depth Specifications of the 4 Core Advanced Domains

### 1. High-Dimensional Geometry Analytics (Measure Concentration & Hubness)
* **Measure Concentration (The Distance Collapse)**:
  In $\mathbb{R}^{768}$ and $\mathbb{R}^{1536}$, the volume of a hypersphere concentrates in a vanishingly thin shell at its surface. The relative contrast between closest and furthest neighbors collapses:
  $$\lim_{D \to \infty} \frac{d_{\max} - d_{\min}}{d_{\min}} = 0$$
* **The Hubness Phenomenon in LLM Embeddings**:
  Transformer embeddings are anisotropic, clustering in narrow cones. A small number of vectors ("Hubs") appear as nearest neighbors for thousands of queries, causing severe congestion in graph routing.
* **Engine Implementation**: Compute the **Skewness of $k$-occurrences ($S_{N_k}$)** and implement **Centering, Whitening, and Cosine Softmax scaling** to equalize graph node degree.

### 2. Google ScaNN’s Anisotropic Quantization Loss (MIPS Optimization)
* **Why Standard $k$-means Fails Maximum Inner Product Search (MIPS)**:
  Standard $k$-means minimizes total Euclidean reconstruction error: $\|x - \tilde{x}\|_2^2 = \|x_\parallel - \tilde{x}_\parallel\|_2^2 + \|x_\perp - \tilde{x}_\perp\|_2^2$.
  In MIPS, orthogonal errors ($e_\perp$) have zero expectation over random queries, but parallel errors ($e_\parallel$) directly distort dot product ranking.
* **The Anisotropic Loss Function**:
  $$\mathcal{L}_{\text{anisotropic}}(x, \tilde{x}) = h \cdot \|x_\parallel - \tilde{x}_\parallel\|_2^2 + \|x_\perp - \tilde{x}_\perp\|_2^2 \quad (\text{where } h > 1)$$
* **Engine Implementation**: Codebook training with $h=5\times$ parallel error penalty in `ProductQuantizer`, gaining $15\%–30\%$ higher recall at identical bitrates.

### 3. Production Information Retrieval (IR) Analytics & SLA Queuing
* **Ranking Quality Metrics**:
  * **NDCG@K (Normalized Discounted Cumulative Gain)**: $\text{DCG}@K = \sum_{i=1}^K \frac{2^{rel_i} - 1}{\log_2(i + 1)}$, $\text{NDCG}@K = \frac{\text{DCG}@K}{\text{IDCG}@K}$
  * **MRR (Mean Reciprocal Rank)**: $\frac{1}{|Q|} \sum_{i=1}^{|Q|} \frac{1}{\text{rank}_i}$
  * **MAP (Mean Average Precision)**: Precision at each relevant rank position.
* **Latency SLA Percentiles ($p50, p95, p99, p99.9$)**:
  Modeling query arrivals with an $M/M/k$ Poisson queue generator in C++ to measure thread pool latency spikes and queue buildup under saturation load.

### 4. Vector Database Storage Engine Internals (LSM-Trees & Apache Arrow)
* **Log-Structured Merge-Tree (LSM-Tree) Architecture for Live Vector Updates**:
  * **Write-Ahead Log (WAL)**: Append-only disk log for durability (`wal.bin`).
  * **MemTable**: In-memory mutable HNSW buffer absorbing high-velocity live insertions.
  * **Immutable Disk Segments**: Read-only serialized index segments (HNSW / IVF-PQ) in Apache Arrow / Lance columnar memory layout.
  * **Background Compaction Thread**: Multi-way segment merger running asynchronously to compact smaller segments into a single balanced graph without blocking reads.

---

## 🛡️ Production Engineering Protocols & Safeguards

1. **Subnormal / Denormal Protection**: Always enable `_MM_SET_FLUSH_ZERO_MODE(_MM_FLUSH_ZERO_ON)` and `_MM_SET_DENORMALS_ZERO_MODE(_MM_DENORMALS_ZERO_ON)` to prevent $10\times–100\times$ microcode slowdowns.
2. **Unit Sphere Equivalence ($L_2 \equiv \text{Cosine}$)**: Pre-normalize all ingested vectors to unit length ($\|u\|_2 = 1$) so squared Euclidean distance monotonically equals $2 - 2 \cos(\theta)$, eliminating all per-query divisions and square roots.
3. **Outlier Dimension Clipping**: Percentile clipping (0.05th / 99.95th) before scalar quantization to protect 8-bit dynamic range against heavy-tailed embedding outliers.
4. **Sanitizer Harness**: AddressSanitizer (`-fsanitize=address,undefined`), ThreadSanitizer (`-fsanitize=thread`), and NVIDIA `compute-sanitizer` configured from Day 1 for memory safety.
5. **Pragmatic Tokenization**: Dedicated use of Hugging Face's Rust-backed `tokenizers` library in the Python track so 100% of modeling effort stays on neural architectures.
6. **Ground-Truth Regression Matrix**: Automated testing (`tests/test_recall_regression.cpp`) ensuring no commit silently degrades recall or introduces off-by-one errors.
7. **5-Part Essay Standard**: A structured technical post-mortem template (*Math $\to$ Naive Bottleneck $\to$ Optimized Kernel $\to$ `perf`/Nsight Benchmark $\to$ Key Takeaway*) for all 24 Saturday articles.

---

## 📚 Complete Literature Stack

* **STRANG**: *Linear Algebra and Its Applications* (4th Edition) — Gilbert Strang
* **PIKUS**: *The Art of Writing Efficient Programs* — Fedor G. Pikus
* **CSAPP**: *Computer Systems: A Programmer's Perspective* (3rd Edition) — Bryant & O'Hallaron
* **AGNER**: *Optimizing Software in C++* & *Instruction Tables* — Agner Fog
* **CPPHI**: *C++ High Performance* (2nd Edition) — Andrist & Sehr
* **ASYNC**: *High-Performance Asynchronous C++* — Marek Ellison
* **FINSY**: *C++ High Performance for Financial Systems* — Ariel Silahian
* **PMPP**: *Programming Massively Parallel Processors* (4th Edition) — Hwu, Kirk & El Hajj
* **CUDA-GUIDE**: *CUDA C++ Programming Guide* — NVIDIA
* **FLASH-ATTN**: *"FlashAttention: Fast and Memory-Efficient Exact Attention with IO-Awareness"* (Dao et al. 2022) + FlashAttention-2 (Dao 2023)
* **SCANN**: *"Accelerating Large-Scale Inference with Anisotropic Vector Quantization"* (Guo et al. / Google Research 2020)
* **PAGED-ATTN**: *"Efficient Memory Management for Large Language Model Serving with PagedAttention"* (Kwon et al. 2023 / vLLM)
* **COLPALI**: *"ColPali: Efficient Document Retrieval with Vision Language Models"* (Faysse et al. 2024)

---

# BLOCK 1: MATHEMATICAL FOUNDATIONS, CPU ENGINE & PYTORCH (Months 1–3)

---

# 📅 MONTH 1: Vector Spaces, IR Metrics, SIMD Hardware & Transformers (Sep 2026)

---

### Week 1 (Sep 1–5): Vectors, IR Analytics (NDCG/MRR), Matrix Math & Measurement

**Theme**: High-dimensional vector geometry, Information Retrieval ranking metrics, and scientific C++ measurement.

* **Linear Algebra (Strang)**: Chapter 1 (§1.1–1.5) — Vector geometry in $\mathbb{R}^n$, linear combinations, dot products, Cauchy-Schwarz inequality, 4 perspectives on matrix multiplication.
* **IR Analytics**: Mathematical definitions of NDCG@K, MRR, MAP, and building an automated IR evaluation harness.
* **Python Track (`transformers-pytorch`)**: Tensor representations in PyTorch, batched matrix multiplication (`torch.bmm`, `torch.einsum`), scaled dot-product attention $\text{Softmax}\left(\frac{QK^T}{\sqrt{d_k}}\right)V$.
* **C++ Engine (`secan`)**: Google Benchmark integration, `.fvecs` SIFT1M loader, NDCG/MRR evaluator (`tests/test_ir_metrics.cpp`), exact scalar baseline scan with AddressSanitizer.

| Day | Linear Algebra & IR Analytics (45 min) | Systems / C++ Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Sep 1** | **STRANG §1.1–1.2**: Vector geometry in $\mathbb{R}^n$, inner products, Euclidean norm $\|x\|_2$, Cauchy-Schwarz inequality. | **PIKUS Ch 2**: Performance measurements, high-res timers, profiler sampling, micro-benchmark noise floor. | **secan**: Integrate Google Benchmark via CMake. Add ASan/UBSan build flags. Write first benchmark for `l2_squared` with `DoNotOptimize`. |
| **Tue Sep 2** | **STRANG §1.3–1.4**: Matrix multiplication viewed as column/row linear combinations. Block matrix products. | **CSAPP §5.1–5.6**: Compiler limitations, Cycles Per Element (CPE), loop inefficiencies, memory aliasing. | **secan**: Implement binary `.fvecs` and `.bvecs` parsers in `src/io/fvecs_reader.h`. Load SIFT1M ($1\text{M} \times 128\text{D}$). |
| **Wed Sep 3** | **IR Analytics**: Mathematical derivation of NDCG@K, DCG formula, Ideal DCG (IDCG), MRR, MAP. | **CSAPP §5.7**: Superscalar architecture, out-of-order execution, execution ports, latency vs throughput. | **secan**: Build IR metrics evaluator in `tests/test_ir_metrics.cpp`. Run exact scan on SIFT1M; verify Recall@10 = 1.0 and NDCG@10 = 1.0. |
| **Thu Sep 4** | **STRANG §2.1–2.2**: Vector spaces and subspaces. Column space and nullspace of a matrix. | **AGNER Ch 3 & Ch 7.1–7.3**: Finding bottlenecks, clock cycles, variable storage, floating-point efficiency. | **Python (`transformers-pytorch`)**: Scaffold a clean project from scratch (`uv init transformers-pytorch`). Create `src/attention.py` and implement `scaled_dot_product_attention(Q, K, V, mask)` with causal masking from an empty file. |
| **Fri Sep 5** | **STRANG §2.3–2.4**: Linear independence, basis, dimension, span of high-dimensional vector spaces. | **PIKUS Ch 1 & CSAPP §5.14**: Measurement-driven optimization, profiling-guided workflow with `perf stat`. | **secan**: Profile baseline SIFT1M scan with `perf stat`. Record IPC, cache misses, branch misses. Update README benchmark table. |

> **📝 Essay 1 (Sat Sep 6)**: *"The Geometry of High-Dimensional Retrieval: From Cauchy-Schwarz and NDCG to CPU Performance Counters"*  
> Structure: 1. Cauchy-Schwarz geometry and NDCG/MRR mathematical formulations $\to$ 2. Why naive scalar loops hit CPU stall cycles $\to$ 3. Setting up Google Benchmark + `perf stat` harness $\to$ 4. SIFT1M empirical IPC baseline $\to$ 5. The First Rule of Performance: Never Guess.

---

### Week 2 (Sep 8–12): Orthogonality, SIMD AVX2 & Multi-Head Attention

**Theme**: Vector projections and instruction-level parallelism.

* **Linear Algebra (Strang)**: Chapter 2 (§2.5–2.6) + Chapter 3 (§3.1) — Four fundamental subspaces, orthogonality of vector spaces, row space $\perp$ nullspace, orthogonal complements.
* **Python Track (`transformers-pytorch`)**: Multi-Head Attention (MHA) module from scratch. Splitting heads, linear projections ($W_q, W_k, W_v, W_o$), scaled attention, reshaping and concatenation.
* **C++ Engine (`secan`)**: Handcrafted AVX2 + FMA distance kernels, 4-way multi-register accumulator unrolling, 64-byte alignment (`alignas(64)`), subnormal FTZ/DAZ flags.

| Day | Linear Algebra (45 min) | Systems / C++ Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Sep 8** | **STRANG §2.5–2.6**: The four fundamental subspaces of a matrix. The Fundamental Theorem of Linear Algebra. | **AGNER Ch 12**: SIMD instructions, 256-bit YMM registers, data types, intrinsics syntax. | **secan**: Enable `_MM_SET_FLUSH_ZERO_MODE` / `_MM_SET_DENORMALS_ZERO_MODE`. Implement `l2_squared_avx2()` in `src/search/distance_avx2.cpp`. |
| **Tue Sep 9** | **STRANG §3.1**: Orthogonal vectors and orthogonal subspaces. Subspace angles and orthogonal complements. | **CSAPP §5.8–5.9**: Loop unrolling, breaking dependency chains with multiple independent accumulator registers. | **secan**: Implement 4-way unrolled `l2_squared_avx2` with 4 parallel `__m256` accumulators. Measure speedup over 1-acc. |
| **Wed Sep 10** | **STRANG §3.2**: Cosine of the angle between vectors, inner product geometry, orthogonal decomposition. | **AGNER-INST & AGNER Ch 11**: VFMADD latency/throughput port mapping on modern x86 microarchitectures. | **secan**: Implement `cosine_distance_avx2()`: compute dot product, norm $A$, and norm $B$ simultaneously in 1 pass. |
| **Thu Sep 11** | Review Strang Ch 1–3 exercises on projections and vector inner products. | **AGNER Ch 13.1–13.3**: Alignment, `alignas(64)`, cache line splits, unaligned load penalties. | **Python (`transformers-pytorch`)**: Build `MultiHeadAttention(d_model, num_heads)` class from scratch. Validate shapes with unit tests. |
| **Fri Sep 12** | Matrix rank and dimensionality reduction intuition: why low-rank projections preserve energy. | **PIKUS Ch 3**: Instruction-level parallelism, register pressure, compiler vectorization limits. | **secan**: Add AVX-512 backend (`_mm512_*`) behind `#ifdef __AVX512F__`. Benchmark scalar vs AVX2 vs AVX-512. |

> **📝 Essay 2 (Sat Sep 13)**: *"Breaking Dependency Chains: Multi-Register SIMD Kernels and Multi-Head Attention Geometry"*  
> Structure: 1. Orthogonal subspaces in linear algebra $\to$ 2. Why 1-accumulator loops stall on FMA latency $\to$ 3. 4-way `__m256` accumulator unrolling code $\to$ 4. `perf stat` IPC jump from 1.2 to 3.8 $\to$ 5. Subnormal traps and FTZ/DAZ protection.

---

### Week 3 (Sep 15–19): Projections, Least Squares, Cache Hierarchy & Transformer Encoder

**Theme**: Subspace projections and overcoming the CPU memory bandwidth wall.

* **Linear Algebra (Strang)**: Chapter 3 (§3.2–3.3) — Projections onto lines and subspaces, projection matrix $P = A(A^T A)^{-1} A^T$, projection properties ($P^2 = P, P^T = P$), least squares approximations.
* **Python Track (`transformers-pytorch`)**: Position-wise Feed-Forward Network (FFN), Layer Normalization (Pre-LN vs Post-LN from scratch), Positional Encodings (sinusoidal), assembling the full `TransformerEncoderLayer`.
* **C++ Engine (`secan`)**: Memory hierarchy profiling, cache-blocking/tiling, software prefetching (`_mm_prefetch`), unit sphere pre-normalization.

| Day | Linear Algebra (45 min) | Systems / C++ Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Sep 15** | **STRANG §3.2**: Projection onto a 1D line: formula $p = \hat{x} a$, error vector $e \perp a$, projection matrix $P = \frac{a a^T}{a^T a}$. | **CSAPP §6.1–6.3**: SRAM vs DRAM, memory latency gap, spatial and temporal locality principles. | **secan**: Profile SIFT1M cache misses with `perf stat -e L1-dcache-load-misses,LLC-load-misses`. Calculate working set. |
| **Tue Sep 16** | **STRANG §3.3**: Projection onto an $n$-dimensional subspace. Normal equations $A^T A \hat{x} = A^T b$. Invertibility of $A^T A$. | **CSAPP §6.4–6.5**: Cache line organization, set associativity, conflict misses, cache-friendly coding. | **secan**: Implement cache-blocked `linear_scan_tiled`: partition dataset into tiles fitting in L2 cache ($256\text{KB}$). |
| **Wed Sep 17** | **STRANG §3.3**: Geometric interpretation of least squares: minimizing $\|Ax - b\|_2^2$ by projecting $b$ onto the column space of $A$. | **CSAPP §6.6 & PIKUS Ch 4**: The Memory Mountain, cache hierarchy on real workloads, software prefetching. | **secan**: Add software prefetching (`_mm_prefetch`, `_MM_HINT_T0`). Tune prefetch distances ($4, 8, 16, 32$ vectors). |
| **Thu Sep 18** | Orthogonal projection matrices: prove $P^2 = P$ (idempotent) and $P^T = P$ (symmetric). | **AGNER Ch 9**: Optimizing memory access, cache line splits, non-temporal streaming stores. | **Python (`transformers-pytorch`)**: Implement `LayerNorm` from scratch, sinusoidal `PositionalEncoding`, and `FeedForwardBlock`. |
| **Fri Sep 19** | Subspace projection applications: connecting projections to vector compression. | **FINSY Ch 6**: Cache optimization, system warmup routines, `madvise(MADV_HUGEPAGE)`. | **Python (`transformers-pytorch`)**: Assemble `TransformerEncoder` stacking $N$ layers with residual connections. Verify forward pass. |

> **📝 Essay 3 (Sat Sep 20)**: *"The Geometry of Subspaces and the Physics of CPU Caches"*  
> Structure: 1. Projection matrices and least squares geometry $\to$ 2. Why raw DRAM bandwidth chokes linear scans $\to$ 3. Implementing L2 cache-tiling and software prefetching $\to$ 4. Memory Mountain benchmark plots $\to$ 5. Unit sphere pre-normalization eliminating division.

---

### Week 4 (Sep 22–26): Gram-Schmidt, Online Softmax Math, IVF Index & Full Transformer

**Theme**: Orthogonal bases, coarse Voronoi partitioning, and the mathematical derivation of Online Softmax.

* **Linear Algebra (Strang)**: Chapter 3 (§3.4) — Orthogonal bases, orthonormal matrices ($Q^T Q = I$), Gram-Schmidt orthogonalization process, $A = QR$ factorization.
* **Python Track (`transformers-pytorch`)**: Decoder block (cross-attention, causal masking), full Encoder-Decoder model, mathematical derivation and Python prototype of **Online Softmax** (Milakov-Gimelshtein algorithm for FlashAttention).
* **C++ Engine (`secan`)**: Batch Query GEMM, `IVFIndex` with $k$-means coarse Voronoi partitioning, multi-threaded `std::jthread` scaling.

| Day | Linear Algebra (45 min) | Systems / C++ Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Sep 22** | **STRANG §3.4**: Orthonormal vectors: $q_i^T q_j = 0$ ($i \neq j$) and $q_i^T q_i = 1$. Properties of square orthogonal matrices ($Q^{-1} = Q^T$). | **PIKUS Ch 5**: Cache coherence, false sharing, atomic memory ordering basics. | **secan**: Implement `batch_linear_scan`: process $B=32/64$ queries simultaneously against tiled dataset (GEMV $\to$ GEMM). |
| **Tue Sep 23** | **STRANG §3.4**: The Gram-Schmidt process: constructing an orthonormal basis step-by-step from arbitrary independent vectors. | Research: Faiss IVF coarse quantizer architecture, Voronoi cell partitioning. | **secan**: Implement `IVFIndex`: train $k$-means centroids on dataset vectors; assign vectors to Voronoi cells; build inverted lists. |
| **Wed Sep 24** | **STRANG §3.4**: The $A = QR$ matrix factorization. Rectangular $Q$ with orthonormal columns and upper-triangular $R$. | **PIKUS Ch 6**: Concurrency, work decomposition, thread pool patterns. | **secan**: Implement multi-probe IVF search: query searches top `nprobe` cells. Sweep `nprobe` from 1 to 64; plot Recall vs speedup. |
| **Thu Sep 25** | Online Softmax Mathematics: derivation of incremental running max $m_{new} = \max(m_{prev}, x)$ and partition update $\ell_{new} = \ell_{prev} e^{m_{prev} - m_{new}} + e^{x - m_{new}}$. | **CPPHI Concurrency & ASYNC Ch 1–2**: `std::jthread`, thread affinity, eliminating false sharing with `alignas(64)`. | **Python (`transformers-pytorch`)**: Implement **Online Softmax** self-attention in Python (block-by-block without $N \times N$ matrix allocation). |
| **Fri Sep 26** | Review Strang Chapter 3: orthogonality, projections, Gram-Schmidt, QR. | **PIKUS Ch 12**: Design for performance, evaluating whole-system throughput. | **secan & Python**: Multi-thread IVF search across CPU cores with pinned threads. Assemble full PyTorch Transformer model. Tag `v0.2-simd-ivf`. |

> **📝 Essay 4 (Sat Sep 27)**: *"From Orthonormal Bases to Voronoi Cells: The Mathematical Architecture of Scalable Search"*  
> Structure: 1. Gram-Schmidt and $A=QR$ factorization $\to$ 2. Why single-query GEMV is memory-bound $\to$ 3. Transforming batch search into GEMM and IVF Voronoi cell partitioning $\to$ 4. Derivation of Online Softmax $\to$ 5. Multi-core scaling efficiency.

---

# 📅 MONTH 2: Eigenvalues, Anisotropic ScaNN, Hubness & HNSW (Oct 2026)

---

### Week 5 (Sep 29 – Oct 3): Eigenvalues, Diagonalization, SQ8/SQ4 & Vision Transformer (ViT)

**Theme**: Spectral properties of matrices, integer SIMD vector quantization, and patching images into tokens.

* **Linear Algebra (Strang)**: Chapter 5 (§5.1–5.2) — Eigenvalues and eigenvectors ($\det(A - \lambda I) = 0$), trace and determinant in terms of eigenvalues, diagonalizing a matrix ($A = S \Lambda S^{-1}$).
* **Python Track (`transformers-pytorch` / ViT)**: Vision Transformer from scratch: image patch extraction ($P \times P$), linear patch projection, learnable `[CLS]` token embedding, 1D learnable position embeddings, ViT Encoder.
* **C++ Engine (`secan`)**: Scalar Quantization (`SQ8` with **percentile outlier clipping** and `SQ4`), integer SIMD dot products (`_mm256_maddubs_epi16`, `_mm256_dpbusd_epi32`), two-stage re-ranking pipeline.

| Day | Linear Algebra (45 min) | Systems / C++ Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Sep 29** | **STRANG §5.1**: Introduction to eigenvalues and eigenvectors. Geometric meaning: $Ax$ parallel to $x$. Characteristic equation $\det(A - \lambda I) = 0$. | **AGNER Ch 7.2 & CSAPP §2.2–2.3**: Integer arithmetic efficiency, two's complement, overflow, bit-width conversion. | **secan**: Implement `ScalarQuantizer` with **percentile clipping (0.05th/99.95th)** to handle outlier dimensions. Verify dequantization error. |
| **Tue Sep 30** | **STRANG §5.1**: Properties of eigenvalues: $\sum \lambda_i = \text{trace}(A)$, $\prod \lambda_i = \det(A)$. Eigenvalues of triangular and diagonal matrices. | **INTEL Intrinsics Guide**: Study `_mm256_maddubs_epi16`, `_mm256_madd_epi16`, `_mm256_dpbusd_epi32` (VNNI dot product). | **secan**: Implement `l2_squared_sq8()` using AVX2 integer intrinsics. Process 32 dimensions per iteration in a single `__m256i`. |
| **Wed Oct 1** | **STRANG §5.2**: Diagonalization of a matrix: $S^{-1} A S = \Lambda$ when $A$ has $n$ linearly independent eigenvectors. Powers of a matrix $A^k = S \Lambda^k S^{-1}$. | **AGNER Ch 12**: Integer SIMD saturation arithmetic, signed vs unsigned byte multiplication, widening instructions. | **Python (ViT)**: Scaffold clean project (`uv init vit-pytorch`). Create `src/patch_embed.py` from scratch: implement `PatchEmbedding(image_size, patch_size, in_channels, embed_dim)`. |
| **Thu Oct 2** | **STRANG §5.2**: Nondiagonalizable matrices (defective matrices, algebraic vs geometric multiplicity). | **CSAPP §2.4**: Floating-point representation, rounding error bounds, precision loss in quantization. | **secan**: Implement 4-bit scalar quantization (`SQ4`): pack 2 dimensions per byte with nibble masking. Build 2-stage SQ8 $\to$ FP32 re-ranker. |
| **Fri Oct 3** | Eigenvalue stability: why small matrix perturbations shift eigenvalues. | **PIKUS Ch 9**: High-performance C++, move semantics, zero-copy buffer views (`std::span`). | **Python (ViT)**: Add learnable `[CLS]` token and 1D positional embeddings. Stack Transformer encoder layers to complete `VisionTransformer`. |

> **📝 Essay 5 (Sat Oct 4)**: *"Spectral Transformations and Low-Bit Quantization: Compressing High-Dimensional Information"*  
> Structure: 1. Eigenvalues and diagonal coordinate systems $\to$ 2. The outlier dimension trap in LLM embeddings $\to$ 3. Percentile clipping + integer SIMD accumulation $\to$ 4. ViT image patch projection mechanics $\to$ 5. Two-stage SQ8 coarse scan + FP32 re-ranking Pareto curve.

---

### Week 6 (Oct 6–10): Symmetric Matrices, SVD, Product Quantization & BERT from Scratch

**Theme**: The Spectral Theorem, Singular Value Decomposition, codebook compression, and bidirectional language modeling.

* **Linear Algebra (Strang)**: Chapter 5 (§5.5) + Chapter 6 (§6.1–6.3) — Symmetric matrices ($A = Q \Lambda Q^T$, all real eigenvalues, orthogonal eigenvectors), Positive Definite Matrices, Singular Value Decomposition ($A = U \Sigma V^T$).
* **Python Track (`bert-pytorch`)**: BERT architecture from scratch using Hugging Face `tokenizers` for WordPiece IDs: Segment embeddings, Positional embeddings, Bidirectional Self-Attention, Masked LM head, Next Sentence Prediction head, extracting `[CLS]` sentence vectors.
* **C++ Engine (`secan`)**: Product Quantization (`ProductQuantizer`), subspace $k$-means codebook training, Asymmetric Distance Computation (ADC) with precomputed Query Lookup Tables (LUT).

| Day | Linear Algebra (45 min) | Systems / C++ Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Oct 6** | **STRANG §5.5**: Real symmetric matrices: proof that eigenvalues are real and eigenvectors are orthogonal. The Spectral Theorem: $A = Q \Lambda Q^T$. | Research paper: *"Product Quantization for Nearest Neighbor Search"* (Jégou et al. 2011) §1–4. | **secan**: Implement $k$-means clustering in C++ for a subspace: `train_kmeans(data, k=256, dim_sub)` using $k$-means++. |
| **Tue Oct 7** | **STRANG §6.1–6.2**: Positive definite matrices: tests for positive definiteness (eigenvalues $> 0$, pivots $> 0$, energy $x^T A x > 0$). | Faiss wiki on Product Quantizer: subspace splitting, codebook memory layouts. | **secan**: Implement `ProductQuantizer`: split $D$ dimensions into $M$ subspaces. Train $M$ codebooks. Encode vectors as $M$-byte codes. |
| **Wed Oct 8** | **STRANG §6.3**: Singular Value Decomposition (SVD): $A = U \Sigma V^T$. Singular values $\sigma_i$, left singular vectors $U$, right singular vectors $V$. | **AGNER Ch 7.10 & Ch 9**: Array structures for cache-friendly table lookups, stride optimization. | **secan**: Implement Asymmetric Distance Computation (ADC): precompute query-to-centroid table `float LUT[M][256]`. Distance = sum of $M$ lookups. |
| **Thu Oct 9** | **STRANG §6.3**: Low-rank matrix approximation via truncated SVD (Eckart-Young-Mirsky Theorem). Connection to PCA. | **PIKUS Ch 10**: Compiler optimizations, `__restrict__`, loop vectorization, Link-Time Optimization (LTO). | **Python (`bert-pytorch`)**: Scaffold clean project (`uv init bert-pytorch`). Use HF `tokenizers`. Implement `src/embeddings.py` (`Token + Segment + Position`) and bidirectional encoder from scratch. |
| **Fri Oct 10** | Geometric interpretation of SVD: mapping hyper-spheres to hyper-ellipsoids. | **PIKUS Ch 11**: Undefined behavior, memory aliasing, safe usage of low-level pointer arithmetic. | **Python (`bert-pytorch`) & secan**: Implement BERT MLM prediction head. In `secan`, benchmark IVFPQ vs IVFFlat on SIFT1M. |

> **📝 Essay 6 (Sat Oct 11)**: *"The Spectral Theorem, SVD, and Product Quantization: Compressing Vectors to 16 Bytes"*  
> Structure: 1. Spectral Theorem and SVD low-rank approximations $\to$ 2. Why full-precision vectors waste memory bandwidth $\to$ 3. Subspace decomposition and codebook training $\to$ 4. Asymmetric Distance Computation (ADC) LUT architecture $\to$ 5. IVFPQ compression vs Recall@10 benchmark.

---

### Week 7 (Oct 13–17): Google ScaNN Anisotropic Loss, PCA, FastScan & Matryoshka MRL

**Theme**: Directional quantization loss (ScaNN), Matryoshka Representation Learning, and in-register FastScan lookups.

* **Linear Algebra (Strang)**: Chapter 6 (§6.7) — Principal Component Analysis (PCA), covariance matrix $C = \frac{1}{n} X X^T$, finding principal directions via SVD.
* **ScaNN Anisotropic Theory**: Mathematical derivation of ScaNN's directional quantization loss: $\mathcal{L} = h \|e_\parallel\|^2 + \|e_\perp\|^2$ ($h > 1$) for Maximum Inner Product Search (MIPS).
* **Python Track (`bert-pytorch`)**: **Matryoshka Representation Learning (MRL)**: training BERT with nested dimension loss ($64\text{D} \subset 128\text{D} \subset 256\text{D} \subset 768\text{D}$) allowing dynamic dimension slicing.
* **C++ Engine (`secan`)**: ScaNN anisotropic codebook training in `ProductQuantizer`, 1-bit RaBitQ with random orthogonal rotations, 4-bit FastScan with in-register `_mm256_shuffle_epi8` (PSHUFB) lookups.

| Day | Linear Algebra & ScaNN Math (45 min) | Systems / C++ Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Oct 13** | **STRANG §6.7**: Principal Component Analysis (PCA): centering data, covariance matrix $C = \frac{1}{n-1} \tilde{X}^T \tilde{X}$, principal eigenvectors. | ScaNN Paper §1–3: MIPS error decomposition: why orthogonal error $e_\perp$ has 0 expectation while parallel error $e_\parallel$ degrades inner products. | **secan**: Implement **ScaNN Anisotropic Loss** in `ProductQuantizer`: penalize parallel error with weight $h=5.0$. Compare codebooks. |
| **Tue Oct 14** | **STRANG §6.7**: Dimensionality reduction with PCA: projecting $D$-dimensional data onto the top $k$ principal eigenvectors. Explained variance ratio. | **INTEL Intrinsics & AGNER-INST**: Deep dive into `_mm256_shuffle_epi8` (PSHUFB) semantics and port mapping. | **secan**: Implement RaBitQ: generate random orthogonal rotation matrix via QR decomposition. Apply rotation before 1-bit quantization + error correction. |
| **Wed Oct 15** | Orthogonal transformations: why random orthogonal rotations distribute variance evenly across dimensions (critical for RaBitQ). | Faiss FastScan documentation & André et al. (2015) paper §1–3. | **secan**: Implement 4-bit PQ encoding ($k=16$ centroids per subspace, packing 2 codes per byte). |
| **Thu Oct 16** | Matrix norms: Frobenius norm $\|A\|_F$, Spectral norm $\|A\|_2$, connection to singular values. | AGNER-INST: Study `VPSHUFB`, `VPADDB`, `VPUNPCKLBW` instruction latency and accumulation chains. | **secan**: Implement **FastScan kernel**: load 16 centroid distances into `__m128i` / `__m256i`. Execute table lookups **entirely in-register** via PSHUFB. |
| **Fri Oct 17** | Matryoshka Nested Subspace Mathematics: leading eigenvectors capturing dominant variance. | **CSAPP §5.10–5.12**: Register spilling, store-load forwarding, pipeline limiting factors. | **Python (`bert-pytorch`)**: Train BERT with Matryoshka Representation Loss. Export multi-resolution embeddings ($64\text{D}, 128\text{D}, 768\text{D}$) to `.fvecs`. |

> **📝 Essay 7 (Sat Oct 18)**: *"Google ScaNN Anisotropic Loss, Matryoshka Embeddings, and In-Register SIMD FastScan"*  
> Structure: 1. Why standard $k$-means minimizes the wrong error for MIPS $\to$ 2. ScaNN's anisotropic loss derivation ($h \|e_\parallel\|^2 + \|e_\perp\|^2$) $\to$ 3. Matryoshka MRL nested representations $\to$ 4. FastScan 4-bit PSHUFB in-register lookup mechanics $\to$ 5. Anisotropic vs standard PQ Recall@10 benchmark.

---

### Week 8 (Oct 20–24): Graph Theory, The Hubness Phenomenon & HNSW from Scratch

**Theme**: Small-world networks, the Hubness Problem in embedding spaces, and $O(\log N)$ beam search routing.

* **Linear Algebra (Strang)**: Chapter 8 (§8.2) — Graphs and Networks: Incidence matrices, adjacency matrices, Laplacian matrix $L = D - A$, graph connectivity.
* **High-D Analytics**: **The Hubness Phenomenon**: Calculating the skewness of $k$-occurrences ($S_{N_k}$); centering & whitening transforms to eliminate graph hub congestion.
* **Python Track**: Building a complete text-to-vector search pipeline: Raw Text Corpus $\to$ Tokenization (HF `tokenizers`) $\to$ PyTorch BERT $\to$ Export `.fvecs` $\to$ Ingest into `secan`.
* **C++ Engine (`secan`)**: Full HNSW index from scratch (skip-list hierarchy, greedy beam search, heuristic neighbor selection Algorithm 4, CSR-packed adjacency, bounded flat heaps).

| Day | Linear Algebra & Hubness Theory (45 min) | Systems / C++ Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Oct 20** | **STRANG §8.2**: Graphs and Networks: Node-arc incidence matrix, Kirchhoff's laws, Graph Laplacian $L = A^T A = D - W$. | Research paper: *"Efficient and Robust ANN Search Using HNSW Graphs"* (Malkov & Yashunin 2020) §1–3. | **secan**: Implement `HNSWIndex` data structures: flat CSR adjacency storage (`neighbors[]` + `offsets[]`), node struct, entry point. |
| **Tue Oct 21** | **Hubness Analytics**: Skewness of $k$-occurrences $S_{N_k} = \frac{\sum (N_k(x) - \mu)^3}{\sigma^3}$. Why high hubness degrades HNSW graph routing. | HNSW paper §4–5: Algorithm 4 (heuristic neighbor selection), level multiplier $m_L$, parameter tuning ($M, ef$). | **secan**: Implement HNSW `insert()`: exponential level assignment ($\ell = \lfloor -\ln(\text{unif}) \cdot m_L \rfloor$), greedy descent, multi-layer neighbor connection. |
| **Wed Oct 22** | Centering and Whitening transforms: $x_{\text{white}} = \Lambda^{-1/2} Q^T (x - \mu)$ to eliminate embedding anisotropy. | **PIKUS Ch 7**: Concurrent data structures, cache-friendly priority queues, memory allocation in graphs. | **secan**: Implement HNSW `search()`: beam search with visited-set bitfield. Implement Algorithm 4 diverse neighbor selection. |
| **Thu Oct 23** | Distance metrics on graph nodes: shortest path distance vs Euclidean embedding distance. | **AGNER Ch 7.12–7.13 & Ch 7.5**: Branch prediction in graph traversal, branchless heap sift-down. | **secan**: Optimize HNSW: replace `std::priority_queue` with custom **bounded flat heap** (fixed-size array). Replace visited hash-set with flat bitset. |
| **Fri Oct 24** | Review graph spectra and small-world network properties. | **CSAPP §5.14**: Profiling graph traversal bottlenecks with `perf record`. | **End-to-End Test**: Ingest BERT text embeddings ($768\text{D}$) into `secan` HNSW. Benchmark Recall@10 vs QPS Pareto curves. Tag `v0.3-hnsw`. |

> **📝 Essay 8 (Sat Oct 25)**: *"Building HNSW from Scratch: Graph Laplacians, The Hubness Phenomenon, and Sub-Millisecond Search"*  
> Structure: 1. Graph Laplacians and small-world connectivity $\to$ 2. The Hubness Problem in LLM embeddings and its mitigation $\to$ 3. HNSW skip-list hierarchy and Algorithm 4 neighbor pruning in C++20 $\to$ 4. Bounded flat heaps vs `std::priority_queue` $\to$ 5. SIFT1M Recall vs Latency Pareto frontier.

---

# 📅 MONTH 3: Multi-Vector ColBERT, LSM Storage Engine & Production Packaging (Nov 2026)

---

### Week 9 (Oct 27–31): Matrix Inner Products, ColBERT Architecture & SIMD MaxSim

**Theme**: Token-level multi-vector representations and SIMD cross-matrix MaxSim kernels.

* **Linear Algebra (Strang)**: Chapter 1 & 2 revisited — Frobenius inner product of matrices $\langle A, B \rangle_F = \text{trace}(A^T B)$, rank of token embedding matrices, tensor contractions.
* **Python Track (`colbert-pytorch`)**: ColBERT architecture from scratch: Query Encoder ($Q \in \mathbb{R}^{32 \times 128}$), Document Encoder ($D \in \mathbb{R}^{L_d \times 128}$), Linear projection layer ($768 \to 128$), Query `[Q]` token padding, Document `[D]` punctuation filtering.
* **C++ Engine (`secan`)**: `MultiVectorIndex` class, SIMD-vectorized MaxSim kernel ($\sum_{q} \max_{d} (q \cdot d)$), token centroid inverted index.

| Day | Linear Algebra (45 min) | Systems / C++ Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Oct 27** | Matrix trace and inner products: $\text{trace}(A B) = \text{trace}(B A)$, Frobenius norm $\|A\|_F = \sqrt{\text{trace}(A^T A)}$. | Research paper: *"ColBERT: Efficient and Effective Passage Search via Late Interaction"* (Khattab & Zaharia 2020). | **Python (`colbert-pytorch`)**: Scaffold clean project (`uv init colbert-pytorch`). Create `src/model.py` and implement ColBERT dual encoder architecture from scratch: BERT backbone + `Linear(768, 128)` + L2 normalization per token. |
| **Tue Oct 28** | Tensor contractions and multi-dimensional dot products: computing pairwise similarities across sets of vectors. | Research paper: *"PLAID: An Efficient Engine for Late Interaction Retrieval"* (Santhanam et al. 2022) §1–4. | **Python (`colbert-pytorch`)**: Implement PyTorch MaxSim operator: `torch.einsum('bsh,bdh->bsd', Q, D).max(dim=2).values.sum(dim=1)`. |
| **Wed Oct 29** | Mathematical analysis of MaxSim vs single-vector dot product: soft alignment across token subspaces. | **INTEL Intrinsics Guide**: Study `_mm256_max_ps`, `_mm256_permute2f128_ps`, cross-lane max reduction. | **secan**: Implement **SIMD-vectorized MaxSim kernel** in C++: process 8 document tokens in parallel with AVX2 FMA + horizontal max reduction. |
| **Thu Oct 30** | Matrix clustering: clustering points in $\mathbb{R}^{128}$ vs clustering subspaces. | **AGNER Ch 13**: Data parallelism, cache layout for multi-vector matrices. | **secan**: Build **token centroid index**: cluster document tokens into centroids ($C=32\text{K}$). Build inverted lists `centroid_id → (doc_id, token_idx)`. |
| **Fri Oct 31** | Review Late Interaction linear algebra properties. | Re-read PLAID paper §3 "Centroid Interaction" + §4 "Decompression and Scoring". | **secan**: Implement centroid candidate pruning: query tokens retrieve candidate documents from centroid inverted lists. Score candidates with MaxSim. |

> **📝 Essay 9 (Sat Nov 1)**: *"Beyond Single Vectors: The Linear Algebra and SIMD Architecture of ColBERT Late Interaction"*  
> Structure: 1. Token matrix representations and Frobenius inner products $\to$ 2. Why single-vector embeddings lose fine-grained lexical context $\to$ 3. PyTorch ColBERT dual-encoder implementation $\to$ 4. Handcrafting AVX2 MaxSim with horizontal max reductions $\to$ 5. Token centroid candidate pruning speedup.

---

### Week 10 (Nov 3–7): Sparse Representations, PLAID Engine & Poisson SLA Tail Latency

**Theme**: Sparse vector spaces, progressive multi-stage pruning, Block-Max WAND, and $p95/p99$ tail latency modeling.

* **Linear Algebra (Strang)**: Chapter 7 (§7.1–7.2) — Sparse matrices, compressed sparse row (CSR) representations, sparse matrix-vector multiplication (SpMV), $L_1$ norm vs $L_2$ norm sparsity.
* **Queuing Theory Analytics**: Poisson process query arrival modeling ($M/M/k$ queue); evaluating $p50, p95, p99, p99.9$ tail latency percentiles under load.
* **Python Track (`colbert-pytorch`)**: Training ColBERT with Margin MSE / in-batch negatives loss, residual token quantization (compressing token embeddings relative to centroids).
* **C++ Engine (`secan`)**: PLAID 3-stage progressive scoring (Centroid $\to$ Quantized MaxSim $\to$ FP32 MaxSim), Sparse Inverted Index with BM25, Block-Max WAND, Poisson query load generator.

| Day | Linear Algebra & Queuing Math (45 min) | Systems / C++ Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Nov 3** | **STRANG §7.1**: Sparse matrices: sparsity patterns, non-zero density, $L_0$ and $L_1$ norms promoting sparsity. | Re-read PLAID §5 on 2-bit/4-bit residual token quantization. | **secan**: Implement 2-bit/4-bit token quantization for ColBERT residuals (`token - centroid`). Build quantized MaxSim kernel. |
| **Tue Nov 4** | **STRANG §7.2**: Compressed Sparse Row (CSR) and Compressed Sparse Column (CSC) data structures. Memory efficiency of sparse matrices. | BM25 algorithm theory: TF-IDF, document length normalization, saturation parameter $k_1$, length parameter $b$. | **secan**: Implement sparse inverted index: `term_id → PostingList{(doc_id, tf)}`. Implement BM25 scoring function. |
| **Wed Nov 5** | Vector space model of Information Retrieval: high-dimensional orthogonal vocabulary spaces ($V \approx 30,000$). | Research paper: *"Faster Top-k Document Retrieval Using Block-Max Indexes"* (Ding & Suel 2011) §1–3. | **secan**: Implement **Block-Max WAND**: store max score per block of 128 postings. Skip non-competitive blocks during traversal. |
| **Thu Nov 6** | **Queuing Theory**: Poisson arrival distribution $P(k \text{ arrivals in } t) = \frac{(\lambda t)^k e^{-\lambda t}}{k!}$. Tail latency SLA modeling. | **CPPHI Parallel Algorithms**: `std::execution::par`, parallel divide-and-conquer search. | **secan**: Build Poisson query load generator in C++. Measure $p50, p95, p99, p99.9$ tail latencies under 500 QPS load. |
| **Fri Nov 7** | Convex combinations of metrics: properties of $\alpha \cdot S_{\text{dense}} + (1-\alpha) \cdot S_{\text{sparse}}$. | **PIKUS Ch 8**: C++20 concurrency features (`std::latch`, `std::barrier`, `std::counting_semaphore`). | **secan**: Implement PLAID 3-stage pipeline end-to-end: Centroid $\to$ Quantized MaxSim $\to$ FP32 MaxSim. Benchmark latency percentiles. |

> **📝 Essay 10 (Sat Nov 8)**: *"PLAID, Block-Max WAND, and Tail Latency: The Engineering of 3-Stage Cascaded Retrieval"*  
> Structure: 1. Sparse vs dense vector space duality $\to$ 2. The computational cost of exhaustive MaxSim on millions of documents $\to$ 3. The 3-stage PLAID cascade architecture in C++20 $\to$ 4. Block-Max WAND early-termination algorithm $\to$ 5. Poisson queueing theory and $p99$ tail latency benchmarking.

---

### Week 11 (Nov 10–14): LSM-Tree Storage Engine, WAL, Apache Arrow & DiskANN

**Theme**: Real-time vector updates, Write-Ahead Logs (WAL), MemTables, columnar Arrow memory layout, and DiskANN SSD streaming.

* **Linear Algebra (Strang)**: Chapter 3 & 4 revisited — Affine subspaces ($x_0 + V$), linear constraints ($Ax = b$), orthogonal projection onto constrained manifolds.
* **Storage Engine Internals**: Log-Structured Merge-Tree (LSM-Tree) architecture for vectors: Write-Ahead Log (WAL), in-memory mutable MemTable HNSW, immutable disk segments in Apache Arrow format, background compaction.
* **C++ Engine (`secan`)**: Implement `LSMVectorEngine`: append-only `wal.bin`, mutable MemTable, immutable Arrow segment flushing, background multi-way compaction thread, DiskANN `io_uring` SSD streaming.

| Day | Storage Engine & Math Reading (45 min) | Systems / C++ Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Nov 10** | **LSM Architecture**: Write-Ahead Log (WAL) for crash recovery; MemTable buffer; SSTable segment immutability principles. | Research paper: *"ACORN: Performant and Predicate-Agnostic Search Over Vector Embeddings"* (Patel et al. 2024). | **secan**: Implement `WriteAheadLog` (`wal.bin`) and in-memory mutable `MemTable` (dynamic HNSW absorbing live writes). |
| **Tue Nov 11** | **Columnar Memory Layout**: Apache Arrow layout specifications: contiguous vector buffers, offset buffers, validity bitmasks. | Research paper: *"DiskANN: Fast Accurate Billion-point NN Search on a Single Node"* (Subramanya et al. 2019). | **secan**: Implement Segment Flusher: when MemTable reaches 100K vectors, flush to immutable disk segment in flat Arrow/Lance layout. |
| **Wed Nov 12** | Mathematical analysis of multi-way segment merging: unifying disjoint neighbor graphs into a single compact graph. | Linux `io_uring` tutorial: submission queue (SQ), completion queue (CQ), zero-copy Direct I/O (`O_DIRECT`). | **secan**: Implement **Background Compaction Thread**: runs asynchronously in `std::jthread` to merge small segments into large optimized graphs. |
| **Thu Nov 13** | Distance geometry under missing coordinates / masked dimensions. | **ASYNC Ch 6 & Ch 9**: Boost.Asio I/O concepts, profiling asynchronous workflows. | **secan**: Implement DiskANN-style disk search: store vectors on disk with `O_DIRECT`. Fetch candidates asynchronously during beam search via `io_uring`. |
| **Fri Nov 14** | Review constrained optimization and LSM storage trade-offs. | **FINSY Ch 3**: High-performance system measurement, scaling modules, latency distributions. | **secan**: Benchmark live ingestion throughput (inserts/sec) during concurrent search traffic. Verify 0-data-loss crash recovery via WAL replay. |

> **📝 Essay 11 (Sat Nov 15)**: *"LSM-Trees for Vector Databases: Write-Ahead Logs, MemTables, and Apache Arrow Storage"*  
> Structure: 1. Why static vector indexes fail live-update workloads $\to$ 2. The LSM-Tree vector storage architecture (WAL + MemTable + Segments) $\to$ 3. Zero-copy Apache Arrow columnar memory layouts $\to$ 4. Background multi-way graph compaction $\to$ 5. DiskANN SSD streaming with Linux `io_uring`.

---

### Week 12 (Nov 17–21): Zero-Copy Bindings, Concurrent Index & Block 1 Capstone

**Theme**: Production C++ packaging, zero-copy Python interoperability, and CPU engine validation.

* **Linear Algebra (Strang)**: Review Chapters 1, 2, 3, 5, 6, 7 — comprehensive synthesis of all vector space, orthogonality, SVD, and graph matrix concepts.
* **Python Track**: Full Python SDK for `secan`: `import secan`, `index = secan.LSMIndex(dim=128)`, `index.insert(numpy_array)`, `index.search(query, k=10)`.
* **C++ Engine (`secan`)**: Zero-copy Python bindings via `nanobind`, concurrent read-write HNSW with per-node reader-writer locks, memory-mapped binary index serialization, complete `ann-benchmarks` evaluation.

| Day | Linear Algebra (45 min) | Systems / Architecture Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Nov 17** | Synthesis: The mathematical roadmap from dot products to SVD to graph routing. | `nanobind` documentation: zero-copy buffer protocol, NumPy type casters, ownership models. | **secan**: Set up `python/` directory with `nanobind`. Expose `LSMIndex`, `HNSWIndex`, `IVFPQIndex`, and `MultiVectorIndex` to Python. |
| **Tue Nov 18** | Matrix condition numbers and numerical stability in production retrieval systems. | **PIKUS Ch 6 & ASYNC Ch 3**: Reader-writer locks, fine-grained concurrency, thread-safe data structures. | **secan**: Implement **concurrent HNSW**: per-node `std::shared_mutex`. Multiple concurrent searches (shared lock) + live insertions (exclusive lock). |
| **Wed Nov 19** | Memory layout of multi-dimensional tensors: strides, contiguous vs non-contiguous memory in NumPy/C++. | **CPPHI Memory Management & FINSY Ch 5**: Custom memory allocators, memory-mapped files. | **secan**: Implement memory-mapped serialization: `save(path)` writes header + CSR graph + vectors. `load(path)` uses `mmap` for instant loading. |
| **Thu Nov 20** | Review all Strang chapters and prepare personal mathematical cheat-sheet. | `ann-benchmarks` protocol: standardized evaluation across dataset sizes, recall levels, and build times. | **secan**: Run `ann-benchmarks` suite on SIFT1M and Cohere-1M. Plot Pareto frontier of `secan` vs `hnswlib` and `faiss`. |
| **Fri Nov 21** | — | **PIKUS Ch 12**: Design retrospective. | **Block 1 Grand Finale**: Update README with full benchmark suite. Tag `v1.0-cpu-complete`. Prepare CUDA GPU environment. |

> **📝 Essay 12 (Sat Nov 22)**: *"secan v1.0: Architectural Blueprint of a Modern C++20 Vector Engine with Python Bindings"*  
> Structure: 1. Mathematical synthesis of high-dimensional indexing $\to$ 2. The C++20 engine architecture: distance kernels $\to$ quantization $\to$ CSR graph $\to$ 3. Zero-copy Python bindings via `nanobind` $\to$ 4. Comprehensive benchmarks against Faiss and HNSWLib $\to$ 5. Lessons learned from 3 months of CPU optimization.

---

# BLOCK 2: GPU ACCELERATION, FLASHATTENTION & MULTIMODAL (Months 4–6)

---

# 📅 MONTH 4: CUDA Architecture, FlashAttention Kernel & Tensor Cores (Dec 2026)

---

### Week 13 (Nov 24–28): CUDA Programming Model, GPU Architecture & Naive Kernels

**Theme**: The massively parallel SIMT execution model and writing first GPU distance kernels.

* **Linear Algebra (Strang)**: Chapter 7 (§7.3–7.4) — Numerical linear algebra, matrix norms, condition numbers, floating-point error propagation in large-scale matrix operations.
* **Python Track**: Multi-GPU tensor parallelism basics in PyTorch (`torch.nn.DataParallel`, `torch.distributed`), CUDA stream synchronization in PyTorch.
* **C++ Engine (`secan`)**: CUDA CMake integration, `compute-sanitizer` memory checker harness, `GpuBuffer<T>` RAII wrapper, naive GPU L2 distance kernel.

| Day | Linear Algebra (45 min) | GPU / CUDA Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Nov 24** | **STRANG §7.3**: Matrix condition number $\kappa(A) = \|A\| \|A^{-1}\| = \frac{\sigma_{\max}}{\sigma_{\min}}$. Ill-conditioned systems. | **PMPP Ch 1–2**: Heterogeneous computing, SIMT execution model, latency hiding via massive hardware multithreading. | **secan**: Add CUDA to CMakeLists.txt (`enable_language(CUDA)`). Create `src/gpu/`. Configure `compute-sanitizer` test script. |
| **Tue Nov 25** | **STRANG §7.4**: Iterative methods for linear systems: Jacobi and Gauss-Seidel as parallel matrix operations. | **PMPP Ch 3**: Grid, Block, Thread hierarchy. Computing linear memory indices from `threadIdx`, `blockIdx`, `blockDim`. | **secan**: Implement RAII `GpuBuffer<T>` class for device memory allocation (`cudaMalloc`, `cudaFree`, `cudaMemcpy`). |
| **Wed Nov 26** | Parallel matrix-vector multiplication algorithms and mathematical communication complexity. | **PMPP Ch 4**: Compute Architecture: Streaming Multiprocessors (SMs), warps (32 threads), warp divergence, occupancy. | **secan**: Implement naive GPU L2 distance kernel: 1 thread per vector pair. Benchmark against CPU AVX2 on single query. |
| **Thu Nov 27** | Error accumulation in massively parallel floating-point sum reductions. | **CUDA-GUIDE Memory Hierarchy**: Global memory (HBM/GDDR), Shared memory (SRAM), Registers, Constant memory. | **secan**: Implement dataset upload: store SIFT1M in GPU global memory. Implement batch brute-force scan kernel (1 block per query). |
| **Fri Nov 28** | Geometric analysis of parallel batch vector comparisons. | **PMPP Ch 5**: Memory architecture, shared memory tiling, bank conflicts, memory coalescing principles. | **secan**: Implement **shared memory tiled** L2 kernel: load query and dataset tiles into shared memory. Benchmark tiled vs naive. |

> **📝 Essay 13 (Sat Nov 29)**: *"GPU Architecture for Vector Search: Why Naive CUDA Kernels Lose to CPU AVX2"*  
> Structure: 1. Numerical linear algebra and parallel matrix operations $\to$ 2. The GPU SIMT execution model (SMs, warps, shared memory, HBM) $\to$ 3. Why single-query GPU search suffers from PCIe transfer latency $\to$ 4. Memory tiling and `compute-sanitizer` verification $\to$ 5. The batching crossover point.

---

### Week 14 (Dec 1–5): Memory Coalescing, Warp Reductions & GPU Top-K

**Theme**: Memory throughput saturation and fast warp-level parallel reductions.

* **Linear Algebra**: Matrix transposition properties ($A^T$, column-major vs row-major layouts in memory), memory coalescing geometry.
* **Python Track**: Writing custom PyTorch CUDA C++ extensions with `torch.utils.cpp_extension`.
* **C++ Engine (`secan`)**: Coalesced GPU distance kernel, warp shuffle reductions (`__shfl_down_sync`), GPU top-$k$ selection using partial bitonic sort.

| Day | Linear Algebra (45 min) | GPU / CUDA Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Dec 1** | Row-major vs Column-major matrix layouts: index mapping $A[i, j] = i \cdot C + j$ vs $j \cdot R + i$. | **PMPP Ch 6**: Performance considerations: memory coalescing patterns, maximizing global memory bus utilization. | **secan**: Implement **coalesced GPU distance kernel**: ensure adjacent threads in a warp access consecutive memory addresses. |
| **Tue Dec 2** | Parallel reduction trees: logarithmic depth reductions $\sum_{i=1}^N x_i$ in $O(\log N)$ parallel steps. | **PMPP Ch 10**: Parallel reductions, warp shuffle primitives (`__shfl_down_sync`), eliminating shared memory bank conflicts. | **secan**: Implement **warp-level reduction**: use `__shfl_down_sync` to reduce 32 partial sums inside a warp with zero shared memory overhead. |
| **Wed Dec 3** | Algebraic properties of metric spaces under batch vector transformations. | **CUDA-GUIDE Warp Primitives**: `__shfl_sync`, `__shfl_xor_sync`, `__ballot_sync`, `__any_sync`, Cooperative Groups. | **secan**: Implement batched GPU scanner: process $B=256$ queries simultaneously. Each block processes a query; warps scan dataset chunks. |
| **Thu Dec 4** | 2D matrix tiling for distance matrices $D_{i,j} = \|q_i - x_j\|^2$. | **PMPP Ch 7**: Tiling patterns, halo cells, constant memory for read-only query parameters. | **secan**: Implement fused Cosine similarity GPU kernel: dot product + norms in a single pass. Add inner-product kernel. |
| **Fri Dec 5** | Sorting networks: Bitonic sort mathematical proof and parallel sorting steps. | **PMPP Ch 11–12**: Parallel merge and sorting on GPU: partial bitonic sort, warp-cooperative top-$k$ selection. | **secan**: Implement **GPU top-k selection**: warp-cooperative partial bitonic sort extracting top-$k$ without sorting all $N$ distances. |

> **📝 Essay 14 (Sat Dec 6)**: *"Warp Shuffles and Memory Coalescing: Saturating GPU Memory Bandwidth in Vector Search"*  
> Structure: 1. Memory layout geometry and reduction tree mathematics $\to$ 2. Why uncoalesced memory reads waste 87% of HBM bandwidth $\to$ 3. Warp shuffle `__shfl_down_sync` reduction code $\to$ 4. GPU partial bitonic top-$k$ selection $\to$ 5. Nsight Compute throughput validation.

---

### Week 15 (Dec 8–12): FlashAttention CUDA Kernel from Scratch & Tensor Cores

**Theme**: IO-aware attention, fused Online Softmax CUDA kernel, and Tensor Core GEMM.

* **Linear Algebra**: Matrix tiling algebra, Online Softmax numerical stability proofs, reforming attention as block-wise matrix products without intermediate materialization.
* **Frontier Reading**: *"FlashAttention: Fast and Memory-Efficient Exact Attention with IO-Awareness"* (Dao et al. 2022) + FlashAttention-2 (Dao 2023).
* **Implementation (`transformers-pytorch` & CUDA)**: Handcrafted **FlashAttention Forward CUDA Kernel** from scratch: load $Q$ tile into SRAM, loop over $K, V$ blocks, compute block attention, update running $m$ and $\ell$ via Online Softmax, scale and accumulate output $O$ in SRAM, write output to HBM.

| Day | Mathematical & Paper Reading (45 min) | GPU / CUDA Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Dec 8** | FlashAttention Paper §1–3: IO-Awareness, HBM vs SRAM bandwidth gap ($1.5\text{TB/s}$ vs $19\text{TB/s}$). IO complexity analysis ($O(N^2 d / M)$ vs $O(N d)$). | **PMPP Ch 16 / NVIDIA Docs**: Tensor Core architecture, WMMA API, mapping block matrix multiplies to Tensor Cores. | **CUDA**: Set up FlashAttention kernel scaffolding: grid configuration ($B \times H$), shared memory allocation for $Q_{block}, K_{block}, V_{block}, O_{block}$. |
| **Tue Dec 9** | FlashAttention Algorithm 1: Step-by-step mathematical tracing of outer loop over $K, V$ blocks and inner loop over $Q$ blocks. | CUDA Shared Memory banking: avoiding bank conflicts when loading $Q, K^T$ tiles. | **CUDA**: Implement block GEMM $S_{ij} = Q_i K_j^T / \sqrt{d}$ in shared memory. Verify intermediate values against PyTorch. |
| **Wed Dec 10** | Online Softmax Rescaling Mathematics: proving $O_{new} = \text{diag}(\ell_{new})^{-1} (\text{diag}(\ell_{prev}) e^{m_{prev} - m_{new}} O_{prev} + e^{S_{ij} - m_{new}} V_j)$. | **CUDA-GUIDE Warp Primitives**: `__shfl_sync` for warp-level row max and row sum reductions. | **CUDA**: Implement Online Softmax update in registers: compute block max $\tilde{m}$, new max $m_{new}$, update $\ell$, rescale accumulator $O$. |
| **Thu Dec 11** | FlashAttention-2 Innovations: swapping loop order (outer loop over $Q$, inner loop over $K, V$) to eliminate shared memory writes of $O$. | CUTLASS epilogue visitor patterns for fused matrix scaling. | **CUDA**: Optimize kernel to FlashAttention-2 loop order. Partition warps along the sequence dimension to reduce inter-warp synchronization. |
| **Fri Dec 12** | Review: FLOPs vs Memory IO roofline comparison of Standard Attention vs FlashAttention. | Profile kernel with NVIDIA Nsight Compute (`ncu`): measure DRAM bandwidth reduction and achieved TFLOPS. | **Python & CUDA**: Expose custom FlashAttention kernel to PyTorch via `torch.utils.cpp_extension`. Benchmark speedup vs `torch.nn.functional.scaled_dot_product_attention`. |

> **📝 Essay 15 (Sat Dec 13)**: *"Building FlashAttention from Scratch in CUDA: IO-Aware Tiling and Online Softmax"*  
> Structure: 1. The $O(N^2)$ memory bandwidth bottleneck of standard attention $\to$ 2. The Online Softmax algebraic derivation $\to$ 3. Complete CUDA implementation walkthrough: SRAM tiling, warp reduction, and register rescaling $\to$ 4. `ncu` profiling showing 80% DRAM traffic elimination $\to$ 5. Benchmarking against PyTorch standard attention.

---

### Week 16 (Dec 15–19): GPU-Resident IVF Index & CUDA Streams

**Theme**: Coarse Voronoi cell search running entirely within GPU VRAM with pipelined execution.

* **Linear Algebra**: Voronoi tessellation of high-dimensional Euclidean space, centroid assignment matrices.
* **Python Track**: PyTorch GPU memory management: caching allocator, memory fragmentation, custom PyTorch allocators.
* **C++ Engine (`secan`)**: GPU-resident IVF index (`GpuIVFIndex`), warp-cooperative cell scanning, CUDA streams for pipelined query execution.

| Day | Linear Algebra (45 min) | GPU / CUDA Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Dec 15** | Geometry of Voronoi partitions in $\mathbb{R}^D$: hyperplanes separating adjacent centroid regions. | Research paper: *"Billion-Scale Similarity Search with GPUs"* (Johnson, Douze, Jégou / Faiss GPU 2019) §1–3. | **secan**: Design GPU IVF memory layout: coarse centroids in global/constant memory; cell vectors stored as packed arrays with offset table. |
| **Tue Dec 16** | Centroid distance bounding: triangle inequality for pruning distant Voronoi cells. | Faiss GPU paper §4–5: GPU $k$-selection, warp-cooperative list scanning. | **secan**: Implement GPU coarse quantizer: compute query-to-centroid distances on GPU; select top-`nprobe` cells with warp selection. |
| **Wed Dec 17** | Parallel cell processing: work distribution across variable-length inverted lists. | **CUDA-GUIDE Streams & Events**: Concurrent kernel execution, overlapping compute and data transfer. | **secan**: Implement **warp-cooperative cell scan**: within each selected cell, warps cooperatively scan vectors and update partial top-$k$. |
| **Thu Dec 18** | Integer quantization inside Voronoi cells: local affine transformations. | **PMPP Ch 13–14**: Irregular data structures, handling load imbalance across variable-length blocks. | **secan**: Implement GPU IVF-SQ8: store cell vectors as `uint8`. Implement integer distance kernel inside cells. |
| **Fri Dec 19** | Analytical trade-off: `nprobe` vs Voronoi cell radius vs Recall@10. | Review CUDA stream synchronization patterns. | **secan**: Implement **CUDA stream pipelining**: overlap query batch $N+1$ coarse search with batch $N$ cell scanning. Benchmark. |

> **📝 Essay 16 (Sat Dec 20)**: *"GPU-Resident IVF: Pipelining Voronoi Cell Search with CUDA Streams at 100K QPS"*  
> Structure: 1. Voronoi tessellations in high dimensions $\to$ 2. The GPU memory layout for irregular inverted lists $\to$ 3. Warp-cooperative scanning across cells $\to$ 4. CUDA stream double-buffering timeline $\to$ 5. GPU IVF-SQ8 throughput benchmark.

---

# 📅 MONTH 5: GPU Graph Algorithms, Quantization & Multi-GPU (Jan 2027)

---

### Week 17 (Dec 22–26): GPU Graph Search (CAGRA Architecture)

**Theme**: Massively parallel graph beam search directly within GPU global memory.

* **Linear Algebra**: Graph adjacency matrices, warp-level graph traversal, fixed-degree regular graph approximations.
* **Python Track**: Graph Neural Networks (GNN) baseline in PyTorch: Message Passing Neural Networks (MPNN), adjacency matrix multiplication.
* **C++ Engine (`secan`)**: GPU HNSW/CAGRA-style graph traversal, warp-cooperative neighbor evaluation, visited-set bitmasks with `__ballot_sync`.

| Day | Linear Algebra (45 min) | GPU / CUDA Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Dec 22** | Graph adjacency matrix powers: $A^k[i, j]$ gives number of walks of length $k$. Graph expansion properties. | Research paper: *"CAGRA: Highly Parallel Graph Construction and ANN Search for GPUs"* (NVIDIA 2024) §1–4. | **secan**: Design GPU graph layout: store HNSW graph adjacency in GPU memory as a fixed-degree CSR array with padding. |
| **Tue Dec 23** | Degree distributions in small-world graphs; spectral gap of regularized graph matrices. | CAGRA paper §5–6: Search kernel design, warp-level parallel beam search, avoiding dynamic queues on GPU. | **secan**: Implement **GPU graph search kernel**: each warp processes 1 query. 32 threads in warp evaluate 32 candidate neighbors in parallel. |
| **Wed Dec 24** | Mathematical formulation of beam search frontier expansion. | **CUDA-GUIDE Warp Primitives**: `__ballot_sync`, `__any_sync`, warp-local bitfield operations. | **secan**: Implement warp-level visited set using `__ballot_sync` bitfields. Implement warp-level top-$k$ beam with shuffle min-reduction. |
| **Thu Dec 25** | Graph spectral clustering: partitioning large graphs across GPU memory. | **PMPP Ch 9**: Parallel Prefix Sum (Scan) for compacting candidate neighbor lists on GPU. | **secan**: Implement multi-query parallel graph search: launch grid of warps. Benchmark throughput vs CPU HNSW. |
| **Fri Dec 26** | Trade-offs: random memory access in graph traversal vs sequential scanning in IVF. | Profile GPU graph search with `ncu`: measure compute-to-memory stall ratio. | **secan**: Optimize GPU graph search: add shared memory caching for frequently visited upper-layer hub nodes. |

> **📝 Essay 17 (Sat Dec 27)**: *"CAGRA and GPU Graph Traversal: Overcoming Random Memory Access at Warp Scale"*  
> Structure: 1. Graph adjacency spectra and small-world routing $\to$ 2. Why traditional dynamic queues stall on GPUs $\to$ 3. Warp-cooperative neighbor expansion and `__ballot_sync` bitfields $\to$ 4. `ncu` compute vs memory stall analysis $\to$ 5. CAGRA vs CPU HNSW benchmark.

---

### Week 18 (Dec 29 – Jan 2): GPU Product Quantization & Warp-Shuffle FastScan

**Theme**: Quantized distance computation in GPU shared memory and warp-register lookups.

* **Linear Algebra**: Subspace projection matrices in GPU shared memory, orthogonal codebook transformations.
* **Python Track**: Vector Quantization in PyTorch: Vector Quantized Variational Autoencoder (VQ-VAE) codebook training.
* **C++ Engine (`secan`)**: GPU PQ ADC kernel (LUT in shared memory), GPU FastScan using warp shuffles (`__shfl_sync`), GPU IVF-PQ combined index.

| Day | Linear Algebra (45 min) | GPU / CUDA Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Dec 29** | Mathematical analysis of subspace distance lookups: expressing table lookups as sparse matrix products. | Faiss GPU PQ documentation: storing query lookup tables in GPU shared memory. | **secan**: Implement GPU PQ ADC kernel: upload query LUT to shared memory. Threads compute PQ distances via shared-memory lookups. |
| **Tue Dec 30** | Shared memory bank conflict mathematics: 32 banks, 4 bytes/bank, conflict-free stride conditions. | **CUDA-GUIDE Shared Memory**: Bank conflicts, padding strategies, broadcast mechanisms. | **secan**: Optimize shared-memory LUT layout: apply padding to ensure conflict-free broadcast reads during distance accumulation. |
| **Wed Dec 31** | In-register permutation algebra: mapping permutation matrices to warp shuffles. | Research: GPU FastScan architecture using warp-level registers. | **secan**: Implement **GPU 4-bit FastScan**: store 16 centroid distances in warp registers. Execute lookups via `__shfl_sync(mask, dist, code)`. |
| **Thu Jan 1** | Two-stage candidate filtering error bounds on GPU. | **PMPP Ch 18**: Multi-GPU concepts, CUDA IPC, peer-to-peer memory access. | **secan**: Implement **GPU IVF-PQ**: combine GPU coarse cell routing with GPU FastScan distance inside cells. |
| **Fri Jan 2** | SVD and anisotropic loss in GPU quantization codebooks. | Review all GPU quantization kernels. | **secan**: Benchmark GPU-FP32 vs GPU-FP16 vs GPU-SQ8 vs GPU-IVF-PQ vs GPU-FastScan. Create comprehensive comparison table. |

> **📝 Essay 18 (Sat Jan 3)**: *"GPU Quantization: Shared-Memory LUTs and Warp-Shuffle In-Register Lookups"*  
> Structure: 1. Subspace projection algebra $\to$ 2. Bank-conflict-free shared-memory LUT design $\to$ 3. GPU FastScan using `__shfl_sync` as a register permutation engine $\to$ 4. GPU IVF-PQ full search pipeline $\to$ 5. Throughput comparison table.

---

### Week 19 (Jan 5–9): PagedAttention (vLLM Architecture) & Async CPU↔GPU Pipeline

**Theme**: Virtual memory paging for GPU KV caches and asynchronous double-buffering.

* **Systems Reading**: CS:APP Chapter 9 "Virtual Memory" (§9.1–9.6) applied to GPU memory management.
* **Frontier Reading**: *"Efficient Memory Management for Large Language Model Serving with PagedAttention"* (Kwon et al. 2023 / vLLM).
* **Implementation (`transformers-pytorch` & `secan`)**: 
  * **Python/CUDA**: Implement **PagedAttention Block Table**: non-contiguous physical GPU block allocation for dynamic sequences, eliminating KV cache internal/external memory fragmentation.
  * **secan**: Double-buffered async pinned memory pipeline (`cudaHostAlloc`) overlapping batch search compute with PCIe transfers.

| Day | Systems / Math Reading (45 min) | GPU / vLLM Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Jan 5** | **CSAPP §9.1–9.4**: Physical vs virtual addressing, page tables, page faults, demand paging mathematics. | vLLM Paper §1–3: The KV Cache fragmentation problem in LLMs ($60\%–80\%$ memory wasted on over-allocation). | **Python/CUDA**: Implement `BlockTable` data structure in PyTorch: maps logical sequence tokens to physical GPU memory blocks (block size 16). |
| **Tue Jan 6** | **CSAPP §9.5–9.6**: Multi-level page tables, TLB caching, address translation equations. | vLLM Paper §4: PagedAttention kernel design: reading $K, V$ blocks via block lookup table in CUDA. | **CUDA**: Implement **PagedAttention CUDA kernel**: during self-attention, resolve physical $K, V$ block pointers on-the-fly via block table. |
| **Wed Jan 7** | Mathematical design of clean C++ RAII abstractions for heterogeneous memory. | NVIDIA cuVS API design and architecture review. | **secan**: Build unified `GpuIndex` wrapper class: handles device memory lifecycle, async transfers, kernel launches, RAII cleanup. |
| **Thu Jan 8** | Dataset partitioning mathematics: splitting matrices across RAM and VRAM. | **PMPP Ch 19**: Heterogeneous CPU+GPU workload partitioning. | **secan**: Implement **CPU↔GPU hybrid fallback**: partition oversized dataset into GPU VRAM (fast) and CPU RAM (AVX2). Merge results. |
| **Fri Jan 9** | Calculating the exact batch size crossover point where GPU throughput exceeds CPU. | Profile PagedAttention vs standard KV cache memory utilization in PyTorch. | **secan**: Benchmark query batch sizes ($B=1, 10, 100, 1000$). Plot the CPU vs GPU crossover curve. |

> **📝 Essay 19 (Sat Jan 10)**: *"PagedAttention and Virtual Memory: How OS Principles Solved the LLM Memory Wall"*  
> Structure: 1. Virtual memory theory and page table translation $\to$ 2. Why contiguous KV cache allocation wastes 80% of GPU memory $\to$ 3. PagedAttention block table architecture in CUDA $\to$ 4. Async double-buffered PCIe pipeline in `secan` $\to$ 5. Memory fragmentation elimination benchmark.

---

### Week 20 (Jan 12–16): Multi-GPU Sharded Index & NCCL Aggregation

**Theme**: Scaling vector search across multiple GPUs using data sharding and collective communication.

* **Linear Algebra**: Block-row and block-column matrix partitioning across distributed devices, global top-$k$ reduction mathematics.
* **Python Track**: PyTorch Distributed Data Parallel (DDP) and `torch.distributed` collective operations (`all_reduce`, `all_gather`).
* **C++ Engine (`secan`)**: `MultiGpuIndex` class, dataset sharding across GPUs, NCCL AllGather result aggregation, multi-GPU load balancing.

| Day | Linear Algebra (45 min) | GPU / CUDA Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Jan 12** | Sharding matrices: horizontal sharding (split vectors $N/G$) vs vertical sharding (split dimensions $D/G$). | **CUDA-GUIDE Multi-GPU**: `cudaSetDevice`, peer-to-peer memory access (`cudaDeviceEnablePeerAccess`). | **secan**: Implement dataset sharding: split $N$ vectors into $G$ shards. Upload shard $i$ to GPU $i$. Build `MultiGpuIndex` class. |
| **Tue Jan 13** | Distributed top-$k$ reduction: proving that $\text{TopK}(\bigcup_{i=1}^G \text{TopK}_i(D_i)) = \text{TopK}(\bigcup_{i=1}^G D_i)$. | NCCL Documentation: `ncclAllGather`, `ncclAllReduce`, ring-based collective algorithms. | **secan**: Implement multi-GPU brute-force search: each GPU searches local shard; use NCCL AllGather to merge per-GPU top-$k$ heaps. |
| **Wed Jan 14** | Sharding inverted file indexes: replicating centroids vs sharding Voronoi cells. | Faiss multi-GPU implementation: replicated coarse quantizer with sharded inverted lists. | **secan**: Implement **multi-GPU IVF**: replicate coarse centroids on all GPUs; shard inverted lists across GPUs. Route queries via NCCL. |
| **Thu Jan 15** | Load balancing algorithms for unevenly distributed Voronoi cells across GPUs. | NVLink vs PCIe inter-GPU bandwidth analysis. | **secan**: Implement dynamic load balancing: redistribute heavy IVF cells across GPUs to prevent stragglers during multi-probe search. |
| **Fri Jan 16** | Amdahl's Law for multi-GPU scaling: parallel efficiency $\eta = \frac{T_1}{G \cdot T_G}$. | Measure multi-GPU scaling efficiency across 1, 2, and 4 GPUs on synthetic billion-scale data. | **secan**: Benchmark multi-GPU search on SIFT1M and large synthetic datasets. Measure scaling efficiency and communication overhead. |

> **📝 Essay 20 (Sat Jan 17)**: *"Distributed Nearest Neighbors: Multi-GPU Sharding and NCCL Collective Reductions"*  
> Structure: 1. Mathematical correctness of distributed top-$k$ reductions $\to$ 2. Sharding strategies: data-parallel vs index-parallel $\to$ 3. Multi-GPU IVF with NCCL AllGather $\to$ 4. Load balancing and straggler prevention $\to$ 5. Multi-GPU scaling efficiency plots.

---

# 📅 MONTH 6: Multimodal ColPali, Kernel Fusion & Master Release (Feb 2027)

---

### Week 21 (Jan 19–23): ColPali (Vision-Language Retrieval) & GPU ColBERT MaxSim

**Theme**: Extending Late Interaction to visual document retrieval using Vision Transformers.

* **Linear Algebra**: Tensor contractions for multi-vector matrices, cross-modal metric learning, cosine similarity in shared multimodal spaces.
* **Frontier Reading**: *"ColPali: Efficient Document Retrieval with Vision Language Models"* (Faysse et al. 2024).
* **Implementation (`colbert-pytorch` & `secan`)**:
  * **Python**: Build **ColPali visual retrieval pipeline**: pass document page images through ViT patch encoder $\to$ generate token embedding matrices $\to$ score text queries against visual document patches via MaxSim.
  * **secan**: GPU MaxSim kernel via batched CUTLASS GEMM + warp reductions; GPU NN-Descent for fast graph construction.

| Day | Linear Algebra / Paper Reading (45 min) | GPU / CUDA Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Jan 19** | Multi-vector tensor geometry: batch matrix multiplications for token similarity matrices $S = Q D_i^T$. | Re-read ColBERT/PLAID papers with GPU focus: mapping MaxSim to batched GEMM + reductions. | **secan**: Implement **GPU MaxSim kernel**: formulate cross-token similarity as CUTLASS GEMM followed by warp row-max + column-sum reductions. |
| **Tue Jan 20** | ColPali Paper §1–3: Bypassing OCR by treating document image patches as visual tokens. | Research paper: *"Efficient K-NN Graph Construction for Generic Similarity Measures"* (Dong, Moses, Li / NN-Descent 2011). | **Python (ColPali)**: Build `ColPaliPipeline`: connect ViT patch projector (Month 2) to ColBERT MaxSim scoring head. |
| **Wed Jan 21** | Symmetric contrastive loss mathematics: $\mathcal{L} = -\frac{1}{2} \left[ \log \frac{e^{\langle u_i, v_i \rangle / \tau}}{\sum e^{\langle u_i, v_j \rangle / \tau}} + \log \frac{e^{\langle v_i, u_i \rangle / \tau}}{\sum e^{\langle v_j, u_i \rangle / \tau}} \right]$. | CAGRA paper §3–4: GPU NN-Descent implementation, warp-level neighbor exchange. | **secan**: Implement GPU NN-Descent base layer graph construction in CUDA. |
| **Thu Jan 22** | Contrastive temperature parameter $\tau$: geometric effect on embedding hypersphere clustering. | **CUDA-GUIDE Dynamic Parallelism**: Launching child kernels from within a running kernel. | **Python (ColPali)**: Export document image patch embeddings to `secan` multi-vector index format. |
| **Fri Jan 23** | Multi-modal vector space alignment: text queries searching image patch embeddings. | Review GPU ColBERT and ColPali integration. | **secan**: Ingest ColPali visual embeddings into `secan` GPU index. Execute text query $\to$ visual page search. |

> **📝 Essay 21 (Sat Jan 24)**: *"ColPali and Vision-Language Retrieval: Scoring Visual Document Patches with GPU MaxSim"*  
> Structure: 1. Why traditional OCR + text embedding pipelines fail on visual documents $\to$ 2. The ColPali architecture: ViT visual patch tokens $\to$ 3. Decomposing ColPali MaxSim into CUTLASS GEMM + warp reductions on GPU $\to$ 4. GPU NN-Descent graph construction $\to$ 5. End-to-end multimodal search benchmark.

---

### Week 22 (Jan 26–30): GPU Kernel Fusion, Occupancy Tuning & Nsight Profiling

**Theme**: Eliminating global memory round-trips via fused kernels and maximizing SM occupancy.

* **Linear Algebra**: Matrix fusion algebra: combining distance computation, normalization, and top-$k$ heap filtering into a single operator.
* **Python Track**: PyTorch JIT compiler (`torch.jit.trace`, `torch.compile`), TorchScript export for C++ deployment.
* **C++ Engine (`secan`)**: Fused distance + top-$k$ kernel, register tiling, occupancy tuning with `__launch_bounds__`, non-coherent cache loads (`__ldg()`).

| Day | Linear Algebra (45 min) | GPU / CUDA Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Jan 26** | Mathematical analysis of intermediate memory traffic in multi-step vector operations. | **CUDA-GUIDE Occupancy Calculator**: Shared memory vs register limits per SM. | **secan**: Profile all GPU kernels with NVIDIA Nsight Compute (`ncu`). Identify compute-bound vs memory-bound bottlenecks. |
| **Tue Jan 27** | Operator fusion algebra: merging $\text{TopK}(\text{Distance}(Q, X))$ into a single mathematical step. | Research: Kernel fusion techniques in CUB and Thrust libraries. | **secan**: Implement **fused distance+topk kernel**: maintain thread-local top-$k$ heap in registers/shared memory, writing only final results to global memory. |
| **Wed Jan 28** | Register file utilization: keeping intermediate values in 256KB register file per SM. | **PMPP Ch 5**: Register tiling strategies to eliminate shared memory round-trips. | **secan**: Implement **register-tiled distance computation**: unroll inner dimension loops into registers to maximize ILP on GPU. |
| **Thu Jan 29** | Cache bypass and non-coherent memory access: PTX `ld.global.nc` instruction. | **CUDA-GUIDE PTX ISA**: Read-only texture cache path (`__ldg()`), `__launch_bounds__` compiler directives. | **secan**: Add `__ldg()` intrinsic for dataset vector reads; tune `__launch_bounds__(threads_per_block, min_blocks_per_sm)`. |
| **Fri Jan 30** | Roofline model analysis of optimized fused GPU kernels. | Nsight Compute comparison: before vs after fusion profiling. | **secan**: Run full GPU benchmark suite. Compare initial Week 13 naive kernels vs final Week 22 fused kernels ($10\times–50\times$ speedup). |

> **📝 Essay 22 (Sat Jan 31)**: *"GPU Kernel Fusion and Register Tiling: Eliminating DRAM Round-Trips in CUDA Vector Search"*  
> Structure: 1. Memory traffic math of multi-pass pipelines $\to$ 2. Why separate distance and reduction passes choke on HBM bandwidth $\to$ 3. Fused distance+top-$k$ CUDA implementation $\to$ 4. Register tiling and `__launch_bounds__` tuning $\to$ 5. Nsight Compute roofline comparison.

---

### Week 23 (Feb 2–6): ARM NEON, Cross-Platform SIMD & Edge Vector Search

**Theme**: Cross-platform portability, ARM NEON intrinsics, and running on Apple Silicon & AWS Graviton.

* **Linear Algebra**: Dimension padding and vector chunking across varying SIMD register widths (128-bit NEON vs 256-bit AVX2 vs 512-bit AVX-512).
* **Python Track**: ONNX runtime export (`torch.onnx.export`) of PyTorch Transformer/ViT models for cross-platform CPU/edge execution.
* **C++ Engine (`secan`)**: ARM NEON distance kernels (`float32x4_t`, `vfmaq_f32`, `vaddvq_f32`), compile-time and runtime CPU feature detection (`cpuid`), cross-platform CMake CI.

| Day | Linear Algebra (45 min) | Systems / ARM Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Feb 2** | Register width geometry: mapping 128D vectors across 128-bit (4 floats), 256-bit (8 floats), and 512-bit (16 floats) lanes. | ARM NEON Intrinsics Guide: `vld1q_f32`, `vfmaq_f32`, `vaddvq_f32`, `vmaxvq_f32`. | **secan**: Design unified SIMD abstraction layer: `namespace simd { float l2_squared(const float*, const float*, int); }` with dispatch. |
| **Tue Feb 3** | Horizontal vector reductions in ARM NEON: comparing NEON's direct `vaddvq_f32` with x86's shuffle chains. | ARM NEON programming manual: 128-bit vector types (`float32x4_t`, `uint8x16_t`), FMA instruction throughput. | **secan**: Implement `l2_squared_neon()` and `cosine_distance_neon()` using ARM NEON intrinsics with 4-way accumulator unrolling. |
| **Wed Feb 4** | Integer quantization arithmetic on ARM: `vmull_u8` (multiply uint8 $\to$ uint16), `vpadalq_u16` (accumulate uint16 $\to$ uint32). | **AGNER Ch 14**: Cross-platform optimization, compiler-specific intrinsics differences. | **secan**: Implement NEON integer kernels: `l2_squared_sq8_neon()` and `cosine_distance_sq8_neon()`. |
| **Thu Feb 5** | Hardware capability detection algorithms across OS and CPU architectures. | Research: runtime CPU dispatch patterns in Faiss and HNSWLib (`platform_macros.h`). | **secan**: Implement runtime CPU feature detection: `cpuid` on x86, `/proc/cpuinfo` / `sysctl` on ARM. Configure dynamic dispatch. |
| **Fri Feb 6** | Floating-point reproducibility across diverse CPU microarchitectures. | Set up cross-platform CI matrix: Ubuntu x86_64, macOS Apple Silicon (ARM64). | **Python & secan**: Export PyTorch Transformer to ONNX. Verify `secan` builds and passes all tests on both x86_64 and ARM64. |

> **📝 Essay 23 (Sat Feb 7)**: *"Cross-Platform Vector Search: AVX2, AVX-512, and ARM NEON Under One Abstraction Layer"*  
> Structure: 1. Vector lane geometry across microarchitectures $\to$ 2. ARM NEON vs x86 SIMD instruction comparisons $\to$ 3. Zero-overhead C++20 dispatch layer $\to$ 4. Apple Silicon / AWS Graviton benchmark results $\to$ 5. Floating-point numerical reproducibility.

---

### Week 24 (Feb 9–13): Grand Integration, Final Benchmarking & Master Retrospective

**Theme**: End-to-end integration, competitive validation, and publishing the complete engine.

* **Linear Algebra**: Master synthesis of all 8 chapters of Strang: Vector spaces $\to$ Orthogonality $\to$ SVD $\to$ Sparse Matrices $\to$ Multimodal Projections.
* **Python Track**: End-to-End Multimodal Application: Text & Image Ingestion $\to$ PyTorch ColPali/BERT $\to$ Zero-Copy `nanobind` $\to$ `secan` (CPU/GPU) $\to$ Top-$K$ Results in $< 1\text{ ms}$.
* **C++ Engine (`secan`)**: Comprehensive `secan` CLI tool, full Doxygen documentation, 5 standalone runnable examples, complete `ann-benchmarks` evaluation suite, `v2.0` release.

| Day | Linear Algebra (45 min) | Systems / Architecture Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Feb 9** | Review: The unified geometric thread connecting all 6 months of linear algebra. | **PIKUS Ch 12**: Design for performance retrospective — lessons from building a complete engine. | **secan**: Implement comprehensive `secan` CLI: `secan build --index hnsw --gpu`, `secan search --query q.fvecs --k 10`, `secan bench`. |
| **Tue Feb 10** | Mathematical formulation of competitive Pareto frontiers in vector search. | Review `ann-benchmarks` standard evaluation protocol. | **Master Benchmark Run**: Execute full benchmark matrix across ALL index types (Brute-Force, IVF, HNSW, ColBERT) on CPU and GPU. |
| **Wed Feb 11** | Error budget analysis: quantization error vs graph routing error vs floating-point precision. | Doxygen documentation standards and C++ API design best practices. | **secan**: Generate full Doxygen API documentation for every public class, function, and parameter. |
| **Thu Feb 12** | Clean architecture principles in high-performance computing libraries. | Code cleanup, compiler warning elimination (`-Wall -Wextra -Wpedantic -Werror`). | **secan**: Create `examples/` directory: (1) Basic CPU search, (2) HNSW index, (3) Quantized search, (4) ColBERT search, (5) GPU batch search. |
| **Fri Feb 13** | — | — | **Grand Finale**: Update README with final architecture diagram, benchmark tables, and Python examples. Git tag `v2.0-complete`. |

> **📝 Essay 24 (Sat Feb 14)**: *"6 Months from Scratch: Building a Modern Vector Search Engine in C++20, CUDA, and PyTorch"*  
> Structure: 1. The complete mathematical-to-systems journey $\to$ 2. Architecture evolution of `secan` from scalar to multi-GPU $\to$ 3. PyTorch modeling track integration (FlashAttention $\to$ ViT $\to$ BERT $\to$ ColPali $\to$ MRL) $\to$ 4. Full benchmark Pareto curves vs Faiss/HNSWLib/cuVS $\to$ 5. Retrospective: What truly matters in high-performance AI systems.

---

## 📋 Comprehensive 24-Week Essay Publication Schedule

| Week | Essay Date | Essay Title |
|:---|:---|:---|
| **1** | Sat Sep 6 | *The Geometry of High-Dimensional Retrieval: From Cauchy-Schwarz and NDCG to CPU Performance Counters* |
| **2** | Sat Sep 13 | *Breaking Dependency Chains: Multi-Register SIMD Kernels and Multi-Head Attention Geometry* |
| **3** | Sat Sep 20 | *The Geometry of Subspaces and the Physics of CPU Caches* |
| **4** | Sat Sep 27 | *From Orthonormal Bases to Voronoi Cells: The Mathematical Architecture of Scalable Search* |
| **5** | Sat Oct 4 | *Spectral Transformations and Low-Bit Quantization: Compressing High-Dimensional Information* |
| **6** | Sat Oct 11 | *The Spectral Theorem, SVD, and Product Quantization: Compressing Vectors to 16 Bytes* |
| **7** | Sat Oct 18 | *Google ScaNN Anisotropic Loss, Matryoshka Embeddings, and In-Register SIMD FastScan* |
| **8** | Sat Oct 25 | *Building HNSW from Scratch: Graph Laplacians, The Hubness Phenomenon, and Sub-Millisecond Search* |
| **9** | Sat Nov 1 | *Beyond Single Vectors: The Linear Algebra and SIMD Architecture of ColBERT Late Interaction* |
| **10** | Sat Nov 8 | *PLAID, Block-Max WAND, and Tail Latency: The Engineering of 3-Stage Cascaded Retrieval* |
| **11** | Sat Nov 15 | *LSM-Trees for Vector Databases: Write-Ahead Logs, MemTables, and Apache Arrow Storage* |
| **12** | Sat Nov 22 | *secan v1.0: Architectural Blueprint of a Modern C++20 Vector Engine with Python Bindings* |
| **13** | Sat Nov 29 | *GPU Architecture for Vector Search: Why Naive CUDA Kernels Lose to CPU AVX2* |
| **14** | Sat Dec 6 | *Warp Shuffles and Memory Coalescing: Saturating GPU Memory Bandwidth in Vector Search* |
| **15** | Sat Dec 13 | *Building FlashAttention from Scratch in CUDA: IO-Aware Tiling and Online Softmax* |
| **16** | Sat Dec 20 | *GPU-Resident IVF: Pipelining Voronoi Cell Search with CUDA Streams at 100K QPS* |
| **17** | Sat Dec 27 | *CAGRA and GPU Graph Traversal: Overcoming Random Memory Access at Warp Scale* |
| **18** | Sat Jan 3 | *GPU Quantization: Shared-Memory LUTs and Warp-Shuffle In-Register Lookups* |
| **19** | Sat Jan 10 | *PagedAttention and Virtual Memory: How OS Principles Solved the LLM Memory Wall* |
| **20** | Sat Jan 17 | *Distributed Nearest Neighbors: Multi-GPU Sharding and NCCL Collective Reductions* |
| **21** | Sat Jan 24 | *ColPali and Vision-Language Retrieval: Scoring Visual Document Patches with GPU MaxSim* |
| **22** | Sat Jan 31 | *GPU Kernel Fusion and Register Tiling: Eliminating DRAM Round-Trips in CUDA Vector Search* |
| **23** | Sat Feb 7 | *Cross-Platform Vector Search: AVX2, AVX-512, and ARM NEON Under One Abstraction Layer* |
| **24** | Sat Feb 14 | *6 Months from Scratch: Building a Modern Vector Search Engine in C++20, CUDA, and PyTorch* |
