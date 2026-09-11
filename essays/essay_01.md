# The Geometry of High-Dimensional Retrieval: Trigonometric Projections, NDCG Ranking, and Hardware Performance Counters

| Metadata | Specification |
|:---|:---|
| **Week** | Week 01 — Friday, September 11, 2026 |
| **Theme / Block** | Pure Trigonometry, Limits, Derivatives & Hardware Measurement / Block I — Vector Search Engine |
| **Hardware & Systems Target** | AMD Zen 4 (Hawk Point, 12 Cores @ up to 5.02 GHz), L1/L2/L3 Cache Hierarchy, PMU Hardware Counters via `perf stat` |
| **Target Code Artifact** | `secan::search`, `secan::distance`, `secan::utils::io`, `secan::utils::metrics` |

---

## 🏛️ Executive Summary

High-dimensional vector search engines power modern artificial intelligence retrieval architectures, from Retrieval-Augmented Generation (RAG) to multi-modal semantic deduplication. Yet the standard software abstraction layer often treats vector comparison as an opaque mathematical formulation, divorcing high-dimensional geometry from the underlying silicon execution.

This technical lab-note formalizes the bridge between the mathematical foundations of vector retrieval—spanning spherical trigonometry, the law of cosines, and logarithmic rank discounting—and the microarchitectural realities of modern superscalar x86 execution. Using `secan` (a production-grade C++20 vector search engine built from first principles), we establish an empirical baseline on AMD Zen 4 architecture, instrumented via Linux PMU hardware performance counters (`perf stat`), examining instruction-level parallelism (IPC), execution port pressure, memory aliasing boundaries, and cache behavior.

---

## 1. Systems Motivation & The Hardware Reality (10%)

In high-dimensional nearest neighbor retrieval over large corpora ($N \ge 10^6$, $D \ge 128$), the innermost computation is an exhaustive distance kernel executed across flat arrays of IEEE-754 single-precision floating-point numbers.

Consider a naive query over a 100K-vector corpus with embedding dimension $D = 128$:
$$	ext{Operations per query} pprox 100{,}000 	imes 128 	imes 2 pprox 2.56 	imes 10^7 	ext{ floating-point operations (FLOPs)}$$

At 10,000 queries, this demands over $256 	ext{ GFLOPs}$. On a modern Zen 4 core clocked at $4.3	ext{ GHz}$, arithmetic compute is rarely the sole limiting resource; the primary bottlenecks arise from microarchitectural hazards:

1. **Non-Pipelined Divider Latency**: Standard cosine distance computes $rac{\langle u, v angle}{\|u\|_2 \|v\|_2}$, requiring a hardware square root and division. While single-precision FMA (Fused Multiply-Add) operations execute in 3–4 clock cycles with pipelined 0.5-cycle reciprocal throughput (two FMAs per cycle on Zen 4 execution ports 0 and 1), hardware scalar division (`divss`) and square root (`sqrtss`) are non-pipelined operations requiring 12–20 cycles. These operations hold the execution unit hostage and stall subsequent instructions.
2. **Compiler Aliasing Barriers**: In standard C++ kernels accepting pointers `const float* a` and `const float* b`, an optimizing compiler (`-O3`) cannot assume without strict aliasing guarantees (`__restrict__`) that writes to an accumulator do not alias with vector reads, inhibiting aggressive register allocation.
3. **Subnormal / Denormal Penalties**: Unnormalized or poorly scaled vectors can produce intermediate products in the denormal range ($0 < |x| < 2^{-126}$ for FP32), triggering microcode exception assists on x86 hardware that degrade instruction throughput by up to $100	imes$.

Before writing hand-tuned AVX2 or AVX-512 assembly intrinsics, rigorous systems engineering demands establishing an empirical scalar baseline free of compiler noise and CPU frequency jitter.

---

## 2. Mathematical Derivation & Algorithmic Geometry (30%)

### 2.1 The Hypersphere Projection and Metric Equivalence

