#include <stdio.h>

#define tam 4

void geraTransp(FILE *arqEntrada, int matriz[tam][tam], int matrizT[tam][tam]);

int main(){
    FILE *arqEntrada, *arqSaida;
    int matriz[tam][tam], i, j, matrizT[tam][tam];

    arqEntrada = fopen("Matriz4x4.txt", "r");
    arqSaida = fopen("Transposta.txt", "w");

    geraTransp(arqEntrada, matriz, matrizT);

    for( i = 0; i < tam; i++ ){
        for( j = 0; j < tam; j++ ){
            fprintf(arqSaida, "%d ", matrizT[i][j]);
        }
        fprintf(arqSaida, "\n");
    }
    
    fclose(arqEntrada);
    fclose(arqSaida);

    return 0;
}

void geraTransp(FILE *arqEntrada, int matriz[tam][tam], int matrizT[tam][tam]){
    int i, j;
    for( i = 0; i < tam; i++ ){
        for( j = 0; j < tam; j++ ){
            fscanf(arqEntrada, "%d ", &matriz[i][j]);
            matrizT[j][i] = matriz[i][j];
        }
    }
}