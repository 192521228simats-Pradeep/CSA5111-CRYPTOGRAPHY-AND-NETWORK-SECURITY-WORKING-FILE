/* CSA5111 Question 2: independent executable */
#include "common/crypto_common.h"
static void q02(void){readstr("Plaintext: ",buf,sizeof buf);char key[MAXBUF];readstr("26-letter cipher alphabet or keyword: ",key,sizeof key);if(strlen(key)==26){int seen[26]={0},ok=1;for(int i=0;i<26;i++){if(!isalpha((unsigned char)key[i]))ok=0;else if(seen[toupper((unsigned char)key[i])-'A']++)ok=0;}if(!ok){puts("Cipher alphabet must contain each A-Z exactly once.");return;}for(int i=0;buf[i];i++){char c=buf[i];if(isalpha((unsigned char)c)){char o=key[toupper((unsigned char)c)-'A'];c=islower((unsigned char)c)?(char)tolower((unsigned char)o):o;}putchar(c);}puts("");}else substitution(buf,key,0);}
int main(void){ OSSL_PROVIDER_load(NULL,"default"); OSSL_PROVIDER_load(NULL,"legacy"); q02(); return 0; }
