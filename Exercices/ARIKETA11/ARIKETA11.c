#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, i, Gehiketa=0;
	char str[128];

	printf("Zenbaki bat idatzi: \n ");
	scanf("%d", &n);

	for (i = n; i >= 0; i--) {
		Gehiketa += i;
		printf("%d ", i);
	}
	printf("\nZenbaki guztien gehiketa %d da.", Gehiketa);

	return 0;
}