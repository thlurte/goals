// ==============================================================================
// 🥋 Drill 27 (Day 34.18): IVF Deep Dive (Part 4) — IVF-PQ Residual Vector Encoding
//
// 📖 READING SOURCES:
// - Jégou, Douze, Schmid: "Product Quantization for Nearest Neighbor Search" (IEEE TPAMI §4.1)
// - Faiss: `IndexIVFPQ` Codebook & Residual Formulation
//
// 🎯 CORE LESSON:
// 1. Inverted File with Product/Scalar Quantization (IVF-PQ / IVF-SQ):
//    Instead of storing the raw vector $x$ in cluster $c$, store its **centroid residual**:
//    $$r = x - c$$
// 2. Reduced Variance: Centroid residuals have much smaller variance than raw vectors,
//    significantly reducing quantization error.
// 3. Asymmetric Query Distance:
//    $$\|q - x\|^2 = \|(q - c) - r\|^2$$
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra drill_27_day034_ivf_residual_encoding_quant.cpp -o drill27 && ./drill27
// ==============================================================================

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>
#include <cassert>

// TODO 1: Implement IVF Centroid Residual Calculation
// residual[d] = raw_vec[d] - centroid[d]
void compute_ivf_residual(
    const float* raw_vec,
    const float* centroid,
    float* out_residual,
    size_t dim
) {
    // [YOUR CODE HERE]
    (void)raw_vec;
    (void)centroid;
    (void)out_residual;
    (void)dim;
}

// TODO 2: Implement Asymmetric Query Residual Distance
// Evaluates ||(q - c) - r||^2 directly
float query_to_residual_l2_squared(
    const float* query_minus_centroid,
    const float* residual,
    size_t dim
) {
    // [YOUR CODE HERE]
    (void)query_minus_centroid;
    (void)residual;
    (void)dim;
    return 0.0f;
}

int main() {
    std::cout << "--- Drill 27: IVF Deep Dive Part 4 — Centroid Residuals ---\n\n";

    constexpr size_t D = 4;
    float raw_vector[4] = {10.5f, 20.2f, 30.8f, 40.1f};
    float centroid[4]   = {10.0f, 20.0f, 30.0f, 40.0f};
    float query[4]      = {11.0f, 21.0f, 31.0f, 41.0f};

    // 1. Calculate residual
    float residual[4];
    compute_ivf_residual(raw_vector, centroid, residual, D);

    assert(std::abs(residual[0] - 0.5f) < 1e-5f);
    assert(std::abs(residual[1] - 0.2f) < 1e-5f);
    assert(std::abs(residual[2] - 0.8f) < 1e-5f);
    assert(std::abs(residual[3] - 0.1f) < 1e-5f);
    std::cout << "✓ Centroid residual calculation verified!\n";

    // 2. Pre-calculate query minus centroid
    float q_minus_c[4];
    for (size_t d = 0; d < D; ++d) {
        q_minus_c[d] = query[d] - centroid[d]; // {1.0, 1.0, 1.0, 1.0}
    }

    float residual_dist = query_to_residual_l2_squared(q_minus_c, residual, D);

    // Exact direct distance ||q - raw_vec||^2
    float direct_dist = 0.0f;
    for (size_t d = 0; d < D; ++d) {
        float diff = query[d] - raw_vector[d];
        direct_dist += diff * diff;
    }

    std::cout << "Residual formulation distance: " << residual_dist << "\n";
    std::cout << "Direct raw vector distance:   " << direct_dist << "\n";

    assert(std::abs(residual_dist - direct_dist) < 1e-5f && "Residual distance must match direct L2 distance!");

    std::cout << "\n✓ Drill 27 Passed: IVF Residual encoding verified!\n";
    return 0;
}
