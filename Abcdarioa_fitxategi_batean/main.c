#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 128

int main() {
    FILE* fitxategia = fopen("abc.txt", "w");
    
    char karakterea;

    if (fitxategia == NULL) {
        printf("Errorea: Fitxategia ez da existitzen.\n");
        return 0;  
    }

    for (karakterea = 'A'; karakterea <= 'Z'; karakterea++) {
        fprintf(fitxategia, "%c", karakterea);
    }
    fprintf(fitxategia, "\n");
    for (karakterea = 'a'; karakterea <= 'z'; karakterea++) {
        fprintf(fitxategia, "%c", karakterea);
    }

    fclose(fitxategia);

    return 0;
}
