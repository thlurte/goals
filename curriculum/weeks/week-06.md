# 🚀 Week 06 Execution Playbook

> **Theme**: Lagrange Multipliers, Multiple Integrals, Jacobians & BERT from Scratch  
> **Calendar Dates**: Sat Oct 10 – Fri Oct 16 (2026-10-10 to 2026-10-16)
> **Parent Month Dashboard**: [Month 2 (Oct 2026)](month-02-oct.md) · **Block**: I — Vector Search Engine

| | | |
|:---|:---|:---|
| [← Week 05](week-05.md) | [Month 2 (Oct 2026) Dashboard](month-02-oct.md) | [Week 07 →](week-07.md) |

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
| **Saturday** | Sat Oct 10 | [`Day 036`](../days/month-02/day-036-2026-10-10.md) | **09:00–13:00**: Pure Math Block 1 (Theory & Derivations) | **15:00–16:30**: Literature Sanctuary | **18:00–19:30**: Information Theory (Cover & Thomas) · **19:30–21:00**: Thought Leadership (Richard W. Hamming) · **21:00+**: Free / Rest|
| **Sunday** | Sun Oct 11 | [`Day 037`](../days/month-02/day-037-2026-10-11.md) | **09:00–13:00**: Pure Math Block 2 (Problem Sets & Proofs) | **13:00**: Maint · **15:00**: Penrose | **18:00–19:30**: Dist Systems (DDIA Ch 5) · **19:30–21:00**: Systems Lab (H&P Ch 3) |
| **Monday** | Mon Oct 12 | [`Day 038`](../days/month-02/day-038-2026-10-12.md) | Research paper: *"Product Quantization for Nearest Neighbor Search"* (Jégou et al. 2011) §1–4. | **Hardware Profiling & Benchmark Sweeps** | **secan**: Implement $k$-means clustering in C++ for a subspace: `train_kmeans(data, k=256, dim_sub)` using $k$-means++. |
| **Tuesday** | Tue Oct 13 | [`Day 039`](../days/month-02/day-039-2026-10-13.md) | Faiss wiki on Product Quantizer: subspace splitting, codebook memory layouts. | **DL Track (Part 1): Architecture & Tensor Shapes** | **secan**: Implement `ProductQuantizer`: split $D$ dimensions into $M$ subspaces. Train $M$ codebooks. Encode vectors as $M$-byte codes. |
| **Wednesday** | Wed Oct 14 | [`Day 040`](../days/month-02/day-040-2026-10-14.md) | **AGNER Ch 7.10 & Ch 9**: Array structures for cache-friendly table lookups, stride optimization. | **DL Track (Part 2): Training Loop & Verification** | **secan**: Implement Asymmetric Distance Computation (ADC): precompute query-to-centroid table `float LUT[M][256]`. Distance = sum of $M$ lookups. |
| **Thursday** | Thu Oct 15 | [`Day 041`](../days/month-02/day-041-2026-10-15.md) | **PIKUS Ch 10**: Compiler optimizations, `__restrict__`, loop vectorization, Link-Time Optimization (LTO). | **DL / Vector Retrieval Integration & Profiling** | **secan**: **Asymmetric BQ**: FP32 query vs 1-bit db (Hamming / IP estimator). Keep query in FP32. |
| **Friday** | Fri Oct 16 | [`Day 042`](../days/month-02/day-042-2026-10-16.md) | **PIKUS Ch 11**: Undefined behavior, memory aliasing. | **Weekly Technical Article: Drafting & Publishing** | **secan (required)**: Wire **IVF + PQ ADC** sketch (`IVFPQIndex` stub): coarse IVF then PQ inside lists. Recall vs IVFFlat on SIFT subset. **Compose, do not stop at PQ-only.** *(DL InfoNCE: Sat Oct 11.)* |

---

## 📋 Daily Action Items & Deliverables (Week 06)

### 🔹 Saturday, Sat Oct 10 ([`Day 036`](../days/month-02/day-036-2026-10-10.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 1**: Theory, concepts, and analytical derivations (textbook chapters & core proofs).
* `[ ]` **Core (15:00–16:30)**: **Weekend Reading Sanctuary**: Literature / Philosophy deep reading.
* `[ ]` **Core (16:30–18:00)**: **Physical Break & Mental Decompression**: Walk, tea, and recovery.
* `[ ]` **Core (18:00–19:30)**: **Information Theory Track**: Thomas M. Cover & Joy A. Thomas, *Elements of Information Theory* — **Ch 5.5–5.8** (Huffman Codes & Optimality Proofs).
* `[ ]` **Core (19:30–21:00)**: **Thought Leadership Masterclass**: Richard W. Hamming, *The Art of Doing Science and Engineering* — **Ch 8–12: Information & Coding** (Interlude, Shannon Information, Coding Theory, Error-Correcting Codes, Redundancy).
* `⭐ Optional / Stretch`: 21:00 onwards 100% Free / Rest.

