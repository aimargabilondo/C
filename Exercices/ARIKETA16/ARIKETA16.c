#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int i = 1, n, handiena = -999, txikiena = 999, Pos = 0, Pos2=0;
	char str[128];

	do {
		printf("%d. zenbakia sakatu : ", i);
		scanf("%d", &n);

		if (n > handiena) {
			handiena = n;
			Pos = i;
		}
		if (n < txikiena && n != 0) {
				txikiena = n;
			Pos2 = i;
		}
		i++;
		
	} while (n != 0);

	printf("Zenbaki handiena: %d, %d. Posizioan\n", handiena, Pos);
	printf("Zenbaki txikiena: %d, %d. Posizioan", txikiena, Pos2);

	return 0;
}