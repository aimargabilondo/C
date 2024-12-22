#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, m, p, tmp=0;
	char str[128];

	printf("Lehenengo zenbakia eman:\n ");
	scanf("%d", &n);
	printf("Bigarren zenbakia eman:\n ");
	scanf("%d", &m);
	printf("Hirugarren zenbakia eman:\n ");
	scanf("%d", &p);

	if (n > m) {
		tmp = n;
		n = m;
		m = tmp;
	}

	if (m > p) {
		tmp = m;
		m = p;
		p = tmp;
	}

	if (n > m) {
		tmp = n;
		n = m;
		m = tmp;
	}

	printf("%d, %d, %d", n, m, p);
	
	return 0;
}