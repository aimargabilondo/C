#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int i = 0, zen1 = 0, zen2 = 0, zen3 = 0, zen4 = 0;
    char str[128];

    printf("Eman zenbaki bat:");
    scanf("%d", &zen1);

    zen2 = zen1;

    zen3 = zen1;

    for (i = 1; i < zen2; i++)
    {
        zen3 = zen3 - 1;
        zen1 = zen1 * zen3;

    }
    printf("\n %d exponentziala %d da", zen2, zen1);

    return 0;
}