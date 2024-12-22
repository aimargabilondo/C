#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int i = 0, zen1 = 0, zen2 = 0, zen3 = 1;
    char str[128];

    printf("Eman zenbaki bat:");
    scanf("%d", &zen1);

    zen2 = zen1;

        for (i = 2; i <= zen1 / 2; i++)
        {
            if (zen2 % i == 0) {
                zen3 = i + zen3;
            }
        }
    
    if (zen3 == zen2) {
        printf("\n %d perfektua da", zen3);
    }
    else {
        printf("\n ez da perfektua");
    }

    return 0;

}