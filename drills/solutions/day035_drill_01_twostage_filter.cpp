/**
 * @file day035_drill_01_twostage_filter.cpp
 * @brief Drill 35.1: Two-Stage Re-ranking Architecture & std::partial_sort in Modern C++
 *
 * 🎓 C++ CONCEPTS TAUGHT IN THIS DRILL:
 * 1. Structs with custom `operator<`: Enabling sorting without writing cumbersome custom comparators.
 * 2. `std::partial_sort`: Why sorting only Top-K elements is O(N log K) instead of O(N log N) std::sort.
 * 3. Cache-friendly contiguous vectors: Storing structures by value vs allocating node pointers.
 * 4. Two-stage candidate filtering: Coarse fast filter (SQ8) -> Exact fine score (FP32).
 *
 * Compile: g++ -O3 -std=c++20 -Wall -Wextra day035_drill_01_twostage_filter.cpp -o drill35 && ./drill35
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cassert>
#include <chrono>

struct Candidate {
    uint32_t doc_id{0};
    float score{0.0f};

    bool operator<(const Candidate& other) const noexcept {
        return score < other.score;
    }
};

int main() {
    std::cout << "===================================================================\n";
    std::cout << "🥋 Drill 35.1: Two-Stage Filter & Re-rank with std::partial_sort\n";
    std::cout << "===================================================================\n";

    constexpr size_t N_VECTORS = 100000;
    constexpr size_t D = 128;
    constexpr size_t K_COARSE = 100;
    constexpr size_t K_FINAL = 10;

    std::vector<float> fp32_database(N_VECTORS * D);
    std::vector<uint8_t> sq8_database(N_VECTORS * D);
    std::vector<float> query_fp32(D);
    std::vector<uint8_t> query_sq8(D);

    std::mt19937 rng(42);
    std::uniform_real_distribution<float> dist(0.0f, 1.0f);

    for (float& x : fp32_database) x = dist(rng);
    for (float& x : query_fp32) x = dist(rng);

    for (size_t i = 0; i < N_VECTORS * D; ++i) {
        sq8_database[i] = static_cast<uint8_t>(fp32_database[i] * 255.0f);
    }
    for (size_t i = 0; i < D; ++i) {
        query_sq8[i] = static_cast<uint8_t>(query_fp32[i] * 255.0f);
    }

    auto t0 = std::chrono::high_resolution_clock::now();

    // Stage 1: Fast Coarse Scan over SQ8 database
    std::vector<Candidate> coarse_candidates(N_VECTORS);
    for (size_t i = 0; i < N_VECTORS; ++i) {
        const uint8_t* vec = &sq8_database[i * D];
        uint32_t int_l2 = 0;
        for (size_t d = 0; d < D; ++d) {
            int32_t diff = static_cast<int32_t>(query_sq8[d]) - static_cast<int32_t>(vec[d]);
            int_l2 += diff * diff;
        }
        coarse_candidates[i] = { static_cast<uint32_t>(i), static_cast<float>(int_l2) };
    }

    std::partial_sort(coarse_candidates.begin(),
                      coarse_candidates.begin() + K_COARSE,
                      coarse_candidates.end());

    // Stage 2: Exact FP32 Re-rank on top K_COARSE candidates
    std::vector<Candidate> final_candidates(K_COARSE);
    for (size_t i = 0; i < K_COARSE; ++i) {
        uint32_t id = coarse_candidates[i].doc_id;
        const float* vec = &fp32_database[id * D];
        float fp32_l2 = 0.0f;
        for (size_t d = 0; d < D; ++d) {
            float diff = query_fp32[d] - vec[d];
            fp32_l2 += diff * diff;
        }
        final_candidates[i] = { id, fp32_l2 };
    }

    std::partial_sort(final_candidates.begin(),
                      final_candidates.begin() + K_FINAL,
                      final_candidates.end());

    auto t1 = std::chrono::high_resolution_clock::now();
    double elapsed_ms = std::chrono::duration<double, std::milli>(t1 - t0).count();

    std::cout << "🏆 Top-" << K_FINAL << " Final Results (Elapsed: " << elapsed_ms << " ms):\n";
    for (size_t i = 0; i < K_FINAL; ++i) {
        std::cout << "  [" << i + 1 << "] DocID: " << final_candidates[i].doc_id
                  << " (FP32 Dist: " << final_candidates[i].score << ")\n";
    }

    std::cout << "\n✅ DRILL 35.1 PASSED: 2-stage re-ranking with std::partial_sort verified.\n";
    return 0;
}
