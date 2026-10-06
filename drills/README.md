# 🥋 Daily C++ Systems & Performance Drills

Targeted, hands-on micro-drills designed to build instinctual C++ systems reflexes for:
- SIMD vectorization (AVX2/AVX-512 FMA)
- Cache-line locality & false-sharing prevention (`alignas(64)`)
- Zero-copy non-owning memory views (`std::span`)
- Bounded-heap priority queues & sorting complexity (`std::partial_sort`)
- Software prefetching & memory bandwidth optimization (`_mm_prefetch`)

---

## Week 02 (Sep 14 – Sep 18) — AVX2 & Memory Mechanics

| Drill | Title | Key C++ Systems Concepts | Status | File |
|:---:|:---|:---|:---:|:---|
| **10.1** | MXCSR FTZ/DAZ Modes | Denormals, microcode traps, `_MM_SET_FLUSH_ZERO_MODE` | ✅ | [`day010_drill_01_mxcsr_ftz_daz.cpp`](day010_drill_01_mxcsr_ftz_daz.cpp) |
| **10.2** | SIMD Load & FMA Operations | `_mm256_loadu_ps`, `_mm256_fmadd_ps`, 8-lane math | ✅ | [`day010_drill_02_simd_fma_load.cpp`](day010_drill_02_simd_fma_load.cpp) |
| **11.1** | Pointer Offset & Flat Indexing | Row-major layout `(i * D + j)`, pointer arithmetic | ✅ | [`day011_drill_01_pointer_offset.cpp`](day011_drill_01_pointer_offset.cpp) |
| **11.2** | Dual Accumulator Unrolling | Breaking dependency chains, ILP, FMA port saturation | ✅ | [`day011_drill_02_dual_accumulator.cpp`](day011_drill_02_dual_accumulator.cpp) |
| **11.3** | SIMD Chunk & Tail Loop | 8-float chunks, remainder scalar cleanup | ✅ | [`day011_drill_03_chunk_tail_loop.cpp`](day011_drill_03_chunk_tail_loop.cpp) |
| **11.4** | In-Place L2 Normalization | Unit vector scaling, epsilon guard | ✅ | [`day011_drill_04_normalize_inplace.cpp`](day011_drill_04_normalize_inplace.cpp) |
| **12.1** | Fused 1-Pass Cosine Distance | Computing dot product and norms in single loop | ✅ | [`day012_drill_01_fused_cosine.cpp`](day012_drill_01_fused_cosine.cpp) |
| **12.2** | Peak Single-Core GFLOPS | Calculating execution port saturation on Zen 4 | ✅ | [`day012_drill_02_peak_gflops.cpp`](day012_drill_02_peak_gflops.cpp) |
| **12.3** | Fused vs 2-Pass Memory Traffic | Halving memory bus load traffic (50% reduction) | ✅ | [`day012_drill_03_pass_comparison.cpp`](day012_drill_03_pass_comparison.cpp) |

---

## Week 04 (Sep 28 – Oct 02) — IVF, Multi-Probe & Cache Architecture

| Drill | Title | Key C++ Systems Concepts | File |
|:---:|:---|:---|:---|
| **24.1** | Cache Isolation (`alignas(64)`) | Preventing MESI false sharing in concurrent lists | [`day024_drill_01_cache_alignment.cpp`](day024_drill_01_cache_alignment.cpp) |
| **25.1** | Spherical $k$-Means Projection | Unit hypersphere projection for Cosine/MIPS | [`day025_drill_01_spherical_projection.cpp`](day025_drill_01_spherical_projection.cpp) |
| **26.1** | `std::partial_sort` Routing | $O(K \log P)$ centroid selection vs $O(K \log K)$ waste | [`day026_drill_01_partial_sort_routing.cpp`](day026_drill_01_partial_sort_routing.cpp) |
| **26.2** | Bounded Max-Heap Top-K | Zero-allocation streaming $O(N \log K)$ neighbor heap | [`day026_drill_02_bounded_heap.cpp`](day026_drill_02_bounded_heap.cpp) |
| **27.1** | Software Prefetching (`_mm_prefetch`) | L1/L2 cache preloading across 64-byte strides | [`day027_drill_01_cache_stride_prefetch.cpp`](day027_drill_01_cache_stride_prefetch.cpp) |
| **28.1** | C++20 `std::span` Zero-Alloc Views | Non-owning pointer+size views over arbitrary buffers | [`day028_drill_01_span_zero_alloc.cpp`](day028_drill_01_span_zero_alloc.cpp) |

---

## How to Compile & Run Any Drill

```bash
g++ -O3 -march=native -mavx2 -mfma -std=c++20 day026_drill_01_partial_sort_routing.cpp -o drill && ./drill
```

---

## 🔬 Benchmark Cross-Reference ([`cpu-performance-engineering`](file:///home/ahmed/personal/cpu-performance-engineering/misc/benchmarks))

For standalone, reproducible C benchmarks with committed raw hardware numbers and assembly listings:

| Drill Focus Area | Reference Benchmark | Systems Phenomenon |
| :--- | :--- | :--- |
| **Branchless Select & Routing** | [`02-branch-misprediction`](file:///home/ahmed/personal/cpu-performance-engineering/misc/benchmarks/02-branch-misprediction) | Branch misprediction penalty: sorted vs unsorted vs branchless paths. |
| **FMA Saturation & Throughput** | [`03-latency-vs-throughput`](file:///home/ahmed/personal/cpu-performance-engineering/misc/benchmarks/03-latency-vs-throughput) | Instruction latency vs reciprocal throughput on execution ports. |
| **Cache-Line Strides & Prefetch** | [`04-cache-latency`](file:///home/ahmed/personal/cpu-performance-engineering/misc/benchmarks/04-cache-latency) | Step changes in dependent load latencies across L1D, L2, L3, and DRAM. |
| **Arithmetic Intensity & Roofline**| [`06-roofline`](file:///home/ahmed/personal/cpu-performance-engineering/misc/benchmarks/06-roofline) | Empirical FLOPs/byte vs DRAM and cache bandwidth ceilings. |
| **SIMD Layouts (SoA vs AoS)** | [`07-aos-vs-soa-simd`](file:///home/ahmed/personal/cpu-performance-engineering/misc/benchmarks/07-aos-vs-soa-simd) | Contiguous SIMD loads vs strided gather overhead. |
| **Pointer Aliasing & Vectors** | [`08-autovectorization-aliasing`](file:///home/ahmed/personal/cpu-performance-engineering/misc/benchmarks/08-autovectorization-aliasing) | Compiler vectorization inhibitors and `__restrict__` semantics. |
| **Cache Isolation (`alignas(64)`)** | [`09-false-sharing`](file:///home/ahmed/personal/cpu-performance-engineering/misc/benchmarks/09-false-sharing) | Multithreaded throughput collapse from shared cache line invalidations. |
| **Memory Allocation & Placement** | [`10-first-touch`](file:///home/ahmed/personal/cpu-performance-engineering/misc/benchmarks/10-first-touch) | NUMA memory allocation policies under Linux. |
| **Dense GEMM & BLAS** | [`13-sgemm-naive-vs-blas`](file:///home/ahmed/personal/cpu-performance-engineering/misc/benchmarks/13-sgemm-naive-vs-blas) | Naive triple loops vs register-blocked and tiled BLAS kernels. |
| **Memory Bus Saturation** | [`15-stream-bandwidth`](file:///home/ahmed/personal/cpu-performance-engineering/misc/benchmarks/15-stream-bandwidth) | Sustained memory bandwidth under STREAM Triad and Scale kernels. |

