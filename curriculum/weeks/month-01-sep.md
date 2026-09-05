# Month 1 — Sep (Weeks 1–4)

> Part of the [28-week curriculum](../README.md). Research: [`research/`](../../research/README.md).

| | |
|:---|:---|
| [← Curriculum index](../README.md) | [Month 2 — Oct →](month-02-oct.md) |

---

# BLOCK I: VECTOR SEARCH ENGINE — 4 months (Weeks 1–16 / Sep–Dec 2026)

---

# 📅 MONTH 1: Pure Trigonometry, Single-Variable Calculus, SIMD & Transformers (Sep 2026)

> **🔬 Monthly research (GAPQ Milestone 1)**: *Microarchitectural Limits of Distance Kernels & Empirical Embedding Cone Anisotropy* → publish **Sun Sep 27** · folder `research/2026-09-measurement-protocol/`

---


### 📚 Master Reference Textbooks (Month 1)
* **High-Dimensional Probability**: Roman Vershynin, *High-Dimensional Probability: An Introduction with Applications in Data Science* (CUP 2018) — Ch 1–3 (Random vectors in $\mathbb{R}^d$, spherical distributions on $\mathcal{S}^{d-1}$, sub-Gaussian variables, concentration of measure). *Foundational for GAPQ Landmark Paper 1.*
* **Computer Architecture**: John L. Hennessy & David A. Patterson, *Computer Architecture: A Quantitative Approach* (6th ed, Morgan Kaufmann 2017) — Ch 1 (Quantitative Principles, Amdahl's Law) & Ch 2 (Memory Hierarchy Design, Cache Optimizations).
* **Systems Performance**: Brendan Gregg, *Systems Performance: Enterprise and the Cloud* (2nd ed, Addison-Wesley 2020) — Ch 2 (Methodologies) & Ch 6 (CPUs, PMU Hardware Counters, `perf stat` / `perf record`).

---

### Week 1 (Sat Sep 5 – Fri Sep 11): Pure Trigonometry, Limits, Derivatives & Measurement

**Theme**: Trigonometric ratios, unit circle wrapping, derivative foundations, and scientific C++ measurement.

* **Pure Math (Gelfand Trig & Strang Calc)**:
  * **Trig (Gelfand Ch 1–3)**: Trigonometric ratios in right triangles, radian measure, the wrapping function on the unit circle $x^2 + y^2 = 1$, graphs and periodic symmetries of $\sin\theta, \cos\theta, \tan\theta$.
  * **Calculus (Strang Ch 1–2)**: Intuitive and $\epsilon$-$\delta$ definitions of limits, continuity, first-principles derivative definition $f'(x) = \lim_{h \to 0} \frac{f(x+h) - f(x)}{h}$.
* **IR Analytics**: Mathematical definitions of NDCG@K, DCG formula, Ideal DCG (IDCG), MRR, **MAP** (Mean Average Precision).
* **C++ Track**:
  * **secan**: Google Benchmark, `.fvecs` loaders, IR metrics (NDCG, MRR, **MAP**), scalar baseline. **IP kernel Thursday.**
  * **DL**: Sat Sep 6 (not weekday).

| Day | Systems Reading (05:30–06:30) | Morning Builder Track (06:30–08:30) | Night Hands-On C++/CUDA (20:30–23:00) |
|:---|:---|:---|:---|
| **Mon Sep 1** | **PIKUS Ch 2**: Performance measurements, high-res timers, profiler sampling, micro-benchmark noise floor. | **Monthly Research: Planning & Literature Synthesis** | **secan**: Integrate Google Benchmark via CMake. Add ASan/UBSan build flags. Write first benchmark for `l2_squared` with `DoNotOptimize`. |
| **Tue Sep 2** | **CSAPP §5.1–5.6**: Compiler limitations, Cycles Per Element (CPE), loop inefficiencies, memory aliasing. | **DL Track (Part 1): Architecture & Forward Pass** | **secan**: Implement binary `.fvecs`, `.bvecs`, and `.ivecs` parsers. Download SIFT1M base + ground-truth; load into `data/sift1m/`. |
| **Wed Sep 3** | **CSAPP §5.7**: Superscalar architecture, out-of-order execution, execution ports, latency vs throughput. | **DL Track (Part 2): Training, Loss & Verification** | **secan**: Build IR metrics in `tests/test_ir_metrics.cpp` (NDCG@K, MRR, **MAP**). Run exact scan on a **SIFT1M subset** (e.g. 100K base / 1K queries) first; verify Recall@10 = 1.0. Full 1M scan = stretch. |
| **Thu Sep 4** | **AGNER Ch 3 & Ch 7.1–7.3**: Bottlenecks, FP efficiency. | **Monthly Research: Sweeps & Data Logging** | **secan**: First-class **inner-product** kernel `ip()` alongside `l2_squared`. Distance enum: L2 / IP / cosine. *(DL: Sat Sep 6.)* |
| **Fri Sep 5** | **PIKUS Ch 1 & CSAPP §5.14**: Measurement-driven optimization, profiling-guided workflow with `perf stat`. | **Technical Essay: Lab-Note Drafting** | **secan**: Profile baseline scan with `perf stat`. Record IPC, cache misses, branch misses. Populate first row of README benchmark table. |

#### 📋 Daily Action Items & Optional Activities (Week 1)
* **Mon Sep 1**:
  * `[ ]` **Core**: CMake setup for Google Benchmark via `FetchContent`; implement `benchmarks/bench_distance.cpp` with `benchmark::DoNotOptimize`.
  * `⭐ Optional / Stretch`: Add a benchmark measuring the exact nanosecond cost of compiler dead-code elimination (with vs without `DoNotOptimize`).
* **Tue Sep 2**:
  * `[ ]` **Core**: Implement `.fvecs`, `.bvecs`, `.ivecs` binary loaders in `include/secan/utils/io.h` and `src/utils/io.cpp`; verify SIFT1M headers.
  * `⭐ Optional / Stretch`: Implement memory-mapped (`mmap`) zero-copy loader in addition to standard `std::ifstream` and compare load times.
* **Wed Sep 3**:
  * `[ ]` **Core**: Implement NDCG@K, MRR, and MAP in `tests/test_ir_metrics.cpp`; run exact scan on 100K SIFT subset.
  * `⭐ Optional / Stretch`: Complete exact scan over the full 1M SIFT1M dataset; verify Recall@10 = 1.000 on all 10,000 queries.
* **Thu Sep 4**:
  * `[ ]` **Core**: Implement first-class `ip()` inner product kernel in `distance.cpp`; define `enum class MetricType { L2, IP, Cosine }`.
  * `⭐ Optional / Stretch`: Implement a fast reciprocal square root (`1.0f / sqrtf(...)`) approximation for cosine normalizations.
* **Fri Sep 5**:
  * `[ ]` **Core**: Profile baseline exact scan with `perf stat -e cycles,instructions,branches,branch-misses,L1-dcache-load-misses`; record baseline IPC.
  * `⭐ Optional / Stretch`: Capture a flame graph / `perf record` trace of the exact scan loop; identify instruction-cache vs data-cache bottleneck.

#### ⛔ What NOT to Overspend Time On (Time Traps)
* ❌ **Do NOT** hand-write custom timing harnesses or CLI parsers—use Google Benchmark.
* ❌ **Do NOT** start writing AVX2/AVX-512 intrinsics—keep distance kernels in scalar C++ to establish the true unoptimized baseline.
* ❌ **Do NOT** run exact scans on all 1,000,000 vectors $\times$ 10,000 queries if scalar latency exceeds 60s—use the 100K subset for rapid iteration.
* ❌ **Do NOT** touch Deep Learning / PyTorch on weekdays—DL is strictly reserved for Saturday afternoon (14:00–18:00).

> **📝 Essay 1 (Sat Sep 6)**: *"The Geometry of High-Dimensional Retrieval: Trigonometric Projections, NDCG Ranking, and Hardware Performance Counters"*  
> **🧠 DL weekend**: `uv init transformers-pytorch`; SDPA + causal mask.

---

### Week 2 (Sat Sep 12 – Fri Sep 18): Trigonometric Identities, Chain Rule, SIMD AVX2 & Multi-Head Attention

**Theme**: Pure trigonometric identities, differentiation techniques, and instruction-level SIMD parallelism.

* **Pure Math (Gelfand Trig & Strang Calc)**:
  * **Trig (Gelfand Ch 4–5)**: Pythagorean identities ($\sin^2\theta + \cos^2\theta = 1$, $1 + \tan^2\theta = \sec^2\theta$), angle addition formulas $\cos(\alpha \pm \beta), \sin(\alpha \pm \beta)$, double-angle and half-angle formulas, product-to-sum identities.
  * **Calculus (Strang §2.6–3.2)**: The Chain Rule $\frac{d}{dx} f(g(x)) = f'(g(x)) g'(x)$, implicit differentiation, derivatives of exponential ($e^x$) and logarithmic functions ($\ln x$).
* **C++ Track**: FTZ/DAZ, AVX2 L2/cosine/**IP**, 4-way unroll, AVX-512 `#ifdef`.
* **DL**: Sat Sep 13 — MHA + GQA.

| Day | Systems Reading (05:30–06:30) | Morning Builder Track (06:30–08:30) | Night Hands-On C++/CUDA (20:30–23:00) |
|:---|:---|:---|:---|
| **Mon Sep 8** | **AGNER Ch 12**: SIMD instructions, 256-bit YMM registers, data types, intrinsics syntax. | **Monthly Research: Planning & Literature Synthesis** | **secan**: Enable FTZ/DAZ flags. Implement `l2_squared_avx2()` in `src/search/distance_avx2.cpp`. Single accumulator baseline. |
| **Tue Sep 9** | **CSAPP §5.8–5.9**: Loop unrolling, breaking dependency chains with multiple independent accumulator registers. | **DL Track (Part 1): Architecture & Forward Pass** | **secan**: Implement 4-way unrolled `l2_squared_avx2` with 4 parallel `__m256` accumulators. Measure speedup over 1-acc. |
| **Wed Sep 10** | **AGNER-INST & AGNER Ch 11**: VFMADD latency/throughput port mapping on modern x86 microarchitectures. | **DL Track (Part 2): Training, Loss & Verification** | **secan**: Implement `cosine_distance_avx2()`: compute dot product, norm $A$, and norm $B$ simultaneously in 1 pass. |
| **Thu Sep 11** | **AGNER Ch 13.1–13.3**: Alignment, cache line splits. | **Monthly Research: Sweeps & Data Logging** | **secan**: `ip_avx2()` + fused cosine (dot + norms). Same unrolling as L2. *(DL: Sat Sep 13 GQA.)* |
| **Fri Sep 12** | **PIKUS Ch 3**: Instruction-level parallelism, register pressure, compiler vectorization limits. | **Technical Essay: Lab-Note Drafting** | **secan**: Add AVX-512 backend (`_mm512_*`) behind `#ifdef __AVX512F__`. Benchmark scalar vs AVX2 vs AVX-512. |

#### 📋 Daily Action Items & Optional Activities (Week 2)
* **Mon Sep 8**:
  * `[ ]` **Core**: Enable FTZ/DAZ (`_MM_SET_FLUSH_ZERO_MODE`); implement `l2_squared_avx2()` baseline (1 `__m256` accumulator).
  * `⭐ Optional / Stretch`: Write a microbenchmark testing floating-point denormal performance penalties with FTZ disabled vs enabled.
* **Tue Sep 9**:
  * `[ ]` **Core**: Implement 4-way unrolled `l2_squared_avx2()` (4 parallel accumulators); measure IPC improvement on Google Benchmark.
  * `⭐ Optional / Stretch`: Benchmark 2-way vs 4-way vs 8-way unrolling to determine register pressure limits on your specific CPU microarchitecture.
* **Wed Sep 10**:
  * `[ ]` **Core**: Implement fused `cosine_distance_avx2()` computing dot product and norms concurrently in a single pass.
  * `⭐ Optional / Stretch`: Verify numerical precision parity between 1-pass fused cosine vs 2-pass separate norm computation on float vectors with large magnitude variance.
* **Thu Sep 11**:
  * `[ ]` **Core**: Implement `ip_avx2()` with 4-way unrolling; ensure 64-byte vector alignment (`alignas(64)`).
  * `⭐ Optional / Stretch`: Benchmark unaligned load (`_mm256_loadu_ps`) vs aligned load (`_mm256_load_ps`) across cache line boundaries.
* **Fri Sep 12**:
  * `[ ]` **Core**: Implement `#ifdef __AVX512F__` backend for 512-bit ZMM registers (`_mm512_sub_ps`, `_mm512_fmadd_ps`).
  * `⭐ Optional / Stretch`: Profile AVX-512 frequency downclocking behavior (if CPU throttles clock speed under 512-bit vector load).

#### ⛔ What NOT to Overspend Time On (Time Traps)
* ❌ **Do NOT** hand-tune assembly (`__asm__`)—intrinsic functions (`_mm256_fmadd_ps`) give the compiler full register allocator freedom and produce optimal code.
* ❌ **Do NOT** worry if AVX-512 is unsupported on your CPU—the `#ifdef __AVX512F__` macro ensures portable fallback to AVX2.
* ❌ **Do NOT** write a custom memory allocator for vector alignments—`alignas(64)` or `posix_memalign` is sufficient.

> **📝 Essay 2 (Sat Sep 13)**: *"Breaking Dependency Chains: Multi-Register SIMD Kernels"*  
> **🧠 DL weekend**: MHA + GQA; Pre-LN vs Post-LN.

---

### Week 3 (Sat Sep 19 – Fri Sep 25): Integration, Fundamental Theorem, Cache Hierarchy & Transformer Encoder

**Theme**: Definite integrals, accumulation, Fundamental Theorem of Calculus, and CPU cache hierarchy.

* **Pure Math (Strang Calc Ch 4–5)**:
  * **Riemann Sums & Definite Integrals**: $\int_a^b f(x) dx = \lim_{n \to \infty} \sum_{i=1}^n f(x_i^*) \Delta x$. Properties of integrals (linearity, additivity).
  * **Fundamental Theorem of Calculus (FTC Part 1 & 2)**: $\frac{d}{dx} \int_a^x f(t) dt = f(x)$ and $\int_a^b f(x) dx = F(b) - F(a)$.
  * **Integration Techniques**: Integration by substitution (u-substitution), Integration by parts $\int u dv = uv - \int v du$.
* **C++ Track**: Cache tiling, prefetch, **unit-sphere / IP path**, hugepages.
* **DL**: Sat Sep 20 — Pre-LN encoder.

| Day | Systems Reading (05:30–06:30) | Morning Builder Track (06:30–08:30) | Night Hands-On C++/CUDA (20:30–23:00) |
|:---|:---|:---|:---|
| **Mon Sep 15** | **CSAPP §6.1–6.3**: SRAM vs DRAM, memory latency gap, spatial and temporal locality principles. | **Monthly Research: Planning & Literature Synthesis** | **secan**: Profile SIFT1M cache misses with `perf stat -e L1-dcache-load-misses,LLC-load-misses`. Calculate working set. |
| **Tue Sep 16** | **CSAPP §6.4–6.5**: Cache line organization, set associativity, conflict misses, cache-friendly coding. | **DL Track (Part 1): Architecture & Forward Pass** | **secan**: Implement cache-blocked `linear_scan_tiled`: partition dataset into tiles fitting in L2 cache ($256\text{KB}$). |
| **Wed Sep 17** | **CSAPP §6.6 & PIKUS Ch 4**: The Memory Mountain, cache hierarchy on real workloads, software prefetching. | **DL Track (Part 2): Training, Loss & Verification** | **secan**: Add software prefetching (`_mm_prefetch`, `_MM_HINT_T0`). Tune prefetch distances ($4, 8, 16, 32$ vectors). |
| **Thu Sep 18** | **AGNER Ch 9**: Memory access, non-temporal stores. | **Monthly Research: Sweeps & Data Logging** | **secan**: Unit-sphere pre-normalization path for cosine/IP. Store optional `norm` column. |
| **Fri Sep 19** | **FINSY Ch 6**: `madvise(MADV_HUGEPAGE)`. | **Technical Essay: Lab-Note Drafting** | **secan**: Hugepage / `madvise` warmup on dataset mmap. *(DL: Sat Sep 20 Pre-LN encoder.)* |

#### 📋 Daily Action Items & Optional Activities (Week 3)
* **Mon Sep 15**:
  * `[ ]` **Core**: Profile SIFT1M cache miss rates with `perf stat`; compute working set size for $10^5$ and $10^6$ vectors.
  * `⭐ Optional / Stretch`: Write a tiny benchmark that measures the cache memory mountain (bandwidth vs stride size from 4KB to 64MB).
* **Tue Sep 16**:
  * `[ ]` **Core**: Implement `linear_scan_tiled()` partitioning vector database into L2-cache tiles ($256\text{KB}$).
  * `⭐ Optional / Stretch`: Experiment with multi-level cache tiling (L1 tile inside L2 tile) for multi-query batches.
* **Wed Sep 17**:
  * `[ ]` **Core**: Insert `_mm_prefetch` instructions in linear scan loop; benchmark prefetch lookahead distance $K \in \{4, 8, 16, 32\}$.
  * `⭐ Optional / Stretch`: Test non-temporal prefetch hints (`_MM_HINT_NTA`) vs temporal (`_MM_HINT_T0`) on datasets that exceed L3 cache.
* **Thu Sep 18**:
  * `[ ]` **Core**: Implement offline unit-sphere pre-normalization for cosine distance so queries reduce to pure inner product `ip()`.
  * `⭐ Optional / Stretch`: Implement in-place SIMD normalization kernel using `_mm256_div_ps` and compare throughput.
* **Fri Sep 19**:
  * `[ ]` **Core**: Add `madvise(MADV_HUGEPAGE)` and transparent hugepage allocation on dataset mmap buffer.
  * `⭐ Optional / Stretch`: Measure TLB page fault overhead via `perf stat -e dTLB-load-misses` before and after hugepages.

#### ⛔ What NOT to Overspend Time On (Time Traps)
* ❌ **Do NOT** spend hours over-tuning prefetch distances—test 4 discrete distances ($4, 8, 16, 32$) and select the best median.
* ❌ **Do NOT** implement complex custom thread pools for tiled scans yet—single-threaded cache tiling establishes the baseline.
* ❌ **Do NOT** solve advanced trigonometric integrals with multiple integration-by-parts iterations on paper—grasp the reduction formula concept and stop.

> **📝 Essay 3 (Sat Sep 20)**: *"Integrals, Accumulation, and the Physics of CPU Caches"*  
> **🧠 DL weekend**: **Micrograd autograd engine** (~150 lines): `Value` class with `+`, `*`, `tanh`, `exp`, `backward()` using topological sort. Verify gradient of a tiny 2-layer MLP matches PyTorch. **Then** implement Pre-LN encoder + FFN with manual `backward()` for `Linear` layer (compare `dW` vs `param.grad`).

---

### Week 4 (Sat Sep 26 – Fri Oct 2): Euler's Formula, IVF, MIPS & List Rebalance

**Theme**: Complex plane / Euler (math hook for weekend RoPE), **IP/MIPS IVF**, spherical k-means, inverted-list skew.

* **Pure Math**: Gelfand Ch 7 + Strang Ch 8 (unchanged).
* **C++**: Batch GEMM, **MIPS IVF** (spherical k-means), list imbalance, pinned threads.
* **DL**: Sat Sep 27 — RoPE + CausalLM + naive KV (not weekday).

| Day | Systems Reading (05:30–06:30) | Morning Builder Track (06:30–08:30) | Night Hands-On C++/CUDA (20:30–23:00) |
|:---|:---|:---|:---|
| **Mon Sep 22** | **PIKUS Ch 5**: Cache coherence, false sharing. | **Monthly Research: Planning & Literature Synthesis** | **secan**: `batch_linear_scan` $B=32/64$ (GEMV $\to$ GEMM). |
| **Tue Sep 23** | Faiss IVF coarse quantizer; **spherical k-means** for IP/MIPS. | **DL Track (Part 1): Architecture & Forward Pass** | **secan**: `IVFIndex` — L2 k-means + **spherical k-means** for IP. |
| **Wed Sep 24** | **PIKUS Ch 6**: Thread pools. | **DL Track (Part 2): Training, Loss & Verification** | **secan**: Multi-probe IVF; `nprobe` sweep; pinned `std::jthread`. |
| **Thu Sep 25** | IVF inverted-list skew (Faiss `make_direct_map` / list size). | **Monthly Research: Sweeps & Data Logging** | **secan (required)**: Histogram of IVF list sizes; **rebalance / split oversized lists**. |
| **Fri Sep 26** | IP vs L2 recall on same vectors. | **Technical Essay: Lab-Note Drafting** | **secan**: IP/MIPS search path on IVF; compare Recall@10 vs L2. Tag `v0.2-simd-ivf`. |

#### 📋 Daily Action Items & Optional Activities (Week 4)
* **Mon Sep 22**:
  * `[ ]` **Core**: Implement `batch_linear_scan()` for $B=32/64$ queries, transforming single-query GEMV into cached batch GEMM.
  * `⭐ Optional / Stretch`: Implement cache-blocked matrix transpose to evaluate column-major vs row-major dataset layouts for batch scans.
* **Tue Sep 23**:
  * `[ ]` **Core**: Implement `IVFIndex` class with coarse centroids trained via $k$-means; add spherical $k$-means for Inner Product (IP).
  * `⭐ Optional / Stretch`: Implement $k$-means++ centroid initialization heuristic to speed up coarse quantizer convergence.
* **Wed Sep 24**:
  * `[ ]` **Core**: Implement multi-probe IVF query scanner with `nprobe` parameter sweep; parallelize across queries with `std::jthread`.
  * `⭐ Optional / Stretch`: Pin worker threads to physical CPU cores with `pthread_setaffinity_np` and measure latency jitter reduction.
* **Thu Sep 25**:
  * `[ ]` **Core**: Build histogram of inverted-list sizes; implement list rebalancing (splitting clusters larger than $2\times$ median size).
  * `⭐ Optional / Stretch`: Analyze the relationship between cluster size variance and tail query latency ($p99$).
* **Fri Sep 26**:
  * `[ ]` **Core**: Validate Inner Product (IP) search path on IVF index; plot Recall@10 vs `nprobe` for L2 and IP on SIFT1M. Tag `v0.2-simd-ivf`.
  * `⭐ Optional / Stretch`: Compute exact Voronoi cell boundary distances to identify boundary query misclassification rates.

#### ⛔ What NOT to Overspend Time On (Time Traps)
* ❌ **Do NOT** run $k$-means for 100 iterations—10 to 15 Lloyd iterations are more than enough to stabilize coarse centroids.
* ❌ **Do NOT** implement Product Quantization (PQ) inside IVF lists yet—Month 1 is strictly IVFFlat (PQ is built in Month 2).
* ❌ **Do NOT** try to implement GPU kernels this week—GPU is scheduled for Month 4 (Weeks 13–16).

> **📝 Essay 4 (Sat Sep 27)**: *"From Euler's Formula to RoPE and Voronoi Cells"*  
> **🚀 Month 1 PUBLISH (Sun Sep 27)**. **🧠 DL**: RoPE + SwiGLU + CausalLM + CE + naive KV. **Also**: implement `SGD` optimizer from scratch (momentum $v_t = \beta v_{t-1} + \nabla\mathcal{L}$, $\theta_t = \theta_{t-1} - \alpha v_t$); train CausalLM with your SGD, verify loss matches `torch.optim.SGD`.

---
