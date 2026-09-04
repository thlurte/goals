# 🚀 Week 20 Execution Playbook

> **Theme**: Information Theory, Entropy, KL-Divergence & Multi-GPU NCCL  
> **Calendar Dates**: Mon Jan 12 – Sun Jan 18 (2027-01-12 to 2027-01-18)  
> **Parent Month Dashboard**: [Month 5 (Jan 2027)](month-05-jan.md) · **Block**: II — GPU Specialization

| | | |
|:---|:---|:---|
| [← Week 19](week-19.md) | [Month 5 (Jan 2027) Dashboard](month-05-jan.md) | [Week 21 →](week-21.md) |

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
| **Monday** | Mon Jan 12 | [`Day 134`](../days/month-05/day-134-2027-01-12.md) | **CUDA-GUIDE Multi-GPU**: `cudaSetDevice`, peer-to-peer memory access (`cudaDeviceEnablePeerAccess`). | **Monthly Research: Planning & Literature Synthesis** | **secan**: Implement dataset sharding: split $N$ vectors into $G$ shards. Upload shard $i$ to GPU $i$. Build `MultiGpuIndex` class. |
| **Tuesday** | Tue Jan 13 | [`Day 135`](../days/month-05/day-135-2027-01-13.md) | X)$, and the Chain Rule for Entropy: $H(X_1, \dots, X_n) = \sum H(X_i | **DL Track (Part 1): Architecture & Tensor Shapes** | X_{i-1}, \dots, X_1)$. |
| **Wednesday** | Wed Jan 14 | [`Day 136`](../days/month-05/day-136-2027-01-14.md) | Q)$. Rigorous proof that $D_{KL} \geq 0$ via Jensen's Inequality on convex functions. | **DL Track (Part 2): Training Loop & Verification** | Faiss multi-GPU implementation: replicated coarse quantizer with sharded inverted lists. |
| **Thursday** | Thu Jan 15 | [`Day 137`](../days/month-05/day-137-2027-01-15.md) | NVLink vs PCIe inter-GPU bandwidth analysis. | **Monthly Research: Sweeps & Data Logging** | **secan**: Implement dynamic load balancing: redistribute heavy IVF cells across GPUs to prevent stragglers during multi-probe search. |
| **Friday** | Fri Jan 16 | [`Day 138`](../days/month-05/day-138-2027-01-16.md) | Measure multi-GPU scaling efficiency across 1, 2, and 4 GPUs on synthetic billion-scale data. | **Technical Essay: Lab-Note Drafting** | **secan**: Benchmark multi-GPU search on SIFT1M and large synthetic datasets. Measure scaling efficiency and communication overhead. |
| **Saturday** | Sat Jan 17 | [`Day 139`](../days/month-05/day-139-2027-01-17.md) | **09:00–13:00**: Pure Math Block 1 (Theory & Derivations) | **14:00–18:00**: FREE / Rest / Buffer | Weekend Deep Work |
| **Sunday** | Sun Jan 18 | [`Day 140`](../days/month-05/day-140-2027-01-18.md) | **09:00–13:00**: Pure Math Block 2 (Problem Sets & Proofs) | **13:00–14:00**: Maintenance | Rest & Buffer |

---

## 📋 Daily Action Items & Deliverables (Week 20)

### 🔹 Monday, Mon Jan 12 ([`Day 134`](../days/month-05/day-134-2027-01-12.md))
* `[ ]` **Core**: Implement dataset sharding across $G$ GPUs; build `MultiGpuIndex` managing per-device buffers with peer-to-peer access enabled.
* `⭐ Optional / Stretch`: Derive the maximum Shannon entropy of quantized embedding codes under uniform vs Gaussian coordinate distributions.

### 🔹 Tuesday, Tue Jan 13 ([`Day 135`](../days/month-05/day-135-2027-01-13.md))
* `[ ]` **Core**: Implement multi-GPU parallel scan merging per-GPU top-$k$ candidate heaps using `ncclAllGather`.
* `⭐ Optional / Stretch`: Benchmark NCCL ring-based collective transfer latency over NVLink vs PCIe bus.

