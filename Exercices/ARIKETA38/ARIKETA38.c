#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, Zatiketa = 1, i, Batura = 0, Hondarra = 0;
	char str[128];

	printf("Zenbaki bat sartu: ");
	scanf("%d", &n);

	while (Zatiketa > 0) {
		Zatiketa = n / 10;
		Hondarra = n % 10;
		n = Zatiketa;
		Batura += Hondarra;
	}
	printf("Digituen batura, %d da", Batura);


	return 0;
}