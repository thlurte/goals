# ==============================================================================
# 🥋 Drill 09 (Week 04 / Day 026): DL Builder Track — Custom SGD with Momentum from Scratch
#
# 📖 READING / CONTEXT:
# - Sutskever et al.: "On the importance of initialization and momentum in deep learning"
#
# 🎯 CORE LESSON:
# 1. Classical Momentum Update:
#    v_t = beta * v_{t-1} + g_t
#    theta_t = theta_{t-1} - lr * v_t
# 2. Verifying custom optimizer parity against `torch.optim.SGD`.
#
# 🚀 RUN COMMAND:
# python3 drill_09_day026_dl_sgd_momentum_from_scratch.py
# ==============================================================================

import torch

class CustomSGDMomentum:
    def __init__(self, params, lr: float = 0.01, momentum: float = 0.9):
        self.params = list(params)
        self.lr = lr
        self.momentum = momentum
        self.velocities = [torch.zeros_like(p) for p in self.params]

    def step(self):
        with torch.no_grad():
            for p, v in zip(self.params, self.velocities):
                if p.grad is None:
                    continue
                # v = beta * v + grad
                v.mul_(self.momentum).add_(p.grad)
                # param = param - lr * v
                p.add_(v, alpha=-self.lr)

    def zero_grad(self):
        for p in self.params:
            if p.grad is not None:
                p.grad.zero_()

if __name__ == "__main__":
    print("--- Week 04 Drill 09: Custom SGD with Momentum from Scratch ---\n")

    # Verify numerical match with PyTorch official SGD
    w_custom = torch.tensor([1.0, 2.0, 3.0], requires_grad=True)
    w_torch = torch.tensor([1.0, 2.0, 3.0], requires_grad=True)

    opt_custom = CustomSGDMomentum([w_custom], lr=0.1, momentum=0.9)
    opt_torch = torch.optim.SGD([w_torch], lr=0.1, momentum=0.9)

    for step in range(5):
        loss_custom = (w_custom ** 2).sum()
        loss_torch = (w_torch ** 2).sum()

        loss_custom.backward()
        loss_torch.backward()

        opt_custom.step()
        opt_torch.step()

        opt_custom.zero_grad()
        opt_torch.zero_grad()

        assert torch.allclose(w_custom, w_torch, atol=1e-6), f"Mismatch at step {step}!"

    print("✓ Custom SGD momentum optimizer matches torch.optim.SGD across all 5 training steps!")
    print("\n✓ Week 04 Drill 09 Passed Successfully!")
