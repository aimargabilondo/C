#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int i = 0, n, Handiena = -999, j = 0 ;
	char str[128];

	do {
		printf("Zenbakia sakatu : ");
		scanf("%d", &n);

		if (n > Handiena) {
			Handiena = n;
			j++;
		}
		i++;

	} while (i < 3);

	if (j == 3) {
		printf("Ordenean daude");
	}
	else {
		printf("Ez daude ordenean");
	}

	return 0;
}