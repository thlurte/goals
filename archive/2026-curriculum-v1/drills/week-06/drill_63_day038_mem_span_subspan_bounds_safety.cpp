// ==============================================================================
// 🥋 Drill: Zero-Copy Buffer Windowing with std::span and subspan
//
// 📖 READING SOURCES:
// - C++20 Standard: <span>
// - C++ Core Guidelines: F.24 (Use a span<T> to refer to a contiguous sequence)
//
// 🎯 CORE LESSON:
// 1. `std::span<T>` provides a bounds-safe view over contiguous memory without ownership.
// 2. `span.subspan(offset, count)` creates zero-copy slices for vector subspaces and batches.
// 3. Prevents pointer decay and eliminates the need to pass paired `(T* ptr, size_t len)` arguments.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_63_day038_mem_span_subspan_bounds_safety.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <span>
#include <vector>
#include <numeric>
#include <cassert>

float sum_subspace(std::span<const float> slice) {
    return std::accumulate(slice.begin(), slice.end(), 0.0f);
}

int main() {
    std::cout << "--- Drill 63: std::span Subspan Windowing ---\n\n";

    std::vector<float> full_vector(128, 1.0f);
    std::span<const float> view(full_vector);

    // Carve 4 subspaces of 32 dimensions each
    std::span<const float> sub0 = view.subspan(0, 32);
    std::span<const float> sub1 = view.subspan(32, 32);

    assert(sub0.size() == 32);
    assert(sub1.size() == 32);
    assert(sum_subspace(sub0) == 32.0f);
    assert(sum_subspace(sub1) == 32.0f);

    std::cout << "Subspaces windowed zero-copy with std::span::subspan.\n";
    std::cout << "\n✓ Drill 63 Passed: Bounds-safe span slicing verified!\n";
    return 0;
}
