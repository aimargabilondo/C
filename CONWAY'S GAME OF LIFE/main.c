#include <stdio.h>
#include <stdlib.h>

//En Windows: Usa Cygwin, MinGW o WSL para poder usar bibliotecas como <unistd.h> y <arpa/inet.h>

#include <unistd.h>

#define ROWS 20
#define COLS 40

void printGrid(int grid[ROWS][COLS]) {
    system("clear");
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf(grid[i][j] ? "O" : ".");
        }
        printf("\n");
    }
    usleep(200000);
}

int countNeighbors(int grid[ROWS][COLS], int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;
            int nx = x + i, ny = y + j;
            if (nx >= 0 && nx < ROWS && ny >= 0 && ny < COLS)
                count += grid[nx][ny];
        }
    }
    return count;
}

void updateGrid(int grid[ROWS][COLS]) {
    int newGrid[ROWS][COLS] = {0};

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            int neighbors = countNeighbors(grid, i, j);
            if (grid[i][j] && (neighbors == 2 || neighbors == 3))
                newGrid[i][j] = 1;
            else if (!grid[i][j] && neighbors == 3)
                newGrid[i][j] = 1;
        }
    }

    for (int i = 0; i < ROWS; ++i)
        for (int j = 0; j < COLS; ++j)
            grid[i][j] = newGrid[i][j];
}

int main() {
    int grid[ROWS][COLS] = {0};

    // Inicialización de ejemplo
    grid[10][20] = grid[11][21] = grid[12][19] = grid[12][20] = grid[12][21] = 1;

    while (1) {
        printGrid(grid);
        updateGrid(grid);
    }

    return 0;
}
