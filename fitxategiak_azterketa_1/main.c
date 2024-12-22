#include "orokorrak.h"
#include "herrialdeak.h"
#include "menua.h"

int main(void) {
    int zenbat_herrialde = 3;
    HERRIALDEAK herrialde[MAX_HERRIALDEAK];
    int aukera = 0;

    fitxategia_irakurri_herrialdeak(herrialde, zenbat_herrialde);

    do {
        aukera = menua();
        zenbat_herrialde = menua_exekutatu(aukera, herrialde, zenbat_herrialde, MAX_HERRIALDEAK);
    } while (aukera != IRTEN);

    return EXIT_SUCCESS;
}