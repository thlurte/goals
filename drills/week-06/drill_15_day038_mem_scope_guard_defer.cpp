// ==============================================================================
// 🥋 Drill: Scope Guard & Defer Idiom for Transactional Rollback
//
// 📖 READING SOURCES:
// - Alexandrescu: Modern C++ Design (Ch 6: Generalized Functors & ScopeGuard)
// - C++ Core Guidelines: E.19 (Use a final_action object to express cleanup if no suitable RAII object exists)
//
// 🎯 CORE LESSON:
// 1. A Scope Guard runs an arbitrary cleanup callable when exiting scope.
// 2. A dismissible scope guard allows committing a transaction and canceling cleanup.
// 3. Guarantees that temporary side-effects are undone if an exception occurs.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_15_day038_mem_scope_guard_defer.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <utility>
#include <functional>
#include <cassert>

template <typename F>
class ScopeGuard {
public:
    explicit ScopeGuard(F&& fn) : fn_(std::forward<F>(fn)), active_(true) {}
    ~ScopeGuard() noexcept {
        if (active_) {
            fn_();
        }
    }

    ScopeGuard(const ScopeGuard&) = delete;
    ScopeGuard& operator=(const ScopeGuard&) = delete;

    void dismiss() noexcept { active_ = false; }

private:
    F fn_;
    bool active_;
};

template <typename F>
auto make_scope_guard(F&& fn) {
    return ScopeGuard<F>(std::forward<F>(fn));
}

int main() {
    std::cout << "--- Drill 15: Scope Guard / Defer Rollback ---\n\n";

    bool rolled_back = false;
    {
        auto guard = make_scope_guard([&] {
            rolled_back = true;
        });
        // Simulated failure: scope exits without dismiss()
    }
    assert(rolled_back == true && "Undismissed guard must trigger cleanup!");

    bool committed = false;
    {
        auto guard = make_scope_guard([&] {
            committed = false;
        });
        committed = true;
        guard.dismiss(); // Success: cancel rollback
    }
    assert(committed == true && "Dismissed guard must not execute cleanup!");

    std::cout << "\n✓ Drill 15 Passed: Scope guard transactional rollback verified!\n";
    return 0;
}
