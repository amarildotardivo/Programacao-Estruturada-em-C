/*
19) Considere uma matriz quadrada de ordem 6 gerada aleatoriamente com números de
1 até 30. Faça um algoritmo que calcule e imprima a soma dos elementos dessa matriz
que não pertençam à diagonal principal nem à diagonal secundária. Crie e utilize um
procedimento para a geração da matriz e uma função para retornar a soma. A
impressão da soma tem que ser na função main.
*/
#include <stdio.h>
#include <time.h>

#define tam 6

void preencheM(int matriz[][tam]);
int somaM(int matriz[][tam]);

int main(){
    int matriz[tam][tam], resultado;

    preencheM(matriz);
    resultado = somaM(matriz);

    printf("Soma: %d\n", resultado);

    return 0;
}

void preencheM(int matriz[][tam]){
    int i, j;

    srand(time(NULL));

    for(i = 0; i < tam; i++){
        for(j = 0; j < tam; j++){
            matriz[i][j] = rand() % 30 + 1;
        }
    }
}
int somaM(int matriz[][tam]){
    int i, j, soma = 0;

    for(i = 0; i < tam; i++){
        for(j = 0; j < tam; j++){
            if(i != j){
                if( i + j != tam - 1 ){
                    soma += matriz[i][j];
                }
            } 
        }
    }
    return soma;
}