# 🚀 Week 1 Detailed Execution Plan (Sep 1 – Sep 6, 2026)

> **Theme**: High-Dimensional Vector Geometry, Trigonometric Foundations, IR Ranking Metrics, and Scientific C++ Measurement.

---

## ⏰ Daily Operational Rhythm

```
┌──────────────────────────────┬────────────────────────────────────────────────────────────────────────┐
│ Time Block                   │ Focus Area                                                             │
├──────────────────────────────┼────────────────────────────────────────────────────────────────────────┤
│ **🌅 06:00 – 07:30 (90 min)**│ **Morning Pure Mathematics** (Pencil, paper, theorems & derivations)   │
│ **📖 07:30 – 08:30 (60 min)**│ **Systems & Architecture Deep Reading** (Hardware mechanics & theory)  │
│ **☀️ Daytime**               │ **Subconscious Incubation Period** (Diffuse thinking)                  │
│ **💻 20:30 – 23:00 (2.5 hrs)**│ **Night Hands-On Implementation** (Flow state coding & benchmarking)   │
└──────────────────────────────┴────────────────────────────────────────────────────────────────────────┘
```

---

## 📅 Day-by-Day Breakdown

---

### 🔹 Monday, Sep 1: Trigonometric Coordinates, Micro-Benchmarking & Google Benchmark

#### 🌅 06:00 – 07:30 | Pure Mathematics (90 min)
* **Book**: *Trigonometry* — I.M. Gelfand & Mark Saul
* **Chapters**: Chapter 1 (*Trigonometric Ratios in a Right Triangle*) & Chapter 2 (*Coordinates and Angles*)
* **Core Topics**:
  1. Transition from geometric triangle ratios to analytical coordinate functions on the unit circle $x^2 + y^2 = 1$.
  2. Radian measure definition: $\theta = s/r$, arc length, sector area.
  3. The wrapping function: mapping the real line $\mathbb{R}$ continuously onto the unit circle.
* **Pencil & Paper Problem Set**:
  - Prove that $\sin^2\theta + \cos^2\theta = 1$ directly from the Pythagorean theorem on coordinate axes.
  - Solve for exact values of $\sin$ and $\cos$ at $\pi/6, \pi/4, \pi/3, \pi/2$ without a calculator.

#### 📖 07:30 – 08:30 | Systems & Architecture Reading (60 min)
* **Book**: *The Art of Writing Efficient Programs* — Fedor G. Pikus
* **Chapter**: Chapter 2 (*Performance Measurements*)
* **Core Topics**:
  1. Why wall-clock time is noisy and non-deterministic on modern multi-core OSs.
  2. Profiler sampling vs instrumentation overhead.
  3. Compiler dead-code elimination traps in micro-benchmarks: why the compiler deletes unused loops.
  4. Memory clobbering and `benchmark::DoNotOptimize`.

#### 💻 20:30 – 23:00 | Hands-On Implementation (2.5 hrs)
* **Target**: `/home/ahmed/personal/secan`
* **Tasks**:
  1. **CMake Setup**: Integrate Google Benchmark via `FetchContent` in `CMakeLists.txt`.
  2. **Sanitizer Profiles**: Add explicit CMake flags for AddressSanitizer and UndefinedBehaviorSanitizer:
     ```cmake
     set(CMAKE_CXX_FLAGS_DEBUG "-fsanitize=address,undefined -g -O1")
     set(CMAKE_CXX_FLAGS_RELEASE "-O3 -march=native -DNDEBUG")
     ```
  3. **Benchmark Scaffold**: Create `benchmarks/bench_distance.cpp` measuring `l2_squared` across vector dimensions $D \in \{64, 128, 768, 1536\}$.
  4. **Validation**: Run `cmake --build build && ./build/benchmarks/bench_distance` and verify zero ASan errors.

#### ⛔ What NOT to Overspend Time On (Time Traps)
* ❌ **Do NOT** hand-write a custom benchmarking timer framework or CLI argument parser—use Google Benchmark directly.
* ❌ **Do NOT** start writing AVX2/AVX-512 SIMD intrinsics today—keep distance kernels in clean, naive scalar C++ to establish the unoptimized baseline.
* ❌ **Do NOT** spend hours proving exotic trigonometric identities in the morning—once the unit circle wrapping and fundamental identity $\sin^2\theta + \cos^2\theta = 1$ are clear, move on.

---

### 🔹 Tuesday, Sep 2: Periodic Symmetries, Compiler Limits & Binary Data Loaders

