// ==============================================================================
// 🥋 Drill 28.1: Modern C++20 std::span & Zero-Allocation View Semantics
//
// 🚀 RUN COMMAND:
// g++ -O3 -march=native -std=c++20 day028_drill_01_span_zero_alloc.cpp -o drill28_1 && ./drill28_1
//
// CONTEXT:
// Vector search engines process millions of queries per second. Passing vectors
// as `std::vector<float>` creates heap copies. Using raw pointers loses size bounds.
//
// C++ SYSTEMS LESSON:
// - `std::span<const float>` provides a zero-overhead (pointer + size) non-owning view.
// - Compatible with std::vector, C-arrays, and memory-mapped buffers with 0 allocations.
// - Compiles directly to pointer arithmetic in assembly.
// ==============================================================================

#include <iostream>
#include <vector>
#include <span>
#include <numeric>
#include <cassert>

// TODO 1: Implement dot product accepting non-owning std::span views
// Function: dot_product_span(std::span<const float> a, std::span<const float> b)
inline float dot_product_span(std::span<const float> a, std::span<const float> b) {
    // 1. Assert that a.size() == b.size()
    // 2. Compute sum of a[i] * b[i]
    // 3. Return the float sum
    // [YOUR CODE HERE]
    return 0.0f;
}

int main() {
    std::cout << "--- Drill 28.1: std::span Zero-Allocation View Semantics ---\n\n";

    // 1. View over std::vector
    std::vector<float> vec_a = {1.0f, 2.0f, 3.0f, 4.0f};
    std::vector<float> vec_b = {0.5f, 1.0f, 1.5f, 2.0f};

    // TODO 2: Call dot_product_span passing vec_a and vec_b (implicit conversion to span)
    float dot1 = 0.0f;
    // [YOUR CODE HERE]
    std::cout << "1. Span over std::vector dot product: " << dot1 << "\n";

    // 2. View over raw stack C-array (Zero allocations!)
    const float raw_a[4] = {2.0f, 2.0f, 2.0f, 2.0f};
    const float raw_b[4] = {3.0f, 3.0f, 3.0f, 3.0f};

    // TODO 3: Call dot_product_span with std::span wrapping the raw arrays
    float dot2 = 0.0f;
    // [YOUR CODE HERE]
    std::cout << "2. Span over raw C-array dot product: " << dot2 << "\n\n";

    // -------------------------------------------------------------------------
    // Verification (Do not modify)
    // -------------------------------------------------------------------------
    assert(dot1 == 15.0f);
    assert(dot2 == 24.0f);
    std::cout << "✓ Drill Passed: std::span demonstrated seamless zero-copy views.\n";
    return 0;
}
