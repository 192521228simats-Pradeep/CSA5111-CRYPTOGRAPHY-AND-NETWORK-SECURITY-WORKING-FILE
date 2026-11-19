# CSA5111 Cryptography and Network Security Lab

## Run in GitHub Codespaces

Open this branch in Codespaces, then run:

```bash
sudo apt update
sudo apt install -y build-essential libssl-dev
make
./cryptolab
```

Select a question number from 1 to 40. The build uses GCC and OpenSSL development headers.

## Implemented in the current source

- Caesar cipher (Q1, Q36)
- Monoalphabetic substitution and keyword-based alphabet construction (Q2, Q8)
- Playfair encryption/decryption (Q3, Q9); Q10 fixed-matrix encryption is not yet wired as a separate menu option
- Vigenere encryption (Q4, Q14, Q35)
- Hill 2x2 encryption/decryption (Q12)
- S-DES block cipher with CBC and CTR modes (Q22, Q23)
- RSA private exponent calculation for n=3599, e=31 (Q24)
- SHA3-256 helper exists in source but is not currently connected to a menu option

## Explanation / partial work

Several questions print the algorithmic reasoning rather than a complete standalone program: affine validity/cryptanalysis (Q5–6), Sherlock Holmes symbol cryptogram (Q7), Playfair keyspace (Q11), Hill known-plaintext attack (Q13, Q38), additive and monoalphabetic frequency attacks (Q15–16, Q37, Q39–40), DES key schedule and mode/error-propagation topics (Q17–21, Q33–34), RSA attacks (Q25–27), Diffie-Hellman (Q28), SHA-3 lane reasoning (Q29), CBC-MAC (Q30), CMAC constants (Q31), and DSA nonce implications (Q32). These are not all full executable implementations. Q10 and the full DES/3DES, AES modes, CMAC generation, DSA signing and automatic cryptanalysis remain to be added.

## S-DES worksheet test vectors

- CBC: plaintext bytes `01 23`, key `0111111101` (decimal 509), IV `AA` (decimal 170) -> ciphertext `F4 0B`.
- CTR: plaintext bytes `01 02 04`, same key, counter `00` -> ciphertext `38 4F 32`.

The key is entered as decimal 509 in the program.

This is a classroom project, not production cryptography. DES, 3DES, textbook RSA, small DH parameters, classical ciphers and S-DES are insecure for real-world use. Use authenticated modern encryption such as AES-GCM in production.
