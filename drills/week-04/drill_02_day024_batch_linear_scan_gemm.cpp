// ==============================================================================
// 🥋 Drill 02 (Week 04 / Day 024): `secan` — Batch Query Scanning (GEMV to GEMM)
//
// 📖 READING SOURCES:
// - `secan` Batch Scanning Architecture
//
// 🎯 CORE LESSON:
// 1. Single Query (GEMV):
//    Scanning N database vectors for 1 query traverses N vectors through memory bus once.
// 2. Batch Queries (GEMM):
//    Processing B queries simultaneously keeps database vectors in L1/L2 cache,
//    reusing loaded vectors across all B queries!
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra drill_02_day024_batch_linear_scan_gemm.cpp -o drill02 && ./drill02
// ==============================================================================

#include <iostream>
#include <vector>
#include <cassert>

void batch_inner_product(
    const float* queries, // (B, D)
    const float* base,    // (N, D)
    float* output,        // (B, N)
    size_t B, size_t N, size_t D
) {
    // Database vector in outer loop -> reused across queries
    for (size_t n = 0; n < N; ++n) {
        const float* b_vec = base + n * D;
        for (size_t b = 0; b < B; ++b) {
            const float* q_vec = queries + b * D;
            float dot{0.0f};
            for (size_t d = 0; d < D; ++d) {
                dot += q_vec[d] * b_vec[d];
            }
            output[b * N + n] = dot;
        }
    }
}

int main() {
    std::cout << "--- Week 04 Drill 02: Batch Vector Scanning (GEMM) ---\n\n";

    constexpr size_t B = 2, N = 4, D = 4;
    std::vector<float> queries(B * D, 1.0f);
    std::vector<float> base(N * D, 2.0f);
    std::vector<float> out(B * N, 0.0f);

    batch_inner_product(queries.data(), base.data(), out.data(), B, N, D);

    // Each dot product = 4 dims * (1.0 * 2.0) = 8.0
    for (size_t i = 0; i < B * N; ++i) {
        assert(out[i] == 8.0f);
    }

    std::cout << "✓ Batch GEMM scan output matches expected 8.0 dot product!\n";
    std::cout << "\n✓ Week 04 Drill 02 Passed Successfully!\n";
    return 0;
}
