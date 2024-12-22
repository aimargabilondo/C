#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, Kont = 0, Gehiketa = 0, Txikiena = 9999, Handiena = -9999;
	float Media = 0;
	char str[128];


	do {

		printf("Emaidazu zenbaki bat: ");
		fgets(str, 128, stdin);
		sscanf(str, "%d", &n);

		Gehiketa += n;

		if ( Txikiena > n) {
			Txikiena = n;
		}
		if( n > Handiena){
			Handiena = n;
		}

		Kont++;

	}while(Kont < 10);

	Media = Gehiketa / 10;

	printf("Zerrendaren media: %f\nZenbaki handiena:%d\nZenbaki txikiena:%d", Media, Handiena, Txikiena);

	

	return 0;
}