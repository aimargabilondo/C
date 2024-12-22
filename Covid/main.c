#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Datu egitura definizioa
struct Gaixoa {
    int id;
    char izena[50];
    char abizena[50];
    char emaitza;
};

// Funtzioen definizioak
void gaixoa_pantailan(struct Gaixoa gaixoa);
void emaitza_gordetu(struct Gaixoa gaixoak[], int emaitzak[], int tamaina);
void informeak_pantailan(int emaitzak[], int tamaina);
void sailkatu_herriak(struct Gaixoa gaixoak[], int emaitzak[], int tamaina);

int main() {
    // Gaixoak eta emaitzak gordetzeko datu egiturak
    struct Gaixoa gaixoak[] = {
        {1, "Enaitz", "Ezpeleta", 'p'},
        {2, "Joseba", "Agirre", 'z'},
        {3, "Pedro", "Arrieta", 'n'}
    };
    int emaitzak[] = { 1, 2, 3 };

    // Emaitzen txategia ordenatu
    emaitza_gordetu(gaixoak, emaitzak, sizeof(gaixoak) / sizeof(gaixoak[0]));

    // Informeak pantailan idatzi
    informeak_pantailan(emaitzak, sizeof(emaitzak) / sizeof(emaitzak[0]));

    // Herriak mailaren arabera sailkatu eta emaitza pantailan idatzi
    sailkatu_herriak(gaixoak, emaitzak, sizeof(gaixoak) / sizeof(gaixoak[0]));

    return 0;
}

void gaixoa_pantailan(struct Gaixoa gaixoa) {
    printf("%s %s\n", gaixoa.izena, gaixoa.abizena);
}

void emaitza_gordetu(struct Gaixoa gaixoak[], int emaitzak[], int tamaina) {
    for (int i = 0; i < tamaina - 1; i++) {
        for (int j = i + 1; j < tamaina; j++) {
            if (emaitzak[i] > emaitzak[j]) {
                // Emaitzak txikitu
                int tmp = emaitzak[i];
                emaitzak[i] = emaitzak[j];
                emaitzak[j] = tmp;

                // Gaixoak ere bateratu
                struct Gaixoa tmp_gaixoa = gaixoak[i];
                gaixoak[i] = gaixoak[j];
                gaixoak[j] = tmp_gaixoa;
            }
        }
    }
}

void informeak_pantailan(int emaitzak[], int tamaina) {
    // Adin batazbestekoa eta desbiazio estandarra kalkulatu
    float adin_batazbestekoa = 0;
    for (int i = 0; i < tamaina; i++) {
        adin_batazbestekoa += emaitzak[i];
    }
    adin_batazbestekoa /= tamaina;

    float desbiazio_estandarra = 0;
    for (int i = 0; i < tamaina; i++) {
        desbiazio_estandarra += (emaitzak[i] - adin_batazbestekoa) * (emaitzak[i] - adin_batazbestekoa);
    }
    desbiazio_estandarra = sqrt(desbiazio_estandarra / tamaina);

    // Informazioa pantailan idatzi
    printf("Egunero positibo ematen duten gaixoen adin batazbestekoa: %.2f\n", adin_batazbestekoa);
    printf("Desbiazio estandarra: %.2f\n", desbiazio_estandarra);
}

void sailkatu_herriak(struct Gaixoa gaixoak[], int emaitzak[], int tamaina) {
    // Herriak sailkatu eta emaitza pantailan idatzi
    int maila_berdea = 0, abisu_maila = 0, gune_beroa = 0;

    for (int i = 0; i < tamaina; i++) {
        printf("%d - ", gaixoak[i].id);
        gaixoa_pantailan(gaixoak[i]);

        switch (gaixoak[i].emaitza) {
        case 'p':
            printf("Positiboa\n");
            if (gaixoak[i].id <= 1) {
                maila_berdea++;
            }
            else if (gaixoak[i].id <= 2) {
                abisu_maila++;
            }
            else {
                gune_beroa++;
            }
            break;
        case 'z':
            printf("Zalantza\n");
            break;
        case 'n':
            printf("Negatiboa\n");
            break;
        default:
            break;
        }
    }

    // Sailketa emaitza pantailan idatzi
    printf("\nHerriak mailaren arabera sailkatuta:\n");
    printf("Maila Berdea: %d kasu\n", maila_berdea);
    printf("Abisu Maila: %d kasu\n", abisu_maila);
    printf("Gune Beroa: %d kasu\n", gune_beroa);
}
