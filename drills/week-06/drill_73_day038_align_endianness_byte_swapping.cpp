// ==============================================================================
// 🥋 Drill: Endianness Detection & std::byteswap / __builtin_bswap32
//
// 📖 READING SOURCES:
// - C++23 std::byteswap & std::endian
// - CS:APP (Ch 2.1.3: Byte Ordering)
//
// 🎯 CORE LESSON:
// 1. x86-64 is Little-Endian (Least Significant Byte at lowest memory address).
// 2. Network protocols and legacy datasets often store integers in Big-Endian format.
// 3. `__builtin_bswap32` compiles to a single hardware `BSWAP` instruction.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_73_day038_align_endianness_byte_swapping.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <bit>
#include <cstdint>
#include <cassert>

int main() {
    std::cout << "--- Drill 73: Endianness & Byte Swapping ---\n\n";

    // Verify system endianness
    static_assert(std::endian::native == std::endian::little, "x86-64 is Little-Endian!");

    uint32_t original = 0x12345678;
    uint32_t swapped = __builtin_bswap32(original);

    assert(swapped == 0x78563412);
    assert(__builtin_bswap32(swapped) == original);

    std::cout << "0x12345678 byte-swapped to: 0x" << std::hex << swapped << std::dec << "\n";
    std::cout << "\n✓ Drill 73 Passed: Byte swapping verified!\n";
    return 0;
}
