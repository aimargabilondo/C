#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int i, n, j;
	char str[128];

	
	printf("Zenbakia sakatu : ");
	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		for (j = n; j > 0; j--) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}