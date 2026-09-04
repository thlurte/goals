# 🚀 Week 17 Execution Playbook

> **Theme**: Limit Theorems, LLN, CLT, Inequalities & CAGRA GPU Graphs  
> **Calendar Dates**: Mon Dec 22 – Sun Dec 28 (2026-12-22 to 2026-12-28)  
> **Parent Month Dashboard**: [Month 5 (Jan 2027)](month-05-jan.md) · **Block**: II — GPU Specialization

| | | |
|:---|:---|:---|
| [← Week 16](week-16.md) | [Month 5 (Jan 2027) Dashboard](month-05-jan.md) | [Week 18 →](week-18.md) |

---

## ⏰ Daily Operational Rhythm

```
┌──────────────────────────────┬────────────────────────────────────────────────────────────────────────┐
│ Time Slot                    │ Focus / Activity                                                       │
├──────────────────────────────┼────────────────────────────────────────────────────────────────────────┤
│ 📖 05:30 – 06:30 (60 min)    │ Systems & Architecture Deep Reading (Papers & Microarchitecture)       │
│ 🛠️ 06:30 – 08:30 (120 min)   │ Morning Builder Track (DL / Monthly Research / Technical Essays)        │
│ ☀️ Daytime                   │ Professional Workday (Full focus, zero math fatigue)                   │
│ 📚 18:30 – 20:00 (90 min)    │ Evening Reading Sanctuary (Pirsig / GEB / Dostoevsky / Wiener)         │
│ 💻 20:30 – 22:30 (2.0 hrs)   │ Night Hands-On Implementation (secan C++20 / CUDA flow state)          │
├──────────────────────────────┼────────────────────────────────────────────────────────────────────────┤
│ 📐 Saturday 09:00 – 13:00    │ Pure Mathematics Block 1 (Theory, Concepts, Derivations)               │
│ ☕ Saturday 15:00 – 16:30    │ Weekend Reading Immersion (Pirsig / GEB / Literature)                  │
│ 📐 Sunday 09:00 – 13:00      │ Pure Mathematics Block 2 (Problem Sets, Chalkboard Proofs)             │
│ 🔧 Sunday 13:00 – 14:00      │ Runtime Maintenance (limbed / ggmbed check)                            │
│ 🌌 Sunday 15:00 – 16:45      │ Penrose Sunday: The Road to Reality (1 chapter/week, visual geometry)  │
└──────────────────────────────┴────────────────────────────────────────────────────────────────────────┘
```

---

## 📅 Day-by-Day Master Timetable

| Day | Date | Daily Runbook | Systems Reading (05:30–06:30) | Morning Builder Track (06:30–08:30) | Night Hands-On C++/CUDA (20:30–23:00) |
|:---|:---|:---|:---|:---|:---|
| **Monday** | Mon Dec 22 | [`Day 113`](../days/month-05/day-113-2026-12-22.md) | Research paper: *"CAGRA: Highly Parallel Graph Construction and ANN Search for GPUs"* (NVIDIA 2024) §1–4. | **Monthly Research: Planning & Literature Synthesis** | **secan**: Design GPU graph layout: store HNSW graph adjacency in GPU memory as a fixed-degree CSR array with padding. |
| **Tuesday** | Tue Dec 23 | [`Day 114`](../days/month-05/day-114-2026-12-23.md) | CAGRA paper §5–6: Search kernel design, warp-level parallel beam search, avoiding dynamic queues on GPU. | **DL Track (Part 1): Architecture & Tensor Shapes** | **secan**: Implement **GPU graph search kernel**: each warp processes 1 query. 32 threads in warp evaluate 32 candidate neighbors in parallel. |
| **Wednesday** | Wed Dec 24 | [`Day 115`](../days/month-05/day-115-2026-12-24.md) | **CUDA-GUIDE Warp Primitives**: `__ballot_sync`, `__any_sync`, warp-local bitfield operations. | **DL Track (Part 2): Training Loop & Verification** | **secan**: Implement warp-level visited set using `__ballot_sync` bitfields. Implement warp-level top-$k$ beam with shuffle min-reduction. |
| **Thursday** | Thu Dec 25 | [`Day 116`](../days/month-05/day-116-2026-12-25.md) | **PMPP Ch 9**: Parallel Prefix Sum (Scan) for compacting candidate neighbor lists on GPU. | **Monthly Research: Sweeps & Data Logging** | **secan**: Implement multi-query parallel graph search: launch grid of warps. Benchmark throughput vs CPU HNSW. |
| **Friday** | Fri Dec 26 | [`Day 117`](../days/month-05/day-117-2026-12-26.md) | Profile GPU graph search with `ncu`: measure compute-to-memory stall ratio. | **Technical Essay: Lab-Note Drafting** | **secan**: Optimize GPU graph search: add shared memory caching for frequently visited upper-layer hub nodes. |
| **Saturday** | Sat Dec 27 | [`Day 118`](../days/month-05/day-118-2026-12-27.md) | **09:00–13:00**: Pure Math Block 1 (Theory & Derivations) | **14:00–18:00**: FREE / Rest / Buffer | Weekend Deep Work |
| **Sunday** | Sun Dec 28 | [`Day 119`](../days/month-05/day-119-2026-12-28.md) | **09:00–13:00**: Pure Math Block 2 (Problem Sets & Proofs) | **13:00–14:00**: Maintenance | Rest & Buffer |

