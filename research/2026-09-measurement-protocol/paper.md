# Microarchitectural Limits of Vector Distance Kernels: Execution Port Contention, Cache-Line Splits, and Measurement Artifacts on Modern x86 & ARM

| Metadata | Specification |
|:---|:---|
| **Month** | 1 — September 2026 |
| **Status** | Empirical Benchmark Report |
| **Domain** | Low-Level Systems, SIMD Microarchitecture, Sub-Microsecond Signal Processing |

---

## 1. Executive Abstract & Falsifiable Question


**Core Falsifiable Question**:
> *At what vector dimensionality ($D \in [64, 1536]$) does distance calculation transition from execution-port latency bound (FMA dependency chains on Intel Port 0/1 and ARM NEON pipes) to memory-bus saturation (L1/L2 cache load port and cache-line split limits), and does a noise-free, dead-code-safe microbenchmark protocol eliminate measurement variance within a strict 5% IPC bound?*

---

## 2. Theoretical Microarchitectural Model

For a vector of dimension $D$ processed with SIMD vector width $V$ ($V=8$ for AVX2 FP32, $V=16$ for AVX-512, $V=4$ for ARM NEON):

1. **FMA Latency Bound (Single Accumulator)**:
   $$T_{\text{latency}} = \left\lceil \frac{D}{V} \right\rceil \times L_{\text{FMA}} \quad (L_{\text{FMA}} = 4\text{ cycles})$$

2. **FMA Throughput Bound ($N_{\text{acc}} \ge L_{\text{FMA}} \times R_{\text{FMA}}$ Accumulators)**:
   $$T_{\text{throughput}} = \left\lceil \frac{D}{V} \right\rceil \times \frac{1}{R_{\text{FMA}}} \quad (R_{\text{FMA}} = 2\text{ FMA units/cycle on Port 0 and Port 1})$$

3. **Memory Load Port Limit**:
   $$T_{\text{memory}} = \frac{2 \times D \times 4\text{ bytes}}{\text{L1 Cache Load Bandwidth (64 bytes/cycle)}} = \frac{D}{8}\text{ cycles}$$

4. **Denormal / Subnormal Floating-Point Exception Trap**:
   * Any distance accumulation resulting in $0 < |x| < 2^{-126}$ triggers CPU microcode exception assists, degrading execution throughput by up to **$100\times$** unless hardware FTZ/DAZ (Flush-To-Zero / Denormals-Are-Zero) flags are activated in the MXCSR register.

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

#### 5.1.1 Microarchitectural Disassembly Audit & Serial Dependency Trap
Disassembly analysis of `build/libsecan_lib.a` via `objdump -d -M intel` reveals why scalar C++ under `-O3 -march=native` fails to exploit the full hardware throughput of AMD Zen 4:

```asm
.L_inner_loop:
  movups   xmm1, XMMWORD PTR [rdi+rax*1]  ; 128-bit unaligned vector load (4 floats)
  movups   xmm3, XMMWORD PTR [rsi+rax*1]  ; 128-bit unaligned vector load (4 floats)
  add      rax, 0x10                      ; Advance offset by 16 bytes
  subps    xmm1, xmm3                     ; Parallel subtraction (4 floats)
  mulps    xmm1, xmm1                     ; Parallel squaring (4 floats)
  addss    xmm0, xmm1                     ; Accumulate lane 0
  movaps   xmm2, xmm1
  shufps   xmm2, xmm1, 0x55               ; Extract lane 1
  addss    xmm0, xmm2                     ; Serial accumulation into xmm0
  movaps   xmm2, xmm1
  unpckhps xmm2, xmm1                     ; Extract lane 2
  shufps   xmm1, xmm1, 0xff               ; Extract lane 3
  addss    xmm0, xmm2                     ; Serial accumulation into xmm0
  addss    xmm0, xmm1                     ; Serial accumulation into xmm0
  cmp      rax, rcx
  jne      .L_inner_loop
```

**Key Architectural Insights**:
1. **The In-Loop Horizontal Reduction Penalty**: Because the high-level C++ source code reduces into a single scalar variable `float sum`, the auto-vectorizer is forced to perform an intra-register horizontal reduction *inside* the tight loop. For every 4 floats processed, the CPU executes 2 vector arithmetic instructions (`subps`, `mulps`) followed by **6 shuffling and serial scalar accumulation instructions** (`shufps`, `unpckhps`, `addss`).
2. **Serial Dependency Stall on `xmm0`**: The four sequential `addss` instructions create a strict data dependency chain on register `xmm0`. With an addition latency of $3$ cycles on Zen 4, the accumulator remains stalled, capping the overall Instructions Per Cycle ($IPC$) at **1.719**—far below Zen 4's maximum retire width of 6 instructions per cycle.
3. **Absence of 256-bit AVX2 / FMA**: The compiler defaults to 128-bit `xmm` registers without fused multiply-add (`vfmadd213ps`), leaving both 256-bit execution pipes on AMD Zen 4 Port 0 and Port 1 severely underutilized.

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
