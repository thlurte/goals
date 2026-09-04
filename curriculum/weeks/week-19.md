# 🚀 Week 19 Execution Playbook

> **Theme**: Mathematical Statistics, MLE, PagedAttention & KV Compression  
> **Calendar Dates**: Mon Jan 5 – Sun Jan 11 (2027-01-05 to 2027-01-11)  
> **Parent Month Dashboard**: [Month 5 (Jan 2027)](month-05-jan.md) · **Block**: II — GPU Specialization

| | | |
|:---|:---|:---|
| [← Week 18](week-18.md) | [Month 5 (Jan 2027) Dashboard](month-05-jan.md) | [Week 20 →](week-20.md) |

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
| **Monday** | Mon Jan 5 | [`Day 127`](../days/month-05/day-127-2027-01-05.md) | vLLM Paper §1–3: The KV Cache fragmentation problem in LLMs ($60\%–80\%$ memory wasted on over-allocation). | **Monthly Research: Planning & Literature Synthesis** | **Python/CUDA**: Implement `BlockTable` data structure in PyTorch: maps logical sequence tokens to physical GPU memory blocks (block size 16). |
| **Tuesday** | Tue Jan 6 | [`Day 128`](../days/month-05/day-128-2027-01-06.md) | vLLM Paper §4: PagedAttention kernel design: reading $K, V$ blocks via block lookup table in CUDA. | **DL Track (Part 1): Architecture & Tensor Shapes** | **CUDA**: Implement **PagedAttention CUDA kernel**: during self-attention, resolve physical $K, V$ block pointers on-the-fly via block table. |
| **Wednesday** | Wed Jan 7 | [`Day 129`](../days/month-05/day-129-2027-01-07.md) | [TurboQuant](https://research.google/blog/turboquant-redefining-ai-efficiency-with-extreme-compression/): KV experiments (LongBench, RULER, needle-in-haystack); PolarQuant + QJL residual as bias killer for attention scores. | **DL Track (Part 2): Training Loop & Verification** | **secan**: Build unified `GpuIndex` wrapper class: device memory lifecycle, async transfers, kernel launches, RAII cleanup. |
| **Thursday** | Thu Jan 8 | [`Day 130`](../days/month-05/day-130-2027-01-08.md) | **PMPP Ch 19**: Heterogeneous CPU+GPU workload partitioning. | **Monthly Research: Sweeps & Data Logging** | **secan**: Implement **CPU↔GPU hybrid fallback**: partition oversized dataset into GPU VRAM (fast) and CPU RAM (AVX2). Merge results. |
| **Friday** | Fri Jan 9 | [`Day 131`](../days/month-05/day-131-2027-01-09.md) | Profile PagedAttention vs standard KV cache memory; contrast with TurboQuant bitwidth story (paging ≠ quantizing). | **Technical Essay: Lab-Note Drafting** | **secan**: Benchmark query batch sizes ($B=1, 10, 100, 1000$). Plot the CPU vs GPU crossover curve. |
| **Saturday** | Sat Jan 10 | [`Day 132`](../days/month-05/day-132-2027-01-10.md) | **09:00–13:00**: Pure Math Block 1 (Theory & Derivations) | **14:00–18:00**: FREE / Rest / Buffer | Weekend Deep Work |
| **Sunday** | Sun Jan 11 | [`Day 133`](../days/month-05/day-133-2027-01-11.md) | **09:00–13:00**: Pure Math Block 2 (Problem Sets & Proofs) | **13:00–14:00**: Maintenance | Rest & Buffer |

---

## 📋 Daily Action Items & Deliverables (Week 19)

### 🔹 Monday, Mon Jan 5 ([`Day 127`](../days/month-05/day-127-2027-01-05.md))
* `[ ]` **Core**: Implement PyTorch `BlockTable` data structure mapping logical sequence tokens to physical GPU memory pages (block size 16).
* `⭐ Optional / Stretch`: Simulate KV cache memory fragmentation under random sequence length arrivals (verify $>60\%$ memory savings).

### 🔹 Tuesday, Tue Jan 6 ([`Day 128`](../days/month-05/day-128-2027-01-06.md))
* `[ ]` **Core**: Implement PagedAttention CUDA kernel resolving physical $K, V$ block pointers on-the-fly via block table during attention decoding.
* `⭐ Optional / Stretch`: Add support for variable sequence lengths in a single batched kernel launch.

### 🔹 Wednesday, Wed Jan 7 ([`Day 129`](../days/month-05/day-129-2027-01-07.md))
* `[ ]` **Core**: Build unified `GpuIndex` wrapper managing device memory lifecycle, async streams, and RAII cleanup.
* `⭐ Optional / Stretch`: Design a PolarQuant 3-bit KV compression sketch storing quantized $K$ cache blocks inside the PagedAttention block table.

### 🔹 Thursday, Thu Jan 8 ([`Day 130`](../days/month-05/day-130-2027-01-08.md))
* `[ ]` **Core**: Implement heterogeneous CPU+GPU fallback pipeline: retain hot dataset in GPU VRAM and overflow in host RAM; merge top-$k$ results.
* `⭐ Optional / Stretch`: Measure end-to-end query latency as a function of GPU VRAM partition fraction (0% to 100%).

### 🔹 Friday, Fri Jan 9 ([`Day 131`](../days/month-05/day-131-2027-01-09.md))
* `[ ]` **Core**: Benchmark query batch sizes $B \in [1, 1000]$; plot CPU AVX2 vs GPU latency crossover curve.
* `⭐ Optional / Stretch`: Compute the exact QPS break-even point where GPU throughput justifies PCIe transfer latency overhead.

### 🔹 Saturday, Sat Jan 10 ([`Day 132`](../days/month-05/day-132-2027-01-10.md))
* `[ ]` **Core (09:00–13:00)**: Write and ship **Technical Essay 19**: *"Virtual Memory for Attention: Paged KV Blocks and Extreme PolarQuant 3-Bit Compression"* to `goals/essays/essay_19.md`.
* `[ ]` **Core (14:00–18:00)**: Execute Saturday Deep Learning from Scratch track ().
* `⭐ Optional / Stretch`: Run automated test suite validating PyTorch numerical gradient and attention equivalence.

### 🔹 Sunday, Sun Jan 11 ([`Day 133`](../days/month-05/day-133-2027-01-11.md))
* `[ ]` **Core (09:00–13:00)**: Execute Monthly Research Milestone for Month 5 (`research/2027-01-paging-vs-quantizing-kv/`): run empirical benchmarks and record data tables.
* `⭐ Optional / Stretch`: Draft / update section figures and experimental limitations.

---

## ⛔ What NOT to Overspend Time On (Week 19 Time Traps)

* ❌ **Do NOT** implement dynamic memory defragmentation compaction algorithms—block paging naturally eliminates internal and external fragmentation.
* ❌ **Do NOT** build a full LLM serving scheduler with continuous batching—focus strictly on the `BlockTable` address resolution kernel.
* ❌ **Do NOT** solve advanced hypothesis testing Neyman-Pearson lemma optimization problems by hand—understand Type I/II error trade-offs and move on.

---

## 📝 Weekend Deliverables

### ✍️ Technical Essay 19 (Saturday 09:00–13:00)
* **Title**: *"Virtual Memory for Attention: Paged KV Blocks and Extreme PolarQuant 3-Bit Compression"*
* **Target File**: `~/personal/goals/essays/essay_19.md`
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
