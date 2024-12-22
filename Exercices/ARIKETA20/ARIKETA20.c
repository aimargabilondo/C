#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int i, Biderketa = 1, n;
	char str[128];


	printf("Zenbaki bat sakatu : ");
	scanf("%d", &n);


	for (i = n; i > 0; i--) {
		if (n % i == 0) {
			printf("%d ", i);
		}
	}

	return 0;
}