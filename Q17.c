/* CSA5111 Question 17: independent executable */
#include "common/crypto_common.h"
static void q17(void){char k[128],c[128];readstr("DES key (16 hex digits): ",k,sizeof k);readstr("Ciphertext block (16 hex digits): ",c,sizeof c);uint64_t key,x;if(strlen(k)!=16||strlen(c)!=16||!parse_u64(k,&key)||!parse_u64(c,&x)){puts("Enter exactly 16 hexadecimal digits for key and block.");return;}uint64_t p=des_block(x,key,1);printf("Plaintext block: %016llX\n",(unsigned long long)p);puts("The Feistel network is identical for both directions; decryption uses K16,K15,...,K1.");}
int main(void){ OSSL_PROVIDER_load(NULL,"default"); OSSL_PROVIDER_load(NULL,"legacy"); q17(); return 0; }
