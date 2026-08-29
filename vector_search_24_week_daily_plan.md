# Vector Search Engine & AI Systems: 24-Week Master Curriculum (Pure Mathematics & Systems Edition)

**Start Date**: Monday, September 1, 2026  
**End Date**: Friday, February 19, 2027  
**Schedule**: 5 Days/Week (Mon–Fri), Weekends for Reflection, Overflow & Essay Writing  
**Daily Cadence**:
1. **Morning Pure Mathematics (90 min)**: Rigorous pencil-and-paper math, proofs, and theory.
2. **Morning Systems & Architecture Reading (45 min)**: Pikus, CS:APP, Agner Fog, PMPP, CUDA Guide.
3. **Afternoon Hands-On Implementation (2.5 hrs)**: Python models from scratch + C++20 / CUDA `secan` engine.

---

## 🏛️ The Three Synchronized Pillars

```
 ┌──────────────────────────────────────────────────────────────────────────────────────────────────┐
 │                               PILLAR 1: PURE MATHEMATICS (90 MIN/DAY)                            │
 │ • Month 1 (Sep): Pure Trigonometry (Gelfand) & Single-Variable Calculus (Strang/Stewart)        │
 │ • Month 2 (Oct): Multivariable & Vector Calculus (Gradients, Jacobians, Hessians, Integrals)     │
 │ • Month 3 (Nov): Linear Algebra from First Principles (Gilbert Strang 4th Edition)               │
 │ • Month 4 (Dec): Pure Probability Theory (Axioms, Distributions, Expectation, MGFs)              │
 │ • Month 5 (Jan): Multivariate Distributions, Statistics, Limit Theorems & Markov Chains          │
 │ • Month 6 (Feb): Numerical Optimization, Fourier Analysis & Spectral Graph Theory                │
 └────────────────────────┬─────────────────────────────────────────┬───────────────────────────────┘
                          │                                         │
                          ▼                                         ▼
 ┌────────────────────────────────────────┐     ┌───────────────────────────────────────────────────┐
 │   PILLAR 2: DEEP LEARNING (Py) (1 HR)  │     │  PILLAR 3: DATABASE & C++/GPU ENGINE (secan) (1.5H)│
 │ • Transformers from Scratch (`uv init`)│     │ • Storage Engine: LSM-Tree, WAL, MemTable, Segs   │
 │ • Online Softmax & FlashAttention-1/2  │────►│ • Columnar Formats: Zero-Copy Apache Arrow Layout │
 │ • Vision Transformer (ViT from scratch)│     │ • Handcrafted SIMD: AVX2, AVX-512, ARM NEON       │
 │ • BERT & Matryoshka Embeddings (MRL)   │     │ • Quantization: SQ8 (Outliers), Anisotropic PQ, BQ│
 │ • ColBERT Late Interaction & MaxSim    │     │ • Graph ANN: HNSW & DiskANN (io_uring Async SSD)  │
 │ • ColPali Multimodal Retrieval         │     │ • CUDA: FlashAttention, CUTLASS GEMM, CAGRA Graph │
 │ • PagedAttention & KV Cache Paging     │     │ • Zero-Copy nanobind Python Engine Architecture   │
 └────────────────────────────────────────┘     └───────────────────────────────────────────────────┘
```

---

## 📚 Complete Literature Stack

### 1. Pure Mathematics Literature
* **TRIG**: *Trigonometry* — I.M. Gelfand & Mark Saul (`/home/ahmed/Downloads/Trigonometry -- Gelʹfand, I_ M_ ...pdf`)
* **CALC**: *Calculus* — Gilbert Strang (MIT OpenCourseWare free textbook) or *Calculus: Early Transcendentals* — James Stewart
* **LINALG**: *Linear Algebra and Its Applications* (4th Edition) — Gilbert Strang (`/home/ahmed/Downloads/Linear Algebra and Its Applications, 4th Edition (Gilbert Strang) (Z-Library).pdf`)
* **PROB**: *Introduction to Probability* — Joseph K. Blitzstein & Jessica Hwang (Harvard Stat 110) or *Introduction to Probability* — Bertsekas & Tsitsiklis (MIT)

### 2. High-Performance C++ & Systems Literature
* **PIKUS**: *The Art of Writing Efficient Programs* — Fedor G. Pikus
* **CSAPP**: *Computer Systems: A Programmer's Perspective* (3rd Edition) — Bryant & O'Hallaron
* **AGNER**: *Optimizing Software in C++* & *Instruction Tables* — Agner Fog
* **CPPHI**: *C++ High Performance* (2nd Edition) — Andrist & Sehr
* **ASYNC**: *High-Performance Asynchronous C++* — Marek Ellison
* **FINSY**: *C++ High Performance for Financial Systems* — Ariel Silahian

### 3. GPU Architecture & Frontier Papers
* **PMPP**: *Programming Massively Parallel Processors* (4th Edition) — Hwu, Kirk & El Hajj
* **CUDA-GUIDE**: *CUDA C++ Programming Guide* — NVIDIA
* **FLASH-ATTN**: *"FlashAttention: Fast and Memory-Efficient Exact Attention with IO-Awareness"* (Dao et al. 2022) + FlashAttention-2 (Dao 2023)
* **SCANN**: *"Accelerating Large-Scale Inference with Anisotropic Vector Quantization"* (Guo et al. / Google Research 2020)
* **PAGED-ATTN**: *"Efficient Memory Management for Large Language Model Serving with PagedAttention"* (Kwon et al. 2023 / vLLM)
* **COLPALI**: *"ColPali: Efficient Document Retrieval with Vision Language Models"* (Faysse et al. 2024)

---

# BLOCK 1: MATHEMATICAL FOUNDATIONS, CPU ENGINE & PYTORCH (Months 1–3)

---

# 📅 MONTH 1: Pure Trigonometry, Single-Variable Calculus, SIMD & Transformers (Sep 2026)

---

### Week 1 (Sep 1–5): Pure Trigonometry, Limits, Derivatives & Measurement

**Theme**: Trigonometric ratios, unit circle wrapping, derivative foundations, and scientific C++ measurement.

* **Pure Math (Gelfand Trig & Strang Calc)**:
  * **Trig (Gelfand Ch 1–3)**: Trigonometric ratios in right triangles, radian measure, the wrapping function on the unit circle $x^2 + y^2 = 1$, graphs and periodic symmetries of $\sin\theta, \cos\theta, \tan\theta$.
  * **Calculus (Strang Ch 1–2)**: Intuitive and $\epsilon$-$\delta$ definitions of limits, continuity, first-principles derivative definition $f'(x) = \lim_{h \to 0} \frac{f(x+h) - f(x)}{h}$.
* **IR Analytics**: Mathematical definitions of NDCG@K, DCG formula, Ideal DCG (IDCG), MRR, MAP.
* **C++ & Python Track**:
  * **secan**: Google Benchmark integration, `.fvecs` SIFT1M loader, IR metrics evaluator (`tests/test_ir_metrics.cpp`), exact scalar baseline scan with AddressSanitizer.
  * **Python (`transformers-pytorch`)**: Scaffold project with `uv init transformers-pytorch`. Implement `scaled_dot_product_attention(Q, K, V, mask)` in `src/attention.py`.

| Day | Pure Mathematics (90 min) | Systems / C++ Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Sep 1** | **TRIG (Gelfand Ch 1–2)**: Geometric definition of sine/cosine from right triangles to unit circle coordinates. Radian measure and arc length. | **PIKUS Ch 2**: Performance measurements, high-res timers, profiler sampling, micro-benchmark noise floor. | **secan**: Integrate Google Benchmark via CMake. Add ASan/UBSan build flags. Write first benchmark for `l2_squared` with `DoNotOptimize`. |
| **Tue Sep 2** | **TRIG (Gelfand Ch 3)**: Periodic properties: $\sin(\theta + 2\pi) = \sin\theta$, parity: $\cos(-\theta) = \cos\theta$, $\sin(-\theta) = -\sin\theta$. Graphs of trig functions. | **CSAPP §5.1–5.6**: Compiler limitations, Cycles Per Element (CPE), loop inefficiencies, memory aliasing. | **secan**: Implement binary `.fvecs` and `.bvecs` parsers in `src/io/fvecs_reader.h`. Load SIFT1M ($1\text{M} \times 128\text{D}$). |
| **Wed Sep 3** | **CALC (Strang §1.1–1.5)**: Introduction to limits: $\lim_{x \to c} f(x) = L$, one-sided limits, continuity, the Intermediate Value Theorem. | **CSAPP §5.7**: Superscalar architecture, out-of-order execution, execution ports, latency vs throughput. | **secan**: Build IR metrics evaluator in `tests/test_ir_metrics.cpp`. Run exact scan on SIFT1M; verify Recall@10 = 1.0 and NDCG@10 = 1.0. |
| **Thu Sep 4** | **CALC (Strang §2.1–2.3)**: Derivative from first principles: slope of secant line $\to$ tangent line. Power rule proof: $\frac{d}{dx} x^n = n x^{n-1}$. | **AGNER Ch 3 & Ch 7.1–7.3**: Finding bottlenecks, clock cycles, variable storage, floating-point efficiency. | **Python (`transformers-pytorch`)**: Scaffold project (`uv init`). Implement `scaled_dot_product_attention` in `src/attention.py` with causal masking. |
| **Fri Sep 5** | **CALC (Strang §2.4–2.5)**: Product Rule $\frac{d}{dx}(uv) = u'v + uv'$, Quotient Rule, and differentiation of trigonometric functions ($\frac{d}{dx}\sin x = \cos x$). | **PIKUS Ch 1 & CSAPP §5.14**: Measurement-driven optimization, profiling-guided workflow with `perf stat`. | **secan**: Profile baseline SIFT1M scan with `perf stat`. Record IPC, cache misses, branch misses. Populate first row of README benchmark table. |

> **📝 Essay 1 (Sat Sep 6)**: *"The Geometry of High-Dimensional Retrieval: From Trigonometric Coordinates and NDCG to CPU Performance Counters"*

---

### Week 2 (Sep 8–12): Trigonometric Identities, Chain Rule, SIMD AVX2 & Multi-Head Attention

**Theme**: Pure trigonometric identities, differentiation techniques, and instruction-level SIMD parallelism.

* **Pure Math (Gelfand Trig & Strang Calc)**:
  * **Trig (Gelfand Ch 4–5)**: Pythagorean identities ($\sin^2\theta + \cos^2\theta = 1$, $1 + \tan^2\theta = \sec^2\theta$), angle addition formulas $\cos(\alpha \pm \beta), \sin(\alpha \pm \beta)$, double-angle and half-angle formulas, product-to-sum identities.
  * **Calculus (Strang §2.6–3.2)**: The Chain Rule $\frac{d}{dx} f(g(x)) = f'(g(x)) g'(x)$, implicit differentiation, derivatives of exponential ($e^x$) and logarithmic functions ($\ln x$).
* **C++ & Python Track**:
  * **secan**: Enable `_MM_SET_FLUSH_ZERO_MODE` / `_MM_SET_DENORMALS_ZERO_MODE`. Handcrafted AVX2+FMA distance kernels, 4-way multi-register unrolling, 64-byte alignment (`alignas(64)`).
  * **Python (`transformers-pytorch`)**: Multi-Head Attention (MHA) module from scratch in `src/multihead_attention.py`.

