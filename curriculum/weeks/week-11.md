# 🚀 Week 11 Execution Playbook

> **Theme**: Determinants, Eigenvalues, Spectral Theorem & LSM-Tree Engine  
> **Calendar Dates**: Sat Nov 14 – Fri Nov 20 (2026-11-14 to 2026-11-20)
> **Parent Month Dashboard**: [Month 3 (Nov 2026)](month-03-nov.md) · **Block**: I — Vector Search Engine

| | | |
|:---|:---|:---|
| [← Week 10](week-10.md) | [Month 3 (Nov 2026) Dashboard](month-03-nov.md) | [Week 12 →](week-12.md) |

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
| **Saturday** | Sat Nov 14 | [`Day 071`](../days/month-03/day-071-2026-11-14.md) | **09:00–13:00**: Pure Math Block 1 (Theory & Derivations) | **15:00–16:30**: Literature Sanctuary | **18:00–19:30**: Information Theory (Cover & Thomas) · **19:30–21:00**: Thought Leadership (Claude E. Shannon) · **21:00+**: Free / Rest|
| **Sunday** | Sun Nov 15 | [`Day 072`](../days/month-03/day-072-2026-11-15.md) | **09:00–13:00**: Pure Math Block 2 (Problem Sets & Proofs) | **13:00**: Maint · **15:00**: Penrose | **18:00–19:30**: Dist Systems (DDIA Ch 10) · **19:30–21:00**: Systems Lab (Gregg Ch 9) |
| **Monday** | Mon Nov 16 | [`Day 073`](../days/month-03/day-073-2026-11-16.md) | Research paper: *"DiskANN: Fast Accurate Billion-point NN Search on a Single Node"* (Subramanya et al. 2019) — architecture skim (**build Week 16 Thu**). | **Hardware Profiling & Benchmark Sweeps** | **secan**: Implement `WriteAheadLog` (`wal.bin`) and in-memory mutable `MemTable` (dynamic HNSW absorbing live writes). |
| **Tuesday** | Tue Nov 17 | [`Day 074`](../days/month-03/day-074-2026-11-17.md) | Apache Arrow / Lance columnar layout notes for segment files. | **DL Track (Part 1): Architecture & Tensor Shapes** | **secan**: Implement Segment Flusher: when MemTable reaches threshold, flush to immutable disk segment (flat Arrow/Lance layout). |
| **Wednesday** | Wed Nov 18 | [`Day 075`](../days/month-03/day-075-2026-11-18.md) | Linux `io_uring` tutorial: SQ/CQ basics (**implement Week 16 Thu**). | **DL Track (Part 2): Training Loop & Verification** | **secan**: Background compaction: merge **segments and HNSW graphs** (not only LSM files). Rebuild/compact graph edges after merge. |
| **Thursday** | Thu Nov 19 | [`Day 076`](../days/month-03/day-076-2026-11-19.md) | **ASYNC Ch 6 & Ch 9**: Boost.Asio I/O concepts, profiling asynchronous workflows. | **DL / Vector Retrieval Integration & Profiling** | **secan**: Concurrent search-while-ingest smoke test. **Stretch**: Poisson load gen ($p50/p95/p99$) moved from Week 10. Add ThreadSanitizer CI job. |
| **Friday** | Fri Nov 20 | [`Day 077`](../days/month-03/day-077-2026-11-20.md) | **FINSY Ch 3**: High-performance system measurement, scaling modules, latency distributions. | **Weekly Technical Article: Drafting & Publishing** | **secan**: Crash-recovery test: kill process mid-write; verify WAL replay restores MemTable. Benchmark inserts/sec under search traffic. |

---

## 📋 Daily Action Items & Deliverables (Week 11)

### 🔹 Saturday, Sat Nov 14 ([`Day 071`](../days/month-03/day-071-2026-11-14.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 1**: Theory, concepts, and analytical derivations (Determinants, Eigenvalues, **Schur Complement Block Inversion**, **Sherman–Morrison–Woodbury Formula**, and **Kronecker Products $\mathbf{A} \otimes \mathbf{B}$**).
* `[ ]` **Core (15:00–16:30)**: **Weekend Reading Sanctuary**: Literature / Philosophy deep reading.
* `[ ]` **Core (16:30–18:00)**: **Physical Break & Mental Decompression**: Walk, tea, and recovery.
* `[ ]` **Core (18:00–19:30)**: **Information Theory Track**: Thomas M. Cover & Joy A. Thomas, *Elements of Information Theory* — **Ch 10.1–10.3** (Rate-Distortion Theory: Continuous Distortion Measures & Rate-Distortion Function $R(D)$).
* `[ ]` **Core (19:30–21:00)**: **Thought Leadership Masterclass**: Claude E. Shannon, *The Mathematical Theory of Communication* — **Part IV & V: Continuous Information & Rate Distortion** (Continuous Entropy, Gaussian Maximization, Capacity of Bandlimited Gaussian Channel W log(1 + P/N)).
* `⭐ Optional / Stretch`: 21:00 onwards 100% Free / Rest.

