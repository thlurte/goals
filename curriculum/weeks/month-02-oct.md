# Month 2 — Oct (Weeks 5–8)

> **Retrieval math integration**: rate–distortion for SQ/PQ, randomized geometry, OPQ numerical linear algebra, and benchmark inference land in the existing Weeks 5–7 work. No time block changes.

> Part of the [28-week curriculum](../README.md). Research: [`research/`](../../research/README.md).

> **Monthly benchmark outcome**: publish comparable, reproducible evidence for this month’s systems milestone: manifests and raw results, parameter sweeps, Pareto/latency plots, oracle status, and concise conclusions. Preserve all inputs needed to reproduce the result.

| | |
|:---|:---|
| [← Month 1 — Sep](month-01-sep.md) | [Month 3 — Nov →](month-03-nov.md) |

---

# 📅 MONTH 2: Multivariable Calculus, Vector Fields, Vision Transformers & HNSW (Oct 2026)

> **🔬 Empirical Systems & Benchmarking Focus**: *Geometry-Aware Anisotropic Quantization & In-Register FastScan Kernels* · folder `research/2026-10-anisotropic-quantization/`

---


### 📚 Master Reference Textbooks (Month 2)
* **Microarchitectural Performance**: Denis Bakhvalov, *Performance Analysis and Tuning on Modern CPUs (2nd ed, 2024)* — Top-Down Microarchitecture Analysis (TMAM), PMU hardware counters, and port contention profiling.
* **Bitwise Systems Engineering**: Henry S. Warren Jr., *Hacker's Delight (2nd ed)* — Popcount trees, bit-matrix permutations, and branch-free SIMD index arithmetic.
* **Concurrent & Lock-Free Systems**: Paul E. McKenney, *Is Parallel Programming Hard ("The Perfbook")* — Cache coherence invalidations, RCU, Hazard Pointers, and Memory Models.
* **Memory Hierarchy Architecture**: Ulrich Drepper, *What Every Programmer Should Know About Memory* — Cache associativity, Structure-of-Arrays (SoA), and NUMA topology.
* **Metric Space Similarity Search**: Pavel Zezula et al., *Similarity Search: The Metric Space Approach* — Intrinsic dimensionality, VP-trees, and metric pruning bounds.
* **Numerical Linear Algebra & Optimization**: Gene H. Golub & Charles F. Van Loan, *Matrix Computations (4th ed)* & Jorge Nocedal & Stephen J. Wright, *Numerical Optimization (2nd ed)* — Block GEMM, Householder QR, L-BFGS, and KKT conditions.
* **Storage Engine Internals**: Alex Petrov, *Database Internals* — Disk-backed slotted pages, NVMe 4KB sector alignment, LSM-trees, and Raft consensus.
* **Cybernetics & Complex Systems**: Herbert A. Simon, *The Sciences of the Artificial* & Stanisław Lem, *Summa Technologiae* — Hierarchical complexity, bounded rationality, and intellectronics.
* **Matrix Analysis**: Roger A. Horn & Charles R. Johnson, *Matrix Analysis* (2nd ed, CUP 2012) — Ch 1–4 (Eigenvalues, Schur Triangularization, Spectral Theorem, Rayleigh Quotient, Courant-Fischer Minimax Theorem, Positive Semidefinite Matrices).
* **High-Dimensional Probability**: Roman Vershynin, *High-Dimensional Probability* (CUP 2018) — Ch 4–5 (Concentration of Random Matrices, Covariance Estimation, Anisotropic Loss).
* **Computer Architecture**: John L. Hennessy & David A. Patterson, *Computer Architecture: A Quantitative Approach* (6th ed) — Ch 3 (Instruction-Level Parallelism, Dynamic Scheduling, Hardware Speculation).

---

### Week 5 (Sat Oct 3 – Fri Oct 9): Partial Derivatives, Gradients, Hessians, **Probability Primer** & Vision Transformer (ViT)

**Theme**: Multivariable functions, gradient vectors, Hessian matrices, **probability bridge** for Weeks 7–8, and Vision Transformers from scratch.

