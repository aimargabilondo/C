#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int i = 0, zen1 = 0, zen2 = 0, zen3 = 1;
    char str[128];

    printf("Eman zenbaki bat:");
    scanf("%d", &zen1);

    zen2 = zen1;

    if (zen2 <= 1) {
        printf("\n %d ez lehena da", zen1);
        return 0;
    }
    else {
        for (i = 2; i < zen1 - 1; i++)
        {
            if (zen2 % i == 0) {
                zen3 = 0;
                break;
            }
        }
    }
    if (zen3) {
       printf("\n %d lehena da", zen1);
    }
    else {
       printf("\n %d ez da lehena", zen1);
    }
    return 0;
}
