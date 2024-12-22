
#include <stdio.h>

#include "nodo.h"

int main(){

	printf("===============DISKEN ARIKETA============\n");
	int aukera = 0;
	char str[MAX_STR];
	NODOA* ptr_berria= NULL; //ORIANIDK EZ DA EXISTITZEN
	NODOA* ptr_hasiera= NULL; //ORIANIDK EZ DA EXISTITZEN
	NODOA* ptr_aux= NULL; //ORIANIDK EZ DA EXISTITZEN
	NODOA* ptr_hasiera2= NULL; //ORIANIDK EZ DA EXISTITZEN


	NODO_DISKA* ptr_berria_diska= NULL;
	//ptr_berria_diska->id = 1; //PETARDAZO  0 HELBIDEA ID-ri 1 baloea BEHAR DAU MALLOC

	DISKA diska_bat;
	diska_bat.id = 1;

	do{
		//LEHENEGO ZERRENDAN
		ptr_berria = sortu_nodo_bat_v1();
		ptr_hasiera = sartu_bukaeran(ptr_hasiera, ptr_berria);
		//BIGARREN ZERRENDA
		ptr_berria = sortu_nodo_bat_v1();
		ptr_hasiera2 = sartu_bukaeran(ptr_hasiera2, ptr_berria);


		aukera = jarraitu();
	}while(aukera != -1); //-1 idatzi arte elementuak sortzen

	//bistaratu_zerrenda
	bistaratu_zerrenda(ptr_hasiera);
	printf("============ROCK DISKAK BISTARATZEN=====================\n");
	bistaratu_estilo_batekoak(ptr_hasiera, 	ROCK);
	//AURKITU ELEMENTU BAT
	ptr_aux = aurkitu_elementua(ptr_hasiera, "2");
	if (ptr_aux != NULL){
		printf("Aurkitua\n");
		bistaratu_diska(ptr_aux->elementua);
		//Orain modifikatzera goiez
		modifikatu_prezioa(ptr_aux);
		bistaratu_zerrenda(ptr_hasiera);
	}
	else{
		printf("Disko hori ez dago stockean.\n");
	}


	//malloc erabiltzen da memoria erreserbatzeko
	//free memoria liberatu egiten da

	printf("============ALDERANTZIZ====================\n");

	bistaratu_zerrenda_alderantziz(ptr_hasiera);

	printf("============bi zerrendak lotu====================\n");
	//ptr_hasiera eta ptr_hasiera2
	ptr_hasiera = lotu_bi_zerrenda(ptr_hasiera, ptr_hasiera2);
	bistaratu_zerrenda(ptr_hasiera);


	printf("=============ELEMENTUAK KENTZEN 4==============================\n");
	ptr_hasiera =  kendu_elementua(ptr_hasiera, 4);
	bistaratu_zerrenda(ptr_hasiera);

	printf("=============ELEMENTUAK KENTZEN 6==============================\n");
	ptr_hasiera =  kendu_elementua(ptr_hasiera, 6);
	bistaratu_zerrenda(ptr_hasiera);

	printf("=============ELEMENTUAK KENTZEN 1==============================\n");
	ptr_hasiera =  kendu_elementua(ptr_hasiera, 1);
	bistaratu_zerrenda(ptr_hasiera);

	printf("=============ELEMENTUAK KENTZEN 2==============================\n");
	ptr_hasiera =  kendu_elementua(ptr_hasiera, 2);
	bistaratu_zerrenda(ptr_hasiera);



	//PROGRAMAREN BUKAERA
	//memoria hustu -> memory leak
	printf("================================\n");
	printf("Zerrenda liberatzen FREE egiten. \n");
	ptr_hasiera = hustu_zerrenda(ptr_hasiera);
	bistaratu_zerrenda(ptr_hasiera);

	return 0;
}
