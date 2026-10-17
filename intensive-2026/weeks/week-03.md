# Week 3: SIMD Intrinsics, Instruction-Level Parallelism & Vectorization
> **Dates**: November 2 – November 8, 2026  
> **Core Focus**: AVX2 & AVX-512 register sets, instruction latencies & throughputs, ILP accumulator unrolling, shuffle reductions, masked loads, and branchless popcount.

---

### Day 15 (Mon, Nov 2): AVX2 Foundations & FMA Dot Product
- 📖 **Reading**: **[AgnerFog]** (`goals/agner_cpp.pdf`) — **§12 & §13** (pp. 95–130). Vector programming, SIMD instruction sets, alignments, and loop-carried dependencies.
- 💻 **Drills (`day_15_drills.md`)**:
  1. `drill_15a_avx2_load_store.cpp`: Aligned vs unaligned loads (`_mm256_load_ps` vs `_mm256_loadu_ps`).
  2. `drill_15b_avx2_dot_product_basic.cpp`: AVX2 float dot product with single `__m256` accumulator.
  3. `drill_15c_horizontal_shuffle_reduction.cpp`: Fast 256-bit horizontal sum without slow `_mm_hadd_ps`, using `_mm256_extractf128_ps`, `_mm_movehdup_ps`, and `_mm_add_ss`.
- 🛠️ **`secan`**: Scaffold `secan/include/secan/simd/distance.hpp`.

---

### Day 16 (Tue, Nov 3): Accumulator Unrolling & Hiding Pipeline Latency
- 📖 **Reading**: **[ArtOfProg]** (Fedor Pikus) — **Chapter 6** (pp. 160–190). Compile-time vectorization and loop optimizations.
- 📖 **Reference**: **[AgnerFog Tables]** (`goals/agner_it.pdf`). Zen 4 / Skylake FMA latency = 4 cycles, reciprocal throughput = 0.5 cycles.
- 💻 **Drills (`day_16_drills.md`)**:
  1. `drill_16a_ilp_unroll_bench.cpp`: Implement 1-acc, 2-acc, and 4-acc unrolling for Squared Euclidean distance. Measure why 4 accumulators achieves ~1.6x–1.8x speedup.
  2. `drill_16b_assembly_inspection.cpp`: Inspect disassembly (`objdump -d` / `-S`) to verify GCC does not spill registers to the stack.
  3. `drill_16c_inner_product_unrolled.cpp`: Implement 4-accumulator unrolled Inner Product (`dot`) kernel.
- 🛠️ **`secan`**: Integrate 4-accumulator unrolled FP32 distance kernels into `secan`.

---

### Day 17 (Wed, Nov 4): Branch-Predictable SIMD Remainder Handling
- 📖 **Reading**: **[CS:APP]** — **§5.1 – §5.7** (pp. 531–558). Optimizing program performance, loop unrolling, and branch misprediction penalties.
- 💻 **Drills (`day_17_drills.md`)**:
  1. `drill_17a_simd_remainder_chunks.cpp`: Implement chunked remainder handling (`if (i + 16 <= dim)`, `if (i + 8 <= dim)`, scalar loop).
  2. `drill_17b_unaligned_dimensions_bench.cpp`: Benchmark performance on odd dimensions ($D=63, 127, 768, 775, 1536$).
  3. `drill_17c_cosine_delegation.cpp`: Implement Cosine distance delegating to unrolled Inner Product with vector norm normalization.
- 🛠️ **`secan`**: Handle non-multiple-of-8 vector dimensions cleanly without scalar performance drops.

---

### Day 18 (Thu, Nov 5): AVX-512 Masked Tail Reductions
- 📖 **Reading**: **[Intel Optimization Reference Manual]** / **[AgnerFog]** — AVX-512 masking, ZMM 512-bit registers, and folded reductions.
- 💻 **Drills (`day_18_drills.md`)**:
  1. `drill_18a_avx512_maskz_load.cpp`: Load arbitrary tail elements ($1..15$) using `_mm512_maskz_loadu_ps` with dynamic bitmask `(1u << remainder) - 1`.
  2. `drill_18b_avx512_folded_tail.cpp`: Fold masked tail computation directly into `acc3` via `_mm512_fmadd_ps` before a single `_mm512_reduce_add_ps`.
  3. `drill_18c_avx512_cpuid_dispatch.cpp`: Runtime CPUID check to dispatch dynamically between AVX2 and AVX-512 at engine startup.
- 🛠️ **`secan`**: Add dynamic CPU dispatching (`secan::simd::dispatch`).

---

### Day 19 (Fri, Nov 6): Binary Vector Distance & Vectorized Popcount
- 📖 **Reading**: **[Hacker's Delight]** (Henry S. Warren) — **Chapter 5** (Counting Bits, pp. 81–110).
- 💻 **Drills (`day_19_drills.md`)**:
  1. `drill_19a_hamming_builtin.cpp`: Hamming distance using `__builtin_popcountll` on 64-bit unsigned integers.
  2. `drill_19b_avx2_hamming_popcnt.cpp`: AVX2 Hamming distance using `_mm256_xor_si256` and vectorized popcount.
  3. `drill_19c_jaccard_distance.cpp`: Vectorized Jaccard similarity / distance ($1.0 - \frac{|A \cap B|}{|A \cup B|}$) on binary vectors.
- 🛠️ **`secan`**: Implement binary quantization distance metric in `secan`.

---

### Day 20 (Sat, Nov 7): One-to-Many Batch Distance Kernels
- 💻 **Drills (`day_20_drills.md`)**:
  1. `drill_20a_one_to_many_batch.cpp`: Implement 1-to-4 batch kernel: query vector is loaded once into registers and scored simultaneously against 4 target candidate vectors.
  2. `drill_20b_software_prefetching.cpp`: Experiment with `_mm_prefetch((const char*)(ptr), _MM_HINT_T0)` on future memory addresses. Measure L1 cache hit rate impact.
  3. `drill_20c_batch_speedup_bench.cpp`: Compare 1-by-1 distance loops vs 1-to-4 batched distance loops across 100,000 vectors.
- 🛠️ **`secan`**: Add 1-to-N batch distance routines for top-$k$ candidate scoring.

---

### Day 21 (Sun, Nov 8): Timed SIMD Exam (No Notes)
- ⏱️ **45-minute timed coding exam**: Write an AVX2 L2 distance kernel with 4 accumulators and fast shuffle reduction from a blank file with zero compiler warnings.