#### 🌅 06:00 – 07:30 | Pure Mathematics (90 min)
* **Book**: *Trigonometry* — I.M. Gelfand & Mark Saul
* **Chapter**: Chapter 3 (*Sine and Cosine Functions and Their Graphs*)
* **Core Topics**:
  1. Periodic symmetries: $\sin(\theta + 2\pi) = \sin\theta$, $\tan(\theta + \pi) = \tan\theta$.
  2. Parity properties: $\cos(-\theta) = \cos\theta$ (even function), $\sin(-\theta) = -\sin\theta$ (odd function).
  3. Geometric analysis of sign patterns across all 4 quadrants ($ASTC$ rule: All, Sine, Tangent, Cosine).
* **Pencil & Paper Problem Set**:
  - Sketch the transformation $f(x) = 3\cos(2x - \pi/2) + 1$, labeling amplitude, period, and phase shift.
  - Prove $\sin(\pi - \theta) = \sin\theta$ and $\cos(\pi - \theta) = -\cos\theta$.

#### 📖 07:30 – 08:30 | Systems & Architecture Reading (60 min)
* **Book**: *Computer Systems: A Programmer's Perspective* (CS:APP 3rd Ed.)
* **Sections**: §5.1–5.6 (*Optimizing Program Performance*)
* **Core Topics**:
  1. Compiler optimization limitations: why pointers cause memory aliasing and block auto-vectorization.
  2. Cycles Per Element (CPE) metric.
  3. Eliminating loop overhead and reducing procedure calls inside inner loops.

#### 💻 20:30 – 23:00 | Hands-On Implementation (2.5 hrs)
* **Target**: `/home/ahmed/personal/secan`
* **Tasks**:
  1. **Binary I/O Headers**: Create `include/secan/io/fvecs_reader.h` declaring:
     ```cpp
     struct VectorDataset {
         int num_vectors;
         int dimension;
         std::vector<float> data; // Contiguous row-major buffer
     };
     VectorDataset load_fvecs(const std::string& path);
     VectorDataset load_bvecs(const std::string& path);
     // Ground-truth neighbor IDs (SIFT *.ivecs)
     struct NeighborDataset {
         int num_queries;
         int k;
         std::vector<int> ids; // row-major [num_queries * k]
     };
     NeighborDataset load_ivecs(const std::string& path);
     ```
  2. **Zero-Copy Parser**: Implement `src/io/fvecs_reader.cpp` parsing `.fvecs` / `.bvecs` / `.ivecs`.
  3. **Unit Tests**: Create `tests/test_io.cpp` generating synthetic binary files, reading them back, asserting equality.
  4. **Dataset Acquisition**: Download SIFT1M base + ground-truth into `data/sift1m/` (full 1M OK; Wed metrics may use a subset).

#### ⛔ What NOT to Overspend Time On (Time Traps)
* ❌ **Do NOT** build complex memory-mapped (`mmap`) kernel paging logic yet—standard `std::ifstream::read` into a contiguous `std::vector<float>` is 100% fine for Week 1.
* ❌ **Do NOT** spend time downloading multi-gigabyte text datasets—stick strictly to SIFT1M.
* ❌ **Do NOT** get bogged down in graphing tricky trigonometric curves by hand—understand period, frequency, and phase shift, then move forward.

---

### 🔹 Wednesday, Sep 3: Limits & Continuity, Processor Pipelines & IR Analytics

#### 🌅 06:00 – 07:30 | Pure Mathematics (90 min)
* **Book**: *Calculus* — Gilbert Strang (MIT OpenCourseWare)
* **Chapter**: Chapter 1 (*Introduction to Calculus & Limits*, §1.1–1.5)
* **Core Topics**:
  1. The intuitive concept of a limit: $\lim_{x \to c} f(x) = L$.
  2. Formal $\epsilon$-$\delta$ definition of a limit: $\forall \epsilon > 0, \exists \delta > 0 \text{ s.t. } 0 < |x - c| < \delta \implies |f(x) - L| < \epsilon$.
  3. Continuity of functions, limit laws (sum, product, quotient), and the Intermediate Value Theorem.
* **Pencil & Paper Problem Set**:
  - Prove using $\epsilon$-$\delta$ that $\lim_{x \to 3} (2x + 1) = 7$.
  - Evaluate the indeterminate limit $\lim_{x \to 0} \frac{\sqrt{1+x} - 1}{x}$ algebraically without L'Hôpital.

#### 📖 07:30 – 08:30 | Systems & Architecture Reading (60 min)
* **Book**: *Computer Systems: A Programmer's Perspective* (CS:APP 3rd Ed.)
* **Section**: §5.7 (*Understanding Modern Superscalar Processors*)
* **Core Topics**:
  1. Instruction-Level Parallelism (ILP): Instruction Control Unit (ICU) vs Execution Unit (EU).
  2. Out-of-order execution, branch prediction, and speculative execution.
  3. Functional units, execution ports, latency vs issue time of floating-point addition/multiplication.

