// ==============================================================================
// 🥋 Drill: alignas Specifier: 32-Byte (AVX2) and 64-Byte (Cache Line) Alignment
//
// 📖 READING SOURCES:
// - Intel 64 and IA-32 Architectures Optimization Reference Manual (Ch 3.6)
// - cppreference: alignas specifier
//
// 🎯 CORE LESSON:
// 1. `alignas(N)` requests memory alignment to an $N$-byte boundary.
// 2. AVX2 256-bit SIMD registers require 32-byte alignment for aligned load instructions.
// 3. 64-byte alignment matches the L1/L2 cache line size and AVX-512 vector registers.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_22_day038_align_alignas_specifier.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <cstddef>
#include <cstdint>
#include <cassert>

struct alignas(32) AVX2Vector {
    float values[8]; // Exactly 32 bytes aligned to 32 bytes
};

struct alignas(64) CacheLineAlignedVector {
    float values[16]; // Exactly 64 bytes aligned to 64 bytes
};

int main() {
    std::cout << "--- Drill 22: alignas Specifier ---\n\n";

    AVX2Vector v32;
    CacheLineAlignedVector v64;

    uintptr_t addr32 = reinterpret_cast<uintptr_t>(&v32);
    uintptr_t addr64 = reinterpret_cast<uintptr_t>(&v64);

    std::cout << "alignof(AVX2Vector): " << alignof(AVX2Vector) << ", addr % 32 = " << (addr32 % 32) << "\n";
    std::cout << "alignof(CacheLineAlignedVector): " << alignof(CacheLineAlignedVector) << ", addr % 64 = " << (addr64 % 64) << "\n";

    assert(addr32 % 32 == 0 && "AVX2Vector must be 32-byte aligned!");
    assert(addr64 % 64 == 0 && "CacheLineAlignedVector must be 64-byte aligned!");

    std::cout << "\n✓ Drill 22 Passed: alignas(32) and alignas(64) verified!\n";
    return 0;
}
