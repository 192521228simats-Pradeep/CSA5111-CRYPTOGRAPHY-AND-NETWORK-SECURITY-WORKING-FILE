/* CSA5111 Question 35: independent executable */
#include "common/crypto_common.h"
static void q35(void){readstr("Plaintext: ",buf,sizeof buf);int keys[4096],n=0;char line[4096];readstr("Numeric key stream (0..25 separated by spaces): ",line,sizeof line);for(char*p=strtok(line," ,");p&&n<4096;p=strtok(NULL," ,"))keys[n++]=mod(atoi(p),26);otp_numeric(buf,keys,n,0);}
int main(void){ OSSL_PROVIDER_load(NULL,"default"); OSSL_PROVIDER_load(NULL,"legacy"); q35(); return 0; }
