/* CSA5111 Question 5: independent executable */
#include "common/crypto_common.h"
static void q05(void){readstr("Text: ",buf,sizeof buf);int a=(int)readint("a: "),b=(int)readint("b: ");printf("gcd(a,26)=%d; b may be any integer. a must be coprime to 26.\n",gcd_i(a,26));if(gcd_i(a,26)!=1){puts("This a is invalid because encryption is not one-to-one.");return;}printf("Encrypt: ");affine(buf,a,b,0);printf("Decrypt: ");affine(buf,a,b,1);puts("Allowed a: 1,3,5,7,9,11,15,17,19,21,23,25.");}
int main(void){ OSSL_PROVIDER_load(NULL,"default"); OSSL_PROVIDER_load(NULL,"legacy"); q05(); return 0; }
