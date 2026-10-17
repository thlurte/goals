// ==============================================================================
// 🥋 Drill 24 (Day 34.15): IVF Deep Dive (Part 1) — Lloyd's K-Means Centroid Training
//
// 📖 READING SOURCES:
// - Lloyd: "Least Squares Quantization in PCM" (IEEE TIT 1982)
// - Arthur & Vassilvitskii: "k-means++: The Advantages of Careful Seeding" (SODA 2007)
//
// 🎯 CORE LESSON:
// 1. K-Means Clustering for Voronoi Cell Partitioning in IVF.
// 2. Expectation-Maximization (EM) Steps:
//    - Assignment Step (E): Assign each vector to its nearest centroid.
//    - Update Step (M): Recompute centroid coordinates as the mean of all assigned vectors.
// 3. Empty Cluster Re-seeding: Re-seed any degenerate empty cluster from the training vector with worst quantization loss.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra drill_24_day034_ivf_kmeans_centroid_training.cpp -o drill24 && ./drill24
// ==============================================================================

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>
#include <cassert>
#include <limits>
#include <numeric>

struct KMeansTrainer {
    size_t dim{0};
    size_t k{0};
    size_t max_iters{15};
    std::vector<float> centroids; // Size: k * dim

    // TODO 1: Implement Lloyd's K-Means Training Loop
    // 1. Initialize centroids from first k vectors (or random sample)
    // 2. Loop max_iters:
    //    a. Accumulator buffers: cluster_sums (k * dim, 0.0f) and cluster_counts (k, 0)
    //    b. E-step: For each training vector, find closest centroid index c. Add vector to cluster_sums[c] and increment cluster_counts[c].
    //    c. M-step: For each cluster c:
    //       - If count > 0: centroid[c] = cluster_sums[c] / count
    //       - If count == 0: re-seed centroid[c] from the training vector with highest distance (or first vector)
    void train(const float* data, size_t n_vectors, size_t dimension, size_t num_clusters) {
        dim = dimension;
        k = num_clusters;
        centroids.resize(k * dim);

        // [YOUR CODE HERE]
        (void)data;
        (void)n_vectors;
    }

    size_t find_closest_centroid(const float* query) const {
        size_t best_c = 0;
        float min_dist = std::numeric_limits<float>::max();
        for (size_t c = 0; c < k; ++c) {
            const float* cent = centroids.data() + c * dim;
            float dist = 0.0f;
            for (size_t d = 0; d < dim; ++d) {
                float diff = query[d] - cent[d];
                dist += diff * diff;
            }
            if (dist < min_dist) {
                min_dist = dist;
                best_c = c;
            }
        }
        return best_c;
    }
};

int main() {
    std::cout << "--- Drill 24: IVF Deep Dive Part 1 — K-Means Centroid Training ---\n\n";

    constexpr size_t D = 2;
    constexpr size_t K = 2;
    constexpr size_t N = 6;

    // Two obvious 2D clusters: cluster 0 around (1,1), cluster 1 around (10,10)
    std::vector<float> dataset = {
        1.0f, 1.0f,
        1.2f, 0.9f,
        0.8f, 1.1f,
        10.0f, 10.0f,
        10.2f, 9.8f,
        9.9f, 10.1f
    };

    KMeansTrainer trainer;
    trainer.train(dataset.data(), N, D, K);

    assert(trainer.centroids.size() == K * D);

    // Centroids should be around (1, 1) and (10, 10)
    float q_low[2] = {1.1f, 1.0f};
    float q_high[2] = {9.9f, 10.0f};

    size_t c_low = trainer.find_closest_centroid(q_low);
    size_t c_high = trainer.find_closest_centroid(q_high);

    std::cout << "Centroid for (1.1, 1.0):   Cluster " << c_low << "\n";
    std::cout << "Centroid for (9.9, 10.0):  Cluster " << c_high << "\n";

    assert(c_low != c_high && "Low and high clusters must map to distinct Voronoi centroids!");
    std::cout << "\n✓ Drill 24 Passed: IVF K-Means Centroid training operational!\n";
    return 0;
}