#### 💻 20:30 – 23:00 | Hands-On Implementation (2.5 hrs)
* **Target**: `/home/ahmed/personal/secan`
* **Tasks**:
  1. **IR Evaluation Module**: Create `tests/test_ir_metrics.cpp` implementing:
     * Discounted Cumulative Gain: $\text{DCG}@K = \sum_{i=1}^K \frac{2^{rel_i} - 1}{\log_2(i + 1)}$
     * Ideal DCG ($\text{IDCG}@K$) and Normalized DCG ($\text{NDCG}@K = \frac{\text{DCG}@K}{\text{IDCG}@K}$)
     * Mean Reciprocal Rank: $\text{MRR} = \frac{1}{|Q|} \sum_{q} \frac{1}{\text{rank}_q}$
     * Mean Average Precision: $\text{MAP} = \frac{1}{|Q|} \sum_{q} \text{AP}(q)$
  2. **Ground Truth Validation**: Run exact scalar `linear_scan` on a **SIFT subset** first (e.g. 100K base / 1K queries); verify Recall@10 = 1.0, NDCG@10 = 1.0, MAP sanity checks. Full SIFT1M scan = stretch / weekend.

#### ⛔ What NOT to Overspend Time On (Time Traps)
* ❌ **Do NOT** run the exact scan over all 1,000,000 vectors $\times$ 10,000 queries tonight if it takes $>60$ seconds on scalar code—validate Recall@10 = 1.0 on a 100K slice.
* ❌ **Do NOT** spend hours struggling with pathological $\epsilon$-$\delta$ proofs for non-linear functions—prove 1 linear limit to master the definition, then move to limit algebra.
* ❌ **Do NOT** build a custom sorting network for top-$k$ yet—standard `std::priority_queue` or `std::partial_sort` is completely sufficient.

---

### 🔹 Thursday, Sep 4: The Derivative, Port Mapping & Inner-Product Kernel

#### 🌅 06:00 – 07:30 | Pure Mathematics (90 min)
* **Book**: *Calculus* — Gilbert Strang
* **Chapter**: Chapter 2 (*The Derivative*, §2.1–2.3)
* **Core Topics**:
  1. The derivative from first principles: secant line slope $\to$ instantaneous tangent slope:
     $$f'(x) = \lim_{h \to 0} \frac{f(x+h) - f(x)}{h}$$
  2. Differentiability implies continuity (proof).
  3. Proof of the Power Rule: $\frac{d}{dx} x^n = n x^{n-1}$ for positive integers via binomial expansion.
* **Pencil & Paper Problem Set**:
  - Differentiate $f(x) = \frac{1}{x^2}$ directly from the limit definition.
  - Prove that $f(x) = |x|$ is continuous at $x=0$ but not differentiable.

#### 📖 07:30 – 08:30 | Systems & Architecture Reading (60 min)
* **Book**: *Optimizing Software in C++* — Agner Fog
* **Chapters**: Chapter 3 (*Finding Bottlenecks*) & Chapter 7.1–7.3 (*Floating-Point Efficiency*)
* **Core Topics**:
  1. CPU clock cycles vs instruction throughput.
  2. Floating-point division and square root latency ($10\times–15\times$ slower than multiplication).
  3. Port distribution of arithmetic instructions on modern Intel/AMD architectures.

#### 💻 20:30 – 23:00 | Hands-On Implementation (2.5 hrs)
* **Target**: `/home/ahmed/personal/secan`
* **Tasks**:
  1. First-class **`ip()`** (inner product) next to `l2_squared`. Distance enum: L2 / IP / cosine.
  2. Same Google Benchmark harness: $D \in \{64, 128, 768, 1536\}$.
  3. Unit tests: IP vs naive loop; cosine via IP + norms.

#### ⛔ What NOT to Overspend Time On (Time Traps)
* ❌ **Do NOT** touch Deep Learning / PyTorch tonight—DL is strictly reserved for Saturday afternoon (14:00–18:00).
* ❌ **Do NOT** try to implement Fast Inverse Square Root (`Q_rsqrt`) hacks—use `std::sqrt` in standard C++20 for scalar cosine baseline.
* ❌ **Do NOT** optimize compiler flags beyond `-O3 -march=native -DNDEBUG`.

---

### 🔹 Friday, Sep 5: Differentiation Rules, `perf stat` Profiling & Baseline Benchmark

