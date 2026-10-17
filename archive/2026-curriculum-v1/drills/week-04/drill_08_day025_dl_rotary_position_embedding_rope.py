# ==============================================================================
# 🥋 Drill 08 (Week 04 / Day 025): DL Builder Track — Rotary Position Embeddings (RoPE)
#
# 📖 READING / CONTEXT:
# - Su et al.: "RoFormer: Enhanced Transformer with Rotary Position Embedding"
#
# 🎯 CORE LESSON:
# 1. RoPE 2D Rotation:
#    Pairs of adjacent dimensions (x_{2i}, x_{2i+1}) are rotated by angle (m * theta_i),
#    where theta_i = 10000^(-2i / d).
# 2. Invariant:
#    <R_m x, R_n y> = g(x, y, m - n). Relative distance depends strictly on token offset (m - n).
#
# 🚀 RUN COMMAND:
# python3 drill_08_day025_dl_rotary_position_embedding_rope.py
# ==============================================================================

import torch

def precompute_rope_freqs(dim: int, max_seq_len: int, theta: float = 10000.0):
    freqs = 1.0 / (theta ** (torch.arange(0, dim, 2)[: (dim // 2)].float() / dim))
    t = torch.arange(max_seq_len, dtype=torch.float32)
    freqs = torch.outer(t, freqs) # (max_seq_len, dim // 2)
    freqs_cos = torch.cos(freqs)  # (max_seq_len, dim // 2)
    freqs_sin = torch.sin(freqs)  # (max_seq_len, dim // 2)
    return freqs_cos, freqs_sin

def apply_rope(x: torch.Tensor, cos: torch.Tensor, sin: torch.Tensor) -> torch.Tensor:
    """
    x: (B, S, D)
    cos, sin: (S, D // 2)
    """
    B, S, D = x.shape
    x1 = x[..., 0::2] # Even dimensions
    x2 = x[..., 1::2] # Odd dimensions
    
    # 2D Givens rotation: [x1*cos - x2*sin, x1*sin + x2*cos]
    out1 = x1 * cos.unsqueeze(0) - x2 * sin.unsqueeze(0)
    out2 = x1 * sin.unsqueeze(0) + x2 * cos.unsqueeze(0)
    
    out = torch.stack([out1, out2], dim=-1).flatten(-2)
    return out

if __name__ == "__main__":
    print("--- Week 04 Drill 08: Rotary Position Embedding (RoPE) from Scratch ---\n")

    B, S, D = 2, 8, 64
    x = torch.randn(B, S, D)
    cos, sin = precompute_rope_freqs(dim=D, max_seq_len=S)

    x_rotated = apply_rope(x, cos, sin)
    print(f"Input Shape:   {x.shape}")
    print(f"Rotated Shape: {x_rotated.shape}")

    assert x_rotated.shape == (B, S, D)
    # At position 0, angle = 0 -> cos = 1, sin = 0 -> x_rotated[b, 0] must equal x[b, 0]
    assert torch.allclose(x_rotated[:, 0, :], x[:, 0, :], atol=1e-5), "Position 0 must be identity rotation!"

    print("\n✓ Week 04 Drill 08 Passed: RoPE 2D complex frequency rotation verified!")
