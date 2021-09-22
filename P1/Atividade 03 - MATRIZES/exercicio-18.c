/*
18) Faça um algoritmo que leia uma matriz 3 x 3 de números inteiros. Depois, calcule e
armazene na posição i de um vetor de tamanho 3 a soma dos valores da coluna i da
matriz (0 ≤ i ≤ 2), imprimindo em seguida o vetor. Crie e utilize dois procedimentos:
um para ler a matriz e outro para preencher e imprimir o vetor. O vetor também deve ser
declarado na função main
*/
#include <stdio.h>

#define tam 3

void lerM(int matriz[][tam]);
void imprimiVetor(int matriz[][tam], int *vetor);

int main(){
    int matriz[tam][tam], vetor[tam];

    lerM(matriz);
    imprimiVetor(matriz, vetor);

    return 0;
}

void lerM(int matriz[][tam]){
    int i, j;

    printf("Entre com %d numeros:\n", tam * tam);
    for(i = 0; i < tam; i++){
        for(j = 0; j < tam; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
}
void imprimiVetor(int matriz[][tam], int *vetor){
    int i, j;

    for(j = 0; j < tam; j++){
        vetor[j] = 0;
        for(i = 0; i < tam; i++){
            vetor[j] += matriz[i][j];
        }
    }

    printf("Vetor com as somas: ");
    for(i = 0; i < tam; i++){
        printf("%d ", vetor[i]);
    }
}