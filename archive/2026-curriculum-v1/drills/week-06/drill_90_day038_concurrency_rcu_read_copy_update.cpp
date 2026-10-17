// ==============================================================================
// 🥋 Drill: Read-Copy-Update (RCU) Idiom for High-Read Vector Indexes
//
// 📖 READING SOURCES:
// - McKenney: Read-Copy Update (Linux Kernel Documentation)
// - Williams: C++ Concurrency in Action
//
// 🎯 CORE LESSON:
// 1. Readers read an immutable snapshot via atomic pointer with zero lock overhead.
// 2. Writers make a modified copy of the data structure and atomically swap the active pointer.
// 3. The old version is reclaimed only after all existing readers exit their grace period.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_90_day038_concurrency_rcu_read_copy_update.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <atomic>
#include <vector>
#include <thread>
#include <cassert>

struct VectorConfig {
    int ef_search;
    int nprobe;
};

class RCUConfigManager {
public:
    explicit RCUConfigManager(VectorConfig initial)
        : active_(new VectorConfig(initial)) {}

    ~RCUConfigManager() {
        delete active_.load();
    }

    // Zero-overhead lock-free read
    VectorConfig get() const {
        return *active_.load(std::memory_order_acquire);
    }

    // Update via Copy-and-Atomic-Swap
    void update(VectorConfig new_cfg) {
        VectorConfig* new_ptr = new VectorConfig(new_cfg);
        VectorConfig* old_ptr = active_.exchange(new_ptr, std::memory_order_acq_rel);

        // In production RCU: synchronize_rcu() grace period wait before delete
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
        delete old_ptr;
    }

private:
    std::atomic<VectorConfig*> active_;
};

int main() {
    std::cout << "--- Drill 90: Read-Copy-Update (RCU) Idiom ---\n\n";

    RCUConfigManager mgr(VectorConfig{64, 16});
    assert(mgr.get().ef_search == 64);

    mgr.update(VectorConfig{128, 32});
    assert(mgr.get().ef_search == 128);
    assert(mgr.get().nprobe == 32);

    std::cout << "\n✓ Drill 90 Passed: RCU atomic swap and deferred update verified!\n";
    return 0;
}
