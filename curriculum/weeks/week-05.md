# 🚀 Week 05 Execution Playbook

> **Theme**: Partial Derivatives, Gradients, Hessians, **Probability Primer** & Vision Transformer (ViT)  
> **Calendar Dates**: Sat Oct 3 – Fri Oct 9 (2026-10-03 to 2026-10-09)
> **Parent Month Dashboard**: [Month 2 (Oct 2026)](month-02-oct.md) · **Block**: I — Vector Search Engine

| | | |
|:---|:---|:---|
| [← Week 04](week-04.md) | [Month 2 (Oct 2026) Dashboard](month-02-oct.md) | [Week 06 →](week-06.md) |

---

## ⏰ Daily Operational Rhythm

```
┌──────────────────────────────┬────────────────────────────────────────────────────────────────────────┐
│ Time Slot                    │ Focus / Activity                                                       │
├──────────────────────────────┼────────────────────────────────────────────────────────────────────────┤
│ 📐 Saturday 09:00 – 13:00    │ Pure Mathematics Block 1 (Theory, Concepts, Derivations)               │
│ ☕ Saturday 15:00 – 16:30    │ Weekend Literature Sanctuary (Pirsig / GEB / Literature)               │
│ 🍵 Saturday 16:30 – 18:00    │ Physical Break & Mental Decompression (Walk, tea, workout)             │
│ 📚 Saturday 18:00 – 19:30    │ [NEW] Information Theory (Cover & Thomas: Rate-Distortion & AEP)       │
│ 🌙 Saturday 19:30 Onwards    │ 100% Free / Dinner & Recovery (No night math; morning block done)       │
├──────────────────────────────┼────────────────────────────────────────────────────────────────────────┤
│ 📐 Sunday 09:00 – 13:00      │ Pure Mathematics Block 2 (Problem Sets, Chalkboard Proofs)             │
│ 🔧 Sunday 13:00 – 14:00      │ Runtime Maintenance (limbed / ggmbed check)                            │
│ 🌌 Sunday 15:00 – 16:45      │ Penrose Sunday: The Road to Reality (1 chapter/week, visual geometry)  │
│ 🗄️ Sunday 18:00 – 19:30      │ [NEW] Distributed Systems & IR Track (DDIA / Manning IIR)              │
│ ⚙️ Sunday 19:30 – 21:00      │ [LAB] Graduate Systems & GPU Architecture Lab (H&P / Kirk & Hwu)       │
├──────────────────────────────┼────────────────────────────────────────────────────────────────────────┤
│ 📖 Mon–Fri 05:30 – 06:30     │ Systems & Architecture Deep Reading (Papers & Microarchitecture)       │
│ 🛠️ Mon–Fri 06:30 – 08:30     │ Morning Builder Track (DL / Benchmarking / Technical Articles)        │
│ ☀️ Mon–Fri Daytime           │ Professional Workday (Full focus, zero math fatigue)                   │
│ 📚 Mon–Fri 18:30 – 20:00     │ Evening Reading Sanctuary (Pirsig / GEB / Dostoevsky / Wiener)         │
│ 💻 Mon–Fri 20:30 – 22:30     │ Night Hands-On Implementation (secan C++20 / CUDA flow state)          │
└──────────────────────────────┴────────────────────────────────────────────────────────────────────────┘
```

---

## 📅 Day-by-Day Master Timetable

