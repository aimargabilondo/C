#include "orokorrak.h"

void izenaGaldetu(char izena[]) {
    printf("Ezabatu nahi duzun pelikularen izena: ");
    fgets(izena, MAX_STR, stdin);
    izena[strlen(izena) - 1] = '\0';
}
void jarraitu() {
    printf("Sakatu return jarraitzeko...");
    getchar();
}
void borratu_pantila() {
    system("cls");
}