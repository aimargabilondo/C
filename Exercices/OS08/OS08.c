#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, i, m, Kont=0;
	char str[128];

	printf("Emaidazu zenbaki arrunt bat:");
	fgets(str, 128, stdin);
	sscanf(str, "%d", &n);

	for (i = n; i > 0; i--) {
		if (n % i == 0) {
			Kont++;
		}
	}
	if (Kont == 2) {
		printf("Lehena da");
	}
	else {
		printf("EZ da lehena");
	}

	return 0;
}