* **Pure Math (Strang Calc Ch 13 + Probability Primer)**:
  * Functions of several variables $f(x, y, z)$, level curves and contour maps.
  * Partial derivatives $\frac{\partial f}{\partial x}, \frac{\partial f}{\partial y}$, Clairaut's Theorem (equality of mixed partials $\frac{\partial^2 f}{\partial x \partial y} = \frac{\partial^2 f}{\partial y \partial x}$).
  * The Gradient vector $\nabla f = \left( \frac{\partial f}{\partial x_1}, \dots, \frac{\partial f}{\partial x_n} \right)$, directional derivatives $D_{\mathbf{u}} f = \nabla f \cdot \mathbf{u}$.
  * The Hessian matrix $H[i, j] = \frac{\partial^2 f}{\partial x_i \partial x_j}$, Second Derivative Test for multivariable extrema.
  * **🔗 Probability Primer** (Mon): Expectation $\mathbb{E}[X]$, Variance $\text{Var}(X)$, Gaussian distribution $\mathcal{N}(\mu, \sigma^2)$, random projections, Johnson-Lindenstrauss lemma — **bridge for RaBitQ, ScaNN, Hubness in Weeks 7–8**.
  * **🔗 LSH & IEEE 754** (Thu): Locality-Sensitive Hashing families (random hyperplane LSH, SimHash, multi-probe LSH); IEEE 754 floating-point bit layout (sign/exponent/mantissa), rounding modes, subnormal traps — **foundations for quantization kernels and MUVERA FDEs**.
* **C++ Track**: `ScalarQuantizer`, SQ8/SQ4 integer AVX2, 2-stage re-ranker.
* **DL**: Tue & Wed mornings (06:30–08:30 builder track).

| Day | Systems Reading (05:30–06:30) | Morning Builder Track (06:30–08:30) | Night Hands-On C++/CUDA (20:30–23:00) |
|:---|:---|:---|:---|
| **Mon Oct 5** | **AGNER Ch 7.2 & CSAPP §2.2–2.3**: Integer arithmetic efficiency, two's complement, overflow, bit-width conversion. | **Hardware Profiling & Benchmark Sweeps** | **secan**: Implement `ScalarQuantizer` with **percentile clipping (0.05th/99.95th)** to handle outlier dimensions. Verify dequantization error. |
| **Tue Oct 6** | **INTEL Intrinsics Guide**: Study `_mm256_maddubs_epi16`, `_mm256_madd_epi16`, `_mm256_dpbusd_epi32` (VNNI dot product). | **DL Track (Part 1): Architecture & Tensor Shapes** | **secan**: Implement `l2_squared_sq8()` using AVX2 integer intrinsics. Process 32 dimensions per iteration in a single `__m256i`. |
| **Wed Oct 7** | **AGNER Ch 12**: Integer SIMD saturation arithmetic, signed vs unsigned byte multiplication, widening instructions. | **DL Track (Part 2): Training Loop & Verification** | **secan**: SQ8 LUT / packed layout polish; SIMD path vs scalar dequant error check. |
| **Thu Oct 8** | **CSAPP §2.4 (deep)**: Floating-point representation, rounding modes (round-to-nearest-even), subnormals, FP16/BF16 range vs precision tradeoffs for quantization kernels. | **DL / Vector Retrieval Integration & Profiling** | **secan**: Implement 4-bit scalar quantization (`SQ4`): pack 2 dimensions per byte with nibble masking. Build 2-stage SQ8 $\to$ FP32 re-ranker. |
| **Fri Oct 9** | **PIKUS Ch 9**: High-performance C++, move semantics, zero-copy buffer views (`std::span`). | **Weekly Technical Article: Drafting & Publishing** | **secan**: `std::span` views over quantized buffers; zero-copy encode path. |

