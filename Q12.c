/* CSA5111 Question 12: independent executable */
#include "common/crypto_common.h"
static void q12(void){readstr("Plaintext (default worksheet phrase if blank): ",buf,sizeof buf);if(!*buf)strcpy(buf,"meet me at the usual place at ten rather than eight oclock");char p[MAXBUF],ct[MAXBUF];clean_alpha(buf,p);int n=(int)strlen(p);if(n%2)p[n++]='x',p[n]=0;for(int i=0;i<n;i+=2){int x=p[i]-'a',y=p[i+1]-'a';ct[i]=(char)('a'+mod(9*x+4*y,26));ct[i+1]=(char)('a'+mod(5*x+7*y,26));}ct[n]=0;printf("Ciphertext: %s\n",ct);printf("Decrypted plaintext: ");hill2(ct,9,4,5,7,1);}
int main(void){ OSSL_PROVIDER_load(NULL,"default"); OSSL_PROVIDER_load(NULL,"legacy"); q12(); return 0; }
