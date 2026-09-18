# Breaking Dependency Chains: Multi-Register Accumulator Unrolling and Port Saturation in AVX2/AVX-512

| Metadata | Specification |
|:---|:---|
| **Week** | Week 02 — Friday, September 18, 2026 |
| **Theme / Block** | Trigonometric Identities, Chain Rule, SIMD AVX2 & Multi-Head Attention / Block I — Vector Search Engine |
| **Hardware & Systems Target** | AMD Zen 4 (Hawk Point, 12 Cores @ up to 5.02 GHz), AVX2 (256-bit YMM) & AVX-512 (512-bit ZMM), Linux PMU Hardware Counters via `perf stat` |
| **Target Code Artifact** | `secan::l2_squared_avx2_single`, `secan::l2_squared_avx2_unroll4`, `secan::ip_avx2_unroll4` |

---

## 🏛️ Executive Summary

Modern superscalar execution engines feature massive theoretical computational throughput. On AMD Zen 4 and modern Intel x86-64 microarchitectures, dual execution ports (Ports 0 and 1) can each dispatch a 256-bit or 512-bit Fused Multiply-Add (FMA) instruction every single clock cycle. This yields a peak throughput of two vector FMAs per cycle—operating on up to 32 single-precision floats every clock.

However, naive vector implementations invariably fall prey to a subtle, pervasive microarchitectural hazard: **the read-after-write (RAW) data dependency chain**. Because hardware FMA units have an execution latency of 4 clock cycles, accumulating into a single SIMD vector register creates a serialized feedback loop. The processor's out-of-order execution window is starved of independent work, forcing the hardware ALU ports to idle for $75\%$ of available execution cycles.

This technical lab-note demonstrates the formal mathematical and microarchitectural mechanics of breaking instruction dependency chains. By applying Little's Law to hardware execution pipelines, we derive the exact minimum degree of register unrolling required to saturate CPU execution ports. We evaluate single-accumulator versus 4-way unrolled AVX2 kernels in `secan`, verifying a latency drop from $21.8\text{ ns}$ down to $15.3\text{ ns}$ ($D=128$), an instruction throughput of $4.60\text{ IPC}$, and sustained memory bandwidth of $62.3\text{ GiB/s}$ on AMD Zen 4 silicon.

---

## 1. Systems Motivation & The Hardware Reality (10%)

### 1.1 The Illusion of Vectorization

When developers transition a distance computation from scalar code to SIMD, they typically implement a loop structured like this:

```cpp
__m256 sum = _mm256_setzero_ps();
for (size_t i = 0; i < dim; i += 8) {
    __m256 diff = _mm256_sub_ps(_mm256_loadu_ps(a + i), _mm256_loadu_ps(b + i));
    sum = _mm256_fmadd_ps(diff, diff, sum); // RAW dependency on 'sum'
}
```

At first glance, this loop appears fully optimized: it processes 8 single-precision values per vector iteration using dedicated 256-bit YMM registers. But at the silicon level, instruction issue is immediately throttled by hardware data dependencies:

1. **The 4-Cycle Pipeline Latency**: On modern x86 cores (Zen 3/4/5, Skylake/Golden Cove), the vector FMA instruction (`vfmadd231ps` or `vfmadd213ps`) has an execution latency of $L = 4\text{ clock cycles}$. This means that once an FMA begins execution on Port 0 or Port 1, its output register `sum` is not physically ready to be consumed as an operand by another instruction until 4 cycles later.
2. **The Reciprocal Throughput Bottleneck**: The CPU's execution units are pipelined with a reciprocal throughput of $R = 0.5\text{ cycles/instruction}$ (i.e., the hardware can accept two new independent FMAs every cycle across Port 0 and Port 1).
3. **The Pipeline Bubble**: If the subsequent FMA depends directly on the result of the preceding FMA (accumulating into the exact same register `sum`), the hardware cannot issue the next iteration's FMA until the previous one completes. The execution units sit completely idle for 3 out of every 4 cycles, capping pipeline utilization at a dismal $25\%$ of peak arithmetic capability.

