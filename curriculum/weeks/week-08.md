# 🚀 Week 08 Execution Playbook

> **Theme**: Graph Theory, The Hubness Phenomenon & HNSW Core  
> **Calendar Dates**: Mon Oct 20 – Sun Oct 26 (2026-10-20 to 2026-10-26)  
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
│ 📖 05:30 – 06:30 (60 min)    │ Systems & Architecture Deep Reading (Papers & Microarchitecture)       │
│ 🛠️ 06:30 – 08:30 (120 min)   │ Morning Builder Track (DL / Monthly Research / Technical Essays)        │
│ ☀️ Daytime                   │ Professional Workday (Full focus, zero math fatigue)                   │
│ 💻 20:30 – 23:00 (2.5 hrs)   │ Night Hands-On Implementation (secan C++20 / CUDA flow state)          │
├──────────────────────────────┼────────────────────────────────────────────────────────────────────────┤
│ 📐 Saturday 09:00 – 13:00    │ Pure Mathematics Block 1 (Theory, Concepts, Derivations)               │
│ 🧘 Saturday 14:00 – 18:00    │ 100% FREE / Rest / Personal Time / Buffer                              │
│ 📐 Sunday 09:00 – 13:00      │ Pure Mathematics Block 2 (Problem Sets, Chalkboard Proofs)             │
│ 🔧 Sunday 13:00 – 14:00      │ Runtime Maintenance (limbed / ggmbed check)                            │
│ 🧘 Sunday 14:00 – 18:00      │ 100% FREE / Rest / Personal Time / Buffer                              │
└──────────────────────────────┴────────────────────────────────────────────────────────────────────────┘
```

---

## 📅 Day-by-Day Master Timetable

| Day | Date | Daily Runbook | Systems Reading (05:30–06:30) | Morning Builder Track (06:30–08:30) | Night Hands-On C++/CUDA (20:30–23:00) |
|:---|:---|:---|:---|:---|:---|
| **Monday** | Mon Oct 20 | [`Day 050`](../days/month-02/day-050-2026-10-20.md) | Research paper: *"Efficient and Robust ANN Search Using HNSW Graphs"* (Malkov & Yashunin 2020) §1–3. | **Monthly Research: Planning & Literature Synthesis** | **secan**: Implement `HNSWIndex` data structures: flat CSR adjacency (`neighbors[]` + `offsets[]`), node struct, entry point. |
| **Tuesday** | Tue Oct 21 | [`Day 051`](../days/month-02/day-051-2026-10-21.md) | HNSW paper §4–5: Algorithm 4 (heuristic neighbor selection), level multiplier $m_L$, parameter tuning ($M, ef$). | **DL Track (Part 1): Architecture & Tensor Shapes** | **secan**: Implement HNSW `insert()`: exponential level assignment, greedy descent, multi-layer neighbor connection. |
| **Wednesday** | Wed Oct 22 | [`Day 052`](../days/month-02/day-052-2026-10-22.md) | **PIKUS Ch 7**: Concurrent data structures, cache-friendly priority queues, memory allocation in graphs. | **DL Track (Part 2): Training Loop & Verification** | **secan**: Implement HNSW `search()`: beam search with visited-set. Implement Algorithm 4 diverse neighbor selection. |
| **Thursday** | Thu Oct 23 | [`Day 053`](../days/month-02/day-053-2026-10-23.md) | **AGNER Ch 7.12–7.13 & Ch 7.5**: Branch prediction in graph traversal, branchless heap sift-down (**prep for Week 12 Wed**). | **Monthly Research: Sweeps & Data Logging** | **secan**: Correctness harness: Recall@10 vs exact on SIFT subset. Do **not** optimize heaps yet → Week 12 Wed. |
| **Friday** | Fri Oct 24 | [`Day 054`](../days/month-02/day-054-2026-10-24.md) | **CSAPP §5.14**: Profiling graph traversal bottlenecks with `perf record`. | **Technical Essay: Lab-Note Drafting** | **secan (required)**: Ingest **768-D text** `.fvecs` into HNSW; plot **Recall@10 vs QPS**. SIFT remains kernel bench; this is the text product bench. Tag `v0.3-hnsw`. |
| **Saturday** | Sat Oct 25 | [`Day 055`](../days/month-02/day-055-2026-10-25.md) | **09:00–13:00**: Pure Math Block 1 (Theory & Derivations) | **14:00–18:00**: FREE / Rest / Buffer | Weekend Deep Work |
| **Sunday** | Sun Oct 26 | [`Day 056`](../days/month-02/day-056-2026-10-26.md) | **09:00–13:00**: Pure Math Block 2 (Problem Sets & Proofs) | **13:00–14:00**: Maintenance | Rest & Buffer |

---

## 📋 Daily Action Items & Deliverables (Week 08)

### 🔹 Monday, Mon Oct 20 ([`Day 050`](../days/month-02/day-050-2026-10-20.md))
* `[ ]` **Core**: Implement `HNSWIndex` core memory layout with flat CSR adjacency array (`neighbors[]` and `offsets[]`).
* `⭐ Optional / Stretch`: Profile memory fragmentation of dynamic node vectors `std::vector<std::vector<uint32_t>>` vs flat contiguous CSR buffer.

### 🔹 Tuesday, Tue Oct 21 ([`Day 051`](../days/month-02/day-051-2026-10-21.md))
* `[ ]` **Core**: Implement HNSW `insert()` with exponential random level generator and greedy multi-layer descent.
* `⭐ Optional / Stretch`: Compute degree distribution histogram across all nodes to verify graph connectivity properties.

### 🔹 Wednesday, Wed Oct 22 ([`Day 052`](../days/month-02/day-052-2026-10-22.md))
* `[ ]` **Core**: Implement HNSW `search()` (greedy descent on upper layers, $efSearch$ beam search on layer 0); implement Algorithm 4 diverse neighbor heuristic.
* `⭐ Optional / Stretch`: Measure the impact of Algorithm 4 neighbor diversity heuristic on Recall@10 vs simple nearest-neighbor graph edges.

### 🔹 Thursday, Thu Oct 23 ([`Day 053`](../days/month-02/day-053-2026-10-23.md))
* `[ ]` **Core**: Construct correctness test harness validating Recall@10 on 10,000 queries on SIFT subset.
* `⭐ Optional / Stretch`: Measure the correlation between graph hop count and Euclidean distance to ground-truth neighbor.

### 🔹 Friday, Fri Oct 24 ([`Day 054`](../days/month-02/day-054-2026-10-24.md))
* `[ ]` **Core**: Ingest golden 768-D text embeddings (`.fvecs` pre-staged in `data/text768/`) into HNSW; plot Recall@10 vs QPS curve across $efSearch \in [10, 200]$. (Evaluate custom Week 6 DL export as a secondary comparative dataset). Tag `v0.3-hnsw`.
* `⭐ Optional / Stretch`: Calculate empirical hubness skewness $S_{N_k}$ on the 768-D text dataset and identify top-10 hub nodes.

### 🔹 Saturday, Sat Oct 25 ([`Day 055`](../days/month-02/day-055-2026-10-25.md))
* `[ ]` **Core (09:00–13:00)**: Write and ship **Technical Essay 8**: *"Graph Laplacians, Hubness Skewness, and Navigable Small-World Routing: Building HNSW from Scratch"* to `goals/essays/essay_08.md`.
* `[ ]` **Core (14:00–18:00)**: Execute Saturday Deep Learning from Scratch track ().
* `⭐ Optional / Stretch`: Run automated test suite validating PyTorch numerical gradient and attention equivalence.

### 🔹 Sunday, Sun Oct 26 ([`Day 056`](../days/month-02/day-056-2026-10-26.md))
* `[ ]` **Core (09:00–13:00)**: Execute Monthly Research Milestone for Month 2 (`research/2026-10-anisotropy-hubness-bits/`): run empirical benchmarks and record data tables.
* `⭐ Optional / Stretch`: Draft / update section figures and experimental limitations.

---

## ⛔ What NOT to Overspend Time On (Week 08 Time Traps)

* ❌ **Do NOT** attempt complex lock-free concurrent HNSW graph mutations this week—focus strictly on single-threaded algorithmic correctness first.
* ❌ **Do NOT** premature optimize the priority queues—standard `std::priority_queue` is fine (bounded flat heaps are added in Week 12).
* ❌ **Do NOT** implement SVD whitening transforms this week—whitening requires full Linear Algebra SVD (Week 12).

---

## 📝 Weekend Deliverables

### ✍️ Technical Essay 08 (Saturday 09:00–13:00)
* **Title**: *"Graph Laplacians, Hubness Skewness, and Navigable Small-World Routing: Building HNSW from Scratch"*
* **Target File**: `~/personal/goals/essays/essay_08.md`
* **5-Part Structure**:
  1. **Mathematical Foundation**: Core theorems, derivations, and formal definitions.
  2. **The Systems Bottleneck**: Hardware limitation (memory bandwidth, port contention, cache line splits, warp stalls).
  3. **The Engine Architecture**: Exact data structures and SIMD/CUDA kernel design implemented in `secan`.
  4. **Empirical Benchmarks**: Perf counter tables, latency percentiles ($p50/p95/p99$), and QPS curves.
  5. **Key Takeaway**: Architectural rule of thumb for production AI systems.

### 🧠 Deep Learning Track (Saturday 14:00–18:00)
* **Task**: 

### 🔬 Monthly Research Milestone (Sunday 09:00–13:00)
* **Paper**: *"Anisotropy-Aware Vector Quantization: Dissecting the Interplay Between Embedding Cones, Hubness, and Quantization Loss Functions"*
* **Workspace**: `research/2026-10-anisotropy-hubness-bits/`
* **Publish Deadline**: **Sun Oct 25**
