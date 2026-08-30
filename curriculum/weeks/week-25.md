# 🚀 Week 25 Execution Playbook

> **Theme**: FlashAttention-2 (Week 15 catch-up)  
> **Calendar Dates**: Mon Feb 16 – Sun Feb 22 (2027-02-16 to 2027-02-22)  
> **Parent Month Dashboard**: [Month 7 (Mar 2027)](month-07-mar.md) · **Block**: II — GPU Specialization

| | | |
|:---|:---|:---|
| [← Week 24](week-24.md) | [Month 7 (Mar 2027) Dashboard](month-07-mar.md) | [Week 26 →](week-26.md) |

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
| **Monday** | Mon Feb 16 | [`Day 169`](../days/month-07/day-169-2027-02-16.md) | Online softmax recap (`m`, $\ell$). | FlashAttention-2 (Dao 2023). | **CUDA**: FA-2 loop order on Week 15 kernel. |
| **Tuesday** | Tue Feb 17 | [`Day 170`](../days/month-07/day-170-2027-02-17.md) | Work/span of tiled GEMM. | Warp partition along sequence. | **CUDA**: Reduce inter-warp sync; unit-test vs PyTorch. |
| **Wednesday** | Wed Feb 18 | [`Day 171`](../days/month-07/day-171-2027-02-18.md) | Numerical stability of online softmax. | `ncu` metrics: DRAM, achieved TFLOPS. | **CUDA (required)**: Nsight FA-1 vs FA-2 vs SDPA. |
| **Thursday** | Thu Feb 19 | [`Day 172`](../days/month-07/day-172-2027-02-19.md) | GQA + FA: fewer KV tiles. | Integrate GQA from Week 2/4. | **Python/CUDA**: FA-2 path with `num_kv_heads`. |
| **Friday** | Fri Feb 20 | [`Day 173`](../days/month-07/day-173-2027-02-20.md) | — | — | Expose FA-2 via `cpp_extension`. Document speedup table for March paper. |
| **Saturday** | Sat Feb 21 | [`Day 174`](../days/month-07/day-174-2027-02-21.md) | **09:00–13:00**: Essay 25 | **14:00–18:00**: Deep Learning Track | Deep Learning from Scratch (uv/PyTorch) |
| **Sunday** | Sun Feb 22 | [`Day 175`](../days/month-07/day-175-2027-02-22.md) | **09:00–13:00**: Monthly Research | Research Experimentation | Rest & Subconscious Incubation |

---

## 📋 Daily Action Items & Deliverables (Week 25)

### 🔹 Monday, Mon Feb 16 ([`Day 169`](../days/month-07/day-169-2027-02-16.md))
* `[ ]` **Core**: Implement FlashAttention-2 loop inversion (outer loop over $Q$ blocks, inner loop over $K, V$ blocks) to reduce shared memory write traffic.
* `⭐ Optional / Stretch`: Derive the exact register footprint comparison between FlashAttention-1 and FlashAttention-2.

### 🔹 Tuesday, Tue Feb 17 ([`Day 170`](../days/month-07/day-170-2027-02-17.md))
* `[ ]` **Core**: Implement sequence-level warp partitioning inside thread blocks; eliminate inter-warp synchronization barriers during forward pass.
* `⭐ Optional / Stretch`: Verify numerical equivalence against PyTorch `scaled_dot_product_attention` across sequence lengths $L \in [512, 16384]$.

### 🔹 Wednesday, Wed Feb 18 ([`Day 171`](../days/month-07/day-171-2027-02-18.md))
* `[ ]` **Core**: Profile FA-1 vs FA-2 vs PyTorch SDPA in Nsight Compute (`ncu`); measure achieved TFLOPS and DRAM bandwidth saturation.
* `⭐ Optional / Stretch`: Calculate tensor core compute efficiency percentage (% of theoretical FP16 peak).

### 🔹 Thursday, Thu Feb 19 ([`Day 172`](../days/month-07/day-172-2027-02-19.md))
* `[ ]` **Core**: Implement Grouped-Query Attention (GQA) support in FA-2 kernel (`num_heads_q != num_heads_kv`); broadcast $K, V$ heads to query groups in SRAM.
* `⭐ Optional / Stretch`: Benchmark latency speedup of GQA ($G=8$) vs MHA ($G=1$) at batch size 32.

### 🔹 Friday, Fri Feb 20 ([`Day 173`](../days/month-07/day-173-2027-02-20.md))
* `[ ]` **Core**: Build production PyTorch C++ extension bindings for FA-2; generate speedup curves for Month 7 publication paper.
* `⭐ Optional / Stretch`: Implement causal masking without branching by computing diagonal tile intersections.

### 🔹 Saturday, Sat Feb 21 ([`Day 174`](../days/month-07/day-174-2027-02-21.md))
* `[ ]` **Core (09:00–13:00)**: Write and ship **Technical Essay 25**: *"Warp Partitioning and Register Rescaling: Implementing FlashAttention-2 with Grouped-Query Attention"* to `goals/essays/essay_25.md`.
* `[ ]` **Core (14:00–18:00)**: Execute Saturday Deep Learning from Scratch track ().
* `⭐ Optional / Stretch`: Run automated test suite validating PyTorch numerical gradient and attention equivalence.

### 🔹 Sunday, Sun Feb 22 ([`Day 175`](../days/month-07/day-175-2027-02-22.md))
* `[ ]` **Core (09:00–13:00)**: Execute Monthly Research Milestone for Month 7 (`research/2027-03-gpu-serving/`): run empirical benchmarks and record data tables.
* `⭐ Optional / Stretch`: Draft / update section figures and experimental limitations.

---

## ⛔ What NOT to Overspend Time On (Week 25 Time Traps)

* ❌ **Do NOT** implement backward gradient kernels for FA-2—forward inference execution is the complete target.
* ❌ **Do NOT** hand-tune PTX for specific Hopper (SM90) wgmma instructions—standard FP16/BF16 shared-memory tiling provides massive speedup portably.
* ❌ **Do NOT** spend days micro-optimizing head dimensions beyond $d \in \{64, 128\}$.

---

## 📝 Weekend Deliverables

### ✍️ Technical Essay 25 (Saturday 09:00–13:00)
* **Title**: *"Warp Partitioning and Register Rescaling: Implementing FlashAttention-2 with Grouped-Query Attention"*
* **Target File**: `~/personal/goals/essays/essay_25.md`
* **5-Part Structure**:
  1. **Mathematical Foundation**: Core theorems, derivations, and formal definitions.
  2. **The Systems Bottleneck**: Hardware limitation (memory bandwidth, port contention, cache line splits, warp stalls).
  3. **The Engine Architecture**: Exact data structures and SIMD/CUDA kernel design implemented in `secan`.
  4. **Empirical Benchmarks**: Perf counter tables, latency percentiles ($p50/p95/p99$), and QPS curves.
  5. **Key Takeaway**: Architectural rule of thumb for production AI systems.

### 🧠 Deep Learning Track (Saturday 14:00–18:00)
* **Task**: 

### 🔬 Monthly Research Milestone (Sunday 09:00–13:00)
* **Paper**: *"Unified IO-Aware GPU Architecture for Vector Retrieval and LLM Attention Serving: FlashAttention-2, Paged KV Caches, and Multi-GPU Scaling"*
* **Workspace**: `research/2027-03-gpu-serving/`
* **Publish Deadline**: **Fri Mar 12**
