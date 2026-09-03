# 🚀 Week 22 Execution Playbook

> **Theme**: Production Hardening — ACORN, Tombstones & NUMA  
> **Calendar Dates**: Mon Jan 26 – Sun Feb 1 (2027-01-26 to 2027-02-01)  
> **Parent Month Dashboard**: [Month 6 (Feb 2027)](month-06-feb.md) · **Block**: II — GPU Specialization

| | | |
|:---|:---|:---|
| [← Week 21](week-21.md) | [Month 6 (Feb 2027) Dashboard](month-06-feb.md) | [Week 23 →](week-23.md) |

---

## ⏰ Daily Operational Rhythm

```
┌──────────────────────────────┬────────────────────────────────────────────────────────────────────────┐
│ Time Block                   │ Focus Area                                                             │
├──────────────────────────────┼────────────────────────────────────────────────────────────────────────┤
│ 🌅 06:00 – 07:30 (90 min)    │ Pure Mathematics (Pencil, paper, theorems, derivations & proofs)       │
│ 📖 07:30 – 08:30 (60 min)    │ Systems & Architecture Deep Reading (Hardware mechanics & papers)      │
│ ☀️ Daytime                   │ Subconscious Incubation Period (Diffuse thinking)                      │
│ 💻 20:30 – 23:00 (2.5 hrs)   │ Night Hands-On Implementation (secan C++20 / CUDA flow state)          │
├──────────────────────────────┼────────────────────────────────────────────────────────────────────────┤
│ 📝 Saturday 09:00 – 13:00    │ Weekly Long-Form Technical Essay / Lab Note                            │
│ 🧠 Saturday 14:00 – 18:00    │ Deep Learning from Scratch Track (PyTorch / uv)                        │
│ 🔬 Sunday 09:00 – 13:00      │ Monthly Research Paper Experiments & Drafting                          │
└──────────────────────────────┴────────────────────────────────────────────────────────────────────────┘
```

---

## 📅 Day-by-Day Master Timetable

| Day | Date | Daily Runbook | Pure Mathematics (90 min) | Systems / Architecture Reading (45-60 min) | Night Hands-On C++/CUDA (2.5 hrs) |
|:---|:---|:---|:---|:---|:---|
| **Monday** | Mon Jan 26 | [`Day 148`](../days/month-06/day-148-2027-01-26.md) | Filter selectivity $P(\text{pass})$; **post-filter recall collapse**. | Payload/B-tree + ANN; pre- vs post-filter. | **secan (required)**: Payload index (B-tree or sorted ids) + **pre-filter** candidate set; **post-filter** HNSW; plot recall vs selectivity. |
| **Tuesday** | Tue Jan 27 | [`Day 149`](../days/month-06/day-149-2027-01-27.md) | ACORN $N$-hop vs connectivity under filters. | ACORN paper §1–6. | **secan**: ACORN-style filtered graph search; compare to Mon's pre/post. |
| **Wednesday** | Wed Jan 28 | [`Day 150`](../days/month-06/day-150-2027-01-28.md) | Tombstone amortization vs vacuum. | Lock-free bitset / graph mutation. | **secan**: Tombstones + vacuum rewires. |
| **Thursday** | Thu Jan 29 | [`Day 151`](../days/month-06/day-151-2027-01-29.md) | NUMA / PCIe budget. | `libnuma`; DiskANN under NUMA. | **secan**: NUMA pin; re-bench. |
| **Friday** | Fri Jan 30 | [`Day 152`](../days/month-06/day-152-2027-01-30.md) | Range predicates vs boolean bitmaps. | Production checklist. | **secan (required)**: **Range filter** (`payload < x`) on pre-filter path; smoke tests. Tag `v1.5-production`. |
| **Saturday** | Sat Jan 31 | [`Day 153`](../days/month-06/day-153-2027-01-31.md) | **09:00–13:00**: Essay 22 | **14:00–18:00**: Deep Learning Track | Deep Learning from Scratch (uv/PyTorch) |
| **Sunday** | Sun Feb 1 | [`Day 154`](../days/month-06/day-154-2027-02-01.md) | **09:00–13:00**: Monthly Research | Research Experimentation | Rest & Subconscious Incubation |

