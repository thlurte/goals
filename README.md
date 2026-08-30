# Vector Search Engine & AI Systems Specialization

> **28 weeks / 7 months** (Sep 2026 – Mar 2027).  
> **Months 1–4 = Vector Search Engine.** **Months 5–7 = GPU specialization.**  
> **Deep learning is a slow path all 7 months** (**one Saturday afternoon**, not weekdays).  
> **No REST API** in `secan` (nanobind + CLI). Distributed CPU cluster = stretch.  
> **Plus: one research topic per month** → [`research/README.md`](research/README.md).

---

## ✅ Entry Prerequisites (before Sep 1)

Confirm these before Week 1; do not assume them mid-curriculum.

| Gate | Requirement |
|:---|:---|
| **CPU** | x86_64 with AVX2 (AVX-512 nice-to-have). ARM64 host or CI runner needed by Week 23. |
| **GPU** | NVIDIA GPU with CUDA toolkit by Week 13. Multi-GPU / NVLink only required for Week 20 stretch. |
| **Storage** | ≥50 GB free; **NVMe required by Week 16** for DiskANN / `io_uring` (not optional). |
| **Datasets** | SIFT1M Week 1; **Week 8 Fri** production dense encode (`ggmbed`/ONNX) → HNSW; **Week 9 Fri** `limbed` ONNX ColBERT → multi-vector; BEIR/MS MARCO **slice** Month 3 Sundays; Deep1B optional Week 16+. |
| **Repos / GPU RAM** | BERT/ColBERT/ViT training expects a GPU; CPU-only = tiny synthetic runs, not full MLM. |
| **Tooling** | CMake 3.20+, C++20 compiler, `perf`, `uv`, Python 3.11+, Git. |

---

## 🔬 Monthly Research → Publish

| Month | Topic | Publish |
|:---|:---|:---|
| Sep | Measurement-first vector distance microbenchmarks | Sep 27 |
| Oct | Anisotropy, hubness, SQ/PQ/FastScan/ScaNN **+ OPQ / asymmetric** | Oct 25 |
| Nov | PLAID vs **MUVERA** FDE→MIPS + **BEIR/MS MARCO slice** | Nov 29 |
| Dec | GPU IVF + Vamana/DiskANN + **RRF**/WAND | Dec 27 |
| Jan | PagedAttention × TurboQuant (KV memory) | Jan 31 |
| Feb | ACORN **+ pre/post/range filters** + tombstones + portable SIMD | Feb 28 |
| Mar | GPU serving: FA-2, multi-GPU, KV paging | Mar 12 |

Weekend: Sat 09–13 lab note · **Sat 14–18 DL** · Sun 09–13 research · last weekend = public post + `research/YYYY-MM-*/paper.md`.

---

## 📂 Curriculum Documents

1. [**Week 1 Detailed Execution Plan**](week_01_execution_plan.md)
2. [**28-Week Master Daily Curriculum**](vector_search_24_week_daily_plan.md)
3. [**Specialization Architecture & Macro Roadmap**](vector_search_specialization_roadmap.md)
4. [**Monthly Research Program**](research/README.md)
5. [**Intextus 30-min track**](intextus_30min_six_month.md) — maintains `limbed`/`ggmbed`; **ONNX handoff is Week 8–9 on the VS timeline**

---

## 🏛️ The Three Pillars

```
 ┌──────────────────────────────────────────────────────────────────────────────────────────────────┐
 │                               PILLAR 1: MATHEMATICS & HIGH-D ANALYTICS                           │
 │ • Gilbert Strang's Linear Algebra (Vector Spaces, Orthogonality, QR, SVD, Eigenvalues, Graphs)   │
 │ • High-D Geometry: Measure Concentration, Curse of Dimensionality, Hubness & Anisotropic Cones   │
 │ • ScaNN Theory: Anisotropic Vector Quantization Loss (Directional Error Weighting for MIPS)      │
 │ • IR Analytics: NDCG@K, MRR, MAP, and Poisson Process p95/p99 Tail Latency Queueing Theory       │
 │ • Frontier Quant: SCaNN anisotropic, RaBitQ, TurboQuant (PolarQuant + QJL) for search + KV cache │
 └────────────────────────┬─────────────────────────────────────────┬───────────────────────────────┘
                          │                                         │
                          ▼                                         ▼
 ┌────────────────────────────────────────┐     ┌───────────────────────────────────────────────────┐
 │      PILLAR 2: DEEP LEARNING (Py)      │     │      PILLAR 3: DATABASE & C++/GPU ENGINE (secan)  │
 │ • Transformers from Scratch            │     │ • Storage Engine: LSM-Tree, WAL, MemTable, Segs   │
 │ • Online Softmax & FlashAttention-1/2  │────►│ • Columnar Formats: Zero-Copy Apache Arrow Layout │
 │ • Vision Transformer (ViT)             │     │ • Handcrafted SIMD: AVX2, AVX-512, ARM NEON       │
 │ • Dense retriever (InfoNCE / DPR-E5)   │     │ • Quantization: SQ8, OPQ, PQ, BQ, RaBitQ, TQ   │
 │ • ViT, BERT, ColBERT, CLIP→ColPali     │     │ • Graph ANN: HNSW-SQ, IVF-PQ, Vamana/DiskANN    │
 │ • RoPE, GQA, naive KV → PagedAttention │     │ • CUDA: FA-1/2, CUTLASS, CAGRA, multi-GPU       │
 └────────────────────────────────────────┘     └───────────────────────────────────────────────────┘
```
