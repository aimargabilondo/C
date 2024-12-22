#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, Kont = 0, i;
	char str[128];

	printf("Zenbaki bat sartu: ");
	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		if (n % i == 0) {
			Kont++;
		}
	}
	if (Kont == 2) {
		printf("Zenbaki Lehena da");
	}
	else {
		printf("Ez da zenbaki lehena");
	}
	
	return 0;
}