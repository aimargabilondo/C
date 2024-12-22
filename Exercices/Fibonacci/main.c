#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int zen1 = 0, zen2 = 0, zen3 = 1, zen4 = 0;
    char str[128];

    printf("Eman fibonacci segidaren zenbaki bat:\n");
    scanf("%d", &zen1);

    for(int i = 2; i < zen1; i++)
    {
        zen4 = zen2 + zen3;

        zen2 = zen3;

        zen3 = zen4;
    }
    printf("\n %d zenbakia da", zen4);

    return 0;
}