// ==============================================================================
// 🥋 Drill 12 (Week 01 / Day 007): High-D Metric Geometry — Euclidean-Cosine Identity
//
// 📖 READING SOURCES:
// - Roman Vershynin: High-Dimensional Probability (Ch 1: Vectors on the Hypersphere S^{d-1})
// - `secan` Metric Geometry Validation
//
// 🎯 CORE LESSON:
// 1. The Hypersphere Metric Identity:
//    For any two unit vectors ||u||_2 = 1 and ||v||_2 = 1:
//    ||u - v||_2^2 = ||u||^2 + ||v||^2 - 2<u, v> = 1 + 1 - 2<u, v> = 2 - 2<u, v>.
// 2. Systems Optimization:
//    Searching normalized embeddings under Cosine distance is strictly equivalent to L2 distance,
//    allowing vector databases to use fast L2 SIMD kernels directly.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra drill_12_day007_euclidean_cosine_identity.cpp -o drill12 && ./drill12
// ==============================================================================

#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

// Normalize vector to unit length ||v|| = 1.0 in place
void normalize_unit_vector(std::vector<float>& vec) {
    float norm_sq{0.0f};
    for (float x : vec) norm_sq += x * x;
    float inv_norm = 1.0f / std::sqrt(norm_sq);
    for (float& x : vec) x *= inv_norm;
}

float l2_squared(const std::vector<float>& u, const std::vector<float>& v) {
    float sum{0.0f};
    for (size_t i = 0; i < u.size(); ++i) {
        float d = u[i] - v[i];
        sum += d * d;
    }
    return sum;
}

float inner_product(const std::vector<float>& u, const std::vector<float>& v) {
    float dot{0.0f};
    for (size_t i = 0; i < u.size(); ++i) {
        dot += u[i] * v[i];
    }
    return dot;
}

int main() {
    std::cout << "--- Week 01 Drill 12: High-D Euclidean-Cosine Identity ---\n\n";

    constexpr size_t D = 128;
    std::vector<float> u(D), v(D);
    for (size_t i = 0; i < D; ++i) {
        u[i] = static_cast<float>(i + 1);
        v[i] = static_cast<float>((i + 1) * (i + 1));
    }

    normalize_unit_vector(u);
    normalize_unit_vector(v);

    float l2_dist_sq = l2_squared(u, v);
    float dot = inner_product(u, v);
    float identity_dist_sq = 2.0f - 2.0f * dot;

    std::cout << "Direct L2 Squared:        " << l2_dist_sq << "\n";
    std::cout << "Identity (2 - 2 * <u,v>): " << identity_dist_sq << "\n";

    assert(std::abs(l2_dist_sq - identity_dist_sq) < 1e-5f && "Metric identity must hold exactly for unit vectors!");
    std::cout << "\n✓ Week 01 Drill 12 Passed Successfully!\n";
    return 0;
}
