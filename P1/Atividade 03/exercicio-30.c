#include <stdio.h>
#include <time.h>
#include <math.h>

#define n 4
#define m 5

void preencheMatriz(int matriz[][m]);
int verificaMatriz(int matrizA[][m], int matrizB[][n]);

int main(){
    int matrizA[n][m], matrizB[m][n], resultado;

    preencheMatriz(matrizA);
    preencheMatriz(matrizB);

    resultado = verificaMatriz(matrizA, matrizB);

    if(resultado == 1){
        printf("Condicao Satisfeita!!!\n");
    }else{
        printf("Condicao NAO Satisfeita!!!\n");
    }
    
    return 0;
}

void preencheMatriz(int matriz[][m]){
    int i, j;

    srand(time(NULL));

    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++){
            matriz[i][j] = rand() % 30 + 1;
        }
}

int verificaMatriz(int matrizA[][m], int matrizB[][n]){
    int i, j, soma, multi, min, max;

    for(j = 0; j <= m - 1; j++){
        soma = 0;
        for(i = 0; i < n - 1; i++){
            soma += abs(matrizA[i][j]);
        }

        if(j == 0){
            min = soma;
        }else if(soma < min){
            min = soma;
        }
    }

    for(i = 0; i <= n - 1; i++){
        multi = 1;
        for(j = 0; j <= m - 1; j++){
            multi *= matrizB[i][j];
        }

        if(i == 0){
            max = multi;
        }else if(multi < max){
            max = multi;
        }
    }

    if(min <= max){
        return 1;

    }else{
        return 0;
    }
    
}