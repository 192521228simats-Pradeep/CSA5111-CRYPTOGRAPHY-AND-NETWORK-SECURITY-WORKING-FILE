/* CSA5111 Question 9: independent executable */
#include "common/crypto_common.h"
undefined
int main(void){ OSSL_PROVIDER_load(NULL,"default"); OSSL_PROVIDER_load(NULL,"legacy"); q9(); return 0; }
