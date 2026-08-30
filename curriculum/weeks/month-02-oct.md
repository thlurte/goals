# Month 2 — Oct (Weeks 5–8)

> Part of the [28-week curriculum](../README.md). Research: [`research/`](../../research/README.md).

| | |
|:---|:---|
| [← Month 1 — Sep](month-01-sep.md) | [Month 3 — Nov →](month-03-nov.md) |

---

# 📅 MONTH 2: Multivariable Calculus, Vector Fields, Vision Transformers & HNSW (Oct 2026)

> **🔬 Monthly research**: *Anisotropy, Hubness, and Bits: SQ / PQ / FastScan / ScaNN **+ OPQ / asymmetric distance*** → publish **Sun Oct 25** · folder `research/2026-10-anisotropy-hubness-bits/`

---

### Week 5 (Sep 29 – Oct 3): Partial Derivatives, Gradients, Hessians, **Probability Primer** & Vision Transformer (ViT)

**Theme**: Multivariable functions, gradient vectors, Hessian matrices, **probability bridge** for Weeks 7–8, and Vision Transformers from scratch.

* **Pure Math (Strang Calc Ch 13 + Probability Primer)**:
  * Functions of several variables $f(x, y, z)$, level curves and contour maps.
  * Partial derivatives $\frac{\partial f}{\partial x}, \frac{\partial f}{\partial y}$, Clairaut's Theorem (equality of mixed partials $\frac{\partial^2 f}{\partial x \partial y} = \frac{\partial^2 f}{\partial y \partial x}$).
  * The Gradient vector $\nabla f = \left( \frac{\partial f}{\partial x_1}, \dots, \frac{\partial f}{\partial x_n} \right)$, directional derivatives $D_{\mathbf{u}} f = \nabla f \cdot \mathbf{u}$.
  * The Hessian matrix $H[i, j] = \frac{\partial^2 f}{\partial x_i \partial x_j}$, Second Derivative Test for multivariable extrema.
  * **🔗 Probability Primer** (Mon): Expectation $\mathbb{E}[X]$, Variance $\text{Var}(X)$, Gaussian distribution $\mathcal{N}(\mu, \sigma^2)$, random projections, Johnson-Lindenstrauss lemma — **bridge for RaBitQ, ScaNN, Hubness in Weeks 7–8**.
  * **🔗 LSH & IEEE 754** (Thu): Locality-Sensitive Hashing families (random hyperplane LSH, SimHash, multi-probe LSH); IEEE 754 floating-point bit layout (sign/exponent/mantissa), rounding modes, subnormal traps — **foundations for quantization kernels and MUVERA FDEs**.
* **C++ Track**: `ScalarQuantizer`, SQ8/SQ4 integer AVX2, 2-stage re-ranker.
* **DL**: Sat Oct 4 — ViT `PatchEmbedding` + `[CLS]`.

