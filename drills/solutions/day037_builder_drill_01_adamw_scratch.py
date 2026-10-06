#!/usr/bin/env python3
import torch
from typing import List

class CustomAdamW:
    def __init__(self, params: List[torch.Tensor], lr: float = 1e-3, betas=(0.9, 0.999), eps: float = 1e-8, weight_decay: float = 1e-2):
        self.params = list(params)
        self.lr = lr
        self.beta1, self.beta2 = betas
        self.eps = eps
        self.weight_decay = weight_decay
        self.state = {}
        self.step_count = 0

    def step(self):
        self.step_count += 1
        for p in self.params:
            if p.grad is None:
                continue
            grad = p.grad.data
            state = self.state.setdefault(p, {
                'm': torch.zeros_like(p.data),
                'v': torch.zeros_like(p.data)
            })
            m, v = state['m'], state['v']

            # Update biased 1st and 2nd moment estimate
            m.mul_(self.beta1).add_(grad, alpha=1.0 - self.beta1)
            v.mul_(self.beta2).addcmul_(grad, grad, value=1.0 - self.beta2)

            # Bias correction
            bias_correction1 = 1.0 - self.beta1 ** self.step_count
            bias_correction2 = 1.0 - self.beta2 ** self.step_count

            # Decoupled weight decay
            if self.weight_decay != 0.0:
                p.data.mul_(1.0 - self.lr * self.weight_decay)

            step_size = self.lr / bias_correction1
            denom = (v.sqrt() / (bias_correction2 ** 0.5)).add_(self.eps)

            p.data.addcdiv_(m, denom, value=-step_size)

    def zero_grad(self):
        for p in self.params:
            if p.grad is not None:
                p.grad.zero_()

def test_adamw():
    print("--- Testing Custom AdamW Optimizer (Solution) ---")
    torch.manual_seed(42)
    w_custom = torch.randn(10, 10, requires_grad=True)
    w_torch = w_custom.clone().detach().requires_grad_(True)

    opt_custom = CustomAdamW([w_custom], lr=0.01, weight_decay=0.05)
    opt_torch = torch.optim.AdamW([w_torch], lr=0.01, weight_decay=0.05)

    for step in range(5):
        target = torch.ones_like(w_custom) * 0.5
        loss_custom = ((w_custom - target) ** 2).sum()
        loss_torch = ((w_torch - target) ** 2).sum()

        loss_custom.backward()
        loss_torch.backward()

        opt_custom.step()
        opt_torch.step()

        opt_custom.zero_grad()
        opt_torch.zero_grad()

        max_diff = (w_custom - w_torch).abs().max().item()
        print(f"Step {step+1}: Max weight difference vs torch.optim.AdamW = {max_diff:.8e}")
        assert max_diff < 1e-6, f"Mismatch at step {step+1}: diff = {max_diff}"

    print("\n✓ Drill Passed: Custom AdamW verified!\n")

if __name__ == "__main__":
    test_adamw()