---

## 📋 Daily Action Items & Deliverables (Week 17)

### 🔹 Monday, Mon Dec 22 ([`Day 113`](../days/month-05/day-113-2026-12-22.md))
* `[ ]` **Core**: Design GPU graph layout: store HNSW graph adjacency in GPU memory as a fixed-degree CSR array with padding.
* `⭐ Optional / Stretch`: Derive Chernoff bounds on the probability of graph search getting trapped in local minima.

### 🔹 Tuesday, Tue Dec 23 ([`Day 114`](../days/month-05/day-114-2026-12-23.md))
* `[ ]` **Core**: Implement GPU graph search kernel: 1 warp per query; 32 threads evaluate 32 candidate neighbors in parallel.
* `⭐ Optional / Stretch`: Profile warp divergence during neighbor list filtering with Nsight Compute (`ncu`).

### 🔹 Wednesday, Wed Dec 24 ([`Day 115`](../days/month-05/day-115-2026-12-24.md))
* `[ ]` **Core**: Implement warp-level visited set using `__ballot_sync` bitfields; implement warp-level top-$k$ beam with shuffle min-reduction.
* `⭐ Optional / Stretch`: Implement hash-based visited table in shared memory for graphs with degree $M > 64$.

### 🔹 Thursday, Thu Dec 25 ([`Day 116`](../days/month-05/day-116-2026-12-25.md))
* `[ ]` **Core**: Launch multi-query parallel graph search grid; benchmark QPS vs CPU HNSW implementation.
* `⭐ Optional / Stretch`: Measure the impact of thread block occupancy on memory latency hiding during random graph pointer chasing.

### 🔹 Friday, Fri Dec 26 ([`Day 117`](../days/month-05/day-117-2026-12-26.md))
* `[ ]` **Core**: Add shared memory caching for frequently visited upper-layer hub nodes to eliminate global memory roundtrips.
* `⭐ Optional / Stretch`: Compute graph degree centrality to identify top-64 hub nodes for permanent SRAM staging.

### 🔹 Saturday, Sat Dec 27 ([`Day 118`](../days/month-05/day-118-2026-12-27.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 1**: Theory, concepts, and analytical derivations (textbook chapters & core proofs).
* `[ ]` **Core (15:00–16:30)**: **Weekend Reading Sanctuary**: Literature / Philosophy deep reading.
* `⭐ Optional / Stretch`: 100% Free / Rest / Recovery buffer.
### 🔹 Sunday, Sun Dec 28 ([`Day 119`](../days/month-05/day-119-2026-12-28.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 2**: Advanced theorems, problem sets, and chalkboard proof defense.
* `[ ]` **Core (13:00–14:00)**: **Runtime Maintenance**: Quick 30–60 min check for `limbed` / `ggmbed` (`embed-runtimes`).
* `[ ]` **Core (15:00–16:45)**: **Penrose Sunday**: *The Road to Reality* (1 chapter/week, visual geometry focus).
---

## ⛔ What NOT to Overspend Time On (Week 17 Time Traps)

* ❌ **Do NOT** implement dynamic-degree variable-length CSR arrays on GPU—pad neighbor lists to fixed max degree $M$ for uniform warp loads.
* ❌ **Do NOT** maintain per-thread dynamic candidate queues in global memory—warp-cooperative bitfield visited masks eliminate queue allocation.
* ❌ **Do NOT** write measure-theoretic probability proofs for SLLN—grasp the Chebyshev proof for WLLN and move on.

---

## 📝 Weekend Deliverables

### ✍️ Technical Essay 17 (Saturday 09:00–13:00)
* **Title**: *"Warp-Scale Graph Traversal: Overcoming Random Memory Access Bottlenecks in GPU CAGRA"*
* **Target File**: `~/personal/goals/essays/essay_17.md`
* **5-Part Structure**:
  1. **Mathematical Foundation**: Core theorems, derivations, and formal definitions.
  2. **The Systems Bottleneck**: Hardware limitation (memory bandwidth, port contention, cache line splits, warp stalls).
  3. **The Engine Architecture**: Exact data structures and SIMD/CUDA kernel design implemented in `secan`.
  4. **Empirical Benchmarks**: Perf counter tables, latency percentiles ($p50/p95/p99$), and QPS curves.
  5. **Key Takeaway**: Architectural rule of thumb for production AI systems.

### 🧠 Deep Learning Track (Tue/Wed 06:30–08:30 Morning Builder)
* **Task**: 

### 🔬 Monthly Research Milestone (FlashMaxSim Milestone 2 — Mon/Thu 06:30–08:30 Morning Builder)
* **Paper**: *"The Online Max Reduction Invariant & In-SRAM Accumulation Mechanics"*
* **Workspace**: `research/2027-01-cagra-warp-search/`
* **Publish Deadline**: **Sun Jan 31**
