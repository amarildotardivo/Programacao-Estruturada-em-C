/*
6) Faça um algoritmo para preencher um vetor (de tamanho 10) com elementos gerados aleatoriamente de 1 a
20, de maneira que não sejam inseridos números iguais no vetor, ou seja, todos os números contidos no vetor
têm que ser distintos. Crie e utilize dois procedimentos: um para preencher o vetor e outro para imprimi-lo.
*/
#include <stdio.h>
#include<time.h>

#define TAM 10

void aleatorios(int *vetor);
void imprimiVetor(int *vetor);

int main(){
    int vetor[TAM];

    srand(time(NULL));

    aleatorios(vetor);
    imprimiVetor(vetor);

    return 0;
}

void aleatorios(int *vetor){
    int i = 0, j, verifica = 0;

    do{
        vetor[i] = rand() % 20 + 1;
        verifica = 0;
        for(j = 0; j < i; j++){
            if(vetor[j] == vetor[i]){
                verifica = 1;
            }
        }

        if(verifica == 0){
            i++;
        }
    }while (i < TAM);
    
}
void imprimiVetor(int *vetor){
    int i;
	
    printf("Vetor de Numeros aleatorios nao repetidos:\n\n    ");
	for(i = 0; i < TAM; i++){
		printf("%d ", vetor[i]);
	}
    printf("\n\n");
}