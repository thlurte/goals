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
| **Saturday** | Sat Jan 30 | [`Day 148`](../days/month-06/day-148-2027-01-30.md) | **09:00–13:00**: Pure Math Block 1 (Theory & Derivations) | **15:00–16:30**: Literature Sanctuary | **18:00–19:30**: Information Theory (Cover & Thomas) · **19:30–21:00**: Thought Leadership (Alan M. Turing) · **21:00+**: Free / Rest|
| **Sunday** | Sun Jan 31 | [`Day 149`](../days/month-06/day-149-2027-01-31.md) | **09:00–13:00**: Pure Math Block 2 (Problem Sets & Proofs) | **13:00**: Maint · **15:00**: Penrose | **18:00–19:30**: Dist Systems (IIR Ch 12) · **19:30–21:00**: Systems Lab (FlashMaxSim Lab 1) |
| **Monday** | Mon Feb 1 | [`Day 150`](../days/month-06/day-150-2027-02-01.md) | Payload/B-tree + ANN; pre- vs post-filter. | **Hardware Profiling & Benchmark Sweeps** | **secan (required)**: Payload index (B-tree or sorted ids) + **pre-filter** candidate set; **post-filter** HNSW; plot recall vs selectivity. |
| **Tuesday** | Tue Feb 2 | [`Day 151`](../days/month-06/day-151-2027-02-02.md) | ACORN paper §1–6. | **DL Track (Part 1): Architecture & Tensor Shapes** | **secan**: ACORN-style filtered graph search; compare to Mon's pre/post. |
| **Wednesday** | Wed Feb 3 | [`Day 152`](../days/month-06/day-152-2027-02-03.md) | Lock-free bitset / graph mutation. | **DL Track (Part 2): Training Loop & Verification** | **secan**: Tombstones + vacuum rewires. |
| **Thursday** | Thu Feb 4 | [`Day 153`](../days/month-06/day-153-2027-02-04.md) | `libnuma`; DiskANN under NUMA. | **DL / Vector Retrieval Integration & Profiling** | **secan**: NUMA pin; re-bench. |
| **Friday** | Fri Feb 5 | [`Day 154`](../days/month-06/day-154-2027-02-05.md) | Production checklist. | **Weekly Technical Article: Drafting & Publishing** | **secan (required)**: **Range filter** (`payload < x`) on pre-filter path; smoke tests. Tag `v1.5-production`. |

---

