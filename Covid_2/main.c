#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "orokorrak.h"
#include "pertsonak.h"
#include "covid.h"


int main() {
    PERTSONAK pertsonak[MAX_PERTSONAK];
    int kopurua = 0;
    HERRIA herriak[MAX_PERTSONAK];
    int kop_herriak = 0;
    float desbideratzea = 0;
    float bataz = 0;

    printf("Datuak irakurtzera.\n");
    kopurua = erabiltzaileenInformazioaBete(FITX_IZENA_GAIXOAK_ARRASATE, FITX_IZENA_EMAITZAK_ARRASATE, pertsonak);

    printf("POSITIBOAK.\n");
    covidPositiboakPantailaratu(pertsonak, kopurua);

    printf("Covid datuak fitxategian gordetzera.\n");
    covidDatuakFitxategianGorde(pertsonak, kopurua);

    //=========================HEMENDIK BEHERAKO FUNTZIOAK EGIN BEHAR DITUZUE======================
    printf("COVIB adib batazbestekoa kalkulatzera.\n");
    bataz = covidPositiboAdinBBkalkulatu(pertsonak, kopurua);
    desbideratzea = desbiazioEstandarraKalkulatu(pertsonak, kopurua, bataz);
    printf("Positiboen adin bataz Bestekoa: %2.2f urte\nDesbideratze estandarra: %2.2f\n", bataz, desbideratzea);

    printf("Herrien datu aurkitzen...\n");
    kop_herriak = pertsonen_herriak_aurkitu(pertsonak, kopurua, herriak);
    herrien_positiboak_kalkulatu(herriak, kop_herriak, pertsonak, kopurua);
    herrien_egoera_kalkulatu(herriak, kop_herriak);

    printf("Herrien datuak bistaratzen..\n");
    datuakBistaratu(herriak, kop_herriak);

    printf("Herrien datuak fitxategian gordetzen....\n");
    herrien_egoera_fitxategian(herriak, kop_herriak);

    printf("Sakatu return amaitzeko.....");
    getchar();
    return 0;
}
