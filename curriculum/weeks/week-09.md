# 🚀 Week 09 Execution Playbook

> **Theme**: Vector Spaces, Four Fundamental Subspaces, ColBERT & SIMD MaxSim  
> **Calendar Dates**: Sat Oct 31 – Fri Nov 6 (2026-10-31 to 2026-11-06)
> **Parent Month Dashboard**: [Month 3 (Nov 2026)](month-03-nov.md) · **Block**: I — Vector Search Engine

| | | |
|:---|:---|:---|
| [← Week 08](week-08.md) | [Month 3 (Nov 2026) Dashboard](month-03-nov.md) | [Week 10 →](week-10.md) |

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
| **Saturday** | Sat Oct 31 | [`Day 057`](../days/month-03/day-057-2026-10-31.md) | **09:00–13:00**: Pure Math Block 1 (Theory & Derivations) | **15:00–16:30**: Literature Sanctuary | **18:00–19:30**: Information Theory (Cover & Thomas) · **19:30+**: Free / Rest |
| **Sunday** | Sun Nov 1 | [`Day 058`](../days/month-03/day-058-2026-11-01.md) | **09:00–13:00**: Pure Math Block 2 (Problem Sets & Proofs) | **13:00**: Maint · **15:00**: Penrose | **18:00–19:30**: Dist Systems (DDIA Ch 8) · **19:30–21:00**: Systems Lab (H&P Ch 4) |
| **Monday** | Mon Nov 2 | [`Day 059`](../days/month-03/day-059-2026-11-02.md) | Research paper: *"ColBERT: Efficient and Effective Passage Search via Late Interaction"* (Khattab & Zaharia 2020). | **Monthly Research: Planning & Literature Synthesis** | **secan (required)**: **Batch HNSW build**: insert $N$ in one pass (level assignment + sequential connect). Compare build time vs one-by-one insert. |
| **Tuesday** | Tue Nov 3 | [`Day 060`](../days/month-03/day-060-2026-11-03.md) | PLAID paper §1–4; HNSW bulk-construction notes. | **DL Track (Part 1): Architecture & Tensor Shapes** | **secan**: Parallel batch graph construction (shard-then-merge or lock-free insert). Measure Recall@10 vs sequential insert. |
| **Wednesday** | Wed Nov 4 | [`Day 061`](../days/month-03/day-061-2026-11-04.md) | **INTEL Intrinsics Guide**: Study `_mm256_max_ps`, `_mm256_permute2f128_ps`, cross-lane max reduction. | **DL Track (Part 2): Training Loop & Verification** | **secan**: Implement **SIMD-vectorized MaxSim kernel** in C++: process 8 document tokens in parallel with AVX2 FMA + horizontal max reduction. |
| **Thursday** | Thu Nov 5 | [`Day 062`](../days/month-03/day-062-2026-11-05.md) | **AGNER Ch 13**: Data parallelism, cache layout for multi-vector matrices. | **Monthly Research: Sweeps & Data Logging** | **secan**: Build **token centroid index**: cluster document tokens into centroids ($C=32\text{K}$). Build inverted lists `centroid_id → (doc_id, token_idx)`. |
| **Friday** | Fri Nov 6 | [`Day 063`](../days/month-03/day-063-2026-11-06.md) | Re-read PLAID paper §3 "Centroid Interaction" + §4 "Decompression and Scoring". | **Technical Essay: Lab-Note Drafting** | **secan**: Implement centroid candidate pruning: query tokens retrieve candidate documents from centroid inverted lists. Score candidates with MaxSim. |

---

## 📋 Daily Action Items & Deliverables (Week 09)

### 🔹 Saturday, Sat Oct 31 ([`Day 057`](../days/month-03/day-057-2026-10-31.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 1**: Theory, concepts, and analytical derivations (textbook chapters & core proofs).
* `[ ]` **Core (15:00–16:30)**: **Weekend Reading Sanctuary**: Literature / Philosophy deep reading.
* `[ ]` **Core (16:30–18:00)**: **Physical Break & Mental Decompression**: Walk, tea, and recovery.
* `[ ]` **Core (18:00–19:30)**: **Information Theory Track**: Thomas M. Cover & Joy A. Thomas, *Elements of Information Theory* — **Ch 8.1–8.6** (Differential Entropy & Gaussian Distributions).
* `⭐ Optional / Stretch`: 19:30 onwards 100% Free / Rest.

