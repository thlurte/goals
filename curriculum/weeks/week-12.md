# 🚀 Week 12 Execution Playbook

> **Theme**: SVD, Whitening, Composed Indexes & Pareto vs Faiss  
> **Calendar Dates**: Mon Nov 17 – Sun Nov 23 (2026-11-17 to 2026-11-23)  
> **Parent Month Dashboard**: [Month 3 (Nov 2026)](month-03-nov.md) · **Block**: I — Vector Search Engine

| | | |
|:---|:---|:---|
| [← Week 11](week-11.md) | [Month 3 (Nov 2026) Dashboard](month-03-nov.md) | [Week 13 →](week-13.md) |

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
| **Monday** | Mon Nov 17 | [`Day 078`](../days/month-03/day-078-2026-11-17.md) | Query-side PCA / OPQ literature. | **Monthly Research: Planning & Literature Synthesis** | **secan**: **Whitening + query-side PCA**. Hubness $S_{N_k}$ before/after. |
| **Tuesday** | Tue Nov 18 | [`Day 079`](../days/month-03/day-079-2026-11-18.md) | **PIKUS Ch 6**: RW locks. | **DL Track (Part 1): Architecture & Tensor Shapes** | **secan**: `nanobind` + CLI: expose `HNSWIndex`, **`IVFPQIndex`**, **`HNSWSQIndex`**, `LSMIndex`. |
| **Wednesday** | Wed Nov 19 | [`Day 080`](../days/month-03/day-080-2026-11-19.md) | Branchless heap; bitset visited. | **DL Track (Part 2): Training Loop & Verification** | **secan (required)**: Bounded flat heap + **bitset visited**. Then concurrent HNSW locks. |
| **Thursday** | Thu Nov 20 | [`Day 081`](../days/month-03/day-081-2026-11-20.md) | `ann-benchmarks` protocol (required, not stretch). | **Monthly Research: Sweeps & Data Logging** | **secan (required)**: Finish **`IVFPQIndex`** (IVF + PQ ADC + optional OPQ). Recall–QPS vs **Faiss IVFPQ** on SIFT. |
| **Friday** | Fri Nov 21 | [`Day 082`](../days/month-03/day-082-2026-11-21.md) | hnswlib SQ / Faiss HNSW+SQ notes. | **Technical Essay: Lab-Note Drafting** | **secan (required)**: **`HNSWSQIndex`** (HNSW over SQ8/SQ4). Pareto vs **hnswlib/Faiss** on **SIFT + 768-D**. Tag `v1.0-cpu-complete`. |
| **Saturday** | Sat Nov 22 | [`Day 083`](../days/month-03/day-083-2026-11-22.md) | **09:00–13:00**: Pure Math Block 1 (Theory & Derivations) | **14:00–18:00**: FREE / Rest / Buffer | Weekend Deep Work |
| **Sunday** | Sun Nov 23 | [`Day 084`](../days/month-03/day-084-2026-11-23.md) | **09:00–13:00**: Pure Math Block 2 (Problem Sets & Proofs) | **13:00–14:00**: Maintenance | Rest & Buffer |

---

## 📋 Daily Action Items & Deliverables (Week 12)

### 🔹 Monday, Mon Nov 17 ([`Day 078`](../days/month-03/day-078-2026-11-17.md))
* `[ ]` **Core**: Implement SVD-based vector whitening transform $x_{\text{white}} = \Lambda^{-1/2} Q^T (x - \mu)$; compute hubness skewness $S_{N_k}$ before/after.
* `⭐ Optional / Stretch`: Test dimension reduction via truncated SVD ($768\text{D} \to 256\text{D}$) and measure recall retention.

### 🔹 Tuesday, Tue Nov 18 ([`Day 079`](../days/month-03/day-079-2026-11-18.md))
* `[ ]` **Core**: Build `nanobind` Python bindings exposing `HNSWIndex`, `IVFPQIndex`, `HNSWSQIndex`, and `LSMIndex` directly to Python without REST overhead.
* `⭐ Optional / Stretch`: Implement zero-copy NumPy buffer protocol in `nanobind` avoiding vector copies across the Python/C++ boundary.

### 🔹 Wednesday, Wed Nov 19 ([`Day 080`](../days/month-03/day-080-2026-11-19.md))
* `[ ]` **Core**: Optimize HNSW graph traversal using bounded flat heap and 64-bit word-aligned bitset visited table.
* `⭐ Optional / Stretch`: Benchmark branchless heap sift-down vs `std::priority_queue` in HNSW beam search.

### 🔹 Thursday, Thu Nov 20 ([`Day 081`](../days/month-03/day-081-2026-11-20.md))
* `[ ]` **Core**: Finalize `IVFPQIndex` with asymmetric ADC lookups; generate Pareto Recall@10 vs QPS curve against `faiss.IndexIVFPQ` on SIFT1M.
* `⭐ Optional / Stretch`: Measure index memory footprint comparison (secan IVFPQ vs Faiss IVFPQ).

