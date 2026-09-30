// ==============================================================================
// 🥋 Drill 25.1: Unit-Hypersphere Projection for Spherical k-Means (MIPS)
//
// 🚀 RUN COMMAND:
// g++ -O3 -march=native -std=c++20 day025_drill_01_spherical_projection.cpp -o drill25_1 && ./drill25_1
//
// CONTEXT:
// In Maximum Inner Product Search (MIPS) and Cosine Similarity, centroids
// must be projected back onto the unit sphere S^(D-1) after each clustering iteration.
//
// C++ SYSTEMS LESSON:
// - Spherical projection: c_k = c_k / ||c_k||_2
// - 1. Compute sum of squares (L2 norm squared).
// - 2. Invert square root: inv_norm = 1.0f / sqrt(norm_sq).
// - 3. Scale all vector elements by inv_norm in-place.
// ==============================================================================

#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

// TODO 1: Implement in-place projection onto the unit sphere S^(D-1)
// Function: project_to_unitsphere(float* vec, size_t dim)
inline void project_to_unitsphere(float* vec, size_t dim) {
    // 1. Calculate norm_sq (sum of vec[i] * vec[i])
    // 2. If norm_sq > 1e-12f, compute inv_norm = 1.0f / std::sqrt(norm_sq)
    // 3. Multiply every vec[i] *= inv_norm
    // [YOUR CODE HERE]
}

int main() {
    std::cout << "--- Drill 25.1: Spherical k-Means Centroid Projection ---\n\n";

    const size_t dim = 8;
    std::vector<float> centroid = {3.0f, 1.5f, 4.2f, 0.8f, 2.1f, 5.5f, 1.1f, 2.9f};

    // Calculate original length
    float unnorm_len = 0.0f;
    for (float v : centroid) unnorm_len += v * v;
    unnorm_len = std::sqrt(unnorm_len);

    std::cout << "Original Centroid L2 Norm = " << unnorm_len << "\n";

    // Call your projection function
    project_to_unitsphere(centroid.data(), dim);

    // Calculate length after projection
    float post_len = 0.0f;
    for (float v : centroid) post_len += v * v;
    post_len = std::sqrt(post_len);

    std::cout << "Projected Centroid L2 Norm = " << post_len << "\n\n";

    // Verification: L2 norm must now be exactly 1.0 (within float epsilon)
    assert(std::abs(post_len - 1.0f) < 1e-5f);
    std::cout << "✓ Drill Passed: Centroid successfully projected onto S^(D-1).\n";
    return 0;
}
