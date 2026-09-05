# 🚀 Week 18 Execution Playbook

> **Theme**: Markov Chains, Transition Matrices & GPU FastScan  
> **Calendar Dates**: Sat Jan 2 – Fri Jan 8 (2027-01-02 to 2027-01-08)
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
│ 📐 Saturday 09:00 – 13:00    │ Pure Mathematics Block 1 (Theory, Concepts, Derivations)               │
│ ☕ Saturday 15:00 – 16:30    │ Weekend Reading Immersion (Pirsig / GEB / Literature)                  │
│ 📐 Sunday 09:00 – 13:00      │ Pure Mathematics Block 2 (Problem Sets, Chalkboard Proofs)             │
│ 🔧 Sunday 13:00 – 14:00      │ Runtime Maintenance (limbed / ggmbed check)                            │
│ 🌌 Sunday 15:00 – 16:45      │ Penrose Sunday: The Road to Reality (1 chapter/week, visual geometry)  │
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
| **Saturday** | Sat Jan 2 | [`Day 120`](../days/month-05/day-120-2027-01-02.md) | **09:00–13:00**: Pure Math Block 1 (Theory & Derivations) | **14:00–18:00**: FREE / Rest / Buffer | Weekend Deep Work |
| **Sunday** | Sun Jan 3 | [`Day 121`](../days/month-05/day-121-2027-01-03.md) | **09:00–13:00**: Pure Math Block 2 (Problem Sets & Proofs) | **13:00–14:00**: Maintenance | Rest & Buffer |
| **Monday** | Mon Jan 4 | [`Day 122`](../days/month-05/day-122-2027-01-04.md) | Faiss GPU PQ documentation: storing query lookup tables in GPU shared memory. | **Monthly Research: Planning & Literature Synthesis** | **secan**: Implement GPU PQ ADC kernel: upload query LUT to shared memory. Threads compute PQ distances via shared-memory lookups. |
| **Tuesday** | Tue Jan 5 | [`Day 123`](../days/month-05/day-123-2027-01-05.md) | **CUDA-GUIDE Shared Memory**: Bank conflicts, padding strategies, broadcast mechanisms. | **DL Track (Part 1): Architecture & Tensor Shapes** | **secan**: Optimize shared-memory LUT layout: apply padding to ensure conflict-free broadcast reads during distance accumulation. |
| **Wednesday** | Wed Jan 6 | [`Day 124`](../days/month-05/day-124-2027-01-06.md) | Research: GPU FastScan architecture using warp-level registers. | **DL Track (Part 2): Training Loop & Verification** | **secan**: Implement **GPU 4-bit FastScan**: store 16 centroid distances in warp registers. Execute lookups via `__shfl_sync(mask, dist, code)`. |
| **Thursday** | Thu Jan 7 | [`Day 125`](../days/month-05/day-125-2027-01-07.md) | E | **Monthly Research: Sweeps & Data Logging** | }$ is the stationary distribution on an undirected graph with degree $d_i$. |
| **Friday** | Fri Jan 8 | [`Day 126`](../days/month-05/day-126-2027-01-08.md) | Review all GPU quantization kernels. | **Technical Essay: Lab-Note Drafting** | **secan**: Benchmark GPU-FP32 vs GPU-FP16 vs GPU-SQ8 vs GPU-IVF-PQ vs GPU-FastScan. Create comprehensive comparison table. |

---

## 📋 Daily Action Items & Deliverables (Week 18)

### 🔹 Saturday, Sat Jan 2 ([`Day 120`](../days/month-05/day-120-2027-01-02.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 1**: Theory, concepts, and analytical derivations (textbook chapters & core proofs).
* `[ ]` **Core (15:00–16:30)**: **Weekend Reading Sanctuary**: Literature / Philosophy deep reading.
* `⭐ Optional / Stretch`: 100% Free / Rest / Recovery buffer.

### 🔹 Sunday, Sun Jan 3 ([`Day 121`](../days/month-05/day-121-2027-01-03.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 2**: Advanced theorems, problem sets, and chalkboard proof defense.
* `[ ]` **Core (13:00–14:00)**: **Runtime Maintenance**: Quick 30–60 min check for `limbed` / `ggmbed` (`embed-runtimes`).
* `[ ]` **Core (15:00–16:45)**: **Penrose Sunday**: *The Road to Reality* (1 chapter/week, visual geometry focus).

### 🔹 Monday, Mon Jan 4 ([`Day 122`](../days/month-05/day-122-2027-01-04.md))
* `[ ]` **Core**: Implement GPU PQ ADC kernel staging query centroid lookup tables ($M \times 256$ floats) in shared memory.
* `⭐ Optional / Stretch`: Derive the exact transition probability matrix of random walk beam search on a small $k$-regular graph.


### 🔹 Tuesday, Tue Jan 5 ([`Day 123`](../days/month-05/day-123-2027-01-05.md))
* `[ ]` **Core**: Optimize shared-memory LUT layout with stride padding; verify 0 shared-memory bank conflicts in `ncu`.
* `⭐ Optional / Stretch`: Benchmark shared memory broadcast efficiency when all 32 warp threads access the identical centroid entry.


### 🔹 Wednesday, Wed Jan 6 ([`Day 124`](../days/month-05/day-124-2027-01-06.md))
* `[ ]` **Core**: Implement GPU 4-bit FastScan storing 16 centroid distances across 16 warp registers; execute table lookups via `__shfl_sync(mask, dist, code)`.
* `⭐ Optional / Stretch`: Measure register pressure and warp occupancy trade-offs in GPU FastScan kernel.


### 🔹 Thursday, Thu Jan 7 ([`Day 125`](../days/month-05/day-125-2027-01-07.md))
* `[ ]` **Core**: Compose GPU IVF-PQ index (GPU coarse quantizer + GPU FastScan kernel inside selected cells).
* `⭐ Optional / Stretch`: Implement asynchronous batch cell scanning using multiple CUDA streams.


### 🔹 Friday, Fri Jan 8 ([`Day 126`](../days/month-05/day-126-2027-01-08.md))
* `[ ]` **Core**: Benchmark full suite: GPU-FP32 vs GPU-FP16 vs GPU-SQ8 vs GPU-IVF-PQ vs GPU-FastScan; produce comprehensive performance matrix.
* `⭐ Optional / Stretch`: Compute total memory bandwidth efficiency percentage against theoretical GPU VRAM bandwidth limit.


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

### 🧠 Deep Learning Track (Tue/Wed 06:30–08:30 Morning Builder)
* **Task**: 

### 🔬 Monthly Research Milestone (FlashMaxSim Milestone 2 — Mon/Thu 06:30–08:30 Morning Builder)
* **Paper**: *"The Online Max Reduction Invariant & In-SRAM Accumulation Mechanics"*
* **Workspace**: `research/2027-01-cagra-warp-search/`
* **Publish Deadline**: **Sun Jan 31**
