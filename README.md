# CSA5111 Cryptography and Network Security Lab

## Run in GitHub Codespaces

Open this branch in Codespaces, then run:

```bash
make
./cryptolab
```

Choose a question number at the prompt. Requires GCC.

## Implementation scope

This is a starter menu-driven C program, **not yet a complete implementation of all 40 programs**. It implements Caesar, affine, Vigenere, monoalphabetic substitution and Hill 2x2 operations. Other questions currently print concise algorithm explanations or attack approaches. Playfair, full S-DES, DES/3DES, AES modes, SHA-3, CMAC, DSA, full RSA operations, and automated cryptanalysis for the Sherlock Holmes symbol ciphertext still need implementation. The S-DES values below are expected worksheet vectors, not a claim that this branch executes them.

S-DES CBC expected vector: plaintext 0123, key 509, IV 170 -> F40B. CTR expected vector: plaintext 010204, key 509, counter 0 -> 384F32.

DES, 3DES, textbook RSA, small DH, classical ciphers and S-DES are educational only and insecure for real-world use. Prefer authenticated encryption such as AES-GCM in production.
