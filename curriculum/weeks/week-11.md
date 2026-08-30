# 🚀 Week 11 Execution Playbook

> **Theme**: Determinants, Eigenvalues, Spectral Theorem & LSM-Tree Engine  
> **Calendar Dates**: Mon Nov 10 – Sun Nov 16 (2026-11-10 to 2026-11-16)  
> **Parent Month Dashboard**: [Month 3 (Nov 2026)](month-03-nov.md) · **Block**: I — Vector Search Engine

| | | |
|:---|:---|:---|
| [← Week 10](week-10.md) | [Month 3 (Nov 2026) Dashboard](month-03-nov.md) | [Week 12 →](week-12.md) |

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
| **Monday** | Mon Nov 10 | [`Day 071`](../days/month-03/day-071-2026-11-10.md) | **STRANG §4.1–4.4**: Determinants: axiomatic definition (linearity, sign change, $\det I = 1$), cofactor expansions, formula for $A^{-1}$. | Research paper: *"DiskANN: Fast Accurate Billion-point NN Search on a Single Node"* (Subramanya et al. 2019) — architecture skim (**build Week 16 Thu**). | **secan**: Implement `WriteAheadLog` (`wal.bin`) and in-memory mutable `MemTable` (dynamic HNSW absorbing live writes). |
| **Tuesday** | Tue Nov 11 | [`Day 072`](../days/month-03/day-072-2026-11-11.md) | **STRANG §5.1–5.2**: Eigenvalues and eigenvectors: characteristic polynomial $\det(A - \lambda I) = 0$. Matrix diagonalization $S^{-1} A S = \Lambda$. | Apache Arrow / Lance columnar layout notes for segment files. | **secan**: Implement Segment Flusher: when MemTable reaches threshold, flush to immutable disk segment (flat Arrow/Lance layout). |
| **Wednesday** | Wed Nov 12 | [`Day 073`](../days/month-03/day-073-2026-11-12.md) | **STRANG §5.3–5.4**: Systems of differential equations $\frac{du}{dt} = Au$, matrix exponential $e^{At}$, stability of linear dynamical systems. | Linux `io_uring` tutorial: SQ/CQ basics (**implement Week 16 Thu**). | **secan**: Background compaction: merge **segments and HNSW graphs** (not only LSM files). Rebuild/compact graph edges after merge. |
| **Thursday** | Thu Nov 13 | [`Day 074`](../days/month-03/day-074-2026-11-13.md) | **STRANG §5.5**: Real symmetric matrices: proof that eigenvalues are real and eigenvectors are orthogonal. The Spectral Theorem $A = Q \Lambda Q^T$. | **ASYNC Ch 6 & Ch 9**: Boost.Asio I/O concepts, profiling asynchronous workflows. | **secan**: Concurrent search-while-ingest smoke test. **Stretch**: Poisson load gen ($p50/p95/p99$) moved from Week 10. Add ThreadSanitizer CI job. |
| **Friday** | Fri Nov 14 | [`Day 075`](../days/month-03/day-075-2026-11-14.md) | **STRANG §5.6**: Positive definite matrices: tests via eigenvalues, pivots, determinants, and energy $x^T A x > 0$. Cholesky factorization $A = L L^T$. | **FINSY Ch 3**: High-performance system measurement, scaling modules, latency distributions. | **secan**: Crash-recovery test: kill process mid-write; verify WAL replay restores MemTable. Benchmark inserts/sec under search traffic. |
| **Saturday** | Sat Nov 15 | [`Day 076`](../days/month-03/day-076-2026-11-15.md) | **09:00–13:00**: Essay 11 | **14:00–18:00**: Deep Learning Track | Deep Learning from Scratch (uv/PyTorch) |
| **Sunday** | Sun Nov 16 | [`Day 077`](../days/month-03/day-077-2026-11-16.md) | **09:00–13:00**: Monthly Research | Research Experimentation | Rest & Subconscious Incubation |

---

## 📋 Daily Action Items & Deliverables (Week 11)

### 🔹 Monday, Mon Nov 10 ([`Day 071`](../days/month-03/day-071-2026-11-10.md))
* `[ ]` **Core**: Implement binary append-only `WriteAheadLog` with CRC32 checksums; wire into mutable in-memory `MemTable`.
* `⭐ Optional / Stretch`: Implement zero-allocation ring-buffer WAL flusher using synchronous `fdatasync` vs asynchronous batching.

