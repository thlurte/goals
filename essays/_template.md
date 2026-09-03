# [Essay Title]: [Technical Subtitle]

| Metadata | Specification |
|:---|:---|
| **Week** | {N} — {Date} |
| **Theme / Block** | {e.g. SIMD Intrinsics / Quantization / Graph Traversal / GPU Kernels} |
| **Hardware & Systems Target** | {e.g. x86 AVX2/AVX-512, ARM NEON, CUDA, perf stat, nsys} |
| **Target Code Artifact** | `secan::{component}` |

---

## 🏛️ Writing Architecture: The 80/20 Systems Lab-Note Formula
Maintain disciplined systems engineering rigor:
* **10% Systems Motivation**: The concrete bottleneck (e.g. FMA pipeline stalls, cache line crossing, memory fragmentation).
* **30% Pure Mathematics**: Rigorous LaTeX derivations, metric formulations, and geometric invariants.
* **40% Silicon Execution**: C++20 / CUDA intrinsics, CPU port contention, assembly pipelines, hard profiler counters.
* **20% Benchmark Synthesis**: Empirical latency/throughput speedups and Pareto analysis.

---

## 1. Systems Motivation & Problem Definition (10%)
*Define the exact microarchitectural or computational bottleneck.*
* **Hardware Context**: What CPU/GPU resource is under contention? (e.g. execution ports, memory bandwidth, L1/L2 cache capacity).
* **Failure Mode of Naive Code**: What happens if naive unoptimized code runs? (e.g. instruction pipeline bubbles, store-forwarding stalls, $O(N^2)$ VRAM explosion).
* **Target Objective**: State the exact latency, throughput, or memory footprint target.

---

## 2. Mathematical Derivation & Algorithmic Geometry (30%)
*Formal mathematical proofs with zero hand-waving.*
* **Objective Function**: Write out the exact equations in LaTeX.
* **Analytical Derivation**: Step-by-step mathematical proof (e.g. gradient calculation, error variance bound, spanner stretch).
* **Key Geometric Invariant**: Highlight the mathematical property enabling hardware acceleration.

---

## 3. Microarchitectural Silicon Implementation & Profiler Evidence (40%)
*Hard low-level engineering that sets you apart from 99.9% of developers.*
* **Handcrafted Intrinsics**: Show the inner computational kernel in clean C++20 or CUDA (e.g. `vfmaq_f32`, `_mm256_shuffle_epi8`, `vdotq_u32`, `cp.async`).
* **Microarchitectural Mechanics**:
  * Which execution ports are being saturated? (e.g. Intel Ports 0 & 1 for FMAs).
  * How many independent accumulator registers are unrolled to break instruction latency dependency chains?
  * How is memory aligned? (`alignas(64)` cache-line alignment to avoid false sharing).
  * Are subnormal denormal floating-point traps masked? (FTZ / DAZ mode).
* **Hard Profiler Evidence Table**:
  ```
  | Hardware Counter Metric        | Naive Baseline | Optimized secan Kernel | Improvement |
  |:-------------------------------|:---------------|:-----------------------|:------------|
  | Instructions Per Cycle (IPC)   | 0.85           | 3.42                   | 4.02x       |
  | L1-D Cache Miss Rate           | 8.4%           | 0.12%                  | 70x cleaner |
  | Branch Misprediction Rate       | 2.1%           | 0.02%                  | Eliminated  |
  | Port 0/1 Saturation Duty Cycle  | 22%            | 88%                    | Near-Peak   |
  | Latency per Vector Operation   | 1,420 ns       | 165 ns                 | 8.6x faster |
  ```

---

## 4. Benchmark Synthesis & Pareto Evaluation (20%)
*Translate silicon metrics into system-level performance gains.*
* **Empirical Speedup**: Compare against standard baselines (e.g. naive loop, standard Faiss, scalar reference).
* **Reproducibility Command**:
  ```bash
  ./build/benchmarks/bench_{name} --benchmark_filter=all
  ```
