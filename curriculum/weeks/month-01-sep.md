# Month 1 — Sep (Weeks 1–4)

> Part of the [28-week curriculum](../README.md). Research: [`research/`](../../research/README.md).

| | |
|:---|:---|
| [← Curriculum index](../README.md) | [Month 2 — Oct →](month-02-oct.md) |

---

# BLOCK I: VECTOR SEARCH ENGINE — 4 months (Weeks 1–16 / Sep–Dec 2026)

---

# 📅 MONTH 1: Pure Trigonometry, Single-Variable Calculus, SIMD & Transformers (Sep 2026)

> **🔬 Monthly research**: *Measurement Before Optimization: A Reproducible Protocol for Vector Distance Microbenchmarks* → publish **Sun Sep 27** · folder `research/2026-09-measurement-protocol/`

---

### Week 1 (Sep 1–5): Pure Trigonometry, Limits, Derivatives & Measurement

> **Hour-by-hour**: [`week-01/execution.md`](../week-01/execution.md)

**Theme**: Trigonometric ratios, unit circle wrapping, derivative foundations, and scientific C++ measurement.

* **Pure Math (Gelfand Trig & Strang Calc)**:
  * **Trig (Gelfand Ch 1–3)**: Trigonometric ratios in right triangles, radian measure, the wrapping function on the unit circle $x^2 + y^2 = 1$, graphs and periodic symmetries of $\sin\theta, \cos\theta, \tan\theta$.
  * **Calculus (Strang Ch 1–2)**: Intuitive and $\epsilon$-$\delta$ definitions of limits, continuity, first-principles derivative definition $f'(x) = \lim_{h \to 0} \frac{f(x+h) - f(x)}{h}$.
* **IR Analytics**: Mathematical definitions of NDCG@K, DCG formula, Ideal DCG (IDCG), MRR, **MAP** (Mean Average Precision).
* **C++ Track**:
  * **secan**: Google Benchmark, `.fvecs` loaders, IR metrics (NDCG, MRR, **MAP**), scalar baseline. **IP kernel Thursday.**
  * **DL**: Sat Sep 6 (not weekday).

| Day | Pure Mathematics (90 min) | Systems / C++ Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Sep 1** | **TRIG (Gelfand Ch 1–2)**: Geometric definition of sine/cosine from right triangles to unit circle coordinates. Radian measure and arc length. | **PIKUS Ch 2**: Performance measurements, high-res timers, profiler sampling, micro-benchmark noise floor. | **secan**: Integrate Google Benchmark via CMake. Add ASan/UBSan build flags. Write first benchmark for `l2_squared` with `DoNotOptimize`. |
| **Tue Sep 2** | **TRIG (Gelfand Ch 3)**: Periodic properties: $\sin(\theta + 2\pi) = \sin\theta$, parity: $\cos(-\theta) = \cos\theta$, $\sin(-\theta) = -\sin\theta$. Graphs of trig functions. | **CSAPP §5.1–5.6**: Compiler limitations, Cycles Per Element (CPE), loop inefficiencies, memory aliasing. | **secan**: Implement binary `.fvecs`, `.bvecs`, and `.ivecs` parsers. Download SIFT1M base + ground-truth; load into `data/sift1m/`. |
| **Wed Sep 3** | **CALC (Strang §1.1–1.5)**: Introduction to limits: $\lim_{x \to c} f(x) = L$, one-sided limits, continuity, the Intermediate Value Theorem. | **CSAPP §5.7**: Superscalar architecture, out-of-order execution, execution ports, latency vs throughput. | **secan**: Build IR metrics in `tests/test_ir_metrics.cpp` (NDCG@K, MRR, **MAP**). Run exact scan on a **SIFT1M subset** (e.g. 100K base / 1K queries) first; verify Recall@10 = 1.0. Full 1M scan = stretch. |
| **Thu Sep 4** | **CALC (Strang §2.1–2.3)**: Derivative from first principles. Power rule proof. | **AGNER Ch 3 & Ch 7.1–7.3**: Bottlenecks, FP efficiency. | **secan**: First-class **inner-product** kernel `ip()` alongside `l2_squared`. Distance enum: L2 / IP / cosine. *(DL: Sat Sep 6.)* |
| **Fri Sep 5** | **CALC (Strang §2.4–2.5)**: Product Rule $\frac{d}{dx}(uv) = u'v + uv'$, Quotient Rule, and differentiation of trigonometric functions ($\frac{d}{dx}\sin x = \cos x$). | **PIKUS Ch 1 & CSAPP §5.14**: Measurement-driven optimization, profiling-guided workflow with `perf stat`. | **secan**: Profile baseline scan with `perf stat`. Record IPC, cache misses, branch misses. Populate first row of README benchmark table. |

