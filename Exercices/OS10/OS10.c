#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, batura = 0;
	char str[128];

	printf("Emaidazu zenbaki bat: ");
	fgets(str, 128, stdin);
	sscanf(str, "%d", &n);

	n = n * n;
	while (n > 0) {
		batura = batura + n % 10;
		n = n / 10;
	}

	printf("Batuketa: %d", batura);

	return 0;
}