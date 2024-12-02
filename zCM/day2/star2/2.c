#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void safe2(int array1[1000][1000], int col_conta[1000], int x, int i, int *punteggio) {
    int original_array[1000]; 
    int temp;
    
    for (int z = 0; z < col_conta[x]; z++) {
        original_array[z] = array1[x][z];
    }

    for (int z = 0; z < col_conta[x]; z++) {
        temp = array1[x][z];
        for (int k = z; k < col_conta[x] - 1; k++) {
            array1[x][k] = array1[x][k + 1];
        }
        col_conta[x]--; 

        int controlla = 0;
        int maggiore = 0;
        int minore = 0;
        int y = 0;
        while (y < col_conta[x] - 1 && controlla == 0) { 
            if (array1[x][y] == array1[x][y + 1]) {
                controlla = 1;
            } else if (array1[x][y] > array1[x][y + 1]) {
                if (minore == 1 || abs(array1[x][y] - array1[x][y + 1]) > 3) {
                    controlla = 1;
                }
                maggiore = 1;
            } else if (array1[x][y] < array1[x][y + 1]) {
                if (maggiore == 1 || abs(array1[x][y] - array1[x][y + 1]) > 3) {
                    controlla = 1;
                }
                minore = 1;
            }
            y++;
        }

        if (controlla == 0) {
            *punteggio += 1;
            return;
        }

        for (int k = col_conta[x]; k > z; k--) {
            array1[x][k] = array1[x][k - 1];
        }
        array1[x][z] = temp;
        col_conta[x]++;
    }
}

void safe(int array1[1000][1000], int col_conta[1000], int i, int *punteggio) {
    for (int x = 0; x < i; x++) {
        int y = 0;
        int controlla = 0;
        int maggiore = 0;
        int minore = 0;
        while (y < col_conta[x] - 1 && controlla == 0) { 
            if (array1[x][y] == array1[x][y + 1]) {
                controlla = 1;
            } else if (array1[x][y] > array1[x][y + 1]) {
                if (minore == 1 || abs(array1[x][y] - array1[x][y + 1]) > 3) {
                    controlla = 1;
                }
                maggiore = 1;
            } else if (array1[x][y] < array1[x][y + 1]) {
                if (maggiore == 1 || abs(array1[x][y] - array1[x][y + 1]) > 3) {
                    controlla = 1;
                }
                minore = 1;
            }
            y++;
        }
        if (controlla == 0) {
            *punteggio += 1;
        } else {
            safe2(array1, col_conta, x, i, punteggio);
        }
    }
}


int main() {
    FILE *file;
    int array1[1000][1000];
    int i = 0;
    int col_conta[1000];

    file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[10000];
    while (i < 1000 && fgets(line, sizeof(line), file)) {
        int j = 0;
        char *token = strtok(line, " ");
        while (token != NULL && j < 1000) {
            array1[i][j] = atoi(token);
            token = strtok(NULL, " ");
            j++;
        }
        col_conta[i] = j;
        i++;
    }

    if (ferror(file)) {
        perror("Error reading file");
        fclose(file);
        return 1;
    }

    int punteggio = 0;
    safe(array1, col_conta, i, &punteggio);

    printf("%d\n", punteggio);
    fclose(file);
    return 0;
}



