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
| **Saturday** | Sat Oct 31 | [`Day 057`](../days/month-03/day-057-2026-10-31.md) | **09:00–13:00**: Pure Math Block 1 (Theory & Derivations) | **15:00–16:30**: Literature Sanctuary | **18:00–19:30**: Information Theory (Cover & Thomas) · **19:30–21:00**: Thought Leadership (Claude E. Shannon) · **21:00+**: Free / Rest|
| **Sunday** | Sun Nov 1 | [`Day 058`](../days/month-03/day-058-2026-11-01.md) | **09:00–13:00**: Pure Math Block 2 (Problem Sets & Proofs) | **13:00**: Maint · **15:00**: Penrose | **18:00–19:30**: Dist Systems (DDIA Ch 8) · **19:30–21:00**: Systems Lab (H&P Ch 4) |
| **Monday** | Mon Nov 2 | [`Day 059`](../days/month-03/day-059-2026-11-02.md) | Research paper: *"ColBERT: Efficient and Effective Passage Search via Late Interaction"* (Khattab & Zaharia 2020). | **Hardware Profiling & Benchmark Sweeps** | **secan (required)**: **Batch HNSW build**: insert $N$ in one pass (level assignment + sequential connect). Compare build time vs one-by-one insert. |
| **Tuesday** | Tue Nov 3 | [`Day 060`](../days/month-03/day-060-2026-11-03.md) | **PiPNN paper** (Rubel et al. 2024/2025): Partition-local dense GEMM & **HashPrune**. | **DL Track (Part 1): Architecture & Tensor Shapes** | **secan**: Implement **PiPNN / HashPrune** batch graph builder (partition-local dense GEMM + HashPrune edge pruning). Measure build speedup ($10\times$) & Recall vs sequential insert. |
| **Wednesday** | Wed Nov 4 | [`Day 061`](../days/month-03/day-061-2026-11-04.md) | **INTEL Intrinsics Guide**: Study `_mm256_max_ps`, `_mm256_permute2f128_ps`, cross-lane max reduction. | **DL Track (Part 2): Training Loop & Verification** | **secan**: Implement **SIMD-vectorized MaxSim kernel** in C++: process 8 document tokens in parallel with AVX2 FMA + horizontal max reduction. |
| **Thursday** | Thu Nov 5 | [`Day 062`](../days/month-03/day-062-2026-11-05.md) | **AGNER Ch 13**: Data parallelism, cache layout for multi-vector matrices. | **DL / Vector Retrieval Integration & Profiling** | **secan**: Build **token centroid index**: cluster document tokens into centroids ($C=32\text{K}$). Build inverted lists `centroid_id → (doc_id, token_idx)`. |
| **Friday** | Fri Nov 6 | [`Day 063`](../days/month-03/day-063-2026-11-06.md) | Re-read PLAID paper §3 "Centroid Interaction" + §4 "Decompression and Scoring". | **Weekly Technical Article: Drafting & Publishing** | **secan**: Implement centroid candidate pruning: query tokens retrieve candidate documents from centroid inverted lists. Score candidates with MaxSim. |

---

