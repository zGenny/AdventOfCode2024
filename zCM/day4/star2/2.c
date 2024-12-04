#include <stdio.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define WORD "MAS"

int check_xmas(char matrix[MAX_ROWS][MAX_COLS], int rows, int cols, int x, int y) {
    if (matrix[x][y] != 'A') {
        return 0;
    }

    // Controllo nelle 4 diagonali

    // 1. Diagonale su-sinistra per "M", diagonale giù-destra per "S"
    if (x - 1 >= 0 && y - 1 >= 0 && matrix[x - 1][y - 1] == 'M' && x + 1 < rows && y + 1 < cols && matrix[x + 1][y + 1] == 'S') {
        //Diagonale giù-sinistra per "M", diagonale su-destra per "S"
        if (x + 1 < rows && y - 1 >= 0 && matrix[x + 1][y - 1] == 'M' && x - 1 >= 0 && y + 1 < cols && matrix[x - 1][y + 1] == 'S') {
            return 1;
        }
        //Diagonale su-destra per "M", diagonale giù-sinistra per "S"
        else if (x - 1 >= 0 && y + 1 < cols && matrix[x - 1][y + 1] == 'M' && x + 1 < rows && y - 1 >= 0 && matrix[x + 1][y - 1] == 'S') {
            return 1;
        }
    }

    // 2. Diagonale su-destra per "M", diagonale giù-sinistra per "S"
    if (x - 1 >= 0 && y + 1 < cols && matrix[x - 1][y + 1] == 'M' && x + 1 < rows && y - 1 >= 0 && matrix[x + 1][y - 1] == 'S') {
        //Diagonale su-sinistra per "M", diagonale giù-destra per "S"
        if (x - 1 >= 0 && y - 1 >= 0 && matrix[x - 1][y - 1] == 'M' && x + 1 < rows && y + 1 < cols && matrix[x + 1][y + 1] == 'S') {
            return 1;
        }
        // 4. Diagonale giù-destra per "M", diagonale su-sinistra per "S"
        else if (x + 1 < rows && y + 1 < cols && matrix[x + 1][y + 1] == 'M' && x - 1 >= 0 && y - 1 >= 0 && matrix[x - 1][y - 1] == 'S') {
            return 1;
        }
    }

    // 3. Diagonale giù-sinistra per "M", diagonale su-destra per "S"
    if (x + 1 < rows && y - 1 >= 0 && matrix[x + 1][y - 1] == 'M' && x - 1 >= 0 && y + 1 < cols && matrix[x - 1][y + 1] == 'S') {
        //Diagonale giù-destra per "M", diagonale su-sinistra per "S"
        if (x + 1 < rows && y + 1 < cols && matrix[x + 1][y + 1] == 'M' && x - 1 >= 0 && y - 1 >= 0 && matrix[x - 1][y - 1] == 'S') {
            return 1;
        }
        //Diagonale su-sinistra per "M", diagonale giù-destra per "S"
        else if (x - 1 >= 0 && y - 1 >= 0 && matrix[x - 1][y - 1] == 'M' && x + 1 < rows && y + 1 < cols && matrix[x + 1][y + 1] == 'S') {
            return 1;
        }

    }

    // 4. Diagonale giù-destra per "M", diagonale su-sinistra per "S"
    if (x + 1 < rows && y + 1 < cols && matrix[x + 1][y + 1] == 'M' && x - 1 >= 0 && y - 1 >= 0 && matrix[x - 1][y - 1] == 'S') {
        //Diagonale su-destra per "M", diagonale giù-sinistra per "S"
        if (x + 1 < rows && y - 1 >= 0 && matrix[x + 1][y - 1] == 'M' && x - 1 >= 0 && y + 1 < cols && matrix[x - 1][y + 1] == 'S') {
            return 1;
        }
        //Diagonale giù-sinistra per "M", diagonale su-destra per "S"
        else if (x - 1 >= 0 && y + 1 < cols && matrix[x - 1][y + 1] == 'M' && x + 1 < rows && y - 1 >= 0 && matrix[x + 1][y - 1] == 'S') {
            return 1;
        }
    }

    return 0; 
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Errore nell'apertura del file");
        return 1;
    }

    char matrix[MAX_ROWS][MAX_COLS];
    int rows = 0, cols = 0;

    // Lettura del file nella matrice
    while (fgets(matrix[rows], MAX_COLS, file)) {
        cols = strlen(matrix[rows]);
        if (matrix[rows][cols - 1] == '\n') {
            matrix[rows][cols - 1] = '\0';
            cols--;
        }
        rows++;
    }
    fclose(file);

    int count = 0;

    
    for (int i = 1; i < rows - 1; i++) {  
        for (int j = 0; j < cols - 1; j++) {
            // Verifica se la cella corrente può essere la "A" centrale
            if (matrix[i][j] == 'A') {
                count += check_xmas(matrix, rows, cols, i, j);
            }
        }
    }
    
    printf("Il numero di X-MAS trovati è: %d\n", count);

    return 0;
}
