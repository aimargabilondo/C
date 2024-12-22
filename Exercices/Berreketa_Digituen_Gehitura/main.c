#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int i = 0, zen1 = 0, zen2 = 0, zen3 = 1, zen4 = 0, digitu = 0, batura = 0;
    char str[128];

    printf("Eman zenbaki bat:");
    scanf("%d", &zen1);

    printf("Eman zenbaki bat:");
    scanf("%d", &zen2);

    zen4 = zen1;
    zen3 = zen4;
    for (int i = 1; i < zen2; i++)
    {
        zen3 = zen3 * zen4;

    }

    while (zen3 != 0) {
        digitu = zen3 % 10; 
        batura += digitu;
        zen3 /= 10; 
    }

    printf("\n%d da berreketarem dijituen batura", batura);

    return 0;

}