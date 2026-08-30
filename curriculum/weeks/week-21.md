# 🚀 Week 21 Execution Playbook

> **Theme**: Convex Optimization, KKT, ColPali GPU Path  
> **Calendar Dates**: Mon Jan 19 – Sun Jan 25 (2027-01-19 to 2027-01-25)  
> **Parent Month Dashboard**: [Month 6 (Feb 2027)](month-06-feb.md) · **Block**: II — GPU Specialization

| | | |
|:---|:---|:---|
| [← Week 20](week-20.md) | [Month 6 (Feb 2027) Dashboard](month-06-feb.md) | [Week 22 →](week-22.md) |

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
| **Monday** | Mon Jan 19 | [`Day 141`](../days/month-06/day-141-2027-01-19.md) | **CONVEX §2.1–2.4**: Convex sets: affine sets, convex combinations, convex hulls, cones, hyperplanes, and Euclidean balls. | Re-read ColBERT/PLAID papers with GPU focus: mapping MaxSim to batched GEMM + reductions. | **secan**: Implement **GPU MaxSim kernel**: CUTLASS GEMM + warp row-max + column-sum. |
| **Tuesday** | Tue Jan 20 | [`Day 142`](../days/month-06/day-142-2027-01-20.md) | **CONVEX §3.1–3.4**: Convex functions: first/second-order conditions, Jensen. | CLIP / SigLIP contrastive alignment (image encoder ↔ text encoder). | **secan**: GPU MaxSim polish / fused pipeline. *(CLIP projector: Sat Jan 24.)* |
| **Wednesday** | Wed Jan 21 | [`Day 143`](../days/month-06/day-143-2027-01-21.md) | **CONVEX §4.1–4.4**: Convex optimization problems: LP, QP, SOCP. | NN-Descent / CAGRA neighbor exchange. | **secan**: GPU NN-Descent base-layer graph construction. **FA-2 → Week 25.** |
| **Thursday** | Thu Jan 22 | [`Day 144`](../days/month-06/day-144-2027-01-22.md) | **CONVEX §5.1–5.4**: Duality: Lagrangian, weak/strong duality, Slater. | CAGRA / NN-Descent GPU neighbor exchange. | **secan**: GPU NN-Descent base-layer graph construction. |
| **Friday** | Fri Jan 23 | [`Day 145`](../days/month-06/day-145-2027-01-23.md) | **CONVEX §5.5**: KKT conditions: necessity and sufficiency for convex problems. | Review GPU ColBERT / ColPali integration. | **secan**: Ingest ColPali visual embeddings; text query → visual page search. **Stretch**: same tokens through MUVERA FDE + IP MIPS. |
| **Saturday** | Sat Jan 24 | [`Day 146`](../days/month-06/day-146-2027-01-24.md) | **09:00–13:00**: Essay 21 | **14:00–18:00**: Deep Learning Track | Deep Learning from Scratch (uv/PyTorch) |
| **Sunday** | Sun Jan 25 | [`Day 147`](../days/month-06/day-147-2027-01-25.md) | **09:00–13:00**: Monthly Research | Research Experimentation | Rest & Subconscious Incubation |

---

## 📋 Daily Action Items & Deliverables (Week 21)

### 🔹 Monday, Mon Jan 19 ([`Day 141`](../days/month-06/day-141-2027-01-19.md))
* `[ ]` **Core**: Implement GPU MaxSim kernel in CUTLASS computing batched GEMM followed by warp row-max and column-sum reduction.
* `⭐ Optional / Stretch`: Derive the dual formulation of token alignment under convex regularized transportation costs.

### 🔹 Tuesday, Tue Jan 20 ([`Day 142`](../days/month-06/day-142-2027-01-20.md))
* `[ ]` **Core**: Fuse GPU MaxSim query scoring and candidate document filtering into a single CUDA pipeline.
* `⭐ Optional / Stretch`: Benchmark latency vs batch size for single-page visual tokens (1030 tokens per image page).

