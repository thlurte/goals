# ==============================================================================
# 🥋 Drill 08 (Week 03 / Day 019): DL Builder Track — Manual Linear Layer Backpropagation
#
# 📖 READING / CONTEXT:
# - Matrix Calculus for Deep Learning
#
# 🎯 CORE LESSON:
# 1. Linear Forward:
#    Y = X @ W^T + b, where X is (B, InDim), W is (OutDim, InDim), b is (OutDim,)
# 2. Analytical Backpropagation Derivatives:
#    - dX = dY @ W          (shape: B, InDim)
#    - dW = dY^T @ X        (shape: OutDim, InDim)
#    - db = sum_{b=0}^{B-1} dY[b] (shape: OutDim,)
#
# 🚀 RUN COMMAND:
# python3 drill_08_day019_manual_linear_backward_pass.py
# ==============================================================================

import torch

def manual_linear_backward(
    x: torch.Tensor,   # (B, InDim)
    w: torch.Tensor,   # (OutDim, InDim)
    dy: torch.Tensor   # (B, OutDim)
):
    """
    Computes analytical gradients for Linear layer without autograd.
    """
    dx = torch.matmul(dy, w)               # (B, InDim)
    dw = torch.matmul(dy.transpose(0, 1), x) # (OutDim, InDim)
    db = dy.sum(dim=0)                     # (OutDim,)
    return dx, dw, db

if __name__ == "__main__":
    print("--- Week 03 Drill 08: Manual Linear Backpropagation ---\n")

    B, InDim, OutDim = 4, 8, 16
    x = torch.randn(B, InDim, requires_grad=True)
    w = torch.randn(OutDim, InDim, requires_grad=True)
    b = torch.randn(OutDim, requires_grad=True)

    # PyTorch Autograd Forward & Backward
    y = torch.matmul(x, w.t()) + b
    dy = torch.randn_like(y)
    y.backward(dy)

    # Manual analytical gradients
    dx_manual, dw_manual, db_manual = manual_linear_backward(x.detach(), w.detach(), dy)

    assert torch.allclose(dx_manual, x.grad, atol=1e-5), "dX mismatch!"
    assert torch.allclose(dw_manual, w.grad, atol=1e-5), "dW mismatch!"
    assert torch.allclose(db_manual, b.grad, atol=1e-5), "db mismatch!"

    print("✓ Manual dX, dW, and db match PyTorch autograd ground truth!")
    print("\n✓ Week 03 Drill 08 Passed Successfully!")