### 🔹 Tuesday, Tue Nov 11 ([`Day 072`](../days/month-03/day-072-2026-11-11.md))
* `[ ]` **Core**: Implement immutable segment flusher writing compacted vector data and HNSW graph topology to flat binary files.
* `⭐ Optional / Stretch`: Structure segment files using columnar Apache Arrow layout with dictionary-encoded vector metadata.

### 🔹 Wednesday, Wed Nov 12 ([`Day 073`](../days/month-03/day-073-2026-11-12.md))
* `[ ]` **Core**: Implement background compaction thread merging 2 immutable disk segments into 1 and rebuilding neighbor graph edges.
* `⭐ Optional / Stretch`: Add a tiered compaction strategy (similar to RocksDB Levelled Compaction) for multi-gigabyte vector indexes.

### 🔹 Thursday, Thu Nov 13 ([`Day 074`](../days/month-03/day-074-2026-11-13.md))
* `[ ]` **Core**: Implement reader-writer locking on `LSMVectorEngine`; verify search-while-ingest under ThreadSanitizer (`-fsanitize=thread`).
* `⭐ Optional / Stretch`: Implement Poisson distributed query load generator measuring $p50, p95, p99$ latency spikes during active segment flushing.

### 🔹 Friday, Fri Nov 14 ([`Day 075`](../days/month-03/day-075-2026-11-14.md))
* `[ ]` **Core**: Implement crash-recovery test suite: kill process during active write stream; verify WAL replay restores exact vector count and recall.
* `⭐ Optional / Stretch`: Benchmark sustained write throughput (vectors/sec) under simultaneous 100 QPS query load.

### 🔹 Saturday, Sat Nov 15 ([`Day 076`](../days/month-03/day-076-2026-11-15.md))
* `[ ]` **Core (09:00–13:00)**: Write and ship **Technical Essay 11**: *"Eigenvalues, Spectral Decompositions, and LSM Storage Engines: Write-Ahead Logs and Vector Compaction"* to `goals/essays/essay_11.md`.
* `[ ]` **Core (14:00–18:00)**: Execute Saturday Deep Learning from Scratch track ().
* `⭐ Optional / Stretch`: Run automated test suite validating PyTorch numerical gradient and attention equivalence.

### 🔹 Sunday, Sun Nov 16 ([`Day 077`](../days/month-03/day-077-2026-11-16.md))
* `[ ]` **Core (09:00–13:00)**: Execute Monthly Research Milestone for Month 3 (`research/2026-11-late-interaction-lsm/`): run empirical benchmarks and record data tables.
* `⭐ Optional / Stretch`: Draft / update section figures and experimental limitations.

---

## ⛔ What NOT to Overspend Time On (Week 11 Time Traps)

* ❌ **Do NOT** build a full distributed database Raft consensus layer—single-node WAL with segment files is the complete scope.
* ❌ **Do NOT** implement complex multi-level B-trees—flat binary disk segment files with contiguous arrays are ideal for vector storage.
* ❌ **Do NOT** over-engineer background compaction heuristics—a simple merge of 2 oldest segments into 1 is sufficient.

---

## 📝 Weekend Deliverables

### ✍️ Technical Essay 11 (Saturday 09:00–13:00)
* **Title**: *"Eigenvalues, Spectral Decompositions, and LSM Storage Engines: Write-Ahead Logs and Vector Compaction"*
* **Target File**: `~/personal/goals/essays/essay_11.md`
* **5-Part Structure**:
  1. **Mathematical Foundation**: Core theorems, derivations, and formal definitions.
  2. **The Systems Bottleneck**: Hardware limitation (memory bandwidth, port contention, cache line splits, warp stalls).
  3. **The Engine Architecture**: Exact data structures and SIMD/CUDA kernel design implemented in `secan`.
  4. **Empirical Benchmarks**: Perf counter tables, latency percentiles ($p50/p95/p99$), and QPS curves.
  5. **Key Takeaway**: Architectural rule of thumb for production AI systems.

### 🧠 Deep Learning Track (Saturday 14:00–18:00)
* **Task**: 

### 🔬 Monthly Research Milestone (Sunday 09:00–13:00)
* **Paper**: *"Streaming Late Interaction: Evaluating PLAID Centroid Inverted Lists vs MUVERA Fixed-Dimensional Encodings in Dynamic LSM Vector Storage"*
* **Workspace**: `research/2026-11-late-interaction-lsm/`
* **Publish Deadline**: **Sun Nov 29**
