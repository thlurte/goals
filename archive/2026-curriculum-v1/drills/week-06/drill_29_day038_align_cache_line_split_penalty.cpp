// ==============================================================================
// 🥋 Drill: Cache Line Split: Detecting SIMD Loads Crossing 64-Byte Boundaries
//
// 📖 READING SOURCES:
// - Intel 64 and IA-32 Optimization Reference Manual (Section 3.6.2: Cache Line Splits)
// - CS:APP (Ch 6: Memory Hierarchy)
//
// 🎯 CORE LESSON:
// 1. L1 Data Cache is fetched in 64-byte chunks.
// 2. A 32-byte SIMD load that straddles a 64-byte boundary must access two separate cache lines.
// 3. Alignment guarantees that every 32-byte or 64-byte SIMD load never splits across cache boundaries.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_29_day038_align_cache_line_split_penalty.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <cstdint>
#include <cassert>

bool crosses_cache_line(const void* ptr, size_t load_bytes) {
    uintptr_t start = reinterpret_cast<uintptr_t>(ptr);
    uintptr_t end = start + load_bytes - 1;
    return (start / 64) != (end / 64);
}

int main() {
    std::cout << "--- Drill 29: Cache Line Split Detection ---\n\n";

    alignas(64) uint8_t buffer[128];

    // Address at offset 0: spans bytes [0..31] (within first 64-byte line)
    assert(!crosses_cache_line(buffer + 0, 32));

    // Address at offset 32: spans bytes [32..63] (within first 64-byte line)
    assert(!crosses_cache_line(buffer + 32, 32));

    // Address at offset 48: spans bytes [48..79] (crosses line boundary at byte 64!)
    assert(crosses_cache_line(buffer + 48, 32) && "Offset 48 must cross 64-byte cache line!");

    std::cout << "Cache line boundary crossing correctly detected!\n";
    std::cout << "\n✓ Drill 29 Passed: Cache line split mechanics verified!\n";
    return 0;
}
