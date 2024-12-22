#include <stdio.h>
#include <string.h>
#include "orokorrak.h"
#include "pertsonak.h"
#include "covid.h"

#define FITX_IZENA_GAIXOAK_ARRASATE "pertsonak.txt"
#define FITX_IZENA_EMAITZAK_ARRASATE "emaitzak.txt"
#define FITX_IZENA_ID_EMAITZA "datuak.txt"

int main() {
    PERTSONAK pertsonak[MAX_PERTSONAK];
    int kopurua=0;
    HERRIA herriak[MAX_PERTSONAK];
    int kop_herriak = 0;
    float desbideratzea = 0;
    float bataz = 0;

    printf("Datuak irakurtzera.\n");
    kopurua = erabiltzaileenInformazioaBete(FITX_IZENA_GAIXOAK_ARRASATE, FITX_IZENA_EMAITZAK_ARRASATE ,pertsonak);
    itxoin_eta_pantailagarbitu();

    printf("POSITIBOAK.\n");
    covidPositiboakPantailaratu(pertsonak, kopurua);
    itxoin_eta_pantailagarbitu();

    printf("Covid datuak fitxategian gordetzera.\n");
    covidDatuakFitxategianGorde(pertsonak, kopurua);
    itxoin_eta_pantailagarbitu();
//======================================================================
    printf("COVIB adib batazbestekoa kalkulatzera.\n");
    bataz = covidPositiboAdinBBkalkulatu(pertsonak, kopurua);
    desbideratzea = desbiazioEstandarraKalkulatu( pertsonak, kopurua, bataz);
    printf("Positiboen adin bataz Bestekoa: %2.2f urte\nDesbideratze estandarra: %2.2f\n", bataz, desbideratzea);
    itxoin_eta_pantailagarbitu();


    printf("Herrien datu aurkitzen...\n");
    kop_herriak = pertsonen_herriak_aurkitu(pertsonak , kopurua, herriak );
    herrien_positiboak_kalkulatu(herriak, kop_herriak, pertsonak, kopurua);
    herrien_egoera_kalkulatu(herriak, kop_herriak);


    printf("Herrien datuak bistaratzen..\n");
    datuakBistaratu(herriak, kop_herriak);
    itxoin_eta_pantailagarbitu();

    printf("Herrien datuak fitxategian gordetzen....\n");
    herrien_egoera_fitxategian(herriak, kop_herriak);
    itxoin_eta_pantailagarbitu();




    //herriz herri strcmp gogoratu ikasleei

    printf("Sakatu return amaitzeko.....");
    getchar();
    return 0;

}
