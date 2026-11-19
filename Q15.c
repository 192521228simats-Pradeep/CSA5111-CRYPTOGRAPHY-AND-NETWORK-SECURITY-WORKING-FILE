/* CSA5111 Question 15: independent executable */
#include "common/crypto_common.h"
static void q15(void){readstr("Additive-cipher ciphertext: ",buf,sizeof buf);additive_attack(buf);}
int main(void){ OSSL_PROVIDER_load(NULL,"default"); OSSL_PROVIDER_load(NULL,"legacy"); q15(); return 0; }
