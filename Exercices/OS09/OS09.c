#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, batura = 0, i;
	char str[128];

	printf("Emaidazu zenbaki bat: ");
	fgets(str, 128, stdin);
	sscanf(str, "%d", &n);

	for (i = 1; i <= n / 2; i++) {

		if (n % i == 0) {
			batura += i;
		}

	}

	if (batura == n) {
		printf("Zenbaki perfektua da");
	}
	else {
		printf("Ez da zenbaki perfektua");
	}
	
	return 0;
}