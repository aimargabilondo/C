#include "orokorrak.h"
#include "herrialdeak.h"

HERRIALDEAK sortu_herrialde_bat() {
    char str[MAX_STR];
    HERRIALDEAK ret;

    printf("IP (Lehenengo puntura arte)?\n");
    fgets(str, MAX_STR, stdin);
    sscanf(str, "%i", &ret.ip_1);

    printf("IP (Lehenengo puntutik bigarrenera arte)?\n");
    fgets(str, MAX_STR, stdin);
    sscanf(str, "%i", &ret.ip_2);

    printf("IP (Bigarren puntutik hirugarrenera arte)?\n");
    fgets(str, MAX_STR, stdin);
    sscanf(str, "%i", &ret.ip_3);

    printf("IP (Hirugarren puntutik bukaerara arte)?\n");
    fgets(str, MAX_STR, stdin);
    sscanf(str, "%i", &ret.ip_4);

    printf("Herrialdea?\n");
    fgets(ret.herrialdea, MAX_STR, stdin);
    ret.herrialdea[strlen(ret.herrialdea) - 1] = '\0';

    borratu_pantila();
    return ret;

}

int herrialde_datuak_aldatu(HERRIALDEAK* herri, int kop) {
    char izena[MAX_STR], aldatu[] = "Aldatu nahi duzun herrialdea";
    izenaGaldetu(izena, aldatu);

    int pos = 0;
    int aurkitua = 0;
    while (aurkitua == 0 && pos < kop) {
        if (strcmp(izena, herri[pos].herrialdea) == 0) {
            aurkitua = 1;
        }
        else {
            pos++;
        }
    }
    if (aurkitua == 1) {
        printf("Modifikatu nahi duzun herrialdearen informazioa honakoa da: \n");
        bistaratu_herrialde_bat(herri[pos]);
        printf("=================================================\n");
        herri[pos] = sortu_herrialde_bat();
    }
    else {
        printf("Izen hori daukan herrialderik ez dago.\n");
    }
    return kop;
}
void izenaGaldetu(char izena[], char hitz[]) {
    printf("%s: ", hitz);
    fgets(izena, MAX_STR, stdin);
    izena[strlen(izena) - 1] = '\0';
}

void bistaratu_herrialde_guztiak(HERRIALDEAK* herri, int kop) {
    for (int i = 0; i < kop; i++) {
        bistaratu_herrialde_bat(herri[i]);
    }
}
void bistaratu_herrialde_bat(HERRIALDEAK herri) {
    char ip[MAX_STR];
    sprintf(ip, "%d.%d.%d.%d", herri.ip_1, herri.ip_2, herri.ip_3, herri.ip_4);
    printf("===================HERRIALDEA INFO====================\n");
    printf("IP: %s\n", ip);
    printf("Mota: %s\n", herri.herrialdea);

    jarraitu();
    borratu_pantila();
}

void fitxategia_irakurri(HERRIALDEAK* herri, int kop) {
    FILE* fitx = 0;
    char fitxategia[] = "Ze fitxategi nahi duzu irakurri?", izena[MAX_STR];
    int i = 0, j = 0;
    izenaGaldetu(izena, fitxategia);
    fitx = fopen(izena, "r");

    if (fitx > 0) {
        for (i = 0; i < kop; i++) {
            fscanf(fitx, "%s %d.%d.%d.%d %s\n", herri[i].egun.ordua, &herri[i].egun.ip_1, &herri[i].egun.ip_2, 
                &herri[i].egun.ip_3, &herri[i].egun.ip_4, herri[i].egun.protokoloa);
        }
        fclose(fitx);
    }
    else {
        printf("Errorea fitxategia ez da ondo ireki\n");
    }
}
void fitxategia_irakurri_herrialdeak(HERRIALDEAK* herri, int kop) {
    FILE* fitx = 0;
    int i = 0, j = 0;
    char izena[MAX_STR];

    fitx = fopen("herrialdeak.txt", "r");
    if (fitx > 0) {
        for (i = 0; i < kop; i++) {
            fscanf(fitx, "%d.%d.%d.%d %s\n", &herri[i].ip_1, &herri[i].ip_2, &herri[i].ip_3, 
                &herri[i].ip_4, herri[i].herrialdea);
            herri[i].kopurua = 0;
        }
    }
}

void konexioak_kontatu(HERRIALDEAK* herri, int kop) {
    int i = 0, j = 0, kop_2 = herri[0].egun.mugimenduak;

    for (i = 0; i < kop; i++) {
        for (j = 0; j < kop_2; j++) {
            if (herri[i].ip_1 == herri[j].egun.ip_1 && strcmp(herri[j].egun.protokoloa, "HTTPS") == 0) {
                herri[i].kopurua += 1;
            }
        }
    }
    bezeroak_fitxategian_idatzi(herri, kop);
}
void bezeroak_fitxategian_idatzi(HERRIALDEAK* herri, int kop) {
    FILE* fitx = 0;
    int i = 0;

    fitx = fopen("bezeroak.txt", "w");
    for (i = 0; i < kop; i++) {
        fprintf(fitx, "%s %d\n", herri[i].herrialdea, herri[i].kopurua);
        printf("%s %d\n", herri[i].herrialdea, herri[i].kopurua);
    }
    fclose(fitx);
}

void ordenatu(HERRIALDEAK* herri, int kop) {
    int i = 0, j = 0, temp = 0;
    char herria[MAX_STR];
    for (i = 0; i < kop - 1; i++) {
        for (j = 0; j < kop - i - 1; j++) {
            if (herri[j].kopurua < herri[j + 1].kopurua) {
                temp = herri[j].kopurua;
                herri[j].kopurua = herri[j + 1].kopurua;
                herri[j + 1].kopurua = temp;

                strcpy(herria, herri[j].herrialdea);
                strcpy(herri[j].herrialdea, herri[j + 1].herrialdea);
                strcpy(herri[j + 1].herrialdea, herria);
            }
        }
    }
    for (i = 0; i < kop; i++) {
        printf("%s %d\n", herri[i].herrialdea, herri[i].kopurua);
    }
}
