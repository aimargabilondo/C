#include "orokorrak.h"
#include "eroslea.h"
#include "menua_eroslea.h"

int erosleak() {
    char str[MAX_STR];
    DIRUA dirua;
    int aukera = 0, i = 0, zenbat_erosketa = 0;
    OROKORRA erosketa[MAX_EROSKETA];

    printf("Zenbat diru daukazu gastatzeko: ");
    fgets(str, MAX_STR, stdin);
    sscanf(str, "%i", &dirua.erabiltzeko);
    dirua.erabilita = 0;

    do {
        aukera = menua_eroslea();
        zenbat_erosketa = menua_exekutatu_eroslea(aukera, erosketa, zenbat_erosketa, dirua.erabiltzeko, &dirua.erabilita, MAX_EROSKETA);
    } while (aukera != IRTEN);
    return aukera;
}


OROKORRA sortu_erosketa_bat(int diru_kop) {
    char str[MAX_STR];
    OROKORRA ret;
    printf("Diskaren izenburua?");
    fgets(ret.izenburua, MAX_STR, stdin);
    ret.izenburua[strlen(ret.izenburua) - 1] = '\0';

    printf("Diskaren autorea?");
    fgets(ret.autorea, MAX_STR, stdin);
    ret.autorea[strlen(ret.autorea) - 1] = '\0';

    do {
        printf("Diskaren prezioa?");
        fgets(str, MAX_STR, stdin);
        sscanf(str, "%f", &ret.dirua);
        if (ret.dirua > diru_kop) {
            printf("Ezin duzu %d baino gehiago gastatu\n", diru_kop);
        }
    } while (ret.dirua > diru_kop);

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

void erosketa_datuak_aldatu(OROKORRA* erosketa, int kop, int diru_kop) {
    char izena[MAX_STR];
    izenaGaldetu(izena);

    int pos = 0;
    int aurkitua = 0;
    while (aurkitua == 0 && pos < kop) {
        if (strcmp(izena, erosketa[pos].izenburua) == 0) {
            aurkitua = 1;
        }
        else {
            pos++;
        }
    }
    if (aurkitua == 1) {
        printf("Modifikatu nahi duzun pelikularen notak honako hauek dira: \n");
        bistaratu_erosketa_bat(erosketa[pos]);
        printf("=================================================\n");
        erosketa[pos] = sortu_erosketa_bat(diru_kop);
    }
    else {
        printf("Izen hori daukan ikaslerik ez dago.\n");
    }
}

void bistaratu_erosketa_guztiak(OROKORRA* erosketa, int zenbat_erosketa) {
    for (int i = 0; i < zenbat_erosketa; i++) {
        bistaratu_erosketa_bat(erosketa[i]);
    }
}
void bistaratu_erosketa_bat(OROKORRA erosketa) {
    printf("===================PELIKULA INFO====================\n");
    printf("Izenburua: %s\n", erosketa.izenburua);
    printf("Zuzendaria: %s\n", erosketa.autorea);
    printf("Urtea: %i\n", erosketa.data);
    printf("Diru bilketa: %.2f€\n", erosketa.dirua);
    printf("Kalifikazioa (IMDB):%.2f\n", erosketa.kalifikazioa);

    bistaratu_estiloa_erosketa(erosketa.estiloa);

    jarraitu();
    borratu_pantila();
}

int bistaratu_stocka_erosteko() {
    //ALDAGAIAK
    char str[MAX_STR];
    int ret = 0;
    //PROGRAMA
    printf("************************EROSTEKO PRODUKTUAK************************\n");
    printf("|1 - The Beatles - Abbey Road \n");
    printf("|2 - Pink Floyd - The Dark Side of the Moon \n");
    printf("|3 - Michael Jackson - Thriller \n");
    printf("|4 - Fleetwood Mac - Rumours\n");
    printf("|5 - David Bowie - The Rise and Fall of Ziggy Stardust and the Spiders from Mars\n");
    printf("|6 - Queen - A Night at the Opera\n");
    printf("|7 - Bob Dylan - Highway 61 Revisited \n");
    printf("|8 - Nirvana - Nevermind\n");
    printf("|9 - Miles Davis - Kind of Blue \n");
    printf("|10 - Radiohead - OK Computer \n");
    printf("********************************************\n");
    do {
        printf("Zer nahi duzu egin(1-9)?: ");
        fgets(str, MAX_STR, stdin);
        sscanf(str, "%i", &ret);
        if (!(ret >= 1 && ret <= 10)) {
            printf("ERROREA: Aukera desegokia. Mesedez 1-9 arteko balore bat.\n");
        }
    } while (ret < 1 || ret > 10);

    //BUKAERA
    return ret;
}
int aukeratu_stocka(int aukera) {
    int prezioa = 0;
    switch (aukera) {
    case BEATLES:
        prezioa = 30;
        break;
    case PINKFLOYD:
        prezioa = 35;
        break;
    case JACKSON:
        prezioa = 30;
        break;
    case FLEETWOOD:
        prezioa = 30;
        break;
    case DAVID:
        prezioa = 35;
        break;
    case QUEEN:
        prezioa = 30;
        break;
    case BODDYLAN:
        prezioa = 30;
        break;
    case NIRVANA:
        prezioa = 35;
        break;
    case MILESDAVIS:
        prezioa = 35;
        break;
    case RADIOHEAD:
        prezioa = 35;
        break;
    default:
        printf("Aukera hori ez da existitzen.\n");
        break;
    }
    jarraitu();
    borratu_pantila();

    return prezioa;
}

void bistaratu_stocka() {
    printf("************************EROSTEKO PRODUKTUAK************************\n");
    printf("|1 - The Beatles - Abbey Road \n");
    printf("|2 - Pink Floyd - The Dark Side of the Moon \n");
    printf("|3 - Michael Jackson - Thriller \n");
    printf("|4 - Fleetwood Mac - Rumours\n");
    printf("|5 - David Bowie - The Rise and Fall of Ziggy Stardust and the Spiders from Mars\n");
    printf("|6 - Queen - A Night at the Opera\n");
    printf("|7 - Bob Dylan - Highway 61 Revisited \n");
    printf("|8 - Nirvana - Nevermind\n");
    printf("|9 - Miles Davis - Kind of Blue \n");
    printf("|10 - Radiohead - OK Computer \n");
    printf("********************************************\n");

    jarraitu();
    borratu_pantila();
}

void bistaratu_estilo_bateko_erosketa(OROKORRA* erosketa, int zenbat_erosketa, int estiloa) {
    for (int i = 0; i < zenbat_erosketa; i++) {
        if (erosketa[i].estiloa == estiloa) {
            printf("===================PELIKULA INFO====================\n");
            printf("Izenburua: %s\n", erosketa[i].izenburua);
            printf("Zuzendaria: %s\n", erosketa[i].autorea);
            printf("Urtea: %i\n", erosketa[i].data);
            printf("Diru bilketa: %.2f€\n", erosketa[i].dirua);
            printf("Kalifikazioa (IMDB):%.2f\n", erosketa[i].kalifikazioa);
            bistaratu_estiloa_erosketa(erosketa[i].estiloa);
        }
    }
}
void bistaratu_estiloa_erosketa(int estiloa) {
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

void autoreka_bistaratu_erosketa(OROKORRA erosketa[], int kop) {
    int i = 0;
    char autorea[64];
    autorea_esan_erosketa(autorea);
    for (i = 0; i < kop; i++) {
        if (strcmp(autorea, erosketa[i].autorea) == 0) {
            printf("%s pelikulako autorea %s da.\n", erosketa[i].izenburua, erosketa[i].autorea);
        }
    }
}
void autorea_esan_erosketa(char autorea[]) {
    printf("Ezabatu nahi duzun pelikularen izena: ");
    fgets(autorea, MAX_STR, stdin);
    autorea[strlen(autorea) - 1] = '\0';
}

void zigiluka_bistaratu_erosketa(OROKORRA erosketa[], int kop) {
    int i = 0;
    char zigilua[MAX_STR];
    zigilua_esan_erosketa(zigilua);
    for (i = 0; i < kop; i++) {
        if (strcmp(zigilua, erosketa[i].zigilua) == 0) {
            printf("%s diska %s zigilua dauka.\n", erosketa[i].izenburua, zigilua);
        }
    }
}
void zigilua_esan_erosketa(char zigilua[]) {
    printf("Diskoaren zigilua esan: ");
    fgets(zigilua, MAX_STR, stdin);
    zigilua[strlen(zigilua) - 1] = '\0';
}

void data_batetik_aurrera_bistaratu_erosketa(OROKORRA erosketa[], int kop) {
    int urtea = 0, i = 0;
    urtea = urtea_esan_erosketa();
    for (i = 0; i < kop; i++) {
        if (urtea <= erosketa[i].data) {
            printf("%s pelikula %d-tik aurrerago atera zen.\n", erosketa[i].izenburua, urtea);
        }
    }
}
int urtea_esan_erosketa() {
    char str[MAX_STR];
    int urtea = 0;
    printf("Esan urte bat: \n");
    fgets(str, MAX_STR, stdin);
    sscanf(str, "%d", &urtea);
    return urtea;
}

void erosketa_aurkitu(OROKORRA erosketa[], int kop) {
    char izena[MAX_STR];
    izenaGaldetu(izena);

    int pos = 0;
    int aurkitua = 0;
    while (aurkitua == 0 && pos < kop) {
        if (strcmp(izena, erosketa[pos].izenburua) == 0) {
            aurkitua = 1;
        }
        else {
            pos++;
        }
    }
    if (aurkitua == 1) {

        printf("Hemen dago aurkitu nahi zenuen erosketa: \n");
        bistaratu_erosketa_bat(erosketa[pos]);
    }
    else {
        printf("Izen hori daukan diskarik ez dago.\n");
    }
}

int erosketa_ezabatu(OROKORRA erosketa[], int kop) {
    char izena[MAX_STR];
    izenaGaldetu(izena);
    kop = erosketa_bat_ezabatu(erosketa, izena, kop);
    return kop;
}
int erosketa_bat_ezabatu(OROKORRA erosketa[], char izena[], int kop) {
    int pos = 0;
    int aurkitua = 0;
    while (aurkitua == 0 && pos < kop) {
        if (strcmp(izena, erosketa[pos].izenburua) == 0) {
            aurkitua = 1;
        }
        else {

            pos++;
        }
    }
    if (aurkitua == 1) {
        int i = 0;
        for (i = pos; i < kop - 1; i++) {
            erosketa[i] = erosketa[i + 1];
        }
    }
    else {
        printf("Izenburu hori daukan ibilbiderik ez dago.\n");
    }
    kop--;
    return kop;
}

