#include <stdio.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define WORD "XMAS"

int check_word(char matrix[MAX_ROWS][MAX_COLS], int rows, int cols, int x, int y, int dx, int dy) {
    int len = strlen(WORD);
    for (int k = 0; k < len; k++) {
        //posizione
        int nx = x + k * dx;
        int ny = y + k * dy;
        if (nx < 0 || nx >= rows || ny < 0 || ny >= cols) {
            return 0;
        }
        if (matrix[nx][ny] != WORD[k]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Errore nell'apertura del file");
        return 1;
    }

    char matrix[MAX_ROWS][MAX_COLS];
    int rows = 0, cols = 0;

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

    int directions[8][2] = {
        {0, 1},   // Destra
        {0, -1},  // Sinistra
        {1, 0},   // Giù
        {-1, 0},  // Su
        {1, 1},   // Diagonale giù-destra
        {-1, -1}, // Diagonale su-sinistra
        {1, -1},  // Diagonale giù-sinistra
        {-1, 1}   // Diagonale su-destra
    };

    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            for (int d = 0; d < 8; d++) {
                //controlliamo tutte le direzioni
                int dx = directions[d][0];
                int dy = directions[d][1];
                if (check_word(matrix, rows, cols, i, j, dx, dy)) {
                    count++;
                }
            }
        }
    }

    printf("La parola '%s' è presente %d volte nel file.\n", WORD, count);

    return 0;
}