#### 📋 Daily Action Items & Optional Activities (Week 5)
* **Mon Oct 5**:
  * `[ ]` **Core**: Implement `ScalarQuantizer` with percentile clipping (0.05th/99.95th); measure dequantization MSE on SIFT1M.
  * `⭐ Optional / Stretch`: Derive and plot the Johnson-Lindenstrauss projection dimension curve $d(\epsilon, n)$ for $\epsilon \in [0.1, 0.5]$ and $n=10^6$.
* **Tue Oct 6**:
  * `[ ]` **Core**: Implement `l2_squared_sq8()` using AVX2 `_mm256_maddubs_epi16` and `_mm256_madd_epi16` (32 dims per iteration).
  * `⭐ Optional / Stretch`: Benchmark VNNI integer dot product (`_mm256_dpbusd_epi32`) if your CPU supports AVX-VNNI.
* **Wed Oct 7**:
  * `[ ]` **Core**: Polish SQ8 LUT table layout; benchmark scalar dequantization + L2 vs direct integer SIMD distance.
  * `⭐ Optional / Stretch`: Profile memory bandwidth saturation during full dataset SQ8 scan vs FP32 scan.
* **Thu Oct 8**:
  * `[ ]` **Core**: Implement 4-bit scalar quantization (`SQ4`) with nibble packing; construct 2-stage `SQ8 -> FP32` candidate re-ranker.
  * `⭐ Optional / Stretch`: Implement a random hyperplane LSH bitset filter as a pre-stage candidate pruner.
* **Fri Oct 9**:
  * `[ ]` **Core**: Refactor buffer management to zero-copy `std::span<const uint8_t>`; verify zero dynamic allocations during query execution.
  * `⭐ Optional / Stretch`: Implement Kahan compensated summation in FP32 distance accumulator and compare error accumulation on 1536-D vectors.

#### ⛔ What NOT to Overspend Time On (Time Traps)
* ❌ **Do NOT** implement complex per-dimension dynamic range clipping—a global 0.05th/99.95th percentile clip is sufficient.
* ❌ **Do NOT** spend time writing 2-bit or 3-bit scalar quantizers—focus strictly on SQ8 (1 byte) and SQ4 (1 nibble).
* ❌ **Do NOT** try to implement Product Quantization (PQ) yet—PQ starts next week (Week 6).

> **📝 Essay 5 (Fri Oct 9)**: *"Low-Bit Compression Under Outliers: Gradients, Percentile Clipping, and SIMD Integer Saturation"*  
> **🧠 DL Builder Track (Tue/Wed)**: ViT patch embed + `[CLS]`.

---

### Week 6 (Sat Oct 10 – Fri Oct 16): Lagrange Multipliers, Multiple Integrals, Jacobians & BERT from Scratch

**Theme**: Constrained optimization, multiple integrals, coordinate Jacobians, and BERT bidirectional modeling.

* **Pure Math (Strang Calc Ch 13 & 14)**:
  * **Constrained Optimization & Lagrange Multipliers**: $\nabla f = \lambda \nabla g$. Finding extrema on constrained surfaces. Multiple constraints $\nabla f = \lambda_1 \nabla g_1 + \lambda_2 \nabla g_2$.
  * **Double & Triple Integrals**: $\iint_R f(x, y) dA$, Fubini's Theorem, changing integration order.
  * **Jacobian of Transformations**: Coordinate transformations $x = g(u, v), y = h(u, v)$, the Jacobian determinant $J = \left|\frac{\partial(x, y)}{\partial(u, v)}\right|$, polar, cylindrical, and spherical substitutions.
* **C++ Track**: `ProductQuantizer`, ADC LUT, **asymmetric PQ** (FP32 query vs PQ db).
* **DL**: Tue & Wed mornings (06:30–08:30 builder track).

