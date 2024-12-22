#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int Bidai, i;
	float Totala;
	char str[128];

	printf("Zenbat bidai nahi ditu? \n ");
	scanf("%d", &Bidai);
	
	if (Bidai > 5) {
		Totala = 3.4;
		for (i = 6; i <= Bidai; i++) {
			Totala = Totala + 0.4;
		}
		printf("Bidai guztien totala: %f", Totala);
	}
	else if (1 < Bidai < 6) {
		Totala = 1; 
		for (i = 2; i <= Bidai; i++) {
			Totala = Totala + 0.6;
		}
		printf("Bidai guztien totala: %f", Totala);
	}
	else{
		printf("Bidai guztien totala: 1");
	}

	return 0;
}