#include <stdio.h>

int main(){
    FILE *file;
    int array1[1000], array2[1000];
    int i = 0;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    while (fscanf(file, "%d %d", &array1[i], &array2[i]) != EOF) {
        i++;
    }
    int risultato = 0;
    for (int j = 0; j < i; j++) {
        int temp = array1[j];
        int conta = 0;
        for (int k = 0; k<i; k++) {
            if (array1[j] == array2[k]) { 
                conta++;
            }
        }
        risultato = risultato + (temp*conta);
    }
    printf("%d\n", risultato);

    fclose(file);
}