| Day | Systems Reading (05:30–06:30) | Morning Builder Track (06:30–08:30) | Night Hands-On C++/CUDA (20:30–23:00) |
|:---|:---|:---|:---|
| **Mon Oct 12** | Research paper: *"Product Quantization for Nearest Neighbor Search"* (Jégou et al. 2011) §1–4. | **Hardware Profiling & Benchmark Sweeps** | **secan**: Implement $k$-means clustering in C++ for a subspace: `train_kmeans(data, k=256, dim_sub)` using $k$-means++. |
| **Tue Oct 13** | Faiss wiki on Product Quantizer: subspace splitting, codebook memory layouts. | **DL Track (Part 1): Architecture & Tensor Shapes** | **secan**: Implement `ProductQuantizer`: split $D$ dimensions into $M$ subspaces. Train $M$ codebooks. Encode vectors as $M$-byte codes. |
| **Wed Oct 14** | **AGNER Ch 7.10 & Ch 9**: Array structures for cache-friendly table lookups, stride optimization. | **DL Track (Part 2): Training Loop & Verification** | **secan**: Implement Asymmetric Distance Computation (ADC): precompute query-to-centroid table `float LUT[M][256]`. Distance = sum of $M$ lookups. |
| **Thu Oct 15** | **PIKUS Ch 10**: Compiler optimizations, `__restrict__`, loop vectorization, Link-Time Optimization (LTO). | **DL / Vector Retrieval Integration & Profiling** | **secan**: **Asymmetric BQ**: FP32 query vs 1-bit db (Hamming / IP estimator). Keep query in FP32. |
| **Fri Oct 16** | **PIKUS Ch 11**: Undefined behavior, memory aliasing. | **Weekly Technical Article: Drafting & Publishing** | **secan (required)**: Wire **IVF + PQ ADC** sketch (`IVFPQIndex` stub): coarse IVF then PQ inside lists. Recall vs IVFFlat on SIFT subset. **Compose, do not stop at PQ-only.** |

#### 📋 Daily Action Items & Optional Activities (Week 6)
* **Mon Oct 12**:
  * `[ ]` **Core**: Implement $k$-means clustering in C++ with $k$-means++ centroid seeding for a single subspace.
  * `⭐ Optional / Stretch`: Implement multi-threaded parallel $k$-means Lloyd iteration across CPU cores.
* **Tue Oct 13**:
  * `[ ]` **Core**: Implement `ProductQuantizer` ($D \to M$ subspaces, $M \times 256$ codebooks); encode $N$ vectors into $N \times M$ bytes.
  * `⭐ Optional / Stretch`: Measure quantization distortion $\|x - \tilde{x}\|^2$ as a function of subspace count $M \in \{8, 16, 32, 64\}$.
* **Wed Oct 14**:
  * `[ ]` **Core**: Implement Asymmetric Distance Computation (`float LUT[M][256]`); compute query distances via $M$ byte lookups.
  * `⭐ Optional / Stretch`: Implement 4-way unrolled ADC distance loop accumulating 4 database vectors simultaneously into registers.
* **Thu Oct 15**:
  * `[ ]` **Core**: Implement asymmetric 1-bit Binary Quantization (FP32 query dot product with 1-bit binary codes).
  * `⭐ Optional / Stretch`: Derive the exact expectation of inner-product error under 1-bit quantization for isotropic Gaussian vectors.
* **Fri Oct 16**:
  * `[ ]` **Core**: Wire `IVFPQIndex` composed index (coarse IVF centroids + PQ ADC inside inverted lists); benchmark Recall@10 on SIFT subset.
  * `⭐ Optional / Stretch`: Compare memory footprint and search latency of IVFFlat vs IVFPQ (e.g. 128 bytes/vector vs 16 bytes/vector).

#### ⛔ What NOT to Overspend Time On (Time Traps)
* ❌ **Do NOT** train PQ codebooks on all 1M vectors—subsample 50,000 to 100,000 vectors for codebook training.
* ❌ **Do NOT** implement symmetric PQ distance computation (SDC)—asymmetric ADC (FP32 query vs PQ codes) is strictly superior for query accuracy.
* ❌ **Do NOT** build a custom multi-threading pool for PQ encoding—standard `std::jthread` or OpenMP parallel loop is sufficient.

