/*
21) Faça um algoritmo que preencha o vetor A com 20 números inteiros gerados aleatoriamente de 0 até 10.
Em seguida, preencha o vetor B onde cada elemento Bi receba o fatorial do elemento Ai
, com 0 ≤ i ≤ 19. Crie
e utilize dois procedimentos: um para preencher o vetor A e outro para preencher o vetor B. Crie e utilize
também uma função para calcular o fatorial de um número.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tam 20

void preencheVetA(int *vetA);
int fatorial(int fatorial);
void preencheVetB(int *vetA, int *vetB);

int main(){
    int vetA[tam], vetB[tam];

    srand(time(NULL));

    preencheVetA(vetA);
    preencheVetB(vetA, vetB);

    return 0;
}

void preencheVetA(int *vetA){
    int i;

    printf("Vetor A: ");
    for(i = 0; i < tam; i++){
        vetA[i] = rand() % 10;
        printf("%d ", vetA[i]);
    }
}
int fatorial(int fat){
    int resultadoFatorial = fat;

    if((fat == 0) || (fat == 1)){
        return 1;
    }else{

        resultadoFatorial = fat * fatorial(fat - 1);
    }

    return resultadoFatorial;
}

int fat(int num){
    int i, fatorial = 1;

    for(i = 2; i <= num; i++){
        fatorial *= i;
    }

    return fatorial;
}

void preencheVetB(int *vetA, int *vetB){
    int i;
    printf("\nVetor B: ");
    for(i = 0; i < tam; i++){
        vetB[i] = fatorial(vetA[i]);
        printf("%d ", vetB[i]);
    }
}