#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, m, tmp, i, j, Kont = 0;
	char str[128];

	printf("Zenbaki bat sartu: ");
	scanf("%d", &n);
	printf("Beste zenbaki bat sartu: ");
	scanf("%d", &m);

	if (m > n) {
		tmp = n;
		n = m;
		m = tmp;
	}

	for (i = m; i <= n; i++) {
		Kont = 0;
		for (j = i; j > 0; j--) {
			if (i % j == 0) {
				Kont++;
			}
			
		}
		if (Kont == 2) {
			printf("%d ", i);
		}
	}
	
	return 0;
}