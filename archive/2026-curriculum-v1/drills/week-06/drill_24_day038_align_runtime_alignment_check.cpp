// ==============================================================================
// 🥋 Drill: Runtime Alignment Assertions via Bitwise Masks
//
// 📖 READING SOURCES:
// - Hacker's Delight: Powers of 2 and Alignment
// - Ulrich Drepper: What Every Programmer Should Know About Memory
//
// 🎯 CORE LESSON:
// 1. For power-of-two alignment $A$, address $P$ is aligned if and only if $(P \ \& \ (A - 1)) == 0$.
// 2. Bitwise AND is significantly faster than modulus (`%`) division in production code paths.
// 3. Always assert SIMD pointer alignment before invoking aligned load intrinsics.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_24_day038_align_runtime_alignment_check.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <cstdint>
#include <cassert>

inline bool is_aligned(const void* ptr, size_t alignment) noexcept {
    assert((alignment & (alignment - 1)) == 0 && "Alignment must be a power of two!");
    return (reinterpret_cast<uintptr_t>(ptr) & (alignment - 1)) == 0;
}

int main() {
    std::cout << "--- Drill 24: Runtime Pointer Alignment Verification ---\n\n";

    uint8_t buffer[128];
    uint8_t* unaligned_ptr = &buffer[1];

    assert(!is_aligned(unaligned_ptr, 16));
    assert(!is_aligned(unaligned_ptr, 32));
    assert(!is_aligned(unaligned_ptr, 64));

    // Find first 64-byte aligned offset
    uintptr_t addr = reinterpret_cast<uintptr_t>(buffer);
    size_t offset = (64 - (addr & 63)) & 63;
    uint8_t* aligned_ptr = buffer + offset;

    assert(is_aligned(aligned_ptr, 64));
    std::cout << "Found aligned pointer with bitwise mask at offset: " << offset << "\n";

    std::cout << "\n✓ Drill 24 Passed: Bitwise alignment check verified!\n";
    return 0;
}
