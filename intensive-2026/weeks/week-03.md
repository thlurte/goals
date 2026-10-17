# Week 3: SIMD Intrinsics, Instruction-Level Parallelism & FastScan
> **Dates**: November 2 – November 8, 2026  
> **Core Focus**: AVX2 / AVX-512 FMA unrolling, shuffle reductions, masked tails, and **In-Register LUT Distance (FastScan via `vpshufb`)**.

---

### Day 15 (Mon, Nov 2): AVX2 Foundations & FMA Dot Product
- 📖 **Reading**: **[AgnerFog]** (`goals/agner_cpp.pdf`) — **§12 & §13** (pp. 95–130). Vector programming, SIMD alignment, and port saturation.
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

### Day 19 (Fri, Nov 6): AVX2 `vpshufb` In-Register LUT (FastScan Core)
- 📖 **Reading**: **FastScan Architecture** (FAISS FastScan & Muła/Lemire SIMD lookup tables).
- 💻 **Drills (`day_19_drills.md`)**:
  1. `drill_19a_pshufb_lut_lookup.cpp`: Use `_mm256_shuffle_epi8` (`vpshufb`) as a parallel 16-entry byte lookup table. Feed a 16-byte table in YMM register and look up 32 4-bit indices simultaneously in a single CPU cycle.
  2. `drill_19b_nibble_extraction.cpp`: Given a 32-byte block of 4-bit packed codes, unpack low and high nibbles using `_mm256_and_si256` and `_mm256_srli_epi16`.
  3. `drill_19c_pshufb_lut_distance.cpp`: Implement a miniature FastScan kernel: 16 centroids preloaded in `__m256i`, lookup 32 distances simultaneously, accumulate in 16-bit integers with `_mm256_maddubs_epi16`.
- 🛠️ **`secan`**: Scaffold `secan/include/secan/simd/fastscan.hpp`.

---

### Day 20 (Sat, Nov 7): Binary Vector Distance & Vectorized Popcount
- 📖 **Reading**: **[Hacker's Delight]** (Henry S. Warren) — **Chapter 5** (Counting Bits, pp. 81–110).
- 💻 **Drills (`day_20_drills.md`)**:
  1. `drill_20a_hamming_builtin.cpp`: Hamming distance using `__builtin_popcountll` on 64-bit unsigned integers.
  2. `drill_20b_avx2_hamming_popcnt.cpp`: AVX2 Hamming distance using `_mm256_xor_si256` and Harley-Seal vector popcount algorithm.
  3. `drill_20c_one_to_many_batch.cpp`: Implement 1-to-4 batch kernel: query vector loaded once and scored against 4 target candidate vectors.
- 🛠️ **`secan`**: Add binary quantization & 1-to-N batch distance routines.

---

### Day 21 (Sun, Nov 8): Timed SIMD Exam (No Notes)
- ⏱️ **45-minute timed coding exam**: Write an AVX2 L2 distance kernel with 4 accumulators AND a `vpshufb` 4-bit LUT lookup from scratch with zero compiler warnings.
