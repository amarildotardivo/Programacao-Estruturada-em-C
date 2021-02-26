#include <stdio.h>
#include <stdlib.h>

#define tam 4

void preencherVetor(float vet[tam]){

    for(int i = 0; i < tam; i++){
        printf("Entre com o %d numero: ", i + 1);
        scanf("%f", &vet[i]);
    }
}

int verificaNumero(float num, float vet[tam]){
    for(int i = 0; i < tam; i++){
        if(num == vet[i]){
            return 1;
        }
    }
    return 0;
}

int main(){
    float vetor[tam], num;

    preencherVetor(vetor);

    printf("Digite um numero: ");
    scanf("%f", &num);

    
    if(verificaNumero(num, vetor) == 1){
        printf("O numero digitado existe no vetor!");
    }else{
        printf("O numero digitado NAO existe no vetor!");
    }

    return 0;
}