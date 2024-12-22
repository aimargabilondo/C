#include "orokorrak.h"
#include "admin.h"
#include "menua_admin.h"

int menua_admin() {
    //ALDAGAIAK
    char str[MAX_STR];
    int ret = 0;
    //PROGRAMA
    printf("*****************ADMIN MENUA*********\n");
    printf("|1 - Diska berri bat gehitu stocka \n");
    printf("|2 - diska bat kendu stocketik \n");
    printf("|3 - Diska bat modifikatu \n");
    printf("|4 - Bistaratu \n");
    printf("|5 - Estilokaka \n");
    printf("|6 - Autoreka \n");
    printf("|7 - Zigilua \n");
    printf("|8 - Datak erabiliz \n");
    printf("|9 - Bat aurkitu \n");
    printf("|0 - Irten \n");
    printf("*****************************************\n");
    do {
        printf("Zer nahi duzu egin(1-9)?: ");
        fgets(str, MAX_STR, stdin);
        sscanf(str, "%i", &ret);
        if (!(ret >= 0 && ret <= 9)) {
            printf("ERROREA: Aukera desegokia. Mesedez 1-9 arteko balore bat.\n");
        }
    } while (ret < 0 || ret > 9);

    //BUKAERA
    return ret;
}
int menua_exekutatu_admin(int aukera, OROKORRA produktuak[], int kop_produktuak, int MAX) {
    char str[MAX_STR];
    int estilo = 0;

    switch (aukera)
    {
    case SORTU://Pelikula berria sortu
        printf("====================Diska berri bat gehitu stocka==========================\n");
        if (kop_produktuak < MAX) {
            produktuak[kop_produktuak] = sortu_diska_bat();
            kop_produktuak++;
        }
        else {
            printf("ERROREA: Arraya beteta dago, ezin da beste bat sortu");
        }
        break;
    case EZABATU://pelikula ezabatu
        kop_produktuak = admin_ezabatu(produktuak, kop_produktuak);
        break;
    case ALDATU://Pelikula aldatu
        admin_datuak_aldatu(produktuak, kop_produktuak);
        break;
    case BISTARATU://Denak bistaratu
        bistaratu_admin_guztiak(produktuak, kop_produktuak);

        break;
    case ESTILO://estilo bateko diskak bistaratu
        printf("Esan ze estiloko diskoak ikusi nahi dituzun: \n");
        printf("0 - PopRock, 1 - ArtRock, 2 - Pop, 3 - Rock Progresiboa, 4 - FolckRock, 5 - Rock Alternatiboa, 6 - Jazz\n");
        fgets(str, MAX_STR, stdin);
        sscanf(str, "%i", &estilo);

        bistaratu_estilo_bateko_admin(produktuak, kop_produktuak, estilo);

        break;
    case AUTORE://autoreka bistaratu
        autoreka_bistaratu_admin(produktuak, kop_produktuak);

        break;
    case ZIGILUA://zigiluka bistaratu
        zigiluka_bistaratu_admin(produktuak, kop_produktuak);

        break;
    case DATA://data batetik aurrerako diska bistaratu
        data_batetik_aurrera_bistaratu_admin(produktuak, kop_produktuak);

        break;
    case AURKITU://aurkitu diska bat
        admin_aurkitu(produktuak, kop_produktuak);
        break;

    case IRTEN_AUKERA://irten
        break;
    default:
        printf("Aukera hori ez da existitzen.\n");
        break;
    }
    jarraitu();
    borratu_pantila();
    return kop_produktuak;

}