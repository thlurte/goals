# 🚀 Week 18 Execution Playbook

> **Theme**: Markov Chains, Transition Matrices & GPU FastScan  
> **Calendar Dates**: Mon Dec 29 – Sun Jan 4 (2026-12-29 to 2027-01-04)  
> **Parent Month Dashboard**: [Month 5 (Jan 2027)](month-05-jan.md) · **Block**: II — GPU Specialization

| | | |
|:---|:---|:---|
| [← Week 17](week-17.md) | [Month 5 (Jan 2027) Dashboard](month-05-jan.md) | [Week 19 →](week-19.md) |

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
| **Monday** | Mon Dec 29 | [`Day 120`](../days/month-05/day-120-2026-12-29.md) | Faiss GPU PQ documentation: storing query lookup tables in GPU shared memory. | **Monthly Research: Planning & Literature Synthesis** | **secan**: Implement GPU PQ ADC kernel: upload query LUT to shared memory. Threads compute PQ distances via shared-memory lookups. |
| **Tuesday** | Tue Dec 30 | [`Day 121`](../days/month-05/day-121-2026-12-30.md) | **CUDA-GUIDE Shared Memory**: Bank conflicts, padding strategies, broadcast mechanisms. | **DL Track (Part 1): Architecture & Tensor Shapes** | **secan**: Optimize shared-memory LUT layout: apply padding to ensure conflict-free broadcast reads during distance accumulation. |
| **Wednesday** | Wed Dec 31 | [`Day 122`](../days/month-05/day-122-2026-12-31.md) | Research: GPU FastScan architecture using warp-level registers. | **DL Track (Part 2): Training Loop & Verification** | **secan**: Implement **GPU 4-bit FastScan**: store 16 centroid distances in warp registers. Execute lookups via `__shfl_sync(mask, dist, code)`. |
| **Thursday** | Thu Jan 1 | [`Day 123`](../days/month-05/day-123-2027-01-01.md) | E | **Monthly Research: Sweeps & Data Logging** | }$ is the stationary distribution on an undirected graph with degree $d_i$. |
| **Friday** | Fri Jan 2 | [`Day 124`](../days/month-05/day-124-2027-01-02.md) | Review all GPU quantization kernels. | **Technical Essay: Lab-Note Drafting** | **secan**: Benchmark GPU-FP32 vs GPU-FP16 vs GPU-SQ8 vs GPU-IVF-PQ vs GPU-FastScan. Create comprehensive comparison table. |
| **Saturday** | Sat Jan 3 | [`Day 125`](../days/month-05/day-125-2027-01-03.md) | **09:00–13:00**: Pure Math Block 1 (Theory & Derivations) | **14:00–18:00**: FREE / Rest / Buffer | Weekend Deep Work |
| **Sunday** | Sun Jan 4 | [`Day 126`](../days/month-05/day-126-2027-01-04.md) | **09:00–13:00**: Pure Math Block 2 (Problem Sets & Proofs) | **13:00–14:00**: Maintenance | Rest & Buffer |

---

## 📋 Daily Action Items & Deliverables (Week 18)

### 🔹 Monday, Mon Dec 29 ([`Day 120`](../days/month-05/day-120-2026-12-29.md))
* `[ ]` **Core**: Implement GPU PQ ADC kernel staging query centroid lookup tables ($M \times 256$ floats) in shared memory.
* `⭐ Optional / Stretch`: Derive the exact transition probability matrix of random walk beam search on a small $k$-regular graph.

### 🔹 Tuesday, Tue Dec 30 ([`Day 121`](../days/month-05/day-121-2026-12-30.md))
* `[ ]` **Core**: Optimize shared-memory LUT layout with stride padding; verify 0 shared-memory bank conflicts in `ncu`.
* `⭐ Optional / Stretch`: Benchmark shared memory broadcast efficiency when all 32 warp threads access the identical centroid entry.

### 🔹 Wednesday, Wed Dec 31 ([`Day 122`](../days/month-05/day-122-2026-12-31.md))
* `[ ]` **Core**: Implement GPU 4-bit FastScan storing 16 centroid distances across 16 warp registers; execute table lookups via `__shfl_sync(mask, dist, code)`.
* `⭐ Optional / Stretch`: Measure register pressure and warp occupancy trade-offs in GPU FastScan kernel.

### 🔹 Thursday, Thu Jan 1 ([`Day 123`](../days/month-05/day-123-2027-01-01.md))
* `[ ]` **Core**: Compose GPU IVF-PQ index (GPU coarse quantizer + GPU FastScan kernel inside selected cells).
* `⭐ Optional / Stretch`: Implement asynchronous batch cell scanning using multiple CUDA streams.

### 🔹 Friday, Fri Jan 2 ([`Day 124`](../days/month-05/day-124-2027-01-02.md))
* `[ ]` **Core**: Benchmark full suite: GPU-FP32 vs GPU-FP16 vs GPU-SQ8 vs GPU-IVF-PQ vs GPU-FastScan; produce comprehensive performance matrix.
* `⭐ Optional / Stretch`: Compute total memory bandwidth efficiency percentage against theoretical GPU VRAM bandwidth limit.

### 🔹 Saturday, Sat Jan 3 ([`Day 125`](../days/month-05/day-125-2027-01-03.md))
* `[ ]` **Core (09:00–13:00)**: Write and ship **Technical Essay 18**: *"Markov Chains, Graph Random Walks, and High-Throughput GPU Quantized FastScan"* to `goals/essays/essay_18.md`.
* `[ ]` **Core (14:00–18:00)**: Execute Saturday Deep Learning from Scratch track ().
* `⭐ Optional / Stretch`: Run automated test suite validating PyTorch numerical gradient and attention equivalence.

### 🔹 Sunday, Sun Jan 4 ([`Day 126`](../days/month-05/day-126-2027-01-04.md))
* `[ ]` **Core (09:00–13:00)**: Execute Monthly Research Milestone for Month 5 (`research/2027-01-paging-vs-quantizing-kv/`): run empirical benchmarks and record data tables.
* `⭐ Optional / Stretch`: Draft / update section figures and experimental limitations.

---

## ⛔ What NOT to Overspend Time On (Week 18 Time Traps)

* ❌ **Do NOT** implement 8-bit FastScan—4-bit FastScan fits 16 centroids directly in 16 warp registers for zero-shared-memory execution.
* ❌ **Do NOT** spend hours proving stationary distributions for continuous-state Markov processes—focus on finite discrete-state transition matrices.
* ❌ **Do NOT** tune codebook centroids on GPU—train codebooks offline on CPU/NumPy and upload final centroids to device memory.

---

## 📝 Weekend Deliverables

### ✍️ Technical Essay 18 (Saturday 09:00–13:00)
* **Title**: *"Markov Chains, Graph Random Walks, and High-Throughput GPU Quantized FastScan"*
* **Target File**: `~/personal/goals/essays/essay_18.md`
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
