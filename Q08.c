/* CSA5111 Question 8: independent executable */
#include "common/crypto_common.h"
static void q08(void){char key[512];readstr("Keyword (example CIPHER): ",key,sizeof key);show_keyword_map(key);readstr("Plaintext: ",buf,sizeof buf);substitution(buf,key,0);}
int main(void){ OSSL_PROVIDER_load(NULL,"default"); OSSL_PROVIDER_load(NULL,"legacy"); q08(); return 0; }
