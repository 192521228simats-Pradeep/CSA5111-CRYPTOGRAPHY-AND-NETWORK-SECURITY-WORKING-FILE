/* CSA5111 Question 2: independent executable */
#include "common/crypto_common.h"
undefined
int main(void){ OSSL_PROVIDER_load(NULL,"default"); OSSL_PROVIDER_load(NULL,"legacy"); q2(); return 0; }
