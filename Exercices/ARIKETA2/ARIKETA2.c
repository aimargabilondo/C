#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, m, p;
	char str[128];

	printf("Lehenengo zenbakia eman:\n ");
	scanf("%d", &n);
	printf("Bigarren zenbakia eman:\n ");
	scanf("%d", &m);
	printf("Hirugarren zenbakia eman:\n ");
	scanf("%d", &p);

	if (n < m && p < m && p < n) {
		printf("%d, %d, %d", m, n, p);
	}
	else if (n < m && p < m && n < p) {
		printf("%d, %d, %d", m, p, n);
	}

	if (m < n && p < n && m < p) {
		printf("%d, %d, %d", n, p, m);
	}
	else if (m < n && p < n && p < m) {
		printf("%d, %d, %d", n, m, p);
	}

	if (m < p && n < p && m < n) {
		printf("%d, %d, %d", p, n, m);
	}
	else if (m < p && n < p && n < m) {
		printf("%d, %d, %d", p, m, n);
	}

	return 0;
}