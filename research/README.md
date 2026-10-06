# Empirical Systems Benchmarking: Profiling, Microarchitecture & Systems Retrieval

Instead of academic paper writing and theoretical manuscript deadlines, the empirical systems track is engineered around **rigorous, reproducible hardware benchmarking in `secan` and GPU kernels**.

All empirical data collected during the weekday morning builder blocks (**Mondays & Thursdays 06:30–08:30**) directly fuels the **28 Weekly Technical Articles** drafted and published every **Friday morning (06:30–08:30)** (see [`curriculum/essays.md`](../curriculum/essays.md)).

## Benchmark Contract: What Makes Work Showcaseable

A feature is not complete because it compiles or produces a promising one-off number. Every completed kernel, index, or reranker must leave a comparable evidence package in `secan`:

```text
secan/
├── benchmarks/
│   ├── manifests/       # machine + dataset + command inputs
│   ├── results/         # immutable JSON/CSV outputs, one file per run
│   └── plots/           # derived Pareto and latency figures
└── docs/benchmarks/     # short interpretation notes linked from the README
```

Use [`templates/benchmark_manifest.template.json`](templates/benchmark_manifest.template.json) and [`templates/benchmark_result.template.json`](templates/benchmark_result.template.json) as the stable interchange format. The templates are deliberately owned here in `goals`; the executed data belongs in `secan` beside the executable that produced it.

### Required evidence for each result claim

| Evidence | Requirement |
|:---|:---|
| **Correctness** | Differential result against exact FP32 search or another defined oracle; tolerance and failure count recorded. |
| **Reproducibility** | Dataset split/checksum, machine, compiler/flags, command, seed, thread policy, and clock state recorded. |
| **Quality** | ANN: Recall@1/10/100. Retrieval: add NDCG@10 and MRR where relevance labels exist. |
| **Cost** | QPS, p50/p95/p99, index build time, bytes/vector, and peak RSS. |
| **Hardware explanation** | CPU: IPC and cache/branch/TLB counters where relevant. GPU: kernel time, achieved bandwidth/FLOPS, and relevant Nsight counters. |
| **Comparison** | Previous `secan` baseline; add Faiss, hnswlib, Qdrant, or cuVS when the algorithm is comparable. Identical dataset, metric, target quality, and hardware are mandatory. |
| **Interpretation** | One short note: what won or lost, why the evidence supports that conclusion, and the known failure boundary. |

### Weekly close rule

Friday’s article and release update are complete only after the week's raw result JSON/CSV, a plot, and one README row have been added. A result below the measured noise floor is recorded as **inconclusive**, not as a speedup. Sweep at least one meaningful tradeoff parameter—such as `nprobe`, `efSearch`, PQ subspaces/bit-rate, batch size, or rerank depth—rather than publishing one cherry-picked configuration.

### Comparison discipline

External engines are reference implementations, not dependencies of `secan`'s inner loop. The objective is an honest explanation, not an immediate victory. “Same recall, slower due to scalar LUT layout; cache-miss profile identifies the next optimization” is a valuable result.

---

## 🏛️ The Two Flagship Systems Implementations

```
+──────────────────────────────────────────────────────────────────────────────────────────────────+
|  AUTUMN TRACK (Months 1–3): MATHEMATICAL REPRESENTATION & QUANTIZATION                           |
|  Flagship Implementation 1: Geometry-Aware Anisotropic Polar Quantization (GAPQ) in secan        |
|  • Month 1: Measurement Protocol, Port Contention & Empirical Anisotropy Bounds                  |
|  • Month 2: Adaptive Ellipsoidal Polar Lattice & Closed-Form Unbiased QJL Implementation         |
|  • Month 3: In-Register SIMD Kernels, SIFT/Cohere/OpenAI Benchmarks & FastScan Pareto Sweeps     |
+──────────────────────────────────────────────────────────────────────────────────────────────────+
|  WINTER/SPRING TRACK (Months 4–7): GPU SILICON & HARDWARE CO-DESIGN                              |
|  Flagship Implementation 2: FlashMaxSim: Hardware-Fused In-SRAM Late Interaction for secan       |
|  • Month 4: Memory Wall in Multimodal Late Interaction & Baseline GPU Kernels                   |
|  • Month 5: Online Max Reduction Invariant & SRAM Double-Buffering Mechanics                     |
|  • Month 6: Bare-Metal CUTLASS Kernel with TMA & Warp Specialization                             |
|  • Month 7: Nsight Roofline Saturation (>75% Peak TFLOPS) & Multi-GPU NCCL Scaling               |
+──────────────────────────────────────────────────────────────────────────────────────────────────+
```

