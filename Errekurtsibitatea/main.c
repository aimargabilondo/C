#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 128 

typedef enum { FALSE, TRUE }BOOLEAN;
BOOLEAN fun(int zenb, int x);
void bistaratu(BOOLEAN lehena, int n);
void funtzio_errekurtsibitatea(int num);
BOOLEAN fun(int zenb, int x);


int main() {

    printf("==================================================\n");
    funtzio_errekurtsibitatea(5);

    BOOLEAN lehena_da = 0;
    lehena_da = fun(6, 6 / 2);
    bistaratu(lehena_da, 6);
    
    lehena_da = fun(7, 7 / 2);
    bistaratu(lehena_da, 7);

    return 0;
}

void funtzio_errekurtsibitatea(int num) {

    if (num == 0) {
        printf("\nHemen amaitzen dira dei rekursiboak\n");
    }
    else {
        printf("\nlehenengo printf-a: %i\n", num);

        funtzio_errekurtsibitatea(num - 1);

        printf("\n%i\n", num);
    }

}

BOOLEAN fun(int zenb, int x) {
    if (x == 1) return 1;
    else {
        if (zenb % x == 0) return 0;
        else return fun(zenb, x - 1);
    }
}

void bistaratu(BOOLEAN lehena, int n) {
    if (lehena) printf("%d Zenbakia lehena da.\n", n);
    else printf("%d Zenbakia ez da lehena.\n", n);
}