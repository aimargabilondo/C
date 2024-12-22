#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int i = 0;
	float Media = 0, n, Gehiketa=0;
	char str[128];

	do {
		printf("Nota sakatu : ");
		scanf("%f", &n);

		Gehiketa += n;
		i++;

	} while (i < 3);

	Media = Gehiketa / 3;
	printf("Noten bataz bestekoa %f da.", Media);



	return 0;
}