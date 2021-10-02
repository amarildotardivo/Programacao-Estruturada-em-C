#include <stdio.h>

#define lin 5
#define col 6

void lerMatriz(FILE *arqEntrada, int matriz[][col]);
int calcSoma(int matriz[][col]);
void imprimirResult(int soma, FILE *arqSaida);

int main(){
    FILE *arqEntrada, *arqSaida;
    int matriz[lin][col], soma;

    arqEntrada = fopen("Matriz5x6.txt", "r");
    arqSaida = fopen("Soma.txt", "w");

    if(arqEntrada == NULL){
        printf("\nErro ao abrir o arquivo!\n\n");
        return 1;
    }
    
    lerMatriz(arqEntrada, matriz);
    soma = calcSoma(matriz);
    imprimirResult(soma, arqSaida);

    fclose(arqEntrada);
    fclose(arqSaida);

    return 0;
}

void lerMatriz(FILE *arqEntrada, int matriz[][col]){
    int i, j;

    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            fscanf(arqEntrada, "%d", &matriz[i][j]);
        }
    }
}

int calcSoma(int matriz[][col]){
    int i, j, soma = 0;

    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            if(j == 1 || j == 3 || j == 5){
                soma += matriz[i][j];
            }
        }
    }

    return soma;
}

void imprimirResult(int soma, FILE *arqSaida){
    fprintf(arqSaida, "Soma: %d", soma);   
}

