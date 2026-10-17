// ==============================================================================
// 🥋 Drill: Pimpl Idiom with std::unique_ptr & Complete Type Destructor
//
// 📖 READING SOURCES:
// - Meyers: Effective Modern C++ (Item 22: When using the Pimpl Idiom, define special member functions in the implementation file)
// - Sutter: Exceptional C++ (Items 26-30: The Pimpl Idiom)
//
// 🎯 CORE LESSON:
// 1. The Pimpl (Pointer to implementation) idiom hides implementation details and speeds up builds.
// 2. `std::unique_ptr<Impl>` requires `Impl` to be a complete type where the destructor is defined.
// 3. Defining `~MyClass()` in the `.h` file with an incomplete `Impl` causes a compiler error.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_20_day038_mem_pimpl_unique_ptr_destructor.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <memory>
#include <cassert>

// Simulated Header
class SearchEngine {
public:
    SearchEngine();
    ~SearchEngine(); // Must be defined where Impl is complete!

    void index(int doc_id);
    int doc_count() const;

private:
    struct Impl;
    std::unique_ptr<Impl> pimpl_;
};

// Simulated Implementation
struct SearchEngine::Impl {
    int count{0};
    void add(int id) { (void)id; count++; }
};

SearchEngine::SearchEngine() : pimpl_(std::make_unique<Impl>()) {}
SearchEngine::~SearchEngine() = default; // Defined after Impl definition!

void SearchEngine::index(int doc_id) { pimpl_->add(doc_id); }
int SearchEngine::doc_count() const { return pimpl_->count; }

int main() {
    std::cout << "--- Drill 20: Pimpl Idiom with std::unique_ptr ---\n\n";

    SearchEngine engine;
    engine.index(101);
    engine.index(102);
    assert(engine.doc_count() == 2);

    std::cout << "\n✓ Drill 20 Passed: Pimpl idiom correctly compiles with complete destructor!\n";
    return 0;
}
