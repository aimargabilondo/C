#ifndef EROSLEA_H
#define EROSLEA_H

//STRUCT-AK

typedef struct Dirua {
    int erabiltzeko;
    int erabilita;
}DIRUA;


typedef enum e_diskoak { ATERA, BEATLES, PINKFLOYD, JACKSON, FLEETWOOD, DAVID, QUEEN, BODDYLAN, NIRVANA, MILESDAVIS, RADIOHEAD }DISKOAK;

//FUNTZIOAK

int erosleak();

OROKORRA sortu_erosketa_bat(int diru_kop);

void erosketa_datuak_aldatu(OROKORRA* erosketa, int kop, int diru_kop);

void bistaratu_erosketa_guztiak(OROKORRA* erosketa, int zenbat_erosketa);
void bistaratu_erosketa_bat(OROKORRA erosketa);

int bistaratu_stocka_erosteko();
int aukeratu_stocka(int aukera);

void bistaratu_stocka();

void bistaratu_estilo_bateko_erosketa(OROKORRA* erosketa, int zenbat_erosketa, int estiloa);
void bistaratu_estiloa_erosketa(int estiloa);

void autoreka_bistaratu_erosketa(OROKORRA erosketa[], int kop);
void autorea_esan_erosketa(char autorea[]);

void zigiluka_bistaratu_erosketa(OROKORRA erosketa[], int kop);
void zigilua_esan_erosketa(char zigilua[]);

void data_batetik_aurrera_bistaratu_erosketa(OROKORRA erosketa[], int kop);
int urtea_esan_erosketa();

void erosketa_aurkitu(OROKORRA erosketa[], int kop);

int erosketa_ezabatu(OROKORRA erosketa[], int kop);
int erosketa_bat_ezabatu(OROKORRA erosketa[], char izena[], int kop);

#endif 