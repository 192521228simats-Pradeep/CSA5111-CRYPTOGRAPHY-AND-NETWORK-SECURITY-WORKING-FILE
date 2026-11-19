/* CSA5111 Question 3: independent executable */
#include "common/crypto_common.h"
static void q03(void){readstr("Plaintext: ",buf,sizeof buf);char key[MAXBUF];readstr("Playfair keyword: ",key,sizeof key);playfair_key(buf,key,0);}
int main(void){ OSSL_PROVIDER_load(NULL,"default"); OSSL_PROVIDER_load(NULL,"legacy"); q03(); return 0; }
