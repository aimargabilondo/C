#include <stdio.h>

#define FALSE 0
#define TRUE 1

int main() {
    int zenbaia = 5;
    int egoera = FALSE;
    int emaitza = 0;

    egoera = factoriala(zenbaia, &emaitza);

    return 0;
}

int factoriala(int zenb, int* hel_emaitza) {
    int i = 0;

    int ret = FALSE;

    if (zenb >= 0) {
        ret = TRUE;
        for (i = 1; i <= zenb; i++) {
            *hel_emaitza = *hel_emaitza * i;
        }
    }
    else {
        ret = FALSE;
        faktoriala = 0;
        *hel_emaitza = 0;
    }
}