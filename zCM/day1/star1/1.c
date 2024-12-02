#include <stdio.h>

void quicksort(int array[], int m, int i){
    int j = m;
    int k = i;
    int pivot = array[(m+i)/2];
    while (j <= k) {
        while (array[j] < pivot) {
            j++;
        }
        while (array[k] > pivot) {
            k--;
        }
        if (j <= k) {
            int temp = array[j];
            array[j] = array[k];
            array[k] = temp;
            j++;
            k--;
        }
    }
    if (m < k) {
        quicksort(array, m, k);
    }
    if (j < i) {
        quicksort(array, j, i);
    }
}

void sottrazione(int array1[], int array2[], int i){
    int sottrazione, risultato;
    risultato=0;
    for(int j=0; j<i; j++){
        sottrazione = array1[j] - array2[j];
        if(sottrazione<0){
            sottrazione = sottrazione * -1;
        }
        risultato=risultato+sottrazione;
    }
    printf("Il risultato della sottrazione è: %d\n", risultato);
}

int main (){
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
    quicksort(array1, 0, i-1);
    quicksort(array2, 0, i-1);

    sottrazione(array1, array2, i);

    fclose(file);
}