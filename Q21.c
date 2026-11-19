/* CSA5111 Question 21: independent executable */
#include "common/crypto_common.h"
static void q21(void){int m=(int)readint("Mode 1=ECB 2=CBC 3=CFB: ");if(m==1)q21_mode("AES-128-ECB");else if(m==2)q21_mode("AES-128-CBC");else if(m==3)q21_mode("AES-128-CFB");else puts("Invalid mode.");}
int main(void){ OSSL_PROVIDER_load(NULL,"default"); OSSL_PROVIDER_load(NULL,"legacy"); q21(); return 0; }
