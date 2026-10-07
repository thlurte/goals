#!/usr/bin/env python3
"""
🥋 Morning Builder Drill 37.1: AdamW Optimizer from Scratch (Decoupled Weight Decay)

🚀 RUN COMMAND:
python3 day037_builder_drill_01_adamw_scratch.py

CONTEXT:
Loshchilov & Hutter (2019) showed that standard Adam with L2 regularization
leads to suboptimal generalization because weight decay gradient is scaled by 1/sqrt(v_t).
AdamW decouples weight decay: theta_t = theta_{t-1} - lr * weight_decay * theta_{t-1} - lr * m_hat / (sqrt(v_hat) + eps).

CONCEPTS TO PRACTICE:
1. First moment (mean gradient) exponential moving average: m_t = beta1 * m_{t-1} + (1 - beta1) * g.
2. Second moment (uncentered variance) EMA: v_t = beta2 * v_{t-1} + (1 - beta2) * g^2.
3. Bias correction terms: m_hat = m_t / (1 - beta1^t), v_hat = v_t / (1 - beta2^t).
4. Decoupled weight decay step.
"""

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

    # TODO: Implement full AdamW parameter update step
    # For each param p in self.params:
    # 1. If p.grad is None, skip.
    # 2. Retrieve or initialize state: m (zeros_like(p)), v (zeros_like(p)).
    # 3. Update moments:
    #    m = beta1 * m + (1 - beta1) * grad
    #    v = beta2 * v + (1 - beta2) * (grad ** 2)
    # 4. Compute bias-corrected moments:
    #    m_hat = m / (1 - beta1 ** step)
    #    v_hat = v / (1 - beta2 ** step)
    # 5. Decoupled weight decay:
    #    p.data.mul_(1.0 - lr * weight_decay)
    # 6. Gradient step:
    #    p.data.addcdiv_(m_hat, torch.sqrt(v_hat) + eps, value=-lr)
    def step(self):
        self.step_count += 1
        # [YOUR CODE HERE]
        pass

    def zero_grad(self):
        for p in self.params:
            if p.grad is not None:
                p.grad.zero_()

def test_adamw():
    print("--- Testing Custom AdamW Optimizer from Scratch ---")
    torch.manual_seed(42)
    w_custom = torch.randn(10, 10, requires_grad=True)
    w_torch = w_custom.clone().detach().requires_grad_(True)

    opt_custom = CustomAdamW([w_custom], lr=0.01, weight_decay=0.05)
    opt_torch = torch.optim.AdamW([w_torch], lr=0.01, weight_decay=0.05)

    for step in range(5):
        # Dummy loss: sum((w - target)^2)
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

    print("\n✓ Drill Passed: Custom AdamW update exactly matches PyTorch reference implementation!\n")

if __name__ == "__main__":
    test_adamw()
