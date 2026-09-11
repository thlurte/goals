# 🚀 Week 08 Execution Playbook

> **Theme**: Graph Theory, The Hubness Phenomenon & HNSW Core  
> **Calendar Dates**: Sat Oct 24 – Fri Oct 30 (2026-10-24 to 2026-10-30)
> **Parent Month Dashboard**: [Month 2 (Oct 2026)](month-02-oct.md) · **Block**: I — Vector Search Engine

| | | |
|:---|:---|:---|
| [← Week 07](week-07.md) | [Month 2 (Oct 2026) Dashboard](month-02-oct.md) | [Week 09 →](week-09.md) |

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
| **Saturday** | Sat Oct 24 | [`Day 050`](../days/month-02/day-050-2026-10-24.md) | **09:00–13:00**: Pure Math Block 1 (Theory & Derivations) | **15:00–16:30**: Literature Sanctuary | **18:00–19:30**: Information Theory (Cover & Thomas) · **19:30–21:00**: Thought Leadership (Richard W. Hamming) · **21:00+**: Free / Rest|
| **Sunday** | Sun Oct 25 | [`Day 051`](../days/month-02/day-051-2026-10-25.md) | **09:00–13:00**: Pure Math Block 2 (Problem Sets & Proofs) | **13:00**: Maint · **15:00**: Penrose | **18:00–19:30**: Dist Systems (DDIA Ch 7) · **19:30–21:00**: Systems Lab (Pikus Ch 7–9) |
| **Monday** | Mon Oct 26 | [`Day 052`](../days/month-02/day-052-2026-10-26.md) | Research paper: *"Efficient and Robust ANN Search Using HNSW Graphs"* (Malkov & Yashunin 2020) §1–3. | **Hardware Profiling & Benchmark Sweeps** | **secan**: Implement `HNSWIndex` data structures: flat CSR adjacency (`neighbors[]` + `offsets[]`), node struct, entry point. |
| **Tuesday** | Tue Oct 27 | [`Day 053`](../days/month-02/day-053-2026-10-27.md) | HNSW paper §4–5: Algorithm 4 (heuristic neighbor selection), level multiplier $m_L$, parameter tuning ($M, ef$). | **DL Track (Part 1): Architecture & Tensor Shapes** | **secan**: Implement HNSW `insert()`: exponential level assignment, greedy descent, multi-layer neighbor connection. |
| **Wednesday** | Wed Oct 28 | [`Day 054`](../days/month-02/day-054-2026-10-28.md) | **PIKUS Ch 7**: Concurrent data structures, cache-friendly priority queues, memory allocation in graphs. | **DL Track (Part 2): Training Loop & Verification** | **secan**: Implement HNSW `search()`: beam search with visited-set. Implement Algorithm 4 diverse neighbor selection. |
| **Thursday** | Thu Oct 29 | [`Day 055`](../days/month-02/day-055-2026-10-29.md) | **AGNER Ch 7.12–7.13 & Ch 7.5**: Branch prediction in graph traversal, branchless heap sift-down (**prep for Week 12 Wed**). | **DL / Vector Retrieval Integration & Profiling** | **secan**: Correctness harness: Recall@10 vs exact on SIFT subset. Do **not** optimize heaps yet → Week 12 Wed. |
| **Friday** | Fri Oct 30 | [`Day 056`](../days/month-02/day-056-2026-10-30.md) | **CSAPP §5.14**: Profiling graph traversal bottlenecks with `perf record`. | **Weekly Technical Article: Drafting & Publishing** | **secan (required)**: Ingest **768-D text** `.fvecs` into HNSW; plot **Recall@10 vs QPS**. SIFT remains kernel bench; this is the text product bench. Tag `v0.3-hnsw`. |

---

## 📋 Daily Action Items & Deliverables (Week 08)

