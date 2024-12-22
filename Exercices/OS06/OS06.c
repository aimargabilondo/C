#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, i,m, Biderketa = 1;
	char str[128];

	printf("Emaidazu zenbaki arrunt bat:");
	fgets(str, 128, stdin);
	sscanf(str, "%d", &n);

	printf("Emaidazu zenbaki arrunt bat:");
	fgets(str, 128, stdin);
	sscanf(str, "%d", &m);

	for (i = m; i > 0; i--) {
		Biderketa *= n;
	}

	printf("Berreketa = %d", Biderketa);

	
	return 0;
}