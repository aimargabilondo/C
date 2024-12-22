#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int numero, digito, posicion = -1, divisor = 1;

    // Solicitar un número entero al usuario
    printf("Introduce un numero entero: ");
    scanf("%d", &numero);

    // Solicitar un dígito al usuario
    printf("Introduce un digito (0-9): ");
    scanf("%d", &digito);

    int numeroOriginal = numero; // Guardar el número original

    // Buscar el dígito en el número utilizando divisiones
    while (numero > 0) {
        int residuo = numero % 10;
        if (residuo == digito) {
            // Si el residuo es igual al dígito, se encontró
            posicion = 0;
            break;
        }
        numero /= 10; // Dividir el número entre 10
        divisor *= 10;
        posicion++;
    }

    // Mostrar el resultado
    if (posicion != -1) {
        printf("El digito %d se encuentra en la posicion %d (empezando desde la derecha).\n", digito, posicion);
    }
    else {
        printf("El digito %d no se encuentra en el numero %d.\n", digito, numeroOriginal);
    }

    return 0;
}
