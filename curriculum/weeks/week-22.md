# 🚀 Week 22 Execution Playbook

> **Theme**: Production Hardening — ACORN, Tombstones & NUMA  
> **Calendar Dates**: Sat Jan 30 – Fri Feb 5 (2027-01-30 to 2027-02-05)
> **Parent Month Dashboard**: [Month 6 (Feb 2027)](month-06-feb.md) · **Block**: II — GPU Specialization

| | | |
|:---|:---|:---|
| [← Week 21](week-21.md) | [Month 6 (Feb 2027) Dashboard](month-06-feb.md) | [Week 23 →](week-23.md) |

---

## ⏰ Daily Operational Rhythm

```
┌──────────────────────────────┬────────────────────────────────────────────────────────────────────────┐
│ Time Slot                    │ Focus / Activity                                                       │
├──────────────────────────────┼────────────────────────────────────────────────────────────────────────┤
│ 📐 Saturday 09:00 – 13:00    │ Pure Mathematics Block 1 (Theory, Concepts, Derivations)               │
│ ☕ Saturday 15:00 – 16:30    │ Weekend Reading Immersion (Pirsig / GEB / Literature)                  │
│ 📐 Sunday 09:00 – 13:00      │ Pure Mathematics Block 2 (Problem Sets, Chalkboard Proofs)             │
│ 🔧 Sunday 13:00 – 14:00      │ Runtime Maintenance (limbed / ggmbed check)                            │
│ 🌌 Sunday 15:00 – 16:45      │ Penrose Sunday: The Road to Reality (1 chapter/week, visual geometry)  │
├──────────────────────────────┼────────────────────────────────────────────────────────────────────────┤
│ 📖 Mon–Fri 05:30 – 06:30     │ Systems & Architecture Deep Reading (Papers & Microarchitecture)       │
│ 🛠️ Mon–Fri 06:30 – 08:30     │ Morning Builder Track (DL / Monthly Research / Technical Essays)        │
│ ☀️ Mon–Fri Daytime           │ Professional Workday (Full focus, zero math fatigue)                   │
│ 📚 Mon–Fri 18:30 – 20:00     │ Evening Reading Sanctuary (Pirsig / GEB / Dostoevsky / Wiener)         │
│ 💻 Mon–Fri 20:30 – 22:30     │ Night Hands-On Implementation (secan C++20 / CUDA flow state)          │
└──────────────────────────────┴────────────────────────────────────────────────────────────────────────┘
```

---

## 📅 Day-by-Day Master Timetable

| Day | Date | Daily Runbook | Systems Reading (05:30–06:30) | Morning Builder Track (06:30–08:30) | Night Hands-On C++/CUDA (20:30–23:00) |
|:---|:---|:---|:---|:---|:---|
| **Saturday** | Sat Jan 30 | [`Day 148`](../days/month-06/day-148-2027-01-30.md) | **09:00–13:00**: Pure Math Block 1 (Theory & Derivations) | **14:00–18:00**: FREE / Rest / Buffer | Weekend Deep Work |
| **Sunday** | Sun Jan 31 | [`Day 149`](../days/month-06/day-149-2027-01-31.md) | **09:00–13:00**: Pure Math Block 2 (Problem Sets & Proofs) | **13:00–14:00**: Maintenance | Rest & Buffer |
| **Monday** | Mon Feb 1 | [`Day 150`](../days/month-06/day-150-2027-02-01.md) | Payload/B-tree + ANN; pre- vs post-filter. | **Monthly Research: Planning & Literature Synthesis** | **secan (required)**: Payload index (B-tree or sorted ids) + **pre-filter** candidate set; **post-filter** HNSW; plot recall vs selectivity. |
| **Tuesday** | Tue Feb 2 | [`Day 151`](../days/month-06/day-151-2027-02-02.md) | ACORN paper §1–6. | **DL Track (Part 1): Architecture & Tensor Shapes** | **secan**: ACORN-style filtered graph search; compare to Mon's pre/post. |
| **Wednesday** | Wed Feb 3 | [`Day 152`](../days/month-06/day-152-2027-02-03.md) | Lock-free bitset / graph mutation. | **DL Track (Part 2): Training Loop & Verification** | **secan**: Tombstones + vacuum rewires. |
| **Thursday** | Thu Feb 4 | [`Day 153`](../days/month-06/day-153-2027-02-04.md) | `libnuma`; DiskANN under NUMA. | **Monthly Research: Sweeps & Data Logging** | **secan**: NUMA pin; re-bench. |
| **Friday** | Fri Feb 5 | [`Day 154`](../days/month-06/day-154-2027-02-05.md) | Production checklist. | **Technical Essay: Lab-Note Drafting** | **secan (required)**: **Range filter** (`payload < x`) on pre-filter path; smoke tests. Tag `v1.5-production`. |

---

## 📋 Daily Action Items & Deliverables (Week 22)