#### 🌅 06:00 – 07:30 | Pure Mathematics (90 min)
* **Book**: *Calculus* — Gilbert Strang
* **Chapter**: Chapter 2 (*Rules of Differentiation*, §2.4–2.5)
* **Core Topics**:
  1. Product Rule proof: $\frac{d}{dx}[u(x)v(x)] = u'(x)v(x) + u(x)v'(x)$.
  2. Quotient Rule proof: $\frac{d}{dx}\left[\frac{u(x)}{v(x)}\right] = \frac{u'(x)v(x) - u(x)v'(x)}{[v(x)]^2}$.
  3. Differentiation of trigonometric functions from first principles:
     $$\lim_{h \to 0} \frac{\sin(x+h) - \sin(x)}{h} = \cos(x) \quad \text{using } \lim_{\theta \to 0} \frac{\sin\theta}{\theta} = 1$$
* **Pencil & Paper Problem Set**:
  - Differentiate $f(x) = x^3 \sin(x) \cos(x)$ using product rule.
  - Derive the derivative of $\tan(x)$ and $\sec(x)$ from quotient rules.

#### 📖 07:30 – 08:30 | Systems & Architecture Reading (60 min)
* **Book**: *The Art of Writing Efficient Programs* — Fedor G. Pikus & CS:APP §5.14
* **Core Topics**:
  1. Using Linux `perf stat` to inspect hardware performance counters.
  2. Instructions Per Cycle (IPC), branch miss rate, L1/L2 cache misses.
  3. Establishing the empirical performance baseline before optimization.

#### 💻 20:30 – 23:00 | Hands-On Implementation (2.5 hrs)
* **Target**: `/home/ahmed/personal/secan`
* **Tasks**:
  1. **Hardware Counter Profiling**: Run `perf stat` on the scalar SIFT1M linear scan:
     ```bash
     perf stat -e task-clock,cycles,instructions,branches,branch-misses,L1-dcache-load-misses ./build/benchmarks/bench_distance
     ```
  2. **Baseline Audit**: Record IPC (typically $\approx 1.0–1.2$ for naive scalar loops), throughput (QPS), and latency ($p50, p95, p99$).
  3. **Documentation**: Update `secan/README.md` with the baseline performance table to compare against future SIMD AVX2 and IVF optimizations.

#### ⛔ What NOT to Overspend Time On (Time Traps)
* ❌ **Do NOT** attempt to analyze 50 different hardware perf events—focus strictly on `cycles`, `instructions` (IPC), and `L1-dcache-load-misses`.
* ❌ **Do NOT** worry if your baseline IPC is low (~1.0)—that is expected and proves the dependency chain bottleneck before Week 2 SIMD unrolling.
* ❌ **Do NOT** start writing the Saturday essay early on Friday night—get proper rest for the Saturday 09:00 writing session.

---

### 🔹 Saturday, Sep 6: Long-Form Technical Essay 1 & Deep Learning from Scratch

#### ✍️ 09:00 – 13:00 | Technical Essay Writing
* **Title**: *"The Geometry of High-Dimensional Retrieval: From Trigonometric Coordinates and NDCG to CPU Performance Counters"*
* **Deliverable**: Save to `~/personal/goals/essays/essay_01_geometry_and_measurement.md`
* **Structure (5-Part Standard)**:
  1. **Mathematical Foundation**: Trigonometric coordinates on the unit circle, Cauchy-Schwarz inequality, and mathematical formulation of NDCG@K / MRR / MAP.
  2. **The Naive Bottleneck**: Why naive scalar loops hit CPU instruction dependency stalls and suffer low IPC ($1.1$).
  3. **The Engine Architecture**: Setting up Google Benchmark with `DoNotOptimize`, zero-copy `.fvecs`/`.ivecs` parsing, and AddressSanitizer safety.
  4. **Empirical Benchmarks**: `perf stat` performance counter tables on SIFT subset / SIFT1M (cycles, instructions, cache misses).
  5. **Key Takeaway**: Why measurement must always precede optimization in high-performance AI systems.

#### 🧠 14:00 – 18:00 | DL Weekend Track
* `uv init transformers-pytorch`; `uv add torch pytest`
* Implement `scaled_dot_product_attention` + causal mask tests (`tests/test_attention.py`)
* Verify numerically against `torch.nn.functional.scaled_dot_product_attention`.

#### ⛔ Saturday Time Traps
* ❌ **Do NOT** spend more than 4 hours on the essay—ship it at 13:00 sharp.
* ❌ **Do NOT** pull in Hugging Face `transformers` models yet—implement SDPA purely in raw PyTorch tensors.

---

### 🔹 Sunday, Sep 7: Reflection, Rest & Research Kickoff
* Review notes; solve remaining calculus problems.
* **Research**: create `research/2026-09-measurement-protocol/` and draft the one-sentence question + first benchmark table stub (see [`research/README.md`](../../research/README.md)).
* Rest before Week 2 — see [Month 1 weeks](../weeks/month-01-sep.md).
