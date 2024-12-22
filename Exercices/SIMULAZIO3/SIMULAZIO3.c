#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, i = 1, m, tmp=0, Kont=0;
	char str[128];

	printf("Emaidazu zenbaki bat: ");
	fgets(str, 128, stdin);
	sscanf(str, "%d", &n);

	printf("Emaidazu beste zenbaki bat: ");
	fgets(str, 128, stdin);
	sscanf(str, "%d", &m);

	if (m > n) {
		tmp = n;
		n = m;
		m = tmp;
	}

	do {

		i++;
		if (n % i == 0 && m % i == 0) {
			Kont++;
		}

	} while (Kont < 2 && i <= m);

	if (Kont == 2) {
		printf("%d", i);
	}
	else {
		printf("Ez dauzka.");
	}

	return 0;
}