### 🔹 Wednesday, Wed Jan 21 ([`Day 143`](../days/month-06/day-143-2027-01-21.md))
* `[ ]` **Core**: Implement GPU NN-Descent base-layer $k$-NN graph construction algorithm exchanging neighbor candidates across thread blocks.
* `⭐ Optional / Stretch`: Measure convergence speed (graph recall vs iteration count) on 100K embedding vectors.

### 🔹 Thursday, Thu Jan 22 ([`Day 144`](../days/month-06/day-144-2027-01-22.md))
* `[ ]` **Core**: Implement 2-opt edge pruning heuristic in GPU NN-Descent graph construction.
* `⭐ Optional / Stretch`: Verify Slater's condition for constrained graph sparsification optimization problems.

### 🔹 Friday, Fri Jan 23 ([`Day 145`](../days/month-06/day-145-2027-01-23.md))
* `[ ]` **Core**: Ingest ColPali multimodal embeddings (text query $\to$ multi-vector document pages); evaluate visual search Recall@10.
* `⭐ Optional / Stretch`: Route ColPali visual multi-vectors through MUVERA FDEs for instant 1-stage MIPS candidate retrieval.

### 🔹 Saturday, Sat Jan 24 ([`Day 146`](../days/month-06/day-146-2027-01-24.md))
* `[ ]` **Core (09:00–13:00)**: Write and ship **Technical Essay 21**: *"Duality and Multimodal Retrieval: Karush-Kuhn-Tucker Conditions, CLIP Alignment, and ColPali MaxSim"* to `goals/essays/essay_21.md`.
* `[ ]` **Core (14:00–18:00)**: Execute Saturday Deep Learning from Scratch track (**🧠 DL weekend**: CLIP-style projector + ColPali head.).
* `⭐ Optional / Stretch`: Run automated test suite validating PyTorch numerical gradient and attention equivalence.

### 🔹 Sunday, Sun Jan 25 ([`Day 147`](../days/month-06/day-147-2027-01-25.md))
* `[ ]` **Core (09:00–13:00)**: Execute Monthly Research Milestone for Month 6 (`research/2027-02-predicate-aware-graphs/`): run empirical benchmarks and record data tables.
* `⭐ Optional / Stretch`: Draft / update section figures and experimental limitations.

---

## ⛔ What NOT to Overspend Time On (Week 21 Time Traps)

* ❌ **Do NOT** write a custom vision transformer model in C++—run ColPali image embeddings generation in Python/PyTorch.
* ❌ **Do NOT** optimize GPU NN-Descent beyond 10-15 iterations—NN-Descent achieves $>98\%$ $k$-NN graph quality quickly.
* ❌ **Do NOT** spend hours proving convex duality theorems for non-linear constraints—focus on KKT conditions for linear/quadratic programs.

---

## 📝 Weekend Deliverables

### ✍️ Technical Essay 21 (Saturday 09:00–13:00)
* **Title**: *"Duality and Multimodal Retrieval: Karush-Kuhn-Tucker Conditions, CLIP Alignment, and ColPali MaxSim"*
* **Target File**: `~/personal/goals/essays/essay_21.md`
* **5-Part Structure**:
  1. **Mathematical Foundation**: Core theorems, derivations, and formal definitions.
  2. **The Systems Bottleneck**: Hardware limitation (memory bandwidth, port contention, cache line splits, warp stalls).
  3. **The Engine Architecture**: Exact data structures and SIMD/CUDA kernel design implemented in `secan`.
  4. **Empirical Benchmarks**: Perf counter tables, latency percentiles ($p50/p95/p99$), and QPS curves.
  5. **Key Takeaway**: Architectural rule of thumb for production AI systems.

### 🧠 Deep Learning Track (Saturday 14:00–18:00)
* **Task**: **🧠 DL weekend**: CLIP-style projector + ColPali head.

### 🔬 Monthly Research Milestone (Sunday 09:00–13:00)
* **Paper**: *"Mitigating Recall Collapse in Filtered Approximate Nearest Neighbor Graphs: An Empirical Evaluation of ACORN vs. Iterative Post-Filtering Across Selectivity Spectrums"*
* **Workspace**: `research/2027-02-predicate-aware-graphs/`
* **Publish Deadline**: **Sun Feb 28**
