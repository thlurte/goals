# 🤖 AGENTS.md — Mission, Operating Model & Engineering Context

> **To Any AI Agent / Pair Programmer Working with Ahmed**:  
> Read this document first. It establishes who the user is, the strict philosophical principles governing this repository, what has been built so far, and the exact roadmap for future execution. Do not deviate from these operating standards.

---

## 👤 1. The Engineer & The North Star

* **User**: Ahmed ([@thlurte](https://github.com/thlurte))
* **Background**: Self-taught, rigorous systems builder without a formal Computer Science degree.
* **The Mission**: A 28-week (7-month, September 2026 – March 2027) full-depth mastery of **Vector Search Engines, Low-Level Systems, Deep Learning from Scratch, High-Dimensional Mathematics, and GPU Silicon Engineering**.
* **Target Outcome (Early 2027)**: Positioning for core **AI Infrastructure, Vector Database Core, and GPU Kernel Engineering** roles (at engineering-driven scaleups like Qdrant, LanceDB, Fireworks.ai, Together AI, Modular, Baseten, Modal, etc.) through **irrefutable living proof-of-work** rather than resume credentials.

---

## 🛡️ 2. Core Philosophy: The Zero-Noise Doctrine

Ahmed has explicitly and aggressively purged all noise from this curriculum. Future agents **must strictly adhere** to these boundaries:

| ❌ What We Do NOT Do (Noise) | ✅ What We Focus On (Pure Signal) |
|:---|:---|
| **No Academic Paper Mills**: No artificial monthly paper deadlines, no LaTeX formatting chores, no preprints. | **Empirical Systems Benchmarking**: Machine-readable benchmark sweeps (`.json`/`.csv`), `perf stat` PMU counters, and cache-miss metrics. |
| **No REST / Web Boilerplate**: No FastAPI, microservices, or HTTP CRUD wrappers around engines. | **Bare-Metal Silicon Realities**: C++20 SIMD (AVX2, AVX-512, NEON), cache locality, memory bandwidth saturation, and CUDA/CUTLASS warp specialization. |
| **No Framework Hype / Black Boxes**: No blindly calling `import faiss` or high-level wrappers without understanding them. | **First-Principles Derivations**: Writing autograd from scratch (`micrograd`), manual `backward()` passes, and building vector indexing algorithms by hand. |
| **No Synthetic LeetCode Trivia**: No algorithmic puzzles divorced from hardware. | **Rigorous Graduate Foundations**: Gilbert Strang (Calc/Linear Algebra), Roman Vershynin (High-Dim Probability), Horn & Johnson (Matrix Analysis), Cover & Thomas (Information Theory). |

---

## ⏱️ 3. The Operating Cadence & Weekly Rhythm

Ahmed’s routine is carefully calibrated for deep work, sustainable progress, and zero burnout:

### Weekdays (Monday – Friday)
* **05:30 – 06:30 | Systems & Architecture Reading**: CS:APP (Bryant & O'Hallaron), Fedor Pikus (*Writing Efficient Programs*), Agner Fog.
* **06:30 – 08:30 | Morning Builder Track (5-Day Rhythm)**:
  * **Monday**: Hardware Profiling & Microbenchmarks (`secan` CPU PMU counters, IPC, cache lines, execution port contention).
  * **Tuesday**: Deep Learning Track — Part 1: Architecture & Tensor Shapes from scratch in Python/PyTorch.
  * **Wednesday**: Deep Learning Track — Part 2: Autograd, manual `backward()`, custom optimizers (`SGD`/`AdamW`), training loops, and ONNX parity exports.
  * **Thursday**: Systems Integration & Model Sweeps (`secan` + DL embeddings, Pareto curves Recall@10 vs QPS).
  * **Friday**: **Weekly Technical Systems Article (Drafting & Publishing)**: 28 long-form technical lab-notes (see [`curriculum/essays.md`](curriculum/essays.md)).
* **Daytime (09:00 – 18:00)**: Professional Workday (protected focus on day job; zero math/systems burnout).
* **18:00 – 19:30 | Reading Sanctuary**: Physical book reading for mental clarity, architectural taste, and philosophy (*Zen and the Art of Motorcycle Maintenance*, Penrose *The Road to Reality*, Bulgakov, Minsky).
* **20:30 – 23:00 | Night Hands-On Implementation**: C++20 / CUDA coding in [`secan`](file:///home/ahmed/personal/secan).

### Weekends (Saturday & Sunday)
* **09:00 – 13:00 | Pure Mathematics Deep Work**: Calculus, Linear Algebra, Multivariable, Probability, Spectral Graph Theory, and whiteboard proofs.
* **Afternoons & Evenings**: Protected Reading Sanctuary and mental decompression (zero night math, zero screen burnout).

---

## 📂 4. Active Codebases & Repositories

1. **`goals`** (`/home/ahmed/personal/goals`):
   * Master curriculum, 196 daily runbooks (`curriculum/days/month-0N/`), 28 weekly playbooks (`curriculum/weeks/`), monthly dashboards, and the 28 weekly essays portfolio (`curriculum/essays.md`).
2. **`secan`** (`/home/ahmed/personal/secan`):
   * High-performance vector search engine written in modern C++20 and CUDA.
   * Architecture: `secan_lib` (core search logic), Google Benchmark suite (`benchmarks/`), Catch2 test suite (`tests/`), and nanobind Python bindings.
   * 10 Planned Index Families: Exact SIMD (AVX2/AVX-512/NEON), IVF-Flat, SQ8/SQ4, PQ-ADC, FastScan, HNSW, ACORN Predicate Graph, GPU IVF, CAGRA Warp Search, and ColPali Multi-Vector MaxSim.
3. **`dl-track`** (`/home/ahmed/personal/dl-track`):
   * Deep Learning from first principles (`transformers-pytorch` initialized via `uv`).
   * Micrograd autograd engine, attention mechanisms (SDPA, GQA, RoPE, SwiGLU), custom optimizers from scratch, and ONNX runtime integration.
4. **`embed-runtimes`** (`/home/ahmed/personal/projects/embed-runtimes.md`):
   * Embedded vector runtime experiments (`limbed` + `ggmbed`).

---

## 🚀 5. Current Progress & Milestones Achieved (as of Sep 7, 2026)

* **Day 001 (Sat Sep 5)**: Completed Pure Math Block 1, Information Theory (Cover & Thomas Ch 1–2), Thought Leadership (George Pólya), and Reading Sanctuary (*Zen* Ch 1–4).
* **Day 002 (Sun Sep 6)**: Completed Pure Math Block 2 (Strang Calculus proofs & problem set), Penrose Sunday (*The Road to Reality* Ch 1).
* **Day 003 (Mon Sep 7)**:
  * Morning Systems Reading: Fedor Pikus Ch 2 (*Performance Measurements*, noise floor, DCE).
  * Curriculum Alignment: 100% purged all academic paper publishing deadlines, aligning the entire repo with the builder track and 28 weekly technical articles.
  * Reading Sanctuary: Reached 75% of *Zen and the Art of Motorcycle Maintenance* Chapter 7 (Classical vs Romantic understanding).
  * Night Hands-On (`secan`): Implemented modern CMake architecture with `FetchContent` Google Benchmark v1.9.0, dead-code safe benchmarking harness, and established initial scalar L2 distance baseline (558 ns for $D=768$, 1108 ns for $D=1536$).

---

## 🎯 6. Upcoming Implementation Sequence

1. **Immediate Next Steps (Month 1 — Sep 2026)**:
   * **Tomorrow (Tue Sep 8, Day 004)**:
     * 05:30: CS:APP §5.1–5.6 (CPE, memory aliasing, `__restrict__`).
     * 06:30: DL Track Part 1 kickoff: `uv init transformers-pytorch` → implement Scaled Dot-Product Attention (SDPA) with causal masking from scratch.
   * **Wednesday Sep 9 (Day 005)**:
     * DL Track Part 2: SDPA unit tests, edge-case masking, and numerical stability.
   * **Thursday Sep 10 (Day 006)**:
     * Implement Inner Product (`ip()`) and cosine distance metrics in `secan`.
   * **Friday Sep 11 (Day 007)**:
     * Draft and publish **Technical Article 01**: *"The Geometry of High-Dimensional Retrieval: Trigonometric Projections, NDCG Ranking, and Hardware Performance Counters"*.
   * **Weeks 2–4**:
     * AVX2 & AVX-512 SIMD vectorization (FMA execution port saturation, horizontal reduction tricks).
     * Binary `.fvecs`/`.bvecs` data loaders and SIFT1M exact scan validation.
     * Inverted File Index (IVF) with spherical k-means clustering.

2. **Months 2–4 (Quantization, Graphs & Disk Storage)**:
   * Scalar Quantization (SQ8/SQ4), Product Quantization (PQ-ADC, FastScan).
   * Flagship Implementation 1: **GAPQ** (Geometry-Aware Anisotropic Polar Quantization).
   * Hierarchical Navigable Small World (HNSW) graphs and DiskANN out-of-core streaming via Linux `io_uring`.

3. **Months 5–7 (GPU Silicon Specialization & Flagship Systems)**:
   * CUDA C++, shared memory bank conflicts, warp shuffle primitives (`__shfl_down_sync`), and cuBLAS/CUTLASS.
   * CAGRA GPU graph search and PagedAttention KV cache mechanics.
   * Flagship Implementation 2: **FlashMaxSim** (bare-metal CUTLASS kernel with TMA and warp specialization for multimodal ColPali retrieval).

---

## 🤝 7. Instructions for Future AI Agents

When interacting with Ahmed:
1. **Be Direct and Technically Rigorous**: Never talk down to him. Never use patronizing corporate speak. Speak in terms of cache lines, register allocation, compiler contracts, mathematical definitions, and profiling data.
2. **Never Re-introduce Noise**: Do not suggest building REST APIs, Docker web wrappers, writing papers for publication, or synthetic interview puzzles.
3. **Keep Code Production-Grade**:
   * Standard: Strict **C++20**.
   * Warnings: Clean under `-Wall -Wextra -Wpedantic -Wconversion`.
   * Efficiency: Zero heap allocations in inner search loops, cache-line aligned buffers, SIMD/vectorized layouts.
4. **Preserve Reading & Rest Buffers**: Never suggest cutting into Ahmed's Reading Sanctuary (evening) or recovery buffers. Long-term mastery requires intellectual freshness.
