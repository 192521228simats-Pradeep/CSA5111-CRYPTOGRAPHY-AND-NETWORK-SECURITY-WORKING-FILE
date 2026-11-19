/* CSA5111 Question 39: independent executable */
#include "common/crypto_common.h"
static void q39(void){readstr("Additive-cipher ciphertext: ",buf,sizeof buf);additive_attack(buf);}
int main(void){ OSSL_PROVIDER_load(NULL,"default"); OSSL_PROVIDER_load(NULL,"legacy"); q39(); return 0; }
