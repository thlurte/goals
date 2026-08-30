# Vector Search Engine & AI Systems: 28-Week Master Curriculum (7 Months)

**Start Date**: Monday, September 1, 2026  
**End Date**: Friday, March 12, 2027  
**Schedule**: 5 Days/Week (Mon–Fri) **`secan` only**. Weekends: **lab notes + one DL afternoon + monthly research**.  

### 🗓️ Two-Block Arc (7 calendar months)

| Block | Weeks | Calendar | Primary deliverable |
|:---|:---|:---|:---|
| **I — Vector Search Engine** | **1–16** | **Sep–Dec 2026 (4 months)** | `secan` composed ANN + **ONNX/`limbed` encode→index**: SIMD, IVF-PQ, HNSW-SQ, ColBERT/PLAID/MUVERA, LSM, GPU IVF, Vamana+DiskANN, RRF/WAND |
| **II — GPU specialization** | **17–28** | **Jan–Mar 2027 (3 months)** | CUDA graphs, FA-2, PagedAttention/TurboQuant, multi-GPU, ColPali, NEON, `v2.0` |

**Deep learning is a slow path across all 7 months**, not a third block. **Weekdays = `secan` only.** DL is **one Saturday afternoon** (14:00–18:00), not a weekday. REST API is **out of scope**.

### 🔬 Monthly Research Program (weekend build → month-end publish)

Full detail: [`research/README.md`](research/README.md). Seven monthlies (not six).

| Month | Research topic | Publish deadline |
|:---|:---|:---|
| **Sep** | Measurement-first distance microbenchmarks | **Sun Sep 27** |
| **Oct** | Anisotropy / hubness / SQ–PQ–FastScan–ScaNN **+ OPQ / asymmetric PQ** | **Sun Oct 25** |
| **Nov** | Late interaction: PLAID vs **MUVERA** FDE→MIPS under LSM writes | **Sun Nov 29** |
| **Dec** | GPU IVF + DiskANN `io_uring` + hybrid WAND **+ RRF** | **Sun Dec 27** |
| **Jan** | PagedAttention × TurboQuant — paging vs quantizing KV | **Sun Jan 31** |
| **Feb** | ACORN **+ pre/post/range filters** + tombstones + portable SIMD | **Sun Feb 28** |
| **Mar** | GPU specialization closeout: FA-2, multi-GPU, serving | **Fri Mar 12** (`v2.0`) |

**Weekend rhythm**:
1. **Sat 09:00–13:00** — weekly essay / lab note  
2. **Sat 14:00–18:00** — **DL weekly** (the one Python day)  
3. **Sun 09:00–13:00** — monthly research experiments / draft  
4. **Last weekend** — publish monthly paper  

**Daily Cadence** (Mon–Fri):
1. **🌅 06:00 – 07:30 (90 min) — Morning Pure Mathematics**
2. **📖 07:30 – 08:30 (60 min) — Systems & Architecture Deep Reading**
3. **💻 20:30 – 23:00 (2.5 hrs) — Night `secan` / CUDA only** (no weekday DL)

**Pacing rules**:
* Weekday night = **`secan` only**. DL does not steal VS days.
* Tiny-corpus training = **Saturday afternoon**.
* **No REST API** in `secan` (nanobind + CLI only). Distributed CPU cluster = stretch, not required.

