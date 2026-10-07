// ==============================================================================
// 🥋 Drill 29 (Day 34.20): Matrix Multiplication Mastery (Part 2) — 4x16 Register-Blocked GEMM
//
// 📖 READING SOURCES:
// - Goto & van de Geijn: "Anatomy of High-Performance Matrix Multiplication" (ACM TOMS 2008)
// - Agner Fog: Optimizing Software in C++ (Ch 12: Loop Unrolling & Register Allocation)
//
// 🎯 CORE LESSON:
// 1. Register Blocking: Keep a $4 \times 16$ tile of matrix $C$ resident in 8 YMM accumulator registers:
//    - `c00`, `c01` (Row 0: 16 floats)
//    - `c10`, `c11` (Row 1: 16 floats)
//    - `c20`, `c21` (Row 2: 16 floats)
//    - `c30`, `c31` (Row 3: 16 floats)
// 2. Broadcast Multiplication (`_mm256_set1_ps` / `_mm256_broadcast_ss`):
//    Broadcast one scalar from row $A[m, k]$ across all 8 vector lanes and multiply with vector $B[k, :]$.
// 3. Peak Compute Saturation: Eliminates memory loads for matrix $C$ throughout the entire $K$-dimension loop!
//
// 🚀 RUN COMMAND:
// g++ -O3 -march=native -mavx2 -mfma -std=c++20 -Wall -Wextra drill_29_day034_gemm_register_blocking_4x16.cpp -o drill29 && ./drill29
// ==============================================================================

#include <iostream>
#include <vector>
#include <immintrin.h>
#include <cstdint>
#include <cassert>
#include <cmath>

// TODO 1: Implement 4x16 Micro-Kernel for Matrix Multiplication (C += A * B)
// A is (4 x K), B is (K x 16), C is (4 x 16)
// 1. Initialize 8 accumulator registers (c00, c01, c10, c11, c20, c21, c30, c31) to zero
// 2. Loop k from 0 to K - 1:
//    - Load 16 floats from row B[k, :]: vb0 (floats 0..7), vb1 (floats 8..15)
//    - Broadcast scalar a0 = A[0, k]; c00 = _mm256_fmadd_ps(a0, vb0, c00); c01 = _mm256_fmadd_ps(a0, vb1, c01);
//    - Broadcast scalar a1 = A[1, k]; c10 = _mm256_fmadd_ps(a1, vb0, c10); c11 = _mm256_fmadd_ps(a1, vb1, c11);
//    - Broadcast scalar a2 = A[2, k]; c20 = _mm256_fmadd_ps(a2, vb0, c20); c21 = _mm256_fmadd_ps(a2, vb1, c21);
//    - Broadcast scalar a3 = A[3, k]; c30 = _mm256_fmadd_ps(a3, vb0, c30); c31 = _mm256_fmadd_ps(a3, vb1, c31);
// 3. Store 8 accumulator registers back into memory C
void gemm_microkernel_4x16_avx2(
    const float* A, // 4 x K row-major (lda = K)
    const float* B, // K x 16 row-major (ldb = 16)
    float* C,       // 4 x 16 row-major (ldc = 16)
    size_t K
) {
    // [YOUR CODE HERE]
    (void)A;
    (void)B;
    (void)C;
    (void)K;
}

int main() {
    std::cout << "--- Drill 29: 4x16 Register-Blocked AVX2 FMA GEMM Micro-Kernel ---\n\n";

    constexpr size_t M = 4;
    constexpr size_t N = 16;
    constexpr size_t K = 32;

    std::vector<float> A(M * K, 1.5f);
    std::vector<float> B(K * N, 2.0f);
    std::vector<float> C(M * N, 0.0f);

    gemm_microkernel_4x16_avx2(A.data(), B.data(), C.data(), K);

    // Each element in C should be K * (1.5 * 2.0) = 32 * 3.0 = 96.0f
    for (size_t i = 0; i < M * N; ++i) {
        assert(std::abs(C[i] - 96.0f) < 1e-4f && "4x16 GEMM kernel calculation mismatch!");
    }

    std::cout << "✓ 4x16 Register-blocked GEMM kernel verified (Expected: 96.0 for all 64 elements)!\n";
    std::cout << "\n✓ Drill 29 Passed: 4x16 register blocking fully operational!\n";
    return 0;
}