### 🔹 Sunday, Sun Nov 1 ([`Day 058`](../days/month-03/day-058-2026-11-01.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 2**: Advanced theorems, problem sets, and chalkboard proof defense.
* `[ ]` **Core (13:00–14:00)**: **Runtime Maintenance**: Quick 30–60 min check for `limbed` / `ggmbed` (`embed-runtimes`).
* `[ ]` **Core (15:00–16:45)**: **Penrose Sunday**: *The Road to Reality* (1 chapter/week, visual geometry focus).
* `[ ]` **Core (18:00–19:30)**: **Distributed Systems & IR Track**: **DDIA Ch 8** (The Trouble with Distributed Systems: Faults, Network Partitions & Clock Skew).
* `[ ]` **Core (19:30–21:00)**: **Graduate Systems & GPU Architecture Lab**: Microarchitecture analysis and CUDA exercises in **H&P Ch 4** (SIMD vector register lanes, gather/scatter latency & roofline model computations).
* `⭐ Optional / Stretch`: 21:00 onwards Weekly review & recovery.

### 🔹 Monday, Mon Nov 2 ([`Day 059`](../days/month-03/day-059-2026-11-02.md))
* `[ ]` **Core**: Implement batch HNSW construction inserting $N$ vectors in a single pass; measure build throughput improvement over sequential inserts.
* `⭐ Optional / Stretch`: Implement thread-local entry point queues to avoid global lock contention during bulk insertion.


### 🔹 Tuesday, Tue Nov 3 ([`Day 060`](../days/month-03/day-060-2026-11-03.md))
* `[ ]` **Core**: Implement parallel batch graph builder (shard dataset into $K$ partitions, build parallel subgraphs, merge boundary edges).
* `⭐ Optional / Stretch`: Measure Recall@10 of shard-merged graph vs monolithic sequential graph on 100K SIFT vectors.


### 🔹 Wednesday, Wed Nov 4 ([`Day 061`](../days/month-03/day-061-2026-11-04.md))
* `[ ]` **Core**: Implement SIMD AVX2 MaxSim kernel computing inner product of 8 document tokens in parallel with horizontal max reduction.
* `⭐ Optional / Stretch`: Implement 2D register tiling computing MaxSim between 4 query tokens and 8 document tokens simultaneously.


### 🔹 Thursday, Thu Nov 5 ([`Day 062`](../days/month-03/day-062-2026-11-05.md))
* `[ ]` **Core**: Build token centroid inverted index clustering document token embeddings into $C=32\text{K}$ centroids.
* `⭐ Optional / Stretch`: Analyze inverted list length distribution and prune stop-word token centroids (e.g. centroids containing > 5% of all tokens).


### 🔹 Friday, Fri Nov 6 ([`Day 063`](../days/month-03/day-063-2026-11-06.md))
* `[ ]` **Core**: Implement centroid candidate pruning: query tokens retrieve candidate documents from centroid lists; score candidates with MaxSim.
* `⭐ Optional / Stretch`: Profile candidate reduction ratio (e.g. evaluating top-1000 candidates vs full corpus MaxSim scan).


---

## ⛔ What NOT to Overspend Time On (Week 09 Time Traps)

* ❌ **Do NOT** build a custom Python tokenizer or vocabulary loader in C++—run tokenization and ColBERT embedding extraction in Python/PyTorch.
* ❌ **Do NOT** compute full exact $N \times M$ all-pairs MaxSim for the entire corpus—always prune candidates using centroid lists or MUVERA.
* ❌ **Do NOT** get lost in infinite Gaussian elimination matrix algebra by hand—understand $A = LU$ and 4 fundamental subspaces conceptually.

---

## 📝 Weekend Deliverables

### ✍️ Technical Essay 09 (Saturday 09:00–13:00)
* **Title**: *"Beyond Single Vectors: The Linear Algebra, Matrix Decompositions, and SIMD Architecture of ColBERT Late Interaction"*
* **Target File**: `~/personal/goals/essays/essay_09.md`
* **5-Part Structure**:
  1. **Mathematical Foundation**: Core theorems, derivations, and formal definitions.
  2. **The Systems Bottleneck**: Hardware limitation (memory bandwidth, port contention, cache line splits, warp stalls).
  3. **The Engine Architecture**: Exact data structures and SIMD/CUDA kernel design implemented in `secan`.
  4. **Empirical Benchmarks**: Perf counter tables, latency percentiles ($p50/p95/p99$), and QPS curves.
  5. **Key Takeaway**: Architectural rule of thumb for production AI systems.

### 🧠 Deep Learning Track (Tue/Wed 06:30–08:30 Morning Builder)
* **Task**: **🧠 DL weekend**: ColBERT dual encoder + MaxSim + tiny Margin MSE. **Knowledge distillation**: implement cross-encoder reranker score as teacher → distill into bi-encoder student (MSE on logits). Compare embedding quality vs Week 6 InfoNCE-only training.

### 🔬 Monthly Research Milestone (GAPQ Milestone 3 (Landmark Paper 1 Freeze) — Mon/Thu 06:30–08:30 Morning Builder)
* **Paper**: *"Sub-2-Bit In-Register SIMD Execution & Manuscript Submission Freeze"*
* **Workspace**: `research/2026-11-rabitq-lsm/`
* **Publish Deadline**: **Sun Nov 29**
