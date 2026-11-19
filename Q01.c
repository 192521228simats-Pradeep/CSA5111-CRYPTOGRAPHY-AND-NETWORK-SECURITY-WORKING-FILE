/* CSA5111 Question 1: independent executable */
#include "common/crypto_common.h"
static void q01(void){readstr("Plaintext: ",buf,sizeof buf);puts("Ciphertext for shifts 1 through 25:");for(int k=1;k<=25;k++){printf("k=%2d: ",k);caesar(buf,k);}}
int main(void){ OSSL_PROVIDER_load(NULL,"default"); OSSL_PROVIDER_load(NULL,"legacy"); q01(); return 0; }
