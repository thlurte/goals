// ==============================================================================
// 🥋 Drill: Use-After-Free & Debug Pointer Poisoning (0xDEADBEEF)
//
// 📖 READING SOURCES:
// - AddressSanitizer: A Fast Memory Error Detector (Serebryany et al.)
// - Meyers: Effective Modern C++ (Item 20: Weak pointers and dangling detection)
//
// 🎯 CORE LESSON:
// 1. Reading memory after `delete` is Undefined Behavior and may silently return garbage or crash.
// 2. Debug allocators overwrite freed memory with poison values (e.g., `0xDEADBEEF`) to catch use-after-free.
// 3. Always set raw pointers to `nullptr` immediately after `delete`.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_53_day038_mem_use_after_free_poisoning.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <cstdint>
#include <cstring>
#include <cassert>

struct VectorNode {
    uint32_t doc_id;
    float score;
};

void safe_release(VectorNode*& ptr) {
    if (ptr) {
        // Debug poisoning: overwrite with garbage to catch dangling reads
        std::memset(ptr, 0xDE, sizeof(VectorNode));
        delete ptr;
        ptr = nullptr; // Nullify pointer immediately
    }
}

int main() {
    std::cout << "--- Drill 53: Use-After-Free Prevention & Poisoning ---\n\n";

    VectorNode* node = new VectorNode{101, 0.95f};
    assert(node->doc_id == 101);

    safe_release(node);

    // Guaranteed safe: pointer is null, preventing use-after-free
    assert(node == nullptr);

    std::cout << "\n✓ Drill 53 Passed: Safe release and pointer nullification verified!\n";
    return 0;
}
