# ==============================================================================
# 🥋 Drill 16 (Week 01 / Day 007): Python / NumPy — Zero-Copy .fvecs Vector Loader
#
# 📖 READING / CONTEXT:
# - Texmex Vector Dataset Standard (SIFT1M, GIST1M)
#
# 🎯 CORE LESSON:
# 1. `.fvecs` Structure:
#    Each vector is stored as (1 + D) * 4 bytes:
#    - 4-byte int32: dimension D
#    - D * 4-byte float32: vector components
# 2. Fast NumPy Vectorized Parsing:
#    Read flat buffer as `np.fromfile(..., dtype=np.float32)`,
#    reshape to `(N, D + 1)`, and slice `[:, 1:]` to drop the dimension header in 1 line!
#
# 🚀 RUN COMMAND:
# python3 drill_16_day007_sift1m_numpy_fvecs_parser.py
# ==============================================================================

import numpy as np
import tempfile
import os

def read_fvecs_numpy(filename: str) -> np.ndarray:
    """
    Fast zero-copy / vectorized read of .fvecs binary file using NumPy.
    """
    # 1. Read first 4 bytes to determine dimension D
    with open(filename, 'rb') as f:
        dim = int(np.fromfile(f, dtype=np.int32, count=1)[0])
    
    # 2. Read entire file as float32 array
    # Each record has (1 + dim) float32 values (first value is the int32 dim cast as float32)
    raw_data = np.fromfile(filename, dtype=np.float32)
    
    # 3. Reshape and slice off the first column
    vectors = raw_data.reshape(-1, dim + 1)[:, 1:]
    return vectors

if __name__ == "__main__":
    print("--- Week 01 Drill 16: Fast NumPy .fvecs Loader ---\n")

    # Generate a temporary synthetic .fvecs file
    N, D = 100, 128
    synthetic_data = np.random.randn(N, D).astype(np.float32)

    with tempfile.NamedTemporaryFile(delete=False, suffix=".fvecs") as tmp:
        tmp_path = tmp.name
        for i in range(N):
            np.int32(D).tofile(tmp)
            synthetic_data[i].tofile(tmp)

    try:
        loaded_vectors = read_fvecs_numpy(tmp_path)
        print(f"Loaded {loaded_vectors.shape[0]} vectors of dimension {loaded_vectors.shape[1]}")
        
        assert loaded_vectors.shape == (N, D)
        assert np.allclose(loaded_vectors, synthetic_data, atol=1e-6)
        print("\n✓ Week 01 Drill 16 Passed: Vectorized .fvecs parsing verified!")
    finally:
        if os.path.exists(tmp_path):
            os.remove(tmp_path)