| Day | Pure Mathematics (90 min) | Systems / C++ Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Sep 29** | **🔗 PROBABILITY PRIMER**: Expectation $\mathbb{E}[X] = \sum x \, p(x)$, Variance $\text{Var}(X)$, Gaussian $\mathcal{N}(\mu, \sigma^2)$, Random Projections: project $\mathbb{R}^D \to \mathbb{R}^d$ with $d = O(\epsilon^{-2} \log n)$ (Johnson-Lindenstrauss lemma). Skewness $S_{N_k}$ preview for hubness. | **AGNER Ch 7.2 & CSAPP §2.2–2.3**: Integer arithmetic efficiency, two's complement, overflow, bit-width conversion. | **secan**: Implement `ScalarQuantizer` with **percentile clipping (0.05th/99.95th)** to handle outlier dimensions. Verify dequantization error. |
| **Tue Sep 30** | **CALC §13.4**: Tangent planes and linear approximations: $L(x, y) = f(a, b) + f_x(a, b)(x-a) + f_y(a, b)(y-b)$. Total differentials. | **INTEL Intrinsics Guide**: Study `_mm256_maddubs_epi16`, `_mm256_madd_epi16`, `_mm256_dpbusd_epi32` (VNNI dot product). | **secan**: Implement `l2_squared_sq8()` using AVX2 integer intrinsics. Process 32 dimensions per iteration in a single `__m256i`. |
| **Wed Oct 1** | **CALC §13.5**: The Multivariable Chain Rule for paths and surfaces. Tree diagrams for composite multivariable functions. | **AGNER Ch 12**: Integer SIMD saturation arithmetic, signed vs unsigned byte multiplication, widening instructions. | **secan**: SQ8 LUT / packed layout polish; SIMD path vs scalar dequant error check. |
| **Thu Oct 2** | **🔗 LSH & FP FORMATS**: Locality-Sensitive Hashing: random hyperplane LSH ($h(x) = \text{sign}(r \cdot x)$), collision probability $P = 1 - \frac{\theta}{\pi}$. Multi-probe LSH. SimHash → MUVERA connection. **IEEE 754**: sign/exponent/mantissa bits, FP16 vs BF16 vs TF32 format differences, Kahan summation for long reduction chains. | **CSAPP §2.4 (deep)**: Floating-point representation, rounding modes (round-to-nearest-even), subnormals, FP16/BF16 range vs precision tradeoffs for quantization kernels. | **secan**: Implement 4-bit scalar quantization (`SQ4`): pack 2 dimensions per byte with nibble masking. Build 2-stage SQ8 $\to$ FP32 re-ranker. |
| **Fri Oct 3** | **CALC §13.7**: Maximum and minimum values of multivariable functions, critical points, the Hessian matrix and discriminant $D = f_{xx} f_{yy} - (f_{xy})^2$. | **PIKUS Ch 9**: High-performance C++, move semantics, zero-copy buffer views (`std::span`). | **secan**: `std::span` views over quantized buffers; zero-copy encode path. *(DL: Sat Oct 4 ViT.)* |

> **📝 Essay 5 (Sat Oct 4)**: *"Multivariable Gradients, Hessians, and Low-Bit Quantization: Compressing High-Dimensional Information"*  
> **🧠 DL weekend**: ViT patch embed + `[CLS]`.

---

### Week 6 (Oct 6–10): Lagrange Multipliers, Multiple Integrals, Jacobians & BERT from Scratch

**Theme**: Constrained optimization, multiple integrals, coordinate Jacobians, and BERT bidirectional modeling.

* **Pure Math (Strang Calc Ch 13 & 14)**:
  * **Constrained Optimization & Lagrange Multipliers**: $\nabla f = \lambda \nabla g$. Finding extrema on constrained surfaces. Multiple constraints $\nabla f = \lambda_1 \nabla g_1 + \lambda_2 \nabla g_2$.
  * **Double & Triple Integrals**: $\iint_R f(x, y) dA$, Fubini's Theorem, changing integration order.
  * **Jacobian of Transformations**: Coordinate transformations $x = g(u, v), y = h(u, v)$, the Jacobian determinant $J = \left|\frac{\partial(x, y)}{\partial(u, v)}\right|$, polar, cylindrical, and spherical substitutions.
* **C++ Track**: `ProductQuantizer`, ADC LUT, **asymmetric PQ** (FP32 query vs PQ db).
* **DL**: Sat Oct 11 — BERT + **InfoNCE**; export 768-D `.fvecs` for Week 8 Fri.