> **📝 Essay 1 (Sat Sep 6)**: *"The Geometry of High-Dimensional Retrieval: From Trigonometric Coordinates and NDCG to CPU Performance Counters"*  
> **🧠 DL weekend**: `uv init transformers-pytorch`; SDPA + causal mask.

---

### Week 2 (Sep 8–12): Trigonometric Identities, Chain Rule, SIMD AVX2 & Multi-Head Attention

**Theme**: Pure trigonometric identities, differentiation techniques, and instruction-level SIMD parallelism.

* **Pure Math (Gelfand Trig & Strang Calc)**:
  * **Trig (Gelfand Ch 4–5)**: Pythagorean identities ($\sin^2\theta + \cos^2\theta = 1$, $1 + \tan^2\theta = \sec^2\theta$), angle addition formulas $\cos(\alpha \pm \beta), \sin(\alpha \pm \beta)$, double-angle and half-angle formulas, product-to-sum identities.
  * **Calculus (Strang §2.6–3.2)**: The Chain Rule $\frac{d}{dx} f(g(x)) = f'(g(x)) g'(x)$, implicit differentiation, derivatives of exponential ($e^x$) and logarithmic functions ($\ln x$).
* **C++ Track**: FTZ/DAZ, AVX2 L2/cosine/**IP**, 4-way unroll, AVX-512 `#ifdef`.
* **DL**: Sat Sep 13 — MHA + GQA.

| Day | Pure Mathematics (90 min) | Systems / C++ Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Sep 8** | **TRIG (Gelfand Ch 4)**: Geometric proof of angle addition: $\cos(\alpha - \beta) = \cos\alpha \cos\beta + \sin\alpha \sin\beta$. Derivation of all addition formulas. | **AGNER Ch 12**: SIMD instructions, 256-bit YMM registers, data types, intrinsics syntax. | **secan**: Enable FTZ/DAZ flags. Implement `l2_squared_avx2()` in `src/search/distance_avx2.cpp`. Single accumulator baseline. |
| **Tue Sep 9** | **TRIG (Gelfand Ch 4)**: Double-angle formulas: $\sin 2\theta = 2\sin\theta\cos\theta$, $\cos 2\theta = \cos^2\theta - \sin^2\theta$. Half-angle formulas. | **CSAPP §5.8–5.9**: Loop unrolling, breaking dependency chains with multiple independent accumulator registers. | **secan**: Implement 4-way unrolled `l2_squared_avx2` with 4 parallel `__m256` accumulators. Measure speedup over 1-acc. |
| **Wed Sep 10** | **CALC (Strang §2.6)**: The Chain Rule: step-by-step rigorous proof using limits. Differentiating nested composite functions. | **AGNER-INST & AGNER Ch 11**: VFMADD latency/throughput port mapping on modern x86 microarchitectures. | **secan**: Implement `cosine_distance_avx2()`: compute dot product, norm $A$, and norm $B$ simultaneously in 1 pass. |
| **Thu Sep 11** | **CALC (Strang §3.1–3.2)**: Derivatives of $e^x$ and $\ln x$. | **AGNER Ch 13.1–13.3**: Alignment, cache line splits. | **secan**: `ip_avx2()` + fused cosine (dot + norms). Same unrolling as L2. *(DL: Sat Sep 13 GQA.)* |
| **Fri Sep 12** | **TRIG & CALC Integration**: Differentiating inverse trigonometric functions: $\frac{d}{dx}\arcsin x = \frac{1}{\sqrt{1-x^2}}$, $\frac{d}{dx}\arctan x = \frac{1}{1+x^2}$. | **PIKUS Ch 3**: Instruction-level parallelism, register pressure, compiler vectorization limits. | **secan**: Add AVX-512 backend (`_mm512_*`) behind `#ifdef __AVX512F__`. Benchmark scalar vs AVX2 vs AVX-512. |

> **📝 Essay 2 (Sat Sep 13)**: *"Breaking Dependency Chains: Multi-Register SIMD Kernels"*  
> **🧠 DL weekend**: MHA + GQA; Pre-LN vs Post-LN.

---

### Week 3 (Sep 15–19): Integration, Fundamental Theorem, Cache Hierarchy & Transformer Encoder

**Theme**: Definite integrals, accumulation, Fundamental Theorem of Calculus, and CPU cache hierarchy.

* **Pure Math (Strang Calc Ch 4–5)**:
  * **Riemann Sums & Definite Integrals**: $\int_a^b f(x) dx = \lim_{n \to \infty} \sum_{i=1}^n f(x_i^*) \Delta x$. Properties of integrals (linearity, additivity).
  * **Fundamental Theorem of Calculus (FTC Part 1 & 2)**: $\frac{d}{dx} \int_a^x f(t) dt = f(x)$ and $\int_a^b f(x) dx = F(b) - F(a)$.
  * **Integration Techniques**: Integration by substitution (u-substitution), Integration by parts $\int u dv = uv - \int v du$.
* **C++ Track**: Cache tiling, prefetch, **unit-sphere / IP path**, hugepages.
* **DL**: Sat Sep 20 — Pre-LN encoder.

| Day | Pure Mathematics (90 min) | Systems / C++ Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Sep 15** | **CALC (Strang §4.1–4.3)**: Riemann sums, partitions, upper and lower Darboux sums, definition of the Riemann integral. | **CSAPP §6.1–6.3**: SRAM vs DRAM, memory latency gap, spatial and temporal locality principles. | **secan**: Profile SIFT1M cache misses with `perf stat -e L1-dcache-load-misses,LLC-load-misses`. Calculate working set. |
| **Tue Sep 16** | **CALC (Strang §4.4)**: The Fundamental Theorem of Calculus Part 1 and Part 2: Rigorous proof connecting differentiation and integration. | **CSAPP §6.4–6.5**: Cache line organization, set associativity, conflict misses, cache-friendly coding. | **secan**: Implement cache-blocked `linear_scan_tiled`: partition dataset into tiles fitting in L2 cache ($256\text{KB}$). |
| **Wed Sep 17** | **CALC (Strang §5.1–5.3)**: Integration by Substitution (the reverse chain rule) and change of variables in definite integrals. | **CSAPP §6.6 & PIKUS Ch 4**: The Memory Mountain, cache hierarchy on real workloads, software prefetching. | **secan**: Add software prefetching (`_mm_prefetch`, `_MM_HINT_T0`). Tune prefetch distances ($4, 8, 16, 32$ vectors). |
| **Thu Sep 18** | **CALC (Strang §5.4–5.5)**: Integration by Parts. | **AGNER Ch 9**: Memory access, non-temporal stores. | **secan**: Unit-sphere pre-normalization path for cosine/IP. Store optional `norm` column. |
| **Fri Sep 19** | **CALC (Strang §5.6)**: Trigonometric integrals. | **FINSY Ch 6**: `madvise(MADV_HUGEPAGE)`. | **secan**: Hugepage / `madvise` warmup on dataset mmap. *(DL: Sat Sep 20 Pre-LN encoder.)* |

> **📝 Essay 3 (Sat Sep 20)**: *"Integrals, Accumulation, and the Physics of CPU Caches"*  
> **🧠 DL weekend**: Pre-LN encoder + FFN.

---

### Week 4 (Sep 22–26): Euler's Formula, IVF, MIPS & List Rebalance

**Theme**: Complex plane / Euler (math hook for weekend RoPE), **IP/MIPS IVF**, spherical k-means, inverted-list skew.

* **Pure Math**: Gelfand Ch 7 + Strang Ch 8 (unchanged).
* **C++**: Batch GEMM, **MIPS IVF** (spherical k-means), list imbalance, pinned threads.
* **DL**: Sat Sep 27 — RoPE + CausalLM + naive KV (not weekday).

| Day | Pure Mathematics (90 min) | Systems / C++ Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Sep 22** | **TRIG (Gelfand Ch 7)**: Complex plane, modulus, polar multiplication. | **PIKUS Ch 5**: Cache coherence, false sharing. | **secan**: `batch_linear_scan` $B=32/64$ (GEMV $\to$ GEMM). |
| **Tue Sep 23** | **TRIG (Gelfand Ch 7)**: Euler $e^{i\theta}$, roots of unity. | Faiss IVF coarse quantizer; **spherical k-means** for IP/MIPS. | **secan**: `IVFIndex` — L2 k-means + **spherical k-means** for IP. |
| **Wed Sep 24** | **CALC (Strang §8.1–8.3)**: Series, convergence tests. | **PIKUS Ch 6**: Thread pools. | **secan**: Multi-probe IVF; `nprobe` sweep; pinned `std::jthread`. |
| **Thu Sep 25** | **CALC (Strang §8.4–8.6)**: Taylor of $e^x$. | IVF inverted-list skew (Faiss `make_direct_map` / list size). | **secan (required)**: Histogram of IVF list sizes; **rebalance / split oversized lists**. |
| **Fri Sep 26** | **LINALG PREVIEW**: Length, angles, Cauchy-Schwarz. | IP vs L2 recall on same vectors. | **secan**: IP/MIPS search path on IVF; compare Recall@10 vs L2. Tag `v0.2-simd-ivf`. |

> **📝 Essay 4 (Sat Sep 27)**: *"From Euler's Formula to RoPE and Voronoi Cells"*  
> **🚀 Month 1 PUBLISH (Sun Sep 27)**. **🧠 DL**: RoPE + SwiGLU + CausalLM + CE + naive KV.

---
