#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, Kont = 0, i;
	char str[128];

	printf("Zenbaki bat sartu: ");
	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		printf("*");
	}

	return 0;
}