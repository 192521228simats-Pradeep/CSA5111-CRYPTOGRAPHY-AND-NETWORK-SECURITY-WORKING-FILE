/* CSA5111 Question 4: independent executable */
#include "common/crypto_common.h"
static void q04(void){readstr("Plaintext: ",buf,sizeof buf);char key[512];readstr("Vigenere keyword: ",key,sizeof key);vigenere(buf,key,0);}
int main(void){ OSSL_PROVIDER_load(NULL,"default"); OSSL_PROVIDER_load(NULL,"legacy"); q04(); return 0; }
