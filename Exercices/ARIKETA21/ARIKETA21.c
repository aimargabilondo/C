#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int i = 0, n, Gehiketa = 0;
	float Media = 0;
	char str[128];

	do {
		printf("Zenbakia sakatu : ");
		scanf("%d", &n);

		Gehiketa += n;
		if (n != 0) {
			i++;
		}

	} while (n != 0);
	Media = Gehiketa / i;

	printf("Zerrendaren media: %2.f", Media);


	return 0;
}