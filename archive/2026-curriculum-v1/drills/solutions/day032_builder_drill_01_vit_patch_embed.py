#!/usr/bin/env python3
import torch
import torch.nn as nn

class ViTPatchEmbedding(nn.Module):
    def __init__(self, img_size: int = 224, patch_size: int = 16, in_channels: int = 3, embed_dim: int = 768):
        super().__init__()
        self.img_size = img_size
        self.patch_size = patch_size
        self.num_patches = (img_size // patch_size) ** 2
        self.embed_dim = embed_dim

        self.proj = nn.Conv2d(in_channels, embed_dim, kernel_size=patch_size, stride=patch_size)
        self.cls_token = nn.Parameter(torch.zeros(1, 1, embed_dim))
        self.pos_embed = nn.Parameter(torch.zeros(1, self.num_patches + 1, embed_dim))
        nn.init.trunc_normal_(self.cls_token, std=0.02)
        nn.init.trunc_normal_(self.pos_embed, std=0.02)

    def forward(self, x: torch.Tensor) -> torch.Tensor:
        B, C, H, W = x.shape
        assert H == self.img_size and W == self.img_size, f"Input image size ({H}, {W}) != ({self.img_size}, {self.img_size})"

        # (B, D, H/P, W/P) -> (B, D, N) -> (B, N, D)
        x = self.proj(x).flatten(2).transpose(1, 2)
        cls_tokens = self.cls_token.expand(B, -1, -1)
        x = torch.cat((cls_tokens, x), dim=1)
        x = x + self.pos_embed
        return x

def test_vit_patch_embed():
    print("--- Testing ViT Patch Embedding & [CLS] Token (Solution) ---")
    model = ViTPatchEmbedding(img_size=224, patch_size=16, in_channels=3, embed_dim=768)
    dummy_img = torch.randn(4, 3, 224, 224)

    out = model(dummy_img)
    expected_patches = (224 // 16) ** 2  # 196
    expected_tokens = expected_patches + 1  # 197
    print(f"Output shape: {out.shape} (expected: torch.Size([4, 197, 768]))")

    assert out.shape == (4, expected_tokens, 768), f"Shape mismatch: {out.shape}"
    print("\n✓ Drill Passed: ViT patch projection, CLS concatenation, and pos embeddings verified!\n")

if __name__ == "__main__":
    test_vit_patch_embed()
