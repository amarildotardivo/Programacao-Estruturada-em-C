#include <stdio.h>
#include <stdlib.h>

#define tam 4

void preencheVet(int vet[tam]){
    for(int i = 0; i < tam; i++){
        printf("Entre com o %d numero: ", i + 1);
        scanf("%d", &vet[i]);
    } 
}

int verificaVet(int vet[tam]){
    for(int i = 0; i < tam; i++){
        if(vet[i] > vet[i + 1]){
            return 0;
        }
    }
    return 1;
}

int main(){
    int vetor[tam];

    preencheVet(vetor);
    int result = verificaVet(vetor);

    if(result == 1){
        printf("Vetor Correto!");
    }else{
        printf("Vetor INCORRETO!");
    }

    return 0;

}