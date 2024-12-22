#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, i, tmp = 0, x = 0, y = 1, Kont2 = 0;
	char str[128];

	while (tmp < 101) {
		
		tmp = x + y;
		x = y;
		y = tmp;

		Kont2 = 0;
		
		for (i = tmp; i > 0; i--) {
			if (tmp % i == 0) {
				Kont2++;
			}
		}
		if (Kont2 == 2) {
			printf("%d ", tmp);
		}
	}
	return 0;
}

