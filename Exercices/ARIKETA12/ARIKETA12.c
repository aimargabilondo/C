#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, m, i, Gehiketa = 0, tmp;
	char str[128];

	printf("Zenbaki bat idatzi: \n ");
	scanf("%d", &n);
	printf("Beste zenbaki bat idatzi: \n ");
	scanf("%d", &m);

	if (n > m) {
		tmp = n;
		n = m;
		m = tmp;
	}

	for (i = n; i <= m; i++) {
		if (i % 2 == 0) {
			Gehiketa += i;
		}
	}
	printf("\nZenbaki guztien gehiketa %d da.", Gehiketa);

	return 0;
}