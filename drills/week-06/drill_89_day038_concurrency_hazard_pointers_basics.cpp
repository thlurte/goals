// ==============================================================================
// 🥋 Drill: Hazard Pointers: Safe Memory Reclamation for Lock-Free Reads
//
// 📖 READING SOURCES:
// - Michael: Hazard Pointers: Safe Memory Reclamation for Lock-Free Objects (2004)
// - Williams: C++ Concurrency in Action (Ch 7.2.5)
//
// 🎯 CORE LESSON:
// 1. Readers publish a pointer to a thread-local 'Hazard Pointer' slot before reading.
// 2. Reclaiming threads scan all hazard pointers before deleting any node.
// 3. If a hazard pointer matches the node, deletion is deferred until readers finish.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_89_day038_concurrency_hazard_pointers_basics.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <atomic>
#include <cassert>

constexpr size_t MaxHazardPointers = 4;
std::atomic<void*> g_hazard_ptrs[MaxHazardPointers];

void set_hazard(size_t thread_id, void* ptr) {
    g_hazard_ptrs[thread_id].store(ptr, std::memory_order_release);
}

void clear_hazard(size_t thread_id) {
    g_hazard_ptrs[thread_id].store(nullptr, std::memory_order_release);
}

bool is_hazardous(void* ptr) {
    for (size_t i = 0; i < MaxHazardPointers; ++i) {
        if (g_hazard_ptrs[i].load(std::memory_order_acquire) == ptr) {
            return true;
        }
    }
    return false;
}

int main() {
    std::cout << "--- Drill 89: Hazard Pointers Basics ---\n\n";

    int target_node = 42;
    set_hazard(0, &target_node);

    assert(is_hazardous(&target_node) == true && "Hazardous pointer must not be deleted!");

    clear_hazard(0);
    assert(is_hazardous(&target_node) == false && "Cleared pointer can now safely be reclaimed!");

    std::cout << "\n✓ Drill 89 Passed: Hazard pointer protection verified!\n";
    return 0;
}
