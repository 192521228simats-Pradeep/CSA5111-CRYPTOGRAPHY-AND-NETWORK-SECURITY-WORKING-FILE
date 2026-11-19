/* CSA5111 Question 25: independent executable */
#include "common/crypto_common.h"
static void q25(void){char ns[128];readstr("RSA modulus n (decimal): ",ns,sizeof ns);BIGNUM*n=NULL,*m=BN_new(),*g=BN_new();BN_CTX*ctx=BN_CTX_new();BN_dec2bn(&n,ns);char ms[128];readstr("Known plaintext block m (decimal): ",ms,sizeof ms);BN_dec2bn(&m,ms);BN_gcd(g,m,n,ctx);printf("gcd(m,n) = ");BN_print_fp(stdout,g);puts("");if(!BN_is_one(g)&&BN_cmp(g,n)!=0)puts("Non-trivial factor found: compute the other factor n/g; RSA modulus factored.");else puts("No non-trivial factor was revealed by this block.");BN_free(n);BN_free(m);BN_free(g);BN_CTX_free(ctx);}
int main(void){ OSSL_PROVIDER_load(NULL,"default"); OSSL_PROVIDER_load(NULL,"legacy"); q25(); return 0; }