| Day | Pure Mathematics (90 min) | Systems / C++ Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Sep 8** | **TRIG (Gelfand Ch 4)**: Geometric proof of angle addition: $\cos(\alpha - \beta) = \cos\alpha \cos\beta + \sin\alpha \sin\beta$. Derivation of all addition formulas. | **AGNER Ch 12**: SIMD instructions, 256-bit YMM registers, data types, intrinsics syntax. | **secan**: Enable FTZ/DAZ flags. Implement `l2_squared_avx2()` in `src/search/distance_avx2.cpp`. Single accumulator baseline. |
| **Tue Sep 9** | **TRIG (Gelfand Ch 4)**: Double-angle formulas: $\sin 2\theta = 2\sin\theta\cos\theta$, $\cos 2\theta = \cos^2\theta - \sin^2\theta$. Half-angle formulas. | **CSAPP §5.8–5.9**: Loop unrolling, breaking dependency chains with multiple independent accumulator registers. | **secan**: Implement 4-way unrolled `l2_squared_avx2` with 4 parallel `__m256` accumulators. Measure speedup over 1-acc. |
| **Wed Sep 10** | **CALC (Strang §2.6)**: The Chain Rule: step-by-step rigorous proof using limits. Differentiating nested composite functions. | **AGNER-INST & AGNER Ch 11**: VFMADD latency/throughput port mapping on modern x86 microarchitectures. | **secan**: Implement `cosine_distance_avx2()`: compute dot product, norm $A$, and norm $B$ simultaneously in 1 pass. |
| **Thu Sep 11** | **CALC (Strang §3.1–3.2)**: Derivatives of $e^x$ and $\ln x$. Logarithmic differentiation. Derivation of $\lim_{x \to 0} (1+x)^{1/x} = e$. | **AGNER Ch 13.1–13.3**: Alignment, `alignas(64)`, cache line splits, unaligned load penalties. | **Python (`transformers-pytorch`)**: Build `MultiHeadAttention(d_model, num_heads)` class in `src/multihead_attention.py`. |
| **Fri Sep 12** | **TRIG & CALC Integration**: Differentiating inverse trigonometric functions: $\frac{d}{dx}\arcsin x = \frac{1}{\sqrt{1-x^2}}$, $\frac{d}{dx}\arctan x = \frac{1}{1+x^2}$. | **PIKUS Ch 3**: Instruction-level parallelism, register pressure, compiler vectorization limits. | **secan**: Add AVX-512 backend (`_mm512_*`) behind `#ifdef __AVX512F__`. Benchmark scalar vs AVX2 vs AVX-512. |

> **📝 Essay 2 (Sat Sep 13)**: *"Breaking Dependency Chains: Multi-Register SIMD Kernels and Multi-Head Attention Geometry"*

---

### Week 3 (Sep 15–19): Integration, Fundamental Theorem, Cache Hierarchy & Transformer Encoder

**Theme**: Definite integrals, accumulation, Fundamental Theorem of Calculus, and CPU cache hierarchy.

* **Pure Math (Strang Calc Ch 4–5)**:
  * **Riemann Sums & Definite Integrals**: $\int_a^b f(x) dx = \lim_{n \to \infty} \sum_{i=1}^n f(x_i^*) \Delta x$. Properties of integrals (linearity, additivity).
  * **Fundamental Theorem of Calculus (FTC Part 1 & 2)**: $\frac{d}{dx} \int_a^x f(t) dt = f(x)$ and $\int_a^b f(x) dx = F(b) - F(a)$.
  * **Integration Techniques**: Integration by substitution (u-substitution), Integration by parts $\int u dv = uv - \int v du$.
* **C++ & Python Track**:
  * **secan**: Memory hierarchy profiling, cache-blocking/tiling, software prefetching (`_mm_prefetch`), unit sphere pre-normalization.
  * **Python (`transformers-pytorch`)**: `LayerNorm`, `PositionalEncoding`, `FeedForwardBlock`, assembling full `TransformerEncoder`.

| Day | Pure Mathematics (90 min) | Systems / C++ Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Sep 15** | **CALC (Strang §4.1–4.3)**: Riemann sums, partitions, upper and lower Darboux sums, definition of the Riemann integral. | **CSAPP §6.1–6.3**: SRAM vs DRAM, memory latency gap, spatial and temporal locality principles. | **secan**: Profile SIFT1M cache misses with `perf stat -e L1-dcache-load-misses,LLC-load-misses`. Calculate working set. |
| **Tue Sep 16** | **CALC (Strang §4.4)**: The Fundamental Theorem of Calculus Part 1 and Part 2: Rigorous proof connecting differentiation and integration. | **CSAPP §6.4–6.5**: Cache line organization, set associativity, conflict misses, cache-friendly coding. | **secan**: Implement cache-blocked `linear_scan_tiled`: partition dataset into tiles fitting in L2 cache ($256\text{KB}$). |
| **Wed Sep 17** | **CALC (Strang §5.1–5.3)**: Integration by Substitution (the reverse chain rule) and change of variables in definite integrals. | **CSAPP §6.6 & PIKUS Ch 4**: The Memory Mountain, cache hierarchy on real workloads, software prefetching. | **secan**: Add software prefetching (`_mm_prefetch`, `_MM_HINT_T0`). Tune prefetch distances ($4, 8, 16, 32$ vectors). |
| **Thu Sep 18** | **CALC (Strang §5.4–5.5)**: Integration by Parts: deriving $\int u v' dx = uv - \int u' v dx$. Tabular integration and reduction formulas. | **AGNER Ch 9**: Optimizing memory access, cache line splits, non-temporal streaming stores. | **Python (`transformers-pytorch`)**: Implement `LayerNorm`, `PositionalEncoding`, and `FeedForwardBlock` from scratch. |
| **Fri Sep 19** | **CALC (Strang §5.6)**: Trigonometric integrals: evaluating $\int \sin^m x \cos^n x dx$ and trigonometric substitutions ($x = a\sin\theta, x = a\tan\theta$). | **FINSY Ch 6**: Cache optimization, system warmup routines, `madvise(MADV_HUGEPAGE)`. | **Python (`transformers-pytorch`)**: Assemble `TransformerEncoder` stacking $N$ layers with residual connections. Verify forward pass. |

> **📝 Essay 3 (Sat Sep 20)**: *"The Geometry of Subspaces and the Physics of CPU Caches"*

---

### Week 4 (Sep 22–26): Complex Numbers, Euler's Formula, Taylor Series & Full Transformer

**Theme**: Complex plane geometry, Euler's formula, Taylor series, and complete Transformer encoder-decoder.

* **Pure Math (Gelfand Trig Ch 7 & Strang Calc Ch 8)**:
  * **Complex Numbers & Polar Form**: $z = a + bi$, modulus $|z| = \sqrt{a^2 + b^2}$, argument $\theta = \arctan(b/a)$, polar form $z = r(\cos\theta + i\sin\theta)$.
  * **Euler's Formula & De Moivre's Theorem**: $e^{i\theta} = \cos\theta + i\sin\theta$, $[r(\cos\theta + i\sin\theta)]^n = r^n(\cos n\theta + i\sin n\theta)$, roots of unity.
  * **Taylor & Maclaurin Series**: $f(x) = \sum_{n=0}^\infty \frac{f^{(n)}(a)}{n!} (x-a)^n$. Taylor series of $e^x, \sin x, \cos x, \frac{1}{1-x}$.
* **C++ & Python Track**:
  * **secan**: Batch Query GEMM, `IVFIndex` with $k$-means coarse Voronoi partitioning, multi-threaded `std::jthread` scaling.
  * **Python (`transformers-pytorch`)**: `TransformerDecoder` with cross-attention, causal masking, complete `Transformer` model.

| Day | Pure Mathematics (90 min) | Systems / C++ Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Sep 22** | **TRIG (Gelfand Ch 7)**: The complex plane $\mathbb{C}$, complex arithmetic, conjugate $\bar{z}$, modulus, and geometric multiplication in polar form. | **PIKUS Ch 5**: Cache coherence, false sharing, atomic memory ordering basics. | **secan**: Implement `batch_linear_scan`: process $B=32/64$ queries simultaneously against tiled dataset (GEMV $\to$ GEMM). |
| **Tue Sep 23** | **TRIG (Gelfand Ch 7)**: De Moivre's Theorem and Euler's Formula $e^{i\theta} = \cos\theta + i\sin\theta$. Solving $z^n = 1$ for the $n$-th roots of unity. | Research: Faiss IVF coarse quantizer architecture, Voronoi cell partitioning. | **secan**: Implement `IVFIndex`: train $k$-means centroids on dataset vectors; assign vectors to Voronoi cells; build inverted lists. |
| **Wed Sep 24** | **CALC (Strang §8.1–8.3)**: Infinite sequences and series. Convergence tests (Integral test, Comparison test, Ratio test, Alternating series test). | **PIKUS Ch 6**: Concurrency, work decomposition, thread pool patterns. | **secan**: Implement multi-probe IVF search: query searches top `nprobe` cells. Sweep `nprobe` from 1 to 64; plot Recall vs speedup. |
| **Thu Sep 25** | **CALC (Strang §8.4–8.6)**: Power series, radius of convergence, and Taylor/Maclaurin series expansions. Proof that $e^x = \sum \frac{x^n}{n!}$. | **CPPHI Concurrency & ASYNC Ch 1–2**: `std::jthread`, thread affinity, eliminating false sharing with `alignas(64)`. | **Python (`transformers-pytorch`)**: Build `TransformerDecoder` with cross-attention and causal mask. Assemble complete `Transformer` model. |
| **Fri Sep 26** | **Pure Math Synthesis**: Proving Euler's formula $e^{i\theta} = \cos\theta + i\sin\theta$ by substituting $ix$ into the Taylor series of $e^x$. | **PIKUS Ch 12**: Design for performance, evaluating whole-system throughput. | **secan & Python**: Multi-thread IVF search across CPU cores with pinned threads. Assemble full PyTorch Transformer model. Tag `v0.2-simd-ivf`. |

> **📝 Essay 4 (Sat Sep 27)**: *"From Euler's Formula to Voronoi Cells: The Mathematical Architecture of Scalable Search"*

---

# 📅 MONTH 2: Multivariable Calculus, Vector Fields, Vision Transformers & HNSW (Oct 2026)

---

### Week 5 (Sep 29 – Oct 3): Partial Derivatives, Gradients, Hessians & Vision Transformer (ViT)

**Theme**: Multivariable functions, gradient vectors, Hessian matrices, and Vision Transformers from scratch.

* **Pure Math (Strang Calc Ch 13)**:
  * Functions of several variables $f(x, y, z)$, level curves and contour maps.
  * Partial derivatives $\frac{\partial f}{\partial x}, \frac{\partial f}{\partial y}$, Clairaut's Theorem (equality of mixed partials $\frac{\partial^2 f}{\partial x \partial y} = \frac{\partial^2 f}{\partial y \partial x}$).
  * The Gradient vector $\nabla f = \left( \frac{\partial f}{\partial x_1}, \dots, \frac{\partial f}{\partial x_n} \right)$, directional derivatives $D_{\mathbf{u}} f = \nabla f \cdot \mathbf{u}$.
  * The Hessian matrix $H[i, j] = \frac{\partial^2 f}{\partial x_i \partial x_j}$, Second Derivative Test for multivariable extrema.
* **C++ & Python Track**:
  * **secan**: `ScalarQuantizer` with percentile clipping (0.05th/99.95th), `l2_squared_sq8` integer AVX2 intrinsics (`_mm256_maddubs_epi16`).
  * **Python (`vit-pytorch`)**: Scaffold project (`uv init vit-pytorch`). Write `src/patch_embed.py` from scratch (`PatchEmbedding` + `[CLS]` token).

