# Microarchitectural Limits of Vector Distance Kernels: Execution Port Contention, Cache-Line Splits, and Measurement Artifacts on Modern x86 & ARM

| Metadata | Specification |
|:---|:---|
| **Month** | 1 — September 2026 |
| **Status** | Active Working Manuscript |
| **Domain** | Low-Level Systems, SIMD Microarchitecture, Sub-Microsecond Signal Processing |

---

## 1. Executive Abstract & Falsifiable Question


**Core Falsifiable Question**:
> *At what vector dimensionality ($D \in [64, 1536]$) does distance calculation transition from execution-port latency bound (FMA dependency chains on Intel Port 0/1 and ARM NEON pipes) to memory-bus saturation (L1/L2 cache load port and cache-line split limits), and does a noise-free, dead-code-safe microbenchmark protocol eliminate measurement variance within a strict 5% IPC bound?*

---

## 2. Theoretical Microarchitectural Model

For a vector of dimension $D$ processed with SIMD vector width $V$ ($V=8$ for AVX2 FP32, $V=16$ for AVX-512, $V=4$ for ARM NEON):
1. **FMA Latency Bound (Single Accumulator)**:
   $$T_{	ext{latency}} = \left\lceil rac{D}{V} 
ight
ceil 	imes L_{	ext{FMA}} \quad (L_{	ext{FMA}} = 4	ext{ cycles})$$
2. **FMA Throughput Bound ($N_{	ext{acc}} \ge L_{	ext{FMA}} 	imes R_{	ext{FMA}}$ Accumulators)**:
   $$T_{	ext{throughput}} = \left\lceil rac{D}{V} 
ight
ceil 	imes rac{1}{R_{	ext{FMA}}} \quad (R_{	ext{FMA}} = 2	ext{ FMA units/cycle on Port 0 & 1})$$
3. **Memory Load Port Limit**:
   $$T_{	ext{memory}} = rac{2 	imes D 	imes 4	ext{ bytes}}{	ext{L1 Cache Load Bandwidth (64 bytes/cycle)}} = rac{D}{8}	ext{ cycles}$$
4. **Denormal / Subnormal Floating-Point Exception Trap**:
   * Any distance accumulation resulting in $0 < |x| < 2^{-126}$ triggers CPU microcode exception assists, degrading execution throughput by up to **$100	imes$** unless hardware FTZ/DAZ (Flush-To-Zero / Denormals-Are-Zero) flags are activated in the MXCSR register.

---

## 3. Experimental Protocol & Hardware Setup

| Hardware Platform | Specification |
|:---|:---|
| **CPU Microarchitecture** | AMD Zen 4 (Hawk Point, 12 Threads @ up to 5.02 GHz) |
| **Cache Hierarchy** | L1D: 32 KiB (x6), L1I: 32 KiB (x6), L2: 1024 KiB (x6), L3: 16 MiB Unified |
| **Energy Policy** | `amd-pstate-epp` driver locked to `performance` mode, Core Boost active |
| **Compilation Flags** | `g++ -O3 -march=native -DNDEBUG` (CMake Release) |
| **Measurement Suite** | Google Benchmark v1.9.0 (`DoNotOptimize`) + Linux `perf stat` hardware counters |
| **Monitored PMU Counters** | `cycles`, `instructions`, `L1-dcache-loads`, `L1-dcache-load-misses`, `branch-misses` |

---

## 4. Controlled Parameter Sweeps
* **Experiment 1 (Port Contention & Unrolling)**: Sweep unrolling factor $U \in \{1, 2, 4, 8\}$ across dimensions $D \in \{64, 128, 256, 512, 768, 1024, 1536\}$ to verify the exact knee where $IPC$ saturates at $>3.2$.
* **Experiment 2 (Dead Code Elimination Trap)**: Quantify the illusion of speed in naive microbenchmarks where the compiler deletes the inner distance loop due to lack of memory clobbering.
* **Experiment 3 (FTZ/DAZ Mitigation)**: Inject subnormal FP32 inputs and measure the latency cliff without `_MM_SET_FLUSH_ZERO_MODE(_MM_FLUSH_ZERO_ON)`.

---

## 5. Industrial Baseline Comparison

### 5.1 Calibrated Baseline A: Naive Scalar Loop (Unvectorized)
*Measured on AMD Zen 4 @ 5.02 GHz max boost (L1D Miss Rate: 0.021%, IPC: 1.719)*:

| Vector Dimension ($D$) | Mean Latency ($ns$) | CPU Time ($ns$) | Iterations | Memory Bandwidth ($\text{GiB/s}$) | Latency / Dim ($ns/D$) |
|:---|:---:|:---:|:---:|:---:|:---:|
| **$D = 64$** | **27.0 ns** | 26.9 ns | 24,557,193 | **17.71 GiB/s** | 0.42 ns |
| **$D = 128$** | **58.6 ns** | 58.4 ns | 12,227,023 | **16.32 GiB/s** | 0.45 ns |
| **$D = 256$** | **153.0 ns** | 152.0 ns | 4,617,914 | **12.53 GiB/s** | 0.59 ns |
| **$D = 512$** | **329.0 ns** | 328.0 ns | 2,132,348 | **11.62 GiB/s** | 0.64 ns |
| **$D = 768$** | **518.0 ns** | 517.0 ns | 1,325,745 | **11.08 GiB/s** | 0.67 ns |
| **$D = 1024$** | **689.0 ns** | 688.0 ns | 986,451 | **11.09 GiB/s** | 0.67 ns |
| **$D = 1536$** | **1056.0 ns** | 1054.0 ns | 667,606 | **10.86 GiB/s** | 0.68 ns |

* **Baseline B**: Compiler auto-vectorized loop (`-O3 -march=native`).
* **Baseline C**: Faiss `fvec_L2sqr` standard release.
* **This Work**: `secan::simd::l2_squared` (4-way register unrolled with explicit port scheduling).

---

## 6. Reproducibility
```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --target bench_distance
perf stat -e cycles,instructions,L1-dcache-load-misses,branch-misses ./build/benchmarks/bench_distance
```
