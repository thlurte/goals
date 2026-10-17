# ==============================================================================
# 🥋 Drill 16 (Week 05 / Day 033): DL Track — Vision Transformer (ViT) Full Encoder Block
#
# 📖 READING SOURCES:
# - Dosovitskiy et al.: ViT Paper (§3.1: Transformer Encoder Architecture)
#
# 🎯 CORE LESSON:
# 1. ViT Transformer Block:
#    x = x + MultiHeadSelfAttention(LayerNorm(x))
#    x = x + MLP(LayerNorm(x))
# 2. MLP Structure:
#    Linear(D, 4D) -> GELU -> Linear(4D, D)
#
# 🚀 RUN COMMAND:
# python3 drill_16_day033_vit_encoder_block.py
# ==============================================================================

import torch
import torch.nn as nn

class ViTEncoderBlock(nn.Module):
    def __init__(self, d_model: int = 192, num_heads: int = 3, mlp_ratio: int = 4):
        super().__init__()
        self.norm1 = nn.LayerNorm(d_model)
        self.attn = nn.MultiheadAttention(d_model, num_heads, batch_first=True)
        self.norm2 = nn.LayerNorm(d_model)
        self.mlp = nn.Sequential(
            nn.Linear(d_model, d_model * mlp_ratio),
            nn.GELU(),
            nn.Linear(d_model * mlp_ratio, d_model)
        )

    def forward(self, x: torch.Tensor) -> torch.Tensor:
        # Pre-LN Self-Attention
        normed1 = self.norm1(x)
        attn_out, _ = self.attn(normed1, normed1, normed1)
        x = x + attn_out

        # Pre-LN MLP
        x = x + self.mlp(self.norm2(x))
        return x

if __name__ == "__main__":
    print("--- Week 05 Drill 16: ViT Transformer Encoder Block ---\n")

    block = ViTEncoderBlock(d_model=192, num_heads=3)
    tokens = torch.randn(2, 197, 192)

    out = block(tokens)
    print(f"Input Tokens:  {tokens.shape}")
    print(f"Output Tokens: {out.shape}")

    assert out.shape == (2, 197, 192)
    print("\n✓ Week 05 Drill 16 Passed: ViT Transformer Encoder block verified!")
