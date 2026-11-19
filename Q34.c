/* CSA5111 Question 34: independent executable */
#include "common/crypto_common.h"
static void q34(void){char h[4096];readstr("Message as hex bytes (empty allowed): ",h,sizeof h);unsigned char in[2048],out[2080];int n=unhex(h,in,2048);if(n<0){puts("Invalid hex.");return;}int z=aes_pad80(in,n,out);printf("ISO/IEC 7816-4 style 80 00... padded data (%d bytes): ",z);printhex(out,z);puts("A full padding block is always added when length is already a multiple of the block size, so the receiver can remove padding unambiguously.");}
int main(void){ OSSL_PROVIDER_load(NULL,"default"); OSSL_PROVIDER_load(NULL,"legacy"); q34(); return 0; }