> **📚 Advanced Research Reference (Week 09)**: * [Paul E. McKenney, *Is Parallel Programming Hard ("The Perfbook")*](https://mirrors.edge.kernel.org/pub/linux/kernel/people/paulmck/perfbook/perfbook.html) — **Ch 3 (§3.1–3.4) & Ch 9 (§9.1–9.3)** (*MESI Cache Invalidation & Epoch-Based Reclamation for Concurrent HNSW*) · * [Pavel Zezula et al., *Similarity Search: The Metric Space Approach*](https://link.springer.com/book/10.1007/0-387-29151-2) — **Ch 4 (§4.1–4.4) & Ch 5 (§5.1–5.3)** (*Ball Partitioning VP-Trees vs Small-World Graph Routing*)

## 📋 Daily Action Items & Deliverables (Week 09)

### 🔹 Saturday, Sat Oct 31 ([`Day 057`](../days/month-03/day-057-2026-10-31.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 1**: Theory, concepts, and analytical derivations (textbook chapters & core proofs).
* `[ ]` **Core (15:00–16:30)**: **Weekend Reading Sanctuary**: [Richard W. Hamming, *The Art of Doing Science and Engineering: Learning to Learn*](https://press.stripe.com/the-art-of-doing-science-and-engineering) — **Ch 12–13 (*Error-Correcting Codes & Redundancy*)**.
* `[ ]` **Core (16:30–18:00)**: **Physical Break & Mental Decompression**: Walk, tea, and recovery.
* `[ ]` **Core (18:00–19:30)**: **Information Theory Track**: [Thomas M. Cover & Joy A. Thomas, *Elements of Information Theory (2nd ed)*](https://www.wiley.com/en-us/Elements+of+Information+Theory%2C+2nd+Edition-p-9780471241959) — **Ch 5 (§5.1–5.4)** (Data Compression, Kraft Inequality, Optimal Codes & Bounds on Optimal Code Length).
* `[ ]` **Core (19:30–21:00)**: **Thought Leadership Masterclass**: [Claude E. Shannon, *The Mathematical Theory of Communication (1948)*](https://archive.org/details/bstj27-3-379) — **Part I: Discrete Noiseless Systems & Entropy** (Fundamental Limits of Compression and Source Coding).
* `⭐ Optional / Stretch`: 21:00 onwards 100% Free / Rest.

### 🔹 Sunday, Sun Nov 1 ([`Day 058`](../days/month-03/day-058-2026-11-01.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 2**: Advanced theorems, problem sets, and chalkboard proof defense.
* `[ ]` **Core (13:00–14:00)**: **Runtime Maintenance**: Quick 30–60 min check for `limbed` / `ggmbed` (`embed-runtimes`).
* `[ ]` **Core (15:00–16:45)**: **Penrose Sunday**: [Sir Roger Penrose, *The Road to Reality*](https://www.vintagebooks.com) — **Ch 4: Magical Complex Numbers** ($i = \sqrt{-1}$, Argand plane, geometry of complex addition/multiplication, Euler's formula $e^{i\pi} + 1 = 0$.).
* `[ ]` **Core (18:00–19:30)**: **Distributed Systems & IR Track**: [Martin Kleppmann, *Designing Data-Intensive Applications*](https://dataintensive.net/) — **DDIA Ch 4** (Encoding and Evolution: Protobuf, Apache Thrift, Avro, Schema evolution & binary formats).
* `[ ]` **Core (19:30–21:00)**: **Graduate Systems & GPU Architecture Lab**: [John L. Hennessy & David A. Patterson, *Computer Architecture: A Quantitative Approach (6th ed)*](https://shop.elsevier.com/books/computer-architecture/hennessy/978-0-443-15406-5) — **H&P Ch 3 (§3.1–3.6)** (Instruction-Level Parallelism: Dynamic scheduling, Tomasulo's algorithm, CDB & ROB Commit).
* `⭐ Optional / Stretch`: 21:00 onwards Weekly review & recovery.

### 🔹 Monday, Mon Nov 2 ([`Day 059`](../days/month-03/day-059-2026-11-02.md))
* `[ ]` **Core**: Implement batch HNSW construction inserting $N$ vectors in a single pass; measure build throughput improvement over sequential inserts.
* `⭐ Optional / Stretch`: Implement thread-local entry point queues to avoid global lock contention during bulk insertion.

### 🔹 Tuesday, Tue Nov 3 ([`Day 060`](../days/month-03/day-060-2026-11-03.md))
* `[ ]` **Core**: Implement **PiPNN / HashPrune** parallel batch graph builder (partition dataset into overlapping clusters, compute intra-partition candidate edges with dense GEMM, prune edges with HashPrune).
* `⭐ Optional / Stretch`: Benchmark PiPNN construction speedup ($10\times$) and Recall@10 against standard sequential beam-search insertion on SIFT1M.

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

## Benchmark Close

Before the Friday article or release, save the run manifest and raw JSON/CSV, add one meaningful parameter sweep and plot, update the comparable README result row, and state the oracle result plus one evidence-backed conclusion. Record results below the noise floor as inconclusive.

## 📝 Weekend Deliverables

### ✍️ Technical Essay 09 (Drafted Friday 06:30–08:30)
* **Title**: *"Beyond Single Vectors: The Linear Algebra, Matrix Decompositions, and SIMD Architecture of ColBERT Late Interaction"*
* **Target File**: `~/personal/goals/essays/essay_09.md`
* **5-Part Structure**:
  1. **Mathematical Foundation**: Core theorems, derivations, and formal definitions.
  2. **The Systems Bottleneck**: Hardware limitation (memory bandwidth, port contention, cache line splits, warp stalls).
  3. **The Engine Architecture**: Exact data structures and SIMD/CUDA kernel design implemented in `secan`.
  4. **Empirical Benchmarks**: Perf counter tables, latency percentiles ($p50/p95/p99$), and QPS curves.
  5. **Key Takeaway**: Architectural rule of thumb for production AI systems.

### 🧠 Deep Learning Track (Tue/Wed 06:30–08:30 Morning Builder)
* **Task**: **🧠 DL Builder Track (Tue/Wed)**: ColBERT dual encoder + MaxSim + tiny Margin MSE. **Knowledge distillation**: implement cross-encoder reranker score as teacher → distill into bi-encoder student (MSE on logits). Compare embedding quality vs Week 6 InfoNCE-only training.

### 🔬 Empirical Systems & Benchmarking Focus (Mon/Thu 06:30–08:30 Morning Builder)
* **Focus**: Sub-2-Bit In-Register SIMD Execution & Manuscript Submission Freeze
* **Workspace**: `research/2026-11-rabitq-lsm/`
* **Artifact Target**: Empirical benchmark and profiling data feeding into Friday's technical articles.

---

## ⚡  Embedding Engine Track (Week 09)
> **Weekly Focus**: *ColBERT Multi-Vector Tensor Output*

| Day | 23:00 – 00:00 Implementation Task |
|:---|:---|
| **Mon** | Implement token sequence tensor exporter [B, L, D] in include/cennan/models/colbert.h. |
| **Tue** | Implement punctuation and stop-word token pruning filter to reduce multi-vector storage by 40%. |
| **Wed** | Implement 128D linear projection layer compressing 768D token embeddings for ColBERT v2. |
| **Thu** | Implement [Q] and [D] special query/document prefix marker insertion in C++ tokenizer. |
| **Fri** | Verify multi-vector token generation parity against Stanford ColBERT v2 PyTorch checkpoint. |