| Day | Date | Daily Runbook | Systems Reading (05:30–06:30) | Morning Builder Track (06:30–08:30) | Night Hands-On C++/CUDA (20:30–23:00) |
|:---|:---|:---|:---|:---|:---|
| **Saturday** | Sat Oct 3 | [`Day 029`](../days/month-02/day-029-2026-10-03.md) | **09:00–13:00**: Pure Math Block 1 (Theory & Derivations) | **15:00–16:30**: Literature Sanctuary | **18:00–19:30**: Information Theory (Cover & Thomas) · **19:30–21:00**: Thought Leadership (Richard W. Hamming) · **21:00+**: Free / Rest|
| **Sunday** | Sun Oct 4 | [`Day 030`](../days/month-02/day-030-2026-10-04.md) | **09:00–13:00**: Pure Math Block 2 (Problem Sets & Proofs) | **13:00**: Maint · **15:00**: Penrose | **18:00–19:30**: Dist Systems (DDIA Ch 4) · **19:30–21:00**: Systems Lab (H&P Ch 3) |
| **Monday** | Mon Oct 5 | [`Day 031`](../days/month-02/day-031-2026-10-05.md) | **AGNER Ch 7.2 & CSAPP §2.2–2.3**: Integer arithmetic efficiency, two's complement, overflow, bit-width conversion. | **Hardware Profiling & Benchmark Sweeps** | **secan**: Implement `ScalarQuantizer` with **percentile clipping (0.05th/99.95th)** to handle outlier dimensions. Verify dequantization error. |
| **Tuesday** | Tue Oct 6 | [`Day 032`](../days/month-02/day-032-2026-10-06.md) | **INTEL Intrinsics Guide**: Study `_mm256_maddubs_epi16`, `_mm256_madd_epi16`, `_mm256_dpbusd_epi32` (VNNI dot product). | **DL Track (Part 1): Architecture & Tensor Shapes** | **secan**: Implement `l2_squared_sq8()` using AVX2 integer intrinsics. Process 32 dimensions per iteration in a single `__m256i`. |
| **Wednesday** | Wed Oct 7 | [`Day 033`](../days/month-02/day-033-2026-10-07.md) | **AGNER Ch 12**: Integer SIMD saturation arithmetic, signed vs unsigned byte multiplication, widening instructions. | **DL Track (Part 2): Training Loop & Verification** | **secan**: SQ8 LUT / packed layout polish; SIMD path vs scalar dequant error check. |
| **Thursday** | Thu Oct 8 | [`Day 034`](../days/month-02/day-034-2026-10-08.md) | **CSAPP §2.4 (deep)**: Floating-point representation, rounding modes (round-to-nearest-even), subnormals, FP16/BF16 range vs precision tradeoffs for quantization kernels. | **DL / Vector Retrieval Integration & Profiling** | **secan**: Implement 4-bit scalar quantization (`SQ4`): pack 2 dimensions per byte with nibble masking. Build 2-stage SQ8 $\to$ FP32 re-ranker. |
| **Friday** | Fri Oct 9 | [`Day 035`](../days/month-02/day-035-2026-10-09.md) | **PIKUS Ch 9**: High-performance C++, move semantics, zero-copy buffer views (`std::span`). | **Weekly Technical Article: Drafting & Publishing** | **secan**: `std::span` views over quantized buffers; zero-copy encode path. * |

---

## 📋 Daily Action Items & Deliverables (Week 05)

### 🔹 Saturday, Sat Oct 3 ([`Day 029`](../days/month-02/day-029-2026-10-03.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 1**: Theory, concepts, and analytical derivations (textbook chapters & core proofs).
* `[ ]` **Core (15:00–16:30)**: **Weekend Reading Sanctuary**: Literature / Philosophy deep reading.
* `[ ]` **Core (16:30–18:00)**: **Physical Break & Mental Decompression**: Walk, tea, and recovery.
* `[ ]` **Core (18:00–19:30)**: **Information Theory Track**: Thomas M. Cover & Joy A. Thomas, *Elements of Information Theory* — **Ch 5.1–5.4** (Kraft Inequality & Optimal Source Codes).
* `[ ]` **Core (19:30–21:00)**: **Thought Leadership Masterclass**: Richard W. Hamming, *The Art of Doing Science and Engineering (Stripe Press)* — **Ch 1–4: Orientation & Foundations** (Orientation, Digital Computing Foundations, Evolution of Hardware & Software, Engineering Vision).
* `⭐ Optional / Stretch`: 21:00 onwards 100% Free / Rest.

### 🔹 Sunday, Sun Oct 4 ([`Day 030`](../days/month-02/day-030-2026-10-04.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 2**: Advanced theorems, problem sets, and chalkboard proof defense.
* `[ ]` **Core (13:00–14:00)**: **Runtime Maintenance**: Quick 30–60 min check for `limbed` / `ggmbed` (`embed-runtimes`).
* `[ ]` **Core (15:00–16:45)**: **Penrose Sunday**: *The Road to Reality* (1 chapter/week, visual geometry focus).
* `[ ]` **Core (18:00–19:30)**: **Distributed Systems & IR Track**: **DDIA Ch 4** (Encoding and Evolution: JSON, Protocol Buffers, FlatBuffers & Zero-Copy Binary Formats).
* `[ ]` **Core (19:30–21:00)**: **Graduate Systems & GPU Architecture Lab**: Microarchitecture analysis and CUDA exercises in **H&P Ch 3** (Tomasulo algorithm register renaming, Reorder Buffer (ROB) occupancy & dependency chains).
* `⭐ Optional / Stretch`: 21:00 onwards Weekly review & recovery.

