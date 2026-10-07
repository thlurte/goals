// ==============================================================================
// 🥋 Drill 12 (Day 35.2): Fedor Pikus Ch 9 — Zero-Copy `std::span` Register ABI
//
// 📖 READING SOURCES:
// - Fedor Pikus: The Art of Writing Efficient Programs (Ch 9: Value Semantics & Span)
//
// 🎯 CORE LESSON:
// 1. System V AMD64 ABI: `std::span<const T>` is passed by value in 2 registers (`rdi`, `rsi`).
// 2. Zero-allocation subviews: `span.subspan(offset, count)` creates non-owning pointer slices.
// 3. Eliminates pointer indirection and heap traffic across nested function calls.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra drill_12_day035_span_register_abi.cpp -o drill12 && ./drill12
// ==============================================================================

#include <iostream>
#include <span>
#include <vector>
#include <cassert>

// TODO 1: Implement dot product over two non-owning std::span views
float dot_product_span(std::span<const float> a, std::span<const float> b) {
    assert(a.size() == b.size() && "Spans must have matching size");
    // [YOUR CODE HERE]
    return 0.0f;
}

int main() {
    std::cout << "--- Drill 12: Fedor Pikus Zero-Copy std::span Register ABI ---\n\n";

    std::vector<float> large_buffer = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f};

    // Create zero-copy subviews
    std::span<const float> full_view(large_buffer);
    std::span<const float> slice_a = full_view.subspan(0, 4); // [1, 2, 3, 4]
    std::span<const float> slice_b = full_view.subspan(4, 4); // [5, 6, 7, 8]

    float result = dot_product_span(slice_a, slice_b);
    // 1*5 + 2*6 + 3*7 + 4*8 = 5 + 12 + 21 + 32 = 70
    std::cout << "Span Dot Product: " << result << " (Expected: 70)\n";

    assert(result == 70.0f);
    std::cout << "✓ Drill 12 Passed: Zero-copy std::span views and subspan verified!\n";
    return 0;
}
