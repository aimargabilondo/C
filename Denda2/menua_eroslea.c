#include "orokorrak.h"
#include "eroslea.h"
#include "menua_eroslea.h"

int menua_eroslea() {
    //ALDAGAIAK
    char str[MAX_STR];
    int ret = 0;
    //PROGRAMA
    printf("************************EROSLEAREN MENUA*********\n");
    printf("|1 - Diska berri bat gehitu erosketara (Carrito de la compra) \n");
    printf("|2 - Erosketa burutu \n");
    printf("|3 - Erosketa karritoa ikusi \n");
    printf("|4 - Bistaratu stocka \n");
    printf("|5 - Estilokaka \n");
    printf("|6 - Autoreka \n");
    printf("|7 - Zigilua \n");
    printf("|8 - Datak erabiliz \n");
    printf("|9 - Bat aurkitu \n");
    printf("|0 - Irten \n");
    printf("********************************************\n");
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
int menua_exekutatu_eroslea(int aukera, OROKORRA erosketa[], int zenbat_erosketa, int erabiltzeko, int *erabilita, int MAX){
    char str[MAX_STR];
    int erosteko = 0, estilo = 0, ordaindu = 0;
    OROKORRA produktuak[MAX_DISKA];
    int kop_produktuak = 10;
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

    switch (aukera)
    {
    case GEHITU_EROSKETA://Erosketa berria sortu
        printf("====================Diska berri bat erosi==========================\n");
        erosteko = bistaratu_stocka_erosteko();
        if (erabiltzeko - *erabilita >= produktu_datu_basea[erosteko].dirua) {
            *erabilita += aukeratu_stocka(erosteko);
            erosketa[zenbat_erosketa] = produktu_datu_basea[erosteko];
            zenbat_erosketa++;
        }
        else {
            printf("Ez daukazu diru nahikoa\n");
        }
        break;
    case BURUTU://pelikula ezabatu
        if (*erabilita > 0) {
            printf("Prezio totala %d da\n", *erabilita);
            printf("Ordaindu nahi duzu? 1 - BAI, 0 - EZ\n");
            fgets(str, MAX_STR, stdin);
            sscanf(str, "%i", &ordaindu);
            printf("Eskerrikasko zure erosketagatik\n");
        }
        else{
            printf("Ez duzu ezer hartu.\n");
        }
        break;
    case EROSKETA_IKUSI://Pelikula aldatu
        bistaratu_erosketa_guztiak(erosketa, zenbat_erosketa);
        break;
    case BISTARATU://Denak bistaratu
        bistaratu_stocka();
        break;
    case ESTILO://estilo bateko diskak bistaratu
        printf("Esan ze estiloko diskoak ikusi nahi dituzun: \n");
        printf("0 - PopRock, 1 - ArtRock, 2 - Pop, 3 - Rock Progresiboa, 4 - FolckRock, 5 - Rock Alternatiboa, 6 - Jazz\n");
        fgets(str, MAX_STR, stdin);
        sscanf(str, "%i", &estilo);

        bistaratu_estilo_bateko_erosketa(produktuak, kop_produktuak, estilo);
        break;
    case AUTORE://autoreka bistaratu
        autoreka_bistaratu_erosketa(produktuak, kop_produktuak);

        break;
    case ZIGILUA://zigiluka bistaratu
        zigiluka_bistaratu_erosketa(produktuak, kop_produktuak);

        break;
    case DATA://data batetik aurrerako erosketa bistaratu
        data_batetik_aurrera_bistaratu_erosketa(produktuak, kop_produktuak);

        break;
    case AURKITU://aurkitu erosketa bat
        erosketa_aurkitu(produktuak, kop_produktuak);
        break;

    case IRTEN_AUKERA://irten
        break;
    default:
        printf("Aukera hori ez da existitzen.\n");
        break;
    }
    jarraitu();
    borratu_pantila();
    return zenbat_erosketa;

}