# 🚀 Week 16 Execution Playbook

> **Theme**: VS Spine Capstone — GPU IVF + DiskANN + Hybrid WAND  
> **Calendar Dates**: Mon Dec 15 – Sun Dec 21 (2026-12-15 to 2026-12-21)  
> **Parent Month Dashboard**: [Month 4 (Dec 2026)](month-04-dec.md) · **Block**: I — Vector Search Engine

| | | |
|:---|:---|:---|
| [← Week 15](week-15.md) | [Month 4 (Dec 2026) Dashboard](month-04-dec.md) | [Week 17 →](week-17.md) |

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
| **Monday** | Mon Dec 15 | [`Day 106`](../days/month-04/day-106-2026-12-15.md) | Faiss GPU 2019 §1–3: billion-scale GPU similarity search. | **Monthly Research: Planning & Literature Synthesis** | **secan**: GPU IVF memory layout: coarse centroids; cell vectors + offset table. |
| **Tuesday** | Tue Dec 16 | [`Day 107`](../days/month-04/day-107-2026-12-16.md) | Faiss GPU §4–5: GPU $k$-selection, warp-cooperative list scanning. | **DL Track (Part 1): Architecture & Tensor Shapes** | **secan**: GPU coarse quantizer + top-`nprobe` cell select; warp-cooperative cell scan. |
| **Wednesday** | Wed Dec 17 | [`Day 108`](../days/month-04/day-108-2026-12-17.md) | **CUDA-GUIDE Streams & Events**. | **DL Track (Part 2): Training Loop & Verification** | **secan**: CUDA stream pipelining for IVF batches; quick SQ8-in-cell stretch if time. Tag `v1.1-gpu-ivf`. |
| **Thursday** | Thu Dec 18 | [`Day 109`](../days/month-04/day-109-2026-12-18.md) | DiskANN: **Vamana graph construction** (α-prune) + `io_uring` fetch. | **Monthly Research: Sweeps & Data Logging** | **secan (required)**: Implement **Vamana prune** (build graph, not only SSD fetch); compressed vectors in RAM; FP32 via `io_uring`. Recall vs in-RAM. |
| **Friday** | Fri Dec 19 | [`Day 110`](../days/month-04/day-110-2026-12-19.md) | Ding & Suel WAND; **RRF** (Cormack et al.). | **Technical Essay: Lab-Note Drafting** | **secan (required)**: BM25 + Block-Max WAND; fuse via **RRF** *and* linear $\alpha$. Query-time $\alpha$ / k sweep. SPLADE = stretch. Tag `v1.2-vs-spine-complete`. |
| **Saturday** | Sat Dec 20 | [`Day 111`](../days/month-04/day-111-2026-12-20.md) | **09:00–13:00**: Pure Math Block 1 (Theory & Derivations) | **14:00–18:00**: FREE / Rest / Buffer | Weekend Deep Work |
| **Sunday** | Sun Dec 21 | [`Day 112`](../days/month-04/day-112-2026-12-21.md) | **09:00–13:00**: Pure Math Block 2 (Problem Sets & Proofs) | **13:00–14:00**: Maintenance | Rest & Buffer |

---

## 📋 Daily Action Items & Deliverables (Week 16)

### 🔹 Monday, Mon Dec 15 ([`Day 106`](../days/month-04/day-106-2026-12-15.md))
* `[ ]` **Core**: Implement GPU IVF memory layout: store coarse centroids and jagged inverted list arrays with prefix sum offset table in device memory.
* `⭐ Optional / Stretch`: Implement zero-copy unified memory (`cudaMallocManaged`) coarse centroid lookup.

### 🔹 Tuesday, Tue Dec 16 ([`Day 107`](../days/month-04/day-107-2026-12-16.md))
* `[ ]` **Core**: Implement GPU coarse cell routing kernel finding top-`nprobe` nearest centroids followed by warp-cooperative inverted list scanning.
* `⭐ Optional / Stretch`: Profile warp divergence when inverted lists have non-uniform lengths; implement dynamic warp-balancing scheduler.

### 🔹 Wednesday, Wed Dec 17 ([`Day 108`](../days/month-04/day-108-2026-12-17.md))
* `[ ]` **Core**: Implement CUDA stream pipelining overlapping query upload, cell scan, and top-$k$ download. Tag `v1.1-gpu-ivf`.
* `⭐ Optional / Stretch`: Implement SQ8 integer quantization inside GPU IVF lists to double effective VRAM vector capacity.

