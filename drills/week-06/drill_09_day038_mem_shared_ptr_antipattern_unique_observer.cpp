// ==============================================================================
// 🥋 Drill: std::shared_ptr Anti-Pattern: Replacing Overused shared_ptr with unique_ptr + Observer
//
// 📖 READING SOURCES:
// - Meyers: Effective Modern C++ (Item 19: When shared_ptr is an anti-pattern)
// - Sean Parent: Better Code - Concurrency & Performance
//
// 🎯 CORE LESSON:
// 1. Defaulting to `std::shared_ptr` creates unclear ownership semantics and atomic refcount contention.
// 2. The canonical pattern is single ownership (`std::unique_ptr`) and non-owning observation (`T*` or `T&`).
// 3. Raw pointer observers are zero-overhead and clearly communicate: 'I do NOT own or manage this lifetime'.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_09_day038_mem_shared_ptr_antipattern_unique_observer.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <memory>
#include <vector>
#include <cassert>

class VectorIndex {
public:
    int id;
    explicit VectorIndex(int id) : id(id) {}
    void search() const { /* Fast search */ }
};

// Good architecture: Engine owns indexes uniquely; queries observe via raw pointer
class Engine {
public:
    void add_index(std::unique_ptr<VectorIndex> idx) {
        indexes_.push_back(std::move(idx));
    }

    // Observer: non-owning pointer
    VectorIndex* get_index(size_t i) const {
        assert(i < indexes_.size());
        return indexes_[i].get();
    }

private:
    std::vector<std::unique_ptr<VectorIndex>> indexes_;
};

int main() {
    std::cout << "--- Drill 09: unique_ptr Ownership with Raw Observer ---\n\n";

    Engine engine;
    engine.add_index(std::make_unique<VectorIndex>(1001));
    engine.add_index(std::make_unique<VectorIndex>(1002));

    VectorIndex* obs = engine.get_index(0);
    assert(obs != nullptr);
    assert(obs->id == 1001);

    std::cout << "Observed index ID: " << obs->id << " without shared_ptr overhead.\n";
    std::cout << "\n✓ Drill 09 Passed: Single ownership + observer pattern verified!\n";
    return 0;
}