> **📝 Essay 6 (Fri Oct 16)**: *"Constrained Optimization and Subspace Codebooks: Lagrange Multipliers in Product Quantization"*  
> **🧠 DL Builder Track (Tue/Wed)**: BERT + InfoNCE + **in-batch negatives**; export 768-D `.fvecs`. **Also**: implement `AdamW` optimizer from scratch ($m_t, v_t$ moment estimates, bias correction, **weight decay decoupling** from L2 reg). Train BERT with your AdamW; verify loss curve matches `torch.optim.AdamW`. **Hard negative mining**: retrieve BM25 top-100 per query, sample hard negatives from rank 10–100 for InfoNCE training.

---

### Week 7 (Sat Oct 17 – Fri Oct 23): Matrix Calculus, Backpropagation Foundations, ScaNN Anisotropic Loss & FastScan

**Theme**: Deep Learning Matrix Calculus (Mon–Wed), Reverse-Mode Automatic Differentiation & Hessians (Thu–Fri), ScaNN directional error weighting, and in-register FastScan lookups.

* **Pure Math (Matrix Calculus & Automatic Differentiation for AI)**:
  * **Matrix Calculus & Linear Layer Gradients** (Mon): Trace identities, Frobenius inner products, vectorized chain rule. Analytical derivation of batched linear layer backpropagation: $\frac{\partial \mathcal{L}}{\partial W} = X^T \frac{\partial \mathcal{L}}{\partial Y}$, $\frac{\partial \mathcal{L}}{\partial X} = \frac{\partial \mathcal{L}}{\partial Y} W^T$, $\frac{\partial \mathcal{L}}{\partial b} = \mathbf{1}^T \frac{\partial \mathcal{L}}{\partial Y}$.
  * **Nonlinear Activation Jacobians & Softmax-Cross-Entropy** (Tue): Element-wise activation Jacobians (ReLU, GELU, SwiGLU). Softmax Jacobian $J_{ij} = s_i(\delta_{ij} - s_j)$. Rigorous analytical proof that $\frac{\partial \mathcal{L}_{\text{CE}}}{\partial \mathbf{z}} = \mathbf{s} - \mathbf{y}$.
  * **Attention Mechanism Matrix Calculus** (Wed): Differentiating Scaled Dot-Product Attention $\text{Attn}(Q, K, V) = \text{softmax}(Q K^T / \sqrt{d_k}) V$; step-by-step derivation of adjoint gradients $\frac{\partial \mathcal{L}}{\partial Q}, \frac{\partial \mathcal{L}}{\partial K}, \frac{\partial \mathcal{L}}{\partial V}$.
  * **🔗 Automatic Differentiation & Computational DAGs** (Thu): Forward-mode (JVPs) vs reverse-mode (VJPs). Memory tape management. Mathematical proof of $O(1)$ backward pass complexity for billion-parameter neural networks.
  * **🔗 Loss Surfaces, Hessians & Optimizer Dynamics** (Fri): The Hessian matrix $H = \nabla^2 \mathcal{L}$, condition numbers $\kappa = \frac{\lambda_{\max}}{\lambda_{\min}}$, convergence bounds ($\eta < \frac{2}{\lambda_{\max}}$), and AdamW second-moment scaling as diagonal Hessian preconditioning.
* **ScaNN Theory**: Directional error decomposition: parallel error $e_\parallel$ vs orthogonal error $e_\perp$; ScaNN anisotropic loss $\mathcal{L} = h \|e_\parallel\|^2 + \|e_\perp\|^2$.
* **C++ Track**: ScaNN anisotropic PQ, BQ, FastScan, **OPQ / residual PQ**.
* **DL**: Tue & Wed mornings (06:30–08:30 builder track).

