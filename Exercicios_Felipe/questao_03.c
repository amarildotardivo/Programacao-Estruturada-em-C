#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tam 40
#define range 100

void gerarVetRandom(int vet[tam]){
    printf("------ Vetor Gerado -------\n\n");

    for(int i = 0; i < tam; i++){
        vet[i] = rand() % range + 1;
        printf(" %d: %d \n", i + 1, vet[i]);
    }

    printf("\n\n----- Fim do Vetor Gerado -----\n\n");
}

void verificaValor(int vet[tam]){
    int numero, cont = 0;

    printf("Entre com o numero: ");
    scanf("%d", &numero);

    for(int i = 0; i < tam; i++){
        if( numero == vet[i]){
            cont++;
            printf("Posicao: %d\n", i + 1);
        }
    }

    printf("O numero apareceu %d vezes!", cont);
}
int main(){
    int vetor[tam];

    srand(time(NULL));

    gerarVetRandom(vetor);
    verificaValor(vetor);

    return 0;
}