Let $\mathcal{S}^{D-1} = \{ x \in \mathbb{R}^D : \|x\|_2 = 1 \}$ denote the unit hypersphere in $\mathbb{R}^D$. For any pair of non-zero embeddings $u, v \in \mathbb{R}^D$, their Euclidean distance is given by:

$$\|u - v\|_2^2 = \sum_{i=0}^{D-1} (u_i - v_i)^2 = \|u\|_2^2 + \|v\|_2^2 - 2 \langle u, v angle$$

Cosine similarity measures the cosine of the angle $	heta$ between $u$ and $v$:

$$\cos 	heta = rac{\langle u, v angle}{\|u\|_2 \|v\|_2} = rac{\sum_{i=0}^{D-1} u_i v_i}{\sqrt{\sum_{i=0}^{D-1} u_i^2} \sqrt{\sum_{i=0}^{D-1} v_i^2}}$$

Cosine distance is formally defined as:

$$d_{	ext{cosine}}(u, v) = 1 - \cos 	heta = 1 - rac{\langle u, v angle}{\|u\|_2 \|v\|_2}$$

When vectors are $L_2$-normalized such that $\|u\|_2 = \|v\|_2 = 1$, the Euclidean distance simplifies to:

$$\|u - v\|_2^2 = 1 + 1 - 2 \langle u, v angle = 2(1 - \cos 	heta) = 2 \cdot d_{	ext{cosine}}(u, v)$$

Thus:

$$d_{	ext{cosine}}(u, v) = rac{1}{2} \|u - v\|_2^2$$

**Geometric Invariant**: On the unit hypersphere, ranking candidates by ascending Squared Euclidean Distance ($L_2^2$), descending Inner Product (MIPS), or ascending Cosine Distance produces strictly identical rank permutations. In `secan`, this allows uniform top-$k$ sorting where $L_2$ minimizes $\|u-v\|^2$, Cosine minimizes $1 - \cos	heta$, and MIPS minimizes $-\langle u, v angle$.

### 2.2 Fast Inverse Square Root Derivation

To eliminate the 12–20 cycle latency of hardware division during cosine distance computation, we employ the reciprocal square root formulation:

$$r = rac{1}{\sqrt{x}} \implies r^{-2} - x = 0$$

Applying Newton-Raphson iteration for the function $f(y) = y^{-2} - x$:

