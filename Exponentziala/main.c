#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float expon(float x) {
    if (x < 0.0001 && x > -0.0001) // `x` oso txikia bada, 1 + x itzuliko dugu
        return 1 + x;
    else
        return expon(x / 2) * expon(x / 2); // Beste azkenego batzuk expon(x) biderkatu
}

int main() {
    float x = 1.0; // Adibidez, x = 2
    printf("Expon: %.3f\n", expon(x));
    return 0;
}