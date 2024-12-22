#include "orokorrak.h"
#include "elurra.h"
#include "fitxategia.h"


void batazBeste(int herriKopurua, HERRIA* herriak) {
    float batazBestekea = 0.0;
    for (int i = 0; i < herriKopurua; i++) {
        batazBestekea += herriak[i].elurra;
    }

    batazBestekea = batazBestekea / herriKopurua;

    idatziHerriakElurKopuruagatik(herriak, batazBestekea, herriKopurua);

    // Bataz besteko elur kopurua inprimatu
    printf("Bataz besteko elur kopurua: %.2f\n", batazBestekea);
}

void idatziHerriakElurKopuruagatik(HERRIA* herriak, int batazBestekea, int herriKopurua) {
    FILE* fitxategia1 = fopen("mediaBehetik.txt", "w");
    FILE* fitxategia2 = fopen("mediaGoitik.txt", "w");

    for (int i = 0; i < herriKopurua; i++) {
        if (herriak[i].elurra < batazBestekea) {

            fprintf(fitxategia1, "%d %s %f\n",herriak[i].id, herriak[i].izena, herriak[i].elurra);

        }
        else {

            fprintf(fitxategia2, "%d %s %f\n", herriak[i].id, herriak[i].izena, herriak[i].elurra);

        }

    }

    fclose(fitxategia1);
    fclose(fitxategia2);

}