// ==============================================================================
// 🥋 Drill: Cache-Aware Blocked Matrix Transposition
//
// 📖 READING SOURCES:
// - CS:APP (Ch 6.5: Writing Cache-Friendly Code)
// - Frigo et al.: Cache-Oblivious Algorithms
//
// 🎯 CORE LESSON:
// 1. Naive matrix transposition has stride-1 reads but stride-$N$ writes (terrible cache misses).
// 2. Blocked transposition operates on $B \times B$ submatrices that fit entirely inside L1 cache.
// 3. Drastically accelerates vector codebook transpositions for FastScan AVX2 lookups.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_77_day038_align_cache_oblivious_transposition.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <vector>
#include <cassert>

void transpose_blocked(const float* A, float* B, size_t N, size_t block_size) {
    for (size_t i = 0; i < N; i += block_size) {
        for (size_t j = 0; j < N; j += block_size) {
            for (size_t ii = i; ii < i + block_size && ii < N; ++ii) {
                for (size_t jj = j; jj < j + block_size && jj < N; ++jj) {
                    B[jj * N + ii] = A[ii * N + jj];
                }
            }
        }
    }
}

int main() {
    std::cout << "--- Drill 77: Cache-Blocked Matrix Transposition ---\n\n";

    constexpr size_t N = 64;
    std::vector<float> A(N * N);
    std::vector<float> B(N * N, 0.0f);

    for (size_t i = 0; i < N * N; ++i) A[i] = static_cast<float>(i);

    transpose_blocked(A.data(), B.data(), N, 16);

    for (size_t r = 0; r < N; ++r) {
        for (size_t c = 0; c < N; ++c) {
            assert(B[c * N + r] == A[r * N + c]);
        }
    }

    std::cout << "\n✓ Drill 77 Passed: Cache-blocked transposition verified!\n";
    return 0;
}
