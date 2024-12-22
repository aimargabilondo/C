#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ikaslea {
    char izena[50];
    char abizena[50];
};

void eskatuHelbidea() {
    printf("Sartu MU-ko ikasleen email helbideak, '@alumni.mondragon.edu' gehituz:\n");
}

void ateraIzena(struct Ikaslea* erak) {
    printf("Sartu izena: ");
    scanf("%s", erak->izena);
}

void ateraAbizena(struct Ikaslea* erak) {
    printf("Sartu abizena: ");
    scanf("%s", erak->abizena);
}

void pantailaratu(struct Ikaslea* erak, int kop) {
    printf("\nIkasleen datuak:\n");
    char *gmail_oso = 0;
    for (int i = 0; i < kop; i++) {
        printf("Emaila: %s.%s@alumni.mondragon.edu\n", erak[i].izena, erak[i].abizena);
        strcat(gmail_oso, erak[i].izena);
        strcat(gmail_oso, ".");
        strcat(gmail_oso, erak[i].abizena);
        strcat(gmail_oso, "@alumni.mondragon.edu\n");

    }
    for (int i = 0; i < kop; i++) {
        printf("Emaila: %s", gmail_oso[i]);
    }
}

int main() {
    int kop;
    struct Ikaslea* ikasleak;

    eskatuHelbidea();
    printf("Zenbat ikasle diren sartu: ");
    scanf("%d", &kop);

    ikasleak = (struct Ikaslea*)malloc(kop * sizeof(struct Ikaslea));
    if (ikasleak == NULL) {
        printf("Errorea: ezin da memoriaren erreserba egin.\n");
        return 1;
    }

    for (int i = 0; i < kop; i++) {
        printf("\nIkasle %d:\n", i + 1);
        ateraIzena(&ikasleak[i]);
        ateraAbizena(&ikasleak[i]);
    }

    pantailaratu(ikasleak, kop);

    free(ikasleak);

    return 0;
}
