//PERTSONAK.C
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "orokorrak.h"
#include "pertsonak.h"

float covidPositiboAdinBBkalkulatu(PERTSONAK pertsonak[], int kopurua) {
    int i, positiboak = 0;
    float adina = 0;

    for (i = 0; i < kopurua; i++) {
        if (pertsonak[i].positiboa == 1) {
            positiboak++;
            adina += pertsonak[i].adina;
        }
    }

    if (positiboak != 0) {
        adina /= positiboak;
    }

    return adina;
}

float desbiazioEstandarraKalkulatu(PERTSONAK pertsonak[], int kopurua, int BB) {
    int i;
    float bataz = 0, desbiazio = 0;

    for (i = 0; i < kopurua; i++) {
        if (pertsonak[i].positiboa == 1) {
            bataz += (pertsonak[i].adina - BB) * (pertsonak[i].adina - BB);
        }
    }

    bataz /= kopurua;
    desbiazio = sqrt(bataz);

    return desbiazio;
}
