// PERTSONAK.H
#ifndef PERTSONAK_H
#define PERTSONAK_H

#define MAX_PERTSONAK 100

typedef struct {
    char izena[50];
    char herria[50];
    int adina;
    int positiboa;
} PERTSONAK;

float covidPositiboAdinBBkalkulatu(PERTSONAK pertsonak[], int kopurua);
float desbiazioEstandarraKalkulatu(PERTSONAK pertsonak[], int kopurua, int BB);

#endif  // PERTSONAK_H
