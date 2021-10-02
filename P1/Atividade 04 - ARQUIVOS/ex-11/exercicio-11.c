#include <stdio.h>

#define lin 4
#define col 5

void lerMatriz(FILE *arqEntrada, int matriz[lin][col]);
void trocaColunas(int matriz[lin][col]);
void imprimirMatrizAlt(int matriz[lin][col], FILE *arqSaida);

int main(){
    FILE *arqEntrada, *arqSaida;
    int matriz[lin][col];
    
    arqEntrada = fopen("Matriz4x5.txt", "r");
    arqSaida = fopen("MatrizAlterada.txt","w");
    
    if(arqEntrada == NULL){
        printf("\nErro ao abrir o arquivo!\n\n");
        return 1;
    }

    lerMatriz(arqEntrada, matriz);
    trocaColunas(matriz);
    imprimirMatrizAlt(matriz, arqSaida);

    fclose(arqEntrada);
    fclose(arqSaida);

    return 0;
}

void lerMatriz(FILE *arqEntrada, int matriz[lin][col]){
    int i, j;

    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            fscanf(arqEntrada, "%d", &matriz[i][j]);
        }
    }
}
void trocaColunas(int matriz[lin][col]){
    int i, j, aux;

    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            if(j == 1){
                aux = matriz[i][j];
                matriz[i][j] = matriz[i][4];
                matriz[i][4] = aux;
            }
        }
    }
}
void imprimirMatrizAlt(int matriz[lin][col], FILE *arqSaida){
    int i, j;
    
    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            fprintf(arqSaida, "%d ", matriz[i][j]);
        }
        fprintf(arqSaida, "\n");
    }
}

