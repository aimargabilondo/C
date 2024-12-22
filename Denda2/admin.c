#include "orokorrak.h"
#include "admin.h"
#include "menua_admin.h"



int admin() {
    int aukera = 0, i = 0, kop_produktuak = 10;
    OROKORRA produktuak[MAX_DISKA];

    OROKORRA produktu_datu_basea[] = {
        {"The Dark Side of the Moon",                                    "Pink Floyd",      1973, 1, "Harvest Records",      35, 10},
        {"Abbey Road",                                                   "The Beatles",     1969, 0, "Apple Records",        30, 10},
        {"Thriller",                                                     "Michael Jackson", 1982, 2, "Epic Records",         30, 10},
        {"Rumours",                                                      "Fleetwood Mac",   1977, 0, "Warner Bros. Records", 30, 10},
        {"The Rise and Fall of Ziggy Stardust and the Spiders from Mars","David Bowie",     1972, 1, "RCA Records",          35,  9},
        {"A Night at the Opera",                                         "Queen",           1975, 3, "EMI",                  30,  9},
        {"Highway 61 Revisited",                                         "Bob Dylan",       1965, 4, "Columbia Records",     30,  8},
        {"Nevermind",                                                    "Nirvana",         1991, 5, "DGC Records",          35,  9},
        {"Kind of Blue",                                                 "Miles Davis",     1959, 6, "Columbia Records",     35, 10},
        {"OK Computer",                                                  "Radiohead",       1997, 5, "Parlophone",           35,  9},
    };
    for (int i = 0; i < kop_produktuak; i++) {
        produktuak[i] = produktu_datu_basea[i];
    }

    do {
        aukera = menua_admin();
        kop_produktuak = menua_exekutatu_admin(aukera, produktuak, kop_produktuak, MAX_DISKA);
    } while (aukera != IRTEN);
    return aukera;
}

OROKORRA sortu_diska_bat(){
    char str[MAX_STR];
    OROKORRA ret;
    printf("Diskaren izenburua?");
    fgets(ret.izenburua, MAX_STR, stdin);
    ret.izenburua[strlen(ret.izenburua) - 1] = '\0';

    printf("Diskaren autorea?");
    fgets(ret.autorea, MAX_STR, stdin);
    ret.autorea[strlen(ret.autorea) - 1] = '\0';

    printf("Diskaren prezioa?");
    fgets(str, MAX_STR, stdin);
    sscanf(str, "%f", &ret.dirua);

    printf("Diska grabatu zen urtea?");
    fgets(str, MAX_STR, stdin);
    sscanf(str, "%i", &ret.data);

    printf("Diskaren zigilua?");
    fgets(ret.zigilua, MAX_STR, stdin);
    ret.zigilua[strlen(ret.zigilua) - 1] = '\0';

    printf("Kalifikazioa (IMDB)?");
    fgets(str, MAX_STR, stdin);
    sscanf(str, "%f", &ret.kalifikazioa);

    printf("Esan diskoaren estiloa: \n");
    printf("0 - PopRock, 1 - ArtRock, 2 - Pop, 3 - Rock Progresiboa, 4 - FolckRock, 5 - Rock Alternatiboa, 6 - Jazz\n");
    fgets(str, MAX_STR, stdin);
    sscanf(str, "%i", &ret.estiloa);

    borratu_pantila();
    return ret;

}

void admin_datuak_aldatu(OROKORRA* admin, int kop){
    char izena[MAX_STR];
    izenaGaldetu(izena);

    int pos = 0;
    int aurkitua = 0;
    while (aurkitua == 0 && pos < kop) {
        if (strcmp(izena, admin[pos].izenburua) == 0) {
            aurkitua = 1;
        }
        else {
            pos++;
        }
    }
    if (aurkitua == 1) {
        printf("Modifikatu nahi duzun diskaren notak honako hauek dira: \n");
        bistaratu_admin_bat(admin[pos]);
        printf("=================================================\n");
        admin[pos] = sortu_diska_bat();
    }
    else {
        printf("Izen hori daukan diskarik ez dago.\n");
    }
}

void bistaratu_admin_guztiak(OROKORRA* admin, int zenbat_diska) {
    for (int i = 0; i < zenbat_diska; i++) {
        bistaratu_admin_bat(admin[i]);
    }
}
void bistaratu_admin_bat(OROKORRA admin){

    printf("===================PELIKULA INFO====================\n");
    printf("Izenburua: %s\n", admin.izenburua);
    printf("Zuzendaria: %s\n", admin.autorea);
    printf("Urtea: %i\n", admin.data);
    printf("Diru bilketa: %.2f€\n", admin.dirua);
    printf("Kalifikazioa (IMDB):%.2f\n", admin.kalifikazioa);

    bistaratu_estiloa_admin(admin.estiloa);

    jarraitu();
    borratu_pantila();
}