| Day | Pure Mathematics (90 min) | Systems / C++ Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Oct 6** | **CALC §13.8**: Constrained optimization: Method of Lagrange Multipliers. Geometric proof of $\nabla f \parallel \nabla g$ at tangent extrema. | Research paper: *"Product Quantization for Nearest Neighbor Search"* (Jégou et al. 2011) §1–4. | **secan**: Implement $k$-means clustering in C++ for a subspace: `train_kmeans(data, k=256, dim_sub)` using $k$-means++. |
| **Tue Oct 7** | **CALC §13.8**: Lagrange Multipliers with multiple constraints: $\nabla f = \lambda_1 \nabla g_1 + \lambda_2 \nabla g_2$. Solving constrained systems. | Faiss wiki on Product Quantizer: subspace splitting, codebook memory layouts. | **secan**: Implement `ProductQuantizer`: split $D$ dimensions into $M$ subspaces. Train $M$ codebooks. Encode vectors as $M$-byte codes. |
| **Wed Oct 8** | **CALC §14.1–14.2**: Double integrals over rectangular and general regions. Fubini's Theorem on swapping order of integration. | **AGNER Ch 7.10 & Ch 9**: Array structures for cache-friendly table lookups, stride optimization. | **secan**: Implement Asymmetric Distance Computation (ADC): precompute query-to-centroid table `float LUT[M][256]`. Distance = sum of $M$ lookups. |
| **Thu Oct 9** | **CALC §14.3–14.4**: Double integrals in polar coordinates: $\iint f(r\cos\theta, r\sin\theta) r \, dr \, d\theta$. Evaluating the Gaussian integral $\int_{-\infty}^\infty e^{-x^2} dx = \sqrt{\pi}$. | **PIKUS Ch 10**: Compiler optimizations, `__restrict__`, loop vectorization, Link-Time Optimization (LTO). | **secan**: **Asymmetric BQ**: FP32 query vs 1-bit db (Hamming / IP estimator). Keep query in FP32. |
| **Fri Oct 10** | **CALC §14.7**: Change of Variables in Multiple Integrals: Jacobian $J = \det\left(\frac{\partial(x, y, z)}{\partial(u, v, w)}\right)$. | **PIKUS Ch 11**: Undefined behavior, memory aliasing. | **secan (required)**: Wire **IVF + PQ ADC** sketch (`IVFPQIndex` stub): coarse IVF then PQ inside lists. Recall vs IVFFlat on SIFT subset. **Compose, do not stop at PQ-only.** *(DL InfoNCE: Sat Oct 11.)* |

> **📝 Essay 6 (Sat Oct 11)**: *"Lagrange Multipliers, Jacobians, and Product Quantization: Compressing Vectors to 16 Bytes"*  
> **🧠 DL weekend**: BERT + InfoNCE + **in-batch negatives**; export 768-D `.fvecs`. **Also**: implement `AdamW` optimizer from scratch ($m_t, v_t$ moment estimates, bias correction, **weight decay decoupling** from L2 reg). Train BERT with your AdamW; verify loss curve matches `torch.optim.AdamW`. **Hard negative mining**: retrieve BM25 top-100 per query, sample hard negatives from rank 10–100 for InfoNCE training.

---

### Week 7 (Oct 13–17): Vector Fields, **Matrix Calculus**, ScaNN Anisotropic Loss & FastScan

**Theme**: Vector fields (Mon–Tue), **matrix calculus for neural networks** (Thu–Fri replacing Stokes/Divergence), ScaNN directional error weighting, and in-register FastScan lookups.

* **Pure Math (Strang Calc Ch 15 + Matrix Calculus)**:
  * Vector fields $\mathbf{F}(x, y, z) = P\mathbf{i} + Q\mathbf{j} + R\mathbf{k}$, gradient fields, conservative vector fields.
  * Line integrals of scalar functions and vector fields $\int_C \mathbf{F} \cdot d\mathbf{r} = \int_a^b \mathbf{F}(\mathbf{r}(t)) \cdot \mathbf{r}'(t) dt$.
  * Fundamental Theorem for Line Integrals: $\int_C \nabla f \cdot d\mathbf{r} = f(\mathbf{r}(b)) - f(\mathbf{r}(a))$ (path independence).
  * Green's Theorem in the plane: $\oint_C (P dx + Q dy) = \iint_D \left(\frac{\partial Q}{\partial x} - \frac{\partial P}{\partial y}\right) dA$.
  * **🔗 Matrix Calculus** (Thu): Jacobian of $Y = XW$: $\frac{\partial \text{vec}(Y)}{\partial \text{vec}(W)}$. Chain rule through multi-layer networks. Softmax Jacobian $J_{ij} = p_i(\delta_{ij} - p_j)$. **Stokes'/Divergence theorems**: skim only — not implemented.
  * **🔗 Automatic Differentiation** (Fri): Forward-mode vs reverse-mode AD. Computational graphs. Why reverse-mode AD (backpropagation) is $O(1)$ backward passes regardless of parameter count.
