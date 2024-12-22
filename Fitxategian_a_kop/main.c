#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 128

int main() {
    FILE* fitxategia = fopen("a_kop.txt", "r");
    
    char karakterea;
    int a_kopurua = 0;

    int ondo = fitxategia;
    if (ondo == 0) {
        return 0; // Hutsa itzuli, ez dago datuak prozesatzeko
    }

    while ((karakterea = fgetc(fitxategia)) != EOF) {
        // 'a' karakterea aurkitu
        if (karakterea == 'a' || karakterea == 'A') {
            a_kopurua++;
        }
    }

    printf("%d a daude fitxategian", a_kopurua);
    fclose(fitxategia);
    return 0;
}