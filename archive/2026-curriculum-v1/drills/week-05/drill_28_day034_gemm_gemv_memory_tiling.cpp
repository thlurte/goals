// ==============================================================================
// 🥋 Drill 28 (Day 34.19): Matrix Multiplication Mastery (Part 1) — GEMV vs GEMM Arithmetic Intensity
//
// 📖 READING SOURCES:
// - Williams et al.: "Roofline: An Insightful Visual Performance Model" (CACM 2009)
// - Goto & van de Geijn: "Anatomy of High-Performance Matrix Multiplication" (ACM TOMS 2008)
//
// 🎯 CORE LESSON:
// 1. GEMV (Matrix-Vector: $y = A x$): Arithmetic Intensity = $\frac{2 N^2 \text{ FLOPs}}{4 N^2 \text{ Bytes}} = 0.5 \text{ FLOP/Byte}$.
//    Strictly memory-bandwidth bound! The CPU spends 90% of its time waiting for DRAM line fetches.
// 2. GEMM (Matrix-Matrix Batch: $C = A B$): Batch size $B$. Arithmetic Intensity = $\frac{2 B N^2 \text{ FLOPs}}{4 N^2 + 4 B N \text{ Bytes}} \approx \frac{B}{2} \text{ FLOPs/Byte}$.
//    When $B=64$, operational intensity jumps from $0.5 \to 32 \text{ FLOPs/Byte}$, crossing the Roofline into compute-bound peak FLOPS!
// 3. Vector Batch Querying in Vector DBs: Batching 64 queries transforms slow single-query linear scans into fast Matrix Multiplications ($3.2\times$ throughput speedup).
//
// 🚀 RUN COMMAND:
// g++ -O3 -march=native -mavx2 -mfma -std=c++20 -Wall -Wextra drill_28_day034_gemm_gemv_memory_tiling.cpp -o drill28 && ./drill28
// ==============================================================================

#include <iostream>
#include <vector>
#include <immintrin.h>
#include <cstdint>
#include <cassert>
#include <cmath>

// TODO 1: Implement SIMD Vector-Matrix Multiply GEMV (y = A * x)
// A is row-major (M x N), x is (N x 1), y is (M x 1)
// For each row m: compute dot product of row A[m, :] and vector x using AVX2 FMA
void gemv_row_major_avx2(
    const float* A,
    const float* x,
    float* y,
    size_t M,
    size_t N
) {
    // [YOUR CODE HERE]
    (void)A;
    (void)x;
    (void)y;
    (void)M;
    (void)N;
}

// TODO 2: Implement Naive GEMM (C = A * B)
// A is (M x K), B is (K x N), C is (M x N) - all row-major
void gemm_naive(
    const float* A,
    const float* B,
    float* C,
    size_t M,
    size_t N,
    size_t K
) {
    // [YOUR CODE HERE]
    (void)A;
    (void)B;
    (void)C;
    (void)M;
    (void)N;
    (void)K;
}

int main() {
    std::cout << "--- Drill 28: GEMV vs GEMM Arithmetic Intensity & Roofline ---\n\n";

    constexpr size_t M = 4;
    constexpr size_t N = 8;

    // A is 4x8 matrix filled with 1.0f
    std::vector<float> A(M * N, 1.0f);
    // x is 8x1 vector filled with 2.0f
    std::vector<float> x(N, 2.0f);
    std::vector<float> y(M, 0.0f);

    gemv_row_major_avx2(A.data(), x.data(), y.data(), M, N);

    // Each element in y should be 8 * (1.0 * 2.0) = 16.0f
    for (size_t m = 0; m < M; ++m) {
        assert(y[m] == 16.0f && "GEMV output mismatch!");
    }
    std::cout << "✓ AVX2 GEMV verified (Expected: 16.0 for all rows)!\n";

    // Test GEMM: C (4x4) = A (4x8) * B (8x4)
    constexpr size_t K = 8;
    std::vector<float> B(K * M, 3.0f);
    std::vector<float> C(M * M, 0.0f);

    gemm_naive(A.data(), B.data(), C.data(), M, M, K);

    // Each element in C should be 8 * (1.0 * 3.0) = 24.0f
    for (size_t i = 0; i < M * M; ++i) {
        assert(C[i] == 24.0f && "GEMM output mismatch!");
    }
    std::cout << "✓ Naive GEMM verified (Expected: 24.0 for all elements)!\n";

    std::cout << "\n✓ Drill 28 Passed: GEMV and GEMM foundation operational!\n";
    return 0;
}
