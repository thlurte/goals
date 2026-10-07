// ==============================================================================
// 🥋 Drill 04 (Week 03 / Day 020): Agner Fog Ch 9 — Unit Hypersphere Pre-Normalization
//
// 📖 READING SOURCES:
// - Agner Fog: Optimizing Software in C++ (Ch 9: Reducing Arithmetic Division)
//
// 🎯 CORE LESSON:
// 1. Offline Pre-Normalization:
//    Pre-dividing database vectors by their norm ||x|| offline transforms Cosine similarity
//    queries into pure Inner Products: <q_unit, x_unit>, eliminating run-time square roots.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra drill_04_day020_offline_unit_sphere_normalization.cpp -o drill04 && ./drill04
// ==============================================================================

#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

void pre_normalize_matrix(float* data, size_t num_vectors, size_t dim) {
    for (size_t i = 0; i < num_vectors; ++i) {
        float* vec = data + i * dim;
        float norm_sq{0.0f};
        for (size_t d = 0; d < dim; ++d) norm_sq += vec[d] * vec[d];

        float inv_norm = 1.0f / std::sqrt(norm_sq);
        for (size_t d = 0; d < dim; ++d) vec[d] *= inv_norm;
    }
}

int main() {
    std::cout << "--- Week 03 Drill 04: Unit Hypersphere Pre-Normalization ---\n\n";

    constexpr size_t N = 4, D = 4;
    std::vector<float> matrix = {
        3.0f, 4.0f, 0.0f, 0.0f, // Norm = 5.0 -> [0.6, 0.8, 0, 0]
        1.0f, 1.0f, 1.0f, 1.0f, // Norm = 2.0 -> [0.5, 0.5, 0.5, 0.5]
        0.0f, 0.0f, 2.0f, 0.0f, // Norm = 2.0 -> [0, 0, 1.0, 0]
        0.0f, 5.0f, 0.0f, 0.0f  // Norm = 5.0 -> [0, 1.0, 0, 0]
    };

    pre_normalize_matrix(matrix.data(), N, D);

    assert(std::abs(matrix[0] - 0.6f) < 1e-5f);
    assert(std::abs(matrix[1] - 0.8f) < 1e-5f);

    std::cout << "✓ Matrix successfully pre-normalized on unit hypersphere!\n";
    std::cout << "\n✓ Week 03 Drill 04 Passed Successfully!\n";
    return 0;
}
