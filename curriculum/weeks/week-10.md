# 🚀 Week 10 Execution Playbook

> **Theme**: Orthogonality, MUVERA FDEs, PLAID, RaBitQ & TurboQuant  
> **Calendar Dates**: Mon Nov 3 – Sun Nov 9 (2026-11-03 to 2026-11-09)  
> **Parent Month Dashboard**: [Month 3 (Nov 2026)](month-03-nov.md) · **Block**: I — Vector Search Engine

| | | |
|:---|:---|:---|
| [← Week 09](week-09.md) | [Month 3 (Nov 2026) Dashboard](month-03-nov.md) | [Week 11 →](week-11.md) |

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
| **Monday** | Mon Nov 3 | [`Day 064`](../days/month-03/day-064-2026-11-03.md) | **STRANG §3.1**: Orthogonal vectors, orthogonal subspaces. Proving row space is orthogonal to nullspace in $\mathbb{R}^n$. | [MUVERA](https://arxiv.org/abs/2405.19504) §1–3: FDE construction, SimHash buckets, **asymmetric** query vs doc encode. | **secan (required)**: `fde_encode` — hash tokens into $B$ buckets, per-bucket aggregate, $R$ repetitions. Query FDE $\neq$ doc FDE. |
| **Tuesday** | Tue Nov 4 | [`Day 065`](../days/month-03/day-065-2026-11-04.md) | **STRANG §3.2**: Projection onto a 1D line: $P = \frac{a a^T}{a^T a}$. Cauchy-Schwarz from projection error. | MUVERA §4–5: FDE MIPS + MaxSim re-rank; candidate count vs heuristics. | **secan (required)**: Index doc FDEs with **IP** HNSW or IVF (Week 4/8). Retrieve then **MaxSim re-rank**. Plot Recall vs candidates vs Week 9 centroid prune. |
| **Wednesday** | Wed Nov 5 | [`Day 066`](../days/month-03/day-066-2026-11-05.md) | **STRANG §3.3**: Projection onto a subspace; $A^T A \hat{x} = A^T b$. | PLAID §3–5: centroid → quantized MaxSim → FP32. | **secan (required)**: **PLAID 3-stage** (2/4-bit residual MaxSim). Same slice: PLAID vs MUVERA candidate efficiency. Poisson load gen = stretch. |
| **Thursday** | Thu Nov 6 | [`Day 067`](../days/month-03/day-067-2026-11-06.md) | **STRANG §3.4**: Orthonormal $Q$, Gram-Schmidt, $A = QR$. | RaBitQ: random orthogonal + error correction. **PIKUS Ch 8** concurrency skim. | **secan**: QR rotation helper + **RaBitQ**. Recall vs plain BQ (Week 7). |
| **Friday** | Fri Nov 7 | [`Day 068`](../days/month-03/day-068-2026-11-07.md) | **STRANG §3.4**: Least squares via QR: $\hat{x} = R^{-1} Q^T b$. | [TurboQuant](https://research.google/blog/turboquant-redefining-ai-efficiency-with-extreme-compression/): PolarQuant + QJL; 1@k vs PQ/RaBitQ. | **secan (required)**: **TurboQuant/PolarQuant or QJL 1@k** vs RaBitQ vs PQ on **GloVe-200 or 768-D**. Plot Recall@1. |
| **Saturday** | Sat Nov 8 | [`Day 069`](../days/month-03/day-069-2026-11-08.md) | **09:00–13:00**: Essay 10 | **14:00–18:00**: Deep Learning Track | Deep Learning from Scratch (uv/PyTorch) |
| **Sunday** | Sun Nov 9 | [`Day 070`](../days/month-03/day-070-2026-11-09.md) | **09:00–13:00**: Monthly Research | Research Experimentation | Rest & Subconscious Incubation |

---

## 📋 Daily Action Items & Deliverables (Week 10)

### 🔹 Monday, Mon Nov 3 ([`Day 064`](../days/month-03/day-064-2026-11-03.md))
* `[ ]` **Core**: Implement MUVERA `fde_encode` hashing token sets into $B$ SimHash buckets with $R$ random repetitions.
* `⭐ Optional / Stretch`: Derive the theoretical upper bound on Chamfer distance error as a function of repetition count $R$.

### 🔹 Tuesday, Tue Nov 4 ([`Day 065`](../days/month-03/day-065-2026-11-04.md))
* `[ ]` **Core**: Index document FDEs in IP HNSW index; execute MIPS query retrieval followed by exact MaxSim re-ranking.
* `⭐ Optional / Stretch`: Compare candidate set size needed for 95% Recall@10: MUVERA FDE vs PLAID centroid candidate lists.

### 🔹 Wednesday, Wed Nov 5 ([`Day 066`](../days/month-03/day-066-2026-11-05.md))
* `[ ]` **Core**: Implement PLAID 3-stage pipeline (centroid score $\to$ 2/4-bit quantized MaxSim filter $\to$ FP32 MaxSim re-rank).
* `⭐ Optional / Stretch`: Profile memory footprint of PLAID quantized token storage vs MUVERA single-vector FDE storage.

### 🔹 Thursday, Thu Nov 6 ([`Day 067`](../days/month-03/day-067-2026-11-06.md))
* `[ ]` **Core**: Implement Gram-Schmidt QR rotation helper in C++; implement RaBitQ 1-bit quantization with error correction.
* `⭐ Optional / Stretch`: Benchmark RaBitQ distance calculation throughput using AVX2 integer instructions vs plain Hamming distance.

### 🔹 Friday, Fri Nov 7 ([`Day 068`](../days/month-03/day-068-2026-11-07.md))
* `[ ]` **Core**: Implement TurboQuant / PolarQuant 3-bit polar coordinate transform + 1-bit QJL error correction; plot Recall@1 vs bitwidth.
* `⭐ Optional / Stretch`: Implement SIMD Fast Walsh-Hadamard Transform (FWHT) butterfly kernel (`_mm256_add_ps` / `_mm256_sub_ps`) for $O(D \log D)$ zero-storage randomized incoherence rotation before 1-bit RaBitQ / 3-bit PolarQuant.

### 🔹 Saturday, Sat Nov 8 ([`Day 069`](../days/month-03/day-069-2026-11-08.md))
* `[ ]` **Core (09:00–13:00)**: Write and ship **Technical Essay 10**: *"Orthogonal Projections and Fixed-Dimensional Encodings: Reducing ColBERT MaxSim to MIPS via MUVERA"* to `goals/essays/essay_10.md`.
* `[ ]` **Core (14:00–18:00)**: Execute Saturday Deep Learning from Scratch track ().
* `⭐ Optional / Stretch`: Run automated test suite validating PyTorch numerical gradient and attention equivalence.

### 🔹 Sunday, Sun Nov 9 ([`Day 070`](../days/month-03/day-070-2026-11-09.md))
* `[ ]` **Core (09:00–13:00)**: Execute Monthly Research Milestone for Month 3 (`research/2026-11-late-interaction-lsm/`): run empirical benchmarks and record data tables.
* `⭐ Optional / Stretch`: Draft / update section figures and experimental limitations.

---

## ⛔ What NOT to Overspend Time On (Week 10 Time Traps)

* ❌ **Do NOT** implement full PLAID centroid pruning if MUVERA FDE gives satisfactory recall—treat PLAID and MUVERA as competing candidate generators.
* ❌ **Do NOT** implement full DiskANN or `io_uring` this week—DiskANN is formally built in Week 16.
* ❌ **Do NOT** write a full Householder reflector library for QR—standard Gram-Schmidt is sufficient for rotation matrix generation.

---

## 📝 Weekend Deliverables

### ✍️ Technical Essay 10 (Saturday 09:00–13:00)
* **Title**: *"Orthogonal Projections and Fixed-Dimensional Encodings: Reducing ColBERT MaxSim to MIPS via MUVERA"*
* **Target File**: `~/personal/goals/essays/essay_10.md`
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
