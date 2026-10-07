# ==============================================================================
# 🥋 Drill 15 (Week 01 / Day 006): DL Builder Track — Multi-Head Attention Tensor Shapes
#
# 📖 READING / CONTEXT:
# - Vaswani et al.: "Attention Is All You Need" (§3.2.2: Multi-Head Attention)
#
# 🎯 CORE LESSON:
# 1. Splitting Heads:
#    Input: (B, S, D) -> View: (B, S, H, d_k) -> Transpose: (B, H, S, d_k)
#    where D = H * d_k.
# 2. Batch Matrix Multiplication:
#    (B, H, S, d_k) @ (B, H, d_k, S) -> (B, H, S, S) attention matrix.
# 3. Merging Heads (Contiguous Reshape):
#    (B, H, S, d_v) -> Transpose: (B, S, H, d_v) -> .contiguous().view(B, S, D).
#
# 🚀 RUN COMMAND:
# python3 drill_15_day006_multihead_attention_shapes.py
# ==============================================================================

import torch
import torch.nn as nn
import math

class MultiHeadAttentionSimple(nn.Module):
    def __init__(self, d_model: int, num_heads: int):
        super().__init__()
        assert d_model % num_heads == 0, "d_model must be divisible by num_heads"
        self.d_model = d_model
        self.num_heads = num_heads
        self.d_k = d_model // num_heads

        self.q_proj = nn.Linear(d_model, d_model, bias=False)
        self.k_proj = nn.Linear(d_model, d_model, bias=False)
        self.v_proj = nn.Linear(d_model, d_model, bias=False)
        self.out_proj = nn.Linear(d_model, d_model, bias=False)

    def forward(self, x: torch.Tensor) -> torch.Tensor:
        B, S, D = x.shape

        # 1. Project Q, K, V and reshape to (B, H, S, d_k)
        q = self.q_proj(x).view(B, S, self.num_heads, self.d_k).transpose(1, 2)
        k = self.k_proj(x).view(B, S, self.num_heads, self.d_k).transpose(1, 2)
        v = self.v_proj(x).view(B, S, self.num_heads, self.d_k).transpose(1, 2)

        # 2. Scaled Dot-Product Attention per head
        scores = torch.matmul(q, k.transpose(-2, -1)) / math.sqrt(self.d_k)
        weights = torch.softmax(scores, dim=-1)
        attn_out = torch.matmul(weights, v) # (B, H, S, d_k)

        # 3. Transpose back and merge heads: (B, S, H, d_k) -> (B, S, D)
        merged = attn_out.transpose(1, 2).contiguous().view(B, S, D)

        # 4. Final output linear projection
        return self.out_proj(merged)

if __name__ == "__main__":
    print("--- Week 01 Drill 15: Multi-Head Attention Tensor Shapes ---\n")

    B, SeqLen, D, H = 4, 16, 128, 8
    mha = MultiHeadAttentionSimple(d_model=D, num_heads=H)
    x = torch.randn(B, SeqLen, D)

    out = mha(x)
    print(f"Input Shape:  {x.shape}")
    print(f"Output Shape: {out.shape}")

    assert out.shape == (B, SeqLen, D), "Output tensor shape must match (B, SeqLen, D)!"
    print("\n✓ Week 01 Drill 15 Passed: MHA head splitting and merging verified!")
