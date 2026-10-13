// ==============================================================================
// 🥋 Drill: Raw Byte Buffer Serialization via reinterpret_cast
//
// 📖 READING SOURCES:
// - CS:APP (Ch 3: Machine-Level Representation of Programs)
// - Meyers: Effective C++ (Item 27: Minimize casting)
//
// 🎯 CORE LESSON:
// 1. `reinterpret_cast<const uint8_t*>` treats structured types as raw byte sequences.
// 2. Essential for zero-copy socket transmission, disk serialization, and inverted index lists.
// 3. Only valid for TriviallyCopyable / POD types.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_26_day038_align_raw_byte_serialization_reinterpret.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <cstdint>
#include <vector>
#include <cstring>
#include <cassert>

struct VectorHeader {
    uint32_t magic;
    uint32_t dimension;
    uint64_t num_vectors;
};

int main() {
    std::cout << "--- Drill 26: Raw Byte Serialization via reinterpret_cast ---\n\n";

    VectorHeader out_hdr{0x56454353, 128, 1000000};
    std::vector<uint8_t> buffer(sizeof(VectorHeader));

    // Serialize to raw bytes
    const uint8_t* src_bytes = reinterpret_cast<const uint8_t*>(&out_hdr);
    std::memcpy(buffer.data(), src_bytes, sizeof(VectorHeader));

    // Deserialize from raw bytes
    const VectorHeader* in_hdr = reinterpret_cast<const VectorHeader*>(buffer.data());
    assert(in_hdr->magic == 0x56454353);
    assert(in_hdr->dimension == 128);
    assert(in_hdr->num_vectors == 1000000);

    std::cout << "Serialized and restored header: dim=" << in_hdr->dimension << "\n";
    std::cout << "\n✓ Drill 26 Passed: Raw byte serialization verified!\n";
    return 0;
}
