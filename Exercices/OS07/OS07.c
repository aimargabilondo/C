#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, i, m, Biderketa = 1;
	char str[128];

	printf("Emaidazu zenbaki arrunt bat:");
	fgets(str, 128, stdin);
	sscanf(str, "%d", &n);

	for (i = n; i > 0; i--) {
		Biderketa *= i;
	}

	printf("Berreketa = %d", Biderketa);

	return 0;
}