### 🔹 Saturday, Sat Jan 30 ([`Day 148`](../days/month-06/day-148-2027-01-30.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 1**: Theory, concepts, and analytical derivations (textbook chapters & core proofs).
* `[ ]` **Core (15:00–16:30)**: **Weekend Reading Sanctuary**: Literature / Philosophy deep reading.
* `⭐ Optional / Stretch`: 100% Free / Rest / Recovery buffer.

### 🔹 Sunday, Sun Jan 31 ([`Day 149`](../days/month-06/day-149-2027-01-31.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 2**: Advanced theorems, problem sets, and chalkboard proof defense.
* `[ ]` **Core (13:00–14:00)**: **Runtime Maintenance**: Quick 30–60 min check for `limbed` / `ggmbed` (`embed-runtimes`).
* `[ ]` **Core (15:00–16:45)**: **Penrose Sunday**: *The Road to Reality* (1 chapter/week, visual geometry focus).

### 🔹 Monday, Mon Feb 1 ([`Day 150`](../days/month-06/day-150-2027-02-01.md))
* `[ ]` **Core**: Implement metadata payload index (B-tree / sorted IDs); compare pre-filtering vs post-filtering; reproduce recall collapse at selectivity $< 1\%$.
* `⭐ Optional / Stretch`: Derive the exact probability of graph search disconnection under Bernoulli predicate selection $p$.


### 🔹 Tuesday, Tue Feb 2 ([`Day 151`](../days/month-06/day-151-2027-02-02.md))
* `[ ]` **Core**: Implement ACORN $N$-hop predicate-aware graph routing traversing predicate-satisfying subgraphs.
* `⭐ Optional / Stretch`: Measure ACORN Recall@10 retention across low-selectivity regimes ($0.1\%$ to $5\%$) vs standard HNSW.


### 🔹 Wednesday, Wed Feb 3 ([`Day 152`](../days/month-06/day-152-2027-02-03.md))
* `[ ]` **Core**: Implement soft vector deletion via atomic bitset tombstones; implement background graph vacuum rewiring neighbor edges.
* `⭐ Optional / Stretch`: Measure graph routing degradation as tombstone percentage increases from 0% to 30% before vacuuming.


### 🔹 Thursday, Thu Feb 4 ([`Day 153`](../days/month-06/day-153-2027-02-04.md))
* `[ ]` **Core**: Pin memory allocations and worker threads to specific NUMA nodes using `libnuma` (`numa_alloc_onnode`).
* `⭐ Optional / Stretch`: Measure cross-socket QPI/UPI interconnect traffic during high-concurrency multi-threaded queries.


### 🔹 Friday, Fri Feb 5 ([`Day 154`](../days/month-06/day-154-2027-02-05.md))
* `[ ]` **Core**: Implement numeric range filtering (`timestamp >= t0 AND price < p1`) integrated into graph traversal. Tag `v1.5-production`.
* `⭐ Optional / Stretch`: Implement SIMD Roaring Bitmaps with 16-bit containerized chunks and AVX2/AVX-512 bitwise AND / POPCNT kernels for high-throughput ($>30\text{ GB/s}$) multi-predicate metadata filtering.


---

## ⛔ What NOT to Overspend Time On (Week 22 Time Traps)

* ❌ **Do NOT** implement full SQL query parsing—simple metadata attribute dictionaries (`key == value`, `key < threshold`) cover 100% of filtering needs.
* ❌ **Do NOT** rebuild the entire HNSW graph on every deletion—use atomic bitset tombstones and periodic asynchronous vacuuming.
* ❌ **Do NOT** worry if your development machine is single-socket—simulate NUMA policies with `numactl --interleave` or `numactl --cpunodebind`.

---

## 📝 Weekend Deliverables

### ✍️ Technical Essay 22 (Saturday 09:00–13:00)
* **Title**: *"Graph Disconnection and Selectivity Cliffs: ACORN Predicate Subgraphs vs Post-Filtering"*
* **Target File**: `~/personal/goals/essays/essay_22.md`
* **5-Part Structure**:
  1. **Mathematical Foundation**: Core theorems, derivations, and formal definitions.
  2. **The Systems Bottleneck**: Hardware limitation (memory bandwidth, port contention, cache line splits, warp stalls).
  3. **The Engine Architecture**: Exact data structures and SIMD/CUDA kernel design implemented in `secan`.
  4. **Empirical Benchmarks**: Perf counter tables, latency percentiles ($p50/p95/p99$), and QPS curves.
  5. **Key Takeaway**: Architectural rule of thumb for production AI systems.

### 🧠 Deep Learning Track (Tue/Wed 06:30–08:30 Morning Builder)
* **Task**: 

### 🔬 Monthly Research Milestone (FlashMaxSim Milestone 3 — Mon/Thu 06:30–08:30 Morning Builder)
* **Paper**: *"Bare-Metal CUTLASS Implementation with Hopper/Blackwell TMA & Warp Specialization"*
* **Workspace**: `research/2027-02-predicate-aware-graphs/`
* **Publish Deadline**: **Sun Feb 28**
