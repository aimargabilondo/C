#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int i, j, n, m, Gehiketa=0;
	char str[128];

	
	printf("Zenbaki bat sakatu : ");
	scanf("%d", &n);
	printf("2. Zenbaki bat sakatu : ");
	scanf("%d", &m);

	for (i = 1; i <= m;i++){
		Gehiketa += n;
	}

	printf("Gehiketa: %d", Gehiketa);


	return 0;
}