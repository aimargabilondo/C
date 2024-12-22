#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int n, i = 0, j = 0;
    char str[128];

    printf("Emaidazu zenbaki bat: ");
    fgets(str, 128, stdin);
    sscanf(str, "%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    for (i = n - 1; i >= 1; i--) {
        for (j = i; j >= 1; j--) {
            printf("*");
        }
        printf("\n");
    }


    return 0;
}