#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int punteggio=0;
    
    for (int x = 0; x < i; x++) {
        int y = 0;
        int controlla = 0;
        int maggiore = 0;
        int minore = 0;
        while (y < col_conta[x]-1 && controlla == 0) { 
            if (array1[x][y] == array1[x][y+1]) {
            controlla = 1;
            }
            else if (array1[x][y] > array1[x][y+1]) {
                if (minore == 1 || abs(array1[x][y] - array1[x][y+1]) > 3) {
                    controlla = 1;
                }
                maggiore = 1;
            }
            else if (array1[x][y] < array1[x][y+1]) {
                if (maggiore == 1 || abs(array1[x][y] - array1[x][y+1]) > 3) {
                    controlla = 1;
                }
                minore = 1;
            }
            y++;
        }
        if (controlla == 0) {
            punteggio++;
        }
    }
    printf("%d\n", punteggio);
    fclose(file);
    return 0;
}
