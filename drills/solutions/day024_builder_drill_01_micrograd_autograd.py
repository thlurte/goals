#!/usr/bin/env python3
import math

class Value:
    def __init__(self, data, _children=(), _op=""):
        self.data = float(data)
        self.grad = 0.0
        self._backward = lambda: None
        self._prev = set(_children)
        self._op = _op

    def __repr__(self):
        return f"Value(data={self.data:.4f}, grad={self.grad:.4f})"

    def __add__(self, other):
        other = other if isinstance(other, Value) else Value(other)
        out = Value(self.data + other.data, (self, other), "+")
        def _backward():
            self.grad += 1.0 * out.grad
            other.grad += 1.0 * out.grad
        out._backward = _backward
        return out

    def __mul__(self, other):
        other = other if isinstance(other, Value) else Value(other)
        out = Value(self.data * other.data, (self, other), "*")
        def _backward():
            self.grad += other.data * out.grad
            other.grad += self.data * out.grad
        out._backward = _backward
        return out

    def tanh(self):
        x = self.data
        t = (math.exp(2 * x) - 1) / (math.exp(2 * x) + 1)
        out = Value(t, (self,), "tanh")
        def _backward():
            self.grad += (1.0 - t**2) * out.grad
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

    def __radd__(self, other):
        return self + other

    def __rmul__(self, other):
        return self * other

def test_micrograd():
    print("--- Testing Scalar Autograd Engine (Solution) ---")
    x1 = Value(2.0)
    x2 = Value(0.0)
    w1 = Value(-3.0)
    w2 = Value(1.0)
    b = Value(6.8813735870195432)

    x1w1 = x1 * w1
    x2w2 = x2 * w2
    x1w1_x2w2 = x1w1 + x2w2
    n = x1w1_x2w2 + b
    o = n.tanh()

    o.backward()

    print(f"Output: {o.data:.4f} (expected: ~0.7071)")
    print(f"dx1:    {x1.grad:.4f} (expected: ~-1.5000)")
    print(f"dw1:    {w1.grad:.4f} (expected: ~1.0000)")

    assert abs(o.data - 0.7071) < 1e-3, "Forward output mismatch!"
    assert abs(x1.grad - (-1.5000)) < 1e-3, "dx1 gradient mismatch!"
    assert abs(w1.grad - 1.0000) < 1e-3, "dw1 gradient mismatch!"
    print("\n✓ Drill Passed: Scalar autograd verified!\n")

if __name__ == "__main__":
    test_micrograd()
