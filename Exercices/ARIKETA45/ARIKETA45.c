#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int  n, Bikoiti = 0, Bakoiti = 0, Zenbat = 0;
	char str[128];

	do {
		printf("Zenbakia sakatu : ");
		scanf("%d", &n);

		if (n % 2 == 0) {
			Bikoiti++;
		}
		else {
			Bakoiti++;
		}
		Zenbat++;

	} while (n != 0);

	printf("Bikoitiak: %d\n", Bikoiti-1);
	printf("Bakoitiak: %d\n", Bakoiti);
	printf("Zenbat zenbaki: %d", Zenbat-1);

	return 0;
}