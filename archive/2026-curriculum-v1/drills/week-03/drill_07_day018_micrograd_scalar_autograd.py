# ==============================================================================
# 🥋 Drill 07 (Week 03 / Day 018): DL Builder Track — Micrograd Scalar Autograd Engine
#
# 📖 READING / CONTEXT:
# - Andrej Karpathy: Micrograd & Reverse-Mode Automatic Differentiation
#
# 🎯 CORE LESSON:
# 1. Computational Graph: Value objects track operands and backward closures.
# 2. Topological Sort: Backpropagation must visit nodes in reverse topological order
#    to ensure parent gradients are fully accumulated before child gradients are computed.
#
# 🚀 RUN COMMAND:
# python3 drill_07_day018_micrograd_scalar_autograd.py
# ==============================================================================

class Value:
    def __init__(self, data, _children=(), _op=''):
        self.data = float(data)
        self.grad = 0.0
        self._backward = lambda: None
        self._prev = set(_children)
        self._op = _op

    def __add__(self, other):
        other = other if isinstance(other, Value) else Value(other)
        out = Value(self.data + other.data, (self, other), '+')
        def _backward():
            self.grad += 1.0 * out.grad
            other.grad += 1.0 * out.grad
        out._backward = _backward
        return out

    def __mul__(self, other):
        other = other if isinstance(other, Value) else Value(other)
        out = Value(self.data * other.data, (self, other), '*')
        def _backward():
            self.grad += other.data * out.grad
            other.grad += self.data * out.grad
        out._backward = _backward
        return out

    def backward(self):
        topo = []
        visited = set()
        def build_topo(v):
            if v not in visited:
                visited.add(v)
                for child in v._prev:
                    build_topo(child)
                topo.append(v)
        build_topo(self)

        self.grad = 1.0
        for node in reversed(topo):
            node._backward()

if __name__ == "__main__":
    print("--- Week 03 Drill 07: Micrograd Scalar Autograd Engine ---\n")

    # Expression: L = (a * b) + c
    a = Value(2.0)
    b = Value(-3.0)
    c = Value(10.0)
    d = a * b # -6.0
    L = d + c # 4.0

    L.backward()

    print(f"L.data: {L.data} (Expected: 4.0)")
    print(f"dL/da:  {a.grad} (Expected: -3.0)")
    print(f"dL/db:  {b.grad} (Expected: 2.0)")
    print(f"dL/dc:  {c.grad} (Expected: 1.0)")

    assert L.data == 4.0
    assert a.grad == -3.0
    assert b.grad == 2.0
    assert c.grad == 1.0

    print("\n✓ Week 03 Drill 07 Passed: Reverse topological autograd verified!")
