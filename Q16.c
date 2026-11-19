/* CSA5111 Question 16: independent executable */
#include "common/crypto_common.h"
static void q16(void){readstr("Monoalphabetic substitution ciphertext: ",buf,sizeof buf);mono_frequency_attack(buf);puts("This is a frequency-analysis heuristic, not guaranteed full recovery; use long ciphertext and language context.");}
int main(void){ OSSL_PROVIDER_load(NULL,"default"); OSSL_PROVIDER_load(NULL,"legacy"); q16(); return 0; }
