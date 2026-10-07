# ==============================================================================
# 🥋 Drill 14 (Week 01 / Day 005): DL Builder Track — Numerically Stable Softmax & Attention
#
# 📖 READING / CONTEXT:
# - Goodfellow et al.: Deep Learning (Ch 4: Numerical Computation & Softmax Underflow/Overflow)
#
# 🎯 CORE LESSON:
# 1. Softmax Numerical Overflow:
#    exp(x_i) for x_i > 88 overflows 32-bit float to +inf.
# 2. Softmax Numerical Underflow:
#    exp(x_i) for x_i < -88 underflows to 0.0, causing log(0) = -inf / NaN in loss.
# 3. Stable Softmax Invariant:
#    softmax(x)_i = exp(x_i - max(x)) / sum_j exp(x_j - max(x))
#    Since x_i - max(x) <= 0, exp(...) is strictly in (0, 1], guaranteeing no overflow!
#
# 🚀 RUN COMMAND:
# python3 drill_14_day005_sdpa_numerical_stability.py
# ==============================================================================

import torch

def stable_softmax(logits: torch.Tensor, dim: int = -1) -> torch.Tensor:
    """
    Numerically stable softmax implemented from first principles.
    Subtracts max along the specified dimension to prevent exp() overflow.
    """
    # 1. Compute max along dim (keepdim=True for proper broadcasting)
    max_val = torch.max(logits, dim=dim, keepdim=True).values
    
    # 2. Subtract max before exp
    shifted_exp = torch.exp(logits - max_val)
    
    # 3. Normalize by sum
    sum_exp = torch.sum(shifted_exp, dim=dim, keepdim=True)
    return shifted_exp / sum_exp

if __name__ == "__main__":
    print("--- Week 01 Drill 14: Numerically Stable Softmax from Scratch ---\n")
    
    # Test case 1: Large positive values (would overflow naive exp(1000.0) -> inf)
    large_logits = torch.tensor([[1000.0, 1001.0, 1002.0], [500.0, 501.0, 500.0]])
    
    stable_probs = stable_softmax(large_logits, dim=-1)
    pytorch_probs = torch.softmax(large_logits, dim=-1)
    
    print("Logits with large scale (1000+):")
    print("Stable Softmax output:\n", stable_probs)
    
    assert not torch.isnan(stable_probs).any(), "Softmax produced NaN!"
    assert not torch.isinf(stable_probs).any(), "Softmax produced Inf!"
    assert torch.allclose(stable_probs, pytorch_probs, atol=1e-5), "Mismatch with PyTorch!"
    assert torch.allclose(stable_probs.sum(dim=-1), torch.ones(2), atol=1e-5), "Probabilities must sum to 1.0!"
    
    print("\n✓ Week 01 Drill 14 Passed: Numerically stable softmax verified!")
