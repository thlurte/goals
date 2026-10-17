# ==============================================================================
# 🥋 Drill 10 (Week 04 / Day 027): DL Builder Track — Key-Value (KV) Cache Decoding
#
# 📖 READING / CONTEXT:
# - Autoregressive LLM Inference & Memory-Bound KV Caching
#
# 🎯 CORE LESSON:
# 1. Prefill Step (Prompt Processing):
#    Processes prompt of length S_prompt, computes and stores K, V tensors in cache: (B, H, S_prompt, d_k).
# 2. Decode Step (Token Generation):
#    New token has S_new = 1. Computes single K_new, V_new, appends to KV cache,
#    and attends across all accumulated (S_prompt + step) tokens without recomputing past keys/values.
#
# 🚀 RUN COMMAND:
# python3 drill_10_day027_dl_naive_kv_cache.py
# ==============================================================================

import torch

class SimpleKVCache:
    def __init__(self):
        self.k_cache = None
        self.v_cache = None

    def update(self, k_new: torch.Tensor, v_new: torch.Tensor):
        """
        k_new, v_new: (B, H, S_new, d_k)
        """
        if self.k_cache is None:
            self.k_cache = k_new
            self.v_cache = v_new
        else:
            self.k_cache = torch.cat([self.k_cache, k_new], dim=-2)
            self.v_cache = torch.cat([self.v_cache, v_new], dim=-2)
        return self.k_cache, self.v_cache

if __name__ == "__main__":
    print("--- Week 04 Drill 10: Autoregressive KV-Cache Decoding ---\n")

    B, H, d_k = 1, 4, 32
    cache = SimpleKVCache()

    # Step 1: Prefill prompt of length 4
    k_prompt = torch.randn(B, H, 4, d_k)
    v_prompt = torch.randn(B, H, 4, d_k)
    k_all, v_all = cache.update(k_prompt, v_prompt)

    print(f"Prefill Cache Sequence Length: {k_all.shape[-2]} (Expected: 4)")
    assert k_all.shape == (B, H, 4, d_k)

    # Step 2: Generate token 1 (S_new = 1)
    k_tok1 = torch.randn(B, H, 1, d_k)
    v_tok1 = torch.randn(B, H, 1, d_k)
    k_all, v_all = cache.update(k_tok1, v_tok1)

    print(f"After Decode Step 1 Length:    {k_all.shape[-2]} (Expected: 5)")
    assert k_all.shape == (B, H, 5, d_k)

    # Step 3: Generate token 2 (S_new = 1)
    k_tok2 = torch.randn(B, H, 1, d_k)
    v_tok2 = torch.randn(B, H, 1, d_k)
    k_all, v_all = cache.update(k_tok2, v_tok2)

    print(f"After Decode Step 2 Length:    {k_all.shape[-2]} (Expected: 6)")
    assert k_all.shape == (B, H, 6, d_k)

    print("\n✓ Week 04 Drill 10 Passed: Dynamic KV-cache concatenation verified!")
