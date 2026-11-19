/* CSA5111 Question 7: independent executable */
#include "common/crypto_common.h"
undefined
int main(void){ OSSL_PROVIDER_load(NULL,"default"); OSSL_PROVIDER_load(NULL,"legacy"); q7(); return 0; }
