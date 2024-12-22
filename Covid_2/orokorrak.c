// OROKORRAK.C
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "orokorrak.h"

int erabiltzaileenInformazioaBete(const char fitxIzenaErab[], const char fitxIzenaEmaitzak[], PERTSONAK pertsonak[]) {
    FILE* fitxErab, * fitxEmaitzak;
    int kopurua = 0;
    char izena[50], herria[50];
    int adina, positiboa;

    fitxErab = fopen(fitxIzenaErab, "r");
    if (fitxErab == NULL) {
        printf("Errorea erabiltzaileen fitxategia irakurtzean.\n");
        return 0;
    }

    fitxEmaitzak = fopen(fitxIzenaEmaitzak, "r");
    if (fitxEmaitzak == NULL) {
        printf("Errorea emaitzen fitxategia irakurtzean.\n");
        fclose(fitxErab);
        return 0;
    }

    while (fscanf(fitxErab, "%s %s %d", izena, herria, &adina) == 3 && fscanf(fitxEmaitzak, "%d", &positiboa) == 1) {
        strcpy(pertsonak[kopurua].izena, izena);
        strcpy(pertsonak[kopurua].herria, herria);
        pertsonak[kopurua].adina = adina;
        pertsonak[kopurua].positiboa = positiboa;
        kopurua++;
    }

    fclose(fitxErab);
    fclose(fitxEmaitzak);

    return kopurua;
}

void covidDatuakFitxategianGorde(PERTSONAK pertsonak[], int kopurua) {
    FILE* fitx;
    int i;

    fitx = fopen(FITX_IZENA_EMAITZAK_ARRASATE, "w");
    if (fitx == NULL) {
        printf("Errorea fitxategia sortzean.");
        return;
    }

    for (i = 0; i < kopurua; i++) {
        fprintf(fitx, "%s\t%s\t%d\t%d\n", pertsonak[i].izena, pertsonak[i].herria, pertsonak[i].adina, pertsonak[i].positiboa);
    }

    fclose(fitx);
}

void covidPositiboakPantailaratu(PERTSONAK pertsonak[], int kopurua) {
    int i;

    for (i = 0; i < kopurua; i++) {
        if (pertsonak[i].positiboa == 1) {
            printf("%s\t%s\t%d\t%d\n", pertsonak[i].izena, pertsonak[i].herria, pertsonak[i].adina, pertsonak[i].positiboa);
        }
    }
}

void datuakBistaratu(HERRIA datuak[], int kop) {
    int i;

    for (i = 0; i < kop; i++) {
        printf("%s\t%d\t%d\t%d\n", datuak[i].izena, datuak[i].positiboak, datuak[i].ezgaitasunak, datuak[i].biziak);
    }
}

void itxoin_eta_pantailagarbitu() {
    // Pantailaren garbitzea egin
    system("cls");
}
