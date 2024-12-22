#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int  Neurri;
	float Oina, Altuera, Bolumena = 0;;
	char str[128];

	printf("Ze neurritan egin nahi dezu lan? 1-ZENTIMETRO 2-INCHES ");
	scanf("%d", &Neurri);
	printf("Triangeluaren oina : ");
	scanf("%f", &Oina);
	printf("Triangeluaren altuera : ");
	scanf("%f", &Altuera);

	Bolumena = (Oina * Altuera) / 3;

	if (Neurri == 1) {
		
		printf("Zentimetrotan, Piramidearen bolumena %fcm da.", Bolumena);
	}
	else {
		Bolumena = Bolumena / 2.54;
		printf("Inchetan, Piramidearen bolumena %fin da.", Bolumena);
	}


	return 0;
}