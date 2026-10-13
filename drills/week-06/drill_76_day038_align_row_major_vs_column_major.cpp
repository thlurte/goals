// ==============================================================================
// 🥋 Drill: Row-Major vs Column-Major Layout for SIMD Dot Products
//
// 📖 READING SOURCES:
// - Hennessy & Patterson: Appendix B (Matrix Memory Strides)
// - Golub & Van Loan: Matrix Computations
//
// 🎯 CORE LESSON:
// 1. Row-Major stores each vector contiguously: $V_0 = [d_0, d_1, d_2, \dots]$. Ideal for $L_2$ distance.
// 2. Column-Major stores dimension $k$ across all vectors contiguously. Ideal for broadcast matrix multiplication.
// 3. Choosing wrong layout incurs $O(N)$ stride penalties during SIMD operations.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_76_day038_align_row_major_vs_column_major.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <vector>
#include <cassert>

int main() {
    std::cout << "--- Drill 76: Row-Major vs Column-Major Indexing ---\n\n";

    constexpr size_t Rows = 4;
    constexpr size_t Cols = 8;

    // Row-Major: element (r, c) = r * Cols + c
    std::vector<float> row_major(Rows * Cols);
    for (size_t r = 0; r < Rows; ++r) {
        for (size_t c = 0; c < Cols; ++c) {
            row_major[r * Cols + c] = static_cast<float>(r * 10 + c);
        }
    }
    assert(row_major[2 * Cols + 3] == 23.0f);

    // Column-Major: element (r, c) = c * Rows + r
    std::vector<float> col_major(Rows * Cols);
    for (size_t r = 0; r < Rows; ++r) {
        for (size_t c = 0; c < Cols; ++c) {
            col_major[c * Rows + r] = static_cast<float>(r * 10 + c);
        }
    }
    assert(col_major[3 * Rows + 2] == 23.0f);

    std::cout << "\n✓ Drill 76 Passed: Matrix memory ordering strides verified!\n";
    return 0;
}
