#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int Gehiketa = 0, i;
	char str[128];

	

	for (i = 1; i <= 100; i++) {
		if (i % 2 == 0) {
			printf("%d\n", i);
		}
		else {
			Gehiketa = Gehiketa + i;
		}
	}
	printf("%d, Bakoitien gehieta", Gehiketa);



	return 0;
}