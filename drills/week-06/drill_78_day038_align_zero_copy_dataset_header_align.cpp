// ==============================================================================
// 🥋 Drill: Zero-Copy Serialization Invariant Verification for Headers
//
// 📖 READING SOURCES:
// - CS:APP (Ch 3: Machine-Level Programs)
// - FlatBuffers: Zero-Copy Serialization Design
//
// 🎯 CORE LESSON:
// 1. Zero-copy serialization formats require header structs to be self-aligned.
// 2. Padding must be explicit (`uint32_t reserved`) rather than compiler-inserted.
// 3. Assertions verify `sizeof(Header) % 8 == 0` for cross-platform binary compatibility.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_78_day038_align_zero_copy_dataset_header_align.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <cstdint>
#include <cassert>

#pragma pack(push, 1)
struct PackedHeader {
    uint32_t magic;
    uint32_t version;
    uint32_t dimension;
    uint32_t count;
    uint64_t timestamp;
};
#pragma pack(pop)

int main() {
    std::cout << "--- Drill 78: Zero-Copy Dataset Header Alignment ---\n\n";

    assert(sizeof(PackedHeader) == 24);
    assert(offsetof(PackedHeader, magic) == 0);
    assert(offsetof(PackedHeader, timestamp) == 16);

    std::cout << "PackedHeader verified: sizeof=" << sizeof(PackedHeader) << " bytes.\n";
    std::cout << "\n✓ Drill 78 Passed: Header serialization invariants verified!\n";
    return 0;
}
