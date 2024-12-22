#ifndef HERRIALDEAK_H
#define HERRIALDEAK_H

//STRUCT-AK
typedef struct Eguna {
    char ordua[MAX_STR];
    int ip_1;
    int ip_2;
    int ip_3;
    int ip_4;
    char protokoloa[MAX_STR];
    int mugimenduak;
}EGUNA;

typedef struct Herrialdeak {
    int ip_1;
    int ip_2;
    int ip_3;
    int ip_4;
    char herrialdea[MAX_STR];
    int kopurua;
    EGUNA egun;
}HERRIALDEAK;

//FUNTZIOAK

HERRIALDEAK sortu_herrialde_bat();

int herrialde_datuak_aldatu(HERRIALDEAK* orde, int kop);
void izenaGaldetu(char izena[], char hitz[]);

void bistaratu_herrialde_guztiak(HERRIALDEAK* orde, int kop);
void bistaratu_herrialde_bat(HERRIALDEAK orde);

void fitxategia_irakurri(HERRIALDEAK* herri, int kop);
void fitxategia_irakurri_herrialdeak(HERRIALDEAK* orde, int kop);

void konexioak_kontatu(HERRIALDEAK* herri, int kop);
void bezeroak_fitxategian_idatzi(HERRIALDEAK* herri, int kop);

void ordenatu(HERRIALDEAK* herri, int kop);

#endif 

