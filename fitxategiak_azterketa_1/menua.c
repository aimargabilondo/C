#include "orokorrak.h"
#include "herrialdeak.h"
#include "menua.h"

int menua() {
    //ALDAGAIAK
    char str[MAX_STR];
    int ret = 0;
    //PROGRAMA
    printf("=================================MENUA==========================\n");
    printf("1- Gehitu/Sortu herrialde bat\n");
    printf("2- Aldatu herrialde bat\n");
    printf("3- Bistaratu herrialde guztiak\n");
    printf("4- Egun bateko mugimenduak irakurri\n");
    printf("5- Kontatu herrialde bakoitzeko mugimenduak\n");
    printf("6- Aurreko puntua ordenatu\n");
    printf("0- Irten\n");
    printf("================================================================\n");
    do {
        printf("Zer nahi duzu egin(1-6)?: ");
        fgets(str, MAX_STR, stdin);
        sscanf(str, "%i", &ret);
        if (!(ret >= 0 && ret <= 6)) {
            printf("ERROREA: Aukera desegokia. Mesedez 1-6 arteko balore bat.\n");
        }
    } while (ret < 0 || ret > 6);

    //BUKAERA
    return ret;
}
int menua_exekutatu(int aukera, HERRIALDEAK herri[], int zenbat_herri, int MAX) {
    FILE* fitx = 0;
    int media = 0;
    herri[0].egun.mugimenduak = 12;
    switch (aukera)
    {
    case SORTU:
        printf("====================Herrialde berri bat gehitu==========================\n");
        if (zenbat_herri < MAX) {
            herri[zenbat_herri] = sortu_herrialde_bat();
            zenbat_herri++;
        }
        else {
            printf("ERROREA: Arraya beteta dago, ezin da beste bat sortu");
        }
        break;
    case ALDATU:
        herrialde_datuak_aldatu(herri, zenbat_herri);

        break;
    case BISTARATU:
        bistaratu_herrialde_guztiak(herri, zenbat_herri);

        break;
    case FITX_IRA:
        fitxategia_irakurri(herri, herri[0].egun.mugimenduak);

        break;
    case KONTATU:
        konexioak_kontatu(herri, zenbat_herri);

        break;
    case ORDENATU:
        ordenatu(herri, zenbat_herri);

        break;
    case IRTEN_AUKERA:

        break;
    default:
        printf("Aukera hori ez da existitzen.\n");
        break;
    }
    jarraitu();
    borratu_pantila();
    return zenbat_herri;
}