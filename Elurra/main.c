#include "orokorrak.h"
#include "elurra.h"
#include "fitxategia.h"

int main() {
    HERRIA herriak[MAX_HERRIAK];
    FILE* fitxategia = fopen("elur_kopuruak.txt", "r");

    int herrienKopurua = herri_kop(herriak, fitxategia);

    batazBeste(herrienKopurua, herriak);




    jarraitu(fitxategia);

    return 0;
}