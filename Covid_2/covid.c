//COVID.C
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "orokorrak.h"
#include "pertsonak.h"
#include "covid.h"

void herrien_egoera_fitxategian(HERRIA datuak[], int kop) {
    FILE* fitx;
    int i;

    fitx = fopen(FITX_IZENA_ID_EMAITZA, "w");
    if (fitx == NULL) {
        printf("Errorea fitxategia sortzean.");
        return;
    }

    for (i = 0; i < kop; i++) {
        fprintf(fitx, "%s\t%d\t%d\t%d\n", datuak[i].izena, datuak[i].positiboak, datuak[i].ezgaitasunak, datuak[i].biziak);
    }

    fclose(fitx);
}

void herrien_egoera_kalkulatu(HERRIA herriak[], int kop_herriak) {
    int i;

    for (i = 0; i < kop_herriak; i++) {
        herriak[i].positiboak = herriak[i].biziak - herriak[i].ezgaitasunak;
    }
}

void herrien_positiboak_kalkulatu(HERRIA herriak[], int kop_herriak, PERTSONAK pertsonak[], int kop) {
    int i, j;

    for (i = 0; i < kop_herriak; i++) {
        herriak[i].positiboak = 0;
        for (j = 0; j < kop; j++) {
            if (strcmp(herriak[i].izena, pertsonak[j].herria) == 0 && pertsonak[j].positiboa == 1) {
                herriak[i].positiboak++;
            }
        }
    }
}

int pertsonen_herriak_aurkitu(PERTSONAK pertsonak[], int kopurua, HERRIA herriak[]) {
    int i, j, kop_herriak = 0;
    int aurkitua;

    for (i = 0; i < kopurua; i++) {
        aurkitua = 0;
        for (j = 0; j < kop_herriak; j++) {
            if (strcmp(pertsonak[i].herria, herriak[j].izena) == 0) {
                aurkitua = 1;
                break;
            }
        }
        if (aurkitua == 0) {
            strcpy(herriak[kop_herriak].izena, pertsonak[i].herria);
            kop_herriak++;
        }
    }

    return kop_herriak;
}

int aurkitu_herria(char herria[], HERRIA herriak[], int kop) {
    int i;

    for (i = 0; i < kop; i++) {
        if (strcmp(herria, herriak[i].izena) == 0) {
            return 1;
        }
    }

    return 0;
}
