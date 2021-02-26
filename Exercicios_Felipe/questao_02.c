#include <stdio.h>
#include <stdlib.h>

#define tam 4

void preencheVet(int vet[tam]){
    for(int i = 0; i < tam; i++){
        printf("Entre com o %d numero: ", i + 1);
        scanf("%d", &vet[i]);
    } 
}

void inverteVet(int vet[tam]){
    int aux, j;

    for(int i = 0; i < tam; i++){
        for(j = tam - 1; j > 0; j--){
            if(i < j){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
                
                i++;
            }
        }
    }
}

void imprimiVet(int vet[tam]){
    for(int i = 0; i < tam; i++){
        printf("%d: %d", i + 1, vet[i]);
        printf("\n");
    }
}

int main(){
    int vetor[tam];

    preencheVet(vetor);
    inverteVet(vetor);
    imprimiVet(vetor);

    return 0;
}