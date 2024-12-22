#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int zen1 = 0, zen2 = 0, zen3 = 0, zen4 = 0;
    char str[128];

    printf("Eman zenbaki bat:\n");
    scanf("%d", &zen1);

    printf("Eman zenbaki bat:\n");
    scanf("%d", &zen2);

    zen4 = zen1;
    zen3 = zen4;
    for (int i = 1; i < zen2; i++)
    {
        zen3 = zen3 * zen4;
        
    }
    printf("\n %d zenbakia ber %d = %d da", zen1, zen2, zen3);

    return 0;
}