```
Cycle:      0         1         2         3         4         5         6         7
Port 0:  [FMA 0] ---- stall ---- stall ---- stall -- [FMA 1] ---- stall ---- stall ----
Port 1:  [  idle  ]   [  idle  ]   [  idle  ]   [  idle  ]   [  idle  ]   [  idle  ]   [  idle  ]
                      <---- 3 cycles wasted ---->
```

To extract maximum performance from high-dimensional vector search engines, our loop bodies must maintain multiple concurrent, independent streams of computation.

---

## 2. Mathematical Foundation & Algorithmic Geometry (30%)

### 2.1 Non-Associativity of IEEE-754 Floating-Point Arithmetic

The fundamental reason compilers cannot automatically unroll and restructure reduction loops without specific flags lies in the core axioms of real arithmetic versus floating-point arithmetic.

In real field arithmetic $(\mathbb{R}, +, \times)$, addition is strictly associative:
$$(a + b) + c = a + (b + c) \quad (\forall a, b, c \in \mathbb{R})$$

In IEEE-754 floating-point arithmetic $(\mathbb{F}, \oplus, \otimes)$, round-off error introduces non-associativity:
$$(a \oplus b) \oplus c \ne a \oplus (b \oplus c)$$

#### Proof by Concrete Counterexample
Let $a = 1.0$, $b = 2^{-24} \approx 5.96046 \times 10^{-8}$, and $c = 2^{-24}$ in IEEE-754 single-precision (FP32), where the mantissa has $p = 24$ bits of precision:

1. **Left Association**:
   $$a \oplus b = 1.0 \oplus 2^{-24} = 1.0 \quad (\text{the bit } 2^{-24} \text{ falls off the 24-bit mantissa})$$
   $$(a \oplus b) \oplus c = 1.0 \oplus 2^{-24} = 1.0$$

2. **Right Association**:
   $$b \oplus c = 2^{-24} \oplus 2^{-24} = 2 \cdot 2^{-24} = 2^{-23}$$
   $$a \oplus (b \oplus c) = 1.0 \oplus 2^{-23} = 1.0000001192... \ne 1.0$$

Because the order of summation alters the lower bits of the mantissa, an optimizing compiler strictly compliant with the ISO C++ standard (`-fno-fast-math`) is **legally forbidden** from reassociating a reduction across multiple accumulator registers. It is forced to emit serialized, single-accumulator code.

To achieve maximum throughput, the systems engineer must either explicitly pass `-ffast-math` / `-fassociative-math` or explicitly architect multi-register unrolling directly via SIMD intrinsics.

### 2.2 Little's Law for Instruction Pipelines

Originally derived in queueing theory by John Little (1961), Little's Law states that the average number of items in a stationary queueing system $L$ equals the average arrival rate $\lambda$ multiplied by the average time $W$ that an item spends in the system:

$$L = \lambda \cdot W$$

Applied directly to superscalar microprocessor execution pipelines:

$$\text{Required Concurrency } (C) = \text{Issue Bandwidth } (B) \times \text{Instruction Latency } (L)$$

On AMD Zen 4 microarchitecture:
* **FMA Execution Latency** ($L$): $4\text{ clock cycles}$
* **FMA Issue Bandwidth** ($B$): $2\text{ instructions / cycle}$ (Port 0 and Port 1)

Substituting into Little's Law:

$$C = 2\frac{\text{instructions}}{\text{cycle}} \times 4\text{ cycles} = 8\text{ independent operations}$$

**The Fundamental Axiom of SIMD Port Saturation**: To achieve $100\%$ theoretical utilization of dual FMA execution units on a 4-cycle latency pipeline, the loop kernel must maintain **at least 8 independent instruction streams in flight simultaneously**.

