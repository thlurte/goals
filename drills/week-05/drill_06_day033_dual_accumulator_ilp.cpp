// ==============================================================================
// 🥋 Drill 06 (Day 33.3): CS:APP §5.1–5.12 — ILP & Dual Accumulator Unrolling
//
// 📖 READING SOURCES:
// - Bryant & O'Hallaron: Computer Systems (CS:APP 3rd Ed, §5.1–5.12)
//
// 🎯 CORE LESSON:
// 1. FMA Port Latency (4 cycles) vs Throughput (0.5 cycles):
//    A single accumulator `acc = _mm256_fmadd_ps(..., acc)` forces a 4-cycle stall per iteration.
// 2. Dual Accumulators (`acc0`, `acc1`) break loop-carried dependency chains,
//    allowing out-of-order execution units to issue FMAs back-to-back.
//
// 🚀 RUN COMMAND:
// g++ -O3 -march=native -mavx2 -mfma -std=c++20 -Wall -Wextra drill_06_day033_dual_accumulator_ilp.cpp -o drill06 && ./drill06
// ==============================================================================

#include <iostream>
#include <vector>
#include <immintrin.h>
#include <cassert>

// TODO 1: Implement 2-way unrolled AVX2 FMA dot product
// 1. Initialize `__m256 acc0 = _mm256_setzero_ps();` and `__m256 acc1 = _mm256_setzero_ps();`
// 2. Loop in steps of 16 floats (i + 16 <= dim):
//    acc0 = _mm256_fmadd_ps(va0, vb0, acc0);
//    acc1 = _mm256_fmadd_ps(va1, vb1, acc1);
// 3. Sum `acc0` and `acc1`, then perform horizontal reduction.
float dual_accumulator_fma(const float* a, const float* b, size_t dim) {
    // [YOUR CODE HERE]
    return 0.0f;
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