* **ScaNN Theory**: Directional error decomposition: parallel error $e_\parallel$ vs orthogonal error $e_\perp$; ScaNN anisotropic loss $\mathcal{L} = h \|e_\parallel\|^2 + \|e_\perp\|^2$.
* **C++ Track**: ScaNN anisotropic PQ, BQ, FastScan, **OPQ / residual PQ**.
* **DL**: Sat Oct 18 — MRL tiny-corpus.

| Day | Pure Mathematics & ScaNN Math (90 min) | Systems / C++ Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Oct 13** | **CALC §15.1–15.2**: Vector fields in 2D/3D. Line integrals of vector fields along parameterized curves $\mathbf{r}(t)$. Work done by a force field. | ScaNN Paper §1–3: MIPS error decomposition: why orthogonal error $e_\perp$ has 0 expectation while parallel error $e_\parallel$ degrades inner products. | **secan**: Implement **ScaNN Anisotropic Loss** in `ProductQuantizer`: penalize parallel error with weight $h=5.0$. Compare codebooks. |
| **Tue Oct 14** | **CALC §15.3**: Conservative vector fields, potential functions $f$, and path independence of line integrals. Conditions for a field to be conservative. | **INTEL Intrinsics & AGNER-INST**: Deep dive into `_mm256_shuffle_epi8` (PSHUFB) semantics and port mapping. | **secan**: Implement **plain BQ** (`bit = val > 0`): Hamming via XOR+POPCNT. **Do not** implement RaBitQ yet (needs QR — Week 10). |
| **Wed Oct 15** | **CALC §15.4**: Green's Theorem: rigorous proof connecting a line integral around a closed curve to a double integral over the enclosed region. | Faiss FastScan documentation & André et al. (2015) paper §1–3. | **secan**: Implement 4-bit PQ encoding ($k=16$ centroids per subspace, packing 2 codes per byte). |
| **Thu Oct 16** | **🔗 MATRIX CALCULUS**: Jacobian of $Y = XW$. Chain rule through multi-layer networks: $\frac{\partial \mathcal{L}}{\partial W_1} = \frac{\partial \mathcal{L}}{\partial Y} \cdot \frac{\partial Y}{\partial Z} \cdot \frac{\partial Z}{\partial W_1}$. Softmax Jacobian $J_{ij} = p_i(\delta_{ij} - p_j)$. Skim Stokes/Divergence (not implemented). | AGNER-INST: Study `VPSHUFB`, `VPADDB`, `VPUNPCKLBW` instruction latency and accumulation chains. | **secan**: Implement **FastScan kernel**: load 16 centroid distances into `__m128i` / `__m256i`. Execute table lookups **entirely in-register** via PSHUFB. |
| **Fri Oct 17** | **🔗 AUTOMATIC DIFFERENTIATION**: Forward-mode ($\dot{x}$ tangent vectors) vs reverse-mode ($\bar{x}$ adjoint vectors). Computational graphs. Why backprop is $O(p)$ forward, $O(p)$ backward regardless of parameter count. Connection to Week 3 micrograd. | **CSAPP §5.10–5.12**: Register spilling, store-load forwarding, pipeline limiting factors. | **secan (required)**: **OPQ** (rotate then PQ) *or* **residual PQ**. Compare Recall@10 vs plain PQ on SIFT. Asymmetric ADC remains FP32 query. *(DL: Sat Oct 18 MRL.)* |

