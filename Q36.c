/* CSA5111 Question 36: independent executable */
#include "common/crypto_common.h"
static void q36(void){readstr("Text: ",buf,sizeof buf);int a=(int)readint("Affine multiplier a: "),b=(int)readint("Affine shift b: ");if(gcd_i(a,26)!=1){puts("Invalid a: gcd(a,26) must be 1.");return;}printf("Ciphertext: ");affine(buf,a,b,0);printf("Decrypted: ");affine(buf,a,b,1);}
int main(void){ OSSL_PROVIDER_load(NULL,"default"); OSSL_PROVIDER_load(NULL,"legacy"); q36(); return 0; }
