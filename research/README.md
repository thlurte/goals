# Monthly Research Program

One research topic per calendar month. **Build every weekend. Publish by month-end.**  
Weekly Saturday essays are *lab notes* that feed the monthly paper — not six separate polished publications.

## Cadence

| When | What |
|:---|:---|
| **Sat 09:00–13:00** | Weekly essay / lab note |
| **Sat 14:00–18:00** | **DL weekly** (the one Python day — not research) |
| **Sun 09:00–13:00** | Monthly research experiments / draft in `research/YYYY-MM-<slug>/` |
| **Last weekend of month** | **Publish**: freeze PDF/Markdown + GitHub tag + public post (blog / LinkedIn / HF) |

## Paper structure (every month)

One file, one format: copy [`_template.md`](_template.md) → `YYYY-MM-<slug>/paper.md`.

| § | Required |
|:---|:---|
| 1 Question | One falsifiable sentence |
| 2 Method | Hardware, commit, flags, dataset, protocol |
| 3 Experiments | Table of runs |
| 4 Results | ≥1 figure in `figures/` + numbers in the paper |
| 5 Baseline | Named (`faiss`, `hnswlib`, scalar, paper method) |
| 6 Limitations | Honest paragraph |
| 7 Reproduce | Commands |

Do **not** put weekend checklists in `paper.md` (cadence is this README). Lab notes go in `notes/`, plots in `figures/`.

Curriculum weeks: [`../curriculum/README.md`](../curriculum/README.md). Lab notes: [`../curriculum/essays.md`](../curriculum/essays.md).

## Seven topics (Sep 2026 – Mar 2027)

| Month | Topic (Publication-Grade Title) | Publish by | Primary artifacts |
|:---|:---|:---|:---|
| **1 — Sep 2026** | *Microarchitectural Limits of Vector Distance Kernels: Execution Port Contention, Cache-Line Splits, and Measurement Artifacts on Modern x86* | **Sun Sep 27** | Google Benchmark suite, `perf stat` IPC/port tables, scalar vs AVX2/AVX-512 distance benchmarks across $D \in [64, 1536]$ |
| **2 — Oct 2026** | *Anisotropy-Aware Vector Quantization: Dissecting the Interplay Between Embedding Cones, Hubness, and Quantization Loss Functions* | **Sun Oct 25** | Quantization ablations, hubness $S_{N_k}$, ScaNN directional loss vs MSE PQ vs OPQ vs RaBitQ on **768-D text embeddings** |
| **3 — Nov 2026** | *Streaming Late Interaction: Evaluating PLAID Centroid Inverted Lists vs MUVERA Fixed-Dimensional Encodings in Dynamic LSM Vector Storage* | **Sun Nov 29** | Multi-vector + WAL; **BEIR / MS MARCO slice**; write throughput vs compaction overhead: PLAID cascades vs MUVERA FDE-to-MIPS |
| **4 — Dec 2026** | *Billion-Scale Retrieval Frontiers: Comparing In-VRAM GPU IVF and Asynchronous NVMe DiskANN Under Concurrent Query Pressure* | **Sun Dec 27** | Billion-scale cost-latency-recall Pareto frontiers; tag `v1.2-vs-spine-complete` |
| **5 — Jan 2027** | *Paging vs. Quantizing LLM KV Caches: Memory Fragmentation, Dequantization Overhead, and Serving Throughput at Long Contexts* | **Sun Jan 31** | PagedAttention BlockTable vs TurboQuant 3-bit PolarQuant compression at $4\text{K} \to 128\text{K}$ context lengths |
| **6 — Feb 2027** | *Mitigating Recall Collapse in Filtered Approximate Nearest Neighbor Graphs: An Empirical Evaluation of ACORN vs. Iterative Post-Filtering Across Selectivity Spectrums* | **Sun Feb 28** | Selectivity $P(\text{pass}) < 1\%$ vs recall curves; ACORN multi-hop predicate subgraph traversal vs post-filtering on HNSW |
| **7 — Mar 2027** | *Unified IO-Aware GPU Architecture for Vector Retrieval and LLM Attention Serving: FlashAttention-2, Paged KV Caches, and Multi-GPU Scaling* | **Fri Mar 12** | FA-2 Nsight profiling tables, NCCL multi-GPU scaling, End-to-End Time-to-First-Token (TTFT) benchmarks, master release `v2.0` |

## Relationship to weekly essays

Weekly essays = short, sharp, same-week.  
Monthly paper = synthesis + experiments you could show in a hiring loop.  
Do **not** polish all 28 essays for public; polish **7 monthlies**.
