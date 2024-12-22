#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char izena[100];
    long tamaina;

    FILE * fitxategia = fopen("tamana.txt", "rb");

    int ondo = fitxategia;
    if (ondo == 0) {
        return 0; 
    }

    fseek(fitxategia, 0, SEEK_END);
    tamaina = ftell(fitxategia);

    fclose(fitxategia);

    printf("Fitxategiaren tamaina: %ld byte\n", tamaina);

    return 0;
}
