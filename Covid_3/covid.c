#include <stdio.h>
#include <string.h>
#include "orokorrak.h"
#include "pertsonak.h"
#include "covid.h"
#include <math.h>

int  pertsonen_herriak_aurkitu(PERTSONAK pertsonak[] ,int kopurua, HERRIA herriak []){
	int kop_herriak = 0;
	int pos_pertsona = 0;
	int herria_badago = FALSE;

	 for (pos_pertsona = 0; pos_pertsona < kopurua; pos_pertsona++){
		 printf("Todo#1  pertsonen_herriak_aurkitu\n");
	 }

	return kop_herriak;
}

int aurkitu_herria(char herria [], HERRIA herriak[], int kop){
	int i = 0;
	int aurkitua = FALSE;
	 printf("Todo#1.1  Aurkitu herria\n");
	while ( i < MAX_HERRIAK && 	aurkitua == FALSE && i <kop){
		//TODO
	}
	return aurkitua;
}



void herrien_positiboak_kalkulatu(HERRIA herriak[], int kop_herriak, PERTSONAK pertsonak[], int kop){
	int i = 0;
	int j = 0;
	printf("Todo#2  herrien_positiboak_kalkulatu\n");
	for (i = 0 ; i < kop_herriak; i++){
		for (j = 0; j<kop; j++ ){

		}
	}

}

void herrien_egoera_kalkulatu(HERRIA herriak[], int kop_herriak){
	int i = 0;
	printf("Todo#3  herrien_egooera_kalkultau\n");
	for (i = 0 ; i < kop_herriak; i++){

	}


}



void herrien_egoera_fitxategian(HERRIA herriak[], int kop){
	  int i = 0;
	  FILE* fitxategia;
	  fitxategia = fopen("HerrienBanaketa.txt", "w");
	  if (fitxategia > 0) {
		   printf("Todo#4  errien_egoera_fitxategian\n");
	        fclose(fitxategia);
	    }

}


void datuakBistaratu(HERRIA herriak[], int datuKopurua) {
    int i = 0;
    while (i < datuKopurua) {
        guneakBistaratu(herriak[i]);
        i++;
    }
}
void guneakBistaratu(HERRIA herria) {
    if (herria.positiboKopurua >= 3) {
        printf("GUNE GORRIA\n");

    }
    if (herria.positiboKopurua < 3 && herria.positiboKopurua > 1) {
        printf("GUNE LARANJA\n");
    }
    if (herria.positiboKopurua <= 1) {
        printf("GUNE BERDEA\n");
    }
    printf("Herria: %s\t", herria.herria);
    printf("%d positibo\n", herria.positiboKopurua);

}

