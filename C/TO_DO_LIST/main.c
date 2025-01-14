#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_LENGTH 255

void displayTasks() {
    FILE *file = fopen("tasks.txt", "r");
    if (file == NULL) {
        printf("No hay tareas guardadas.\n");
        return;
    }

    char task[MAX_LENGTH];
    int index = 1;
    while (fgets(task, sizeof(task), file)) {
        printf("%d. %s", index++, task);
    }
    fclose(file);
}

void addTask() {
    char task[MAX_LENGTH];
    printf("Ingrese una nueva tarea: ");
    getchar();  // Limpiar el buffer
    fgets(task, sizeof(task), stdin);

    FILE *file = fopen("tasks.txt", "a");
    if (file == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }
    fprintf(file, "%s", task);
    fclose(file);
    printf("Tarea agregada con éxito.\n");
}

void deleteTask() {
    FILE *file = fopen("tasks.txt", "r");
    if (file == NULL) {
        printf("No hay tareas para eliminar.\n");
        return;
    }

    char tasks[MAX_TASKS][MAX_LENGTH];
    int count = 0;

    while (fgets(tasks[count], sizeof(tasks[count]), file)) {
        count++;
    }
    fclose(file);

    printf("Ingrese el número de la tarea a eliminar (1-%d): ", count);
    int taskNumber;
    scanf("%d", &taskNumber);

    if (taskNumber < 1 || taskNumber > count) {
        printf("Número de tarea inválido.\n");
        return;
    }

    file = fopen("tasks.txt", "w");
    for (int i = 0; i < count; i++) {
        if (i != taskNumber - 1) {
            fprintf(file, "%s", tasks[i]);
        }
    }
    fclose(file);
    printf("Tarea eliminada con éxito.\n");
}

int main() {
    int option;
    do {
        printf("\nGestor de Tareas:\n");
        printf("1. Mostrar tareas\n");
        printf("2. Agregar tarea\n");
        printf("3. Eliminar tarea\n");
        printf("4. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                displayTasks();
                break;
            case 2:
                addTask();
                break;
            case 3:
                deleteTask();
                break;
            case 4:
                printf("Saliendo del gestor de tareas...\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (option != 4);

    return 0;
}
