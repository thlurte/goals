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
| **CPU Server** | Intel Core / Xeon (AVX2, AVX-512, Golden Cove / Zen 4 architecture) |
| **Edge Hardware** | NVIDIA Jetson Orin AGX (ARM Cortex-A78AE, ARMv8.2-A NEON) |
| **Compilation Flags** | `clang++ -O3 -march=native -DNDEBUG -ffast-math` |
| **Measurement Suite** | Google Benchmark v1.9.0 (`DoNotOptimize`, `ClobberMemory`) + Linux `perf stat` |
| **Monitored Hardware Counters** | `cycles`, `instructions`, `L1-dcache-load-misses`, `exe_activity.exe_bound_0_ports` |

---

## 4. Controlled Parameter Sweeps
* **Experiment 1 (Port Contention & Unrolling)**: Sweep unrolling factor $U \in \{1, 2, 4, 8\}$ across dimensions $D \in \{64, 128, 512, 768, 1536\}$ to verify the exact knee where $IPC$ saturates at $>3.2$.
* **Experiment 2 (Dead Code Elimination Trap)**: Quantify the illusion of speed in naive microbenchmarks where the compiler deletes the inner distance loop due to lack of memory clobbering.
* **Experiment 3 (FTZ/DAZ Mitigation)**: Inject subnormal FP32 inputs and measure the $85	imes$ latency cliff without `_MM_SET_FLUSH_ZERO_MODE(_MM_FLUSH_ZERO_ON)`.

---

## 5. Industrial Baseline Comparison
* **Baseline A**: Naive scalar distance loop (unvectorized).
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
