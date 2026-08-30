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
| **Monday** | Mon Jan 12 | [`Day 134`](../days/month-05/day-134-2027-01-12.md) | **INFO §1.1–1.3**: Shannon Entropy: Information content of events $I(x) = -\log_2 p(x)$, entropy $H(X)$, entropy of Bernoulli and discrete uniform distributions. | **CUDA-GUIDE Multi-GPU**: `cudaSetDevice`, peer-to-peer memory access (`cudaDeviceEnablePeerAccess`). | **secan**: Implement dataset sharding: split $N$ vectors into $G$ shards. Upload shard $i$ to GPU $i$. Build `MultiGpuIndex` class. |
| **Tuesday** | Tue Jan 13 | [`Day 135`](../days/month-05/day-135-2027-01-13.md) | **INFO §1.4–1.6**: Joint Entropy $H(X, Y)$, Conditional Entropy $H(Y | X)$, and the Chain Rule for Entropy: $H(X_1, \dots, X_n) = \sum H(X_i | X_{i-1}, \dots, X_1)$. |
| **Wednesday** | Wed Jan 14 | [`Day 136`](../days/month-05/day-136-2027-01-14.md) | **INFO §2.1–2.3**: Relative Entropy (KL Divergence) $D_{KL}(P \ | Q)$. Rigorous proof that $D_{KL} \geq 0$ via Jensen's Inequality on convex functions. | Faiss multi-GPU implementation: replicated coarse quantizer with sharded inverted lists. |
| **Thursday** | Thu Jan 15 | [`Day 137`](../days/month-05/day-137-2027-01-15.md) | **INFO §2.4–2.6**: Mutual Information $I(X; Y)$: properties, symmetry $I(X; Y) = I(Y; X)$, connection to KL divergence between joint and product marginals. | NVLink vs PCIe inter-GPU bandwidth analysis. | **secan**: Implement dynamic load balancing: redistribute heavy IVF cells across GPUs to prevent stragglers during multi-probe search. |
| **Friday** | Fri Jan 16 | [`Day 138`](../days/month-05/day-138-2027-01-16.md) | **INFO §3.1–3.3**: Cross-Entropy $H(P, Q) = -\sum P(x) \log Q(x)$. Mathematical proof that minimizing Cross-Entropy is equivalent to minimizing KL Divergence to target distribution. | Measure multi-GPU scaling efficiency across 1, 2, and 4 GPUs on synthetic billion-scale data. | **secan**: Benchmark multi-GPU search on SIFT1M and large synthetic datasets. Measure scaling efficiency and communication overhead. |
| **Saturday** | Sat Jan 17 | [`Day 139`](../days/month-05/day-139-2027-01-17.md) | **09:00–13:00**: Essay 20 | **14:00–18:00**: Deep Learning Track | Deep Learning from Scratch (uv/PyTorch) |
| **Sunday** | Sun Jan 18 | [`Day 140`](../days/month-05/day-140-2027-01-18.md) | **09:00–13:00**: Monthly Research | Research Experimentation | Rest & Subconscious Incubation |

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
* `[ ]` **Core**: Run multi-GPU scalability benchmark suite; compute parallel scaling efficiency percentage across GPUs.
* `⭐ Optional / Stretch`: Test multi-GPU fault tolerance by simulating device dropout and dynamic shard re-routing.

### 🔹 Saturday, Sat Jan 17 ([`Day 139`](../days/month-05/day-139-2027-01-17.md))
* `[ ]` **Core (09:00–13:00)**: Write and ship **Technical Essay 20**: *"Information Theory and Ring Collectives: Shannon Entropy, KL-Divergence, and Multi-GPU NCCL Search"* to `goals/essays/essay_20.md`.
* `[ ]` **Core (14:00–18:00)**: Execute Saturday Deep Learning from Scratch track ().
* `⭐ Optional / Stretch`: Run automated test suite validating PyTorch numerical gradient and attention equivalence.

### 🔹 Sunday, Sun Jan 18 ([`Day 140`](../days/month-05/day-140-2027-01-18.md))
* `[ ]` **Core (09:00–13:00)**: Execute Monthly Research Milestone for Month 5 (`research/2027-01-paging-vs-quantizing-kv/`): run empirical benchmarks and record data tables.
* `⭐ Optional / Stretch`: Draft / update section figures and experimental limitations.

---

## ⛔ What NOT to Overspend Time On (Week 20 Time Traps)

* ❌ **Do NOT** implement multi-node distributed TCP network clustering—NCCL multi-GPU on a single multi-GPU host is the complete specialization target.
* ❌ **Do NOT** implement complex 2D tensor parallelism—data sharding with top-$k$ heap gathering (`ncclAllGather`) is the standard for vector search.
* ❌ **Do NOT** worry if you only have 1 GPU locally—NCCL supports single-process multi-stream GPU shard simulation.

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