| Day | Pure Mathematics & ScaNN Math (90 min) | Systems / C++ Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Oct 19** | **MATRIX CALCULUS (Linear Layers)**: Matrix trace identities. Full mathematical derivation of batched GEMM backpropagation: $\frac{\partial \mathcal{L}}{\partial W} = X^T \frac{\partial \mathcal{L}}{\partial Y}$, $\frac{\partial \mathcal{L}}{\partial X} = \frac{\partial \mathcal{L}}{\partial Y} W^T$, $\frac{\partial \mathcal{L}}{\partial b} = \mathbf{1}^T \frac{\partial \mathcal{L}}{\partial Y}$. | ScaNN Paper §1–3: MIPS error decomposition: why orthogonal error $e_\perp$ has 0 expectation while parallel error $e_\parallel$ degrades inner products. | **secan**: Implement **ScaNN Anisotropic Loss** in `ProductQuantizer`: penalize parallel error with weight $h=5.0$. Compare codebooks. |
| **Tue Oct 20** | **JACOBIANS & SOFTMAX CE**: Element-wise Jacobians (ReLU, GELU, SwiGLU). Softmax Jacobian $J_{ij} = s_i(\delta_{ij} - s_j)$. Analytical proof that $\frac{\partial \mathcal{L}_{\text{CE}}}{\partial \mathbf{z}} = \mathbf{s} - \mathbf{y}$. | **INTEL Intrinsics & AGNER-INST**: Deep dive into `_mm256_shuffle_epi8` (PSHUFB) semantics and port mapping. | **secan**: Implement **plain BQ** (`bit = val > 0`): Hamming via XOR+POPCNT. **Do not** implement RaBitQ yet (needs QR — Week 10). |
| **Wed Oct 21** | **ATTENTION MATRIX CALCULUS**: Differentiating Scaled Dot-Product Attention $\text{Attn}(Q, K, V) = \text{softmax}(Q K^T / \sqrt{d_k}) V$. Step-by-step derivation of upstream adjoint tensors $\frac{\partial \mathcal{L}}{\partial Q}, \frac{\partial \mathcal{L}}{\partial K}, \frac{\partial \mathcal{L}}{\partial V}$. | Faiss FastScan documentation & André et al. (2015) paper §1–3. | **secan**: Implement 4-bit PQ encoding ($k=16$ centroids per subspace, packing 2 codes per byte). |
| **Thu Oct 22** | **🔗 AUTOMATIC DIFFERENTIATION**: Computational DAGs, topological sorting. Forward-mode (JVPs) vs Reverse-mode (VJPs). Mathematical proof why reverse-mode backpropagation is $O(1)$ backward passes regardless of parameter count. | AGNER-INST: Study `VPSHUFB`, `VPADDB`, `VPUNPCKLBW` instruction latency and accumulation chains. | **secan**: Implement **FastScan kernel**: load 16 centroid distances into `__m128i` / `__m256i`. Execute table lookups **entirely in-register** via PSHUFB. |
| **Fri Oct 23** | **CSAPP §5.10–5.12**: Register spilling, store-load forwarding, pipeline limiting factors. | **Weekly Technical Article: Drafting & Publishing** | **secan (required)**: **OPQ** (rotate then PQ) *or* **residual PQ**. Compare Recall@10 vs plain PQ on SIFT. Asymmetric ADC remains FP32 query. |
* **Builder Track**: Mon: Hardware Profiling; Tue & Wed: DL Track; Thu: Integration & Profiling; Fri: Weekly Technical Article Drafting.
* **Pure Math**: Sat & Sun mornings (09:00–13:00, 8.0 hrs total).

#### 📋 Daily Action Items & Optional Activities (Week 7)
* **Mon Oct 19**:
  * `[ ]` **Core**: Implement ScaNN anisotropic loss in `ProductQuantizer` with parallel penalty weight $h=5.0$.
  * `⭐ Optional / Stretch`: Sweep $h \in [1.0, 10.0]$ on 768-D text embeddings to find optimal MIPS Recall@10 vs $h$.
* **Tue Oct 20**:
  * `[ ]` **Core**: Implement plain Binary Quantization (`_mm256_movemask_ps`) with Hamming distance via `_mm_popcnt_u64`.
  * `⭐ Optional / Stretch`: Benchmark SIMD popcount (`_mm512_popcnt_epi64` / AVX-512 VPOPCNTDQ) vs hardware instruction `popcnt`.
