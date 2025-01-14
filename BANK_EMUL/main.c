#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_NAME_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int accountNumber;
    float balance;
} Account;

void createAccount() {
    FILE *file = fopen("bank_accounts.txt", "a");
    if (file == NULL) {
        printf("No se pudo abrir el archivo de cuentas.\n");
        return;
    }

    Account newAccount;
    printf("Ingrese el nombre del titular de la cuenta: ");
    getchar();  // Limpiar el buffer
    fgets(newAccount.name, sizeof(newAccount.name), stdin);
    newAccount.name[strcspn(newAccount.name, "\n")] = '\0';  // Eliminar salto de línea

    newAccount.accountNumber = rand() % 10000;  // Número de cuenta aleatorio
    newAccount.balance = 0.0;

    fprintf(file, "%s,%d,%.2f\n", newAccount.name, newAccount.accountNumber, newAccount.balance);
    fclose(file);
    printf("Cuenta creada exitosamente. Número de cuenta: %d\n", newAccount.accountNumber);
}

void deposit() {
    FILE *file = fopen("bank_accounts.txt", "r+");
    if (file == NULL) {
        printf("No se pudo abrir el archivo de cuentas.\n");
        return;
    }

    int accountNumber;
    printf("Ingrese el número de cuenta para el depósito: ");
    scanf("%d", &accountNumber);

    Account account;
    int found = 0;
    while (fscanf(file, "%[^,],%d,%f\n", account.name, &account.accountNumber, &account.balance) != EOF) {
        if (account.accountNumber == accountNumber) {
            found = 1;
            float depositAmount;
            printf("Ingrese la cantidad a depositar: ");
            scanf("%f", &depositAmount);
            account.balance += depositAmount;

            // Reescribir el archivo
            fseek(file, -((long)sizeof(Account)), SEEK_CUR);
            fprintf(file, "%s,%d,%.2f\n", account.name, account.accountNumber, account.balance);
            printf("Depósito realizado. Nuevo saldo: %.2f\n", account.balance);
            break;
        }
    }

    if (!found) {
        printf("Cuenta no encontrada.\n");
    }

    fclose(file);
}

void viewBalance() {
    FILE *file = fopen("bank_accounts.txt", "r");
    if (file == NULL) {
        printf("No se pudo abrir el archivo de cuentas.\n");
        return;
    }

    int accountNumber;
    printf("Ingrese el número de cuenta para consultar saldo: ");
    scanf("%d", &accountNumber);

    Account account;
    int found = 0;
    while (fscanf(file, "%[^,],%d,%f\n", account.name, &account.accountNumber, &account.balance) != EOF) {
        if (account.accountNumber == accountNumber) {
            found = 1;
            printf("Saldo de la cuenta %d: %.2f\n", account.accountNumber, account.balance);
            break;
        }
    }

    if (!found) {
        printf("Cuenta no encontrada.\n");
    }

    fclose(file);
}

int main() {
    int option;
    do {
        printf("\nSimulador de Banco:\n");
        printf("1. Crear cuenta\n");
        printf("2. Realizar depósito\n");
        printf("3. Ver saldo\n");
        printf("4. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                viewBalance();
                break;
            case 4:
                printf("Saliendo del simulador...\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (option != 4);

    return 0;
}
