// ==============================================================================
// 🥋 Drill: Generational Handle Pattern: Detecting Stale Observers
//
// 📖 READING SOURCES:
// - Nystrom: Game Programming Patterns (Dirty Flag & Type Object)
// - Actor Frameworks: Generational Handles
//
// 🎯 CORE LESSON:
// 1. Generational handles combine an index and a generation counter (`uint32_t`).
// 2. When an object is freed/reallocated, the generation counter increments.
// 3. Prevents use-after-free bugs without the runtime overhead of `std::weak_ptr`.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_64_day038_mem_observer_token_generation.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <vector>
#include <cstdint>
#include <cassert>

struct Handle {
    uint32_t index;
    uint32_t generation;
};

class SlotMap {
    struct Slot {
        int value;
        uint32_t generation{1};
        bool active{false};
    };

public:
    Handle insert(int val) {
        for (size_t i = 0; i < slots_.size(); ++i) {
            if (!slots_[i].active) {
                slots_[i].value = val;
                slots_[i].active = true;
                return Handle{static_cast<uint32_t>(i), slots_[i].generation};
            }
        }
        slots_.push_back(Slot{val, 1, true});
        return Handle{static_cast<uint32_t>(slots_.size() - 1), 1};
    }

    void remove(Handle h) {
        if (h.index < slots_.size() && slots_[h.index].active && slots_[h.index].generation == h.generation) {
            slots_[h.index].active = false;
            slots_[h.index].generation++; // Invalidate stale handles!
        }
    }

    int* get(Handle h) {
        if (h.index < slots_.size() && slots_[h.index].active && slots_[h.index].generation == h.generation) {
            return &slots_[h.index].value;
        }
        return nullptr; // Stale handle safely detected!
    }

private:
    std::vector<Slot> slots_;
};

int main() {
    std::cout << "--- Drill 64: Generational Handles ---\n\n";

    SlotMap map;
    Handle h1 = map.insert(42);
    assert(map.get(h1) != nullptr && *map.get(h1) == 42);

    map.remove(h1);

    // Stale access safely rejected
    assert(map.get(h1) == nullptr && "Stale generational handle must return nullptr!");

    std::cout << "\n✓ Drill 64 Passed: Generational handle prevented stale access!\n";
    return 0;
}