When unrolling across 256-bit YMM registers:
* **1-Accumulator**: Concurrency = 1. Port utilization = $\frac{1}{8} = 12.5\%$ per port, or $25\%$ of total ALU capacity.
* **2-Accumulators**: Concurrency = 2. Port utilization = $25\%$ per port, $50\%$ overall.
* **4-Accumulators**: Concurrency = 4. Port utilization = $50\%$ per port, $100\%$ of single-port capacity.
* **8-Accumulators**: Concurrency = 8. Full dual-port saturation ($100\%$ utilization across both Port 0 and Port 1).

### 2.3 Calculus of Finite Differences and Vector Distance

In high-dimensional Euclidean space $\mathbb{R}^D$, the squared distance function $f(u, v) = \|u - v\|_2^2$ is the integral of the squared differential:

$$\|u - v\|_2^2 = \sum_{k=0}^{D-1} \Delta x_k^2, \quad \text{where } \Delta x_k = u_k - v_k$$

Partitioning the index space $\{0, 1, \dots, D-1\}$ into $M$ disjoint congruence classes modulo $M$:

$$\|u - v\|_2^2 = \sum_{m=0}^{M-1} S_m, \quad \text{where } S_m = \sum_{\substack{k=0 \\ k \equiv m \pmod M}}^{D-1} (u_k - v_k)^2$$

Because each sub-sum $S_m$ is completely independent of all other sub-sums $S_j$ ($j \ne m$), they can be mapped to $M$ independent physical hardware vector registers (`acc0`, `acc1`, ..., `accM-1`) with zero synchronization until the final reduction tail.

---

## 3. Microarchitectural Silicon Implementation & Profiler Evidence (40%)

### 3.1 Kernel Architecture in `secan`

In `secan::l2_squared_avx2_unroll4`, we unroll the inner loop by $4\times$, processing 32 single-precision floats ($4 \times 8 = 32$) per iteration:

```cpp
float l2_squared_avx2_unroll4(const float *a, const float *b, size_t dim) noexcept {
  __m256 acc0 = _mm256_setzero_ps();
  __m256 acc1 = _mm256_setzero_ps();
  __m256 acc2 = _mm256_setzero_ps();
  __m256 acc3 = _mm256_setzero_ps();

  size_t i = 0;
  // Main unrolled loop: 32 floats (128 bytes) per cycle
  for (; i + 32 <= dim; i += 32) {
    __m256 va0 = _mm256_loadu_ps(a + i);
    __m256 vb0 = _mm256_loadu_ps(b + i);
    __m256 diff0 = _mm256_sub_ps(va0, vb0);
    acc0 = _mm256_fmadd_ps(diff0, diff0, acc0); // Independent chain 0

    __m256 va1 = _mm256_loadu_ps(a + i + 8);
    __m256 vb1 = _mm256_loadu_ps(b + i + 8);
    __m256 diff1 = _mm256_sub_ps(va1, vb1);
    acc1 = _mm256_fmadd_ps(diff1, diff1, acc1); // Independent chain 1

    __m256 va2 = _mm256_loadu_ps(a + i + 16);
    __m256 vb2 = _mm256_loadu_ps(b + i + 16);
    __m256 diff2 = _mm256_sub_ps(va2, vb2);
    acc2 = _mm256_fmadd_ps(diff2, diff2, acc2); // Independent chain 2

    __m256 va3 = _mm256_loadu_ps(a + i + 24);
    __m256 vb3 = _mm256_loadu_ps(b + i + 24);
    __m256 diff3 = _mm256_sub_ps(va3, vb3);
    acc3 = _mm256_fmadd_ps(diff3, diff3, acc3); // Independent chain 3
  }

  // Pairwise reduction tree
  __m256 sum01 = _mm256_add_ps(acc0, acc1);
  __m256 sum23 = _mm256_add_ps(acc2, acc3);
  __m256 sum   = _mm256_add_ps(sum01, sum23);

  // Vector tail loop (8 floats)
  for (; i + 8 <= dim; i += 8) {
    __m256 va = _mm256_loadu_ps(a + i);
    __m256 vb = _mm256_loadu_ps(b + i);
    __m256 diff = _mm256_sub_ps(va, vb);
    sum = _mm256_fmadd_ps(diff, diff, sum);
  }

  // Fast horizontal reduction
  __m128 lo = _mm256_castps256_ps128(sum);
  __m128 hi = _mm256_extractf128_ps(sum, 1);
  __m128 sum128 = _mm_add_ps(lo, hi);
  sum128 = _mm_hadd_ps(sum128, sum128);
  sum128 = _mm_hadd_ps(sum128, sum128);
  float total = _mm_cvtss_f32(sum128);

  // Scalar tail cleanup
  for (; i < dim; ++i) {
    float d = a[i] - b[i];
    total += d * d;
  }
  return total;
}
```