* **Wed Oct 21**:
  * `[ ]` **Core**: Implement 4-bit PQ codebook generator ($k=16$ centroids per subspace, packing 2 codes per byte).
  * `⭐ Optional / Stretch`: Analyze code distribution uniformity across the 16 centroid buckets to detect subspace collapse.
* **Thu Oct 22**:
  * `[ ]` **Core**: Implement AVX2 FastScan kernel executing 16-centroid distance lookups **entirely in-register** via `_mm256_shuffle_epi8` (PSHUFB).
  * `⭐ Optional / Stretch`: Measure L1 cache read bandwidth during FastScan to prove table lookups do not hit cache memory.
* **Fri Oct 23**:
  * `[ ]` **Core**: Implement Optimized Product Quantization (OPQ) orthogonal rotation matrix before PQ; benchmark Recall@10 vs plain PQ on SIFT.
  * `⭐ Optional / Stretch`: Implement residual PQ (2-stage PQ where stage 2 quantizes stage 1 residual error vector).

#### ⛔ What NOT to Overspend Time On (Time Traps)
* ❌ **Do NOT** implement RaBitQ this week—RaBitQ requires QR orthogonal factorizations which are formally studied in Week 10.
* ❌ **Do NOT** spend time proving classical 3D fluid or physical vector theorems (Stokes/Divergence)—all physics vector calculus has been purged in favor of neural network matrix calculus.
* ❌ **Do NOT** write a custom matrix optimizer for OPQ—a basic alternating least squares (ALS) rotation or residual PQ is 100% fine.

> **📝 Essay 7 (Fri Oct 23)**: *"Anisotropic Loss and In-Register SIMD Lookups: Directional Error Weighting and FastScan PSHUFB"*  
> **🧠 DL Builder Track (Tue/Wed)**: MRL nested dims on tiny corpus.

---

### Week 8 (Sat Oct 24 – Fri Oct 30): Graph Theory, The Hubness Phenomenon & HNSW Core

**Theme**: Small-world networks, hubness in high-D spaces, and a **correct** HNSW (optimize later).

* **Pure Math (Graph Theory & High-D Analytics)**:
  * Graph representations: adjacency matrices, Graph Laplacian $L = D - A$.
  * Algebraic connectivity (Fiedler vector) — intuition only; proofs deferred to Week 23.
  * **The Hubness Phenomenon**: Skewness of $k$-occurrences ($S_{N_k}$), measure concentration. **Whitening formula stated**; implement transform in Week 12 after SVD.
* **C++ Track**: HNSW core. **Fri required: 768-D text Recall@10 vs QPS** (InfoNCE export or Cohere slice — not SIFT-only).
  * **Deferred (required Week 12 Wed)**: bounded flat heap + bitset visited.

| Day | Pure Mathematics & Hubness Analytics (90 min) | Systems / C++ Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Oct 26** | **GRAPH THEORY**: Graphs and Networks: Incidence matrix $A$, Graph Laplacian $L = D - W$. | Research paper: *"Efficient and Robust ANN Search Using HNSW Graphs"* (Malkov & Yashunin 2020) §1–3. | **secan**: Implement `HNSWIndex` data structures: flat CSR adjacency (`neighbors[]` + `offsets[]`), node struct, entry point. |
| **Tue Oct 27** | **HUBNESS ANALYTICS**: Skewness of $k$-occurrences $S_{N_k}$. Why high hubness degrades graph routing. Whitening $x_{\text{white}} = \Lambda^{-1/2} Q^T (x - \mu)$ as **formula only** (implement Week 12 Mon). | HNSW paper §4–5: Algorithm 4 (heuristic neighbor selection), level multiplier $m_L$, parameter tuning ($M, ef$). | **secan**: Implement HNSW `insert()`: exponential level assignment, greedy descent, multi-layer neighbor connection. |
| **Wed Oct 28** | **SPECTRAL INTUITION**: Fiedler vector / algebraic connectivity — geometric meaning for bottlenecks (proofs → Week 23). | **PIKUS Ch 7**: Concurrent data structures, cache-friendly priority queues, memory allocation in graphs. | **secan**: Implement HNSW `search()`: beam search with visited-set. Implement Algorithm 4 diverse neighbor selection. |
| **Thu Oct 29** | **GRAPH EMBEDDINGS**: Shortest path distance vs Euclidean embedding distance. Small-world clustering coefficient $C$ and path length $L$. | **AGNER Ch 7.12–7.13 & Ch 7.5**: Branch prediction in graph traversal, branchless heap sift-down (**prep for Week 12 Wed**). | **secan**: Correctness harness: Recall@10 vs exact on SIFT subset. Do **not** optimize heaps yet → Week 12 Wed. |
| **Fri Oct 30** | **PURE MATH REVIEW**: Multivariable Calculus highlights (gradient, Hessian, Lagrange). | **CSAPP §5.14**: Profiling graph traversal bottlenecks with `perf record`. | **secan (required)**: Ingest **768-D text** `.fvecs` into HNSW; plot **Recall@10 vs QPS**. SIFT remains kernel bench; this is the text product bench. Tag `v0.3-hnsw`. |

