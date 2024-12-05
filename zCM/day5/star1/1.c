#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 10000

typedef struct {
    int data;
    int link;
} Regola;

int controllo(int *aggiornamento, int size, Regola *regole, int contatore_regole) {
    for (int i = 0; i < contatore_regole; i++) {
        int data_index = -1, link_index = -1;
        for (int j = 0; j < size; j++) {
            if (aggiornamento[j] == regole[i].data) data_index = j;
            if (aggiornamento[j] == regole[i].link) link_index = j;
        }
        
        if (data_index != -1 && link_index != -1 && data_index > link_index) {
            return 0; 
        }
    }
    return 1; 
}

int trova_numero(int *aggiornamento, int size) {
    return aggiornamento[size / 2];
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (!file) {
        printf("Errore nell'apertura del file.\n");
        return 1;
    }

    Regola regole[DIM];
    int contatore_regole = 0;
    int **aggiornamenti = NULL;
    int *aggiornamento_size = NULL;
    int conta_aggiornamento = 0;

    char line[256];
    int reading_rules = 1;

    while (fgets(line, sizeof(line), file)) {
        
        line[strcspn(line, "\n")] = '\0';

        if (strlen(line) == 0) {
            reading_rules = 0; 
            continue;
        }

        if (reading_rules) {
            int data, link;
            sscanf(line, "%d|%d", &data, &link);
            regole[contatore_regole].data = data;
            regole[contatore_regole].link = link;
            contatore_regole++;
        } else {
            aggiornamenti = realloc(aggiornamenti, (conta_aggiornamento + 1) * sizeof(int *));
            aggiornamento_size = realloc(aggiornamento_size, (conta_aggiornamento + 1) * sizeof(int));
            int *aggiornamento = NULL;
            int size = 0;
            char *token = strtok(line, ",");
            while (token) {
                aggiornamento = realloc(aggiornamento, (size + 1) * sizeof(int));
                aggiornamento[size++] = atoi(token);
                token = strtok(NULL, ",");
            }
            aggiornamenti[conta_aggiornamento] = aggiornamento;
            aggiornamento_size[conta_aggiornamento] = size;
            conta_aggiornamento++;
        }
    }
    
    fclose(file);

    int somma = 0;

    for (int i = 0; i < conta_aggiornamento; i++) {
        if (controllo(aggiornamenti[i], aggiornamento_size[i], regole, contatore_regole)) {
            somma += trova_numero(aggiornamenti[i], aggiornamento_size[i]);
        }
        free(aggiornamenti[i]); 
    }
    free(aggiornamenti); 
    free(aggiornamento_size); 

    printf("Somma dei numeri centrali degli aggiornamenti validi: %d\n", somma);
    return 0;
}
