#include <iostream>
#include <vector>
#include <cmath>
#include <immintrin.h>
#include <cassert>

// Drill 25.1: Unit-Hypersphere Projection for Spherical k-Means (MIPS)
// In Maximum Inner Product Search, unnormalized cluster accumulator centroids
// must be projected onto S^(D-1) via c_k / ||c_k||_2.

inline void project_to_unitsphere(float* vec, size_t dim) {
    float norm_sq = 0.0f;
    for (size_t i = 0; i < dim; ++i) {
        norm_sq += vec[i] * vec[i];
    }
    if (norm_sq > 1e-12f) {
        float inv_norm = 1.0f / std::sqrt(norm_sq);
        for (size_t i = 0; i < dim; ++i) {
            vec[i] *= inv_norm;
        }
    }
}

int main() {
    std::cout << "--- Drill 25.1: Spherical k-Means Centroid Projection ---\n\n";

    const size_t dim = 8;
    std::vector<float> centroid = {3.0f, 1.5f, 4.2f, 0.8f, 2.1f, 5.5f, 1.1f, 2.9f};

    float unnorm_len = 0.0f;
    for (float v : centroid) unnorm_len += v * v;
    unnorm_len = std::sqrt(unnorm_len);

    std::cout << "Original Centroid L2 Norm = " << unnorm_len << "\n";

    project_to_unitsphere(centroid.data(), dim);

    float post_len = 0.0f;
    for (float v : centroid) post_len += v * v;
    post_len = std::sqrt(post_len);

    std::cout << "Projected Centroid L2 Norm = " << post_len << "\n\n";

    assert(std::abs(post_len - 1.0f) < 1e-5f);
    std::cout << "✓ Drill Passed: Centroid successfully projected onto S^(D-1).\n";
    return 0;
}
