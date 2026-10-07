// ==============================================================================
// 🥋 Drill 03 (Week 04 / Day 025): Faiss IVF — Spherical k-Means Centroid Updates
//
// 📖 READING SOURCES:
// - Johnson, Douze, Jégou: "Billion-Scale Similarity Search with GPUs" (IEEE TBD)
//
// 🎯 CORE LESSON:
// 1. Standard Euclidean k-Means: Centroid is arithmetic mean mu = (1 / |C|) * sum(x).
// 2. Spherical k-Means (for MIPS / Cosine):
//    After summing assigned vectors, the centroid must be re-projected to the unit hypersphere:
//    mu_spherical = mu / ||mu||_2.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra drill_03_day025_spherical_kmeans_clustering.cpp -o drill03 && ./drill03
// ==============================================================================

#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

void update_spherical_centroid(
    const std::vector<std::vector<float>>& cluster_vectors,
    std::vector<float>& centroid,
    size_t dim
) {
    if (cluster_vectors.empty()) return;

    // 1. Accumulate sum
    std::vector<float> sum(dim, 0.0f);
    for (const auto& vec : cluster_vectors) {
        for (size_t d = 0; d < dim; ++d) sum[d] += vec[d];
    }

    // 2. Normalize to unit length
    float norm_sq{0.0f};
    for (float x : sum) norm_sq += x * x;
    float inv_norm = 1.0f / std::sqrt(norm_sq);

    for (size_t d = 0; d < dim; ++d) {
        centroid[d] = sum[d] * inv_norm;
    }
}

int main() {
    std::cout << "--- Week 04 Drill 03: Spherical k-Means Centroid Update ---\n\n";

    constexpr size_t D = 2;
    std::vector<std::vector<float>> cluster = {
        {1.0f, 0.0f},
        {0.0f, 1.0f}
    };
    // Sum = [1.0, 1.0] -> Normalized = [1/sqrt(2), 1/sqrt(2)] approx [0.7071, 0.7071]

    std::vector<float> centroid(D, 0.0f);
    update_spherical_centroid(cluster, centroid, D);

    float norm = std::sqrt(centroid[0] * centroid[0] + centroid[1] * centroid[1]);
    std::cout << "Spherical Centroid: [" << centroid[0] << ", " << centroid[1] << "]\n";
    std::cout << "Centroid Norm: " << norm << " (Expected: 1.0)\n";

    assert(std::abs(norm - 1.0f) < 1e-5f);
    assert(std::abs(centroid[0] - 0.707106f) < 1e-4f);

    std::cout << "\n✓ Week 04 Drill 03 Passed Successfully!\n";
    return 0;
}
