#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	float  Ticket = 0;
	int Egun, Distantzia;
	char str[128];

	printf("Distantzia kopurua: ");
	scanf("%d", &Distantzia);
	printf("Egun kopurua: ");
	scanf("%d", &Egun);

	Ticket = Distantzia * 0.10;
	if (Distantzia > 800 && Egun > 7) {
		Ticket = Ticket * 0.70;
	}
	printf("Ticketak %f Euro balio du.", Ticket);
	

	return 0;
}