| Day | Pure Mathematics (90 min) | Systems / C++ Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Sep 29** | **CALC §13.1–13.3**: Functions of several variables, limits and continuity in $\mathbb{R}^n$, partial derivatives definition and geometry. | **AGNER Ch 7.2 & CSAPP §2.2–2.3**: Integer arithmetic efficiency, two's complement, overflow, bit-width conversion. | **secan**: Implement `ScalarQuantizer` with **percentile clipping (0.05th/99.95th)** to handle outlier dimensions. Verify dequantization error. |
| **Tue Sep 30** | **CALC §13.4**: Tangent planes and linear approximations: $L(x, y) = f(a, b) + f_x(a, b)(x-a) + f_y(a, b)(y-b)$. Total differentials. | **INTEL Intrinsics Guide**: Study `_mm256_maddubs_epi16`, `_mm256_madd_epi16`, `_mm256_dpbusd_epi32` (VNNI dot product). | **secan**: Implement `l2_squared_sq8()` using AVX2 integer intrinsics. Process 32 dimensions per iteration in a single `__m256i`. |
| **Wed Oct 1** | **CALC §13.5**: The Multivariable Chain Rule for paths and surfaces. Tree diagrams for composite multivariable functions. | **AGNER Ch 12**: Integer SIMD saturation arithmetic, signed vs unsigned byte multiplication, widening instructions. | **Python (`vit-pytorch`)**: Scaffold project (`uv init vit-pytorch`). Create `src/patch_embed.py` from scratch: implement `PatchEmbedding`. |
| **Thu Oct 2** | **CALC §13.6**: Directional derivatives and the Gradient vector $\nabla f$. Proving that $\nabla f$ points in the direction of maximum rate of increase. | **CSAPP §2.4**: Floating-point representation, rounding error bounds, precision loss in quantization. | **secan**: Implement 4-bit scalar quantization (`SQ4`): pack 2 dimensions per byte with nibble masking. Build 2-stage SQ8 $\to$ FP32 re-ranker. |
| **Fri Oct 3** | **CALC §13.7**: Maximum and minimum values of multivariable functions, critical points, the Hessian matrix and discriminant $D = f_{xx} f_{yy} - (f_{xy})^2$. | **PIKUS Ch 9**: High-performance C++, move semantics, zero-copy buffer views (`std::span`). | **Python (`vit-pytorch`)**: Add learnable `[CLS]` token and 1D positional embeddings. Stack Transformer encoder layers to complete `VisionTransformer`. |

> **📝 Essay 5 (Sat Oct 4)**: *"Multivariable Gradients, Hessians, and Low-Bit Quantization: Compressing High-Dimensional Information"*

---

### Week 6 (Oct 6–10): Lagrange Multipliers, Multiple Integrals, Jacobians & BERT from Scratch

**Theme**: Constrained optimization, multiple integrals, coordinate Jacobians, and BERT bidirectional modeling.

* **Pure Math (Strang Calc Ch 13 & 14)**:
  * **Constrained Optimization & Lagrange Multipliers**: $\nabla f = \lambda \nabla g$. Finding extrema on constrained surfaces. Multiple constraints $\nabla f = \lambda_1 \nabla g_1 + \lambda_2 \nabla g_2$.
  * **Double & Triple Integrals**: $\iint_R f(x, y) dA$, Fubini's Theorem, changing integration order.
  * **Jacobian of Transformations**: Coordinate transformations $x = g(u, v), y = h(u, v)$, the Jacobian determinant $J = \left|\frac{\partial(x, y)}{\partial(u, v)}\right|$, polar, cylindrical, and spherical substitutions.
* **C++ & Python Track**:
  * **secan**: `ProductQuantizer`, $k$-means codebook training, Asymmetric Distance Computation (ADC) with precomputed Query LUT.
  * **Python (`bert-pytorch`)**: Scaffold project (`uv init bert-pytorch`). Write `src/embeddings.py` using HF `tokenizers` and build bidirectional encoder from scratch.

| Day | Pure Mathematics (90 min) | Systems / C++ Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Oct 6** | **CALC §13.8**: Constrained optimization: Method of Lagrange Multipliers. Geometric proof of $\nabla f \parallel \nabla g$ at tangent extrema. | Research paper: *"Product Quantization for Nearest Neighbor Search"* (Jégou et al. 2011) §1–4. | **secan**: Implement $k$-means clustering in C++ for a subspace: `train_kmeans(data, k=256, dim_sub)` using $k$-means++. |
| **Tue Oct 7** | **CALC §13.8**: Lagrange Multipliers with multiple constraints: $\nabla f = \lambda_1 \nabla g_1 + \lambda_2 \nabla g_2$. Solving constrained systems. | Faiss wiki on Product Quantizer: subspace splitting, codebook memory layouts. | **secan**: Implement `ProductQuantizer`: split $D$ dimensions into $M$ subspaces. Train $M$ codebooks. Encode vectors as $M$-byte codes. |
| **Wed Oct 8** | **CALC §14.1–14.2**: Double integrals over rectangular and general regions. Fubini's Theorem on swapping order of integration. | **AGNER Ch 7.10 & Ch 9**: Array structures for cache-friendly table lookups, stride optimization. | **secan**: Implement Asymmetric Distance Computation (ADC): precompute query-to-centroid table `float LUT[M][256]`. Distance = sum of $M$ lookups. |
| **Thu Oct 9** | **CALC §14.3–14.4**: Double integrals in polar coordinates: $\iint f(r\cos\theta, r\sin\theta) r \, dr \, d\theta$. Evaluating the Gaussian integral $\int_{-\infty}^\infty e^{-x^2} dx = \sqrt{\pi}$. | **PIKUS Ch 10**: Compiler optimizations, `__restrict__`, loop vectorization, Link-Time Optimization (LTO). | **Python (`bert-pytorch`)**: Scaffold clean project (`uv init bert-pytorch`). Use HF `tokenizers`. Implement `src/embeddings.py` and bidirectional encoder from scratch. |
| **Fri Oct 10** | **CALC §14.7**: Change of Variables in Multiple Integrals: The Jacobian matrix and determinant $J = \det\left(\frac{\partial(x, y, z)}{\partial(u, v, w)}\right)$. | **PIKUS Ch 11**: Undefined behavior, memory aliasing, safe usage of low-level pointer arithmetic. | **Python (`bert-pytorch`) & secan**: Implement BERT MLM prediction head. In `secan`, benchmark IVFPQ vs IVFFlat on SIFT1M. |

> **📝 Essay 6 (Sat Oct 11)**: *"Lagrange Multipliers, Jacobians, and Product Quantization: Compressing Vectors to 16 Bytes"*

---

### Week 7 (Oct 13–17): Vector Fields, Line Integrals, ScaNN Anisotropic Loss & FastScan

**Theme**: Vector calculus, directional error weighting (ScaNN), and in-register FastScan lookups.

* **Pure Math (Strang Calc Ch 15)**:
  * Vector fields $\mathbf{F}(x, y, z) = P\mathbf{i} + Q\mathbf{j} + R\mathbf{k}$, gradient fields, conservative vector fields.
  * Line integrals of scalar functions and vector fields $\int_C \mathbf{F} \cdot d\mathbf{r} = \int_a^b \mathbf{F}(\mathbf{r}(t)) \cdot \mathbf{r}'(t) dt$.
  * Fundamental Theorem for Line Integrals: $\int_C \nabla f \cdot d\mathbf{r} = f(\mathbf{r}(b)) - f(\mathbf{r}(a))$ (path independence).
  * Green's Theorem in the plane: $\oint_C (P dx + Q dy) = \iint_D \left(\frac{\partial Q}{\partial x} - \frac{\partial P}{\partial y}\right) dA$.
* **ScaNN Theory**: Directional error decomposition: parallel error $e_\parallel$ vs orthogonal error $e_\perp$; ScaNN anisotropic loss $\mathcal{L} = h \|e_\parallel\|^2 + \|e_\perp\|^2$.
* **C++ & Python Track**:
  * **secan**: ScaNN anisotropic loss codebook training, 1-bit RaBitQ, 4-bit FastScan with in-register `_mm256_shuffle_epi8` (PSHUFB).
  * **Python (`bert-pytorch`)**: Train BERT with Matryoshka Representation Learning (MRL) nested dimension loss ($64\text{D} \subset 128\text{D} \subset 768\text{D}$).

| Day | Pure Mathematics & ScaNN Math (90 min) | Systems / C++ Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Oct 13** | **CALC §15.1–15.2**: Vector fields in 2D/3D. Line integrals of vector fields along parameterized curves $\mathbf{r}(t)$. Work done by a force field. | ScaNN Paper §1–3: MIPS error decomposition: why orthogonal error $e_\perp$ has 0 expectation while parallel error $e_\parallel$ degrades inner products. | **secan**: Implement **ScaNN Anisotropic Loss** in `ProductQuantizer`: penalize parallel error with weight $h=5.0$. Compare codebooks. |
| **Tue Oct 14** | **CALC §15.3**: Conservative vector fields, potential functions $f$, and path independence of line integrals. Conditions for a field to be conservative. | **INTEL Intrinsics & AGNER-INST**: Deep dive into `_mm256_shuffle_epi8` (PSHUFB) semantics and port mapping. | **secan**: Implement RaBitQ: generate random orthogonal rotation matrix via QR decomposition. Apply rotation before 1-bit quantization + error correction. |
| **Wed Oct 15** | **CALC §15.4**: Green's Theorem: rigorous proof connecting a line integral around a closed curve to a double integral over the enclosed region. | Faiss FastScan documentation & André et al. (2015) paper §1–3. | **secan**: Implement 4-bit PQ encoding ($k=16$ centroids per subspace, packing 2 codes per byte). |
| **Thu Oct 16** | **CALC §15.5**: Curl and Divergence of vector fields: $\text{curl } \mathbf{F} = \nabla \times \mathbf{F}$ (circulation), $\text{div } \mathbf{F} = \nabla \cdot \mathbf{F}$ (flux density). Physical interpretations. | AGNER-INST: Study `VPSHUFB`, `VPADDB`, `VPUNPCKLBW` instruction latency and accumulation chains. | **secan**: Implement **FastScan kernel**: load 16 centroid distances into `__m128i` / `__m256i`. Execute table lookups **entirely in-register** via PSHUFB. |
| **Fri Oct 17** | **CALC §15.6–15.8**: Surface integrals, Stokes' Theorem ($\oint_C \mathbf{F} \cdot d\mathbf{r} = \iint_S (\nabla \times \mathbf{F}) \cdot d\mathbf{S}$), Divergence Theorem ($\iint_S \mathbf{F} \cdot d\mathbf{S} = \iiint_E (\nabla \cdot \mathbf{F}) dV$). | **CSAPP §5.10–5.12**: Register spilling, store-load forwarding, pipeline limiting factors. | **Python (`bert-pytorch`)**: Train BERT with Matryoshka Representation Loss. Export multi-resolution embeddings ($64\text{D}, 128\text{D}, 768\text{D}$) to `.fvecs`. |

> **📝 Essay 7 (Sat Oct 18)**: *"Google ScaNN Anisotropic Loss, Vector Fields, and In-Register SIMD FastScan"*

---

### Week 8 (Oct 20–24): Graph Theory, The Hubness Phenomenon & HNSW from Scratch

**Theme**: Small-world networks, the Hubness Problem in high-dimensional embedding spaces, and HNSW graph routing.

* **Pure Math (Graph Theory & High-D Analytics)**:
  * Graph representations: Node-arc incidence matrices, adjacency matrices, Graph Laplacian $L = D - A$.
  * Algebraic connectivity (Fiedler vector / second smallest eigenvalue of Laplacian).
  * **The Hubness Phenomenon**: Skewness of $k$-occurrences ($S_{N_k}$), measure concentration in $\mathbb{R}^D$, Centering & Whitening transforms to eliminate hub congestion.
* **C++ & Python Track**:
  * **secan**: Full HNSW index from scratch (skip-list hierarchy, greedy beam search, heuristic neighbor selection Algorithm 4, CSR-packed adjacency, bounded flat heaps).
  * **Python**: Text-to-vector search pipeline: Raw Text Corpus $\to$ Tokenization (HF `tokenizers`) $\to$ PyTorch BERT $\to$ Export `.fvecs` $\to$ Ingest into `secan`.

