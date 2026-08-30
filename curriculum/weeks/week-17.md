# 🚀 Week 17 Execution Playbook

> **Theme**: Limit Theorems, LLN, CLT, Inequalities & CAGRA GPU Graphs  
> **Calendar Dates**: Mon Dec 22 – Sun Dec 28 (2026-12-22 to 2026-12-28)  
> **Parent Month Dashboard**: [Month 5 (Jan 2027)](month-05-jan.md) · **Block**: II — GPU Specialization

| | | |
|:---|:---|:---|
| [← Week 16](week-16.md) | [Month 5 (Jan 2027) Dashboard](month-05-jan.md) | [Week 18 →](week-18.md) |

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
| **Monday** | Mon Dec 22 | [`Day 113`](../days/month-05/day-113-2026-12-22.md) | **PROB §10.1**: Probability inequalities: Markov's and Chebyshev's inequalities proofs and applications in tail bounds. | Research paper: *"CAGRA: Highly Parallel Graph Construction and ANN Search for GPUs"* (NVIDIA 2024) §1–4. | **secan**: Design GPU graph layout: store HNSW graph adjacency in GPU memory as a fixed-degree CSR array with padding. |
| **Tuesday** | Tue Dec 23 | [`Day 114`](../days/month-05/day-114-2026-12-23.md) | **PROB §10.2**: Chernoff bounds: exponential moment bounds $P(X \geq a) \leq \min_{t > 0} \frac{M_X(t)}{e^{ta}}$. Tail bounds for sums of random variables. | CAGRA paper §5–6: Search kernel design, warp-level parallel beam search, avoiding dynamic queues on GPU. | **secan**: Implement **GPU graph search kernel**: each warp processes 1 query. 32 threads in warp evaluate 32 candidate neighbors in parallel. |
| **Wednesday** | Wed Dec 24 | [`Day 115`](../days/month-05/day-115-2026-12-24.md) | **PROB §10.3**: The Law of Large Numbers (LLN): Weak Law of Large Numbers proof via Chebyshev; Strong Law of Large Numbers (Borel-Cantelli lemmas). | **CUDA-GUIDE Warp Primitives**: `__ballot_sync`, `__any_sync`, warp-local bitfield operations. | **secan**: Implement warp-level visited set using `__ballot_sync` bitfields. Implement warp-level top-$k$ beam with shuffle min-reduction. |
| **Thursday** | Thu Dec 25 | [`Day 116`](../days/month-05/day-116-2026-12-25.md) | **PROB §10.4**: The Central Limit Theorem (CLT): Step-by-step rigorous proof using Taylor expansion of MGFs. | **PMPP Ch 9**: Parallel Prefix Sum (Scan) for compacting candidate neighbor lists on GPU. | **secan**: Implement multi-query parallel graph search: launch grid of warps. Benchmark throughput vs CPU HNSW. |
| **Friday** | Fri Dec 26 | [`Day 117`](../days/month-05/day-117-2026-12-26.md) | **PROB §10.5**: Applications of CLT in statistical error estimation and confidence intervals. | Profile GPU graph search with `ncu`: measure compute-to-memory stall ratio. | **secan**: Optimize GPU graph search: add shared memory caching for frequently visited upper-layer hub nodes. |
| **Saturday** | Sat Dec 27 | [`Day 118`](../days/month-05/day-118-2026-12-27.md) | **09:00–13:00**: Essay 17 | **14:00–18:00**: Deep Learning Track | Deep Learning from Scratch (uv/PyTorch) |
| **Sunday** | Sun Dec 28 | [`Day 119`](../days/month-05/day-119-2026-12-28.md) | **09:00–13:00**: Monthly Research | Research Experimentation | Rest & Subconscious Incubation |

---

## 📋 Daily Action Items & Deliverables (Week 17)

### 🔹 Monday, Mon Dec 22 ([`Day 113`](../days/month-05/day-113-2026-12-22.md))
* `[ ]` **Core**: Design GPU graph layout: store HNSW graph adjacency in GPU memory as a fixed-degree CSR array with padding.
* `⭐ Optional / Stretch`: Derive Chernoff bounds on the probability of graph search getting trapped in local minima.

### 🔹 Tuesday, Tue Dec 23 ([`Day 114`](../days/month-05/day-114-2026-12-23.md))
* `[ ]` **Core**: Implement GPU graph search kernel: 1 warp per query; 32 threads evaluate 32 candidate neighbors in parallel.
* `⭐ Optional / Stretch`: Profile warp divergence during neighbor list filtering with Nsight Compute (`ncu`).

### 🔹 Wednesday, Wed Dec 24 ([`Day 115`](../days/month-05/day-115-2026-12-24.md))
* `[ ]` **Core**: Implement warp-level visited set using `__ballot_sync` bitfields; implement warp-level top-$k$ beam with shuffle min-reduction.
* `⭐ Optional / Stretch`: Implement hash-based visited table in shared memory for graphs with degree $M > 64$.

### 🔹 Thursday, Thu Dec 25 ([`Day 116`](../days/month-05/day-116-2026-12-25.md))
* `[ ]` **Core**: Launch multi-query parallel graph search grid; benchmark QPS vs CPU HNSW implementation.
* `⭐ Optional / Stretch`: Measure the impact of thread block occupancy on memory latency hiding during random graph pointer chasing.

### 🔹 Friday, Fri Dec 26 ([`Day 117`](../days/month-05/day-117-2026-12-26.md))
* `[ ]` **Core**: Add shared memory caching for frequently visited upper-layer hub nodes to eliminate global memory roundtrips.
* `⭐ Optional / Stretch`: Compute graph degree centrality to identify top-64 hub nodes for permanent SRAM staging.

### 🔹 Saturday, Sat Dec 27 ([`Day 118`](../days/month-05/day-118-2026-12-27.md))
* `[ ]` **Core (09:00–13:00)**: Write and ship **Technical Essay 17**: *"Warp-Scale Graph Traversal: Overcoming Random Memory Access Bottlenecks in GPU CAGRA"* to `goals/essays/essay_17.md`.
* `[ ]` **Core (14:00–18:00)**: Execute Saturday Deep Learning from Scratch track ().
* `⭐ Optional / Stretch`: Run automated test suite validating PyTorch numerical gradient and attention equivalence.

### 🔹 Sunday, Sun Dec 28 ([`Day 119`](../days/month-05/day-119-2026-12-28.md))
* `[ ]` **Core (09:00–13:00)**: Execute Monthly Research Milestone for Month 5 (`research/2027-01-paging-vs-quantizing-kv/`): run empirical benchmarks and record data tables.
* `⭐ Optional / Stretch`: Draft / update section figures and experimental limitations.

---

## ⛔ What NOT to Overspend Time On (Week 17 Time Traps)

* ❌ **Do NOT** implement dynamic-degree variable-length CSR arrays on GPU—pad neighbor lists to fixed max degree $M$ for uniform warp loads.
* ❌ **Do NOT** maintain per-thread dynamic candidate queues in global memory—warp-cooperative bitfield visited masks eliminate queue allocation.
* ❌ **Do NOT** write measure-theoretic probability proofs for SLLN—grasp the Chebyshev proof for WLLN and move on.

---

## 📝 Weekend Deliverables

### ✍️ Technical Essay 17 (Saturday 09:00–13:00)
* **Title**: *"Warp-Scale Graph Traversal: Overcoming Random Memory Access Bottlenecks in GPU CAGRA"*
* **Target File**: `~/personal/goals/essays/essay_17.md`
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
