#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ZENBAKIAK 100

int main() {
    char izena[100];
    int zenbakiak[MAX_ZENBAKIAK];
    int kopurua = 0;

    FILE* fitxategia = fopen("zenbakiak.txt", "r");

    char karakterea;

    if (fitxategia == NULL) {
        printf("Errorea: Fitxategia ez da existitzen.\n");
        return 0;
    }

    while (fscanf(fitxategia, "%d", &zenbakiak[kopurua]) == 1) {
        kopurua++;
        if (kopurua >= MAX_ZENBAKIAK) {
            printf("Errorea: Fitxategian 100 zenbaki baino gehiago daude.\n");
            fclose(fitxategia);
            return 0;  
        }
    }

    for (int i = 0; i < kopurua - 1; i++) {
        for (int j = i + 1; j < kopurua; j++) {
            if (zenbakiak[i] > zenbakiak[j]) {
                int tmp = zenbakiak[i];
                zenbakiak[i] = zenbakiak[j];
                zenbakiak[j] = tmp;
            }
        }
    }

    fclose(fitxategia);

    printf("Zenbakiak txikitik handira ordenatuta:\n");
    for (int i = 0; i < kopurua; i++) {
        printf("%d\n", zenbakiak[i]);
    }

    fitxategia = fopen("zenbakiak.txt", "w");

    if (fitxategia == NULL) {
        printf("Errorea: Fitxategia ezin da zabaldu idazteko.\n");
        return 0;  
    }

    for (int i = 0; i < kopurua; i++) {
        fprintf(fitxategia, "%d\n", zenbakiak[i]);
    }

    fclose(fitxategia);

    return 0;
}
