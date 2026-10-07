# ==============================================================================
# 🥋 Drill 15 (Week 05 / Day 032): DL Track — Vision Transformer (ViT) Patch Embedding
#
# 📖 READING SOURCES:
# - Dosovitskiy et al.: "An Image is Worth 16x16 Words: Transformers for Image Recognition at Scale" (§3.1)
#
# 🎯 CORE LESSON:
# 1. 2D Patch Projection:
#    Input image (B, C, H, W) is partitioned into patches of size P x P.
#    Implemented via `nn.Conv2d(in_channels=C, out_channels=D, kernel_size=P, stride=P)`.
# 2. [CLS] Token & 1D Position Embeddings:
#    Prepend learnable `[CLS]` token (B, 1, D) -> shape: (B, 1 + N, D).
#    Add learnable 1D position embeddings of shape (1, 1 + N, D).
#
# 🚀 RUN COMMAND:
# python3 drill_15_day032_vit_patch_embed.py
# ==============================================================================

import torch
import torch.nn as nn

class ViTPatchEmbedding(nn.Module):
    def __init__(self, img_size: int = 224, patch_size: int = 16, in_channels: int = 3, d_model: int = 192):
        super().__init__()
        self.img_size = img_size
        self.patch_size = patch_size
        self.num_patches = (img_size // patch_size) ** 2

        self.projection = nn.Conv2d(in_channels, d_model, kernel_size=patch_size, stride=patch_size)
        self.cls_token = nn.Parameter(torch.zeros(1, 1, d_model))
        self.pos_embed = nn.Parameter(torch.randn(1, 1 + self.num_patches, d_model) * 0.02)

    def forward(self, x: torch.Tensor) -> torch.Tensor:
        B = x.shape[0]
        # (B, C, H, W) -> (B, D, H/P, W/P) -> flatten to (B, D, N) -> transpose to (B, N, D)
        patches = self.projection(x).flatten(2).transpose(1, 2)

        # Prepend [CLS] token
        cls_tokens = self.cls_token.expand(B, -1, -1)
        tokens = torch.cat([cls_tokens, patches], dim=1) # (B, 1 + N, D)

        # Add position embeddings
        return tokens + self.pos_embed

if __name__ == "__main__":
    print("--- Week 05 Drill 15: ViT Patch Projection & [CLS] Token ---\n")

    model = ViTPatchEmbedding(img_size=224, patch_size=16, in_channels=3, d_model=192)
    x = torch.randn(2, 3, 224, 224)

    out = model(x)
    expected_num_tokens = 1 + (224 // 16) ** 2 # 1 + 196 = 197 tokens
    print(f"Input Image Shape:   {x.shape}")
    print(f"ViT Output Sequence: {out.shape} (Expected: 2, 197, 192)")

    assert out.shape == (2, expected_num_tokens, 192)
    print("\n✓ Week 05 Drill 15 Passed: ViT patch projection & [CLS] verified!")
