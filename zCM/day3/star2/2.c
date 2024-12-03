#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void moltiplicazione(char array[], int n) {
    int moltiplicazione = 0;
    int i = 0;
    int conferma = 0; 

    while (i < n) {
        int num1 = 1;
        int num2 = 0;

        
        if (i + 7 < n && array[i] == 'd' && array[i + 1] == 'o' && array[i + 2] == 'n' && array[i + 4] == 't' && array[i + 5] == '(' && array[i + 6] == ')') {
            conferma = 1; 
            i += 7;   
        }

        if (i + 3 < n && array[i] == 'd' && array[i + 1] == 'o' && array[i + 2] == '(' && array[i + 3] == ')') {
            conferma = 0;
            i += 4;  
        }

        if (array[i] == 'm' && i + 1 < n && conferma==0) {
            i++;
            if (array[i] == 'u' && i + 1 < n) {
                i++;
                if (array[i] == 'l' && i + 1 < n) {
                    i++;
                    if (array[i] == '(' && i + 1 < n) {
                        i++;
                        if (array[i] >= '0' && array[i] <= '9' && i + 1 < n) {
                            num1 = (array[i] - '0');
                            i++;
                            if (array[i] >= '0' && array[i] <= '9' && i + 1 < n) {
                                int x = (array[i] - '0');
                                num1 = num1 * 10 + x;
                                i++;
                                if (array[i] >= '0' && array[i] <= '9' && i + 1 < n) {
                                    num1 = num1 * 10 + (array[i] - '0');
                                    i++;
                                }
                            }

                            if (array[i] == ',' && i + 1 < n) {
                                i++;
                                if (array[i] >= '0' && array[i] <= '9' && i + 1 <=n) {
                                    num2 = (array[i] - '0');
                                    i++;
                                    if (array[i] >= '0' && array[i] <= '9' && i + 1 <=n) {
                                        num2 = num2 * 10 + (array[i] - '0');
                                        i++;
                                        if (array[i] >= '0' && array[i] <= '9' && i + 1 <=n) {
                                            num2 = num2 * 10 + (array[i] - '0');
                                            i++;
                                            if (array[i] == ')') {
                                                moltiplicazione = moltiplicazione + num1 * num2;
                                            }
                                        }
                                        else if (array[i] == ')') {
                                            moltiplicazione = moltiplicazione + num1 * num2;
                                        }
                                    }
                                    else if (array[i] == ')') {
                                        moltiplicazione = moltiplicazione + num1 * num2;
                                    }
                                }
                                else if (array[i] == ')') {
                                    moltiplicazione = moltiplicazione + num1 * num2;
                                }
                            }
                        }
                    }
                }
            }
        }
        i++;
    }

    printf("La moltiplicazione è: %d\n", moltiplicazione);
}

int main() {
    FILE *file;
    char array[999999];
    int i = 0;
    file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    while (fscanf(file, "%c", &array[i]) != EOF && i < sizeof(array) - 1) {
        i++;
    }
    moltiplicazione(array, i);
    fclose(file);
}
