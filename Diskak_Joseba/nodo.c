
#include <stdio.h>
#include <stdlib.h>//malloc
#include <string.h>

#include "nodo.h"

NODOA* sortu_nodo_bat_v1(){
	NODOA* ptr_berria= NULL;
	ptr_berria = malloc(sizeof(NODOA));
	sortu_nodo_bat_josu(ptr_berria);
	//ptr_berria->elementua = hasieratu_elementua(ptr_berria->elementua);
	return ptr_berria;;
}

NODOA* sortu_nodo_bat(){
	NODOA* ptr_elementua=NULL;
	char str[MAX_STR];
	ptr_elementua = malloc(sizeof(NODOA));
	//
	printf("Idatzi diskaren izenburua?");
	fgets(str, MAX_STR, stdin);
	str[strlen(str)-1]='\0';
	strcpy(ptr_elementua->elementua.izenburua, str);

	printf("Idatzi talderaen izena ?");
	fgets(str, MAX_STR, stdin);
	str[strlen(str)-1]='\0';
	strcpy(ptr_elementua->elementua.taldea, str);
	//PRINTF, FEGTS , SSCANG
	printf("Diksaren  id:");
	fgets(str, MAX_STR, stdin);
	sscanf(str, "%d", &(ptr_elementua->elementua.id));

	ptr_elementua->elementua.edizio_urtea = 1980;
	ptr_elementua->elementua.prezioa = 0;
	printf("Diksaren estiloa? 0-ROCK, 1- JAZZ 2-BLUES 3-ELECTRONICA 4-PUNK 5-POP");
	fgets(str, MAX_STR, stdin);
	sscanf(str, "%d", &(ptr_elementua->elementua.estiloa));
	//sscanf(str, "%d", &estilo_tmp);
	//ptr_elementua->elementua.estiloa = estilo_tmp;

	return ptr_elementua;
}
void sortu_nodo_bat_josu(NODOA* ptr_elementua){
	if (ptr_elementua != NULL){
		char str[MAX_STR];

		printf("Idatzi diskaren izenburua?");
		fgets(str, MAX_STR, stdin);
		str[strlen(str)-1]='\0';
		strcpy(ptr_elementua->elementua.izenburua, str);

		printf("Idatzi talderaen izena ?");
		fgets(str, MAX_STR, stdin);
		str[strlen(str)-1]='\0';
		strcpy(ptr_elementua->elementua.taldea, str);
		//PRINTF, FEGTS , SSCANG
		printf("Diksaren  id:");
		fgets(str, MAX_STR, stdin);
		sscanf(str, "%d", &(ptr_elementua->elementua.id));


		ptr_elementua->elementua.edizio_urtea = 1980;
		ptr_elementua->elementua.prezioa = 0;
		printf("Diksaren estiloa? 0-ROCK, 1- JAZZ 2-BLUES 3-ELECTRONICA 4-PUNK 5-POP");
		fgets(str, MAX_STR, stdin);
		sscanf(str, "%d", &(ptr_elementua->elementua.estiloa));
		//sscanf(str, "%d", &estilo_tmp);
		//ptr_elementua->elementua.estiloa = estilo_tmp;

	}else{
		printf("ERROR: Ez dozu sortu memoria.\n");
	}
}

NODOA* sartu_buruan(NODOA* ptr_hasiera, NODOA* ptr_berria){
	if (ptr_berria != NULL){
		ptr_berria->ptr_hurrengoa = ptr_hasiera;
		ptr_hasiera = ptr_berria;
	}

	return ptr_hasiera; //return 0;
}

NODOA* sartu_bukaeran(NODOA* ptr_hasiera,NODOA* ptr_berria){
	NODOA* ptr_aux=NULL;
	ptr_aux = ptr_hasiera;

	if (ptr_hasiera==NULL){
		//ZERRENDA HUTSIK DAGO
		ptr_hasiera = ptr_berria;
		ptr_berria->ptr_hurrengoa = NULL;
	}else{
		while(ptr_aux->ptr_hurrengoa != NULL){
					ptr_aux = ptr_aux->ptr_hurrengoa;
		}
		ptr_aux->ptr_hurrengoa = ptr_berria;//azkenari berria kateatzen diogu
		ptr_berria->ptr_hurrengoa = NULL;//berria azkena bihurtzen dugu
	}
	return ptr_hasiera;
}

void bistaratu_zerrenda(NODOA* ptr_hasiera){
	NODOA* ptr = NULL;
	ptr = ptr_hasiera;
	if (ptr==NULL)printf("Zerrenda hutsik dago\n");
	while(ptr != NULL ){
		bistaratu_diska(ptr->elementua);
		ptr = ptr->ptr_hurrengoa;
	}
}

void bistaratu_estilo_batekoak(NODOA* ptr_hasiera, ESTILOA estiloa){
	NODOA* ptr = NULL;
	ptr = ptr_hasiera;
	int kont = 0;
	while(ptr != NULL ){
		//if (ptr->estiloa == estiloa)
		if (ptr->elementua.estiloa == estiloa){
			bistaratu_diska(ptr->elementua);
			kont++;
		}
		ptr = ptr->ptr_hurrengoa;
	}
	if(kont == 0){
		printf("Ez dago estilo honetako diskarik.\n");
	}
}

