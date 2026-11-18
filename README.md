# CSA5111 Cryptography and Network Security Lab

## Run in GitHub Codespaces

Open this branch in Codespaces, then run:

```bash
sudo apt update
sudo apt install -y build-essential libssl-dev
make
./cryptolab
```

Choose an experiment number from the menu. OpenSSL 3 is used for DES/3DES/AES/SHA3/CMAC/RSA primitives; classical ciphers and S-DES are implemented in C.

## Coverage and limitations

The menu maps to the 40 questions in the worksheet, including Caesar, monoalphabetic substitution, Playfair, Vigenere, affine, Hill 2x2, S-DES CBC/CTR, DES/3DES examples, AES modes, SHA3-256, CMAC, RSA and Diffie-Hellman demonstrations. Some worksheet questions are conceptual and are answered with the relevant cryptographic reasoning rather than a separate cipher executable. The Sherlock Holmes symbol cryptogram and general monoalphabetic cryptanalysis remain heuristic/manual; Q6 affine cryptanalysis is explained but not a full automatic search; DSA signing and a full DES subkey schedule printout are not implemented as standalone practicals.

S-DES vectors: CBC plaintext 0123, key 509 (binary 0111111101), IV 170 (AA) -> F40B. CTR plaintext 010204, same key, counter 0 -> 384F32.

This is a classroom project, not production cryptography. DES, 3DES, textbook RSA, small DH parameters, classical ciphers and S-DES are insecure for real-world use. Use authenticated modern encryption such as AES-GCM in production.
