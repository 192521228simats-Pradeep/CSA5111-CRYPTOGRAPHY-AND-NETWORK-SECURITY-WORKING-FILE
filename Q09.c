/* CSA5111 Question 9: independent executable */
#include "common/crypto_common.h"
static void q09(void){char ct[MAXBUF],key[512];readstr("PT-109 Playfair ciphertext: ",ct,sizeof ct);readstr("Playfair keyword (required): ",key,sizeof key);playfair_key(ct,key,1);puts("The worksheet does not specify the keyword; this must be supplied to obtain the plaintext.");}
int main(void){ OSSL_PROVIDER_load(NULL,"default"); OSSL_PROVIDER_load(NULL,"legacy"); q09(); return 0; }