| Day | Pure Mathematics & Hubness Analytics (90 min) | Systems / C++ Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Oct 20** | **GRAPH THEORY**: Graphs and Networks: Incidence matrix $A$, Kirchhoff's current/voltage laws, Graph Laplacian $L = A^T A = D - W$. | Research paper: *"Efficient and Robust ANN Search Using HNSW Graphs"* (Malkov & Yashunin 2020) §1–3. | **secan**: Implement `HNSWIndex` data structures: flat CSR adjacency storage (`neighbors[]` + `offsets[]`), node struct, entry point. |
| **Tue Oct 21** | **HUBNESS ANALYTICS**: Skewness of $k$-occurrences $S_{N_k} = \frac{\sum (N_k(x) - \mu)^3}{\sigma^3}$. Why high hubness degrades HNSW graph routing. | HNSW paper §4–5: Algorithm 4 (heuristic neighbor selection), level multiplier $m_L$, parameter tuning ($M, ef$). | **secan**: Implement HNSW `insert()`: exponential level assignment ($\ell = \lfloor -\ln(\text{unif}) \cdot m_L \rfloor$), greedy descent, multi-layer neighbor connection. |
| **Wed Oct 22** | **SPECTRAL GRAPH THEORY**: Centering and Whitening transforms: $x_{\text{white}} = \Lambda^{-1/2} Q^T (x - \mu)$ to eliminate embedding anisotropy. | **PIKUS Ch 7**: Concurrent data structures, cache-friendly priority queues, memory allocation in graphs. | **secan**: Implement HNSW `search()`: beam search with visited-set bitfield. Implement Algorithm 4 diverse neighbor selection. |
| **Thu Oct 23** | **GRAPH EMBEDDINGS**: Shortest path distance vs Euclidean embedding distance. Small-world clustering coefficient $C$ and path length $L$. | **AGNER Ch 7.12–7.13 & Ch 7.5**: Branch prediction in graph traversal, branchless heap sift-down. | **secan**: Optimize HNSW: replace `std::priority_queue` with custom **bounded flat heap** (fixed-size array). Replace visited hash-set with flat bitset. |
| **Fri Oct 24** | **PURE MATH REVIEW**: Comprehensive review of Multivariable Calculus & Vector Calculus theorems (Green's, Stokes', Divergence). | **CSAPP §5.14**: Profiling graph traversal bottlenecks with `perf record`. | **End-to-End Test**: Ingest BERT text embeddings ($768\text{D}$) into `secan` HNSW. Benchmark Recall@10 vs QPS Pareto curves. Tag `v0.3-hnsw`. |

> **📝 Essay 8 (Sat Oct 25)**: *"Building HNSW from Scratch: Graph Laplacians, The Hubness Phenomenon, and Sub-Millisecond Search"*

---

# 📅 MONTH 3: Linear Algebra from First Principles, ColBERT & LSM-Trees (Nov 2026)

---

### Week 9 (Oct 27–31): Vector Spaces, Four Fundamental Subspaces, ColBERT & SIMD MaxSim

**Theme**: Rigorous linear algebra (Strang Ch 1–2), ColBERT dual-encoder architecture, and SIMD MaxSim.

* **Pure Math (Gilbert Strang Linear Algebra Ch 1–2)**:
  * Linear combinations, dot products, length and angles in $\mathbb{R}^n$, matrix elimination, triangular factorizations $A = LU$.
  * Vector spaces and subspaces, the Nullspace $N(A)$, the Column space $C(A)$, linear independence, basis, dimension.
  * The Four Fundamental Subspaces and the Fundamental Theorem of Linear Algebra ($r = \text{rank}(A)$).
* **C++ & Python Track**:
  * **secan**: `MultiVectorIndex` class, SIMD-vectorized MaxSim kernel ($\sum_{q} \max_{d} (q \cdot d)$), token centroid inverted index.
  * **Python (`colbert-pytorch`)**: Scaffold project (`uv init colbert-pytorch`). Write `src/model.py` and implement ColBERT dual encoder architecture from scratch.

| Day | Pure Mathematics (Strang) (90 min) | Systems / C++ Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Oct 27** | **STRANG §1.1–1.6**: Vector geometry, matrix multiplication from 4 perspectives, Gaussian elimination, $LU$ factorization. | Research paper: *"ColBERT: Efficient and Effective Passage Search via Late Interaction"* (Khattab & Zaharia 2020). | **Python (`colbert-pytorch`)**: Scaffold clean project (`uv init colbert-pytorch`). Create `src/model.py` and implement ColBERT dual encoder from scratch. |
| **Tue Oct 28** | **STRANG §2.1–2.2**: Vector spaces, closure axioms, column space $C(A)$, solving $Ax = b$, nullspace $N(A)$, special solutions. | Research paper: *"PLAID: An Efficient Engine for Late Interaction Retrieval"* (Santhanam et al. 2022) §1–4. | **Python (`colbert-pytorch`)**: Implement PyTorch MaxSim operator: `torch.einsum('bsh,bdh->bsd', Q, D).max(dim=2).values.sum(dim=1)`. |
| **Wed Oct 29** | **STRANG §2.3–2.4**: Linear independence, spanning sets, basis, dimension of vector spaces. Computing rank from echelon form. | **INTEL Intrinsics Guide**: Study `_mm256_max_ps`, `_mm256_permute2f128_ps`, cross-lane max reduction. | **secan**: Implement **SIMD-vectorized MaxSim kernel** in C++: process 8 document tokens in parallel with AVX2 FMA + horizontal max reduction. |
| **Thu Oct 30** | **STRANG §2.5–2.6**: The Four Fundamental Subspaces ($C(A), N(A), C(A^T), N(A^T)$). The Fundamental Theorem of Linear Algebra (Part 1). | **AGNER Ch 13**: Data parallelism, cache layout for multi-vector matrices. | **secan**: Build **token centroid index**: cluster document tokens into centroids ($C=32\text{K}$). Build inverted lists `centroid_id → (doc_id, token_idx)`. |
| **Fri Oct 31** | **STRANG §2.6**: Matrix rank and dimensions of the 4 subspaces: $\dim C(A) = \dim C(A^T) = r$, $\dim N(A) = n - r$, $\dim N(A^T) = m - r$. | Re-read PLAID paper §3 "Centroid Interaction" + §4 "Decompression and Scoring". | **secan**: Implement centroid candidate pruning: query tokens retrieve candidate documents from centroid inverted lists. Score candidates with MaxSim. |

> **📝 Essay 9 (Sat Nov 1)**: *"Beyond Single Vectors: The Linear Algebra and SIMD Architecture of ColBERT Late Interaction"*

---

### Week 10 (Nov 3–7): Orthogonality, Projections, QR, PLAID Engine & Poisson SLAs

**Theme**: Orthogonal projections, Gram-Schmidt, $A=QR$, progressive PLAID retrieval, and Poisson tail latency modeling.

* **Pure Math (Gilbert Strang Linear Algebra Ch 3)**:
  * Orthogonality of the four fundamental subspaces ($C(A^T) \perp N(A)$ and $C(A) \perp N(A^T)$).
  * Projections onto lines and subspaces, Projection Matrix $P = A(A^T A)^{-1} A^T$ ($P^2 = P, P^T = P$).
  * Least squares approximations, normal equations $A^T A \hat{x} = A^T b$.
  * Orthonormal bases, Gram-Schmidt orthogonalization process, $A = QR$ factorization.
* **Queuing Theory**: Poisson arrival modeling ($M/M/k$ queue); evaluating $p50, p95, p99, p99.9$ tail latency percentiles under load.
* **C++ & Python Track**:
  * **secan**: PLAID 3-stage progressive scoring (Centroid $\to$ Quantized MaxSim $\to$ FP32 MaxSim), Sparse Inverted Index with BM25, Block-Max WAND, Poisson query load generator.
  * **Python (`colbert-pytorch`)**: Training ColBERT with Margin MSE / in-batch negatives loss, residual token quantization.

| Day | Pure Mathematics (Strang) (90 min) | Systems / C++ Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Nov 3** | **STRANG §3.1**: Orthogonal vectors, orthogonal subspaces. Proving row space is orthogonal to nullspace in $\mathbb{R}^n$. | Re-read PLAID §5 on 2-bit/4-bit residual token quantization. | **secan**: Implement 2-bit/4-bit token quantization for ColBERT residuals (`token - centroid`). Build quantized MaxSim kernel. |
| **Tue Nov 4** | **STRANG §3.2**: Projection onto a 1D line: projection matrix $P = \frac{a a^T}{a^T a}$. Cauchy-Schwarz inequality proof from projection error. | BM25 algorithm theory: TF-IDF, document length normalization, saturation parameter $k_1$, length parameter $b$. | **secan**: Implement sparse inverted index: `term_id → PostingList{(doc_id, tf)}`. Implement BM25 scoring function. |
| **Wed Nov 5** | **STRANG §3.3**: Projection onto an $n$-dimensional subspace. Deriving the normal equations $A^T A \hat{x} = A^T b$ and projection matrix $P = A(A^T A)^{-1} A^T$. | Research paper: *"Faster Top-k Document Retrieval Using Block-Max Indexes"* (Ding & Suel 2011) §1–3. | **secan**: Implement **Block-Max WAND**: store max score per block of 128 postings. Skip non-competitive blocks during traversal. |
| **Thu Nov 6** | **STRANG §3.4**: Orthonormal vectors, square orthogonal matrices ($Q^T Q = I$), Gram-Schmidt process, and $A = QR$ factorization. | **CPPHI Parallel Algorithms**: `std::execution::par`, parallel divide-and-conquer search. | **secan**: Build Poisson query load generator in C++. Measure $p50, p95, p99, p99.9$ tail latencies under 500 QPS load. |
| **Fri Nov 7** | **STRANG §3.4**: Least squares solutions via QR factorization: $\hat{x} = R^{-1} Q^T b$. Properties of upper-triangular back-substitution. | **PIKUS Ch 8**: C++20 concurrency features (`std::latch`, `std::barrier`, `std::counting_semaphore`). | **secan**: Implement PLAID 3-stage pipeline end-to-end: Centroid $\to$ Quantized MaxSim $\to$ FP32 MaxSim. Benchmark latency percentiles. |

> **📝 Essay 10 (Sat Nov 8)**: *"PLAID, Block-Max WAND, and Tail Latency: The Engineering of 3-Stage Cascaded Retrieval"*

---

### Week 11 (Nov 10–14): Determinants, Eigenvalues, Spectral Theorem & LSM-Tree Engine

**Theme**: Determinants, eigenvalues, the Spectral Theorem for symmetric matrices, and LSM-Tree storage engines.

* **Pure Math (Gilbert Strang Linear Algebra Ch 4–5)**:
  * Determinants: 3 fundamental properties, algebraic formulas, cofactors, Cramer's rule.
  * Eigenvalues and Eigenvectors: $\det(A - \lambda I) = 0$, trace and determinant formulas, matrix diagonalization $A = S \Lambda S^{-1}$.
  * Symmetric Matrices: Proof that eigenvalues are all real and eigenvectors are orthogonal. The Spectral Theorem $A = Q \Lambda Q^T$.
* **Storage Engine Internals**: Log-Structured Merge-Tree (LSM-Tree) architecture for vectors: Write-Ahead Log (WAL), in-memory mutable MemTable HNSW, immutable disk segments in Apache Arrow format, background compaction.
* **C++ Engine (`secan`)**: Implement `LSMVectorEngine`: append-only `wal.bin`, mutable MemTable, immutable Arrow segment flushing, background multi-way compaction thread, DiskANN `io_uring` SSD streaming.

