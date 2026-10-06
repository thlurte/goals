// ==============================================================================
// 🥋 Drill 35.1: Two-Stage Re-ranking & std::partial_sort in C++
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra day035_drill_01_twostage_filter.cpp -o drill35 && ./drill35
//
// CONTEXT:
// Scanning raw FP32 vectors takes high memory bandwidth.
// Two-stage retrieval:
// 1. Filter: Rapidly scan low-bit quantized DB (SQ8) to get Top K_COARSE candidates.
// 2. Re-rank: Re-compute exact FP32 distance ONLY for those candidates.
//
// C++ CONCEPTS TO PRACTICE:
// 1. Struct `operator<` overloading for sorting.
// 2. `std::partial_sort(begin, middle, end)`: Sorts only the first N elements in-place.
// ==============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cassert>
#include <chrono>

struct Candidate {
    uint32_t doc_id{0};
    float score{0.0f};

    // TODO 1: Overload operator< to sort candidates by score in ascending order (smallest first)
    bool operator<(const Candidate& other) const noexcept {
        // [YOUR CODE HERE]
        return false;
    }
};

int main() {
    std::cout << "--- Drill 35.1: Two-Stage Re-ranking with std::partial_sort ---\n\n";

    constexpr size_t N_VECTORS = 10000;
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
    for (size_t i = 0; i < N_VECTORS * D; ++i) sq8_database[i] = static_cast<uint8_t>(fp32_database[i] * 255.0f);
    for (size_t i = 0; i < D; ++i) query_sq8[i] = static_cast<uint8_t>(query_fp32[i] * 255.0f);

    // Stage 1: Coarse SQ8 Scan
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

    // TODO 2: Use std::partial_sort to sort ONLY the top K_COARSE candidates in coarse_candidates
    // [YOUR CODE HERE]

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

    // TODO 3: Use std::partial_sort to sort ONLY the top K_FINAL candidates in final_candidates
    // [YOUR CODE HERE]

    std::cout << "Top " << K_FINAL << " Final Results:\n";
    for (size_t i = 0; i < K_FINAL; ++i) {
        std::cout << "  Rank [" << i + 1 << "] DocID: " << final_candidates[i].doc_id
                  << " | Distance: " << final_candidates[i].score << "\n";
    }

    assert(final_candidates[0].score <= final_candidates[1].score);
    std::cout << "\n✓ Drill Passed: Two-stage re-ranking verified!\n";
    return 0;
}
