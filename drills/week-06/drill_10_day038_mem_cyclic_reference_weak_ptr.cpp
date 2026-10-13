// ==============================================================================
// 🥋 Drill: Breaking Circular Reference Leaks with std::weak_ptr
//
// 📖 READING SOURCES:
// - Meyers: Effective Modern C++ (Item 20: Use std::weak_ptr for std::shared_ptr-like pointers that can dangle)
// - Stroustrup: The C++ Programming Language (Ch 34: Memory Management)
//
// 🎯 CORE LESSON:
// 1. Cyclic `std::shared_ptr` relationships (A -> B and B -> A) cause reference count leaks.
// 2. `std::weak_ptr` observes a `shared_ptr` without incrementing the strong reference count.
// 3. Calling `weak_ptr::lock()` yields a temporary `shared_ptr` or `nullptr` if the object has been destroyed.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_10_day038_mem_cyclic_reference_weak_ptr.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <memory>
#include <cassert>

struct Parent;

struct Child {
    int id;
    std::weak_ptr<Parent> parent; // Non-owning weak reference breaks cycle!

    explicit Child(int i) : id(i) {}
    ~Child() { std::cout << "[Child] Destroyed\n"; }
};

struct Parent {
    int id;
    std::shared_ptr<Child> child; // Owning reference

    explicit Parent(int i) : id(i) {}
    ~Parent() { std::cout << "[Parent] Destroyed\n"; }
};

int main() {
    std::cout << "--- Drill 10: Breaking Cyclic Reference with weak_ptr ---\n\n";

    {
        auto p = std::make_shared<Parent>(1);
        auto c = std::make_shared<Child>(2);

        p->child = c;
        c->parent = p;

        assert(p.use_count() == 1); // weak_ptr does NOT increment strong use_count
        assert(c.use_count() == 2);

        // Lock weak pointer to inspect parent
        if (auto parent_locked = c->parent.lock()) {
            assert(parent_locked->id == 1);
        }
    } // Both Parent and Child are cleanly destroyed!

    std::cout << "\n✓ Drill 10 Passed: Circular reference resolved with std::weak_ptr!\n";
    return 0;
}
