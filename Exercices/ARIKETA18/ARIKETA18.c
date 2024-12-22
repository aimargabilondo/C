#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int i, Zatiketa = 0, n, m, Hondarra = 0;
	char str[128];


	printf("Zenbaki bat sakatu : ");
	scanf("%d", &n);
	printf("2. Zenbaki bat sakatu : ");
	scanf("%d", &m);

	for (i = n; i >= m; i-=m) {

		Zatiketa++;
	}
	Hondarra = i;

	printf("Zatiketa: %d\n", Zatiketa);
	printf("Hondarra: %d", Hondarra);

	return 0;
}