---

## 📅 Seven Empirical Systems Milestones (Sep 2026 – Mar 2027)

| Month | Flagship Pillar & Systems Milestone | Benchmark Target | Primary Empirical Artifacts |
|:---|:---|:---|:---|
| **1 — Sep 2026** | **GAPQ Milestone 1**: *Microarchitectural Limits of Distance Kernels & Embedding Anisotropy* (`research/2026-09-measurement-protocol/`) | SIMD Distance Kernels | Google Benchmark suite, `perf stat` IPC/port tables, mean pairwise cosine distributions across SIFT1M, Cohere-1M, and LLaMA embeddings |
| **2 — Oct 2026** | **GAPQ Milestone 2**: *Geometry-Aware Anisotropic Polar Quantization & FastScan Execution* (`research/2026-10-anisotropic-quantization/`) | Quantization Sweeps | Quantization ablations: TurboQuant vs GAPQ on severe cones (mean cosine $>0.40$), hubness mitigation, closed-form variance proofs |
| **3 — Nov 2026** | **GAPQ Milestone 3**: *Sub-2-Bit In-Register SIMD Execution & Dynamic LSM Storage* (`research/2026-11-rabitq-lsm/`) | Dynamic Ingestion & MIPS | AVX-512/AVX2 bitwise kernels, Pareto frontier (Recall@10 vs QPS) on Cohere-1M and OpenAI-1M; LSM compaction latency curves |
| **4 — Dec 2026** | **FlashMaxSim Milestone 1**: *The Memory Wall in Multimodal Late Interaction: Baseline GPU Profiling* (`research/2026-12-flashattn-vamana/`) | In-VRAM GPU IVF & Vamana | Profiling global VRAM traffic on ColPali 1030-token visual pages; baseline batched GEMM vs HBM bandwidth saturation |
| **5 — Jan 2027** | **FlashMaxSim Milestone 2**: *The Online Max Reduction Invariant & In-SRAM Accumulation* (`research/2027-01-cagra-warp-search/`) | PagedAttention & CAGRA | Mathematical proof and profiling of $O(L_q \cdot L_d) \to O(L_q)$ SRAM memory reduction; Python/CUDA numerical parity simulator |
| **6 — Feb 2027** | **FlashMaxSim Milestone 3**: *Bare-Metal CUTLASS Kernel with Hopper/Blackwell TMA* (`research/2027-02-predicate-aware-graphs/`) | ACORN Predicate Routing | CUTLASS Producer/Consumer warpgroups, asynchronous double-buffering, eliminating shared memory bank conflicts |
| **7 — Mar 2027** | **FlashMaxSim Milestone 4**: *Nsight Compute Roofline Validation & Multi-GPU Scaling* (`research/2027-03-gpu-serving/`) | Unified GPU Serving | Nsight Compute Roofline plots ($>75\%$ peak TFLOPS), end-to-end ColPali visual search speedups ($5\times\text{–}8\times$ vs PyTorch/vLLM) |

---

## ⏱️ The Empirical Systems Rhythm
To produce publication-grade systems engineering without academic burnout:
1. **Monday Morning Builder (06:30–08:30)**: Hardware profiling, `perf stat` cache miss sweeps, and microarchitectural benchmark runs in `secan`.
2. **Tuesday & Wednesday Morning Builder (06:30–08:30)**: Deep Learning track implementation (from scratch autograd, transformer architectures, tokenization).
3. **Thursday Morning Builder (06:30–08:30)**: DL model / vector retrieval integration, end-to-end Pareto frontier sweeps (Recall vs QPS, tail latencies).
4. **Friday Morning Systems Article (06:30–08:30)**: Draft and publish the weekly technical article (from [`curriculum/essays.md`](../curriculum/essays.md)) synthesized directly from the week's benchmark data.
