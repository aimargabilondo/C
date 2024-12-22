#include "main.h"

USER datubasea[] = {
        {"admin", "admin", 0, "admin@mondragon.edu", 1},
        {"dendari", "dendari", 1, "aimar@mondragon.edu", 2},
        {"erosle", "erosle", 2, "user@mondragon.edu", 3},
        {"a", "admin", 3, "a@mondragon.edu", 4},

};

int login() {
    int mota, i = 0, irten = 0;
    int user_kop = 4;
    char erabiltzaile_izena[64] = " ", pasahitza[64];
    char* zerDa = " ";


    mota = login_irakurri(erabiltzaile_izena, pasahitza);

    if (mota == 1) {
        while (i <= user_kop && irten == 0) {
            int berdina = strcmp(erabiltzaile_izena, datubasea[i].izena);
            if (berdina == 0) {
               strcpy(zerDa, datubasea[i].erabiltzaile_mota);
               irten = 1;   
            }
            i++;
        }
    }
    else {
        zerDa = NULL;
    }

    printf("%s", zerDa);
    return zerDa;
}

void password_login_irakurri(char* erabiltzaile_izena, char* pasahitza) {
    printf("\nUsername:");
    fgets(erabiltzaile_izena, 64, stdin);
    erabiltzaile_izena[strlen(erabiltzaile_izena) - 1] = '\0';

    printf("\nPassword:");
    fgets(pasahitza, 64, stdin);
    pasahitza[strlen(pasahitza) - 1] = '\0';
}

int login_irakurri(char* erabiltzaile_izena, char* pasahitza) {
    int ret = 0, zailakera = 3, i = 0;

    while (ret == 0 && zailakera > 0) {

        password_login_irakurri(erabiltzaile_izena, pasahitza);

        int izenBerdina = !strcmp(erabiltzaile_izena, datubasea[i].izena);
        int passBerdina = !strcmp(pasahitza, datubasea[i].pasahitza);

        if (izenBerdina == 1 && passBerdina == 1 && zailakera > 0) {
            ret = 1;

        }
        else {
            ret = 0;
            zailakera--;
            printf("\nSaiatu berriro. Tentatibak gelditzen zaizkizu: %d", zailakera);
        }
        i++;
    }
    return ret;
}