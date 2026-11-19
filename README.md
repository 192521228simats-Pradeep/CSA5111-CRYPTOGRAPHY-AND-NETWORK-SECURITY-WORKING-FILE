# CSA5111 — Cryptography and Network Security Lab

**One standalone source file per question:** Q01.c through Q40.c. Shared low-level functions are in common/crypto_common.h. Every question file has its own main() and can be built and run separately.

## GitHub Codespaces

    make all
    ./bin/Q01
    ./bin/Q22
    ./bin/Q33

Build only one: make Q22, then run ./bin/Q22. Run checks with bash smoke.sh.

Dependencies: GCC/Clang C11, Make, OpenSSL 3 development headers/library. The devcontainer installs these.

## Question files
- Q01.c — Caesar cipher
- Q02.c — Monoalphabetic substitution
- Q03.c — Playfair cipher
- Q04.c — Polyalphabetic/Vigenere cipher
- Q05.c — Affine cipher and valid keys
- Q06.c — Affine cipher frequency attack
- Q07.c — Symbol substitution cryptogram
- Q08.c — Keyword substitution
- Q09.c — PT-109 Playfair decryption (keyword input)
- Q10.c — Playfair with supplied matrix
- Q11.c — Playfair keyspace
- Q12.c — Hill encryption/decryption
- Q13.c — Hill known-plaintext attack
- Q14.c — One-time-pad Vigenere
- Q15.c — Additive frequency attack
- Q16.c — Monoalphabetic frequency attack
- Q17.c — DES decryption key order
- Q18.c — DES key schedule halves
- Q19.c — 3DES CBC
- Q20.c — ECB/CBC error propagation
- Q21.c — AES ECB/CBC/CFB and padding
- Q22.c — S-DES CBC
- Q23.c — S-DES CTR
- Q24.c — RSA private key recovery
- Q25.c — RSA common-factor attack
- Q26.c — RSA leaked private exponent
- Q27.c — Textbook RSA codebook attack
- Q28.c — Diffie-Hellman
- Q29.c — SHA-3 capacity lanes
- Q30.c — CBC-MAC forgery
- Q31.c — CMAC subkeys
- Q32.c — DSA nonce demonstration
- Q33.c — DES encrypt/decrypt
- Q34.c — ISO 7816-4 padding
- Q35.c — One-time-pad Vigenere
- Q36.c — Affine Caesar
- Q37.c — Monoalphabetic frequency attack
- Q38.c — Hill known-plaintext attack
- Q39.c — Additive frequency attack
- Q40.c — Monoalphabetic frequency attack

## Notes

- Q07 has a Unicode symbol cryptogram; manual mapping is supported, but automatic frequency guesses cannot guarantee full recovery.
- Q09 needs a Playfair keyword not supplied by the worksheet; the program requests it.
- Q17/Q18 cover DES reverse key order and key schedule; Q33 includes a full DES known-answer implementation.
- Q37–Q40 repeat the frequency/Hill experiments listed in the supplied worksheet.
- DES/S-DES and toy RSA/DSA/DH values are for coursework only, not real-world security.

The build workflow compiles every Q01.c–Q40.c as a separate executable and runs the smoke tests.
