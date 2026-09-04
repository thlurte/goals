# 🚀 Week 09 Execution Playbook

> **Theme**: Vector Spaces, Four Fundamental Subspaces, ColBERT & SIMD MaxSim  
> **Calendar Dates**: Mon Oct 27 – Sun Nov 2 (2026-10-27 to 2026-11-02)  
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
| **Monday** | Mon Oct 27 | [`Day 057`](../days/month-03/day-057-2026-10-27.md) | Research paper: *"ColBERT: Efficient and Effective Passage Search via Late Interaction"* (Khattab & Zaharia 2020). | **Monthly Research: Planning & Literature Synthesis** | **secan (required)**: **Batch HNSW build**: insert $N$ in one pass (level assignment + sequential connect). Compare build time vs one-by-one insert. |
| **Tuesday** | Tue Oct 28 | [`Day 058`](../days/month-03/day-058-2026-10-28.md) | PLAID paper §1–4; HNSW bulk-construction notes. | **DL Track (Part 1): Architecture & Tensor Shapes** | **secan**: Parallel batch graph construction (shard-then-merge or lock-free insert). Measure Recall@10 vs sequential insert. |
| **Wednesday** | Wed Oct 29 | [`Day 059`](../days/month-03/day-059-2026-10-29.md) | **INTEL Intrinsics Guide**: Study `_mm256_max_ps`, `_mm256_permute2f128_ps`, cross-lane max reduction. | **DL Track (Part 2): Training Loop & Verification** | **secan**: Implement **SIMD-vectorized MaxSim kernel** in C++: process 8 document tokens in parallel with AVX2 FMA + horizontal max reduction. |
| **Thursday** | Thu Oct 30 | [`Day 060`](../days/month-03/day-060-2026-10-30.md) | **AGNER Ch 13**: Data parallelism, cache layout for multi-vector matrices. | **Monthly Research: Sweeps & Data Logging** | **secan**: Build **token centroid index**: cluster document tokens into centroids ($C=32\text{K}$). Build inverted lists `centroid_id → (doc_id, token_idx)`. |
| **Friday** | Fri Oct 31 | [`Day 061`](../days/month-03/day-061-2026-10-31.md) | Re-read PLAID paper §3 "Centroid Interaction" + §4 "Decompression and Scoring". | **Technical Essay: Lab-Note Drafting** | **secan**: Implement centroid candidate pruning: query tokens retrieve candidate documents from centroid inverted lists. Score candidates with MaxSim. |
| **Saturday** | Sat Nov 1 | [`Day 062`](../days/month-03/day-062-2026-11-01.md) | **09:00–13:00**: Pure Math Block 1 (Theory & Derivations) | **14:00–18:00**: FREE / Rest / Buffer | Weekend Deep Work |
| **Sunday** | Sun Nov 2 | [`Day 063`](../days/month-03/day-063-2026-11-02.md) | **09:00–13:00**: Pure Math Block 2 (Problem Sets & Proofs) | **13:00–14:00**: Maintenance | Rest & Buffer |

---

## 📋 Daily Action Items & Deliverables (Week 09)

### 🔹 Monday, Mon Oct 27 ([`Day 057`](../days/month-03/day-057-2026-10-27.md))
* `[ ]` **Core**: Implement batch HNSW construction inserting $N$ vectors in a single pass; measure build throughput improvement over sequential inserts.
* `⭐ Optional / Stretch`: Implement thread-local entry point queues to avoid global lock contention during bulk insertion.

### 🔹 Tuesday, Tue Oct 28 ([`Day 058`](../days/month-03/day-058-2026-10-28.md))
* `[ ]` **Core**: Implement parallel batch graph builder (shard dataset into $K$ partitions, build parallel subgraphs, merge boundary edges).
* `⭐ Optional / Stretch`: Measure Recall@10 of shard-merged graph vs monolithic sequential graph on 100K SIFT vectors.

### 🔹 Wednesday, Wed Oct 29 ([`Day 059`](../days/month-03/day-059-2026-10-29.md))
* `[ ]` **Core**: Implement SIMD AVX2 MaxSim kernel computing inner product of 8 document tokens in parallel with horizontal max reduction.
* `⭐ Optional / Stretch`: Implement 2D register tiling computing MaxSim between 4 query tokens and 8 document tokens simultaneously.

### 🔹 Thursday, Thu Oct 30 ([`Day 060`](../days/month-03/day-060-2026-10-30.md))
* `[ ]` **Core**: Build token centroid inverted index clustering document token embeddings into $C=32\text{K}$ centroids.
* `⭐ Optional / Stretch`: Analyze inverted list length distribution and prune stop-word token centroids (e.g. centroids containing > 5% of all tokens).

### 🔹 Friday, Fri Oct 31 ([`Day 061`](../days/month-03/day-061-2026-10-31.md))
* `[ ]` **Core**: Implement centroid candidate pruning: query tokens retrieve candidate documents from centroid lists; score candidates with MaxSim.
* `⭐ Optional / Stretch`: Profile candidate reduction ratio (e.g. evaluating top-1000 candidates vs full corpus MaxSim scan).

### 🔹 Saturday, Sat Nov 1 ([`Day 062`](../days/month-03/day-062-2026-11-01.md))
* `[ ]` **Core (09:00–13:00)**: Write and ship **Technical Essay 9**: *"Beyond Single Vectors: The Linear Algebra, Matrix Decompositions, and SIMD Architecture of ColBERT Late Interaction"* to `goals/essays/essay_09.md`.
* `[ ]` **Core (14:00–18:00)**: Execute Saturday Deep Learning from Scratch track (**🧠 DL weekend**: ColBERT dual encoder + MaxSim + tiny Margin MSE. **Knowledge distillation**: implement cross-encoder reranker score as teacher → distill into bi-encoder student (MSE on logits). Compare embedding quality vs Week 6 InfoNCE-only training.).
* `⭐ Optional / Stretch`: Run automated test suite validating PyTorch numerical gradient and attention equivalence.

### 🔹 Sunday, Sun Nov 2 ([`Day 063`](../days/month-03/day-063-2026-11-02.md))
* `[ ]` **Core (09:00–13:00)**: Execute Monthly Research Milestone for Month 3 (`research/2026-11-late-interaction-lsm/`): run empirical benchmarks and record data tables.
* `⭐ Optional / Stretch`: Draft / update section figures and experimental limitations.

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

### 🧠 Deep Learning Track (Saturday 14:00–18:00)
* **Task**: **🧠 DL weekend**: ColBERT dual encoder + MaxSim + tiny Margin MSE. **Knowledge distillation**: implement cross-encoder reranker score as teacher → distill into bi-encoder student (MSE on logits). Compare embedding quality vs Week 6 InfoNCE-only training.

### 🔬 Monthly Research Milestone (Sunday 09:00–13:00)
* **Paper**: *"Streaming Late Interaction: Evaluating PLAID Centroid Inverted Lists vs MUVERA Fixed-Dimensional Encodings in Dynamic LSM Vector Storage"*
* **Workspace**: `research/2026-11-late-interaction-lsm/`
* **Publish Deadline**: **Sun Nov 29**
