#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

void openFile(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("No se pudo abrir el archivo %s\n", filename);
        return;
    }

    char line[MAX_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

void writeFile(char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("No se pudo abrir el archivo %s para escribir.\n", filename);
        return;
    }

    char content[MAX_LENGTH];
    printf("Escribe el contenido para guardar (fin con una línea vacía):\n");
    getchar();  // Limpiar el buffer
    while (1) {
        fgets(content, sizeof(content), stdin);
        if (strcmp(content, "\n") == 0) break;  // Finaliza cuando se ingresa una línea vacía
        fputs(content, file);
    }
    fclose(file);
    printf("Archivo guardado correctamente.\n");
}

int main() {
    int option;
    char filename[100];

    printf("Mini Editor de Texto\n");
    printf("Ingrese el nombre del archivo: ");
    scanf("%s", filename);

    do {
        printf("\nOpciones:\n");
        printf("1. Ver archivo\n");
        printf("2. Modificar archivo\n");
        printf("3. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                openFile(filename);
                break;
            case 2:
                writeFile(filename);
                break;
            case 3:
                printf("Saliendo del editor...\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (option != 3);

    return 0;
}
