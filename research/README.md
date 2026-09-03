# Monthly Research Program: Dual-Use AI Systems & High-Performance Infrastructure

One research manuscript per calendar month. **Build every weekend. Publish by month-end.**  
Weekly Saturday essays serve as empirical *lab notes* that feed the monthly conference-grade manuscript.

---

## 🏛️ Strategic Philosophy: The Dual-Use Advantage

Every systems component in this research program is engineered with **Dual-Use Architecture**:
1. **Commercial / Academic Track**: Open-source high-throughput vector retrieval and LLM serving engine (`secan`).
2. **Advanced Defense & Tactical Edge Track**: Real-time signal de-interleaving, bandwidth-constrained Link-16/tactical data links, autonomous drone swarm compute, and JADC2 multilevel security filtered graph retrieval.

This dual framing demonstrates low-level systems capabilities that virtually no standard corporate engineer or academic possesses: **mastery from hardware instruction scheduling to contested electromagnetic and battlefield constraints**.

---

## 📅 Seven Research Manuscripts (Sep 2026 – Mar 2027)

| Month | Published Title & Core Microarchitecture | Advanced Military / Defense Application | Primary Empirical Artifact |
|:---|:---|:---|:---|
| **1 — Sep 2026** | **Microarchitectural Limits of Vector Distance Kernels**<br>Execution Port Contention, Cache-Line Splits, and Measurement Artifacts on Modern x86/ARM | **Ultra-Low-Latency Radar Pulse De-Interleaving & ESM Threat Matching**<br>Matching millions of Pulse Descriptor Words (PDWs) in sub-microsecond deadlines on edge airborne avionics before missile lock. | Google Benchmark suite, `perf stat` IPC/port saturation, subnormal FTZ/DAZ traps across $D \in [64, 1536]$ |
| **2 — Oct 2026** | **Anisotropy-Aware Vector Quantization**<br>Dissecting the Interplay Between Embedding Cones, Hubness, and Quantization Loss Functions | **Tactical Data Link Bandwidth Compression (Link-16 / TTNT / MADL)**<br>Compressing 768-D target tracklet embeddings by $32\times$ down to 16–32 bytes for transmission over kilobit/sec RF networks under jamming. | ScaNN anisotropic loss ($h \|\mathbf{e}_\parallel\|^2 + \|\mathbf{e}_\perp\|^2$) vs MSE PQ on real 768-D dense embeddings |
| **3 — Nov 2026** | **Streaming Late Interaction in Dynamic LSM Storage**<br>Evaluating PLAID Centroid Inverted Lists vs MUVERA Fixed-Dimensional Encodings | **Real-Time Electronic Order of Battle (EOB) & Multimodal SIGINT Stream Fusion**<br>Continuous high-rate ingestion of radar/RF intercepts into append-only WAL while serving multi-vector MaxSim threat queries. | Dynamic LSM write throughput vs compaction amplification, multi-vector MaxSim query latency |
| **4 — Dec 2026** | **Scaling Frontiers: In-VRAM GPU IVF vs. NVMe DiskANN**<br>Concurrent Query Pressure and Memory-Hierarchy Trade-Offs | **Massive Acoustic Sonar & Satellite Tracklet Archival Search on Edge Platforms**<br>Searching 10M–100M acoustic signatures directly off ruggedized NVMe SSDs via kernel-bypass `io_uring` direct I/O without host RAM exhaustion. | Cost-per-QPS Pareto curves, 8–15 µs random NVMe direct I/O read profiles, Deep10M/Deep100M benchmarks |
| **5 — Jan 2027** | **Paging vs. Quantizing LLM KV Caches at Long Contexts**<br>Memory Fragmentation, Dequantization Overhead, and Serving Throughput | **Autonomous Drone Swarm Mission Planning & Edge Decision LLMs**<br>Executing 32K–128K context mission reasoning models inside the strict 16GB–32GB SWaP envelope of airborne NVIDIA Jetson Orin AGX hardware. | PagedAttention virtual memory vs 3-bit PolarQuant compression at $4\text{K} \to 128\text{K}$ tokens; VRAM fragmentation curves |
| **6 — Feb 2027** | **Mitigating Recall Collapse in Filtered ANN Graphs**<br>An Empirical Evaluation of ACORN vs. Iterative Post-Filtering Across Selectivity Spectrums | **JADC2 Multilevel Security (MLS) & Target Clearance Filtering**<br>Preventing catastrophic search failure when $99.9\%$ of nodes are filtered out ($P(\text{pass}) < 0.1\%$) by classification clearances and geolocation bounding boxes. | Recall@10 vs selectivity spectrum ($100\% \to 0.01\%$) on multi-predicate small-world graphs |
| **7 — Mar 2027** | **Unified IO-Aware GPU Serving for Retrieval and Attention**<br>FlashAttention-2, Paged KV Caches, and Multi-GPU Scaling | **Distributed Swarm Sensor-to-Shooter Target Interception Pipeline**<br>Unifying GPU CAGRA vector search with FlashAttention-2 generative reasoning on a single distributed memory pool to achieve sub-millisecond fire-control loops. | Nsight Compute Rooflines (>70% peak Tensor Core duty cycle), multi-GPU NCCL ring-allreduce scaling, end-to-end TTFT |

---

## ⏱️ The 16-Hour Production Protocol (4 Sundays × 4 Hours)
To publish top-tier empirical papers while maintaining the master curriculum:
1. **Saturday Lab Notes (09:00–13:00)**: Generate the raw benchmarks, profiler outputs, and plots for that week's component.
2. **Sunday 1 (Method & Baseline Setup)**: Formalize §1 (Question) and §2 (Method); establish baseline numbers.
3. **Sunday 2 (Parameter Sweeps)**: Execute primary sweeps across dimensions, quantization bitwidths, or filter selectivity in background.
4. **Sunday 3 (Ablations & Visuals)**: Generate figures and write §4 (Results) and §5 (Baseline comparison).
5. **Sunday 4 (Draft Freeze & Release)**: Write §6 (Limitations) and §7 (Repro commands); freeze Markdown/PDF and tag release.