---

## 📋 Daily Action Items & Deliverables (Week 22)

### 🔹 Monday, Mon Jan 26 ([`Day 148`](../days/month-06/day-148-2027-01-26.md))
* `[ ]` **Core**: Implement metadata payload index (B-tree / sorted IDs); compare pre-filtering vs post-filtering; reproduce recall collapse at selectivity $< 1\%$.
* `⭐ Optional / Stretch`: Derive the exact probability of graph search disconnection under Bernoulli predicate selection $p$.

### 🔹 Tuesday, Tue Jan 27 ([`Day 149`](../days/month-06/day-149-2027-01-27.md))
* `[ ]` **Core**: Implement ACORN $N$-hop predicate-aware graph routing traversing predicate-satisfying subgraphs.
* `⭐ Optional / Stretch`: Measure ACORN Recall@10 retention across low-selectivity regimes ($0.1\%$ to $5\%$) vs standard HNSW.

### 🔹 Wednesday, Wed Jan 28 ([`Day 150`](../days/month-06/day-150-2027-01-28.md))
* `[ ]` **Core**: Implement soft vector deletion via atomic bitset tombstones; implement background graph vacuum rewiring neighbor edges.
* `⭐ Optional / Stretch`: Measure graph routing degradation as tombstone percentage increases from 0% to 30% before vacuuming.

### 🔹 Thursday, Thu Jan 29 ([`Day 151`](../days/month-06/day-151-2027-01-29.md))
* `[ ]` **Core**: Pin memory allocations and worker threads to specific NUMA nodes using `libnuma` (`numa_alloc_onnode`).
* `⭐ Optional / Stretch`: Measure cross-socket QPI/UPI interconnect traffic during high-concurrency multi-threaded queries.

### 🔹 Friday, Fri Jan 30 ([`Day 152`](../days/month-06/day-152-2027-01-30.md))
* `[ ]` **Core**: Implement numeric range filtering (`timestamp >= t0 AND price < p1`) integrated into graph traversal. Tag `v1.5-production`.
* `⭐ Optional / Stretch`: Implement SIMD Roaring Bitmaps with 16-bit containerized chunks and AVX2/AVX-512 bitwise AND / POPCNT kernels for high-throughput ($>30\text{ GB/s}$) multi-predicate metadata filtering.

### 🔹 Saturday, Sat Jan 31 ([`Day 153`](../days/month-06/day-153-2027-01-31.md))
* `[ ]` **Core (09:00–13:00)**: Write and ship **Technical Essay 22**: *"Graph Disconnection and Selectivity Cliffs: ACORN Predicate Subgraphs vs Post-Filtering"* to `goals/essays/essay_22.md`.
* `[ ]` **Core (14:00–18:00)**: Execute Saturday Deep Learning from Scratch track ().
* `⭐ Optional / Stretch`: Run automated test suite validating PyTorch numerical gradient and attention equivalence.

### 🔹 Sunday, Sun Feb 1 ([`Day 154`](../days/month-06/day-154-2027-02-01.md))
* `[ ]` **Core (09:00–13:00)**: Execute Monthly Research Milestone for Month 6 (`research/2027-02-predicate-aware-graphs/`): run empirical benchmarks and record data tables.
* `⭐ Optional / Stretch`: Draft / update section figures and experimental limitations.

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

### 🧠 Deep Learning Track (Saturday 14:00–18:00)
* **Task**: 

### 🔬 Monthly Research Milestone (Sunday 09:00–13:00)
* **Paper**: *"Mitigating Recall Collapse in Filtered Approximate Nearest Neighbor Graphs: An Empirical Evaluation of ACORN vs. Iterative Post-Filtering Across Selectivity Spectrums"*
* **Workspace**: `research/2027-02-predicate-aware-graphs/`
* **Publish Deadline**: **Sun Feb 28**
