/* CSA5111 Question 10: independent executable */
#include "common/crypto_common.h"
static void q10(void){static const char sq[25]={'m','f','h','i','k','u','n','o','p','q','z','v','w','x','y','e','l','a','r','g','d','s','t','b','c'};playfair_square("Must see you over Cadogan West. Coming at once.",sq,0);}
int main(void){ OSSL_PROVIDER_load(NULL,"default"); OSSL_PROVIDER_load(NULL,"legacy"); q10(); return 0; }
