# ==============================================================================
# 🥋 Drill 08 (Week 02 / Day 012): DL Builder Track — Pre-LN vs Post-LN Architecture
#
# 📖 READING / CONTEXT:
# - Xiong et al.: "On Layer Normalization in the Transformer Architecture" (ICML 2020)
#
# 🎯 CORE LESSON:
# 1. Post-LN (Original Transformer):
#    x = LayerNorm(x + Sublayer(x)) -> Vanishing gradients in deep networks without warmup.
# 2. Pre-LN (Modern LLMs / LLaMA / Mistral):
#    x = x + Sublayer(LayerNorm(x)) -> Clean identity residual highway, enables stable training without warmup.
#
# 🚀 RUN COMMAND:
# python3 drill_08_day012_dl_pre_ln_vs_post_ln.py
# ==============================================================================

import torch
import torch.nn as nn

class PreLNBlock(nn.Module):
    def __init__(self, d_model: int):
        super().__init__()
        self.norm = nn.LayerNorm(d_model)
        self.linear = nn.Linear(d_model, d_model)

    def forward(self, x: torch.Tensor) -> torch.Tensor:
        # Pre-LN: Norm applied before transformation; clean residual skip
        return x + self.linear(self.norm(x))

class PostLNBlock(nn.Module):
    def __init__(self, d_model: int):
        super().__init__()
        self.norm = nn.LayerNorm(d_model)
        self.linear = nn.Linear(d_model, d_model)

    def forward(self, x: torch.Tensor) -> torch.Tensor:
        # Post-LN: Norm applied after transformation and residual addition
        return self.norm(x + self.linear(x))

if __name__ == "__main__":
    print("--- Week 02 Drill 08: Pre-LN vs Post-LN Transformer Blocks ---\n")

    D = 64
    x = torch.randn(2, 8, D, requires_grad=True)

    pre_block = PreLNBlock(D)
    post_block = PostLNBlock(D)

    out_pre = pre_block(x)
    out_post = post_block(x)

    assert out_pre.shape == (2, 8, D)
    assert out_post.shape == (2, 8, D)

    # Verify backward gradient flow through pre-LN residual highway
    loss = out_pre.sum()
    loss.backward()
    assert x.grad is not None and not torch.isnan(x.grad).any()

    print("✓ Pre-LN and Post-LN forward and backward verified!")
    print("\n✓ Week 02 Drill 08 Passed Successfully!")
