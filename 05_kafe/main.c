#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "kafe.h"

int main() {
	NODO_KAFE* ptrHasiera = 0;
	NODO_KAFE* ptrBerria = 0;
	int aukera = 0;
	int eguna = 1;
	char str[MAX_STR];


	do {
		aukera = menua();
		printf("Sakatu return jarraitzeko...\n");
		getchar();
		system("cls");
		ptrBerria = menua_exekutatu(aukera, ptrHasiera, ptrBerria);
		ptrBerria->kafe.data = eguna;
		ptrHasiera = sartuNodoaBuruan(ptrHasiera, ptrBerria);


		eguna++;
	} while (aukera != IRTEN);


	return 0;
}