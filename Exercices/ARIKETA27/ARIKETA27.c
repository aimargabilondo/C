#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int  Ordu, Minutu, Segundu;
	char str[128];

	printf("Ordua sakatu : ");
	scanf("%d", &Ordu);
	printf("Minutuak sakatu : ");
	scanf("%d", &Minutu);
	printf("Segunduak sakatu : ");
	scanf("%d", &Segundu);

	Segundu++;
	if (Segundu < 60) {
		printf("Segundu bat geroago Ordua %d:%d:%d izango da.", Ordu, Minutu, Segundu);
	}
	else {
		Minutu++;
		Segundu = Segundu - 60;
		if (Minutu < 60) {
			printf("Segundu bat geroago Ordua %d:%d:%d izango da.", Ordu, Minutu, Segundu);
		}
		else {
			Ordu++;
			Minutu = Minutu - 60;
			if (Ordu < 24) {
				printf("Segundu bat geroago Ordua %d:%d:%d izango da.", Ordu, Minutu, Segundu);
			}
			else {
				Ordu = 0;
				printf("Segundu bat geroago Ordua %d:%d:%d izango da.", Ordu, Minutu, Segundu);
			}
		}
	
	}
	



	return 0;
}