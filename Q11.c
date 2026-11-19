/* CSA5111 Question 11: independent executable */
#include "common/crypto_common.h"
static void q11(void){double lg=0;for(int i=2;i<=25;i++)lg+=log2((double)i);printf("Raw squares: 25!; log2(25!)=%.5f bits.\n",lg);printf("At least 25 squares are equivalent under cyclic shifts of the five rows and five columns, so quotient by this 5x5 translation symmetry: 25!/25 = 24! (about 2^%.5f).\n",lg-log2(25.0));puts("This effective count uses only the guaranteed global row/column-rotation equivalence; other conventions may count further symmetries differently.");}
int main(void){ OSSL_PROVIDER_load(NULL,"default"); OSSL_PROVIDER_load(NULL,"legacy"); q11(); return 0; }
