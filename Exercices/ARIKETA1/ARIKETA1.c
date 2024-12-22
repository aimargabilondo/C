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

	if (n < m && p < m ) {
		printf("%d, Da Handiena", m);
	}
	else if(m < n && p < n ) {
		printf("%d, Da Handiena", n);
	}
	if (m < p && n < p) {
		printf("%d, Da Handiena", p);
	}
	else {
		printf("Zenbakiak berdinak dira.");
	}
	

	return 0;
}