### 🔹 Friday, Fri Nov 21 ([`Day 082`](../days/month-03/day-082-2026-11-21.md))
* `[ ]` **Core**: Implement `HNSWSQIndex` (HNSW graph routing over SQ8/SQ4 quantized vectors); generate Pareto curve vs `hnswlib` on SIFT and 768-D text. Tag `v1.0-cpu-complete`.
* `⭐ Optional / Stretch`: Compile full Block I benchmark table with memory footprints, indexing times, and QPS at Recall@10 $\ge 0.95$.

### 🔹 Saturday, Sat Nov 22 ([`Day 083`](../days/month-03/day-083-2026-11-22.md))
* `[ ]` **Core (09:00–13:00)**: Write and ship **Technical Essay 12**: *"Singular Value Decomposition and Composed Vector Indexes: Pareto Evaluation of IVF-PQ and HNSW-SQ vs Faiss"* to `goals/essays/essay_12.md`.
* `[ ]` **Core (14:00–18:00)**: Execute Saturday Deep Learning from Scratch track (**🧠 DL weekend (required)**: Export Week 6 InfoNCE bi-encoder with `torch.onnx.export` (dynamic batch). Run **ONNX Runtime** `InferenceSession`; max abs / cosine error vs PyTorch on a fixed batch. Emit 768-D query/doc `.fvecs` via ORT and re-ingest into `HNSWSQIndex` / `IVFPQIndex` — confirm Recall@10 matches the Week 8 Fri PyTorch path within tolerance. **No** onnxruntime C++ inside `secan` (nanobind + ORT Python is enough). ColBERT ONNX = stretch later.).
* `⭐ Optional / Stretch`: Run automated test suite validating PyTorch numerical gradient and attention equivalence.

### 🔹 Sunday, Sun Nov 23 ([`Day 084`](../days/month-03/day-084-2026-11-23.md))
* `[ ]` **Core (09:00–13:00)**: Execute Monthly Research Milestone for Month 3 (`research/2026-11-late-interaction-lsm/`): run empirical benchmarks and record data tables.
* `⭐ Optional / Stretch`: Draft / update section figures and experimental limitations.

---

## ⛔ What NOT to Overspend Time On (Week 12 Time Traps)

* ❌ **Do NOT** build REST / HTTP API endpoints in C++ (e.g. Crow / Pistache)—Python interacts with `secan` directly via zero-copy `nanobind`.
* ❌ **Do NOT** embed `onnxruntime` C++ library into `secan`—run ONNX Runtime in Python and pass raw contiguous float pointers to `secan`.
* ❌ **Do NOT** attempt full SVD matrix solvers from scratch—use Eigen or NumPy SVD for offline whitening matrices.

---

## 📝 Weekend Deliverables

### ✍️ Technical Essay 12 (Saturday 09:00–13:00)
* **Title**: *"Singular Value Decomposition and Composed Vector Indexes: Pareto Evaluation of IVF-PQ and HNSW-SQ vs Faiss"*
* **Target File**: `~/personal/goals/essays/essay_12.md`
* **5-Part Structure**:
  1. **Mathematical Foundation**: Core theorems, derivations, and formal definitions.
  2. **The Systems Bottleneck**: Hardware limitation (memory bandwidth, port contention, cache line splits, warp stalls).
  3. **The Engine Architecture**: Exact data structures and SIMD/CUDA kernel design implemented in `secan`.
  4. **Empirical Benchmarks**: Perf counter tables, latency percentiles ($p50/p95/p99$), and QPS curves.
  5. **Key Takeaway**: Architectural rule of thumb for production AI systems.

### 🧠 Deep Learning Track (Saturday 14:00–18:00)
* **Task**: **🧠 DL weekend (required)**: Export Week 6 InfoNCE bi-encoder with `torch.onnx.export` (dynamic batch). Run **ONNX Runtime** `InferenceSession`; max abs / cosine error vs PyTorch on a fixed batch. Emit 768-D query/doc `.fvecs` via ORT and re-ingest into `HNSWSQIndex` / `IVFPQIndex` — confirm Recall@10 matches the Week 8 Fri PyTorch path within tolerance. **No** onnxruntime C++ inside `secan` (nanobind + ORT Python is enough). ColBERT ONNX = stretch later.

### 🔬 Monthly Research Milestone (Sunday 09:00–13:00)
* **Paper**: *"Streaming Late Interaction: Evaluating PLAID Centroid Inverted Lists vs MUVERA Fixed-Dimensional Encodings in Dynamic LSM Vector Storage"*
* **Workspace**: `research/2026-11-late-interaction-lsm/`
* **Publish Deadline**: **Sun Nov 29**
