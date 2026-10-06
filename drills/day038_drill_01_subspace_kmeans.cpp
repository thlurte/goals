// ==============================================================================
// 🥋 Drill 38.1: Subspace k-Means Clustering for Product Quantization
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra day038_drill_01_subspace_kmeans.cpp -o drill38 && ./drill38
//
// CONTEXT:
// In Product Quantization (PQ), D-dimensional vectors are divided into M subspaces
// of dimension d_s = D / M. In each subspace, k-means clusters sub-vectors into K=256 centroids.
//
// C++ CONCEPTS TO PRACTICE:
// 1. 2D array indexing in flat memory: `train_data[i * SUB_DIM + d]`.
// 2. Buffer resets using `std::fill`.
// 3. Division inversion: compute `1.0f / count` once to multiply inside inner loops.
// ==============================================================================

#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <algorithm>
#include <cassert>

constexpr size_t K_CENTROIDS = 256;
constexpr size_t SUB_DIM = 16;
constexpr size_t N_SAMPLES = 5000;

// TODO 1: Implement Euclidean distance between two sub-vectors of dimension `d`
float euclidean_sub_dist(const float* a, const float* b, size_t d) {
    // [YOUR CODE HERE]
    return 0.0f;
}

int main() {
    std::cout << "--- Drill 38.1: Subspace k-Means Clustering ---\n\n";

    std::vector<float> train_data(N_SAMPLES * SUB_DIM);
    std::mt19937 rng(42);
    std::normal_distribution<float> dist(0.0f, 1.0f);
    for (float& x : train_data) x = dist(rng);

    // Seed initial centroids from dataset
    std::vector<float> centroids(K_CENTROIDS * SUB_DIM);
    for (size_t k = 0; k < K_CENTROIDS; ++k) {
        size_t src_idx = (k * 13) % N_SAMPLES;
        for (size_t d = 0; d < SUB_DIM; ++d) {
            centroids[k * SUB_DIM + d] = train_data[src_idx * SUB_DIM + d];
        }
    }

    std::vector<uint8_t> assignments(N_SAMPLES);
    std::vector<float> centroid_sums(K_CENTROIDS * SUB_DIM, 0.0f);
    std::vector<size_t> centroid_counts(K_CENTROIDS, 0);

    // Run 5 Lloyd iterations
    for (int iter = 0; iter < 5; ++iter) {
        // TODO 2: For each training sample, find its closest centroid and store index in assignments[i]
        for (size_t i = 0; i < N_SAMPLES; ++i) {
            const float* sample = &train_data[i * SUB_DIM];
            float min_dist = 1e30f;
            uint8_t nearest_k = 0;

            // [YOUR CODE HERE: Loop over k in [0, K_CENTROIDS), call euclidean_sub_dist, update min_dist & nearest_k]

            assignments[i] = nearest_k;
        }

        // Step 2: Accumulate sums
        std::fill(centroid_sums.begin(), centroid_sums.end(), 0.0f);
        std::fill(centroid_counts.begin(), centroid_counts.end(), 0);

        for (size_t i = 0; i < N_SAMPLES; ++i) {
            uint8_t k = assignments[i];
            centroid_counts[k]++;
            for (size_t d = 0; d < SUB_DIM; ++d) {
                centroid_sums[k * SUB_DIM + d] += train_data[i * SUB_DIM + d];
            }
        }

        // TODO 3: Update centroid coordinates: centroids[k * SUB_DIM + d] = centroid_sums[...] / count
        for (size_t k = 0; k < K_CENTROIDS; ++k) {
            if (centroid_counts[k] > 0) {
                // [YOUR CODE HERE]
            }
        }
    }

    std::cout << "Successfully trained " << K_CENTROIDS << " centroids in subspace (dim = " << SUB_DIM << ")\n";
    std::cout << "\n✓ Drill Passed: Subspace Lloyd k-means clustering verified!\n";
    return 0;
}
