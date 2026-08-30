# Month 7 — Mar (Weeks 25–28)

> Part of the [28-week curriculum](../README.md). Research: [`research/`](../../research/README.md).

| | |
|:---|:---|
| [← Month 6 — Feb](month-06-feb.md) | [Essays →](../essays.md) |

---

# 📅 MONTH 7: GPU Specialization Closeout (Mar 2027)

> **🔬 Monthly research**: *IO-Aware GPU Serving: FlashAttention-2, Multi-GPU Search, and KV Paging* → publish **Fri Mar 12** · folder `research/2027-03-gpu-serving/`

---

### Week 25 (Feb 16–20): FlashAttention-2 (Week 15 catch-up)

**Theme**: FA-2 loop order, warp partition, Nsight vs FA-1 and SDPA.

| Day | Math (90 min) | Reading (45 min) | Afternoon (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Feb 16** | Online softmax recap (`m`, $\ell$). | FlashAttention-2 (Dao 2023). | **CUDA**: FA-2 loop order on Week 15 kernel. |
| **Tue Feb 17** | Work/span of tiled GEMM. | Warp partition along sequence. | **CUDA**: Reduce inter-warp sync; unit-test vs PyTorch. |
| **Wed Feb 18** | Numerical stability of online softmax. | `ncu` metrics: DRAM, achieved TFLOPS. | **CUDA (required)**: Nsight FA-1 vs FA-2 vs SDPA. |
| **Thu Feb 19** | GQA + FA: fewer KV tiles. | Integrate GQA from Week 2/4. | **Python/CUDA**: FA-2 path with `num_kv_heads`. |
| **Fri Feb 20** | — | — | Expose FA-2 via `cpp_extension`. Document speedup table for March paper. |

> **📝 Essay 25 (Sat Feb 21)**: *"FlashAttention-2: Loop Order and Warp Partition"*

---

### Week 26 (Feb 23–27): PagedAttention polish on naive KV

**Theme**: Week 4 naive KV is the baseline; this week **pages** it (Week 19 may already have a first BlockTable — finish correctness + GQA).

| Day | Math (90 min) | Reading (45 min) | Afternoon (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Feb 23** | Virtual memory recap (CS:APP Ch 9). | vLLM PagedAttention §4. | **CUDA**: BlockTable + paged K/V vs naive concat (A/B latency + memory). |
| **Tue Feb 24** | Fragmentation vs bitwidth (TurboQuant). | TurboQuant KV blog. | Design note: paging ≠ quantizing; optional QJL sketch. |
| **Wed Feb 25** | — | cuVS / serving APIs. | Hybrid CPU↔GPU fallback polish. |
| **Thu Feb 26** | — | Batch size crossover. | Plot $B=1..1000$ with **paged** KV. |
| **Fri Feb 27** | Month 6 paper remaining figures. | — | Freeze ACORN/tombstone paper if not done Feb 28. |

> **📝 Essay 26 (Sat Feb 28)**: *"Naive KV vs Paged KV: The Baseline We Should Have Had First"*  
> **🚀 Month 6 PUBLISH (Sun Feb 28)** if not already.

---

### Week 27 (Mar 2–6): Multi-GPU + ColPali ingest

**Theme**: NCCL search scaling; finish vision–text index.

| Day | Math (90 min) | Reading (45 min) | Afternoon (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Mar 2** | AllReduce vs AllGather cost. | NCCL ring algorithms. | **secan**: Multi-GPU IVF load-balance polish (Week 20). |
| **Tue Mar 3** | — | NVLink vs PCIe. | Scaling efficiency 1/2/4 GPU (or 1 GPU simulated shards). |
| **Wed Mar 4** | Contrastive InfoNCE recap. | ColPali paper. | Ingest CLIP-projected patches into `MultiVectorIndex`. |
| **Thu Mar 5** | — | GPU MaxSim CUTLASS. | Text query → visual page search E2E. |
| **Fri Mar 6** | — | — | Month 7 paper figures: GPU QPS + ColPali demo. |

> **📝 Essay 27 (Sat Mar 7)**: *"Sharded IVF and Visual Late Interaction"*

---

### Week 28 (Mar 9–13): 7-Month Release

**Theme**: `v2.0` — VS spine + GPU specialization + slow-path DL.

| Day | Math (90 min) | Reading (45 min) | Afternoon (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Mar 9** | 7-month geometric thread recap. | API/docs pass. | Finish CLI + Doxygen. |
| **Tue Mar 10** | — | `ann-benchmarks`. | Full CPU+GPU benchmark matrix. |
| **Wed Mar 11** | — | Examples. | Five examples including dense InfoNCE search + GPU batch. |
| **Thu Mar 12** | — | README. | **Publish Month 7 paper.** Tag `v2.0-complete`. |
| **Fri Mar 13** | Rest / interview packet. | — | Portfolio: 7 papers + `secan` Pareto plots. |

> **📝 Essay 28 (Sat Mar 14)**: *"7 Months: Vector Search Spine, GPU Serving, and a Slow-Path Retriever Stack"*  
> **🚀 Month 7 research PUBLISH (Thu Mar 12)**: `research/2027-03-gpu-serving/paper.md`

---
