# 🚀 Week 12 Execution Playbook

> **Theme**: SVD, Whitening, Composed Indexes & Pareto vs Faiss  
> **Calendar Dates**: Sat Nov 21 – Fri Nov 27 (2026-11-21 to 2026-11-27)
> **Parent Month Dashboard**: [Month 3 (Nov 2026)](month-03-nov.md) · **Block**: I — Vector Search Engine

| | | |
|:---|:---|:---|
| [← Week 11](week-11.md) | [Month 3 (Nov 2026) Dashboard](month-03-nov.md) | [Week 13 →](week-13.md) |

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
│ 💻 Mon–Fri 20:30 – 23:00     │ Night Block 1:  (Vector Search Engine in C++20 / SIMD / GPU)    │
│ ⚡ Mon–Fri 23:00 – 00:00     │ Night Block 2:  (C++ Multi-Modal High-D Embedding Runtime)     │
└──────────────────────────────┴────────────────────────────────────────────────────────────────────────┘
```

---

## 📅 Day-by-Day Master Timetable

| Day | Date | Daily Runbook | Systems Reading (05:30–06:30) | Morning Builder Track (06:30–08:30) | Night Hands-On C++/CUDA (20:30–23:00) |
|:---|:---|:---|:---|:---|:---|
| **Saturday** | Sat Nov 21 | [`Day 078`](../days/month-03/day-078-2026-11-21.md) | **09:00–13:00**: Pure Math Block 1 (Theory & Derivations) | **15:00–16:30**: Literature Sanctuary | **18:00–19:30**: Information Theory (Cover & Thomas) · **19:30–21:00**: Thought Leadership (Butler W. Lampson) · **21:00+**: Free / Rest|
| **Sunday** | Sun Nov 22 | [`Day 079`](../days/month-03/day-079-2026-11-22.md) | **09:00–13:00**: Pure Math Block 2 (Problem Sets & Proofs) | **13:00**: Maint · **15:00**: Penrose | **18:00–19:30**: Dist Systems (DDIA Ch 11–12) · **19:30–21:00**: Systems Lab (Pikus Ch 10–12) |
| **Monday** | Mon Nov 23 | [`Day 080`](../days/month-03/day-080-2026-11-23.md) | Query-side PCA / OPQ literature. | **Hardware Profiling & Benchmark Sweeps** | **secan**: **Whitening + query-side PCA**. Hubness $S_{N_k}$ before/after. |
| **Tuesday** | Tue Nov 24 | [`Day 081`](../days/month-03/day-081-2026-11-24.md) | **PIKUS Ch 6**: RW locks. | **DL Track (Part 1): Architecture & Tensor Shapes** | **secan**: `nanobind` + CLI: expose `HNSWIndex`, **`IVFPQIndex`**, **`HNSWSQIndex`**, `LSMIndex`. |
| **Wednesday** | Wed Nov 25 | [`Day 082`](../days/month-03/day-082-2026-11-25.md) | Branchless heap; bitset visited. | **DL Track (Part 2): Training Loop & Verification** | **secan (required)**: Bounded flat heap + **bitset visited**. Then concurrent HNSW locks. |
| **Thursday** | Thu Nov 26 | [`Day 083`](../days/month-03/day-083-2026-11-26.md) | `ann-benchmarks` protocol (required, not stretch). | **DL / Vector Retrieval Integration & Profiling** | **secan (required)**: Finish **`IVFPQIndex`** (IVF + PQ ADC + optional OPQ). Recall–QPS vs **Faiss IVFPQ** on SIFT. |
| **Friday** | Fri Nov 27 | [`Day 084`](../days/month-03/day-084-2026-11-27.md) | hnswlib SQ / Faiss HNSW+SQ notes. | **Weekly Technical Article: Drafting & Publishing** | **secan (required)**: **`HNSWSQIndex`** (HNSW over SQ8/SQ4). Pareto vs **hnswlib/Faiss** on **SIFT + 768-D**. Tag `v1.0-cpu-complete`. |

---

> **📚 Advanced Research Reference (Week 12)**: * [Alex Petrov, *Database Internals: A Deep Dive into Distributed Systems*](https://www.databass.dev/) — **Ch 2 (§2.1–2.4) & Ch 3 (§3.1–3.3)** (*Slotted Page Layout & 4KB Sector-Aligned Asynchronous NVMe IO*) · * [Denis Bakhvalov, *Performance Analysis and Tuning on Modern CPUs*](https://book.easyperf.net/) — **Ch 8 (§8.1–8.4)** (*Hardware Performance Counter Profiling with Linux `perf` during `io_uring` Storage Scans*)

## 📋 Daily Action Items & Deliverables (Week 12)

### 🔹 Saturday, Sat Nov 21 ([`Day 078`](../days/month-03/day-078-2026-11-21.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 1**: Theory, concepts, and analytical derivations (textbook chapters & core proofs).
* `[ ]` **Core (15:00–16:30)**: **Weekend Reading Sanctuary**: [Richard W. Hamming, *The Art of Doing Science and Engineering: Learning to Learn*](https://press.stripe.com/the-art-of-doing-science-and-engineering) — **Ch 27–28 (*Creativity & Style / Research Taste*)**.
* `[ ]` **Core (16:30–18:00)**: **Physical Break & Mental Decompression**: Walk, tea, and recovery.
* `[ ]` **Core (18:00–19:30)**: **Information Theory Track**: [Thomas M. Cover & Joy A. Thomas, *Elements of Information Theory (2nd ed)*](https://www.wiley.com/en-us/Elements+of+Information+Theory%2C+2nd+Edition-p-9780471241959) — **Ch 7 (§7.5–7.9)** (Zero-Error Capacity, Joint AEP & Channel Coding Converse).
* `[ ]` **Core (19:30–21:00)**: **Thought Leadership Masterclass**: [Butler W. Lampson, *Hints for Computer System Design (1983)*](https://www.cs.cmu.edu/~dga/papers/hints-tocs.pdf) — **Complete Landmark Monograph (Xerox PARC / ACM TOCS)** (Functionality, Speed, Fault Tolerance, Interfaces, Indirection & End-to-End Principles).
* `⭐ Optional / Stretch`: 21:00 onwards 100% Free / Rest.

### 🔹 Sunday, Sun Nov 22 ([`Day 079`](../days/month-03/day-079-2026-11-22.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 2**: Advanced theorems, problem sets, and chalkboard proof defense.
* `[ ]` **Core (13:00–14:00)**: **Runtime Maintenance**: Quick 30–60 min check for `limbed` / `ggmbed` (`embed-runtimes`).
* `[ ]` **Core (15:00–16:45)**: **Penrose Sunday**: [Sir Roger Penrose, *The Road to Reality*](https://www.vintagebooks.com) — **Ch 7: Complex-Number Calculus** (Holomorphic functions, Cauchy-Riemann equations, Cauchy integral formula, Laurent series.).
* `[ ]` **Core (18:00–19:30)**: **Distributed Systems & IR Track**: [Martin Kleppmann, *Designing Data-Intensive Applications*](https://dataintensive.net/) — **DDIA Ch 7** (Transactions: ACID properties, Isolation levels (Read Committed, Snapshot Isolation / MVCC, SSI)).
* `[ ]` **Core (19:30–21:00)**: **Graduate Systems & GPU Architecture Lab**: [John L. Hennessy & David A. Patterson, *Computer Architecture: A Quantitative Approach (6th ed)*](https://shop.elsevier.com/books/computer-architecture/hennessy/978-0-443-15406-5) — **H&P Ch 4 (§4.5–4.8)** (GPU Memory Systems & Microarchitecture: Coalescing, Shared Memory Bank Conflicts & Tensor Cores).
* `⭐ Optional / Stretch`: 21:00 onwards Weekly review & recovery.

### 🔹 Monday, Mon Nov 23 ([`Day 080`](../days/month-03/day-080-2026-11-23.md))
* `[ ]` **Core**: Implement SVD-based vector whitening transform $x_{\text{white}} = \Lambda^{-1/2} Q^T (x - \mu)$; compute hubness skewness $S_{N_k}$ before/after.
* `⭐ Optional / Stretch`: Test dimension reduction via truncated SVD ($768\text{D} \to 256\text{D}$) and measure recall retention.


### 🔹 Tuesday, Tue Nov 24 ([`Day 081`](../days/month-03/day-081-2026-11-24.md))
* `[ ]` **Core**: Build `nanobind` Python bindings exposing `HNSWIndex`, `IVFPQIndex`, `HNSWSQIndex`, and `LSMIndex` directly to Python without REST overhead.
* `⭐ Optional / Stretch`: Implement zero-copy NumPy buffer protocol in `nanobind` avoiding vector copies across the Python/C++ boundary.


### 🔹 Wednesday, Wed Nov 25 ([`Day 082`](../days/month-03/day-082-2026-11-25.md))
* `[ ]` **Core**: Optimize HNSW graph traversal using bounded flat heap and 64-bit word-aligned bitset visited table.
* `⭐ Optional / Stretch`: Benchmark branchless heap sift-down vs `std::priority_queue` in HNSW beam search.


### 🔹 Thursday, Thu Nov 26 ([`Day 083`](../days/month-03/day-083-2026-11-26.md))
* `[ ]` **Core**: Finalize `IVFPQIndex` with asymmetric ADC lookups; generate Pareto Recall@10 vs QPS curve against `faiss.IndexIVFPQ` on SIFT1M.
* `⭐ Optional / Stretch`: Measure index memory footprint comparison (secan IVFPQ vs Faiss IVFPQ).


### 🔹 Friday, Fri Nov 27 ([`Day 084`](../days/month-03/day-084-2026-11-27.md))
* `[ ]` **Core**: Implement `HNSWSQIndex` (HNSW graph routing over SQ8/SQ4 quantized vectors); generate Pareto curve vs `hnswlib` on SIFT and 768-D text. Tag `v1.0-cpu-complete`.
* `[ ]` **Core**: Compile the Block I comparison table: memory footprint, index build time, QPS, p50/p95/p99, and QPS at matched Recall@10 $\ge 0.95$, with raw manifests/results and an honest limitation for every index family.


---

## ⛔ What NOT to Overspend Time On (Week 12 Time Traps)

* ❌ **Do NOT** build REST / HTTP API endpoints in C++ (e.g. Crow / Pistache)—Python interacts with `secan` directly via zero-copy `nanobind`.
* ❌ **Do NOT** embed `onnxruntime` C++ library into `secan`—run ONNX Runtime in Python and pass raw contiguous float pointers to `secan`.
* ❌ **Do NOT** attempt full SVD matrix solvers from scratch—use Eigen or NumPy SVD for offline whitening matrices.

---

## Benchmark Close

Before the Friday article or release, save the run manifest and raw JSON/CSV, add one meaningful parameter sweep and plot, update the comparable README result row, and state the oracle result plus one evidence-backed conclusion. Record results below the noise floor as inconclusive.

## 📝 Weekend Deliverables

### ✍️ Technical Essay 12 (Drafted Friday 06:30–08:30)
* **Title**: *"Singular Value Decomposition and Composed Vector Indexes: Pareto Evaluation of IVF-PQ and HNSW-SQ vs Faiss"*
* **Target File**: `~/personal/goals/essays/essay_12.md`
* **5-Part Structure**:
  1. **Mathematical Foundation**: Core theorems, derivations, and formal definitions.
  2. **The Systems Bottleneck**: Hardware limitation (memory bandwidth, port contention, cache line splits, warp stalls).
  3. **The Engine Architecture**: Exact data structures and SIMD/CUDA kernel design implemented in `secan`.
  4. **Empirical Benchmarks**: Perf counter tables, latency percentiles ($p50/p95/p99$), and QPS curves.
  5. **Key Takeaway**: Architectural rule of thumb for production AI systems.

### 🧠 Deep Learning Track (Tue/Wed 06:30–08:30 Morning Builder)
* **Task**: **🧠 DL Builder Track (Tue/Wed, required)**: Export Week 6 InfoNCE bi-encoder with `torch.onnx.export` (dynamic batch). Run **ONNX Runtime** `InferenceSession`; max abs / cosine error vs PyTorch on a fixed batch. Emit 768-D query/doc `.fvecs` via ORT and re-ingest into `HNSWSQIndex` / `IVFPQIndex` — confirm Recall@10 matches the Week 8 Fri PyTorch path within tolerance. **No** onnxruntime C++ inside `secan` (nanobind + ORT Python is enough). ColBERT ONNX = stretch later.

### 🔬 Empirical Systems & Benchmarking Focus (Mon/Thu 06:30–08:30 Morning Builder)
* **Focus**: Sub-2-Bit In-Register SIMD Execution & Manuscript Submission Freeze
* **Workspace**: `research/2026-11-rabitq-lsm/`
* **Artifact Target**: Empirical benchmark and profiling data feeding into Friday's technical articles.


---

## ⚡  Embedding Engine Track (Week 12)
> **Weekly Focus**: *Month 3 Milestone: Multivector Late-Interaction Release*

| Day | 23:00 – 00:00 Implementation Task |
|:---|:---|
| **Mon** | Profile memory bandwidth and cache behavior during multi-vector token streaming. |
| **Tue** | Implement SIMD INT8 quantized matrix multiplication for ColBERT encoder weights. |
| **Wed** | End-to-end evaluation: raw text query -> cennan ColBERT -> secan MaxSim retrieval in <5ms. |
| **Thu** | Stress test concurrent queries across thread pools with pinned worker threads. |
| **Fri** | Milestone Release: Tag cennan v0.2-multivector-colbert and update comparative benchmarks. |
