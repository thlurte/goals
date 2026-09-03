# {Published Title}: {Subtitle}

| Metadata | Specification |
|:---|:---|
| **Month** | {N} — {Month YYYY} |
| **Status** | Working Manuscript |
| **Domain** | {e.g. Microarchitecture, Quantization, Out-of-Core Graph Systems, GPU Attention} |
| **Primary Benchmark Target** | {Target binary / dataset / hardware suite} |

---

## 1. Executive Abstract & Falsifiable Question
*One paragraph framing the computational systems problem, followed by a single falsifiable sentence.*

> **Core Falsifiable Question**:
> *[State the precise hypothesis: "At what parameter threshold does system A beat system B by X factor while maintaining Y recall under Z hardware constraints?"]*

---

## 2. Theoretical Hardware & Mathematical Model
*Construct the formal analytical model before reporting empirical numbers.*
1. **Mathematical Objective**: Formal equations in LaTeX.
2. **Silicon Hardware Bounds**:
   * Latency bound: $T_{\text{latency}} = \lceil D/V \rceil \times L_{\text{inst}}$.
   * Throughput bound: $T_{\text{throughput}} = \lceil D/V \rceil \times (1/R_{\text{units}})$.
   * Memory bandwidth bound: $T_{\text{memory}} = \text{Bytes} / \text{Bandwidth}$.
3. **Failure Boundary**: The theoretical point where the baseline breaks down.

---

## 3. Experimental Protocol & Silicon Hardware Matrix
*Reproducible specification.*

| Platform Component | Specification |
|:---|:---|
| **Primary Host CPU** | {e.g. Intel Core / Xeon Golden Cove, AVX2, AVX-512} |
| **Edge Hardware** | {e.g. NVIDIA Jetson Orin AGX, ARM Cortex-A78AE, NEON} |
| **GPU Accelerator** | {e.g. NVIDIA H100 / A100 / RTX 4090, CUDA 12.x} |
| **Compilation Suite** | `clang++ -O3 -march=native -DNDEBUG -ffast-math` |
| **Measurement Tools** | Google Benchmark v1.9.0, Linux `perf stat`, `perf c2c`, `nsys`, `ncu` |
| **Evaluated Datasets** | {e.g. SIFT1M (128-D), Deep10M (96-D), Dense Embeddings (768-D)} |

### Controlled Execution Protocol
1. Pin CPU frequencies / disable TurboBoost to ensure $<1\%$ run-to-run IPC variance.
2. Apply `benchmark::DoNotOptimize` and `benchmark::ClobberMemory` to prevent dead-code elimination.
3. Warm up caches with 1,000 discardable runs prior to recording steady-state measurements.

---

## 4. Controlled Parameter Sweeps & Empirical Results
*Include at least one structured benchmark table and figure reference.*

**Figure 1.** `{Caption explaining Pareto curve}` → `figures/pareto_frontier.png`

| Parameter Sweep | Baseline Latency | This Work (secan) | Speedup Factor | Hardware Counter Profile |
|:---|:---|:---|:---|:---|
| Sweep 1 | | | | |
| Sweep 2 | | | | |
| Sweep 3 | | | | |

---

## 5. Industrial & Academic Baseline Comparison
*Direct comparison against named, industry-standard systems under identical hardware constraints.*

| Production Engine | Mechanism / Algorithm | Measured QPS | P99 Latency | Recall@10 | Cost / Watt |
|:---|:---|:---|:---|:---|:---|
| **Industry Baseline A** | {e.g. Faiss IndexIVFPQ} | | | | |
| **Industry Baseline B** | {e.g. HNSWLib} | | | | |
| **This Work (secan)** | {Hardware-optimized kernel} | | | | |

---

## 6. Honest Limitations & Operational Boundaries
*A rigorous paragraph stating what the numbers do NOT claim.*
* Under what conditions does this optimization offer diminishing returns?
* What are the trade-offs in build complexity or memory footprint?

---

## 7. Open-Source Reproduction Commands
```bash
# Clone, configure, compile, and execute full verification suite
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j$(nproc)
./build/benchmarks/bench_{name} --benchmark_out=notes/raw_results.json
perf stat -e cycles,instructions,L1-dcache-load-misses ./build/benchmarks/bench_{name}
```
