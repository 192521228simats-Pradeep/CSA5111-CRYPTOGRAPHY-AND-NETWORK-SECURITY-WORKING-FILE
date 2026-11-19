/* CSA5111 Question 33: independent executable */
#include "common/crypto_common.h"
static void q33(void){char kh[128],ph[128];readstr("DES key hex (16 digits; test key 133457799BBCDFF1): ",kh,sizeof kh);readstr("Plaintext block hex (16 digits; test 0123456789ABCDEF): ",ph,sizeof ph);uint64_t k,p;if(strlen(kh)!=16||strlen(ph)!=16||!parse_u64(kh,&k)||!parse_u64(ph,&p)){puts("Invalid DES key/plaintext block.");return;}uint64_t c=des_block(p,k,0),d=des_block(c,k,1);printf("Ciphertext: %016llX\nDecrypted:  %016llX\n",(unsigned long long)c,(unsigned long long)d);if(k==0x133457799bbcdff1ULL&&p==0x0123456789abcdefULL)puts("Known DES vector expected ciphertext 85E813540F0AB405.");}
int main(void){ OSSL_PROVIDER_load(NULL,"default"); OSSL_PROVIDER_load(NULL,"legacy"); q33(); return 0; }
