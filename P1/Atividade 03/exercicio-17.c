/*
17) Na teoria dos sistemas, define-se como elemento minimax de uma matriz o menor
elemento de uma linha onde se encontra o maior elemento da matriz. Faça um algoritmo
para gerar uma matriz quadrada 10 x 10 com números aleatórios de 1 até 50 e imprimir
o seu elemento minimax. Crie e utilize um procedimento para a geração da matriz e
uma função para retornar o elemento minimax. A impressão desse elemento tem que ser
na função main.
*/

#include <stdio.h>
#include <time.h>

#define tam 10

void preencheM(int matriz[][tam]);
int minimax(int matriz[][tam]);

int main(){
    int matriz[tam][tam], resultado;

    preencheM(matriz);
    resultado = minimax(matriz);

    printf("O Minimax eh: %d", resultado);

    return 0;
}

void preencheM(int matriz[][tam]){
    int i, j;

    srand(time(NULL));
    for(i = 0; i < tam; i++){
        for(j= 0; j < tam; j++){
            matriz[i][j] = rand() % 50 + 1;
        }
    }
}

int minimax(int matriz[][tam]){
    int i, j, max = 0, indiceMax, min;

    for(i = 0; i < tam; i++){
        for(j= 0; j < tam; j++){
            if(matriz[i][j] > max){
                max = matriz[i][j];
                indiceMax = i;
            }
        }
    }
    printf("\n\n    Max: %d, na linha %d\n\n", max, indiceMax);

    for(j = 0; j < tam; j++){
        if(j == 0){
            min = matriz[indiceMax][j];

        }else if(matriz[indiceMax][j] < min){
            min = matriz[indiceMax][j];
        }
    }

    return min;
}