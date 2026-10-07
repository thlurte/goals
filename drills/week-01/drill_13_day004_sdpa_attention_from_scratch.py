# ==============================================================================
# 🥋 Drill 13 (Week 01 / Day 004): DL Builder Track — Scaled Dot-Product Attention (SDPA)
#
# 📖 READING / CONTEXT:
# - Vaswani et al.: "Attention Is All You Need" (§3.2.1)
# - Transformers from scratch in Python/PyTorch
#
# 🎯 CORE LESSON:
# 1. SDPA Formula:
#    Attention(Q, K, V) = softmax( (Q @ K^T) / sqrt(d_k) + M ) @ V
# 2. Scaling by 1 / sqrt(d_k):
#    For large d_k, dot products grow large in magnitude, pushing softmax into
#    regions with vanishingly small gradients. Scaling stabilizes the variance to 1.0.
# 3. Causal Masking:
#    Upper triangular positions (future tokens) set to -inf before softmax.
#
# 🚀 RUN COMMAND:
# python3 drill_13_day004_sdpa_attention_from_scratch.py
# ==============================================================================

import math
import torch
import torch.nn.functional as F

def scaled_dot_product_attention(
    q: torch.Tensor,
    k: torch.Tensor,
    v: torch.Tensor,
    is_causal: bool = False
) -> torch.Tensor:
    """
    Args:
        q: (B, SeqLen, D) or (B, NumHeads, SeqLen, D)
        k: (B, SeqLen, D) or (B, NumHeads, SeqLen, D)
        v: (B, SeqLen, D) or (B, NumHeads, SeqLen, D)
        is_causal: If True, apply causal lower-triangular mask
    Returns:
        Output tensor of shape matching Q
    """
    d_k = q.size(-1)
    
    # 1. Compute raw attention scores: Q @ K^T / sqrt(d_k)
    scores = torch.matmul(q, k.transpose(-2, -1)) / math.sqrt(d_k)
    
    # 2. Apply causal mask if requested
    if is_causal:
        seq_len = q.size(-2)
        # Upper triangular mask where row < col
        mask = torch.triu(torch.ones((seq_len, seq_len), dtype=torch.bool, device=q.device), diagonal=1)
        scores = scores.masked_fill(mask, float('-inf'))
        
    # 3. Softmax over the last dimension
    attn_weights = F.softmax(scores, dim=-1)
    
    # 4. Multiply by V
    out = torch.matmul(attn_weights, v)
    return out

if __name__ == "__main__":
    print("--- Week 01 Drill 13: Scaled Dot-Product Attention from Scratch ---\n")
    
    B, SeqLen, D = 2, 8, 64
    torch.manual_seed(42)
    q = torch.randn(B, SeqLen, D)
    k = torch.randn(B, SeqLen, D)
    v = torch.randn(B, SeqLen, D)
    
    # Test unmasked SDPA against PyTorch official F.scaled_dot_product_attention
    out_custom = scaled_dot_product_attention(q, k, v, is_causal=False)
    out_pytorch = F.scaled_dot_product_attention(q, k, v, is_causal=False)
    
    assert torch.allclose(out_custom, out_pytorch, atol=1e-5), "Unmasked SDPA mismatch!"
    print("✓ Unmasked SDPA verified against PyTorch reference!")
    
    # Test causal SDPA
    out_causal_custom = scaled_dot_product_attention(q, k, v, is_causal=True)
    out_causal_pytorch = F.scaled_dot_product_attention(q, k, v, is_causal=True)
    
    assert torch.allclose(out_causal_custom, out_causal_pytorch, atol=1e-5), "Causal SDPA mismatch!"
    print("✓ Causal SDPA verified against PyTorch reference!")
    
    print("\n✓ Week 01 Drill 13 Passed Successfully!")