| Day | Pure Mathematics (Strang) (90 min) | Systems / C++ Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Nov 10** | **STRANG §4.1–4.4**: Determinants: axiomatic definition (linearity, sign change, $\det I = 1$), cofactor expansions, formula for $A^{-1}$. | Research paper: *"ACORN: Performant and Predicate-Agnostic Search Over Vector Embeddings"* (Patel et al. 2024). | **secan**: Implement `WriteAheadLog` (`wal.bin`) and in-memory mutable `MemTable` (dynamic HNSW absorbing live writes). |
| **Tue Nov 11** | **STRANG §5.1–5.2**: Eigenvalues and eigenvectors: characteristic polynomial $\det(A - \lambda I) = 0$. Matrix diagonalization $S^{-1} A S = \Lambda$. | Research paper: *"DiskANN: Fast Accurate Billion-point NN Search on a Single Node"* (Subramanya et al. 2019). | **secan**: Implement Segment Flusher: when MemTable reaches 100K vectors, flush to immutable disk segment in flat Arrow/Lance layout. |
| **Wed Nov 12** | **STRANG §5.3–5.4**: Systems of differential equations $\frac{du}{dt} = Au$, matrix exponential $e^{At}$, stability of linear dynamical systems. | Linux `io_uring` tutorial: submission queue (SQ), completion queue (CQ), zero-copy Direct I/O (`O_DIRECT`). | **secan**: Implement **Background Compaction Thread**: runs asynchronously in `std::jthread` to merge small segments into large optimized graphs. |
| **Thu Nov 13** | **STRANG §5.5**: Real symmetric matrices: proof that eigenvalues are real and eigenvectors are orthogonal. The Spectral Theorem $A = Q \Lambda Q^T$. | **ASYNC Ch 6 & Ch 9**: Boost.Asio I/O concepts, profiling asynchronous workflows. | **secan**: Implement DiskANN-style disk search: store vectors on disk with `O_DIRECT`. Fetch candidates asynchronously during beam search via `io_uring`. |
| **Fri Nov 14** | **STRANG §5.6**: Positive definite matrices: tests via eigenvalues, pivots, determinants, and energy $x^T A x > 0$. Cholesky factorization $A = L L^T$. | **FINSY Ch 3**: High-performance system measurement, scaling modules, latency distributions. | **secan**: Benchmark live ingestion throughput (inserts/sec) during concurrent search traffic. Verify 0-data-loss crash recovery via WAL replay. |

> **📝 Essay 11 (Sat Nov 15)**: *"LSM-Trees for Vector Databases: Write-Ahead Logs, MemTables, and Apache Arrow Storage"*

---

### Week 12 (Nov 17–21): SVD, Positive Definite Matrices, Zero-Copy nanobind & Block 1 Capstone

**Theme**: Singular Value Decomposition ($A = U \Sigma V^T$), PCA, zero-copy Python bindings, and CPU engine validation.

* **Pure Math (Gilbert Strang Linear Algebra Ch 6)**:
  * Singular Value Decomposition (SVD): $A = U \Sigma V^T$. Singular values $\sigma_i$, left singular vectors $U$, right singular vectors $V$.
  * Geometric interpretation of SVD: mapping hyper-spheres to hyper-ellipsoids.
  * Low-rank matrix approximation via truncated SVD (Eckart-Young-Mirsky Theorem).
  * Principal Component Analysis (PCA): centering data, sample covariance matrix $C = \frac{1}{n-1} X^T X$, principal eigenvectors.
* **C++ Engine (`secan`)**: Zero-copy Python bindings via `nanobind`, concurrent read-write HNSW with per-node reader-writer locks, memory-mapped binary index serialization, complete `ann-benchmarks` evaluation.

| Day | Pure Mathematics (Strang) (90 min) | Systems / Architecture Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Nov 17** | **STRANG §6.3**: Singular Value Decomposition (SVD): step-by-step proof that any $m \times n$ matrix factors into $A = U \Sigma V^T$. | `nanobind` documentation: zero-copy buffer protocol, NumPy type casters, ownership models. | **secan**: Set up `python/` directory with `nanobind`. Expose `LSMIndex`, `HNSWIndex`, `IVFPQIndex`, and `MultiVectorIndex` to Python. |
| **Tue Nov 18** | **STRANG §6.3**: Low-rank matrix approximation via truncated SVD. Frobenius norm error $\|A - A_k\|_F = \sqrt{\sum_{i=k+1}^r \sigma_i^2}$. | **PIKUS Ch 6 & ASYNC Ch 3**: Reader-writer locks, fine-grained concurrency, thread-safe data structures. | **secan**: Implement **concurrent HNSW**: per-node `std::shared_mutex`. Multiple concurrent searches (shared lock) + live insertions (exclusive lock). |
| **Wed Nov 19** | **STRANG §6.7**: Principal Component Analysis (PCA): variance maximization on unit sphere, connecting SVD of centered data to sample covariance. | **CPPHI Memory Management & FINSY Ch 5**: Custom memory allocators, memory-mapped files. | **secan**: Implement memory-mapped serialization: `save(path)` writes header + CSR graph + vectors. `load(path)` uses `mmap` for instant loading. |
| **Thu Nov 20** | **STRANG §6.7**: Matrix norms: Frobenius norm $\|A\|_F$, Spectral norm $\|A\|_2 = \sigma_{\max}$, Condition number $\kappa(A) = \sigma_{\max}/\sigma_{\min}$. | `ann-benchmarks` protocol: standardized evaluation across dataset sizes, recall levels, and build times. | **secan**: Run `ann-benchmarks` suite on SIFT1M and Cohere-1M. Plot Pareto frontier of `secan` vs `hnswlib` and `faiss`. |
| **Fri Nov 21** | **PURE LINEAR ALGEBRA SYNTHESIS**: Complete synthesis of Strang Ch 1–6 (Vector Spaces $\to$ Orthogonality $\to$ Eigenvalues $\to$ SVD). | **PIKUS Ch 12**: Design retrospective. | **Block 1 Grand Finale**: Update README with full benchmark suite. Tag `v1.0-cpu-complete`. Prepare CUDA GPU environment. |

> **📝 Essay 12 (Sat Nov 22)**: *"secan v1.0: Architectural Blueprint of a Modern C++20 Vector Engine with Python Bindings"*

---

# BLOCK 2: PROBABILITY THEORY, GPU ACCELERATION & MULTIMODAL (Months 4–6)

---

# 📅 MONTH 4: Pure Probability Theory, FlashAttention Kernel & Tensor Cores (Dec 2026)

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

### Week 15 (Dec 8–12): Continuous Distributions, PDF, Gaussians & FlashAttention Kernel

**Theme**: Continuous random variables, Gaussian distributions, and handcrafting the FlashAttention CUDA kernel from scratch.

* **Pure Probability (Blitzstein & Hwang Ch 5–6)**:
  * Continuous Random Variables: Probability Density Functions (PDF) $f(x)$, Cumulative Distribution Functions $F(x) = \int_{-\infty}^x f(t) dt$, $P(a \leq X \leq b) = \int_a b f(x) dx$.
  * Expectation and Variance for continuous variables: $\mathbb{E}[X] = \int x f(x) dx$, LOTUS for continuous distributions.
  * Uniform distribution $\text{Unif}(a, b)$, Exponential distribution $\text{Exp}(\lambda)$ (continuous memorylessness).
  * **The Normal / Gaussian Distribution $\mathcal{N}(\mu, \sigma^2)$**: Standard Normal $Z \sim \mathcal{N}(0, 1)$, proof that $\int e^{-z^2/2} dz = \sqrt{2\pi}$, 68-95-99.7 rule.
* **Frontier Reading**: *"FlashAttention: Fast and Memory-Efficient Exact Attention with IO-Awareness"* (Dao et al. 2022) + FlashAttention-2 (Dao 2023).
* **Implementation (`transformers-pytorch` & CUDA)**: Handcrafted **FlashAttention Forward CUDA Kernel** from scratch: load $Q$ tile into SRAM, loop over $K, V$ blocks, compute block attention, update running $m$ and $\ell$ via Online Softmax, scale and accumulate output $O$ in SRAM, write output to HBM.

