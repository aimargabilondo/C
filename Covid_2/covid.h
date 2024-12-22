//COVID.H
#include "orokorrak.h"
#include "pertsonak.h"

int aurkitu_herria(char herria[], HERRIA herriak[], int kop);
int pertsonen_herriak_aurkitu(PERTSONAK pertsonak[], int kopurua, HERRIA herriak[]);
void herrien_positiboak_kalkulatu(HERRIA herriak[], int kop_herriak, PERTSONAK pertsonak[], int kop);
void herrien_egoera_kalkulatu(HERRIA herriak[], int kop_herriak);
void herrien_egoera_fitxategian(HERRIA datuak[], int kop);
//PERTSONAK.H
float covidPositiboAdinBBkalkulatu(PERTSONAK pertsonak[], int kopurua);
float desbiazioEstandarraKalkulatu(PERTSONAK pertsonak[], int kopurua, int BB);