### 🔹 Wednesday, Wed Jan 14 ([`Day 136`](../days/month-05/day-136-2027-01-14.md))
* `[ ]` **Core**: Implement multi-GPU IVF: replicate coarse centroids across all devices; distribute inverted lists across GPUs.
* `⭐ Optional / Stretch`: Measure multi-GPU speedup over single GPU on a 10M vector synthetic dataset.

### 🔹 Thursday, Thu Jan 15 ([`Day 137`](../days/month-05/day-137-2027-01-15.md))
* `[ ]` **Core**: Implement dynamic cell redistribution to eliminate GPU load imbalance under skewed query workloads.
* `⭐ Optional / Stretch`: Profile GPU execution timeline in Nsight Systems (`nsys`) to identify inter-GPU communication bubbles.

### 🔹 Friday, Fri Jan 16 ([`Day 138`](../days/month-05/day-138-2027-01-16.md))
* `[ ]` **Core**: Run multi-GPU scalability benchmark suite on multi-GPU hardware (local multi-GPU or RunPod 2–4× GPU instance); compute parallel scaling efficiency percentage across GPUs.
* `⭐ Optional / Stretch`: Test multi-GPU fault tolerance by simulating device dropout and dynamic shard re-routing.

### 🔹 Saturday, Sat Jan 17 ([`Day 139`](../days/month-05/day-139-2027-01-17.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 1**: Theory, concepts, and analytical derivations (textbook chapters & core proofs).
* `[ ]` **Core (15:00–16:30)**: **Weekend Reading Sanctuary**: Literature / Philosophy deep reading.
* `⭐ Optional / Stretch`: 100% Free / Rest / Recovery buffer.
### 🔹 Sunday, Sun Jan 18 ([`Day 140`](../days/month-05/day-140-2027-01-18.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 2**: Advanced theorems, problem sets, and chalkboard proof defense.
* `[ ]` **Core (13:00–14:00)**: **Runtime Maintenance**: Quick 30–60 min check for `limbed` / `ggmbed` (`embed-runtimes`).
* `[ ]` **Core (15:00–16:45)**: **Penrose Sunday**: *The Road to Reality* (1 chapter/week, visual geometry focus).
---

## ⛔ What NOT to Overspend Time On (Week 20 Time Traps)

* ❌ **Do NOT** implement multi-node distributed TCP network clustering—NCCL multi-GPU on a single multi-GPU host is the complete specialization target.
* ❌ **Do NOT** implement complex 2D tensor parallelism—data sharding with top-$k$ heap gathering (`ncclAllGather`) is the standard for vector search.
* ❌ **Do NOT** struggle with local hardware limitations—prototype via single-GPU multi-stream simulation locally, then launch a short RunPod multi-GPU instance (2–4× GPUs) on Friday to collect genuine NCCL NVLink/PCIe scaling metrics.

---

## 📝 Weekend Deliverables

### ✍️ Technical Essay 20 (Saturday 09:00–13:00)
* **Title**: *"Information Theory and Ring Collectives: Shannon Entropy, KL-Divergence, and Multi-GPU NCCL Search"*
* **Target File**: `~/personal/goals/essays/essay_20.md`
* **5-Part Structure**:
  1. **Mathematical Foundation**: Core theorems, derivations, and formal definitions.
  2. **The Systems Bottleneck**: Hardware limitation (memory bandwidth, port contention, cache line splits, warp stalls).
  3. **The Engine Architecture**: Exact data structures and SIMD/CUDA kernel design implemented in `secan`.
  4. **Empirical Benchmarks**: Perf counter tables, latency percentiles ($p50/p95/p99$), and QPS curves.
  5. **Key Takeaway**: Architectural rule of thumb for production AI systems.

### 🧠 Deep Learning Track (Saturday 14:00–18:00)
* **Task**: 

### 🔬 Monthly Research Milestone (Sunday 09:00–13:00)
* **Paper**: *"Paging vs. Quantizing LLM KV Caches: Memory Fragmentation, Dequantization Overhead, and Serving Throughput at Long Contexts"*
* **Workspace**: `research/2027-01-paging-vs-quantizing-kv/`
* **Publish Deadline**: **Sun Jan 31**