### 🔹 Sunday, Sun Oct 11 ([`Day 037`](../days/month-02/day-037-2026-10-11.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 2**: Advanced theorems, problem sets, and chalkboard proof defense.
* `[ ]` **Core (13:00–14:00)**: **Runtime Maintenance**: Quick 30–60 min check for `limbed` / `ggmbed` (`embed-runtimes`).
* `[ ]` **Core (15:00–16:45)**: **Penrose Sunday**: *The Road to Reality* (1 chapter/week, visual geometry focus).
* `[ ]` **Core (18:00–19:30)**: **Distributed Systems & IR Track**: **DDIA Ch 5** (Replication: Leaders and Followers, Synchronous vs Asynchronous & Replication Lag).
* `[ ]` **Core (19:30–21:00)**: **Graduate Systems & GPU Architecture Lab**: Microarchitecture analysis and CUDA exercises in **H&P Ch 3** (Branch predictor state machines (2-bit, gshare, TAGE) & misprediction penalty modeling).
* `⭐ Optional / Stretch`: 21:00 onwards Weekly review & recovery.

### 🔹 Monday, Mon Oct 12 ([`Day 038`](../days/month-02/day-038-2026-10-12.md))
* `[ ]` **Core**: Implement $k$-means clustering in C++ with $k$-means++ centroid seeding for a single subspace.
* `⭐ Optional / Stretch`: Implement multi-threaded parallel $k$-means Lloyd iteration across CPU cores.


### 🔹 Tuesday, Tue Oct 13 ([`Day 039`](../days/month-02/day-039-2026-10-13.md))
* `[ ]` **Core**: Implement `ProductQuantizer` ($D \to M$ subspaces, $M \times 256$ codebooks); encode $N$ vectors into $N \times M$ bytes.
* `⭐ Optional / Stretch`: Measure quantization distortion $\|x - \tilde{x}\|^2$ as a function of subspace count $M \in \{8, 16, 32, 64\}$.


### 🔹 Wednesday, Wed Oct 14 ([`Day 040`](../days/month-02/day-040-2026-10-14.md))
* `[ ]` **Core**: Implement Asymmetric Distance Computation (`float LUT[M][256]`); compute query distances via $M$ byte lookups.
* `⭐ Optional / Stretch`: Implement 4-way unrolled ADC distance loop accumulating 4 database vectors simultaneously into registers.


### 🔹 Thursday, Thu Oct 15 ([`Day 041`](../days/month-02/day-041-2026-10-15.md))
* `[ ]` **Core**: Implement asymmetric 1-bit Binary Quantization (FP32 query dot product with 1-bit binary codes).
* `⭐ Optional / Stretch`: Derive the exact expectation of inner-product error under 1-bit quantization for isotropic Gaussian vectors.


### 🔹 Friday, Fri Oct 16 ([`Day 042`](../days/month-02/day-042-2026-10-16.md))
* `[ ]` **Core**: Wire `IVFPQIndex` composed index (coarse IVF centroids + PQ ADC inside inverted lists); benchmark Recall@10 on SIFT subset.
* `⭐ Optional / Stretch`: Compare memory footprint and search latency of IVFFlat vs IVFPQ (e.g. 128 bytes/vector vs 16 bytes/vector).


---

## ⛔ What NOT to Overspend Time On (Week 06 Time Traps)

* ❌ **Do NOT** train PQ codebooks on all 1M vectors—subsample 50,000 to 100,000 vectors for codebook training.
* ❌ **Do NOT** implement symmetric PQ distance computation (SDC)—asymmetric ADC (FP32 query vs PQ codes) is strictly superior for query accuracy.
* ❌ **Do NOT** build a custom multi-threading pool for PQ encoding—standard `std::jthread` or OpenMP parallel loop is sufficient.

---

## 📝 Weekend Deliverables

### ✍️ Technical Essay 06 (Drafted Friday 06:30–08:30)
* **Title**: *"Constrained Optimization and Subspace Codebooks: Lagrange Multipliers in Product Quantization"*
* **Target File**: `~/personal/goals/essays/essay_06.md`
* **5-Part Structure**:
  1. **Mathematical Foundation**: Core theorems, derivations, and formal definitions.
  2. **The Systems Bottleneck**: Hardware limitation (memory bandwidth, port contention, cache line splits, warp stalls).
  3. **The Engine Architecture**: Exact data structures and SIMD/CUDA kernel design implemented in `secan`.
  4. **Empirical Benchmarks**: Perf counter tables, latency percentiles ($p50/p95/p99$), and QPS curves.
  5. **Key Takeaway**: Architectural rule of thumb for production AI systems.

### 🧠 Deep Learning Track (Tue/Wed 06:30–08:30 Morning Builder)
* **Task**: **🧠 DL Builder Track (Tue/Wed)**: BERT + InfoNCE + **in-batch negatives**; export 768-D `.fvecs`. **Also**: implement `AdamW` optimizer from scratch ($m_t, v_t$ moment estimates, bias correction, **weight decay decoupling** from L2 reg). Train BERT with your AdamW; verify loss curve matches `torch.optim.AdamW`. **Hard negative mining**: retrieve BM25 top-100 per query, sample hard negatives from rank 10–100 for InfoNCE training.

### 🔬 Empirical Systems & Benchmarking Focus (Mon/Thu 06:30–08:30 Morning Builder)
* **Focus**: Geometry-Aware Anisotropic Polar Quantization: The Adaptive Ellipsoidal Lattice & Unbiased QJL Proof
* **Workspace**: `research/2026-10-anisotropic-quantization/`
* **Artifact Target**: Empirical benchmark and profiling data feeding into Friday's technical articles.
