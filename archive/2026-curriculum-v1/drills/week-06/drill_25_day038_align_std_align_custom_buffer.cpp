// ==============================================================================
// 🥋 Drill: Carving Aligned Sub-Buffers with std::align
//
// 📖 READING SOURCES:
// - cppreference: std::align
// - Stroustrup: The C++ Programming Language (Ch 11: Pointers, Arrays, and References)
//
// 🎯 CORE LESSON:
// 1. `std::align` adjusts a pointer to satisfy an alignment requirement inside an arbitrary buffer.
// 2. It updates both the pointer and the remaining space in the buffer.
// 3. Returns `nullptr` if the remaining space is insufficient to satisfy alignment plus size.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_25_day038_align_std_align_custom_buffer.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <memory>
#include <cstdint>
#include <cassert>

int main() {
    std::cout << "--- Drill 25: std::align Buffer Carving ---\n\n";

    alignas(64) char raw_storage[256];
    void* ptr = raw_storage + 3; // Intentionally unaligned
    size_t space = sizeof(raw_storage) - 3;

    constexpr size_t desired_alignment = 32;
    constexpr size_t allocation_size = 64;

    void* aligned_ptr = std::align(desired_alignment, allocation_size, ptr, space);
    assert(aligned_ptr != nullptr);
    assert(reinterpret_cast<uintptr_t>(aligned_ptr) % desired_alignment == 0);

    std::cout << "Successfully carved 32-byte aligned 64-byte buffer.\n";
    std::cout << "\n✓ Drill 25 Passed: std::align carved aligned sub-buffer!\n";
    return 0;
}
