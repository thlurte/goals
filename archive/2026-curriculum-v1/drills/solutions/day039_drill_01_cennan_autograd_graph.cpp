// ==============================================================================
// 🥋 Cennan Drill 39.1: Solution
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

    void backward() {
        std::vector<std::shared_ptr<Node>> topo;
        std::unordered_set<Node*> visited;

        std::function<void(const std::shared_ptr<Node>&)> build_topo = [&](const std::shared_ptr<Node>& v) {
            if (visited.find(v.get()) == visited.end()) {
                visited.insert(v.get());
                for (const auto& child : v->parents) {
                    build_topo(child);
                }
                topo.push_back(v);
            }
        };

        build_topo(shared_from_this());

        this->grad = 1.0f;
        for (auto it = topo.rbegin(); it != topo.rend(); ++it) {
            (*it)->backward_fn();
        }
    }
};

inline std::shared_ptr<Node> operator+(const std::shared_ptr<Node>& a, const std::shared_ptr<Node>& b) {
    auto out = std::make_shared<Node>(a->data + b->data);
    out->parents = {a, b};
    out->backward_fn = [a, b, out]() {
        a->grad += 1.0f * out->grad;
        b->grad += 1.0f * out->grad;
    };
    return out;
}

inline std::shared_ptr<Node> operator*(const std::shared_ptr<Node>& a, const std::shared_ptr<Node>& b) {
    auto out = std::make_shared<Node>(a->data * b->data);
    out->parents = {a, b};
    out->backward_fn = [a, b, out]() {
        a->grad += b->data * out->grad;
        b->grad += a->data * out->grad;
    };
    return out;
}

int main() {
    std::cout << "--- Drill 39.1: Cennan C++ DAG Autograd Engine (Solution) ---\n\n";

    auto a = std::make_shared<Node>(3.0f);
    auto b = std::make_shared<Node>(-4.0f);
    auto c = std::make_shared<Node>(2.0f);

    auto ab = a * b;
    auto y = ab + c;

    assert(y != nullptr && "Expression failed to construct!");
    std::cout << "Forward Value y: " << y->data << " (Expected: -10)\n";
    assert(std::abs(y->data - (-10.0f)) < 1e-4);

    y->backward();

    std::cout << "da: " << a->grad << " (Expected: -4)\n";
    std::cout << "db: " << b->grad << " (Expected: 3)\n";
    std::cout << "dc: " << c->grad << " (Expected: 1)\n";

    assert(std::abs(a->grad - (-4.0f)) < 1e-4);
    assert(std::abs(b->grad - 3.0f) < 1e-4);
    assert(std::abs(c->grad - 1.0f) < 1e-4);

    std::cout << "\n✓ Drill Passed: C++ DAG autograd engine verified!\n";
    return 0;
}
