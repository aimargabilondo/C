#include "orokorrak.h"

void jarraitu(FILE* fitxategia) {
    fclose(fitxategia);
    printf("Sakatu return jarraitzeko...");
    getchar();
}
void borratu_pantila() {
    system("cls");
}