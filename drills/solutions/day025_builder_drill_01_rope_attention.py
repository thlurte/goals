#!/usr/bin/env python3
import torch

def precompute_rope_freqs(dim: int, max_seq_len: int, base: float = 10000.0):
    theta = 1.0 / (base ** (torch.arange(0, dim, 2).float() / dim))
    pos = torch.arange(max_seq_len).float()
    freqs = torch.outer(pos, theta)
    freqs_full = torch.repeat_interleave(freqs, 2, dim=-1)
    return torch.cos(freqs_full), torch.sin(freqs_full)

def rotate_half(x: torch.Tensor) -> torch.Tensor:
    x1 = x[..., 0::2]
    x2 = x[..., 1::2]
    x_rot = torch.stack([-x2, x1], dim=-1)
    return x_rot.flatten(-2)

def apply_rope(x: torch.Tensor, cos: torch.Tensor, sin: torch.Tensor) -> torch.Tensor:
    return (x * cos) + (rotate_half(x) * sin)

def test_rope():
    print("--- Testing Rotary Position Embeddings (RoPE - Solution) ---")
    batch_size, seq_len, num_heads, head_dim = 2, 8, 4, 16
    q = torch.randn(batch_size, seq_len, num_heads, head_dim)
    k = torch.randn(batch_size, seq_len, num_heads, head_dim)

    cos, sin = precompute_rope_freqs(head_dim, seq_len)
    cos = cos.view(1, seq_len, 1, head_dim)
    sin = sin.view(1, seq_len, 1, head_dim)

    q_rot = apply_rope(q, cos, sin)
    k_rot = apply_rope(k, cos, sin)

    assert q_rot.shape == q.shape, f"Shape mismatch: {q_rot.shape} vs {q.shape}"
    q_norm = torch.linalg.norm(q, dim=-1)
    q_rot_norm = torch.linalg.norm(q_rot, dim=-1)
    assert torch.allclose(q_norm, q_rot_norm, atol=1e-5), "RoPE rotation must preserve L2 norm!"
    print("✓ Norm preservation verified!")
    print("\n✓ Drill Passed: RoPE frequency precomputation and 2D rotations verified!\n")

if __name__ == "__main__":
    test_rope()
