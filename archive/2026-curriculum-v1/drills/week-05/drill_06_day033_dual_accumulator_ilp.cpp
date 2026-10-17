// ==============================================================================
// 🥋 Drill 06 (Day 33.3): CS:APP §5.1–5.12 — ILP & Dual Accumulator Unrolling
//
// 📖 READING SOURCES:
// - Bryant & O'Hallaron: Computer Systems (CS:APP 3rd Ed, §5.1–5.12)
//
// 🎯 CORE LESSON:
// 1. FMA Port Latency (4 cycles) vs Throughput (0.5 cycles):
//    A single accumulator `acc = _mm256_fmadd_ps(..., acc)` forces a 4-cycle
//    stall per iteration.
// 2. Dual Accumulators (`acc0`, `acc1`) break loop-carried dependency chains,
//    allowing out-of-order execution units to issue FMAs back-to-back.
//
// 🚀 RUN COMMAND:
// g++ -O3 -march=native -mavx2 -mfma -std=c++20 -Wall -Wextra
// drill_06_day033_dual_accumulator_ilp.cpp -o drill06 && ./drill06
// ==============================================================================

#include <cassert>
#include <immintrin.h>
#include <iostream>
#include <vector>

// TODO 1: Implement 2-way unrolled AVX2 FMA dot product
// 1. Initialize `__m256 acc0 = _mm256_setzero_ps();` and `__m256 acc1 =
// _mm256_setzero_ps();`
// 2. Loop in steps of 16 floats (i + 16 <= dim):
//    acc0 = _mm256_fmadd_ps(va0, vb0, acc0);
//    acc1 = _mm256_fmadd_ps(va1, vb1, acc1);
// 3. Sum `acc0` and `acc1`, then perform horizontal reduction.
float dual_accumulator_fma(const float *a, const float *b, size_t dim) {
  __m256 acc0 = _mm256_setzero_ps();
  __m256 acc1 = _mm256_setzero_ps();

  size_t i{0};
  for (; i + 16 <= dim; i += 16) {
    __m256 va0 = _mm256_loadu_ps(a + i);
    __m256 vb0 = _mm256_loadu_ps(b + i);
    __m256 va1 = _mm256_loadu_ps(a + i + 8);
    __m256 vb1 = _mm256_loadu_ps(b + i + 8);

    acc0 = _mm256_fmadd_ps(va0, vb0, acc0);
    acc1 = _mm256_fmadd_ps(va1, vb1, acc1);
  }

  __m256 acc = _mm256_add_ps(acc0, acc1);

  alignas(32) float buf[8];
  _mm256_store_ps(buf, acc);
  float total =
      buf[0] + buf[1] + buf[2] + buf[3] + buf[4] + buf[5] + buf[6] + buf[7];

  for (; i < dim; ++i) {
    total += a[i] * b[i];
  }

  return total;
}

int main() {
  std::cout << "--- Drill 06: CS:APP Dual Accumulator ILP Unrolling ---\n\n";

  constexpr size_t D = 128;
  std::vector<float> a(D, 1.5f), b(D, 2.0f);

  float res = dual_accumulator_fma(a.data(), b.data(), D);
  std::cout << "Dual Accumulator FMA Result: " << res << " (Expected: 384.0)\n";

  assert(res == 384.0f && "FMA result mismatch!");
  std::cout << "✓ Drill 06 Passed: 2-way ILP unrolling verified!\n";
  return 0;
}
