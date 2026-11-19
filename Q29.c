/* CSA5111 Question 29: independent executable */
#include "common/crypto_common.h"
static void q29(void){puts("Keccak-f state = 1600 bits = 25 lanes x 64 bits.");puts("Rate=1024 bits=16 lanes; capacity=1600-1024=576 bits=9 lanes.");puts("The 16 rate lanes are XORed with message data. The 9 capacity lanes start at zero and are not touched by the message XOR.");puts("Ignoring the permutation exactly as instructed, the capacity lanes remain zero forever. They never become nonzero.");}
int main(void){ OSSL_PROVIDER_load(NULL,"default"); OSSL_PROVIDER_load(NULL,"legacy"); q29(); return 0; }