### 🔹 Thursday, Thu Dec 18 ([`Day 109`](../days/month-04/day-109-2026-12-18.md))
* `[ ]` **Core**: Implement Vamana graph construction ($\alpha$-pruning heuristic); implement asynchronous out-of-core SSD vector fetch via Linux `io_uring` with `O_DIRECT` on **Deep10M** (~4 GB core verification dataset; full Deep1B staged for dedicated NVMe).
* `⭐ Optional / Stretch`: Benchmark `IORING_SETUP_SQPOLL` zero-syscall kernel polling + `IORING_REGISTER_BUFFERS` vs standard `io_uring_enter()` syscall submissions on NVMe random reads.

### 🔹 Friday, Fri Dec 19 ([`Day 110`](../days/month-04/day-110-2026-12-19.md))
* `[ ]` **Core**: Implement BM25 inverted index + Block-Max WAND early termination; fuse dense ANN candidates with sparse BM25 scores via Reciprocal Rank Fusion (RRF). Tag `v1.2-vs-spine-complete`.
* `⭐ Optional / Stretch`: Compare retrieval quality (NDCG@10) of RRF rank fusion vs linear weighted score interpolation ($\alpha \cdot S_{\text{dense}} + (1-\alpha) \cdot S_{\text{sparse}}$).

### 🔹 Saturday, Sat Dec 20 ([`Day 111`](../days/month-04/day-111-2026-12-20.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 1**: Theory, concepts, and analytical derivations (textbook chapters & core proofs).
* `[ ]` **Core (15:00–16:30)**: **Weekend Reading Sanctuary**: Literature / Philosophy deep reading.
* `⭐ Optional / Stretch`: 100% Free / Rest / Recovery buffer.
### 🔹 Sunday, Sun Dec 21 ([`Day 112`](../days/month-04/day-112-2026-12-21.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 2**: Advanced theorems, problem sets, and chalkboard proof defense.
* `[ ]` **Core (13:00–14:00)**: **Runtime Maintenance**: Quick 30–60 min check for `limbed` / `ggmbed` (`embed-runtimes`).
* `[ ]` **Core (15:00–16:45)**: **Penrose Sunday**: *The Road to Reality* (1 chapter/week, visual geometry focus).
---

## ⛔ What NOT to Overspend Time On (Week 16 Time Traps)

* ❌ **Do NOT** implement SPLADE sparse neural models—BM25 + Block-Max WAND is the required sparse baseline.
* ❌ **Do NOT** download and run full 400 GB Deep1B during weekday coding blocks—**Deep10M (~4 GB)** is the core proof of out-of-core `io_uring` execution; full Deep1B is strictly for high-capacity NVMe overnight runs.
* ❌ **Do NOT** build complex C++ REST server wrappers—keep `secan` exposed via `nanobind` and CLI.

---

## 📝 Weekend Deliverables

### ✍️ Technical Essay 16 (Saturday 09:00–13:00)
* **Title**: *"Closing the Vector Search Spine: GPU IVF Streaming, Vamana Graph Pruning, and Out-of-Core `io_uring`"*
* **Target File**: `~/personal/goals/essays/essay_16.md`
* **5-Part Structure**:
  1. **Mathematical Foundation**: Core theorems, derivations, and formal definitions.
  2. **The Systems Bottleneck**: Hardware limitation (memory bandwidth, port contention, cache line splits, warp stalls).
  3. **The Engine Architecture**: Exact data structures and SIMD/CUDA kernel design implemented in `secan`.
  4. **Empirical Benchmarks**: Perf counter tables, latency percentiles ($p50/p95/p99$), and QPS curves.
  5. **Key Takeaway**: Architectural rule of thumb for production AI systems.

### 🧠 Deep Learning Track (Saturday 14:00–18:00)
* **Task**: 

### 🔬 Monthly Research Milestone (Sunday 09:00–13:00)
* **Paper**: *"Billion-Scale Retrieval Frontiers: Comparing In-VRAM GPU IVF and Asynchronous NVMe DiskANN Under Concurrent Query Pressure"*
* **Workspace**: `research/2026-12-three-paths-spine/`
* **Publish Deadline**: **Sun Dec 27**
