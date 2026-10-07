// ==============================================================================
// 🥋 Drill 23 (Day 34.14): Quantization Mastery — Residual Quantization (RQ / OPQ)
//
// 📖 READING SOURCES:
// - Jégou, Douze, Schmid: "Product Quantization for Nearest Neighbor Search" (IEEE TPAMI)
// - Martinez et al.: "Revisiting Additive Quantization" (ECCV)
//
// 🎯 CORE LESSON:
// 1. Multi-Stage Residual Quantization (RQ):
//    - Stage 1: Quantize vector $x$ to closest centroid $c_1^{(1)}$; compute residual $r_1 = x - c_1^{(1)}$.
//    - Stage 2: Quantize residual $r_1$ to closest Stage 2 centroid $c_2^{(2)}$; compute residual $r_2 = r_1 - c_2^{(2)}$.
// 2. Exponential Codebook Expressivity: $K$ centroids in Stage 1 + $K$ centroids in Stage 2 represents $K^2$ reconstructed points using only $2 \times \log_2 K$ bits!
// 3. Asymmetric Reconstruction: Reconstructed vector $\hat{x} = c_1^{(1)} + c_2^{(2)}$.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra drill_23_day034_quant_residual_pq_codebook.cpp -o drill23 && ./drill23
// ==============================================================================

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>
#include <cassert>
#include <limits>

struct ResidualQuantizer2Stage {
    size_t dim{0};
    size_t k{0}; // Centroids per stage (e.g. 16)

    std::vector<float> stage1_centroids; // Size: k * dim
    std::vector<float> stage2_centroids; // Size: k * dim

    // Helper: Find closest centroid in a codebook
    size_t find_closest_centroid(const float* vec, const float* codebook) const {
        size_t best_idx = 0;
        float min_dist = std::numeric_limits<float>::max();

        for (size_t c = 0; c < k; ++c) {
            const float* centroid = codebook + c * dim;
            float dist = 0.0f;
            for (size_t d = 0; d < dim; ++d) {
                float diff = vec[d] - centroid[d];
                dist += diff * diff;
            }
            if (dist < min_dist) {
                min_dist = dist;
                best_idx = c;
            }
        }
        return best_idx;
    }

    // TODO 1: Implement 2-stage Residual Encoding
    // 1. Find best Stage 1 centroid code: code1 = find_closest_centroid(x, stage1_centroids.data())
    // 2. Compute Stage 1 residual: residual[d] = x[d] - stage1_centroids[code1 * dim + d]
    // 3. Find best Stage 2 centroid code on residual: code2 = find_closest_centroid(residual, stage2_centroids.data())
    // 4. Return std::pair<uint8_t, uint8_t>{code1, code2}
    std::pair<uint8_t, uint8_t> encode(const float* x) const {
        // [YOUR CODE HERE]
        (void)x;
        return {0, 0};
    }

    // TODO 2: Implement 2-stage Reconstruction
    // dst[d] = stage1_centroids[code1 * dim + d] + stage2_centroids[code2 * dim + d]
    void decode(uint8_t code1, uint8_t code2, float* dst) const {
        // [YOUR CODE HERE]
        (void)code1;
        (void)code2;
        (void)dst;
    }
};

int main() {
    std::cout << "--- Drill 23: 2-Stage Residual Quantization (RQ) ---\n\n";

    constexpr size_t D = 4;
    constexpr size_t K = 4;

    ResidualQuantizer2Stage rq;
    rq.dim = D;
    rq.k = K;

    // Synthetic Stage 1 coarse centroids
    rq.stage1_centroids = {
        0.0f, 0.0f, 0.0f, 0.0f,
        10.0f, 10.0f, 10.0f, 10.0f,
        20.0f, 20.0f, 20.0f, 20.0f,
        30.0f, 30.0f, 30.0f, 30.0f
    };

    // Synthetic Stage 2 fine residual centroids
    rq.stage2_centroids = {
        -2.0f, -2.0f, -2.0f, -2.0f,
        -1.0f, -1.0f, -1.0f, -1.0f,
         1.0f,  1.0f,  1.0f,  1.0f,
         2.0f,  2.0f,  2.0f,  2.0f
    };

    // Target vector: {11.9, 12.1, 11.8, 12.2} -> Closest Stage 1: {10,10,10,10} (res ~ +2.0) -> Closest Stage 2: {+2,+2,+2,+2}
    std::vector<float> x = {11.9f, 12.1f, 11.8f, 12.2f};

    auto [c1, c2] = rq.encode(x.data());
    std::cout << "Encoded 2-Stage Codes: (" << static_cast<int>(c1) << ", " << static_cast<int>(c2) << ")\n";

    assert(c1 == 1 && "Stage 1 code should be index 1 (vector [10,10,10,10])");
    assert(c2 == 3 && "Stage 2 code should be index 3 (vector [+2,+2,+2,+2])");

    std::vector<float> reconstructed(D);
    rq.decode(c1, c2, reconstructed.data());

    std::cout << "Reconstructed Vector: {"
              << reconstructed[0] << ", " << reconstructed[1] << ", "
              << reconstructed[2] << ", " << reconstructed[3] << "} (Expected: {12, 12, 12, 12})\n";

    for (size_t d = 0; d < D; ++d) {
        assert(std::abs(reconstructed[d] - 12.0f) < 1e-4f);
    }

    std::cout << "\n✓ Drill 23 Passed: 2-stage Residual Quantization verified!\n";
    return 0;
}
