/* CSA5111 Question 20: independent executable */
#include "common/crypto_common.h"
static void q20(void){puts("CBC error propagation facts:");puts("(a) A bit error in transmitted C1 corrupts the entire P1 block and flips the corresponding bit in P2. P3 and later plaintext blocks are unaffected.");puts("(b) A bit error in source P1 changes C1 and therefore randomizes the decrypted P1; it also propagates through every later ciphertext block because CBC chaining uses the changed C value. Receiver recovery after the damaged block is not guaranteed.");puts("ECB differs: a corrupted ciphertext block affects only its matching plaintext block.");}
int main(void){ OSSL_PROVIDER_load(NULL,"default"); OSSL_PROVIDER_load(NULL,"legacy"); q20(); return 0; }
