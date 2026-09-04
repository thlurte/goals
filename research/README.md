# Monthly Research Program: Systems Architecture & High-Performance Retrieval

Instead of fragmenting effort across disconnected, shallow preprints, the research track is engineered around **Two Landmark, Tier-1 Conference Submissions (ICLR / ICML / MLSys)** that establish original state-of-the-art breakthroughs in vector search and AI systems.

Each calendar month delivers a rigorous, peer-review-grade **Milestone Phase** that builds directly into these two flagship manuscripts.

---

## 🏛️ The Two Landmark Research Papers

```
+──────────────────────────────────────────────────────────────────────────────────────────────────+
|  AUTUMN TRACK (Months 1–3): MATHEMATICAL REPRESENTATION & QUANTIZATION                           |
|  Landmark Paper 1: Geometry-Aware Anisotropic Polar Quantization (GAPQ)                          |
|  Target Venue: ICLR / ICML 2027 (Representation & Information Theory Track)                      |
|  • Month 1: Milestone 1 — Measurement Protocol, Port Contention & Empirical Anisotropy Bounds    |
|  • Month 2: Milestone 2 — Adaptive Ellipsoidal Polar Lattice & Closed-Form Unbiased QJL Proof    |
|  • Month 3: Milestone 3 — In-Register SIMD Kernels, SIFT/Cohere/OpenAI Benchmarks & Freeze      |
+──────────────────────────────────────────────────────────────────────────────────────────────────+
|  WINTER/SPRING TRACK (Months 4–7): GPU SILICON & HARDWARE CO-DESIGN                              |
|  Landmark Paper 2: FlashMaxSim: Hardware-Fused In-SRAM Late Interaction for Multimodal Search    |
|  Target Venue: MLSys / ICLR 2027 (Systems & Hardware Co-Design Track)                            |
|  • Month 4: Milestone 1 — Memory Wall in Multimodal Late Interaction & Baseline GPU Kernels      |
|  • Month 5: Milestone 2 — Online Max Reduction Invariant & SRAM Double-Buffering Mechanics       |
|  • Month 6: Milestone 3 — Bare-Metal CUTLASS Kernel with TMA & Warp Specialization               |
|  • Month 7: Milestone 4 — Nsight Roofline Saturation (>75% Peak TFLOPS) & Master Submission     |
+──────────────────────────────────────────────────────────────────────────────────────────────────+
```

---

## 📅 Seven Research Milestones (Sep 2026 – Mar 2027)

| Month | Landmark Pillar & Milestone Phase | Publish by | Primary Empirical Artifacts |
|:---|:---|:---|:---|
| **1 — Sep 2026** | **GAPQ Milestone 1**: *Microarchitectural Limits of Distance Kernels & Empirical Embedding Cone Anisotropy* (`research/2026-09-measurement-protocol/`) | **Sun Sep 27** | Google Benchmark suite, `perf stat` IPC/port tables, mean pairwise cosine distributions across SIFT1M, Cohere-1M, and LLaMA embeddings |
| **2 — Oct 2026** | **GAPQ Milestone 2**: *Geometry-Aware Anisotropic Polar Quantization: The Adaptive Ellipsoidal Lattice & Unbiased QJL Proof* (`research/2026-10-anisotropic-quantization/`) | **Sun Oct 25** | Quantization ablations: TurboQuant vs GAPQ on severe cones (mean cosine $>0.40$), hubness mitigation, closed-form variance proofs |
| **3 — Nov 2026** | **GAPQ Milestone 3 (Paper 1 Freeze)**: *Sub-2-Bit In-Register SIMD Execution & Manuscript Submission Freeze* (`research/2026-11-rabitq-lsm/`) | **Sun Nov 29** | AVX-512/AVX2 bitwise kernels, Pareto frontier (Recall@10 vs QPS) on Cohere-1M and OpenAI-1M; **Landmark Paper 1 Draft Freeze** |
| **4 — Dec 2026** | **FlashMaxSim Milestone 1**: *The Memory Wall in Multimodal Late Interaction: Baseline GPU Kernel Profiling* (`research/2026-12-flashattn-vamana/`) | **Sun Dec 27** | Profiling global VRAM traffic on ColPali 1030-token visual pages; baseline batched GEMM vs HBM bandwidth saturation |
| **5 — Jan 2027** | **FlashMaxSim Milestone 2**: *The Online Max Reduction Invariant & In-SRAM Accumulation Mechanics* (`research/2027-01-cagra-warp-search/`) | **Sun Jan 31** | Mathematical proof of $O(L_q \cdot L_d) \to O(L_q)$ SRAM memory complexity reduction; Python/CUDA numerical parity simulator |
| **6 — Feb 2027** | **FlashMaxSim Milestone 3**: *Bare-Metal CUTLASS Implementation with Hopper/Blackwell TMA & Warp Specialization* (`research/2027-02-predicate-aware-graphs/`) | **Sun Feb 28** | CUTLASS Producer/Consumer warpgroups, asynchronous double-buffering, eliminating shared memory bank conflicts |
| **7 — Mar 2027** | **FlashMaxSim Milestone 4 (Paper 2 Freeze)**: *Nsight Compute Roofline Validation & Master Conference Submission* (`research/2027-03-gpu-serving/`) | **Fri Mar 12** | Nsight Compute Roofline plots ($>75\%$ peak TFLOPS), end-to-end ColPali visual search speedups ($5\times\text{–}8\times$ vs PyTorch/vLLM); **Landmark Paper 2 Draft Freeze** |

---

## ⏱️ The 16-Hour Production Protocol (4 Sundays × 4 Hours)
To publish top-tier conference manuscripts without burnout:
1. **Saturday Lab Notes (09:00–13:00)**: Every Saturday note MUST directly generate the raw benchmark tables and plots for that week's component.
2. **Sunday 1 (Method & Baseline Setup)**: Write §1 (Question) and §2 (Method); run scalar/Faiss baseline benchmarks.
3. **Sunday 2 (Core Sweep Runs)**: Execute primary parameter sweeps across dimensions/selectivity in background; dump raw CSVs to `notes/`.
4. **Sunday 3 (Ablations & Plots)**: Generate `figures/` using matplotlib scripts; write §4 (Results) and §5 (Baseline comparison).
5. **Sunday 4 (Draft Freeze & Tag)**: Write §6 (Limitations) and §7 (Repro commands); freeze Markdown/PDF + Git tag. **Never run new experiments on Sunday 4.**
