#include <iostream>
#include <vector>
#include <cstdint>
#include <cassert>

// Drill 24.1: Cache-Line Isolation to prevent False Sharing (Pikus Ch 5)
// In multi-threaded vector ingestion/scanning, independent inverted list headers
// must never share the same 64-byte cache line.

struct UnalignedList {
    uint32_t count{0};
    float* data{nullptr};
};

struct alignas(64) CacheAlignedList {
    uint32_t count{0};
    float* data{nullptr};
};

int main() {
    std::cout << "--- Drill 24.1: Cache Line Alignment & False Sharing Guard ---\n\n";

    std::cout << "1. Unaligned Inverted List:\n";
    std::cout << "   sizeof(UnalignedList)  = " << sizeof(UnalignedList) << " bytes\n";
    std::cout << "   alignof(UnalignedList) = " << alignof(UnalignedList) << " bytes\n";
    std::cout << "   Lists per 64-byte line = " << (64 / sizeof(UnalignedList)) << " (High False Sharing Risk!)\n\n";

    std::cout << "2. Cache-Isolated Inverted List (alignas(64)):\n";
    std::cout << "   sizeof(CacheAlignedList)  = " << sizeof(CacheAlignedList) << " bytes\n";
    std::cout << "   alignof(CacheAlignedList) = " << alignof(CacheAlignedList) << " bytes\n";
    std::cout << "   Lists per 64-byte line   = " << (sizeof(CacheAlignedList) / 64) << " (Zero False Sharing)\n\n";

    assert(alignof(CacheAlignedList) == 64);
    std::cout << "✓ Drill Passed: Cache isolation verified.\n";
    return 0;
}
