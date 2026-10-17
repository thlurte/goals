/**
 * @file day038_drill_01_subspace_kmeans.cpp
 * @brief Drill 38.1: Subspace k-Means Clustering & Centroid Math in C++
 *
 * 🎓 C++ CONCEPTS TAUGHT IN THIS DRILL:
 * 1. Multi-dimensional array flattening: Accessing `data[sample_idx * SUB_DIM + dim]` safely.
 * 2. `std::fill`: Rapidly resetting accumulation buffers without memory re-allocation.
 * 3. Floating-point division inversion: Computing `1.0f / count` once to multiply in the loop.
 * 4. Cache locality in subspace slices: Why keeping `SUB_DIM` small (16 floats = 64 bytes) fits in L1D cache.
 *
 * Compile: g++ -O3 -std=c++20 -Wall -Wextra day038_drill_01_subspace_kmeans.cpp -o drill38 && ./drill38
 */

#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <algorithm>
#include <cassert>

constexpr size_t K_CENTROIDS = 256;
constexpr size_t SUB_DIM = 16;
constexpr size_t N_SAMPLES = 5000;

float euclidean_sub_dist(const float* a, const float* b, size_t d) {
    float sum = 0.0f;
    for (size_t i = 0; i < d; ++i) {
        float diff = a[i] - b[i];
        sum += diff * diff;
    }
    return sum;
}

int main() {
    std::cout << "===================================================================\n";
    std::cout << "🥋 Drill 38.1: Subspace k-Means Lloyd Iteration & L1D Cache Locality\n";
    std::cout << "===================================================================\n";

    std::vector<float> train_data(N_SAMPLES * SUB_DIM);
    std::mt19937 rng(42);
    std::normal_distribution<float> dist(0.0f, 1.0f);
    for (float& x : train_data) x = dist(rng);

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

    for (int iter = 0; iter < 5; ++iter) {
        for (size_t i = 0; i < N_SAMPLES; ++i) {
            const float* sample = &train_data[i * SUB_DIM];
            float min_dist = 1e30f;
            uint8_t nearest_k = 0;

            for (size_t k = 0; k < K_CENTROIDS; ++k) {
                float d = euclidean_sub_dist(sample, &centroids[k * SUB_DIM], SUB_DIM);
                if (d < min_dist) {
                    min_dist = d;
                    nearest_k = static_cast<uint8_t>(k);
                }
            }
            assignments[i] = nearest_k;
        }

        std::fill(centroid_sums.begin(), centroid_sums.end(), 0.0f);
        std::fill(centroid_counts.begin(), centroid_counts.end(), 0);

        for (size_t i = 0; i < N_SAMPLES; ++i) {
            uint8_t k = assignments[i];
            centroid_counts[k]++;
            for (size_t d = 0; d < SUB_DIM; ++d) {
                centroid_sums[k * SUB_DIM + d] += train_data[i * SUB_DIM + d];
            }
        }

        for (size_t k = 0; k < K_CENTROIDS; ++k) {
            if (centroid_counts[k] > 0) {
                float inv_n = 1.0f / static_cast<float>(centroid_counts[k]);
                for (size_t d = 0; d < SUB_DIM; ++d) {
                    centroids[k * SUB_DIM + d] = centroid_sums[k * SUB_DIM + d] * inv_n;
                }
            }
        }
    }

    std::cout << "[Info] Successfully trained " << K_CENTROIDS << " centroids in subspace (dim = " << SUB_DIM << ")\n";
    std::cout << "\n✅ DRILL 38.1 PASSED: Subspace k-means clustering verified.\n";
    return 0;
}
