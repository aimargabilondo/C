#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int zenbakiak[10];
    int i;
    int maximoa, minimoa;
    float media = 0;

    for (i = 0; i < 10; i++) {
        printf("Sartu %d. zenbakia: ", i + 1);
        scanf("%d", &zenbakiak[i]);
        media += zenbakiak[i];
    }

    media /= 10;

    maximoa = minimoa = zenbakiak[0];
    for (i = 1; i < 10; i++) {
        if (zenbakiak[i] > maximoa) {
            maximoa = zenbakiak[i];
        }
        if (zenbakiak[i] < minimoa) {
            minimoa = zenbakiak[i];
        }
    }

    printf("Zenbakiak: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", zenbakiak[i]);
    }
    printf("\nMedia: %f\n", media);
    printf("Maximoa: %d\n", maximoa);
    printf("Minimoa: %d\n", minimoa);

    return 0;
}