void modifikatu_prezioa(NODOA* ptr_aux){
	char str[MAX_STR];
	int prezioa = 0;
	printf("Idatzi %s diskaren prezio (%d€) berria:",
			ptr_aux->elementua.izenburua, ptr_aux->elementua.prezioa);
	fgets(str, MAX_STR, stdin);
	sscanf(str, "%d", &prezioa);
	ptr_aux->elementua.prezioa = prezioa;


}

NODOA* aurkitu_elementua(NODOA* ptr_hasiera, char str[MAX_STR]){
	NODOA* ptr_aurkitua = NULL;
	int aurkitua= 0;

	ptr_aurkitua = ptr_hasiera;
	while(aurkitua == 0 && ptr_aurkitua != NULL){
		if ( strcmp(ptr_aurkitua->elementua.izenburua, str) == 0){
			//aurkitua
			aurkitua = 1; //eta ez gara gehiago mugitzen zerrendan;-)
		}else{
			ptr_aurkitua = ptr_aurkitua->ptr_hurrengoa;
		}
	}

	return ptr_aurkitua;
}

void bistaratu_diska(DISKA diska){
	printf("==================DISKA====================\n");
	printf("Izenburua:%s\n", diska.izenburua);
	printf("Taldea: %s\n", diska.taldea);
	printf("Urtea:%d\n", diska.edizio_urtea);
	printf("Prezioa:%d€\n", diska.prezioa);
	switch(diska.estiloa){
		case ROCK: printf("Rock\n");
				break;
		case JAZZ: printf("Jazz\n");
						break;
		case BLUES: printf("Blues\n");
						break;
		case ELECTRONICA: printf("Electronica\n");
						break;
		case PUNK: printf("Punk\n");
						break;
		default:
			printf("Beste bat.\n");
	}

}


int jarraitu(){
	char str[MAX_STR];
	int aukera = 0;

	printf("Idatzi -1 diskan sartzen amaitzeko:");
	fgets(str, MAX_STR, stdin);
	sscanf(str,"%d", &aukera);

	return aukera;
}

NODOA* hustu_zerrenda(NODOA* ptr_hasiera){
	NODOA* ptr_aux= NULL;

	while( ptr_hasiera != NULL){
		ptr_aux=ptr_hasiera; //ptr mugitu ondoren ezabatuko dodan memoria helbidea
		//mugitu hurrengo elementura
		ptr_hasiera = ptr_hasiera->ptr_hurrengoa;
		free(ptr_aux);
	}
	return ptr_hasiera;
	//return NULL;
}

void bistaratu_zerrenda_alderantziz(NODOA* ptr_hasiera){

	if (ptr_hasiera->ptr_hurrengoa == NULL){
		//BUKAER ABALDINTZA , EZ DEITU GEHIAGO
		bistaratu_diska(ptr_hasiera->elementua);
	}else{
		bistaratu_zerrenda_alderantziz(ptr_hasiera->ptr_hurrengoa);
		bistaratu_diska(ptr_hasiera->elementua);
	}
}


NODOA* lotu_bi_zerrenda(NODOA* ptr_hasiera1, NODOA* ptr_hasiera2){
	NODOA* ptr_aux = NULL;
	ptr_aux = ptr_hasiera1;
	if (ptr_aux == NULL){
		//LEHENEGO ZERRENDA HUTSIK BADAGO BIGARRENJ ZERRENDA BIHURTZEN DA HASIERA
		ptr_hasiera1 = ptr_hasiera2;
	}{
		while(ptr_aux->ptr_hurrengoa != NULL){
			ptr_aux = ptr_aux->ptr_hurrengoa;
		}
		//lehen zerrendako azken elementuan gauz
		ptr_aux->ptr_hurrengoa = ptr_hasiera2;
	}
	return ptr_hasiera1;
}

NODOA* kendu_elementua(NODOA* ptr_hasiera, int id){
	NODOA* ptr_aux = NULL;
	NODOA* ptr_aurkitua=NULL;
	ptr_aux = ptr_hasiera;
	if (ptr_hasiera->elementua.id == id){
		//LEHEN ELEMENTUA KENDU BEHAR DA
		ptr_hasiera = ptr_hasiera->ptr_hurrengoa;
		printf("Hurrengo elementua kendu behar dut.\n");
		//bistaratu_diska(ptr_aux->elementua);
		free(ptr_aux);
	}else{
			//id hori daukan aurrekoaren elemenua aurkitu
			//KONTUZ WHILE HONEN BALDINZTEN ORDENAGAZ
			while(ptr_aux->ptr_hurrengoa != NULL  &&
					ptr_aux->ptr_hurrengoa->elementua.id != id){
				ptr_aux = ptr_aux->ptr_hurrengoa;
			}
			if (ptr_aux->ptr_hurrengoa == NULL){
				printf("Elementua ez dago.\n");
			}else{
				printf("Elementua aurkitua.\n");
				//zerrendatik kendu
				ptr_aurkitua = ptr_aux->ptr_hurrengoa;
				ptr_aux->ptr_hurrengoa = ptr_aurkitua->ptr_hurrengoa;
				//ptr_aux->ptr_hurrengoa = ptr_aux->ptr_hurrengoa->ptr_hurrengoa;
				free(ptr_aurkitua);
			}
	}


	return ptr_hasiera;
}


