#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int i, n, j, Hutsune, k;
	char str[128];


	printf("Zenbakia sakatu : ");
	scanf("%d", &n);
	Hutsune = n;
	for (i = 1; i <= n; i++) {
		for (k = Hutsune; k >= 0; k--) {
			printf(" ");
		}
		Hutsune--;
		for (j = 0; j < i; j++) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}