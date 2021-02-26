#include <stdio.h>
#include <stdlib.h>

#define tam 4

void preencheVet(int vet[tam]){
    for(int i = 0; i < tam; i++){
        printf("Entre com o %d numero: ", i + 1);
        scanf("%d", &vet[i]);
    } 
}

int verificaPA(int vet[tam]){
    int diferenca = 0, difAtual = 0;

    diferenca = vet[0] - vet[1];

    for(int i = 1; i < tam - 1; i++){
        difAtual = vet[i] - vet[i + 1];
        
        if(diferenca != difAtual){
            return 0;
        }
    }
    return 1;
}

int main(){
    int vetor[tam];

    preencheVet(vetor);
    int result = verificaPA(vetor);

    if(result == 1){
        printf("Vetor e uma PA!");
    }else{
        printf("VETOR NAO E UMA PA!!!");
    }

    return 0;
}