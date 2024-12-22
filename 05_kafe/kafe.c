#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "kafe.h"

int menua() {
	int aukera = 0;
	char str[MAX_STR];
	printf("=============================KAFE MENUA==========================\n");
	printf("1: Sortu egun bateko datuak\n");
	printf("2: Azken N egunetako produkzioa bistaratu\n");
	printf("3: Azken eguna eta aurrekoaren produkzio diferentzia kalkulatu\n");
	printf("4: Egun guztietako diferentziaren eboluzioa\n");
	printf("5: Irten\n");
	fgets(str, MAX_STR, stdin);
	sscanf(str, "%i", &aukera);
	system("cls");

	return aukera;
}
NODO_KAFE* menua_exekutatu(int aukera, NODO_KAFE* ptrHasiera, NODO_KAFE* ptrBerria) {
	float produkzioa = 0;
	float diferentzia = 0;
	NODO_KAFE* ptrAux = 0;

	switch (aukera) {
	case SORTU:
		ptrAux = sortu_datuak();
		return ptrAux;
		break;
	case N_EGUNAK:
		N_egunetako_produkzioa(ptrHasiera);
		break;
	case DIFERENTZIA:
		produkzio_diferentzia(ptrHasiera);
		break;
	case EBOLUZIOA:
		bistaratu_eboluzioa(ptrHasiera);
		break;
	}
	return ptrHasiera;
}
NODO_KAFE* sortu_datuak() {
	char str[MAX_STR];
	NODO_KAFE* ptrRet = 0;

	ptrRet = (NODO_KAFE*)malloc(sizeof(NODO_KAFE));
	if (ptrRet != 0){
		printf("====================================DATUAK SORTZEN==================================\n");
		
		printf("Eguneko kafe produkzioa:");
		fgets(str, MAX_STR, stdin);
		sscanf(str, "%f", &ptrRet->kafe.kafe_ekoizpena);

		printf("Kafeina portzentaia:");
		fgets(str, MAX_STR, stdin);
		sscanf(str, "%f", &ptrRet->kafe.kafeina);

	}
	system("cls");
	return ptrRet;
}
void N_egunetako_produkzioa(NODO_KAFE* ptrHasiera) {
	int n = 0;
	int i = 0;
	char str[MAX_STR];
	NODO_KAFE* ptrAux = 0;

	printf("Zenbat egunetako produkzioa nahi duzu ikusi?\n");
	fgets(str, MAX_STR, stdin);
	sscanf(str, "%i", &n);

	ptrAux = ptrHasiera;

	while (ptrAux != 0 && i < n) {
		bistaratu_egun_bat(ptrAux);
		ptrAux = ptrAux->ptrHurrengoa;
		i++;
	}
}
void bistaratu_egun_bat(NODO_KAFE* ptrEguna) {
	printf("=============================%i EGUNEKO PRODUKZIOA=========================\n", ptrEguna->kafe.data);
	printf("Produzitutako kafea: %.2f kg\n", ptrEguna->kafe.kafe_ekoizpena);
	printf("Kafeina: %.2f%%\n", ptrEguna->kafe.kafeina);
}
void produkzio_diferentzia(NODO_KAFE* ptrHasiera) {
	NODO_KAFE* ptrAux = 0;
	float dif = 0;
	ptrAux = ptrHasiera;

	if (ptrAux != 0 && ptrAux->ptrHurrengoa != 0) {
		dif = (ptrAux->kafe.kafe_ekoizpena) - (ptrAux->ptrHurrengoa->kafe.kafe_ekoizpena);

	}
	printf("Produkzio diferentzia: %.2f\n", dif);
}
NODO_KAFE* sartuNodoaBuruan(NODO_KAFE* ptrHasiera, NODO_KAFE* ptrBerria) {

	ptrBerria->ptrHurrengoa = ptrHasiera;
	ptrHasiera = ptrBerria;

	return ptrHasiera;
}
void bistaratu_eboluzioa(NODO_KAFE* ptrHasiera) {
	NODO_KAFE* ptrAux = 0;
	int i = 1;
	ptrAux = ptrHasiera;

	while (ptrAux != 0) {
		printf("%i:", i);
		i++;
		if (ptrAux->ptrHurrengoa != 0) {
			produkzio_diferentzia(ptrAux);
		}
		ptrAux = ptrAux->ptrHurrengoa;
	}

}