#### 📋 Daily Action Items & Optional Activities (Week 8)
* **Mon Oct 26**:
  * `[ ]` **Core**: Implement `HNSWIndex` core memory layout with flat CSR adjacency array (`neighbors[]` and `offsets[]`).
  * `⭐ Optional / Stretch`: Profile memory fragmentation of dynamic node vectors `std::vector<std::vector<uint32_t>>` vs flat contiguous CSR buffer.
* **Tue Oct 27**:
  * `[ ]` **Core**: Implement HNSW `insert()` with exponential random level generator and greedy multi-layer descent.
  * `⭐ Optional / Stretch`: Compute degree distribution histogram across all nodes to verify graph connectivity properties.
* **Wed Oct 28**:
  * `[ ]` **Core**: Implement HNSW `search()` (greedy descent on upper layers, $efSearch$ beam search on layer 0); implement Algorithm 4 diverse neighbor heuristic.
  * `⭐ Optional / Stretch`: Measure the impact of Algorithm 4 neighbor diversity heuristic on Recall@10 vs simple nearest-neighbor graph edges.
* **Thu Oct 29**:
  * `[ ]` **Core**: Construct correctness test harness validating Recall@10 on 10,000 queries on SIFT subset.
  * `⭐ Optional / Stretch`: Measure the correlation between graph hop count and Euclidean distance to ground-truth neighbor.
* **Fri Oct 30**:
  * `[ ]` **Core**: Ingest 768-D text embeddings (`.fvecs`) into HNSW; plot Recall@10 vs QPS curve across $efSearch \in [10, 200]$. Tag `v0.3-hnsw`.
  * `⭐ Optional / Stretch`: Calculate empirical hubness skewness $S_{N_k}$ on the 768-D text dataset and identify top-10 hub nodes.

#### ⛔ What NOT to Overspend Time On (Time Traps)
* ❌ **Do NOT** attempt complex lock-free concurrent HNSW graph mutations this week—focus strictly on single-threaded algorithmic correctness first.
* ❌ **Do NOT** premature optimize the priority queues—standard `std::priority_queue` is fine (bounded flat heaps are added in Week 12).
* ❌ **Do NOT** implement SVD whitening transforms this week—whitening requires full Linear Algebra SVD (Week 12).

> **📝 Essay 8 (Fri Oct 30)**: *"Graph Laplacians, Hubness Skewness, and Navigable Small-World Routing: Building HNSW from Scratch"*  
> **🚀 Month 2 Builder Milestone (Fri Oct 30)**: End-to-end HNSW + FastScan SQ8/PQ benchmark verification across SIFT1M and 768-D text embeddings.

---


---

## ⚡  High-Dimensional Embedding Engine (Month 02 Focus)
> **Theme**: *Dense C++ Embedding Engine, SIMD GEMM, Activations & Tokenizer*
* In tandem with  vector search at 20:30–23:00, the 23:00–00:00 night block develops the standalone C++ multimodal embedding runtime , providing zero-copy feature ingestion directly into .
