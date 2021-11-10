#include <stdio.h>

#define tam 20

int maiorValor(int *vet, int i, int maior);

int main(){
    int vet[tam], resultado, i = tam - 1, maior, k;
    
    srand(time(NULL));

    for(k = 0; k < tam; k++){
        vet[k] = rand() % 40 + 1;
        printf("\n      %d\n", vet[k]);
    }

    maior = vet[tam - 1];
    
    resultado = maiorValor(vet, i, maior);

    printf("\n  Maior valor e: %d\n\n", resultado);

    return 0;
}

int maiorValor(int *vet, int i, int maior){
    
    if(i < 0){
        return maior;
    }else{
        if(maior <= vet[i]){
            maior = vet[i];
            return maiorValor(vet, i - 1, maior);
        }
    }
    return maiorValor(vet, i - 1, maior);
}