> **📚 Advanced Research Reference (Week 22)**: * [Henry S. Warren Jr., *Hacker's Delight (2nd ed)*](https://www.oreilly.com/library/view/hackers-delight-second/9780133084993/) — **Ch 9 (§9.1–9.4)** (*Exact Integer Division via Invariant Multipliers for Vector Dimension Stride Calculations*) · * [Christopher D. Manning et al., *Introduction to Information Retrieval*](https://nlp.stanford.edu/IR-book/) — **Ch 8 & Ch 18** (*Evaluation Metrics in IR (NDCG@k, MAP, MRR) & Latent Semantic Indexing*)

## 📋 Daily Action Items & Deliverables (Week 22)

### 🔹 Saturday, Sat Jan 30 ([`Day 148`](../days/month-06/day-148-2027-01-30.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 1**: Theory, concepts, and analytical derivations (textbook chapters & core proofs).
* `[ ]` **Core (15:00–16:30)**: **Weekend Reading Sanctuary**: [Douglas Hofstadter, *Gödel, Escher, Bach: An Eternal Golden Braid*](https://www.basicbooks.com/titles/douglas-r-hofstadter/godel-escher-bach/9780465026562/) — **Ch 18: Artificial Intelligence: Retrospects**.
* `[ ]` **Core (16:30–18:00)**: **Physical Break & Mental Decompression**: Walk, tea, and recovery.
* `[ ]` **Core (18:00–19:30)**: **Information Theory Track**: [Thomas M. Cover & Joy A. Thomas, *Elements of Information Theory (2nd ed)*](https://www.wiley.com/en-us/Elements+of+Information+Theory%2C+2nd+Edition-p-9780471241959) — **Ch 16 (§16.1–16.3)** (Information Theory and Portfolio Theory, Kelly Criterion & Log-Optimal Portfolios).
* `[ ]` **Core (19:30–21:00)**: **Thought Leadership Masterclass**: [Alan M. Turing, *Computing Machinery and Intelligence (1950)*](https://academic.oup.com/mind/article/LIX/236/433/986238) — **Computing Machinery and Intelligence & On Computable Numbers (1936)** (The Imitation Game, Digital Computers as Universal Machines, and the Halting Problem Foundation).
* `⭐ Optional / Stretch`: 21:00 onwards 100% Free / Rest.

### 🔹 Sunday, Sun Jan 31 ([`Day 149`](../days/month-06/day-149-2027-01-31.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 2**: Advanced theorems, problem sets, and chalkboard proof defense.
* `[ ]` **Core (13:00–14:00)**: **Runtime Maintenance**: Quick 30–60 min check for `limbed` / `ggmbed` (`embed-runtimes`).
* `[ ]` **Core (15:00–16:45)**: **Penrose Sunday**: [Sir Roger Penrose, *The Road to Reality*](https://www.vintagebooks.com) — **Ch 22: Quantum Algebra, Geometry, and Spin** (Pauli spin matrices, Bloch sphere, spin-$1/2$ state space, spinor geometry.).
* `[ ]` **Core (18:00–19:30)**: **Distributed Systems & IR Track**: [Christopher D. Manning, Prabhakar Raghavan & Hinrich Schütze, *Introduction to Information Retrieval*](https://nlp.stanford.edu/IR-book/) — **IIR Ch 7** (Computing Scores in a Search Engine: WAND algorithm, Block-Max WAND, tiering & query pruning).
* `[ ]` **Core (19:30–21:00)**: **Graduate Systems & GPU Architecture Lab**: [High-Performance GPU Microarchitecture Synthesis](https://docs.nvidia.com/cuda/) — **GPU Microarchitecture Lab** (NVIDIA Hopper / Blackwell Architecture: Tensor Memory Accelerator (TMA) & Asynchronous Barriers).
* `⭐ Optional / Stretch`: 21:00 onwards Weekly review & recovery.

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

## Benchmark Close

Before the Friday article or release, save the run manifest and raw JSON/CSV, add one meaningful parameter sweep and plot, update the comparable README result row, and state the oracle result plus one evidence-backed conclusion. Record results below the noise floor as inconclusive.

## 📝 Weekend Deliverables

### ✍️ Technical Essay 22 (Drafted Friday 06:30–08:30)
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

### 🔬 Empirical Systems & Benchmarking Focus (Mon/Thu 06:30–08:30 Morning Builder)
* **Focus**: Bare-Metal CUTLASS Implementation with Hopper/Blackwell TMA & Warp Specialization
* **Workspace**: `research/2027-02-predicate-aware-graphs/`
* **Artifact Target**: Empirical benchmark and profiling data feeding into Friday's technical articles.


---

## ⚡  Embedding Engine Track (Week 22)
> **Weekly Focus**: *Python nanobind Zero-Copy Bindings*

| Day | 23:00 – 00:00 Implementation Task |
|:---|:---|
| **Mon** | Initialize nanobind C++ extension module in python/cennan_py.cpp. |
| **Tue** | Expose zero-copy NumPy / PyTorch tensor wrappers for cennan::Tensor. |
| **Wed** | Implement Python async batch embedding API with GIL release during C++ inference. |
| **Thu** | Unit tests: verify Python API against native C++ outputs and PyTorch tensors. |
| **Fri** | Benchmark Python API overhead: verify < 2 microseconds dispatch overhead per call. |
