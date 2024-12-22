#include "orokorrak.h"
#include "diska.h"

NODOA* sortu_diskak(NODOA* ptrHasiera) {
	char str[64];
	int jarraitu = 0;
	NODOA* ptrBerria;
	do {
		ptrBerria = diskaSortu();
		ptrHasiera = sartuBukaeran(ptrHasiera, ptrBerria);
		bistaratu_zerrenda(ptrBerria);
		printf("Diskak sartzen bukatzeko idazti 0: ");
		fgets(str, 64, stdin);
		sscanf(str, "%i", &jarraitu);
	} while (jarraitu != 0);

	return ptrHasiera;
}
NODOA* diskaSortu() {
	NODOA* ptrBerria = 0;
	char str[64];

	ptrBerria = (NODOA*)malloc(sizeof(NODOA));

	printf("==========DISKA DATUAK SARTU MESEDEZ===============\n");
	printf("Id:");
	fgets(str, 64, stdin);
	sscanf(str, "%i", &(ptrBerria->diska.id));

	printf("Izenburua:");
	fgets(str, 64, stdin);
	str[strlen(str) - 1] = '\0';
	strcpy(ptrBerria->diska.izenburua, str);

	printf("Autorea:");
	fgets(str, 64, stdin);
	str[strlen(str) - 1] = '\0';
	strcpy(ptrBerria->diska.autorea, str);

	printf("Estiloa(Western - 0, Drama - 1, THRILLER - 2, COMEDIA - 3, TERROR - 4, SCIFI - 5):");
	fgets(str, 64, stdin);
	sscanf(str, "%d", &(ptrBerria->diska.estiloa));

	printf("Prezioa:");
	fgets(str, 64, stdin);
	sscanf(str, "%f", &(ptrBerria->diska.prezioa));

	return ptrBerria;
}
NODOA* sartuBuruan(NODOA* ptrHasiera, NODOA* ptrBerria) {
	ptrBerria->ptrHurrengoa = ptrHasiera;
	ptrHasiera = ptrBerria;

	return ptrHasiera;
}
NODOA* sartuBukaeran(NODOA* ptrHasiera, NODOA* ptrBerria) {
	NODOA* ptrAux = 0;
	ptrAux = ptrHasiera;
	//hutsik baldin badago, berria hasiera izango da
	if (ptrHasiera == 0) {
		ptrHasiera = ptrBerria;
		ptrHasiera->ptrHurrengoa = 0;
	}
	else {
		//1- Lortu azken elementuaren helbidea
		while (ptrAux->ptrHurrengoa != 0) {
			ptrAux = ptrAux->ptrHurrengoa;
		}
		//2- esan berria azkenaren hurrengoa da
		ptrAux->ptrHurrengoa = ptrBerria;
		ptrBerria->ptrHurrengoa = 0;
	}
	return ptrHasiera;
}

void bistaratu_zerrenda(NODOA* ptrHasiera) {
	NODOA* ptrAux = 0;
	ptrAux = ptrHasiera;
	printf("===============DISKA GUZTIEN DATUAK BISTARATZEN===================\n");
	while (ptrAux != NULL) {
		//printf("%i %s %s\n", ptrAux->ikaslea.id, ptrAux->ikaslea.izena, ptrAux->ikaslea.abizena);
		diskaBatBistaratu(ptrAux->diska);

		ptrAux = ptrAux->ptrHurrengoa;
	}
}
void diskaBatBistaratu(DISKA diska) {
	printf("================DISKAREN INFORMAZIOA================\n");
	printf("Id-a: %i\n", diska.id);
	printf("Izena: %s\n", diska.izenburua);
	printf("Autorea: %s\n", diska.autorea);
	printf("Estiloa: %i\n", diska.estiloa);
	printf("Prezioa: %.2f\n", diska.prezioa);
}

NODOA* aurkitu_bat(NODOA* ptrHasiera, int id, int estiloa, char izena[], int i) {
	NODOA* ptrAux;
	ptrAux = ptrHasiera;
	if (i == 0) {
		while (ptrAux != 0 && ptrAux->diska.id != id) {
			ptrAux = ptrAux->ptrHurrengoa;
		}
	}
	else if (i == 1) {
		while (ptrAux != 0 && ptrAux->diska.estiloa != estiloa) {
			ptrAux = ptrAux->ptrHurrengoa;
		}
	}
	else {
		while (ptrAux != 0 && strcmp(ptrAux->diska.izenburua, izena) != 0) {
			ptrAux = ptrAux->ptrHurrengoa;
		}
	}

	return ptrAux;

}
void bistaratu_bat(NODOA* ptrHasiera, int id) {
	NODOA* ptrAurkitua = 0;

	ptrAurkitua = aurkitu_bat(ptrHasiera, id, 0, "aaa", 0);
	if (ptrAurkitua != 0) {
		diskaBatBistaratu(ptrAurkitua->diska);
	}
	else {
		printf("Elementua ez dago zerrendan.\n");
	}

}
void bistaratu_estilo_bateko_diskak(NODOA* ptrHasiera, int estilo, int id) {
	NODOA* ptrAurkitua = 0;

	ptrAurkitua = aurkitu_bat(ptrHasiera, id, estilo, "aaa", 1);
	if (ptrAurkitua != 0) {
		diskaBatBistaratu(ptrAurkitua->diska);
	}
	else {
		printf("Elementua ez dago zerrendan.\n");
	}
}
void aurkitu_izenburua(NODOA* ptrHasiera, char izena[], int estilo, int id) {
	NODOA* ptrAurkitua = 0;

	ptrAurkitua = aurkitu_bat(ptrHasiera, id, estilo, izena, 2);
	if (ptrAurkitua != 0) {
		diskaBatBistaratu(ptrAurkitua->diska);
	}
	else {
		printf("Elementua ez dago zerrendan.\n");
	}
}
void modifikatuPrezioa(NODOA* ptr_hasiera, char izenburua[], float prezio_berria) {
	NODOA* ptr_tmp = ptr_hasiera;
	int aurkitua = 0;

	while (ptr_tmp != NULL) {
		if (strcmp(ptr_tmp->diska.izenburua, izenburua) == 0) {
			ptr_tmp->diska.prezioa = prezio_berria;
			aurkitua = 1;
			printf("Prezioa ongi aldatu da.\n");
			break;
		}
		ptr_tmp = ptr_tmp->ptrHurrengoa;
	}

	if (!aurkitua) {
		printf("Ezin da diskaren prezioa aldatu, izenburua ez baita aurkitu.\n");
	}
}