#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int Ordu;
	float Tarifa, Soldata;
	char str[128];

	printf("Zenbat Ordu egin ditu? \n ");
	scanf("%d", &Ordu);
	printf("Zein da Tarifa:\n ");
	scanf("%f", &Tarifa);
	

	if (Ordu <= 35) {
		Soldata = Ordu * Tarifa;
	} else {
		Soldata = Ordu * (Tarifa * 1.5);
	}

	if (600 < Soldata < 1200) {
		Soldata = Soldata * 0.15;
	}
	else if (Soldata > 1200) {
		Soldata = Soldata * 0.2;
	}

	printf("Hau da lortutako Soldata %f", Soldata);
	

	
	return 0;
}