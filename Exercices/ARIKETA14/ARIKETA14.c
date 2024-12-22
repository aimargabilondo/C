#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int Ura;
	float Kuota, Finala = 0;
	char str[128];

	printf("Zenbat Litro Ur kontsuitu ditu? \n ");
	scanf("%d", &Ura);

	if (Ura < 0) {
		printf("ERROREA: Sartutako zenbakia ez da egokia.");
	}
	else {
		if (50 < Ura <= 200) {
			Finala = (Ura - 50) * 0.1;
		}
		else if (Ura > 200) {

			Finala = ((Ura - 150) * 0.1) + ((Ura - 200) * 0.3);
		}
		Finala = Finala + 6;
		printf("Hau da izandako gastua %f", Finala);
	}



	return 0;
}