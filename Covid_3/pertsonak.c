#include <stdio.h>
#include <string.h>
#include "orokorrak.h"
#include "pertsonak.h"

int erabiltzaileenInformazioaBete(char fitx_izena_gaixoak[],  char fitx_izena_emaitzak[], PERTSONAK gaixoak[]) {
	FILE* fitxategia;
	FILE* fitxategiaEmaitzak;
	int kop = 0;
	int egoera = 1; //whilean sartzqeko
	int emaitza=0; //char
	fitxategia = fopen(fitx_izena_gaixoak, "r");
	fitxategiaEmaitzak = fopen(fitx_izena_emaitzak, "r");

	if (fitxategia> 0 && fitxategiaEmaitzak > 0){
		while (egoera > 0 && kop < MAX_PERTSONAK) { //-1 errore edo fitxageia amaitu eta 0 ez badau ezer eirakurri
			egoera = fscanf(fitxategia, "%d %s %s %d %s\n", &gaixoak[kop].id, gaixoak[kop].izena,
															gaixoak[kop].abizena,
															&gaixoak[kop].adina,
															gaixoak[kop].herria);
			if (egoera > 0){//==5
				egoera = fgetc(fitxategiaEmaitzak);

				if (egoera > 0){
					gaixoak[kop].egoera = (char) egoera;
					kop++;
				}
			}

		}
		printf("Datuak ongi irakurri dira\n\n");

	}

	if (fitxategia > 0 )fclose(fitxategia);
	if (fitxategiaEmaitzak > 0  )fclose(fitxategiaEmaitzak);
	return kop;

}
void pertsonaBatPantailaratu(PERTSONAK pertsona) {
    printf("Izena: %s\n", pertsona.izena);
    printf("Abizena: %s\n", pertsona.abizena);
}


void covidPositiboakPantailaratu(PERTSONAK pertsonak[], int kopurua) {
    int i = 0;
    while (i < kopurua) {
        if (pertsonak[i].egoera == 'p') {
            pertsonaBatPantailaratu(pertsonak[i]);
        }
        i++;
    }
}
void covidDatuakFitxategianGorde(PERTSONAK pertsonak[], int kopurua) {
    FILE* fitxategia;
    int i = 0;
    fitxategia = fopen("datuak.txt", "w");
    if (fitxategia > 0) {
        while (i < kopurua) {
            fprintf(fitxategia, "%d,%c\n", pertsonak[i].id, pertsonak[i].egoera);
            i++;
        }
        printf("Datuak ongi gorde dira.\n");
        fclose(fitxategia);
    }
    else printf("Datuak ez dira ongi gorde.\n");
}

float  covidPositiboAdinBBkalkulatu(PERTSONAK pertsonak[], int kopurua) {
    int i = 0, batura=0, kopPos=0;
    float bataz = 0, desbideratzea=0;
    while (i < kopurua) {
    	 printf("Todo#5  covidPositiboAdinBBkalkulatu\n");
        i++;
    }
   // bataz = batura / kopPos;
    //desbideratzea = desbiazioEstandarraKalkulatu(pertsonak, kopurua, BB);
    return bataz;
}

float desbiazioEstandarraKalkulatu(PERTSONAK pertsonak[], int kopurua, int BB) {
    int batura = 0, kenketa=0, kopuruaPos=0, i=0;
    float desbideratzea = 0;
    while (i < kopurua) {
    	printf("Todo#6  desbiazioEstandarraKalkulatu\n");
        i++;
    }
    //desbideratzea = sqrt((batura / kopuruaPos));
    return desbideratzea;
}



