#include <stdio.h>
#include <string.h>
#define MAX_STRING 100
#define BAI 1
#define EZ 0

void irakurriEsaldia(char* str);
void kapikuaKatea(char* str, int* egoera);
void inprimituZuzenAlderantziz(char* str);

int main(void)
{
    char str[MAX_STRING];
    int egoera = BAI;

    irakurriEsaldia(str);
    printf("Esaldia: %s[fin]\n", str);
    kapikuaKatea(str, &egoera);

    if (egoera == BAI) { printf("Esaldia kapikua da.\n"); }
    else { printf("Esaldia Ez da kapikua.\n"); }

    inprimituZuzenAlderantziz(str);

    return 0;
}

void irakurriEsaldia(char* str) {
    printf("Sartu esaldi bat: ");
    fgets(str, MAX_STRING, stdin);
    // Katen azkena '\n' karakterea izan daiteke, hori kendu behar da
    str[strcspn(str, "\n")] = '\0';
}

void kapikuaKatea(char* str, int* egoera) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - 1 - i]) {
            *egoera = EZ;
            return;
        }
    }
}

void inprimituZuzenAlderantziz(char* str) {
    int length = strlen(str);
    printf("Esaldia zuzen eta alderantziz: ");
    for (int i = length - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}
