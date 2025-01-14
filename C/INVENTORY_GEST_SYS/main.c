#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
} Product;

void addProduct() {
    FILE *file = fopen("inventory.txt", "a");
    if (file == NULL) {
        printf("No se pudo abrir el archivo de inventario.\n");
        return;
    }

    Product newProduct;
    printf("Ingrese el nombre del producto: ");
    getchar();  // Limpiar el buffer
    fgets(newProduct.name, sizeof(newProduct.name), stdin);
    newProduct.name[strcspn(newProduct.name, "\n")] = '\0';  // Eliminar salto de línea

    printf("Ingrese el precio del producto: ");
    scanf("%f", &newProduct.price);

    printf("Ingrese la cantidad del producto: ");
    scanf("%d", &newProduct.quantity);

    fprintf(file, "%s,%f,%d\n", newProduct.name, newProduct.price, newProduct.quantity);
    fclose(file);
    printf("Producto agregado exitosamente.\n");
}

void displayInventory() {
    FILE *file = fopen("inventory.txt", "r");
    if (file == NULL) {
        printf("No se pudo abrir el archivo de inventario.\n");
        return;
    }

    Product product;
    while (fscanf(file, "%[^,],%f,%d\n", product.name, &product.price, &product.quantity) != EOF) {
        printf("Producto: %s | Precio: %.2f | Cantidad: %d\n", product.name, product.price, product.quantity);
    }
    fclose(file);
}

int main() {
    int option;
    do {
        printf("\nSistema de Gestión de Inventario:\n");
        printf("1. Ver inventario\n");
        printf("2. Agregar producto\n");
        printf("3. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                displayInventory();
                break;
            case 2:
                addProduct();
                break;
            case 3:
                printf("Saliendo del sistema...\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (option != 3);

    return 0;
}