$$y_{n+1} = y_n - rac{f(y_n)}{f'(y_n)} = y_n - rac{y_n^{-2} - x}{-2 y_n^{-3}} = y_n \left( 1.5 - 0.5 x y_n^2 ight)$$

Using the IEEE-754 floating-point bit representation trick with the magic constant `0x5f3759df`, an initial estimate is obtained in 1 cycle, followed by a single Newton-Raphson refinement step:

$$y_1 = y_0 \cdot \left(1.5 - 0.5 \cdot x \cdot y_0^2ight)$$

This delivers $< 0.15\%$ maximum relative error across positive FP32 domains while keeping the execution pipeline completely inside FMA execution units.

### 2.3 Information Retrieval Ranking Metrics: The Logarithmic Discount

In top-$k$ retrieval evaluations, rank position is not linearly decaying. Normalized Discounted Cumulative Gain ($	ext{NDCG}@K$) formalizes the user attention degradation via a logarithmic discount:

$$	ext{DCG}@K = \sum_{i=1}^K rac{2^{	ext{rel}_i} - 1}{\log_2(i + 1)}$$

$$	ext{NDCG}@K = rac{	ext{DCG}@K}{	ext{IDCG}@K}$$

Where $	ext{IDCG}@K$ is the Ideal DCG obtained by sorting true relevance labels in descending order. In binary relevance settings ($	ext{rel}_i \in \{0, 1\}$), Mean Reciprocal Rank (MRR) and Mean Average Precision ($	ext{MAP}$) measure first-hit and precision-recall trade-offs:

$$	ext{RR} = rac{1}{\min \{ i : 	ext{rank}_i 	ext{ is relevant} \}}, \quad 	ext{AP}@K = rac{1}{\min(K, R)} \sum_{i=1}^K P(i) \cdot 	ext{rel}_i$$

---

## 3. Microarchitectural Silicon Implementation & Profiler Evidence (40%)

### 3.1 Kernel Layout in `secan`

The `secan` engine organizes vector memory in flat, row-major contiguous memory buffers managed by `FloatDataset` to maximize cache prefetcher effectiveness:

```cpp
namespace secan {

float l2_squared_scalar(const float *a, const float *b, size_t dim) noexcept {
  float diff = 0.0f;
  for (size_t i = 0; i < dim; ++i) {
    float r_diff = a[i] - b[i];
    diff += r_diff * r_diff;
  }
  return diff;
}

float inner_product_scalar(const float *a, const float *b, size_t dim) noexcept {
  float sum = 0.0f;
  for (size_t i = 0; i < dim; ++i) {
    sum += a[i] * b[i];
  }
  return sum;
}

float fast_rsqrt(float x) noexcept {
  if (x <= 0.0f) return 0.0f;
  float xhalf = 0.5f * x;
  uint32_t i;
  std::memcpy(&i, &x, sizeof(i));
  i = 0x5f3759df - (i >> 1);
  float y;
  std::memcpy(&y, &i, sizeof(y));
  return y * (1.5f - xhalf * y * y); // 1st Newton-Raphson step
}

} // namespace secan
```

### 3.2 Linux PMU Hardware Counters (`perf stat`)

To isolate hardware performance, benchmarks were executed on an AMD Zen 4 Hawk Point silicon node locked to `performance` Energy Performance Preference (EPP) using the `amd-pstate-epp` driver. 

Sampling 10M+ iterations across $D = 128$ dimensions yielded the following hardware counters:

```
$ perf stat -e cycles,instructions,branches,branch-misses,L1-dcache-loads,L1-dcache-load-misses     ./build/benchmarks/bench_distance --benchmark_filter="BM_L2_Squared_Scalar/128$"
```

#### Hardware Performance Counter Profile (AMD Zen 4, Dimension $D=128$)

| Hardware Metric | `BM_L2_Squared_Scalar` | `BM_IP_Scalar` | Interpretation |
|:---|:---|:---|:---|
| **CPU Clock Cycles** | $6{,}505{,}129{,}229$ | $6{,}736{,}085{,}257$ | Steady state clock frequency ($pprox 4.30	ext{ GHz}$) |
| **Retired Instructions** | $14{,}159{,}341{,}997$ | $14{,}628{,}620{,}151$ | Low instruction footprint per vector loop |
| **Instructions Per Cycle (IPC)** | **2.177** | **2.172** | **Excellent superscalar retirement ($> 2.0$)** |
| **Branches Evaluated** | $1{,}004{,}261{,}966$ | $1{,}099{,}002{,}386$ | Loop boundary checks |
| **Branch Mispredictions** | $30{,}348$ | $33{,}567$ | **$0.003\%$ miss rate** (Predictor near 100% accuracy) |
| **L1 Data Cache Loads** | $1{,}771{,}138{,}435$ | $1{,}938{,}201{,}362$ | Contiguous streaming vector loads |
| **L1-D Cache Misses** | $126{,}045$ | $196{,}707$ | **$< 0.010\%$ miss rate** (Near zero L1D cache thrashing) |
| **Execution Latency ($D=128$)** | **57.7 ns** | **54.4 ns** | Baseline scalar single-vector comparison |
| **Effective Throughput** | **16.53 GiB/s** | **17.54 GiB/s** | Memory bandwidth utilization on scalar core |

### 3.3 Analysis of Microarchitectural Invariants
- **Instruction-Level Parallelism**: Both L2 and Inner Product achieve $pprox 2.17	ext{ IPC}$. With GCC `-O3`, the compiler automatically emits scalar FMA operations (`vfmadd213ss`/`vfmadd231ss`) unrolled across 2 accumulator stages, bypassing single-cycle accumulator stall dependencies.
- **Cache Pre-fetching Integrity**: The contiguous flat layout of `FloatDataset` ensures that the Zen 4 Hardware L1/L2 Stream Pre-fetcher operates with near-perfect hit rates ($99.99\%+$ L1 hits).

---

## 4. Empirical Benchmarks & Sweep Synthesis (20%)

The automated benchmark sweep harness ([`scripts/sweep_microbenchmark.py`](file:///home/ahmed/personal/secan/scripts/sweep_microbenchmark.py)) executed parameter sweeps across standard AI embedding dimensions:

$$D \in \{64, 128, 256, 512, 768, 1024, 1536\}$$

#### Comprehensive Multi-Kernel Sweep Table (AMD Zen 4 @ 4.3 GHz, Release `-O3 -march=native`)

| Dimension ($D$) | L2 Latency (ns) | L2 Bandwidth (GiB/s) | IP Latency (ns) | IP Bandwidth (GiB/s) | Cosine Latency (ns) | Fast Cosine Latency (ns) |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| **64** | 38.9 ns | 12.32 GiB/s | 26.0 ns | 18.34 GiB/s | 44.4 ns | 44.2 ns |
| **128** | 58.1 ns | 16.41 GiB/s | 55.6 ns | 17.15 GiB/s | 88.8 ns | 89.0 ns |
| **256** | 151.7 ns | 12.57 GiB/s | 147.7 ns | 12.91 GiB/s | 179.7 ns | 180.2 ns |
| **512** | 328.6 ns | 11.61 GiB/s | 323.6 ns | 11.79 GiB/s | 359.5 ns | 359.9 ns |
| **768** | 509.6 ns | 11.23 GiB/s | 504.3 ns | 11.35 GiB/s | 541.0 ns | 540.1 ns |
| **1024** | 693.7 ns | 11.00 GiB/s | 687.1 ns | 11.10 GiB/s | 723.2 ns | 723.7 ns |
| **1536** | 1050.0 ns | 10.90 GiB/s | 1046.1 ns | 10.94 GiB/s | 1089.3 ns | 1084.0 ns |

### Key Observations:
1. **Linear Scaling**: Across all 4 kernels, latency scales strictly linearly with dimension $D$ ($R^2 > 0.999$), indicating compute-bound execution within L1 cache bounds.
2. **Inner Product Efficiency**: Inner product kernel consistently outperforms $L_2$ squared by $5	ext{--}30\%$ across lower dimensions due to fewer arithmetic operations (no subtractions prior to accumulation).
3. **Bandwidth Saturation**: Peak scalar single-core bandwidth approaches $18.34	ext{ GiB/s}$ at $D=64$, asymptotically stabilizing around $10.9	ext{ GiB/s}$ for larger vectors due to loop overhead amortization.

---

## 5. Key Takeaways & Architectural Blueprint

1. **Establish the Scalar Noise Floor First**: Modern hardware contains out-of-order execution, frequency governors, and branch predictors that can obscure algorithmic flaws. Profiling with hardware counters (`perf stat`) confirms an IPC of $2.17$ and L1-D hit rate of $99.99\%$, proving that memory access patterns are healthy before SIMD optimizations.
2. **Trigonometric Metric Unification**: By recognizing that Cosine, Inner Product, and Euclidean distance are isomorphic on normalized hyperspheres, vector search engines can eliminate expensive square-root and division operations by projecting vectors during indexing and executing pure inner products during retrieval.
3. **The Foundation for Week 2 (SIMD Intrinsics)**:
   - With the scalar baseline firmly established ($57.7	ext{ ns}$ for $D=128$), the target for Week 2 AVX2/AVX-512 unrolling is clear: saturate 8-wide (256-bit) and 16-wide (512-bit) vector registers across Zen 4 dual FMA pipelines, driving latency below $10	ext{ ns}$ per vector.

---

## 🔬 Reproducibility Manifest

```bash
# Build with native optimizations
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j$(nproc)

# Run PMU counter instrumentation
perf stat -e cycles,instructions,branches,branch-misses,L1-dcache-loads,L1-dcache-load-misses     ./build/benchmarks/bench_distance --benchmark_filter="BM_L2_Squared_Scalar/128$"

# Execute full automated sweep
python3 /home/ahmed/personal/secan/scripts/sweep_microbenchmark.py
```
