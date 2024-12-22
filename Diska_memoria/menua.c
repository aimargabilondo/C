#include "orokorrak.h"
#include "diska.h"
#include "menua.h"

int menua() {
	int aukera = 0;
	char str[MAX_STR];
	printf("---------MENUA----------\n");
	printf("1-Sortu hainbat diska\n");
	printf("2-Bistaratu diska bat\n");
	printf("3-Bistaratu diska guztiak\n");
	printf("4-Bistaratu estilo bateko diskak\n");
	printf("5-Aurkitu diskak izenburuarekin\n");
	printf("6-Modifikatu diska baten prezioa\n");
	printf("0-Irten\n");
	fgets(str, MAX_STR, stdin);
	sscanf(str, "%i", &aukera);
	return aukera;
}
NODOA* exekutatu_menua(int aukera, NODOA* ptrHasiera) {
	NODOA* ptrBerria = 0;
	DISKA* strAux = 0;
	strAux = ptrHasiera;
	int id = 0, estilo = 0; 
	float prezioa = 0;
	char str[MAX_STR], izena[20];

	switch (aukera)
	{
	case 1://sortu
		ptrHasiera = sortu_diskak(ptrHasiera);
		break;
	case 2://bistaratu 1
		printf("Ikusi nahi duzun nahi duzun ikaslearen ida: ");
		fgets(str, 64, stdin);
		sscanf(str, "%i", &id);
		bistaratu_bat(ptrHasiera, id);
		break;
	case 3://bistaratu 
		bistaratu_zerrenda(ptrHasiera);
		break;
	case 4://bistaratu estilo bateko diskak
		printf("Zer estiloko diskak ikusi nahi dituzu: ");
		fgets(str, 64, stdin);
		sscanf(str, "%i", &estilo);
		bistaratu_estilo_bateko_diskak(ptrHasiera, estilo, id);
		break;
	case 5://Aurkitu diskak izenburuarekin
		printf("Ze diska aurkitu nahi duzu:");
		fgets(str, 64, stdin);
		str[strlen(str) - 1] = '\0';
		strcpy(izena, str);
		aurkitu_izenburua(ptrHasiera, izena, estilo, id);
		break;
	case 6://Aldatu prezioa
		printf("Jarri izena aldatu nahi duzun prezioa:");
		fgets(str, 64, stdin);
		str[strlen(str) - 1] = '\0';
		strcpy(izena, str);

		printf("Jarri prezioa: ");
		fgets(str, 64, stdin);
		sscanf(str, "%f", &prezioa);

		modifikatuPrezioa(ptrHasiera, izena, prezioa);
		break;
	case 0:
		break;
	default:
		break;
	}
	return ptrHasiera;
}