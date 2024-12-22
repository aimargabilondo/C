#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int  n, Gehiketa = 0;
	char str[128];

	do {
		printf("Zenbakia sakatu : ");
		scanf("%d", &n);

		Gehiketa += n;

	} while (n != 0);

	printf("Zerrendaren media: %d", Gehiketa);

	return 0;
}