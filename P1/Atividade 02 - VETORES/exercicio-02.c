#include <stdio.h>

#define tam 15

void preencheVet(int *vetor);
void inverteVet(int *vetor);
void imprimeVetor(int *vetor);

int main(){
    int vetor[tam];

    preencheVet(vetor);
    inverteVet(vetor);
    imprimeVetor(vetor);

    return 0;
}

void preencheVet(int *vetor){
    int i;

    printf("Entre com %d elementos no vetor:\n", tam);
    for(i = 0; i < tam; i++){
        scanf("%d", &vetor[i]);
    }
}

void inverteVet(int *vetor){
    int i, aux, j = tam - 1;

    for(i = 0; i < tam/2; i++){
        aux = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = aux;

        j--;
    }
}

void imprimeVetor(int *vetor){
    int i;

    printf("\nVetor: ");
    for(i = 0; i < tam; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n\n");
}