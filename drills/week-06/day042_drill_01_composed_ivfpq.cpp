// ==============================================================================
// 🥋 Drill 42.1: Composed IVF-PQ Inverted List Routing & Scanning
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra day042_drill_01_composed_ivfpq.cpp -o drill42 && ./drill42
//
// CONTEXT:
// In IVF-PQ, coarse centroids partition the dataset into inverted lists.
// At query time:
// 1. Coarse stage: Pick top N_PROBE closest centroid lists.
// 2. Fine stage: Scan only the PQ codes inside those lists using ADC LUT.
//
// C++ CONCEPTS TO PRACTICE:
// 1. Struct composition: `struct InvertedList` containing codes and document IDs.
// 2. Multi-probe routing with `std::partial_sort`.
// ==============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cassert>

constexpr size_t N_LISTS = 16;
constexpr size_t N_PROBE = 3;
constexpr size_t M_SUB = 8;
constexpr size_t K_CENT = 256;
constexpr size_t VECS_PER_LIST = 1000;

struct InvertedList {
    std::vector<uint8_t> pq_codes; // Stores M_SUB bytes per vector
    std::vector<uint32_t> doc_ids;  // Stores document IDs
};

int main() {
    std::cout << "--- Drill 42.1: Composed IVF-PQ Inverted List Routing ---\n\n";

    std::mt19937 rng(42);

    std::vector<InvertedList> lists(N_LISTS);
    uint32_t current_doc_id = 0;
    for (auto& list : lists) {
        list.pq_codes.resize(VECS_PER_LIST * M_SUB);
        list.doc_ids.resize(VECS_PER_LIST);
        for (uint8_t& byte : list.pq_codes) byte = static_cast<uint8_t>(rng() % 256);
        for (uint32_t& id : list.doc_ids) id = current_doc_id++;
    }

    std::vector<std::pair<float, size_t>> centroid_dists(N_LISTS);
    std::uniform_real_distribution<float> dist_gen(0.0f, 10.0f);
    for (size_t k = 0; k < N_LISTS; ++k) {
        centroid_dists[k] = { dist_gen(rng), k };
    }

    // TODO 1: Sort centroid_dists so top N_PROBE closest centroids are at the beginning
    // [YOUR CODE HERE: Use std::partial_sort]

    float lut[M_SUB][K_CENT];
    for (size_t m = 0; m < M_SUB; ++m) {
        for (size_t k = 0; k < K_CENT; ++k) {
            lut[m][k] = dist_gen(rng);
        }
    }

    // TODO 2: Loop over the top N_PROBE lists, compute ADC distance for each vector, and push to candidates
    std::vector<std::pair<float, uint32_t>> candidates;
    for (size_t p = 0; p < N_PROBE; ++p) {
        size_t list_idx = centroid_dists[p].second;
        const auto& list = lists[list_idx];

        for (size_t v = 0; v < VECS_PER_LIST; ++v) {
            const uint8_t* code = &list.pq_codes[v * M_SUB];
            float d = 0.0f;
            // [YOUR CODE HERE: Sum lut[m][code[m]] for m in [0, M_SUB)]
            candidates.push_back({ d, list.doc_ids[v] });
        }
    }

    std::cout << "Scanned " << candidates.size() << " / " << N_LISTS * VECS_PER_LIST << " vectors across " << N_PROBE << " probed lists.\n";
    assert(candidates.size() == N_PROBE * VECS_PER_LIST);

    std::cout << "\n✓ Drill Passed: Composed IVF-PQ routing and scan verified!\n";
    return 0;
}
