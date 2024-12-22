#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int i, n, handiena=-999, txikiena= 999;
	char str[128];


	for (i = 1; i <= 5; i++) {
		printf("%d. zenbakia sakatu : ", i);
		scanf("%d", &n);

		if (n > handiena) {
			handiena = n;
		}
		if (n < txikiena) {
			txikiena = n;
		}

	}
	printf("Zenbaki handiena: %d\n", handiena);
	printf("Zenbaki txikiena: %d", txikiena);



	return 0;
}