void bistaratu_estilo_bateko_admin(OROKORRA* admin, int zenbat_diska, int estiloa){
    for (int i = 0; i < zenbat_diska; i++) {
        if (admin[i].estiloa == estiloa) {
            printf("===================PELIKULA INFO====================\n");
            printf("Izenburua: %s\n", admin[i].izenburua);
            printf("Zuzendaria: %s\n", admin[i].autorea);
            printf("Urtea: %i\n", admin[i].data);
            printf("Diru bilketa: %.2f€\n", admin[i].dirua);
            printf("Kalifikazioa (IMDB):%.2f\n", admin[i].kalifikazioa);
            bistaratu_estiloa_admin(admin[i].estiloa);
        }
    }
}
void bistaratu_estiloa_admin(int estiloa){
    switch (estiloa) {
    case POPROCK:
        printf("-> Pop Rock motako diska. \n");
        break;
    case ARTROCK:
        printf("-> Art Rock motako diska.\n");
        break;
    case POP:
        printf("-> Pop motako diska.\n");
        break;
    case ROCKPROG:
        printf("-> Rock Progresibo motako diska.\n");
        break;
    case FOLCROCK:
        printf("-> Folc Rock motako diska.\n");
        break;
    case ROCKALT:
        printf("-> Rock Alternatibo motako diska.\n");
        break;
    case JAZZ:
        printf("-> Jazz motako diska.\n");
        break;
    default:
        printf("Diskaren generoa ez dago definituta.\n");
        break;
    }
}

void autoreka_bistaratu_admin(OROKORRA admin[], int kop) {
    int i = 0;
    char autorea[128];
    autorea_esan_admin(autorea);
    for (i = 0; i < kop; i++) {
        if (strcmp(autorea, admin[i].autorea) == 0) {
            printf("%s pelikulako autorea %s da.\n", admin[i].izenburua, admin[i].autorea);
        }
    }
}
void autorea_esan_admin(char autorea[]) {
    printf("Ezabatu nahi duzun pelikularen izena: ");
    fgets(autorea, MAX_STR, stdin);
    autorea[strlen(autorea) - 1] = '\0';
}

void zigiluka_bistaratu_admin(OROKORRA admin[], int kop) {
    int i = 0;
    char zigilua[MAX_STR];
    zigilua_esan_admin(zigilua);
    for (i = 0; i < kop; i++) {
        if (strcmp(zigilua, admin[i].zigilua) == 0) {
            printf("%s diska %s zigilua dauka.\n", admin[i].izenburua, zigilua);
        }
    }
}
void zigilua_esan_admin(char zigilua[]) {
    printf("Diskoaren zigilua esan: ");
    fgets(zigilua, MAX_STR, stdin);
    zigilua[strlen(zigilua) - 1] = '\0';
}

void data_batetik_aurrera_bistaratu_admin(OROKORRA admin[], int kop){
    int urtea = 0, i = 0;
    urtea = urtea_esan_diska();
    for (i = 0; i < kop; i++) {
        if (urtea <= admin[i].data) {
            printf("%s pelikula %d-tik aurrerago atera zen.\n", admin[i].izenburua, urtea);
        }
    }
}
int urtea_esan_diska() {
    char str[MAX_STR];
    int urtea = 0;
    printf("Esan urte bat: \n");
    fgets(str, MAX_STR, stdin);
    sscanf(str, "%d", &urtea);
    return urtea;
}

void admin_aurkitu(OROKORRA admin[], int kop) {
    char izena[MAX_STR];
    izenaGaldetu(izena);

    int pos = 0;
    int aurkitua = 0;
    while (aurkitua == 0 && pos < kop) {
        if (strcmp(izena, admin[pos].izenburua) == 0) {
            aurkitua = 1;
        }
        else {
            pos++;
        }
    }
    if (aurkitua == 1) {

        printf("Hemen dago aurkitu nahi zenuen diska: \n");
        bistaratu_admin_bat(admin[pos]);
    }
    else {
        printf("Izen hori daukan diskarik ez dago.\n");
    }
}

int diru_handiena_pos(OROKORRA admin[], int kop) {
    float j = admin[0].dirua;
    int i = 0, pos = 0;
    for (i = 1; i < kop; i++) {
        if (j < admin[i].dirua) {
            j = admin[i].dirua;
            pos = i;
        }
    }
    return pos;
}

int admin_ezabatu(OROKORRA admin[], int kop) {
    char izena[MAX_STR];
    izenaGaldetu(izena);
    kop = admin_bat_ezabatu(admin, izena, kop);
    return kop;
}
int admin_bat_ezabatu(OROKORRA admin[], char izena[], int kop) {
    int pos = 0;
    int aurkitua = 0;
    while (aurkitua == 0 && pos < kop) {
        if (strcmp(izena, admin[pos].izenburua) == 0) {
            aurkitua = 1;
        }
        else {

            pos++;
        }
    }
    if (aurkitua == 1) {
        int i = 0;
        for (i = pos; i < kop - 1; i++) {
            admin[i] = admin[i + 1];
        }
    }
    else {
        printf("Izenburu hori daukan ibilbiderik ez dago.\n");
    }
    kop--;
    return kop;
}

float irabazi_guztien_batura(OROKORRA admin[], int kop) {
    float irabazia = 0;
    int i = 0;
    for (i = 0; i < kop; i++) {
        irabazia += admin[i].dirua;
    }
    return irabazia;
}