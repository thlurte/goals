# Microarchitectural Limits of Vector Distance Kernels: Execution Port Contention, Cache-Line Splits, and Measurement Artifacts on Modern x86

| | |
|:---|:---|
| **Month** | 1 — Sep 2026 |
| **Publish by** | Sun Sep 27, 2026 |
| **Folder** | `research/2026-09-measurement-protocol/` |
| **Primary artifact** | Google Benchmark + `perf stat` on scalar and SIMD distance kernels across $D \in [64, 1536]$ |
| **Status** | draft |
| **Template** | [`../_template.md`](../_template.md) |

Fill Sundays (09:00–13:00). Lab notes stay in `notes/`; do not paste essays here.

## 1. Question

At what embedding dimensions ($D \in [64, 1536]$) does vector distance throughput transition from execution-port latency bound (FMA pipeline dependency chains) to memory-bandwidth bound (L1/L2 cache load-port and line-split saturation), and does a noise-aware, dead-code-safe microbenchmark protocol reproduce within **5% IPC** across runs?

## 2. Method

| Item | Value |
|:---|:---|
| CPU | *(fill: model, AVX2/AVX-512, governors)* |
| `secan` commit | |
| Build | Debug: ASan/UBSan. Release: `-O3 -march=native -DNDEBUG` |
| Dataset | Synthetic dims $D \in \{64,128,768,1536\}$; SIFT1M subset for sanity, not as the kernel bench |
| Metrics | Google Benchmark (ns/op, items/s); `perf stat` IPC, L1-dcache-load-misses, branches |

### Protocol

1. Pin frequency / disable turbo if claiming IPC comparisons *(document if not)*.
2. `benchmark::DoNotOptimize` + `ClobberMemory` on inputs/outputs; compile with and without to show the DCE trap.
3. Report median of ≥5 Google Benchmark runs; discard first warmup.
4. Same binary for `perf stat -e task-clock,cycles,instructions,branches,branch-misses,L1-dcache-load-misses`.
5. Publish CPU model, compiler, flags, and commit in §7.

## 3. Experiments

| ID | Setup | What you measure |
|:---|:---|:---|
| E1 | Scalar `l2_squared`, `ip`, cosine; $D$ sweep | ns/op vs $D$; IPC |
| E2 | With vs without `DoNotOptimize` | Did the compiler delete the loop? |
| E3 | Week 2+: AVX2 vs scalar (same $D$) | speedup; still use this protocol |

## 4. Results

**Figure 1.** IPC and ns/op vs dimension → `figures/dim-sweep.png`

| $D$ | Kernel | ns/op | IPC | L1-d miss |
|:---|:---|:---|:---|:---|
| 64 | l2_squared | | | |
| 128 | l2_squared | | | |
| 768 | l2_squared | | | |
| 1536 | l2_squared | | | |
| 768 | ip | | | |
| 768 | cosine | | | |

## 5. Baseline

| System | Metric | Notes |
|:---|:---|:---|
| **This work** | scalar kernels + protocol | |
| **Baseline** | naive loop without clobber / wall-clock only | show why it lies |

No Faiss required this month. Named baseline = **unprotected scalar** vs **protocol scalar**.

## 6. Limitations

Single CPU; not a search-quality paper (no Recall@k). SIFT1M full scan is optional. 5% IPC bar is same-machine, not cross-SKU.

## 7. Reproduce

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
./build/benchmarks/bench_distance
perf stat -e task-clock,cycles,instructions,branches,branch-misses,L1-dcache-load-misses \
  ./build/benchmarks/bench_distance
```