### 🔹 Sunday, Sun Nov 15 ([`Day 072`](../days/month-03/day-072-2026-11-15.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 2**: Advanced theorems, problem sets, and chalkboard proof defense (Spectral Theorem, Positive Definite Matrices, **Cholesky Factorization $\mathbf{A} = \mathbf{L}\mathbf{L}^T$**, **Correlated Gaussian Sampling $\mathbf{x} = \boldsymbol{\mu} + \mathbf{L}\mathbf{z}$**, and **Fast Mahalanobis Distance via Triangular Substitution**).
* `[ ]` **Core (13:00–14:00)**: **Runtime Maintenance**: Quick 30–60 min check for `limbed` / `ggmbed` (`embed-runtimes`).
* `[ ]` **Core (15:00–16:45)**: **Penrose Sunday**: *The Road to Reality* (1 chapter/week, visual geometry focus).
* `[ ]` **Core (18:00–19:30)**: **Distributed Systems & IR Track**: **DDIA Ch 10** (Batch Processing: MapReduce, Distributed Dataflow Engines & Graph Processing).
* `[ ]` **Core (19:30–21:00)**: **Graduate Systems & GPU Architecture Lab**: Microarchitecture analysis and CUDA exercises in **Gregg Ch 9** (Linux NVMe storage stack, page cache writeback & asynchronous `io_uring` direct I/O).
* `⭐ Optional / Stretch`: 21:00 onwards Weekly review & recovery.

### 🔹 Monday, Mon Nov 16 ([`Day 073`](../days/month-03/day-073-2026-11-16.md))
* `[ ]` **Core**: Implement binary append-only `WriteAheadLog` with CRC32 checksums; wire into mutable in-memory `MemTable`.
* `⭐ Optional / Stretch`: Implement zero-allocation ring-buffer WAL flusher using synchronous `fdatasync` vs asynchronous batching.


### 🔹 Tuesday, Tue Nov 17 ([`Day 074`](../days/month-03/day-074-2026-11-17.md))
* `[ ]` **Core**: Implement immutable segment flusher writing compacted vector data and HNSW graph topology to flat binary files.
* `⭐ Optional / Stretch`: Structure segment files using columnar Apache Arrow layout with dictionary-encoded vector metadata.


### 🔹 Wednesday, Wed Nov 18 ([`Day 075`](../days/month-03/day-075-2026-11-18.md))
* `[ ]` **Core**: Implement background compaction thread merging 2 immutable disk segments into 1 and rebuilding neighbor graph edges.
* `⭐ Optional / Stretch`: Add a tiered compaction strategy (similar to RocksDB Levelled Compaction) for multi-gigabyte vector indexes.


### 🔹 Thursday, Thu Nov 19 ([`Day 076`](../days/month-03/day-076-2026-11-19.md))
* `[ ]` **Core**: Implement reader-writer locking on `LSMVectorEngine`; verify search-while-ingest under ThreadSanitizer (`-fsanitize=thread`).
* `⭐ Optional / Stretch`: Implement Poisson distributed query load generator measuring $p50, p95, p99$ latency spikes during active segment flushing.


### 🔹 Friday, Fri Nov 20 ([`Day 077`](../days/month-03/day-077-2026-11-20.md))
* `[ ]` **Core**: Implement crash-recovery test suite: kill process during active write stream; verify WAL replay restores exact vector count and recall.
* `⭐ Optional / Stretch`: Benchmark sustained write throughput (vectors/sec) under simultaneous 100 QPS query load.


---

## ⛔ What NOT to Overspend Time On (Week 11 Time Traps)

* ❌ **Do NOT** build a full distributed database Raft consensus layer—single-node WAL with segment files is the complete scope.
* ❌ **Do NOT** implement complex multi-level B-trees—flat binary disk segment files with contiguous arrays are ideal for vector storage.
* ❌ **Do NOT** over-engineer background compaction heuristics—a simple merge of 2 oldest segments into 1 is sufficient.

---

## Benchmark Close

Before the Friday article or release, save the run manifest and raw JSON/CSV, add one meaningful parameter sweep and plot, update the comparable README result row, and state the oracle result plus one evidence-backed conclusion. Record results below the noise floor as inconclusive.

## 📝 Weekend Deliverables

### ✍️ Technical Essay 11 (Drafted Friday 06:30–08:30)
* **Title**: *"Eigenvalues, Spectral Decompositions, and LSM Storage Engines: Write-Ahead Logs and Vector Compaction"*
* **Target File**: `~/personal/goals/essays/essay_11.md`
* **5-Part Structure**:
  1. **Mathematical Foundation**: Core theorems, derivations, and formal definitions.
  2. **The Systems Bottleneck**: Hardware limitation (memory bandwidth, port contention, cache line splits, warp stalls).
  3. **The Engine Architecture**: Exact data structures and SIMD/CUDA kernel design implemented in `secan`.
  4. **Empirical Benchmarks**: Perf counter tables, latency percentiles ($p50/p95/p99$), and QPS curves.
  5. **Key Takeaway**: Architectural rule of thumb for production AI systems.

### 🧠 Deep Learning Track (Tue/Wed 06:30–08:30 Morning Builder)
* **Task**: 

### 🔬 Empirical Systems & Benchmarking Focus (Mon/Thu 06:30–08:30 Morning Builder)
* **Focus**: Sub-2-Bit In-Register SIMD Execution & Manuscript Submission Freeze
* **Workspace**: `research/2026-11-rabitq-lsm/`
* **Artifact Target**: Empirical benchmark and profiling data feeding into Friday's technical articles.


---

## ⚡  Embedding Engine Track (Week 11)
> **Weekly Focus**: *Cross-Encoder & Re-ranking Architecture*

| Day | 23:00 – 00:00 Implementation Task |
|:---|:---|
| **Mon** | Implement Cross-Encoder sequence concatenation [Query; Passage] in C++ tokenizer. |
| **Tue** | Implement Classification Head (Linear + Sigmoid/Softmax) for passage re-ranking scores. |
| **Wed** | Benchmark Cross-Encoder latency vs ColBERT Late-Interaction MaxSim throughput. |
| **Thu** | Build two-stage pipeline: secan HNSW/IVF retrieval -> cennan Cross-Encoder re-ranker. |
| **Fri** | Verify NDCG@10 and MRR improvements on MS-MARCO passage ranking benchmark. |
