#include "orokorrak.h"
#include "elurra.h"
#include "fitxategia.h"

int fitxategia_ireki(FILE* fitxategia) {
    if (fitxategia == NULL) {
        perror("Errorea fitxategia irekitzerakoan");
        return FALSE;
    }
    return TRUE;
}

int herri_kop(HERRIA herriak[MAX_HERRIAK], FILE* fitxategia) {
    // fitxategia_ireki funtzioa erabiliz errorea kudeatu
    int ondo = fitxategia_ireki(fitxategia);
    if (ondo == FALSE) {
        return 0; // Hutsa itzuli, ez dago datuak prozesatzeko
    }
    
    int herrienKopurua = 0;
    while (fscanf(fitxategia, "%d %s %f", &herriak[herrienKopurua].id, herriak[herrienKopurua].izena, &herriak[herrienKopurua].elurra) == 3) {
        herrienKopurua++;
    }

    return herrienKopurua;
    
}