### ✅ Entry Prerequisites
See [README.md](README.md#entry-prerequisites-before-sep-1). Minimum: AVX2 CPU, CUDA GPU by Week 13, SIFT1M before Wed Sep 3, **`limbed` + `ggmbed` installable by Week 8**, **768-D / multi-vector dumps by Week 8–9 Fri**, **NVMe by Week 16**, `perf` + CMake + `uv`.

### 📦 Deferred-work ledger (slimmed → hard landing)

Nothing slimmed is optional. Every row is **required** on the landing week.

| Slimmed from | What was cut | **Hard landing (required)** | Why there |
|:---|:---|:---|:---|
| **Week 8** | HNSW bounded flat heap + bitset visited | **Week 12 Wed** | Before composed-index Pareto |
| **Week 10** | BM25 + Block-Max WAND + **RRF** | **Week 16 Fri** | Hybrid IR; not only linear $\alpha$ |
| **Week 11** | DiskANN `io_uring` + **Vamana prune** | **Week 16 Thu** | Graph construction, not only SSD fetch |
| **Week 15** | FlashAttention-2 | **Week 25** | GPU block |
| **Week 7→10** | RaBitQ (after QR) | **Week 10 Thu** | Already required |
| **Week 8→12** | Whitening / query-side PCA | **Week 12 Mon** | After SVD |
| *(frontier)* | ACORN + tombstones + NUMA + **pre/post/range** | **Week 22** | On-call filters |

### 🧩 VS composition landings (the specialty)

REST out of scope. Cluster shard/replica = stretch only.

| Need | Lands (required) |
|:---|:---|
| **IP/MIPS + spherical k-means IVF** + list-size histogram / rebalance | **Week 4 Thu–Fri** |
| **Asymmetric PQ/BQ** (FP32 query vs quantized db) + **OPQ / residual PQ** | **Week 6 Fri + Week 7 Fri** |
| **768-D text Recall@10 vs QPS** via **production encode** (`ggmbed` or dense ONNX → `.fvecs`), not SIFT-only | **Week 8 Fri** |
| **Batch HNSW / graph build** | **Week 9 Mon–Tue** |
| **ONNX ColBERT (`limbed`) → `MultiVectorIndex`** (encode→index handoff; ORT stays in limbed) | **Week 9 Fri** |
| **MUVERA FDE** (asymmetric) → IP MIPS → MaxSim re-rank vs PLAID | **Week 10 Mon–Wed** |
| **TurboQuant 1@k** vs RaBitQ/PQ (GloVe or 768-D) | **Week 10 Fri** |
| **`IVFPQIndex` + `HNSWSQIndex`**; Pareto vs Faiss/hnswlib on **SIFT + 768-D** | **Week 12 Thu–Fri** |
| **Vamana prune** + compressed RAM + `io_uring` raw | **Week 16 Thu** |
| **RRF** + linear $\alpha$ (SPLADE stretch) | **Week 16 Fri** |
| **Pre- vs post-filter vs ACORN**; **range**; selectivity vs recall | **Week 22 Mon + Fri** |
| BEIR / MS MARCO **slice** (dense + ColBERT + **MUVERA**) | **Month 3 research Sunday** |
| REST API | **Skip** |

**ONNX on the VS timeline:** required Weeks **8–9** as *encode → secan ingest*. Runtime stays **`limbed` / export scripts** — `secan` never links ORT. The 30-min Intextus track only *maintains* those packages; it does not replace these Fridays. See [`intextus_30min_six_month.md`](intextus_30min_six_month.md).

### 🧠 DL weekend landings (Sat 14:00–18:00 only)

| Weekend after | DL work |
|:---|:---|
| **W1 Sat Sep 6** | SDPA + causal mask (`uv init transformers-pytorch`) |
| **W2 Sat Sep 13** | MHA + **GQA**; Pre-LN vs Post-LN |
| **W3 Sat Sep 20** | Pre-LN encoder + FFN |
| **W4 Sat Sep 27** | **RoPE + SwiGLU + CausalLM + CE + naive KV** (after Month 1 paper) |
| **W5 Sat Oct 4** | ViT patch embed + `[CLS]` |
| **W6 Sat Oct 11** | BERT + **InfoNCE**; export 768-D `.fvecs` for Week 8 Fri |
| **W7 Sat Oct 18** | MRL tiny-corpus |
| **W8 Sat Oct 25** | *Month 2 publish* — no extra DL |
| **W9 Sat Nov 1** | ColBERT + MaxSim + tiny Margin MSE |
| **W15 Sat Dec 13** | Online softmax (FA-1 math) |
| **W21 Sat Jan 24** | CLIP projector + ColPali head |
| Other Saturdays | Research / overflow only |

---

---

## 🏛️ The Three Synchronized Pillars

```
 ┌──────────────────────────────────────────────────────────────────────────────────────────────────┐
 │                               PILLAR 1: PURE MATHEMATICS (90 MIN/DAY)                            │
 │ • Month 1 (Sep): Pure Trigonometry (Gelfand) & Single-Variable Calculus (Strang/Stewart)        │
 │ • Month 2 (Oct): Multivariable & Vector Calculus (Gradients, Jacobians, Hessians, Integrals)     │
 │ • Month 3 (Nov): Linear Algebra from First Principles (Gilbert Strang 4th Edition)               │
 │ • Month 4 (Dec): Pure Probability Theory (Axioms, Distributions, Expectation, MGFs)              │
 │ • Month 5 (Jan): Limit Theorems, Stats, Markov Chains (GPU graphs)                               │
 │ • Month 6 (Feb): Convex opt, Spectral graphs, production filters                                │
 │ • Month 7 (Mar): GPU specialization synthesis (FA-2, multi-GPU, serving)                         │
 └────────────────────────┬─────────────────────────────────────────┬───────────────────────────────┘
                          │                                         │
                          ▼                                         ▼
 ┌────────────────────────────────────────┐     ┌───────────────────────────────────────────────────┐
 │   PILLAR 2: DEEP LEARNING (Py)         │     │  PILLAR 3: DATABASE & C++/GPU ENGINE (secan)       │
 │ • Pre-LN decoder-only: RoPE, GQA, KV   │────►│ • SIMD, quant, HNSW, IVF, DiskANN, LSM, WAND      │
 │ • Dense InfoNCE retriever (DPR/E5)     │     │ • ColBERT MaxSim / PLAID; GPU IVF + CAGRA         │
 │ • ViT, BERT, ColBERT, CLIP→ColPali     │     │ • FlashAttention, PagedAttention, nanobind        │
 └────────────────────────────────────────┘     └───────────────────────────────────────────────────┘
```

---

## 📚 Complete Literature Stack

### 1. Pure Mathematics Literature
* **TRIG**: *Trigonometry* — I.M. Gelfand & Mark Saul (`/home/ahmed/Downloads/Trigonometry -- Gelʹfand, I_ M_ ...pdf`)
* **CALC**: *Calculus* — Gilbert Strang (MIT OpenCourseWare free textbook) or *Calculus: Early Transcendentals* — James Stewart
* **LINALG**: *Linear Algebra and Its Applications* (4th Edition) — Gilbert Strang (`/home/ahmed/Downloads/Linear Algebra and Its Applications, 4th Edition (Gilbert Strang) (Z-Library).pdf`)
* **PROB**: *Introduction to Probability* — Joseph K. Blitzstein & Jessica Hwang (Harvard Stat 110) or *Introduction to Probability* — Bertsekas & Tsitsiklis (MIT)
* **CONVEX**: *Convex Optimization* — Boyd & Vandenberghe (free PDF) — Month 6
* **INFO**: *Elements of Information Theory* — Cover & Thomas (selected chapters) or MacKay *Information Theory* — Month 5–6
* **SPECTRAL**: Fan Chung *Spectral Graph Theory* or Spielman lecture notes — Week 23

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
* **ACORN**: *"ACORN: Performant and Predicate-Agnostic Search Over Vector Embeddings"* (Patel et al. 2024) — implemented Week 22
* **RABITQ**: RaBitQ paper (2024) — implemented Week 10 (after QR), not Week 7
* **TURBOQUANT**: [TurboQuant / PolarQuant / QJL](https://research.google/blog/turboquant-redefining-ai-efficiency-with-extreme-compression/) (Google Research, ICLR/AISTATS 2026) — Week 10 (vector search vs RaBitQ) + Week 19 (KV-cache compression with PagedAttention)

---

# BLOCK I: VECTOR SEARCH ENGINE — 4 months (Weeks 1–16 / Sep–Dec 2026)

---

# 📅 MONTH 1: Pure Trigonometry, Single-Variable Calculus, SIMD & Transformers (Sep 2026)

> **🔬 Monthly research**: *Measurement Before Optimization: A Reproducible Protocol for Vector Distance Microbenchmarks* → publish **Sun Sep 27** · folder `research/2026-09-measurement-protocol/`

---

### Week 1 (Sep 1–5): Pure Trigonometry, Limits, Derivatives & Measurement

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

# 📅 MONTH 2: Multivariable Calculus, Vector Fields, Vision Transformers & HNSW (Oct 2026)

> **🔬 Monthly research**: *Anisotropy, Hubness, and Bits: SQ / PQ / FastScan / ScaNN **+ OPQ / asymmetric distance*** → publish **Sun Oct 25** · folder `research/2026-10-anisotropy-hubness-bits/`

---

### Week 5 (Sep 29 – Oct 3): Partial Derivatives, Gradients, Hessians & Vision Transformer (ViT)

**Theme**: Multivariable functions, gradient vectors, Hessian matrices, and Vision Transformers from scratch.

* **Pure Math (Strang Calc Ch 13)**:
  * Functions of several variables $f(x, y, z)$, level curves and contour maps.
  * Partial derivatives $\frac{\partial f}{\partial x}, \frac{\partial f}{\partial y}$, Clairaut's Theorem (equality of mixed partials $\frac{\partial^2 f}{\partial x \partial y} = \frac{\partial^2 f}{\partial y \partial x}$).
  * The Gradient vector $\nabla f = \left( \frac{\partial f}{\partial x_1}, \dots, \frac{\partial f}{\partial x_n} \right)$, directional derivatives $D_{\mathbf{u}} f = \nabla f \cdot \mathbf{u}$.
  * The Hessian matrix $H[i, j] = \frac{\partial^2 f}{\partial x_i \partial x_j}$, Second Derivative Test for multivariable extrema.
* **C++ Track**: `ScalarQuantizer`, SQ8/SQ4 integer AVX2, 2-stage re-ranker.
* **DL**: Sat Oct 4 — ViT `PatchEmbedding` + `[CLS]`.

| Day | Pure Mathematics (90 min) | Systems / C++ Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Sep 29** | **CALC §13.1–13.3** + **LINALG §1.3**: Functions of several variables; reinforce dot product / projection as $\mathrm{proj}_u v = \frac{v\cdot u}{u\cdot u}u$ (needed for quantization geometry). | **AGNER Ch 7.2 & CSAPP §2.2–2.3**: Integer arithmetic efficiency, two's complement, overflow, bit-width conversion. | **secan**: Implement `ScalarQuantizer` with **percentile clipping (0.05th/99.95th)** to handle outlier dimensions. Verify dequantization error. |
| **Tue Sep 30** | **CALC §13.4**: Tangent planes and linear approximations: $L(x, y) = f(a, b) + f_x(a, b)(x-a) + f_y(a, b)(y-b)$. Total differentials. | **INTEL Intrinsics Guide**: Study `_mm256_maddubs_epi16`, `_mm256_madd_epi16`, `_mm256_dpbusd_epi32` (VNNI dot product). | **secan**: Implement `l2_squared_sq8()` using AVX2 integer intrinsics. Process 32 dimensions per iteration in a single `__m256i`. |
| **Wed Oct 1** | **CALC §13.5**: The Multivariable Chain Rule for paths and surfaces. Tree diagrams for composite multivariable functions. | **AGNER Ch 12**: Integer SIMD saturation arithmetic, signed vs unsigned byte multiplication, widening instructions. | **secan**: SQ8 LUT / packed layout polish; SIMD path vs scalar dequant error check. |
| **Thu Oct 2** | **CALC §13.6**: Directional derivatives and the Gradient vector $\nabla f$. Proving that $\nabla f$ points in the direction of maximum rate of increase. | **CSAPP §2.4**: Floating-point representation, rounding error bounds, precision loss in quantization. | **secan**: Implement 4-bit scalar quantization (`SQ4`): pack 2 dimensions per byte with nibble masking. Build 2-stage SQ8 $\to$ FP32 re-ranker. |
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
> **🧠 DL weekend**: BERT + InfoNCE; export 768-D `.fvecs`.

---

### Week 7 (Oct 13–17): Vector Fields, Line Integrals, ScaNN Anisotropic Loss & FastScan

**Theme**: Vector calculus, directional error weighting (ScaNN), and in-register FastScan lookups.

* **Pure Math (Strang Calc Ch 15)**:
  * Vector fields $\mathbf{F}(x, y, z) = P\mathbf{i} + Q\mathbf{j} + R\mathbf{k}$, gradient fields, conservative vector fields.
  * Line integrals of scalar functions and vector fields $\int_C \mathbf{F} \cdot d\mathbf{r} = \int_a^b \mathbf{F}(\mathbf{r}(t)) \cdot \mathbf{r}'(t) dt$.
  * Fundamental Theorem for Line Integrals: $\int_C \nabla f \cdot d\mathbf{r} = f(\mathbf{r}(b)) - f(\mathbf{r}(a))$ (path independence).
  * Green's Theorem in the plane: $\oint_C (P dx + Q dy) = \iint_D \left(\frac{\partial Q}{\partial x} - \frac{\partial P}{\partial y}\right) dA$.
* **ScaNN Theory**: Directional error decomposition: parallel error $e_\parallel$ vs orthogonal error $e_\perp$; ScaNN anisotropic loss $\mathcal{L} = h \|e_\parallel\|^2 + \|e_\perp\|^2$.
* **C++ Track**: ScaNN anisotropic PQ, BQ, FastScan, **OPQ / residual PQ**.
* **DL**: Sat Oct 18 — MRL tiny-corpus.

| Day | Pure Mathematics & ScaNN Math (90 min) | Systems / C++ Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Oct 13** | **CALC §15.1–15.2**: Vector fields in 2D/3D. Line integrals of vector fields along parameterized curves $\mathbf{r}(t)$. Work done by a force field. | ScaNN Paper §1–3: MIPS error decomposition: why orthogonal error $e_\perp$ has 0 expectation while parallel error $e_\parallel$ degrades inner products. | **secan**: Implement **ScaNN Anisotropic Loss** in `ProductQuantizer`: penalize parallel error with weight $h=5.0$. Compare codebooks. |
| **Tue Oct 14** | **CALC §15.3**: Conservative vector fields, potential functions $f$, and path independence of line integrals. Conditions for a field to be conservative. | **INTEL Intrinsics & AGNER-INST**: Deep dive into `_mm256_shuffle_epi8` (PSHUFB) semantics and port mapping. | **secan**: Implement **plain BQ** (`bit = val > 0`): Hamming via XOR+POPCNT. **Do not** implement RaBitQ yet (needs QR — Week 10). |
| **Wed Oct 15** | **CALC §15.4**: Green's Theorem: rigorous proof connecting a line integral around a closed curve to a double integral over the enclosed region. | Faiss FastScan documentation & André et al. (2015) paper §1–3. | **secan**: Implement 4-bit PQ encoding ($k=16$ centroids per subspace, packing 2 codes per byte). |
| **Thu Oct 16** | **CALC §15.5**: Curl and Divergence of vector fields: $\text{curl } \mathbf{F} = \nabla \times \mathbf{F}$ (circulation), $\text{div } \mathbf{F} = \nabla \cdot \mathbf{F}$ (flux density). Physical interpretations. | AGNER-INST: Study `VPSHUFB`, `VPADDB`, `VPUNPCKLBW` instruction latency and accumulation chains. | **secan**: Implement **FastScan kernel**: load 16 centroid distances into `__m128i` / `__m256i`. Execute table lookups **entirely in-register** via PSHUFB. |
| **Fri Oct 17** | **LINALG PREVIEW (Strang §2.1–2.2)**: Vector spaces, subspaces, column space $C(A)$, nullspace $N(A)$ — warm-up for Month 3. Skip Stokes/Divergence deep dive (optional weekend). | **CSAPP §5.10–5.12**: Register spilling, store-load forwarding, pipeline limiting factors. | **secan (required)**: **OPQ** (rotate then PQ) *or* **residual PQ**. Compare Recall@10 vs plain PQ on SIFT. Asymmetric ADC remains FP32 query. *(DL: Sat Oct 18 MRL.)* |

> **📝 Essay 7 (Sat Oct 18)**: *"Google ScaNN Anisotropic Loss, Vector Fields, and In-Register SIMD FastScan"*  
> **🧠 DL weekend**: MRL nested dims on tiny corpus.

---

### Week 8 (Oct 20–24): Graph Theory, The Hubness Phenomenon & HNSW Core

**Theme**: Small-world networks, hubness in high-D spaces, and a **correct** HNSW (optimize later).

* **Pure Math (Graph Theory & High-D Analytics)**:
  * Graph representations: adjacency matrices, Graph Laplacian $L = D - A$.
  * Algebraic connectivity (Fiedler vector) — intuition only; proofs deferred to Week 23.
  * **The Hubness Phenomenon**: Skewness of $k$-occurrences ($S_{N_k}$), measure concentration. **Whitening formula stated**; implement transform in Week 12 after SVD.
* **C++ Track**: HNSW core. **Fri required: production text encode → HNSW** (`ggmbed` or dense ONNX `.fvecs`; InfoNCE export OK as secondary). Not SIFT-only.
  * **Deferred (required Week 12 Wed)**: bounded flat heap + bitset visited.
  * **ONNX ColBERT (`limbed`) → Week 9 Fri.**

| Day | Pure Mathematics & Hubness Analytics (90 min) | Systems / C++ Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Oct 20** | **GRAPH THEORY**: Graphs and Networks: Incidence matrix $A$, Graph Laplacian $L = D - W$. | Research paper: *"Efficient and Robust ANN Search Using HNSW Graphs"* (Malkov & Yashunin 2020) §1–3. | **secan**: Implement `HNSWIndex` data structures: flat CSR adjacency (`neighbors[]` + `offsets[]`), node struct, entry point. |
| **Tue Oct 21** | **HUBNESS ANALYTICS**: Skewness of $k$-occurrences $S_{N_k}$. Why high hubness degrades graph routing. Whitening $x_{\text{white}} = \Lambda^{-1/2} Q^T (x - \mu)$ as **formula only** (implement Week 12 Mon). | HNSW paper §4–5: Algorithm 4 (heuristic neighbor selection), level multiplier $m_L$, parameter tuning ($M, ef$). | **secan**: Implement HNSW `insert()`: exponential level assignment, greedy descent, multi-layer neighbor connection. |
| **Wed Oct 22** | **SPECTRAL INTUITION**: Fiedler vector / algebraic connectivity — geometric meaning for bottlenecks (proofs → Week 23). | **PIKUS Ch 7**: Concurrent data structures, cache-friendly priority queues, memory allocation in graphs. | **secan**: Implement HNSW `search()`: beam search with visited-set. Implement Algorithm 4 diverse neighbor selection. |
| **Thu Oct 23** | **GRAPH EMBEDDINGS**: Shortest path distance vs Euclidean embedding distance. Small-world clustering coefficient $C$ and path length $L$. | **AGNER Ch 7.12–7.13 & Ch 7.5**: Branch prediction in graph traversal, branchless heap sift-down (**prep for Week 12 Wed**). | **secan**: Correctness harness: Recall@10 vs exact on SIFT subset. Do **not** optimize heaps yet → Week 12 Wed. |
| **Fri Oct 24** | **PURE MATH REVIEW**: Multivariable Calculus highlights (gradient, Hessian, Lagrange). | **CSAPP §5.14**: Profiling graph traversal; skim `ggmbed` / dense ONNX → `.fvecs` glue. | **secan (required)**: Encode a text slice with **`ggmbed` (or dense ONNX)** → `.fvecs` → HNSW; plot **Recall@10 vs QPS**. Tag `v0.3-hnsw`. |

> **📝 Essay 8 (Sat Oct 25)**: *"Building HNSW from Scratch: Graph Laplacians, The Hubness Phenomenon, and Sub-Millisecond Search"*  
> **🚀 Month 2 research PUBLISH (Sun Oct 25)**: freeze `research/2026-10-anisotropy-hubness-bits/paper.md` + public post.

---

# 📅 MONTH 3: Linear Algebra from First Principles, ColBERT & LSM-Trees (Nov 2026)

> **🔬 Monthly research**: *Late Interaction Under Writes: PLAID vs MUVERA FDE→MIPS Inside an LSM Vector Engine* (+ **BEIR/MS MARCO slice**) → publish **Sun Nov 29** · folder `research/2026-11-late-interaction-lsm/`

---

### Week 9 (Oct 27–31): Vector Spaces, Four Fundamental Subspaces, ColBERT & SIMD MaxSim

**Theme**: Rigorous linear algebra (Strang Ch 1–2), ColBERT dual-encoder architecture, and SIMD MaxSim.

* **Pure Math (Gilbert Strang Linear Algebra Ch 1–2)**:
  * Linear combinations, dot products, length and angles in $\mathbb{R}^n$, matrix elimination, triangular factorizations $A = LU$.
  * Vector spaces and subspaces, the Nullspace $N(A)$, the Column space $C(A)$, linear independence, basis, dimension.
  * The Four Fundamental Subspaces and the Fundamental Theorem of Linear Algebra ($r = \text{rank}(A)$).
* **C++ Track**: **Batch HNSW build** Mon–Tue; SIMD MaxSim Wed–Thu; **Fri: `limbed` ONNX → MultiVectorIndex** (VS ONNX landing). ColBERT train = Sat Nov 1.

| Day | Pure Mathematics (Strang) (90 min) | Systems / C++ Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Oct 27** | **STRANG §1.1–1.6**: Vector geometry, matrix multiplication from 4 perspectives, Gaussian elimination, $LU$ factorization. | Research paper: *"ColBERT: Efficient and Effective Passage Search via Late Interaction"* (Khattab & Zaharia 2020). | **secan (required)**: **Batch HNSW build**: insert $N$ in one pass (level assignment + sequential connect). Compare build time vs one-by-one insert. |
| **Tue Oct 28** | **STRANG §2.1–2.2**: Vector spaces, column space $C(A)$, nullspace $N(A)$. | PLAID paper §1–4; HNSW bulk-construction notes. | **secan**: Parallel batch graph construction (shard-then-merge or lock-free insert). Measure Recall@10 vs sequential insert. |
| **Wed Oct 29** | **STRANG §2.3–2.4**: Linear independence, spanning sets, basis, dimension of vector spaces. Computing rank from echelon form. | **INTEL Intrinsics Guide**: Study `_mm256_max_ps`, `_mm256_permute2f128_ps`, cross-lane max reduction. | **secan**: Implement **SIMD-vectorized MaxSim kernel** in C++: process 8 document tokens in parallel with AVX2 FMA + horizontal max reduction. |
| **Thu Oct 30** | **STRANG §2.5–2.6**: The Four Fundamental Subspaces ($C(A), N(A), C(A^T), N(A^T)$). The Fundamental Theorem of Linear Algebra (Part 1). | **AGNER Ch 13**: Data parallelism, cache layout for multi-vector matrices. | **secan**: Build **token centroid index**: cluster document tokens into centroids ($C=32\text{K}$). Build inverted lists `centroid_id → (doc_id, token_idx)`. Centroid prune path ready for Fri’s limbed dump. |
| **Fri Oct 31** | **STRANG §2.6**: Matrix rank and dimensions of the 4 subspaces: $\dim C(A) = \dim C(A^T) = r$, $\dim N(A) = n - r$, $\dim N(A^T) = m - r$. | `limbed` README: ONNX ColBERT layout (`model.onnx` + `tokenizer.json`). | **secan (required)**: **`limbed` ONNX encode** → token matrices → `MultiVectorIndex` + SIMD MaxSim. Centroid prune on same dump. This is the VS **ONNX** handoff (ORT stays in limbed). |

> **📝 Essay 9 (Sat Nov 1)**: *"Beyond Single Vectors: The Linear Algebra and SIMD Architecture of ColBERT Late Interaction"*  
> **🧠 DL weekend**: ColBERT dual encoder + MaxSim + tiny Margin MSE.  
> **🔬 Month 3 Sundays**: BEIR or MS MARCO **slice** (dense + ColBERT MaxSim + **MUVERA** FDE candidates).

---

### Week 10 (Nov 3–7): Orthogonality, MUVERA FDEs, PLAID, RaBitQ & TurboQuant

**Theme**: Projections / $A=QR$; **MUVERA** reduces MaxSim to IP MIPS; PLAID is the cascade alternative; RaBitQ + TurboQuant 1@k.

* **Pure Math (Gilbert Strang Linear Algebra Ch 3)**:
  * Orthogonality of the four fundamental subspaces ($C(A^T) \perp N(A)$ and $C(A) \perp N(A^T)$).
  * Projections onto lines and subspaces, Projection Matrix $P = A(A^T A)^{-1} A^T$ ($P^2 = P, P^T = P$).
  * Least squares approximations, normal equations $A^T A \hat{x} = A^T b$.
  * Orthonormal bases, Gram-Schmidt orthogonalization process, $A = QR$ factorization.
* **Queuing Theory (light)**: Poisson load generator = **Week 11 stretch** (deep $M/M/k$ in Month 4).
* **MUVERA** ([NeurIPS 2024](https://arxiv.org/abs/2405.19504)): asymmetric **Fixed Dimensional Encodings** so $\langle \mathrm{FDE}(Q), \mathrm{FDE}(P) \rangle$ approximates Chamfer/MaxSim; retrieve with Week 4/8 **IP** index; re-rank with exact MaxSim. Same family as asymmetric PQ (FP32 query vs compressed db).
* **Frontier compression**: [TurboQuant](https://research.google/blog/turboquant-redefining-ai-efficiency-with-extreme-compression/) — PolarQuant + QJL. **1@k Fri required.**
* **C++ Track**: **MUVERA Mon–Tue**; **PLAID 3-stage Wed**; **RaBitQ Thu**; **TurboQuant Fri**.
  * **Deferred (required Week 16 Fri)**: BM25, WAND, **RRF**.

| Day | Pure Mathematics (Strang) (90 min) | Systems / C++ Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Nov 3** | **STRANG §3.1**: Orthogonal vectors, orthogonal subspaces. Proving row space is orthogonal to nullspace in $\mathbb{R}^n$. | [MUVERA](https://arxiv.org/abs/2405.19504) §1–3: FDE construction, SimHash buckets, **asymmetric** query vs doc encode. | **secan (required)**: `fde_encode` on **Week 9 Fri limbed token dump**. Hash tokens into $B$ buckets, per-bucket aggregate, $R$ repetitions. Query FDE $\neq$ doc FDE. |
| **Tue Nov 4** | **STRANG §3.2**: Projection onto a 1D line: $P = \frac{a a^T}{a^T a}$. Cauchy-Schwarz from projection error. | MUVERA §4–5: FDE MIPS + MaxSim re-rank; candidate count vs heuristics. | **secan (required)**: Index doc FDEs with **IP** HNSW or IVF (Week 4/8). Retrieve then **MaxSim re-rank**. Plot Recall vs candidates vs Week 9 centroid prune. |
| **Wed Nov 5** | **STRANG §3.3**: Projection onto a subspace; $A^T A \hat{x} = A^T b$. | PLAID §3–5: centroid → quantized MaxSim → FP32. | **secan (required)**: **PLAID 3-stage** (2/4-bit residual MaxSim). Same slice: PLAID vs MUVERA candidate efficiency. Poisson load gen = stretch. |
| **Thu Nov 6** | **STRANG §3.4**: Orthonormal $Q$, Gram-Schmidt, $A = QR$. | RaBitQ: random orthogonal + error correction. **PIKUS Ch 8** concurrency skim. | **secan**: QR rotation helper + **RaBitQ**. Recall vs plain BQ (Week 7). |
| **Fri Nov 7** | **STRANG §3.4**: Least squares via QR: $\hat{x} = R^{-1} Q^T b$. | [TurboQuant](https://research.google/blog/turboquant-redefining-ai-efficiency-with-extreme-compression/): PolarQuant + QJL; 1@k vs PQ/RaBitQ. | **secan (required)**: **TurboQuant/PolarQuant or QJL 1@k** vs RaBitQ vs PQ on **GloVe-200 or 768-D**. Plot Recall@1. |

> **📝 Essay 10 (Sat Nov 8)**: *"MUVERA FDEs vs PLAID Cascades: Reducing MaxSim to MIPS"*

---

### Week 11 (Nov 10–14): Determinants, Eigenvalues, Spectral Theorem & LSM-Tree Engine

**Theme**: Determinants, eigenvalues, the Spectral Theorem, and LSM-Tree storage (DiskANN = stretch).

* **Pure Math (Gilbert Strang Linear Algebra Ch 4–5)**:
  * Determinants: 3 fundamental properties, algebraic formulas, cofactors, Cramer's rule.
  * Eigenvalues and Eigenvectors: $\det(A - \lambda I) = 0$, trace and determinant formulas, matrix diagonalization $A = S \Lambda S^{-1}$.
  * Symmetric Matrices: Proof that eigenvalues are all real and eigenvectors are orthogonal. The Spectral Theorem $A = Q \Lambda Q^T$.
* **Storage Engine Internals**: LSM-Tree for vectors: WAL, mutable MemTable HNSW, immutable disk segments (Arrow/Lance layout), background compaction.
* **C++ Engine (`secan`)**: `LSMVectorEngine` core this week. **DiskANN + `io_uring` = required Week 16 Thu**. **ACORN = Week 22**.

| Day | Pure Mathematics (Strang) (90 min) | Systems / C++ Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Nov 10** | **STRANG §4.1–4.4**: Determinants: axiomatic definition (linearity, sign change, $\det I = 1$), cofactor expansions, formula for $A^{-1}$. | Research paper: *"DiskANN: Fast Accurate Billion-point NN Search on a Single Node"* (Subramanya et al. 2019) — architecture skim (**build Week 16 Thu**). | **secan**: Implement `WriteAheadLog` (`wal.bin`) and in-memory mutable `MemTable` (dynamic HNSW absorbing live writes). |
| **Tue Nov 11** | **STRANG §5.1–5.2**: Eigenvalues and eigenvectors: characteristic polynomial $\det(A - \lambda I) = 0$. Matrix diagonalization $S^{-1} A S = \Lambda$. | Apache Arrow / Lance columnar layout notes for segment files. | **secan**: Implement Segment Flusher: when MemTable reaches threshold, flush to immutable disk segment (flat Arrow/Lance layout). |
| **Wed Nov 12** | **STRANG §5.3–5.4**: Systems of differential equations $\frac{du}{dt} = Au$, matrix exponential $e^{At}$, stability of linear dynamical systems. | Linux `io_uring` tutorial: SQ/CQ basics (**implement Week 16 Thu**). | **secan**: Background compaction: merge **segments and HNSW graphs** (not only LSM files). Rebuild/compact graph edges after merge. |
| **Thu Nov 13** | **STRANG §5.5**: Real symmetric matrices: proof that eigenvalues are real and eigenvectors are orthogonal. The Spectral Theorem $A = Q \Lambda Q^T$. | **ASYNC Ch 6 & Ch 9**: Boost.Asio I/O concepts, profiling asynchronous workflows. | **secan**: Concurrent search-while-ingest smoke test. **Stretch**: Poisson load gen ($p50/p95/p99$) moved from Week 10. Add ThreadSanitizer CI job. |
| **Fri Nov 14** | **STRANG §5.6**: Positive definite matrices: tests via eigenvalues, pivots, determinants, and energy $x^T A x > 0$. Cholesky factorization $A = L L^T$. | **FINSY Ch 3**: High-performance system measurement, scaling modules, latency distributions. | **secan**: Crash-recovery test: kill process mid-write; verify WAL replay restores MemTable. Benchmark inserts/sec under search traffic. |

> **📝 Essay 11 (Sat Nov 15)**: *"LSM-Trees for Vector Databases: Write-Ahead Logs, MemTables, and Apache Arrow Storage"*

---

### Week 12 (Nov 17–21): SVD, Whitening, Composed Indexes & Pareto vs Faiss

**Theme**: SVD / query-side PCA, HNSW heap opts, **`IVFPQIndex` + `HNSWSQIndex`**, **required** `ann-benchmarks` on **SIFT and 768-D**.

* **Pure Math**: Strang Ch 6 (unchanged).
* **C++ Engine (`secan`)**: Whitening / query PCA; Week 8 heap catch-up; **compose IVF-PQ and HNSW-SQ**; Pareto vs Faiss/hnswlib. **No REST.** nanobind + CLI.

| Day | Pure Mathematics (Strang) (90 min) | Systems / Architecture Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Nov 17** | **STRANG §6.3**: SVD: $A = U \Sigma V^T$. | Query-side PCA / OPQ literature. | **secan**: **Whitening + query-side PCA**. Hubness $S_{N_k}$ before/after. |
| **Tue Nov 18** | **STRANG §6.3**: Truncated SVD / Eckart–Young. | **PIKUS Ch 6**: RW locks. | **secan**: `nanobind` + CLI: expose `HNSWIndex`, **`IVFPQIndex`**, **`HNSWSQIndex`**, `LSMIndex`. |
| **Wed Nov 19** | **STRANG §6.7**: PCA. | Branchless heap; bitset visited. | **secan (required)**: Bounded flat heap + **bitset visited**. Then concurrent HNSW locks. |
| **Thu Nov 20** | **STRANG §6.7**: Matrix norms, $\kappa(A)$. | `ann-benchmarks` protocol (required, not stretch). | **secan (required)**: Finish **`IVFPQIndex`** (IVF + PQ ADC + optional OPQ). Recall–QPS vs **Faiss IVFPQ** on SIFT. |
| **Fri Nov 21** | **PURE LINALG SYNTHESIS**: Strang Ch 1–6. | hnswlib SQ / Faiss HNSW+SQ notes. | **secan (required)**: **`HNSWSQIndex`** (HNSW over SQ8/SQ4). Pareto vs **hnswlib/Faiss** on **SIFT + 768-D**. Tag `v1.0-cpu-complete`. |

> **📝 Essay 12 (Sat Nov 22)**: *"Composed Indexes: IVF-PQ and HNSW-SQ vs Faiss/hnswlib"*

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

# BLOCK II: GPU SPECIALIZATION (Weeks 17–28 / Jan–Mar 2027)

Weekdays remain **`secan`/CUDA**. DL stays **Saturday afternoon**. Cluster shard/replica beyond NCCL = stretch. **No REST.**

---

# 📅 MONTH 5: Mathematical Statistics, Limit Theorems, GPU Graphs & Multi-GPU (Jan 2027)

> **🔬 Monthly research**: *Paging vs Quantizing Memory: PagedAttention and TurboQuant as Complementary KV Levers* → publish **Sun Jan 31** · folder `research/2027-01-paging-vs-quantizing-kv/`

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
> **🚀 Month 4 research PUBLISH (Sun Dec 27)**: freeze `research/2026-12-three-paths-spine/paper.md` + public post.

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

### Week 19 (Jan 5–9): Mathematical Statistics, MLE, PagedAttention & KV Compression

**Theme**: Point estimation, MLE, Fisher Information, PagedAttention (vLLM), and **TurboQuant-style KV quantization** (3-bit, training-free).

* **Mathematical Statistics (Statistical Theory)**:
  * Point Estimation: Estimators $\hat{\theta}(X_1, \dots, X_n)$, Bias $\text{Bias}(\hat{\theta}) = \mathbb{E}[\hat{\theta}] - \theta$, Mean Squared Error $\text{MSE}(\hat{\theta}) = \text{Var}(\hat{\theta}) + \text{Bias}^2$.
  * **Maximum Likelihood Estimation (MLE)**: Likelihood function $L(\theta; \mathbf{x}) = \prod f(x_i; \theta)$, log-likelihood $\ell(\theta)$, score function $S(\theta) = \ell'(\theta)$, solving $\ell'(\hat{\theta}) = 0$.
  * Fisher Information $I(\theta) = \mathbb{E}\left[\left(\frac{\partial}{\partial \theta} \ln f(X; \theta)\right)^2\right] = -\mathbb{E}\left[\frac{\partial^2}{\partial \theta^2} \ln f(X; \theta)\right]$.
  * Cramér-Rao Lower Bound (CRLB): $\text{Var}(\hat{\theta}) \geq \frac{1}{n I(\theta)}$ for unbiased estimators. Efficiency of estimators.
* **Systems / Frontier Reading**: CS:APP Chapter 9 "Virtual Memory" + vLLM PagedAttention + [TurboQuant](https://research.google/blog/turboquant-redefining-ai-efficiency-with-extreme-compression/) KV path (PolarQuant stage + 1-bit QJL residual; unbiased attention-score estimator; ~6× KV memory cut, up to ~8× logits speedup on H100 in blog numbers).
* **C++ Engine (`secan`) & Python**:
  * **Python/CUDA**: Implement `BlockTable` + **PagedAttention** kernel; optional **stretch**: apply PolarQuant/QJL sketch to cached $K$ (or document design only if timeboxed).
  * **secan**: Double-buffered async pinned memory pipeline (`cudaHostAlloc`) overlapping batch search compute with PCIe transfers.

| Day | Mathematical Statistics (90 min) | GPU / vLLM Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Jan 5** | **STATS §1.1–1.3**: Point estimation foundations: Sample mean, sample variance ($s^2$ with $n-1$ denominator for unbiasedness), MSE decomposition. | vLLM Paper §1–3: The KV Cache fragmentation problem in LLMs ($60\%–80\%$ memory wasted on over-allocation). | **Python/CUDA**: Implement `BlockTable` data structure in PyTorch: maps logical sequence tokens to physical GPU memory blocks (block size 16). |
| **Tue Jan 6** | **STATS §2.1–2.3**: Maximum Likelihood Estimation (MLE): Deriving MLE for Gaussian mean/variance, Poisson $\lambda$, and Bernoulli $p$. Invariance property of MLEs. | vLLM Paper §4: PagedAttention kernel design: reading $K, V$ blocks via block lookup table in CUDA. | **CUDA**: Implement **PagedAttention CUDA kernel**: during self-attention, resolve physical $K, V$ block pointers on-the-fly via block table. |
| **Wed Jan 7** | **STATS §2.4–2.5**: Fisher Information: Definition and mathematical equivalence of variance of score vs negative expected Hessian of log-likelihood. | [TurboQuant](https://research.google/blog/turboquant-redefining-ai-efficiency-with-extreme-compression/): KV experiments (LongBench, RULER, needle-in-haystack); PolarQuant + QJL residual as bias killer for attention scores. | **secan**: Build unified `GpuIndex` wrapper class: device memory lifecycle, async transfers, kernel launches, RAII cleanup. |
| **Thu Jan 8** | **STATS §2.6**: Cramér-Rao Lower Bound (CRLB): Step-by-step rigorous proof using Cauchy-Schwarz inequality on the score function. | **PMPP Ch 19**: Heterogeneous CPU+GPU workload partitioning. | **secan**: Implement **CPU↔GPU hybrid fallback**: partition oversized dataset into GPU VRAM (fast) and CPU RAM (AVX2). Merge results. |
| **Fri Jan 9** | **STATS §3.1–3.3**: Hypothesis testing foundations: Null ($H_0$) and alternative ($H_1$) hypotheses, Type I ($\alpha$) and Type II ($\beta$) errors, p-values, Neyman-Pearson Lemma. | Profile PagedAttention vs standard KV cache memory; contrast with TurboQuant bitwidth story (paging ≠ quantizing). | **secan**: Benchmark query batch sizes ($B=1, 10, 100, 1000$). Plot the CPU vs GPU crossover curve. |

> **📝 Essay 19 (Sat Jan 10)**: *"PagedAttention Meets TurboQuant: Virtual Memory for KV Blocks and Extreme Bit Compression"*

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

# 📅 MONTH 6: Optimization, Spectral Graphs, Production Hardening & Master Release (Feb 2027)

> **🔬 Monthly research**: *Predicate-Aware Graphs: ACORN-style Filters, Tombstones, and Portable SIMD* → publish **Sat Feb 14** (with `v2.0`) · folder `research/2027-02-predicate-aware-graphs/`

---

### Week 21 (Jan 19–23): Convex Optimization, KKT, ColPali GPU Path

**Theme**: Convex optimization / KKT, ColPali multimodal retrieval, and **Week 15 FA-2 catch-up (Wed)**.

* **Pure Mathematics (Boyd & Vandenberghe - *Convex Optimization*)**: Convex sets/functions, duality, KKT.
* **C++ Engine (`secan`)**: GPU MaxSim (CUTLASS); GPU NN-Descent. **ColPali CLIP projector = Sat Jan 24.** FA-2 = Week 25.

| Day | Pure Mathematics (Boyd Convex Optimization) (90 min) | GPU / CUDA Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Jan 19** | **CONVEX §2.1–2.4**: Convex sets: affine sets, convex combinations, convex hulls, cones, hyperplanes, and Euclidean balls. | Re-read ColBERT/PLAID papers with GPU focus: mapping MaxSim to batched GEMM + reductions. | **secan**: Implement **GPU MaxSim kernel**: CUTLASS GEMM + warp row-max + column-sum. |
| **Tue Jan 20** | **CONVEX §3.1–3.4**: Convex functions: first/second-order conditions, Jensen. | CLIP / SigLIP contrastive alignment (image encoder ↔ text encoder). | **secan**: GPU MaxSim polish / fused pipeline. *(CLIP projector: Sat Jan 24.)* |
| **Wed Jan 21** | **CONVEX §4.1–4.4**: Convex optimization problems: LP, QP, SOCP. | NN-Descent / CAGRA neighbor exchange. | **secan**: GPU NN-Descent base-layer graph construction. **FA-2 → Week 25.** |
| **Thu Jan 22** | **CONVEX §5.1–5.4**: Duality: Lagrangian, weak/strong duality, Slater. | CAGRA / NN-Descent GPU neighbor exchange. | **secan**: GPU NN-Descent base-layer graph construction. |
| **Fri Jan 23** | **CONVEX §5.5**: KKT conditions: necessity and sufficiency for convex problems. | Review GPU ColBERT / ColPali integration. | **secan**: Ingest ColPali visual embeddings; text query → visual page search. **Stretch**: same tokens through MUVERA FDE + IP MIPS. |

> **📝 Essay 21 (Sat Jan 24)**: *"KKT and ColPali: CLIP Projector + GPU MaxSim"*  
> **🧠 DL weekend**: CLIP-style projector + ColPali head.

---

### Week 22 (Jan 26–30): Production Hardening — ACORN, Tombstones & NUMA

**Theme**: Filtered search as an **on-call product**: pre- vs post-filter, range predicates, ACORN, deletes, NUMA.

* **C++ Engine (`secan`)** — required:
  1. Pre-filter vs post-filter vs **ACORN**; **range** (`price < x`); selectivity vs recall
  2. Tombstone + vacuum
  3. NUMA pin

| Day | Systems Math (90 min) | Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Jan 26** | Filter selectivity $P(\text{pass})$; **post-filter recall collapse**. | Payload/B-tree + ANN; pre- vs post-filter. | **secan (required)**: Payload index (B-tree or sorted ids) + **pre-filter** candidate set; **post-filter** HNSW; plot recall vs selectivity. |
| **Tue Jan 27** | ACORN $N$-hop vs connectivity under filters. | ACORN paper §1–6. | **secan**: ACORN-style filtered graph search; compare to Mon's pre/post. |
| **Wed Jan 28** | Tombstone amortization vs vacuum. | Lock-free bitset / graph mutation. | **secan**: Tombstones + vacuum rewires. |
| **Thu Jan 29** | NUMA / PCIe budget. | `libnuma`; DiskANN under NUMA. | **secan**: NUMA pin; re-bench. |
| **Fri Jan 30** | Range predicates vs boolean bitmaps. | Production checklist. | **secan (required)**: **Range filter** (`payload < x`) on pre-filter path; smoke tests. Tag `v1.5-production`. |

> **📝 Essay 22 (Sat Jan 31)**: *"Pre/Post/Range Filters vs ACORN: Selectivity and Recall Collapse"*  
> **🚀 Month 5 research PUBLISH (Sun Jan 31)**: freeze `research/2027-01-paging-vs-quantizing-kv/paper.md` + public post.

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
| **Fri Feb 6** | **SPECTRAL §3.1**: Expander graphs: Spectral expansion vs edge expansion. Why Ramanujan graphs have optimal small-world routing properties. | Set up cross-platform CI matrix: Ubuntu x86_64, macOS Apple Silicon (ARM64). | **secan**: Verify builds and tests on x86_64 and ARM64. ONNX export → [`intextus_30min_six_month.md`](intextus_30min_six_month.md) (`limbed`), not this afternoon. |

> **📝 Essay 23 (Sat Feb 7)**: *"Spectral Graph Theory, Cheeger's Inequality, and Cross-Platform ARM NEON Optimization"*

---

### Week 24 (Feb 9–13): Spectral Synthesis, CLI Scaffold & GPU Occupancy

**Theme**: Close Month 6 math; **do not** tag `v2.0` yet — GPU specialization still has March.

* **secan**: CLI scaffold + occupancy/`ncu` pass. Full release → Week 28.

| Day | Pure Mathematics (90 min) | Systems Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Feb 9** | Spectral + production recap (Cheeger, ACORN, tombstones). | **PIKUS Ch 12** retrospective. | **secan**: CLI scaffold `secan build/search/bench` (complete Week 28). |
| **Tue Feb 10** | Convexity recap: KKT complementary slackness. | Occupancy calculator / `__launch_bounds__`. | **CUDA**: Occupancy tune on IVF + graph kernels. |
| **Wed Feb 11** | Fourier skim (optional): convolution as GEMM intuition. | CUB/Thrust fusion notes. | **CUDA**: Fused distance+topk kernel (was former Week 22 GPU polish). |
| **Thu Feb 12** | Info-theory recap: CE = $H+D_{KL}$ (ties to InfoNCE). | `-Wall -Wextra -Wpedantic`. | **secan**: Warning cleanup; examples/ stubs. |
| **Fri Feb 13** | — | Month 6 paper freeze checklist. | **secan/CUDA**: Occupancy/`ncu` leftover polish. *(Naive KV re-bench: Saturday DL if needed.)* |

> **📝 Essay 24 (Sat Feb 14)**: *"Portable SIMD and Production Graphs — Month 6 Lab Closeout"*  
> **🚀 Month 6 research PUBLISH (Sun Feb 28)**: `research/2027-02-predicate-aware-graphs/paper.md` (use remaining Feb weekends).

---

# 📅 MONTH 7: GPU Specialization Closeout (Mar 2027)

> **🔬 Monthly research**: *IO-Aware GPU Serving: FlashAttention-2, Multi-GPU Search, and KV Paging* → publish **Fri Mar 12** · folder `research/2027-03-gpu-serving/`

---

### Week 25 (Feb 16–20): FlashAttention-2 (Week 15 catch-up)

**Theme**: FA-2 loop order, warp partition, Nsight vs FA-1 and SDPA.

| Day | Math (90 min) | Reading (45 min) | Afternoon (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Feb 16** | Online softmax recap (`m`, $\ell$). | FlashAttention-2 (Dao 2023). | **CUDA**: FA-2 loop order on Week 15 kernel. |
| **Tue Feb 17** | Work/span of tiled GEMM. | Warp partition along sequence. | **CUDA**: Reduce inter-warp sync; unit-test vs PyTorch. |
| **Wed Feb 18** | Numerical stability of online softmax. | `ncu` metrics: DRAM, achieved TFLOPS. | **CUDA (required)**: Nsight FA-1 vs FA-2 vs SDPA. |
| **Thu Feb 19** | GQA + FA: fewer KV tiles. | Integrate GQA from Week 2/4. | **Python/CUDA**: FA-2 path with `num_kv_heads`. |
| **Fri Feb 20** | — | — | Expose FA-2 via `cpp_extension`. Document speedup table for March paper. |

> **📝 Essay 25 (Sat Feb 21)**: *"FlashAttention-2: Loop Order and Warp Partition"*

---

### Week 26 (Feb 23–27): PagedAttention polish on naive KV

**Theme**: Week 4 naive KV is the baseline; this week **pages** it (Week 19 may already have a first BlockTable — finish correctness + GQA).

| Day | Math (90 min) | Reading (45 min) | Afternoon (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Feb 23** | Virtual memory recap (CS:APP Ch 9). | vLLM PagedAttention §4. | **CUDA**: BlockTable + paged K/V vs naive concat (A/B latency + memory). |
| **Tue Feb 24** | Fragmentation vs bitwidth (TurboQuant). | TurboQuant KV blog. | Design note: paging ≠ quantizing; optional QJL sketch. |
| **Wed Feb 25** | — | cuVS / serving APIs. | Hybrid CPU↔GPU fallback polish. |
| **Thu Feb 26** | — | Batch size crossover. | Plot $B=1..1000$ with **paged** KV. |
| **Fri Feb 27** | Month 6 paper remaining figures. | — | Freeze ACORN/tombstone paper if not done Feb 28. |

> **📝 Essay 26 (Sat Feb 28)**: *"Naive KV vs Paged KV: The Baseline We Should Have Had First"*  
> **🚀 Month 6 PUBLISH (Sun Feb 28)** if not already.

---

### Week 27 (Mar 2–6): Multi-GPU + ColPali ingest

**Theme**: NCCL search scaling; finish vision–text index.

| Day | Math (90 min) | Reading (45 min) | Afternoon (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Mar 2** | AllReduce vs AllGather cost. | NCCL ring algorithms. | **secan**: Multi-GPU IVF load-balance polish (Week 20). |
| **Tue Mar 3** | — | NVLink vs PCIe. | Scaling efficiency 1/2/4 GPU (or 1 GPU simulated shards). |
| **Wed Mar 4** | Contrastive InfoNCE recap. | ColPali paper. | Ingest CLIP-projected patches into `MultiVectorIndex`. |
| **Thu Mar 5** | — | GPU MaxSim CUTLASS. | Text query → visual page search E2E. |
| **Fri Mar 6** | — | — | Month 7 paper figures: GPU QPS + ColPali demo. |

> **📝 Essay 27 (Sat Mar 7)**: *"Sharded IVF and Visual Late Interaction"*

---

### Week 28 (Mar 9–13): 7-Month Release

**Theme**: `v2.0` — VS spine + GPU specialization + slow-path DL.

| Day | Math (90 min) | Reading (45 min) | Afternoon (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Mar 9** | 7-month geometric thread recap. | API/docs pass. | Finish CLI + Doxygen. |
| **Tue Mar 10** | — | `ann-benchmarks`. | Full CPU+GPU benchmark matrix. |
| **Wed Mar 11** | — | Examples. | Five examples including dense InfoNCE search + GPU batch. |
| **Thu Mar 12** | — | README. | **Publish Month 7 paper.** Tag `v2.0-complete`. |
| **Fri Mar 13** | Rest / interview packet. | — | Portfolio: 7 papers + `secan` Pareto plots. |

> **📝 Essay 28 (Sat Mar 14)**: *"7 Months: Vector Search Spine, GPU Serving, and a Slow-Path Retriever Stack"*  
> **🚀 Month 7 research PUBLISH (Thu Mar 12)**: `research/2027-03-gpu-serving/paper.md`

---

## 📋 Comprehensive 28-Week Essay Publication Schedule

| Week | Essay Date | Essay Title |
|:---|:---|:---|
| **1** | Sat Sep 6 | *The Geometry of High-Dimensional Retrieval: From Trigonometric Coordinates and NDCG to CPU Performance Counters* |
| **2** | Sat Sep 13 | *Breaking Dependency Chains: Multi-Register SIMD Kernels* |
| **3** | Sat Sep 20 | *Integrals, Accumulation, and the Physics of CPU Caches* |
| **4** | Sat Sep 27 | *From Euler's Formula to RoPE and Voronoi Cells* |
| **5** | Sat Oct 4 | *Multivariable Gradients, Hessians, and Low-Bit Quantization: Compressing High-Dimensional Information* |
| **6** | Sat Oct 11 | *Lagrange Multipliers, Jacobians, and Product Quantization: Compressing Vectors to 16 Bytes* |
| **7** | Sat Oct 18 | *Google ScaNN Anisotropic Loss, Vector Fields, and In-Register SIMD FastScan* |
| **8** | Sat Oct 25 | *Building HNSW from Scratch: Graph Laplacians, The Hubness Phenomenon, and Sub-Millisecond Search* |
| **9** | Sat Nov 1 | *Beyond Single Vectors: The Linear Algebra and SIMD Architecture of ColBERT Late Interaction* |
| **10** | Sat Nov 8 | *MUVERA FDEs vs PLAID Cascades: Reducing MaxSim to MIPS* |
| **11** | Sat Nov 15 | *LSM-Trees for Vector Databases: Write-Ahead Logs, MemTables, and Apache Arrow Storage* |
| **12** | Sat Nov 22 | *Composed Indexes: IVF-PQ and HNSW-SQ vs Faiss/hnswlib* |
| **13** | Sat Nov 29 | *GPU Architecture for Vector Search: Why Naive CUDA Kernels Lose to CPU AVX2* |
| **14** | Sat Dec 6 | *Warp Shuffles and Memory Coalescing: Saturating GPU Memory Bandwidth in Vector Search* |
| **15** | Sat Dec 13 | *Building FlashAttention from Scratch in CUDA: IO-Aware Tiling and Online Softmax* |
| **16** | Sat Dec 20 | *Closing the Vector Search Spine: GPU IVF, Vamana/DiskANN, and Hybrid RRF/WAND* |
| **17** | Sat Dec 27 | *CAGRA and GPU Graph Traversal: Overcoming Random Memory Access at Warp Scale* |
| **18** | Sat Jan 3 | *Markov Chains, Graph Random Walks, and Warp-Shuffle GPU FastScan* |
| **19** | Sat Jan 10 | *PagedAttention Meets TurboQuant: Virtual Memory for KV Blocks and Extreme Bit Compression* |
| **20** | Sat Jan 17 | *Shannon Entropy, Kullback-Leibler Divergence, and Distributed Multi-GPU Search* |
| **21** | Sat Jan 24 | *KKT and ColPali: CLIP Projector + GPU MaxSim* |
| **22** | Sat Jan 31 | *Pre/Post/Range Filters vs ACORN: Selectivity and Recall Collapse* |
| **23** | Sat Feb 7 | *Spectral Graph Theory, Cheeger's Inequality, and Cross-Platform ARM NEON Optimization* |
| **24** | Sat Feb 14 | *Portable SIMD and Production Graphs — Month 6 Lab Closeout* |
| **25** | Sat Feb 21 | *FlashAttention-2: Loop Order and Warp Partition* |
| **26** | Sat Feb 28 | *Naive KV vs Paged KV: The Baseline We Should Have Had First* |
| **27** | Sat Mar 7 | *Sharded IVF and Visual Late Interaction* |
| **28** | Sat Mar 14 | *7 Months: Vector Search Spine, GPU Serving, and a Slow-Path Retriever Stack* |
