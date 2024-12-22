// OROKORRAK.H
#ifndef OROKORRAK_H
#define OROKORRAK_H

#include "pertsonak.h"

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#define FITX_IZENA_GAIXOAK_ARRASATE "pertsonak.txt"
#define FITX_IZENA_EMAITZAK_ARRASATE "emaitzak.txt"
#define FITX_IZENA_ID_EMAITZA "datuak.txt"

#define MAX_HERRIAK 100

typedef struct {
    char izena[50];
    int positiboak;
    int ezgaitasunak;
    int biziak;
} HERRIA;

int erabiltzaileenInformazioaBete(const char fitxIzenaErab[], const char fitxIzenaEmaitzak[], PERTSONAK pertsonak[]);
void covidDatuakFitxategianGorde(PERTSONAK pertsonak[], int kopurua);
void covidPositiboakPantailaratu(PERTSONAK pertsonak[], int kopurua);
void datuakBistaratu(HERRIA datuak[], int kop);
void itxoin_eta_pantailagarbitu();

#endif  // OROKORRAK_H
