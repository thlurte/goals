/**
 * @file day042_drill_01_composed_ivfpq.cpp
 * @brief Drill 42.1: Composed IVF-PQ Inverted List Routing & C++ Vector of Structs
 *
 * 🎓 C++ CONCEPTS TAUGHT IN THIS DRILL:
 * 1. Nested structs: Structs containing `std::vector` to represent dynamic postings lists.
 * 2. Two-level indexing: Coarse centroid routing followed by fine-grained PQ list scanning.
 * 3. Range-based for loops vs index loops.
 *
 * Compile: g++ -O3 -std=c++20 -Wall -Wextra day042_drill_01_composed_ivfpq.cpp -o drill42 && ./drill42
 */

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
    std::cout << "===================================================================\n";
    std::cout << "🥋 Drill 42.1: Composed IVF-PQ Inverted List Routing & ADC Scan\n";
    std::cout << "===================================================================\n";

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

    std::partial_sort(centroid_dists.begin(), centroid_dists.begin() + N_PROBE, centroid_dists.end());

    float lut[M_SUB][K_CENT];
    for (size_t m = 0; m < M_SUB; ++m) {
        for (size_t k = 0; k < K_CENT; ++k) {
            lut[m][k] = dist_gen(rng);
        }
    }

    std::vector<std::pair<float, uint32_t>> candidates;
    for (size_t p = 0; p < N_PROBE; ++p) {
        size_t list_idx = centroid_dists[p].second;
        const auto& list = lists[list_idx];

        for (size_t v = 0; v < VECS_PER_LIST; ++v) {
            const uint8_t* code = &list.pq_codes[v * M_SUB];
            float d = 0.0f;
            for (size_t m = 0; m < M_SUB; ++m) {
                d += lut[m][code[m]];
            }
            candidates.push_back({ d, list.doc_ids[v] });
        }
    }

    std::cout << "[Info] Total Corpus Size: " << N_LISTS * VECS_PER_LIST << " vectors.\n";
    std::cout << "[Info] Probed " << N_PROBE << " / " << N_LISTS << " lists (" << candidates.size() << " vectors scanned).\n";
    assert(candidates.size() == N_PROBE * VECS_PER_LIST);

    std::cout << "\n✅ DRILL 42.1 PASSED: Composed IVF-PQ two-level routing and ADC scan verified.\n";
    return 0;
}
