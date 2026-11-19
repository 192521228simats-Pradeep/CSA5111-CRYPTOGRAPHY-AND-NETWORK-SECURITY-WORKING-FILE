/* CSA5111 Question 8: independent executable */
#include "common/crypto_common.h"
undefined
int main(void){ OSSL_PROVIDER_load(NULL,"default"); OSSL_PROVIDER_load(NULL,"legacy"); q8(); return 0; }
