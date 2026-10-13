// ==============================================================================
// 🥋 Drill: Tagged Pointers: Preventing ABA with Version Counters
//
// 📖 READING SOURCES:
// - Herlihy & Shavit: The Art of Multiprocessor Programming (Ch 10)
// - Double-Word CAS (CMPXCHG16B)
//
// 🎯 CORE LESSON:
// 1. A Tagged Pointer packs a 16-bit or 32-bit modification sequence counter with the pointer.
// 2. Every write increments the sequence counter.
// 3. Even if pointer address $A$ is recycled, the sequence counter differs, causing stale CAS to safely fail.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_87_day038_concurrency_tagged_pointer_aba_fix.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <cstdint>
#include <cassert>

struct TaggedPointer {
    uintptr_t ptr : 48;
    uintptr_t tag : 16;
};

inline uint64_t pack(void* p, uint16_t tag) {
    return (reinterpret_cast<uint64_t>(p) & 0xFFFFFFFFFFFFULL) | (static_cast<uint64_t>(tag) << 48);
}

inline void* unpack_ptr(uint64_t val) {
    return reinterpret_cast<void*>(val & 0xFFFFFFFFFFFFULL);
}

inline uint16_t unpack_tag(uint64_t val) {
    return static_cast<uint16_t>(val >> 48);
}

int main() {
    std::cout << "--- Drill 87: Tagged Pointers for ABA Prevention ---\n\n";

    int dummy = 42;
    uint64_t v1 = pack(&dummy, 1);
    uint64_t v2 = pack(&dummy, 2);

    assert(v1 != v2 && "Identical pointers with distinct tags must NOT be equal!");
    assert(unpack_ptr(v1) == &dummy);
    assert(unpack_tag(v1) == 1);
    assert(unpack_tag(v2) == 2);

    std::cout << "\n✓ Drill 87 Passed: Tagged pointer sequence increment verified!\n";
    return 0;
}