### 🔹 Monday, Mon Oct 5 ([`Day 031`](../days/month-02/day-031-2026-10-05.md))
* `[ ]` **Core**: Implement `ScalarQuantizer` with percentile clipping (0.05th/99.95th); measure dequantization MSE on SIFT1M.
* `⭐ Optional / Stretch`: Derive and plot the Johnson-Lindenstrauss projection dimension curve $d(\epsilon, n)$ for $\epsilon \in [0.1, 0.5]$ and $n=10^6$.


### 🔹 Tuesday, Tue Oct 6 ([`Day 032`](../days/month-02/day-032-2026-10-06.md))
* `[ ]` **Core**: Implement `l2_squared_sq8()` using AVX2 `_mm256_maddubs_epi16` and `_mm256_madd_epi16` (32 dims per iteration).
* `⭐ Optional / Stretch`: Benchmark VNNI integer dot product (`_mm256_dpbusd_epi32`) if your CPU supports AVX-VNNI.


### 🔹 Wednesday, Wed Oct 7 ([`Day 033`](../days/month-02/day-033-2026-10-07.md))
* `[ ]` **Core**: Polish SQ8 LUT table layout; benchmark scalar dequantization + L2 vs direct integer SIMD distance.
* `⭐ Optional / Stretch`: Profile memory bandwidth saturation during full dataset SQ8 scan vs FP32 scan.


### 🔹 Thursday, Thu Oct 8 ([`Day 034`](../days/month-02/day-034-2026-10-08.md))
* `[ ]` **Core**: Implement 4-bit scalar quantization (`SQ4`) with nibble packing; construct 2-stage `SQ8 -> FP32` candidate re-ranker.
* `⭐ Optional / Stretch`: Implement a random hyperplane LSH bitset filter as a pre-stage candidate pruner.


### 🔹 Friday, Fri Oct 9 ([`Day 035`](../days/month-02/day-035-2026-10-09.md))
* `[ ]` **Core**: Refactor buffer management to zero-copy `std::span<const uint8_t>`; verify zero dynamic allocations during query execution.
* `⭐ Optional / Stretch`: Implement Kahan compensated summation in FP32 distance accumulator and compare error accumulation on 1536-D vectors.


---

## ⛔ What NOT to Overspend Time On (Week 05 Time Traps)

* ❌ **Do NOT** implement complex per-dimension dynamic range clipping—a global 0.05th/99.95th percentile clip is sufficient.
* ❌ **Do NOT** spend time writing 2-bit or 3-bit scalar quantizers—focus strictly on SQ8 (1 byte) and SQ4 (1 nibble).
* ❌ **Do NOT** try to implement Product Quantization (PQ) yet—PQ starts next week (Week 6).

---

## 📝 Weekend Deliverables

### ✍️ Technical Essay 05 (Drafted Friday 06:30–08:30)
* **Title**: *"Low-Bit Compression Under Outliers: Gradients, Percentile Clipping, and SIMD Integer Saturation"*
* **Target File**: `~/personal/goals/essays/essay_05.md`
* **5-Part Structure**:
  1. **Mathematical Foundation**: Core theorems, derivations, and formal definitions.
  2. **The Systems Bottleneck**: Hardware limitation (memory bandwidth, port contention, cache line splits, warp stalls).
  3. **The Engine Architecture**: Exact data structures and SIMD/CUDA kernel design implemented in `secan`.
  4. **Empirical Benchmarks**: Perf counter tables, latency percentiles ($p50/p95/p99$), and QPS curves.
  5. **Key Takeaway**: Architectural rule of thumb for production AI systems.

### 🧠 Deep Learning Track (Tue/Wed 06:30–08:30 Morning Builder)
* **Task**: **🧠 DL Builder Track (Tue/Wed)**: ViT patch embed + `[CLS]`.

### 🔬 Empirical Systems & Benchmarking Focus (Mon/Thu 06:30–08:30 Morning Builder)
* **Focus**: Geometry-Aware Anisotropic Polar Quantization: The Adaptive Ellipsoidal Lattice & Unbiased QJL Proof
* **Workspace**: `research/2026-10-anisotropic-quantization/`
* **Artifact Target**: Empirical benchmark and profiling data feeding into Friday's technical articles.
