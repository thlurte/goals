// ==============================================================================
// 🥋 Drill: Contiguous Posting List Layout without Pointer Indirection
//
// 📖 READING SOURCES:
// - CS:APP (Ch 3.8: Array Allocation and Access)
// - Faiss: Inverted Lists (InvertedLists.h)
//
// 🎯 CORE LESSON:
// 1. Storing node pointers (`Node*`) introduces cache misses and memory overhead per entry.
// 2. Flexible layout places header `[count, capacity]` followed directly by raw contiguous vector codes.
// 3. Guarantees that scanning an IVF posting list is 100% sequential in cache.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_75_day038_align_flexible_array_posting_list.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <cassert>

struct PostingListHeader {
    uint32_t count;
    uint32_t capacity;
    uint8_t data[1]; // Flexible array start
};

PostingListHeader* create_posting_list(uint32_t capacity) {
    size_t total_bytes = sizeof(PostingListHeader) + (capacity - 1) * sizeof(uint8_t);
    void* mem = std::malloc(total_bytes);
    PostingListHeader* pl = static_cast<PostingListHeader*>(mem);
    pl->count = 0;
    pl->capacity = capacity;
    return pl;
}

int main() {
    std::cout << "--- Drill 75: Contiguous Posting List Memory Layout ---\n\n";

    PostingListHeader* pl = create_posting_list(64);
    for (uint32_t i = 0; i < 64; ++i) {
        pl->data[i] = static_cast<uint8_t>(i);
        pl->count++;
    }

    assert(pl->count == 64);
    assert(pl->data[63] == 63);

    std::free(pl);
    std::cout << "\n✓ Drill 75 Passed: Contiguous posting list layout verified!\n";
    return 0;
}
