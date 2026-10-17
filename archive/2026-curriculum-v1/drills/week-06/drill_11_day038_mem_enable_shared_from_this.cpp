// ==============================================================================
// 🥋 Drill: std::enable_shared_from_this Safe Pointer Generation
//
// 📖 READING SOURCES:
// - Meyers: Effective Modern C++ (Item 19: std::enable_shared_from_this)
// - cppreference: std::enable_shared_from_this
//
// 🎯 CORE LESSON:
// 1. Creating `std::shared_ptr<T>(this)` creates a second independent control block, causing double-free.
// 2. Inheriting from `std::enable_shared_from_this<T>` allows `shared_from_this()` to reuse the existing control block.
// 3. `shared_from_this()` must only be invoked after the object has already been owned by a `std::shared_ptr`.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_11_day038_mem_enable_shared_from_this.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <memory>
#include <cassert>

class Service : public std::enable_shared_from_this<Service> {
public:
    int id;
    explicit Service(int i) : id(i) {}

    std::shared_ptr<Service> get_handle() {
        return shared_from_this(); // Shares existing control block
    }
};

int main() {
    std::cout << "--- Drill 11: std::enable_shared_from_this ---\n\n";

    auto s1 = std::make_shared<Service>(42);
    assert(s1.use_count() == 1);

    auto s2 = s1->get_handle();
    assert(s1.use_count() == 2);
    assert(s2.use_count() == 2);
    assert(s1.get() == s2.get());

    std::cout << "\n✓ Drill 11 Passed: shared_from_this avoided double control block!\n";
    return 0;
}
