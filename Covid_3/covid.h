#ifndef COVID_H
#define COVID_H

#define MAX_HERRIAK 10

typedef enum Egoera {BERDEA,LARANJA, GORRIA}EGOERA;

typedef struct Herria {
    char herria[MAX_STR];
    int positiboKopurua;
    EGOERA egoera;
}HERRIA;


int datuenArrayaBete(PERTSONAK pertsonak[], int kopurua, HERRIA herriak[]);
void datuakBistaratu(HERRIA datuak[], int datuKopurua);
void guneakBistaratu(HERRIA datuak);


int aurkitu_herria(char herria [], HERRIA herriak[], int kop);
int  pertsonen_herriak_aurkitu(PERTSONAK pertsonak[] , int kopurua , HERRIA herriak []);
void herrien_positiboak_kalkulatu(HERRIA herriak[], int kop_herriak, PERTSONAK pertsonak[], int kop);
void herrien_egoera_kalkulatu(HERRIA herriak[], int kop_herriak);
void herrien_egoera_fitxategian(HERRIA datuak[], int kop);

#endif