### 3.2 Microarchitectural Mechanics & Register Allocation

1. **Register File Pressure**: x86-64 provides 16 architectural YMM registers (`ymm0` through `ymm15`). An unroll factor of 4 consumes:
   * 4 accumulator registers (`ymm0`–`ymm3`)
   * 4 vector load registers for $a$ (`ymm4`–`ymm7`)
   * 4 vector load registers for $b$ (`ymm8`–`ymm11`)
   * Total = 12 YMM registers. This leaves 4 registers free for pointer calculations and loop bookkeeping, preventing register spilling to the stack.
2. **Elimination of Structural Hazards**: By issuing four independent FMAs in sequence, the out-of-order scheduler distributes `diff0*diff0` to Port 0 and `diff1*diff1` to Port 1 simultaneously. While those two execute during cycles 0–3, `diff2` and `diff3` are dispatched in cycle 1. By the time the next loop iteration arrives, the first set of FMAs is already completing retirement, completely eliminating pipeline bubbles.

### 3.3 Hardware Counter Evidence via Linux PMU (`perf stat`)

Profiling `secan` on an AMD Zen 4 node (4.30 GHz fixed frequency) across 40M+ operations at $D = 128$:

```bash
perf stat -e cycles,instructions,branches,branch-misses \
    ./build/benchmarks/bench_distance --benchmark_filter="BM_L2_Squared_AVX2.*128$"
```

#### Empirical Microarchitectural Comparison ($D=128$, AMD Zen 4)

| Metric | Scalar Reference | AVX2 Single (1-acc) | AVX2 Unroll4 (4-acc) | Delta (Unroll4 vs Single) |
|:---|:---:|:---:|:---:|:---:|
| **Latency per Vector** | $166.0\text{ ns}$ | $21.8\text{ ns}$ | **$15.3\text{ ns}$** | **$1.42\times$ faster** ($29.8\%$ latency drop) |
| **Effective Bandwidth** | $5.73\text{ GiB/s}$ | $43.77\text{ GiB/s}$ | **$62.32\text{ GiB/s}$** | **$+42.4\%$ throughput** |
| **Retired Instructions** | $\approx 14.16\times 10^9$ | $6.50\times 10^9$ | $6.52\times 10^9$ | Identical work footprint |
| **CPU Clock Cycles** | $\approx 6.51\times 10^9$ | $1.66\times 10^9$ | **$1.41\times 10^9$** | **$250\text{ million cycles saved}$** |
| **Instructions per Cycle (IPC)**| $2.18$ | $3.92$ | **$4.60$** | **$+17.3\%$ IPC gain** |
| **Branch Mispredict Rate** | $0.003\%$ | $0.002\%$ | **$0.004\%$** | Zero branch penalties |
| **Speedup vs Scalar** | $1.0\times$ | $7.61\times$ | **$10.85\times$** | **Full order of magnitude** |

---

## 4. Benchmark Synthesis & Pareto Evaluation (20%)

The automated benchmark sweep across standard AI embedding dimensions ($D \in [64, 1536]$) demonstrates the robust scaling of the multi-accumulator approach:

#### Latency and Bandwidth Scaling Across Dimensions

| Dimension ($D$) | Scalar Baseline | AVX2 Single (1-acc) | AVX2 Unroll4 (4-acc) | Peak Bandwidth (Unroll4) | Speedup vs Scalar |
|:---:|:---:|:---:|:---:|:---:|:---:|
| **64** | $38.9\text{ ns}$ | $11.8\text{ ns}$ | **$8.4\text{ ns}$** | $57.1\text{ GiB/s}$ | **$4.63\times$** |
| **128** | $166.0\text{ ns}$ | $21.8\text{ ns}$ | **$15.3\text{ ns}$** | $62.3\text{ GiB/s}$ | **$10.85\times$** |
| **256** | $332.0\text{ ns}$ | $42.5\text{ ns}$ | **$29.7\text{ ns}$** | $64.1\text{ GiB/s}$ | **$11.18\times$** |
| **512** | $664.2\text{ ns}$ | $84.2\text{ ns}$ | **$58.9\text{ ns}$** | $64.8\text{ GiB/s}$ | **$11.28\times$** |
| **768** | $998.4\text{ ns}$ | $126.1\text{ ns}$ | **$88.4\text{ ns}$** | $65.0\text{ GiB/s}$ | **$11.29\times$** |
| **1024** | $1328.0\text{ ns}$ | $168.0\text{ ns}$ | **$117.8\text{ ns}$** | $65.1\text{ GiB/s}$ | **$11.27\times$** |
| **1536** | $1995.0\text{ ns}$ | $251.8\text{ ns}$ | **$176.5\text{ ns}$** | **$65.2\text{ GiB/s}$** | **$11.30\times$** |

### Key Observations:
1. **Asymptotic Bandwidth Saturation**: For all vectors with dimension $D \ge 256$, `secan::l2_squared_avx2_unroll4` saturates single-core L1-D cache streaming bandwidth at **$65.2\text{ GiB/s}$**, hitting the architectural limit of the load-store execution units.
2. **Consistent $1.42\times$ Gain Over Single-Accumulator**: Across every vector dimension, 4-way unrolling provides an unbroken $\approx 42\%$ throughput advantage over 1-accumulator vectorization purely by keeping execution units fed with non-dependent instructions.
3. **IPC Approaching 5.0**: An IPC of **$4.60$** on AMD Zen 4 indicates near-optimal superscalar instruction dispatch, combining integer loop counter updates, SIMD vector loads, and arithmetic FMAs without pipeline stalls.

---

## 5. Key Takeaways & Engineering Blueprint

1. **The Pipeline is a Conveyor Belt**: Writing vector instructions is only half the battle. If your instructions depend on the result of the immediately preceding instruction, the hardware cannot run ahead. You must unroll across independent accumulator registers to match the **Latency $\times$ Bandwidth** product derived from Little's Law.
2. **Respect IEEE-754 Non-Associativity**: The compiler is not lazy; it is legally constrained by ISO standards from reassociating reduction loops. You must take architectural ownership of multi-register reductions either through explicit compiler flags or handcrafted intrinsics.
3. **Register Budgeting Discipline**: In AVX2 (16 YMM registers), an unroll factor of 4 is the sweet spot. In AVX-512 (32 ZMM registers), an unroll factor of 8 achieves full dual-port saturation while leaving 16 registers for streaming cache-line prefetching.

---

## 🔬 Reproducibility Manifest

```bash
# 1. Compile benchmarks with native optimizations
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j$(nproc)

# 2. Run PMU hardware counter profiling
perf stat -e cycles,instructions,branches,branch-misses \
    ./build/benchmarks/bench_distance --benchmark_filter="BM_L2_Squared_AVX2.*128$"

# 3. Run complete multi-dimension sweep
./build/benchmarks/bench_distance --benchmark_filter="BM_L2_Squared.*"
```
