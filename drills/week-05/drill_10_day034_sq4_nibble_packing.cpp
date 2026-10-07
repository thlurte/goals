// ==============================================================================
// 🥋 Drill 10 (Day 34.2): H&P App B.1–B.3 — SQ4 4-Bit Packing & Cache Line Fitting
//
// 📖 READING SOURCES:
// - Hennessy & Patterson: Computer Architecture (6th Ed, Appendix B.1–B.3)
//
// 🎯 CORE LESSON:
// 1. Pack two 4-bit integers [0..15] into a single 8-bit byte (`uint8_t`).
// 2. High nibble: `(val0 << 4)`, Low nibble: `(val1 & 0x0F)`.
// 3. Compression: 128 dimensions compress from 512 bytes (FP32) to exactly 64 bytes (1 cache line!).
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra drill_10_day034_sq4_nibble_packing.cpp -o drill10 && ./drill10
// ==============================================================================

#include <iostream>
#include <vector>
#include <cstdint>
#include <cassert>

// TODO 1: Pack raw 4-bit values (in range 0..15) into byte array
void pack_sq4(const uint8_t* raw_nibbles, uint8_t* packed_out, size_t dim) {
    // [YOUR CODE HERE]
}

// TODO 2: Unpack byte array into raw 4-bit values
void unpack_sq4(const uint8_t* packed_in, uint8_t* raw_nibbles_out, size_t dim) {
    // [YOUR CODE HERE]
}

int main() {
    std::cout << "--- Drill 10: SQ4 4-Bit Nibble Bit-Packing ---\n\n";

    constexpr size_t D = 128;
    std::vector<uint8_t> original(D);
    for (size_t i = 0; i < D; ++i) {
        original[i] = static_cast<uint8_t>(i % 16);
    }

    std::vector<uint8_t> packed(D / 2);
    pack_sq4(original.data(), packed.data(), D);

    std::vector<uint8_t> recovered(D);
    unpack_sq4(packed.data(), recovered.data(), D);

    assert(original == recovered && "Unpacked SQ4 codes must match original input!");
    assert(packed.size() == 64 && "128 dims must fit in exactly 64 bytes (1 cache line)!");

    std::cout << "✓ Drill 10 Passed: SQ4 nibble packing and unpacking verified!\n";
    return 0;
}
