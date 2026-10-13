// ==============================================================================
// 🥋 Drill: 4-Bit Quantized Nibble Indexing & Bitshift Offset Calculations
//
// 📖 READING SOURCES:
// - Hennessy & Patterson: Appendix B (Quantization & Memory Hierarchy)
// - Faiss / ScaNN: 4-Bit Packed Code Layout
//
// 🎯 CORE LESSON:
// 1. 4-bit quantization packs two nibbles into each byte: `byte_idx = dim / 2`.
// 2. Even indices occupy the high nibble (`byte >> 4`), odd indices occupy the low nibble (`byte & 0x0F`).
// 3. Calculations must avoid out-of-bounds byte reads when navigating arbitrary dimension indices.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_34_day038_align_sq4_nibble_offset_math.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <vector>
#include <cstdint>
#include <cassert>

inline uint8_t get_sq4_nibble(const uint8_t* packed, size_t dim_idx) {
    size_t byte_idx = dim_idx / 2;
    uint8_t b = packed[byte_idx];
    return (dim_idx % 2 == 0) ? (b >> 4) : (b & 0x0F);
}

inline void set_sq4_nibble(uint8_t* packed, size_t dim_idx, uint8_t val) {
    size_t byte_idx = dim_idx / 2;
    if (dim_idx % 2 == 0) {
        packed[byte_idx] = (packed[byte_idx] & 0x0F) | (val << 4);
    } else {
        packed[byte_idx] = (packed[byte_idx] & 0xF0) | (val & 0x0F);
    }
}

int main() {
    std::cout << "--- Drill 34: 4-Bit Nibble Offset Math ---\n\n";

    uint8_t packed[4] = {0}; // Holds 8 4-bit values

    set_sq4_nibble(packed, 0, 0xA); // 10
    set_sq4_nibble(packed, 1, 0x5); // 5
    set_sq4_nibble(packed, 7, 0xF); // 15

    assert(get_sq4_nibble(packed, 0) == 0xA);
    assert(get_sq4_nibble(packed, 1) == 0x5);
    assert(get_sq4_nibble(packed, 7) == 0xF);
    assert(get_sq4_nibble(packed, 2) == 0x0);

    std::cout << "\n✓ Drill 34 Passed: Nibble bit-shifting math operational!\n";
    return 0;
}