### 🔹 Saturday, Sat Oct 24 ([`Day 050`](../days/month-02/day-050-2026-10-24.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 1**: Theory, concepts, and analytical derivations (textbook chapters & core proofs).
* `[ ]` **Core (15:00–16:30)**: **Weekend Reading Sanctuary**: Literature / Philosophy deep reading.
* `[ ]` **Core (16:30–18:00)**: **Physical Break & Mental Decompression**: Walk, tea, and recovery.
* `[ ]` **Core (18:00–19:30)**: **Information Theory Track**: Thomas M. Cover & Joy A. Thomas, *Elements of Information Theory* — **Ch 7.7–7.13** (Jointly Typical Sequences & Shannon's Channel Coding Theorem).
* `[ ]` **Core (19:30–21:00)**: **Thought Leadership Masterclass**: Richard W. Hamming, *The Art of Doing Science and Engineering* — **Ch 20–21, 27–32: Taste & You and Your Research** (Creativity, Experts, Systems Engineering, 'You Get What You Measure', and 'You and Your Research').
* `⭐ Optional / Stretch`: 21:00 onwards 100% Free / Rest.

### 🔹 Sunday, Sun Oct 25 ([`Day 051`](../days/month-02/day-051-2026-10-25.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 2**: Advanced theorems, problem sets, and chalkboard proof defense.
* `[ ]` **Core (13:00–14:00)**: **Runtime Maintenance**: Quick 30–60 min check for `limbed` / `ggmbed` (`embed-runtimes`).
* `[ ]` **Core (15:00–16:45)**: **Penrose Sunday**: *The Road to Reality* (1 chapter/week, visual geometry focus).
* `[ ]` **Core (18:00–19:30)**: **Distributed Systems & IR Track**: **DDIA Ch 7** (Transactions: ACID, Isolation Levels, Snapshot Isolation, 2PL & Serializability).
* `[ ]` **Core (19:30–21:00)**: **Graduate Systems & GPU Architecture Lab**: Microarchitecture analysis and CUDA exercises in **Pikus Ch 7–9** (Lock-free ring buffers, cache-line false sharing elimination & memory fences).
* `⭐ Optional / Stretch`: 21:00 onwards Weekly review & recovery.

### 🔹 Monday, Mon Oct 26 ([`Day 052`](../days/month-02/day-052-2026-10-26.md))
* `[ ]` **Core**: Implement `HNSWIndex` core memory layout with flat CSR adjacency array (`neighbors[]` and `offsets[]`).
* `⭐ Optional / Stretch`: Profile memory fragmentation of dynamic node vectors `std::vector<std::vector<uint32_t>>` vs flat contiguous CSR buffer.


### 🔹 Tuesday, Tue Oct 27 ([`Day 053`](../days/month-02/day-053-2026-10-27.md))
* `[ ]` **Core**: Implement HNSW `insert()` with exponential random level generator and greedy multi-layer descent.
* `⭐ Optional / Stretch`: Compute degree distribution histogram across all nodes to verify graph connectivity properties.


### 🔹 Wednesday, Wed Oct 28 ([`Day 054`](../days/month-02/day-054-2026-10-28.md))
* `[ ]` **Core**: Implement HNSW `search()` (greedy descent on upper layers, $efSearch$ beam search on layer 0); implement Algorithm 4 diverse neighbor heuristic.
* `⭐ Optional / Stretch`: Measure the impact of Algorithm 4 neighbor diversity heuristic on Recall@10 vs simple nearest-neighbor graph edges.


### 🔹 Thursday, Thu Oct 29 ([`Day 055`](../days/month-02/day-055-2026-10-29.md))
* `[ ]` **Core**: Construct correctness test harness validating Recall@10 on 10,000 queries on SIFT subset.
* `⭐ Optional / Stretch`: Measure the correlation between graph hop count and Euclidean distance to ground-truth neighbor.


### 🔹 Friday, Fri Oct 30 ([`Day 056`](../days/month-02/day-056-2026-10-30.md))
* `[ ]` **Core**: Ingest golden 768-D text embeddings (`.fvecs` pre-staged in `data/text768/`) into HNSW; plot Recall@10 vs QPS curve across $efSearch \in [10, 200]$. (Evaluate custom Week 6 DL export as a secondary comparative dataset). Tag `v0.3-hnsw`.
* `⭐ Optional / Stretch`: Calculate empirical hubness skewness $S_{N_k}$ on the 768-D text dataset and identify top-10 hub nodes.


---

## ⛔ What NOT to Overspend Time On (Week 08 Time Traps)

* ❌ **Do NOT** attempt complex lock-free concurrent HNSW graph mutations this week—focus strictly on single-threaded algorithmic correctness first.
* ❌ **Do NOT** premature optimize the priority queues—standard `std::priority_queue` is fine (bounded flat heaps are added in Week 12).
* ❌ **Do NOT** implement SVD whitening transforms this week—whitening requires full Linear Algebra SVD (Week 12).

---

## Benchmark Close

Before the Friday article or release, save the run manifest and raw JSON/CSV, add one meaningful parameter sweep and plot, update the comparable README result row, and state the oracle result plus one evidence-backed conclusion. Record results below the noise floor as inconclusive.

## 📝 Weekend Deliverables

### ✍️ Technical Essay 08 (Drafted Friday 06:30–08:30)
* **Title**: *"Graph Laplacians, Hubness Skewness, and Navigable Small-World Routing: Building HNSW from Scratch"*
* **Target File**: `~/personal/goals/essays/essay_08.md`
* **5-Part Structure**:
  1. **Mathematical Foundation**: Core theorems, derivations, and formal definitions.
  2. **The Systems Bottleneck**: Hardware limitation (memory bandwidth, port contention, cache line splits, warp stalls).
  3. **The Engine Architecture**: Exact data structures and SIMD/CUDA kernel design implemented in `secan`.
  4. **Empirical Benchmarks**: Perf counter tables, latency percentiles ($p50/p95/p99$), and QPS curves.
  5. **Key Takeaway**: Architectural rule of thumb for production AI systems.

### 🧠 Deep Learning Track (Tue/Wed 06:30–08:30 Morning Builder)
* **Task**: 

### 🔬 Empirical Systems & Benchmarking Focus (Mon/Thu 06:30–08:30 Morning Builder)
* **Focus**: Geometry-Aware Anisotropic Polar Quantization: The Adaptive Ellipsoidal Lattice & Unbiased QJL Proof
* **Workspace**: `research/2026-10-anisotropic-quantization/`
* **Artifact Target**: Empirical benchmark and profiling data feeding into Friday's technical articles.
