 #ifndef ADMIN_H
#define ADMIN_H

//STRUCT-AK


//FUNTZIOAK

int admin();

OROKORRA sortu_diska_bat();

void admin_datuak_aldatu(OROKORRA* admin, int kop);

void bistaratu_admin_guztiak(OROKORRA* admin, int zenbat_diska);
void bistaratu_admin_bat(OROKORRA admin);

void bistaratu_estilo_bateko_admin(OROKORRA* admin, int zenbat_admin, int estiloa);
void bistaratu_estiloa_admin(int estiloa);

void autoreka_bistaratu_admin(OROKORRA admin[], int kop);
void autorea_esan_admin(char autorea[]);

void zigiluka_bistaratu_admin(OROKORRA admin[], int kop);
void zigilua_esan_admin(char zigilua[]);

void data_batetik_aurrera_bistaratu_admin(OROKORRA admin[], int kop);
int urtea_esan_diska();

void admin_aurkitu(OROKORRA admin[], int kop);

int diru_handiena_pos(OROKORRA admin[], int kop);

int admin_ezabatu(OROKORRA admin[], int kop);
int admin_bat_ezabatu(OROKORRA admin[], char izena[], int kop);

float irabazi_guztien_batura(OROKORRA admin[], int kop);

#endif 