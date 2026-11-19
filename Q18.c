/* CSA5111 Question 18: independent executable */
#include "common/crypto_common.h"
static void q18(void){char k[128];readstr("DES key (16 hex digits): ",k,sizeof k);uint64_t key,sk[16];if(strlen(k)!=16||!parse_u64(k,&key)){puts("Invalid key.");return;}des_keys(key,sk);puts("DES subkeys (48 bits each):");for(int i=0;i<16;i++)printf("K%-2d = %012llX\n",i+1,(unsigned long long)sk[i]);puts("PC-2 selects bits 1..24 from C and bits 25..48 from D; these are disjoint 28-bit halves after PC-1.");}
int main(void){ OSSL_PROVIDER_load(NULL,"default"); OSSL_PROVIDER_load(NULL,"legacy"); q18(); return 0; }
