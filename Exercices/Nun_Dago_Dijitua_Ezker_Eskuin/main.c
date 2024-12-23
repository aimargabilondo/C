#include <stdio.h>
#include <math.h>

int main() {
    int numero, digito, posicion = -1, divisor;

    // Solicitar un n�mero entero al usuario
    printf("Introduce un numero entero: ");
    scanf("%d", &numero);

    // Solicitar un d�gito al usuario
    printf("Introduce un digito (0-9): ");
    scanf("%d", &digito);

    // Guardar el n�mero original para su posterior uso
    int numeroOriginal = numero;

    // Calcular el n�mero de d�gitos en el n�mero
    int numDigitos = (numero == 0) ? 1 : (int)log10(abs(numero)) + 1;

    // Calcular el divisor para extraer el d�gito deseado
    divisor = pow(10, numDigitos - 1);

    // Buscar el d�gito en el n�mero utilizando divisiones
    while (numero > 0) {
        int cociente = numero / divisor;
        if (cociente == digito) {
            // Si el cociente es igual al d�gito, se encontr�
            posicion = numDigitos - 1;
            break;
        }
        numero %= divisor; // Obtener el residuo de la divisi�n
        divisor /= 10;     // Dividir el divisor por 10
        numDigitos--;
    }

    // Mostrar el resultado
    if (posicion != -1) {
        printf("El digito %d se encuentra en la posicion %d (empezando desde la izquierda).\n", digito, posicion);
    }
    else {
        printf("El digito %d no se encuentra en el numero %d.\n", digito, numeroOriginal);
    }

    return 0;
}
