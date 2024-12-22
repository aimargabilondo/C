#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n=0, Zatiketa = 1, i, Lehena, Kont = 0;
	char str[128];

	while (Kont < 101) {
		Lehena = 0;
		n++;
		for (i = n; i > 0; i--) {
			if (n % i == 0) {
				Lehena++;
			}
		}
		if (Lehena == 2) {
			printf("%d ", n);
			Kont++;
		}
	}



	return 0;
}