> **📝 Essay 7 (Sat Oct 18)**: *"Google ScaNN Anisotropic Loss, Vector Fields, and In-Register SIMD FastScan"*  
> **🧠 DL weekend**: MRL nested dims on tiny corpus.

---

### Week 8 (Oct 20–24): Graph Theory, The Hubness Phenomenon & HNSW Core

**Theme**: Small-world networks, hubness in high-D spaces, and a **correct** HNSW (optimize later).

* **Pure Math (Graph Theory & High-D Analytics)**:
  * Graph representations: adjacency matrices, Graph Laplacian $L = D - A$.
  * Algebraic connectivity (Fiedler vector) — intuition only; proofs deferred to Week 23.
  * **The Hubness Phenomenon**: Skewness of $k$-occurrences ($S_{N_k}$), measure concentration. **Whitening formula stated**; implement transform in Week 12 after SVD.
* **C++ Track**: HNSW core. **Fri required: 768-D text Recall@10 vs QPS** (InfoNCE export or Cohere slice — not SIFT-only).
  * **Deferred (required Week 12 Wed)**: bounded flat heap + bitset visited.

| Day | Pure Mathematics & Hubness Analytics (90 min) | Systems / C++ Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Oct 20** | **GRAPH THEORY**: Graphs and Networks: Incidence matrix $A$, Graph Laplacian $L = D - W$. | Research paper: *"Efficient and Robust ANN Search Using HNSW Graphs"* (Malkov & Yashunin 2020) §1–3. | **secan**: Implement `HNSWIndex` data structures: flat CSR adjacency (`neighbors[]` + `offsets[]`), node struct, entry point. |
| **Tue Oct 21** | **HUBNESS ANALYTICS**: Skewness of $k$-occurrences $S_{N_k}$. Why high hubness degrades graph routing. Whitening $x_{\text{white}} = \Lambda^{-1/2} Q^T (x - \mu)$ as **formula only** (implement Week 12 Mon). | HNSW paper §4–5: Algorithm 4 (heuristic neighbor selection), level multiplier $m_L$, parameter tuning ($M, ef$). | **secan**: Implement HNSW `insert()`: exponential level assignment, greedy descent, multi-layer neighbor connection. |
| **Wed Oct 22** | **SPECTRAL INTUITION**: Fiedler vector / algebraic connectivity — geometric meaning for bottlenecks (proofs → Week 23). | **PIKUS Ch 7**: Concurrent data structures, cache-friendly priority queues, memory allocation in graphs. | **secan**: Implement HNSW `search()`: beam search with visited-set. Implement Algorithm 4 diverse neighbor selection. |
| **Thu Oct 23** | **GRAPH EMBEDDINGS**: Shortest path distance vs Euclidean embedding distance. Small-world clustering coefficient $C$ and path length $L$. | **AGNER Ch 7.12–7.13 & Ch 7.5**: Branch prediction in graph traversal, branchless heap sift-down (**prep for Week 12 Wed**). | **secan**: Correctness harness: Recall@10 vs exact on SIFT subset. Do **not** optimize heaps yet → Week 12 Wed. |
| **Fri Oct 24** | **PURE MATH REVIEW**: Multivariable Calculus highlights (gradient, Hessian, Lagrange). | **CSAPP §5.14**: Profiling graph traversal bottlenecks with `perf record`. | **secan (required)**: Ingest **768-D text** `.fvecs` into HNSW; plot **Recall@10 vs QPS**. SIFT remains kernel bench; this is the text product bench. Tag `v0.3-hnsw`. |

> **📝 Essay 8 (Sat Oct 25)**: *"Building HNSW from Scratch: Graph Laplacians, The Hubness Phenomenon, and Sub-Millisecond Search"*  
> **🚀 Month 2 research PUBLISH (Sun Oct 25)**: freeze `research/2026-10-anisotropy-hubness-bits/paper.md` + public post.

---
