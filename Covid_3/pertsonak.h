#ifndef PERTSONAK_H
#define PERTSONAK_H
typedef struct pertsonak {
    int id;
    char izena[MAX_STR];
    char abizena[MAX_STR];
    int adina;
    char herria[MAX_STR];
    char egoera;

}PERTSONAK;

int erabiltzaileenInformazioaBete(char fitx_izena_gaixoak[],  char fitx_izena_emaitzak[], PERTSONAK pertsonak[]);
void pertsonaBatPantailaratu(PERTSONAK pertsona);

void covidPositiboakPantailaratu(PERTSONAK pertsonak[], int kopurua);
void covidDatuakFitxategianGorde(PERTSONAK pertsonak[], int kopurua);

float  covidPositiboAdinBBkalkulatu(PERTSONAK pertsonak[], int kopurua);
float desbiazioEstandarraKalkulatu(PERTSONAK pertsonak[], int kopurua, int BB);


#endif