| Day | Pure Probability & FlashAttention Math (90 min) | GPU / CUDA Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Dec 8** | **PROB §5.1–5.3**: Continuous random variables: PDF vs probability, CDF properties ($F' = f$), Uniform and Exponential distributions. | **PMPP Ch 16 / NVIDIA Docs**: Tensor Core architecture, WMMA API, mapping block matrix multiplies to Tensor Cores. | **CUDA**: Set up FlashAttention kernel scaffolding: grid configuration ($B \times H$), shared memory allocation for $Q_{block}, K_{block}, V_{block}, O_{block}$. |
| **Tue Dec 9** | **PROB §5.4–5.5**: The Normal / Gaussian distribution $\mathcal{N}(\mu, \sigma^2)$: PDF formula, standardization $Z = (X-\mu)/\sigma$, symmetry properties. | CUDA Shared Memory banking: avoiding bank conflicts when loading $Q, K^T$ tiles. | **CUDA**: Implement block GEMM $S_{ij} = Q_i K_j^T / \sqrt{d}$ in shared memory. Verify intermediate values against PyTorch. |
| **Wed Dec 10** | **PROB §6.1–6.3**: Moments, Moment Generating Functions (MGF) $M_X(t) = \mathbb{E}[e^{tX}]$. Finding moments via derivatives $\mathbb{E}[X^k] = M_X^{(k)}(0)$. | **CUDA-GUIDE Warp Primitives**: `__shfl_sync` for warp-level row max and row sum reductions. | **CUDA**: Implement Online Softmax update in registers: compute block max $\tilde{m}$, new max $m_{new}$, update $\ell$, rescale accumulator $O$. |
| **Thu Dec 11** | **PROB §6.4–6.5**: MGF of Normal distribution $M_Z(t) = e^{t^2/2}$. Sums of independent Normal random variables via MGF multiplication. | CUTLASS epilogue visitor patterns for fused matrix scaling. | **CUDA**: Optimize kernel to FlashAttention-2 loop order. Partition warps along sequence dimension to reduce inter-warp synchronization. |
| **Fri Dec 12** | **PROB §6.6**: Gamma distribution, Beta distribution, Cauchy distribution (undefined moments). | Profile kernel with NVIDIA Nsight Compute (`ncu`): measure DRAM bandwidth reduction and achieved TFLOPS. | **Python & CUDA**: Expose custom FlashAttention kernel to PyTorch via `torch.utils.cpp_extension`. Benchmark speedup vs PyTorch standard attention. |

> **📝 Essay 15 (Sat Dec 13)**: *"Building FlashAttention from Scratch in CUDA: IO-Aware Tiling and Online Softmax"*

---

### Week 16 (Dec 15–19): Joint Distributions, Covariance & GPU-Resident IVF

**Theme**: Joint probability distributions, covariance, independence vs correlation, and GPU-resident IVF Voronoi cell search.

* **Pure Probability (Blitzstein & Hwang Ch 7)**:
  * Joint PMFs and Joint PDFs: $f_{X, Y}(x, y)$, Marginal distributions $f_X(x) = \int f_{X, Y}(x, y) dy$.
  * Conditional distributions: $f_{Y|X}(y|x) = \frac{f_{X, Y}(x, y)}{f_X(x)}$.
  * Independence of continuous random variables: $f_{X, Y}(x, y) = f_X(x) f_Y(y)$.
  * 2D LOTUS: $\mathbb{E}[g(X, Y)] = \iint g(x, y) f(x, y) dx dy$.
  * **Covariance and Correlation**: $\text{Cov}(X, Y) = \mathbb{E}[(X - \mu_X)(Y - \mu_Y)] = \mathbb{E}[XY] - \mathbb{E}[X]\mathbb{E}[Y]$. Correlation coefficient $\rho(X, Y) = \frac{\text{Cov}(X, Y)}{\sigma_X \sigma_Y} \in [-1, 1]$.
* **C++ Engine (`secan`)**: GPU-resident IVF index (`GpuIVFIndex`), warp-cooperative cell scanning, CUDA streams for pipelined query execution.

| Day | Pure Probability (90 min) | GPU / CUDA Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Dec 15** | **PROB §7.1–7.2**: Joint, marginal, and conditional discrete distributions. Multinomial distribution. | Research paper: *"Billion-Scale Similarity Search with GPUs"* (Johnson, Douze, Jégou / Faiss GPU 2019) §1–3. | **secan**: Design GPU IVF memory layout: coarse centroids in global/constant memory; cell vectors stored as packed arrays with offset table. |
| **Tue Dec 16** | **PROB §7.3–7.4**: Joint continuous distributions: Joint PDF, finding marginals by integration. 2D Uniform distribution over shapes. | Faiss GPU paper §4–5: GPU $k$-selection, warp-cooperative list scanning. | **secan**: Implement GPU coarse quantizer: compute query-to-centroid distances on GPU; select top-`nprobe` cells with warp selection. |
| **Wed Dec 17** | **PROB §7.5**: 2D change of variables and the Jacobian: $f_{U, V}(u, v) = f_{X, Y}(x(u, v), y(u, v)) |J|$. Generating Normal variables via Box-Muller transform. | **CUDA-GUIDE Streams & Events**: Concurrent kernel execution, overlapping compute and data transfer. | **secan**: Implement **warp-cooperative cell scan**: within each selected cell, warps cooperatively scan vectors and update partial top-$k$. |
| **Thu Dec 18** | **PROB §7.6–7.7**: Covariance and Correlation: step-by-step proof that $-1 \leq \rho \leq 1$ via Cauchy-Schwarz inequality. Variance of sums $\text{Var}(X+Y) = \text{Var}(X) + \text{Var}(Y) + 2\text{Cov}(X, Y)$. | **PMPP Ch 13–14**: Irregular data structures, handling load imbalance across variable-length blocks. | **secan**: Implement GPU IVF-SQ8: store cell vectors as `uint8`. Implement integer distance kernel inside cells. |
| **Fri Dec 19** | **PROB §7.8**: Multivariate Normal Distribution $\mathcal{N}(\boldsymbol{\mu}, \boldsymbol{\Sigma})$: joint PDF formula with covariance matrix $\boldsymbol{\Sigma}$, contours of equal probability density as ellipsoids. | Review CUDA stream synchronization patterns. | **secan**: Implement **CUDA stream pipelining**: overlap query batch $N+1$ coarse search with batch $N$ cell scanning. Benchmark. |

> **📝 Essay 16 (Sat Dec 20)**: *"GPU-Resident IVF: Pipelining Voronoi Cell Search with CUDA Streams at 100K QPS"*

---

# 📅 MONTH 5: Mathematical Statistics, Limit Theorems, GPU Graphs & Multi-GPU (Jan 2027)

---

### Week 17 (Dec 22–26): Limit Theorems, LLN, CLT, Inequalities & CAGRA GPU Graphs

**Theme**: Laws of Large Numbers, Central Limit Theorem, probability inequalities, and GPU CAGRA graph traversal.

* **Pure Probability (Blitzstein & Hwang Ch 10)**:
  * Probability Inequalities: Markov's Inequality $P(X \geq a) \leq \frac{\mathbb{E}[X]}{a}$, Chebyshev's Inequality $P(|X - \mu| \geq k\sigma) \leq \frac{1}{k^2}$, Cauchy-Schwarz inequality for random variables $|\mathbb{E}[XY]|^2 \leq \mathbb{E}[X^2]\mathbb{E}[Y^2]$, Chernoff bounds.
  * **Weak and Strong Law of Large Numbers (WLLN & SLLN)**: Convergence in probability vs almost sure convergence. Sample mean $\bar{X}_n \to \mu$.
  * **The Central Limit Theorem (CLT)**: Rigorous proof via Moment Generating Functions that $\frac{\sum X_i - n\mu}{\sigma \sqrt{n}} \xrightarrow{d} \mathcal{N}(0, 1)$.
* **C++ Engine (`secan`)**: GPU HNSW/CAGRA-style graph traversal, warp-cooperative neighbor evaluation, visited-set bitmasks with `__ballot_sync`.

| Day | Pure Probability (90 min) | GPU / CUDA Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Dec 22** | **PROB §10.1**: Probability inequalities: Markov's and Chebyshev's inequalities proofs and applications in tail bounds. | Research paper: *"CAGRA: Highly Parallel Graph Construction and ANN Search for GPUs"* (NVIDIA 2024) §1–4. | **secan**: Design GPU graph layout: store HNSW graph adjacency in GPU memory as a fixed-degree CSR array with padding. |
| **Tue Dec 23** | **PROB §10.2**: Chernoff bounds: exponential moment bounds $P(X \geq a) \leq \min_{t > 0} \frac{M_X(t)}{e^{ta}}$. Tail bounds for sums of random variables. | CAGRA paper §5–6: Search kernel design, warp-level parallel beam search, avoiding dynamic queues on GPU. | **secan**: Implement **GPU graph search kernel**: each warp processes 1 query. 32 threads in warp evaluate 32 candidate neighbors in parallel. |
| **Wed Dec 24** | **PROB §10.3**: The Law of Large Numbers (LLN): Weak Law of Large Numbers proof via Chebyshev; Strong Law of Large Numbers (Borel-Cantelli lemmas). | **CUDA-GUIDE Warp Primitives**: `__ballot_sync`, `__any_sync`, warp-local bitfield operations. | **secan**: Implement warp-level visited set using `__ballot_sync` bitfields. Implement warp-level top-$k$ beam with shuffle min-reduction. |
| **Thu Dec 25** | **PROB §10.4**: The Central Limit Theorem (CLT): Step-by-step rigorous proof using Taylor expansion of MGFs. | **PMPP Ch 9**: Parallel Prefix Sum (Scan) for compacting candidate neighbor lists on GPU. | **secan**: Implement multi-query parallel graph search: launch grid of warps. Benchmark throughput vs CPU HNSW. |
| **Fri Dec 26** | **PROB §10.5**: Applications of CLT in statistical error estimation and confidence intervals. | Profile GPU graph search with `ncu`: measure compute-to-memory stall ratio. | **secan**: Optimize GPU graph search: add shared memory caching for frequently visited upper-layer hub nodes. |

> **📝 Essay 17 (Sat Dec 27)**: *"CAGRA and GPU Graph Traversal: Overcoming Random Memory Access at Warp Scale"*

---

### Week 18 (Dec 29 – Jan 2): Markov Chains, Transition Matrices & GPU FastScan

**Theme**: Discrete-time Markov chains, stationary distributions, and GPU shared-memory FastScan.

* **Pure Probability (Blitzstein & Hwang Ch 11–12)**:
  * Discrete-Time Markov Chains (DTMC): State space, Markov property $P(X_{n+1}=j | X_n=i, \dots) = P(X_{n+1}=j | X_n=i)$, Transition Probability Matrix $P$.
  * $n$-step transitions: Chapman-Kolmogorov equations, $P^{(n)} = P^n$.
  * Classification of states: Recurrent vs Transient, Absorbing states, Periodicity, Irreducibility.
  * **Stationary Distributions**: $\boldsymbol{\pi} P = \boldsymbol{\pi}$ with $\sum \pi_i = 1$. Existence and uniqueness theorems (Perron-Frobenius theorem connection). Random walks on graphs.
* **C++ Engine (`secan`)**: GPU PQ ADC kernel (LUT in shared memory), GPU FastScan using warp shuffles (`__shfl_sync`), GPU IVF-PQ combined index.

| Day | Pure Probability (90 min) | GPU / CUDA Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Dec 29** | **PROB §11.1–11.2**: Markov chains definition, transition probability matrix $P$, state transition diagrams, Chapman-Kolmogorov equations. | Faiss GPU PQ documentation: storing query lookup tables in GPU shared memory. | **secan**: Implement GPU PQ ADC kernel: upload query LUT to shared memory. Threads compute PQ distances via shared-memory lookups. |
| **Tue Dec 30** | **PROB §11.3**: Classification of states: irreducibility, periodicity, recurrence and transience. Absorbing Markov chains and fundamental matrix. | **CUDA-GUIDE Shared Memory**: Bank conflicts, padding strategies, broadcast mechanisms. | **secan**: Optimize shared-memory LUT layout: apply padding to ensure conflict-free broadcast reads during distance accumulation. |
| **Wed Dec 31** | **PROB §11.4**: Stationary distributions: solving $\boldsymbol{\pi} P = \boldsymbol{\pi}$ as a left-eigenvector problem with eigenvalue $\lambda = 1$. | Research: GPU FastScan architecture using warp-level registers. | **secan**: Implement **GPU 4-bit FastScan**: store 16 centroid distances in warp registers. Execute lookups via `__shfl_sync(mask, dist, code)`. |
| **Thu Jan 1** | **PROB §11.5–11.6**: Random walks on graphs: proving that $\pi_i = \frac{d_i}{2|E|}$ is the stationary distribution on an undirected graph with degree $d_i$. | **PMPP Ch 18**: Multi-GPU concepts, CUDA IPC, peer-to-peer memory access. | **secan**: Implement **GPU IVF-PQ**: combine GPU coarse cell routing with GPU FastScan distance inside cells. |
| **Fri Jan 2** | **PROB §12.1–12.3**: Markov Chain Monte Carlo (MCMC): Metropolis-Hastings algorithm theory and proof of detailed balance. | Review all GPU quantization kernels. | **secan**: Benchmark GPU-FP32 vs GPU-FP16 vs GPU-SQ8 vs GPU-IVF-PQ vs GPU-FastScan. Create comprehensive comparison table. |

> **📝 Essay 18 (Sat Jan 3)**: *"Markov Chains, Graph Random Walks, and Warp-Shuffle GPU FastScan"*

---

### Week 19 (Jan 5–9): Mathematical Statistics, MLE, PagedAttention & Async CPU↔GPU

**Theme**: Point estimation, Maximum Likelihood Estimation, Fisher Information, and PagedAttention (vLLM) memory architecture.

* **Mathematical Statistics (Statistical Theory)**:
  * Point Estimation: Estimators $\hat{\theta}(X_1, \dots, X_n)$, Bias $\text{Bias}(\hat{\theta}) = \mathbb{E}[\hat{\theta}] - \theta$, Mean Squared Error $\text{MSE}(\hat{\theta}) = \text{Var}(\hat{\theta}) + \text{Bias}^2$.
  * **Maximum Likelihood Estimation (MLE)**: Likelihood function $L(\theta; \mathbf{x}) = \prod f(x_i; \theta)$, log-likelihood $\ell(\theta)$, score function $S(\theta) = \ell'(\theta)$, solving $\ell'(\hat{\theta}) = 0$.
  * Fisher Information $I(\theta) = \mathbb{E}\left[\left(\frac{\partial}{\partial \theta} \ln f(X; \theta)\right)^2\right] = -\mathbb{E}\left[\frac{\partial^2}{\partial \theta^2} \ln f(X; \theta)\right]$.
  * Cramér-Rao Lower Bound (CRLB): $\text{Var}(\hat{\theta}) \geq \frac{1}{n I(\theta)}$ for unbiased estimators. Efficiency of estimators.
* **Systems / Frontier Reading**: CS:APP Chapter 9 "Virtual Memory" + vLLM PagedAttention paper.
* **C++ Engine (`secan`) & Python**:
  * **Python/CUDA**: Implement `BlockTable` data structure and **PagedAttention CUDA kernel** (non-contiguous physical block allocation).
  * **secan**: Double-buffered async pinned memory pipeline (`cudaHostAlloc`) overlapping batch search compute with PCIe transfers.

| Day | Mathematical Statistics (90 min) | GPU / vLLM Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Jan 5** | **STATS §1.1–1.3**: Point estimation foundations: Sample mean, sample variance ($s^2$ with $n-1$ denominator for unbiasedness), MSE decomposition. | vLLM Paper §1–3: The KV Cache fragmentation problem in LLMs ($60\%–80\%$ memory wasted on over-allocation). | **Python/CUDA**: Implement `BlockTable` data structure in PyTorch: maps logical sequence tokens to physical GPU memory blocks (block size 16). |
| **Tue Jan 6** | **STATS §2.1–2.3**: Maximum Likelihood Estimation (MLE): Deriving MLE for Gaussian mean/variance, Poisson $\lambda$, and Bernoulli $p$. Invariance property of MLEs. | vLLM Paper §4: PagedAttention kernel design: reading $K, V$ blocks via block lookup table in CUDA. | **CUDA**: Implement **PagedAttention CUDA kernel**: during self-attention, resolve physical $K, V$ block pointers on-the-fly via block table. |
| **Wed Jan 7** | **STATS §2.4–2.5**: Fisher Information: Definition and mathematical equivalence of variance of score vs negative expected Hessian of log-likelihood. | NVIDIA cuVS API design and architecture review. | **secan**: Build unified `GpuIndex` wrapper class: handles device memory lifecycle, async transfers, kernel launches, RAII cleanup. |
| **Thu Jan 8** | **STATS §2.6**: Cramér-Rao Lower Bound (CRLB): Step-by-step rigorous proof using Cauchy-Schwarz inequality on the score function. | **PMPP Ch 19**: Heterogeneous CPU+GPU workload partitioning. | **secan**: Implement **CPU↔GPU hybrid fallback**: partition oversized dataset into GPU VRAM (fast) and CPU RAM (AVX2). Merge results. |
| **Fri Jan 9** | **STATS §3.1–3.3**: Hypothesis testing foundations: Null ($H_0$) and alternative ($H_1$) hypotheses, Type I ($\alpha$) and Type II ($\beta$) errors, p-values, Neyman-Pearson Lemma. | Profile PagedAttention vs standard KV cache memory utilization in PyTorch. | **secan**: Benchmark query batch sizes ($B=1, 10, 100, 1000$). Plot the CPU vs GPU crossover curve. |

> **📝 Essay 19 (Sat Jan 10)**: *"Maximum Likelihood Estimation, Fisher Information, and PagedAttention Architecture"*

---

### Week 20 (Jan 12–16): Information Theory, Entropy, KL-Divergence & Multi-GPU NCCL

**Theme**: Information theory, Shannon entropy, Kullback-Leibler divergence, and multi-GPU distributed search with NCCL.

* **Pure Information Theory (Cover & Thomas / MacKay)**:
  * Shannon Entropy: $H(X) = -\sum p(x) \log_2 p(x)$ (axiomatic definition of uncertainty and information content).
  * Joint Entropy $H(X, Y)$ and Conditional Entropy $H(Y|X) = H(X, Y) - H(X)$.
  * **Relative Entropy / Kullback-Leibler (KL) Divergence**: $D_{KL}(P \| Q) = \sum P(x) \log \frac{P(x)}{Q(x)}$. Proof of Gibbs' Inequality: $D_{KL}(P \| Q) \geq 0$ with equality iff $P = Q$.
  * Mutual Information: $I(X; Y) = H(X) - H(X|Y) = D_{KL}(P(X, Y) \| P(X)P(Y))$.
  * Cross-Entropy: $H(P, Q) = H(P) + D_{KL}(P \| Q) = -\sum P(x) \log Q(x)$.
* **C++ Engine (`secan`)**: `MultiGpuIndex` class, dataset sharding across GPUs, NCCL AllGather result aggregation, multi-GPU load balancing.

| Day | Pure Information Theory (90 min) | GPU / CUDA Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Jan 12** | **INFO §1.1–1.3**: Shannon Entropy: Information content of events $I(x) = -\log_2 p(x)$, entropy $H(X)$, entropy of Bernoulli and discrete uniform distributions. | **CUDA-GUIDE Multi-GPU**: `cudaSetDevice`, peer-to-peer memory access (`cudaDeviceEnablePeerAccess`). | **secan**: Implement dataset sharding: split $N$ vectors into $G$ shards. Upload shard $i$ to GPU $i$. Build `MultiGpuIndex` class. |
| **Tue Jan 13** | **INFO §1.4–1.6**: Joint Entropy $H(X, Y)$, Conditional Entropy $H(Y|X)$, and the Chain Rule for Entropy: $H(X_1, \dots, X_n) = \sum H(X_i | X_{i-1}, \dots, X_1)$. | NCCL Documentation: `ncclAllGather`, `ncclAllReduce`, ring-based collective algorithms. | **secan**: Implement multi-GPU brute-force search: each GPU searches local shard; use NCCL AllGather to merge per-GPU top-$k$ heaps. |
| **Wed Jan 14** | **INFO §2.1–2.3**: Relative Entropy (KL Divergence) $D_{KL}(P \| Q)$. Rigorous proof that $D_{KL} \geq 0$ via Jensen's Inequality on convex functions. | Faiss multi-GPU implementation: replicated coarse quantizer with sharded inverted lists. | **secan**: Implement **multi-GPU IVF**: replicate coarse centroids on all GPUs; shard inverted lists across GPUs. Route queries via NCCL. |
| **Thu Jan 15** | **INFO §2.4–2.6**: Mutual Information $I(X; Y)$: properties, symmetry $I(X; Y) = I(Y; X)$, connection to KL divergence between joint and product marginals. | NVLink vs PCIe inter-GPU bandwidth analysis. | **secan**: Implement dynamic load balancing: redistribute heavy IVF cells across GPUs to prevent stragglers during multi-probe search. |
| **Fri Jan 16** | **INFO §3.1–3.3**: Cross-Entropy $H(P, Q) = -\sum P(x) \log Q(x)$. Mathematical proof that minimizing Cross-Entropy is equivalent to minimizing KL Divergence to target distribution. | Measure multi-GPU scaling efficiency across 1, 2, and 4 GPUs on synthetic billion-scale data. | **secan**: Benchmark multi-GPU search on SIFT1M and large synthetic datasets. Measure scaling efficiency and communication overhead. |

> **📝 Essay 20 (Sat Jan 17)**: *"Shannon Entropy, Kullback-Leibler Divergence, and Distributed Multi-GPU Search"*

---

# 📅 MONTH 6: Optimization, Fourier Analysis, ColPali & Master Release (Feb 2027)

---

### Week 21 (Jan 19–23): Convex Optimization, KKT Conditions & ColPali Multimodal

**Theme**: Convex optimization, KKT optimality conditions, and ColPali visual document retrieval.

* **Pure Mathematics (Boyd & Vandenberghe - *Convex Optimization*)**:
  * Convex sets (hyperplanes, halfspaces, polyhedra, positive semidefinite cone).
  * Convex functions: Definition $f(\theta x + (1-\theta)y) \leq \theta f(x) + (1-\theta)f(y)$, first-order convexity condition $f(y) \geq f(x) + \nabla f(x)^T(y-x)$, second-order condition $\nabla^2 f(x) \succeq 0$ (positive semidefinite Hessian).
  * Unconstrained convex optimization: Gradient descent convergence rates, condition numbers and convergence speed.
  * Constrained optimization and Duality: The Lagrangian $L(x, \lambda, \nu)$, Lagrange dual function $g(\lambda, \nu)$, weak and strong duality (Slater's condition).
  * **Karush-Kuhn-Tucker (KKT) Optimality Conditions**: Primal feasibility, dual feasibility, complementary slackness ($\lambda_i f_i(x^*) = 0$), gradient of Lagrangian vanishing ($\nabla L = 0$).
* **C++ Engine (`secan`) & Python**:
  * **Python (ColPali)**: Build `ColPaliPipeline`: pass document page images through ViT patch encoder $\to$ generate token matrices $\to$ score text queries against visual patches via MaxSim.
  * **secan**: GPU MaxSim kernel via batched CUTLASS GEMM + warp reductions; GPU NN-Descent for fast graph construction.

| Day | Pure Mathematics (Boyd Convex Optimization) (90 min) | GPU / CUDA Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Jan 19** | **CONVEX §2.1–2.4**: Convex sets: affine sets, convex combinations, convex hulls, cones, hyperplanes, and Euclidean balls. | Re-read ColBERT/PLAID papers with GPU focus: mapping MaxSim to batched GEMM + reductions. | **secan**: Implement **GPU MaxSim kernel**: formulate cross-token similarity as CUTLASS GEMM followed by warp row-max + column-sum reductions. |
| **Tue Jan 20** | **CONVEX §3.1–3.4**: Convex functions: first and second-order conditions for convexity. Epigraphs, Jensen's inequality, sublevel sets. | Research paper: *"Efficient K-NN Graph Construction for Generic Similarity Measures"* (Dong, Moses, Li / NN-Descent 2011). | **Python (ColPali)**: Build `ColPaliPipeline`: connect ViT patch projector (Month 2) to ColBERT MaxSim scoring head. |
| **Wed Jan 21** | **CONVEX §4.1–4.4**: Convex optimization problems: linear programs (LP), quadratic programs (QP), second-order cone programs (SOCP). | CAGRA paper §3–4: GPU NN-Descent implementation, warp-level neighbor exchange. | **secan**: Implement GPU NN-Descent base layer graph construction in CUDA. |
| **Thu Jan 22** | **CONVEX §5.1–5.4**: Duality: The Lagrangian, Lagrange dual problem, weak duality ($d^* \leq p^*$), duality gap, Slater's constraint qualification for strong duality ($d^* = p^*$). | **CUDA-GUIDE Dynamic Parallelism**: Launching child kernels from within a running kernel. | **Python (ColPali)**: Export document image patch embeddings to `secan` multi-vector index format. |
| **Fri Jan 23** | **CONVEX §5.5**: The Karush-Kuhn-Tucker (KKT) Conditions: Full rigorous proof of necessity and sufficiency for convex problems. Complementary slackness. | Review GPU ColBERT and ColPali integration. | **secan**: Ingest ColPali visual embeddings into `secan` GPU index. Execute text query $\to$ visual page search. |

> **📝 Essay 21 (Sat Jan 24)**: *"Convex Optimization, KKT Conditions, and ColPali Vision-Language Retrieval"*

---

### Week 22 (Jan 26–30): Fourier Analysis, Convolution Theorem, Kernel Fusion & Profiling

**Theme**: Continuous and discrete Fourier transforms, the Convolution Theorem, GPU kernel fusion, and Nsight profiling.

* **Pure Mathematics (Fourier Analysis & Signal Processing)**:
  * Fourier Series: Representing periodic functions as linear combinations of orthogonal sines and cosines $f(x) = \frac{a_0}{2} + \sum (a_n \cos nx + b_n \sin nx) = \sum c_n e^{inx}$.
  * The Continuous Fourier Transform: $\hat{f}(\xi) = \int_{-\infty}^\infty f(x) e^{-2\pi i x \xi} dx$, Inverse Fourier Transform $f(x) = \int_{-\infty}^\infty \hat{f}(\xi) e^{2\pi i x \xi} d\xi$.
  * **The Convolution Theorem**: $\mathcal{F}\{f * g\} = \mathcal{F}\{f\} \cdot \mathcal{F}\{g\}$ (convolution in time/spatial domain equals point-wise multiplication in frequency domain).
  * The Discrete Fourier Transform (DFT) and Fast Fourier Transform (FFT / Cooley-Tukey $O(N \log N)$ algorithm).
* **C++ Engine (`secan`)**: Fused distance + top-$k$ kernel, register tiling, occupancy tuning with `__launch_bounds__`, non-coherent cache loads (`__ldg()`).

| Day | Pure Mathematics (Fourier Analysis) (90 min) | GPU / CUDA Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Jan 26** | **FOURIER §1.1–1.4**: Fourier Series: Orthogonality of $\{e^{inx}\}_{n=-\infty}^\infty$ over $[-\pi, \pi]$, calculating Fourier coefficients $c_n = \frac{1}{2\pi}\int_{-\pi}^\pi f(x) e^{-inx} dx$, Parseval's identity. | **CUDA-GUIDE Occupancy Calculator**: Shared memory vs register limits per SM. | **secan**: Profile all GPU kernels with NVIDIA Nsight Compute (`ncu`). Identify compute-bound vs memory-bound bottlenecks. |
| **Tue Jan 27** | **FOURIER §2.1–2.3**: The Continuous Fourier Transform $\hat{f}(\xi)$. Symmetries of Fourier transforms for real, even, and odd functions. Fourier transform of Gaussian $\mathcal{F}\{e^{-\pi x^2}\} = e^{-\pi \xi^2}$. | Research: Kernel fusion techniques in CUB and Thrust libraries. | **secan**: Implement **fused distance+topk kernel**: maintain thread-local top-$k$ heap in registers/shared memory, writing only final results to global memory. |
| **Wed Jan 28** | **FOURIER §2.4–2.5**: Properties of Fourier Transforms: Linearity, time-shifting, frequency-shifting, differentiation in time domain $\mathcal{F}\{f'\} = 2\pi i \xi \hat{f}(\xi)$. | **PMPP Ch 5**: Register tiling strategies to eliminate shared memory round-trips. | **secan**: Implement **register-tiled distance computation**: unroll inner dimension loops into registers to maximize ILP on GPU. |
| **Thu Jan 29** | **FOURIER §3.1–3.3**: The Convolution Theorem: Step-by-step rigorous proof that $\mathcal{F}\{f * g\} = \hat{f} \cdot \hat{g}$. Applications in linear filters. | **CUDA-GUIDE PTX ISA**: Read-only texture cache path (`__ldg()`), `__launch_bounds__` compiler directives. | **secan**: Add `__ldg()` intrinsic for dataset vector reads; tune `__launch_bounds__(threads_per_block, min_blocks_per_sm)`. |
| **Fri Jan 30** | **FOURIER §4.1–4.3**: The Discrete Fourier Transform (DFT) and Fast Fourier Transform (FFT): Cooley-Tukey divide-and-conquer radix-2 algorithm. | Nsight Compute comparison: before vs after fusion profiling. | **secan**: Run full GPU benchmark suite. Compare initial Week 13 naive kernels vs final Week 22 fused kernels ($10\times–50\times$ speedup). |

> **📝 Essay 22 (Sat Jan 31)**: *"Fourier Analysis, The Convolution Theorem, and GPU Kernel Fusion"*

---

### Week 23 (Feb 2–6): Spectral Graph Theory, Cheeger's Inequality & ARM NEON

**Theme**: Spectral graph theory, Cheeger's inequality, ARM NEON SIMD, and cross-platform portability.

* **Pure Mathematics (Spectral Graph Theory - Fan Chung / Spielman)**:
  * Normalized Graph Laplacian $\mathcal{L} = D^{-1/2} L D^{-1/2} = I - D^{-1/2} A D^{-1/2}$.
  * Eigenvalues of Normalized Laplacian: $0 = \lambda_1 \leq \lambda_2 \leq \dots \leq \lambda_n \leq 2$. Multiplicity of $\lambda=0$ equals number of connected components.
  * **Cheeger's Inequality**: $\frac{\lambda_2}{2} \leq h(G) \leq \sqrt{2\lambda_2}$, where $h(G)$ is the Cheeger isoperimetric constant (conductance of the graph). Rigorous connection between spectral gap and graph bottleneck cuts.
* **C++ Engine (`secan`)**: ARM NEON distance kernels (`float32x4_t`, `vfmaq_f32`, `vaddvq_f32`), compile-time and runtime CPU feature detection (`cpuid`), cross-platform CMake CI.

| Day | Pure Mathematics (Spectral Graph Theory) (90 min) | Systems / ARM Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Feb 2** | **SPECTRAL §1.1–1.3**: The Graph Laplacian $L = D - A$ revisited. Quadratic form $x^T L x = \sum_{(u, v) \in E} (x_u - x_v)^2$. Proof that $L$ is positive semidefinite. | ARM NEON Intrinsics Guide: `vld1q_f32`, `vfmaq_f32`, `vaddvq_f32`, `vmaxvq_f32`. | **secan**: Design unified SIMD abstraction layer: `namespace simd { float l2_squared(const float*, const float*, int); }` with dispatch. |
| **Tue Feb 3** | **SPECTRAL §1.4–1.6**: The Normalized Graph Laplacian $\mathcal{L} = I - D^{-1/2} A D^{-1/2}$. Bounds on eigenvalues ($0 \leq \lambda_i \leq 2$), bipartiteness and $\lambda_n = 2$. | ARM NEON programming manual: 128-bit vector types (`float32x4_t`, `uint8x16_t`), FMA instruction throughput. | **secan**: Implement `l2_squared_neon()` and `cosine_distance_neon()` using ARM NEON intrinsics with 4-way accumulator unrolling. |
| **Wed Feb 4** | **SPECTRAL §2.1–2.3**: Graph cuts and Conductance (Cheeger constant) $h(G) = \min_{S \subset V} \frac{|\partial S|}{\min(\text{vol}(S), \text{vol}(S^c))}$. | **AGNER Ch 14**: Cross-platform optimization, compiler-specific intrinsics differences. | **secan**: Implement NEON integer kernels: `l2_squared_sq8_neon()` and `cosine_distance_sq8_neon()`. |
| **Thu Feb 5** | **SPECTRAL §2.4**: Cheeger's Inequality: Rigorous proof connecting the spectral gap $\lambda_2$ to the conductance $h(G)$ via Fiedler vector sweep cuts. | Research: runtime CPU dispatch patterns in Faiss and HNSWLib (`platform_macros.h`). | **secan**: Implement runtime CPU feature detection: `cpuid` on x86, `/proc/cpuinfo` / `sysctl` on ARM. Configure dynamic dispatch. |
| **Fri Feb 6** | **SPECTRAL §3.1**: Expander graphs: Spectral expansion vs edge expansion. Why Ramanujan graphs have optimal small-world routing properties. | Set up cross-platform CI matrix: Ubuntu x86_64, macOS Apple Silicon (ARM64). | **Python & secan**: Export PyTorch Transformer to ONNX. Verify `secan` builds and passes all tests on both x86_64 and ARM64. |

> **📝 Essay 23 (Sat Feb 7)**: *"Spectral Graph Theory, Cheeger's Inequality, and Cross-Platform ARM NEON Optimization"*

---

### Week 24 (Feb 9–13): 6-Month Pure Mathematics Synthesis & Master Engine Release

**Theme**: Master mathematical synthesis (Trig $\to$ Calculus $\to$ Linear Algebra $\to$ Probability $\to$ Stats $\to$ Optimization $\to$ Spectral Theory), full benchmarking, and v2.0 production release.

* **Pure Mathematics Synthesis**: Comprehensive synthesis connecting:
  1. Trigonometry & Complex Numbers ($e^{i\theta}$)
  2. Multivariable Calculus & Gradient Optimization ($\nabla f, H, \text{KKT}$)
  3. Linear Algebra & Spectral Decompositions ($A = U \Sigma V^T$)
  4. Probability & Information Theory ($H(X), D_{KL}, \text{MLE}$)
  5. Fourier Transforms & Spectral Graph Theory ($\mathcal{F}, \lambda_2, \text{Cheeger}$)
* **C++ Engine (`secan`)**: Comprehensive `secan` CLI tool, full Doxygen documentation, 5 standalone runnable examples, complete `ann-benchmarks` evaluation suite, `v2.0` release.

| Day | Pure Mathematics Master Synthesis (90 min) | Systems / Architecture Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Feb 9** | **MASTER SYNTHESIS (Part 1)**: The geometric thread: from the Unit Circle in $\mathbb{R}^2$ to Euclidean Hyperspheres, Hilbert Spaces, and SVD in $\mathbb{R}^D$. | **PIKUS Ch 12**: Design for performance retrospective — lessons from building a complete engine. | **secan**: Implement comprehensive `secan` CLI: `secan build --index hnsw --gpu`, `secan search --query q.fvecs --k 10`, `secan bench`. |
| **Tue Feb 10** | **MASTER SYNTHESIS (Part 2)**: The optimization thread: from 1D derivatives to multivariable Hessians, Lagrange Multipliers, KKT duality, and Gradient Descent. | Review `ann-benchmarks` standard evaluation protocol. | **Master Benchmark Run**: Execute full benchmark matrix across ALL index types (Brute-Force, IVF, HNSW, ColBERT) on CPU and GPU. |
| **Wed Feb 11** | **MASTER SYNTHESIS (Part 3)**: The stochastic thread: from Kolmogorov's axioms to Central Limit Theorem, Fisher Information, and Shannon Entropy. | Doxygen documentation standards and C++ API design best practices. | **secan**: Generate full Doxygen API documentation for every public class, function, and parameter. |
| **Thu Feb 12** | **MASTER SYNTHESIS (Part 4)**: The spectral thread: from Fourier series to Graph Laplacians, Algebraic Connectivity, and Small-World Expander graphs. | Code cleanup, compiler warning elimination (`-Wall -Wextra -Wpedantic -Werror`). | **secan**: Create `examples/` directory: (1) Basic CPU search, (2) HNSW index, (3) Quantized search, (4) ColBERT search, (5) GPU batch search. |
| **Fri Feb 13** | — | — | **Grand Finale**: Update README with final architecture diagram, benchmark tables, and Python examples. Git tag `v2.0-complete`. |

> **📝 Essay 24 (Sat Feb 14)**: *"6 Months from Scratch: The Complete Synthesis of Pure Mathematics, AI Systems, and GPU Engineering"*

---

## 📋 Comprehensive 24-Week Essay Publication Schedule

| Week | Essay Date | Essay Title |
|:---|:---|:---|
| **1** | Sat Sep 6 | *The Geometry of High-Dimensional Retrieval: From Trigonometric Coordinates and NDCG to CPU Performance Counters* |
| **2** | Sat Sep 13 | *Breaking Dependency Chains: Multi-Register SIMD Kernels and Multi-Head Attention Geometry* |
| **3** | Sat Sep 20 | *The Geometry of Subspaces and the Physics of CPU Caches* |
| **4** | Sat Sep 27 | *From Euler's Formula to Voronoi Cells: The Mathematical Architecture of Scalable Search* |
| **5** | Sat Oct 4 | *Multivariable Gradients, Hessians, and Low-Bit Quantization: Compressing High-Dimensional Information* |
| **6** | Sat Oct 11 | *Lagrange Multipliers, Jacobians, and Product Quantization: Compressing Vectors to 16 Bytes* |
| **7** | Sat Oct 18 | *Google ScaNN Anisotropic Loss, Vector Fields, and In-Register SIMD FastScan* |
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
| **18** | Sat Jan 3 | *Markov Chains, Graph Random Walks, and Warp-Shuffle GPU FastScan* |
| **19** | Sat Jan 10 | *Maximum Likelihood Estimation, Fisher Information, and PagedAttention Architecture* |
| **20** | Sat Jan 17 | *Shannon Entropy, Kullback-Leibler Divergence, and Distributed Multi-GPU Search* |
| **21** | Sat Jan 24 | *Convex Optimization, KKT Conditions, and ColPali Vision-Language Retrieval* |
| **22** | Sat Jan 31 | *Fourier Analysis, The Convolution Theorem, and GPU Kernel Fusion* |
| **23** | Sat Feb 7 | *Spectral Graph Theory, Cheeger's Inequality, and Cross-Platform ARM NEON Optimization* |
| **24** | Sat Feb 14 | *6 Months from Scratch: The Complete Synthesis of Pure Mathematics, AI Systems, and GPU Engineering* |
