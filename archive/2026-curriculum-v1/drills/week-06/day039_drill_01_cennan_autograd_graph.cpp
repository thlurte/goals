// ==============================================================================
// 🥋 Cennan Drill 39.1: C++ Computational Graph Node & Topological Backward
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra day039_drill_01_cennan_autograd_graph.cpp -o drill39 && ./drill39
//
// CONTEXT:
// In `cennan`, automatic differentiation constructs a Directed Acyclic Graph (DAG)
// of `Node` shared pointers. Calling `backward()` builds a topological order and executes
// backward functions in reverse dependency order.
//
// C++ CONCEPTS TO PRACTICE:
// 1. `std::shared_ptr<Node>` and `std::vector<std::shared_ptr<Node>>` parent dependencies.
// 2. `std::function<void()>` backward closures capturing input pointers.
// 3. Topological sort using `std::unordered_set<Node*>` visited set.
// ==============================================================================

#include <iostream>
#include <vector>
#include <memory>
#include <functional>
#include <unordered_set>
#include <cmath>
#include <cassert>

struct Node : public std::enable_shared_from_this<Node> {
    float data{0.0f};
    float grad{0.0f};
    std::vector<std::shared_ptr<Node>> parents;
    std::function<void()> backward_fn{[](){}};

    Node(float val) : data(val), grad(0.0f) {}
    Node(float val, std::vector<std::shared_ptr<Node>> deps, std::function<void()> bwd)
        : data(val), grad(0.0f), parents(std::move(deps)), backward_fn(std::move(bwd)) {}

    // TODO 1: Implement topological backward traversal
    // Steps:
    // 1. Traverse DAG with DFS: collect nodes into `std::vector<std::shared_ptr<Node>> topo`.
    // 2. Set this->grad = 1.0f (seed gradient).
    // 3. Loop in reverse order: for (auto it = topo.rbegin(); it != topo.rend(); ++it) (*it)->backward_fn();
    void backward() {
        // [YOUR CODE HERE]
    }
};

// TODO 2: Overload operator+ for Node pointers
inline std::shared_ptr<Node> operator+(const std::shared_ptr<Node>& a, const std::shared_ptr<Node>& b) {
    // [YOUR CODE HERE]
    // 1. Compute out_val = a->data + b->data
    // 2. Create backward closure: a->grad += out->grad; b->grad += out->grad
    // 3. Return std::make_shared<Node>(out_val, {a, b}, bwd)
    return nullptr;
}

// TODO 3: Overload operator* for Node pointers
inline std::shared_ptr<Node> operator*(const std::shared_ptr<Node>& a, const std::shared_ptr<Node>& b) {
    // [YOUR CODE HERE]
    // 1. Compute out_val = a->data * b->data
    // 2. Create backward closure: a->grad += b->data * out->grad; b->grad += a->data * out->grad
    // 3. Return std::make_shared<Node>(out_val, {a, b}, bwd)
    return nullptr;
}

int main() {
    std::cout << "--- Drill 39.1: Cennan C++ DAG Autograd Engine ---\n\n";

    auto a = std::make_shared<Node>(3.0f);
    auto b = std::make_shared<Node>(-4.0f);
    auto c = std::make_shared<Node>(2.0f);

    // Expression: y = (a * b) + c  ->  (3 * -4) + 2 = -10
    auto ab = a * b;
    auto y = ab + c;

    assert(y != nullptr && "Expression failed to construct!");
    std::cout << "Forward Value y: " << y->data << " (Expected: -10)\n";
    assert(std::abs(y->data - (-10.0f)) < 1e-4);

    y->backward();

    // dy/da = b = -4
    // dy/db = a = 3
    // dy/dc = 1
    std::cout << "da: " << a->grad << " (Expected: -4)\n";
    std::cout << "db: " << b->grad << " (Expected: 3)\n";
    std::cout << "dc: " << c->grad << " (Expected: 1)\n";

    assert(std::abs(a->grad - (-4.0f)) < 1e-4);
    assert(std::abs(b->grad - 3.0f) < 1e-4);
    assert(std::abs(c->grad - 1.0f) < 1e-4);

    std::cout << "\n✓ Drill Passed: C++ DAG autograd engine verified!\n";
    return 0;
}
