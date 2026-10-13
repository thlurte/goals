// ==============================================================================
// 🥋 Drill: Intrusive Reference Counting for Zero Control-Block Overhead
//
// 📖 READING SOURCES:
// - Boost: boost::intrusive_ptr documentation
// - Abrahams & Gurtovoy: C++ Template Metaprogramming
//
// 🎯 CORE LESSON:
// 1. Intrusive pointers embed reference counts directly inside the managed object.
// 2. Eliminates the separate control block allocation of `std::shared_ptr`.
// 3. Provides superior cache locality and allows creating a smart pointer from raw pointer anytime.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_16_day038_mem_intrusive_ref_counting.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <atomic>
#include <cassert>

class RefCountedBase {
public:
    RefCountedBase() : ref_count_(0) {}
    virtual ~RefCountedBase() = default;

    void add_ref() noexcept {
        ref_count_.fetch_add(1, std::memory_order_relaxed);
    }

    void release() noexcept {
        if (ref_count_.fetch_sub(1, std::memory_order_acq_rel) == 1) {
            delete this;
        }
    }

    int use_count() const noexcept {
        return ref_count_.load(std::memory_order_relaxed);
    }

private:
    std::atomic<int> ref_count_;
};

template <typename T>
class IntrusivePtr {
public:
    IntrusivePtr() : ptr_(nullptr) {}
    explicit IntrusivePtr(T* p) : ptr_(p) {
        if (ptr_) ptr_->add_ref();
    }

    ~IntrusivePtr() noexcept {
        if (ptr_) ptr_->release();
    }

    IntrusivePtr(const IntrusivePtr& other) : ptr_(other.ptr_) {
        if (ptr_) ptr_->add_ref();
    }

    IntrusivePtr& operator=(const IntrusivePtr& other) {
        if (ptr_ != other.ptr_) {
            if (ptr_) ptr_->release();
            ptr_ = other.ptr_;
            if (ptr_) ptr_->add_ref();
        }
        return *this;
    }

    T* get() const noexcept { return ptr_; }
    T* operator->() const noexcept { return ptr_; }

private:
    T* ptr_;
};

struct GraphNode : public RefCountedBase {
    int id;
    explicit GraphNode(int i) : id(i) {}
};

int main() {
    std::cout << "--- Drill 16: Intrusive Reference Counting ---\n\n";

    {
        IntrusivePtr<GraphNode> p1(new GraphNode(42));
        assert(p1->use_count() == 1);
        {
            IntrusivePtr<GraphNode> p2 = p1;
            assert(p1->use_count() == 2);
            assert(p2->id == 42);
        }
        assert(p1->use_count() == 1);
    }

    std::cout << "\n✓ Drill 16 Passed: Intrusive refcount managed without external control block!\n";
    return 0;
}
