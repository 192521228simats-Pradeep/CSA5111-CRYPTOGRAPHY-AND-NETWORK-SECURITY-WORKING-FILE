/* CSA5111 Question 24: independent executable */
#include "common/crypto_common.h"
static void q24(void){BIGNUM*n=BN_new(),*e=BN_new(),*p=BN_new(),*q=BN_new(),*phi=BN_new(),*d=NULL;BN_CTX*ctx=BN_CTX_new();BN_set_word(p,59);BN_set_word(q,61);BN_mul(n,p,q,ctx);BN_copy(phi,p);BN_sub_word(phi,1);BN_sub_word(q,1);BN_mul(phi,phi,q,ctx);BN_set_word(e,31);d=BN_mod_inverse(NULL,e,phi,ctx);printf("n=3599 = 59 x 61; phi(n)=58 x 60 = 3480; e=31\nPrivate exponent d = ");BN_print_fp(stdout,d);puts("");puts("Check: (31 x 3031) mod 3480 = 1.");BN_free(n);BN_free(e);BN_free(p);BN_free(q);BN_free(phi);BN_free(d);BN_CTX_free(ctx);}
int main(void){ OSSL_PROVIDER_load(NULL,"default"); OSSL_PROVIDER_load(NULL,"legacy"); q24(); return 0; }
