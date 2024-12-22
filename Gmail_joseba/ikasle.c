#include <stdio.h>
#include <string.h>

#include "ikasle.h"

ERABILTZAILEA eskatuHelbidea() {
	ERABILTZAILEA erabil;
	char str[MAX_STR];
	int egokia = 0;
	//.....
	system("clear"); //system("cls");
	printf("Sartu zure emaila?");
	/*fgets( str , MAX_STR, stdin);
	str[strlen(str)-1]='\0';
	strcpy( erabil.emaila , str );*/

	fgets(erabil.emaila, MAX_STR, stdin);
	erabil.emaila[strlen(erabil.emaila) - 1] = '\0';

	/*egokia = balidatuEmaila(erabil.emaila);
	if (egokia == 0) primtf("[ERROR] Email desegokia.\n");*/

	return erabil;
}

void bistaratuErabiltzailea(ERABILTZAILEA erabil) {
	printf("Bistaratzen erabilztrailearen emaila:%s\n", erabil.emaila);

}

void bistaratuErabiltzaileaPTRgaz(ERABILTZAILEA* ptr_erabil) {
	printf("Bistaratzen erabilztrailearen emaila:%s\n", ptr_erabil->emaila);
}

void eskatuHainbatHelbidev2(ERABILTZAILEA* erabiltzaileak, int kop) {
	ERABILTZAILEA erabil;
	char str[MAX_STR];
	int egokia = 0;

	while (erabil.emaila == 0) {
		system("clear");
		printf("Sartu zure emaila?");

		fgets(erabil.emaila, MAX_STR, stdin);
		erabil.emaila[strlen(erabil.emaila) - 1] = '\0';
		kop++;
	}

}

void ateraIzenaV2(ERABILTZAILEA* erak) {
	int pos = 0;
	int i = 0;
	
	while (erak->emaila[pos] != '.' && erak->emaila[pos] != '\0') {
		pos++;
	}
	for (i = 0; i < pos; i++) {
		erak->izena[i] = erak->emaila[pos];
	}
}

void ateraAbizenaV2(ERABILTZAILEA* erak) {
	int pos = 0;
	int i = 0;

	while (erak->emaila[pos] != '.' && erak->emaila[pos] != '\0') {
		pos++;
	}
	for (i = 0; i < pos; i++) {
		erak->abizena[i] = erak->emaila[pos];
	}
}