# Monthly Research Program: Systems Architecture & High-Performance Retrieval

One research manuscript per calendar month. **Build every weekend. Publish by month-end.**  
Weekly Saturday essays are empirical *lab notes* that feed the monthly conference-grade manuscript.

---

## 📅 Seven Research Manuscripts (Sep 2026 – Mar 2027)

| Month | Topic (Publication-Grade Title) | Publish by | Primary Empirical Artifacts |
|:---|:---|:---|:---|
| **1 — Sep 2026** | *Microarchitectural Limits of Vector Distance Kernels: Execution Port Contention, Cache-Line Splits, and Measurement Artifacts on Modern x86* | **Sun Sep 27** | Google Benchmark suite, `perf stat` IPC/port tables, scalar vs AVX2/AVX-512 distance benchmarks across $D \in [64, 1536]$ |
| **2 — Oct 2026** | *Anisotropy-Aware Vector Quantization: Dissecting the Interplay Between Embedding Cones, Hubness, and Quantization Loss Functions* | **Sun Oct 25** | Quantization ablations, hubness $S_{N_k}$, ScaNN directional loss vs MSE PQ vs OPQ vs RaBitQ on **768-D text embeddings** |
| **3 — Nov 2026** | *Streaming Late Interaction: Evaluating PLAID Centroid Inverted Lists vs MUVERA Fixed-Dimensional Encodings in Dynamic LSM Vector Storage* | **Sun Nov 29** | Multi-vector + WAL; **BEIR / MS MARCO slice**; write throughput vs compaction overhead: PLAID cascades vs MUVERA FDE-to-MIPS |
| **4 — Dec 2026** | *Billion-Scale Retrieval Frontiers: Comparing In-VRAM GPU IVF and Asynchronous NVMe DiskANN Under Concurrent Query Pressure* | **Sun Dec 27** | Cost-per-QPS Pareto curves, 8–15 µs random NVMe direct I/O read profiles, Deep10M/Deep100M benchmarks |
| **5 — Jan 2027** | *Paging vs. Quantizing LLM KV Caches at Long Contexts: Memory Fragmentation, Dequantization Overhead, and Serving Throughput* | **Sun Jan 31** | PagedAttention BlockTable vs TurboQuant 3-bit PolarQuant compression at $4\text{K} \to 128\text{K}$ context lengths |
| **6 — Feb 2027** | *Mitigating Recall Collapse in Filtered Approximate Nearest Neighbor Graphs: An Empirical Evaluation of ACORN vs. Iterative Post-Filtering Across Selectivity Spectrums* | **Sun Feb 28** | Selectivity $P(\text{pass}) < 1\%$ vs recall curves; ACORN multi-hop predicate subgraph traversal vs post-filtering on HNSW |
| **7 — Mar 2027** | *Unified IO-Aware GPU Architecture for Vector Retrieval and LLM Attention Serving: FlashAttention-2, Paged KV Caches, and Multi-GPU Scaling* | **Fri Mar 12** | FA-2 Nsight profiling tables, NCCL multi-GPU scaling, End-to-End Time-to-First-Token (TTFT) benchmarks, master release `v2.0` |

---

## ⏱️ The 16-Hour Production Protocol (4 Sundays × 4 Hours)
To publish publication-grade papers without burnout:
1. **Saturday Lab Notes (09:00–13:00)**: Every Saturday note MUST directly generate the raw benchmark tables and plots for that week's component.
2. **Sunday 1 (Method & Baseline Setup)**: Write §1 (Question) and §2 (Method); run scalar/Faiss baseline benchmarks.
3. **Sunday 2 (Core Sweep Runs)**: Execute primary parameter sweeps across dimensions/selectivity in background; dump raw CSVs to `notes/`.
4. **Sunday 3 (Ablations & Plots)**: Generate `figures/` using matplotlib scripts; write §4 (Results) and §5 (Baseline comparison).
5. **Sunday 4 (Draft Freeze & Tag)**: Write §6 (Limitations) and §7 (Repro commands); freeze Markdown/PDF + Git tag. **Never run new experiments on Sunday 4.**
