#include <stdio.h>
#include <time.h>

#define tam 2

int soma(int *vet, int i);

int main(){
    int vet[tam], resultado, i = tam - 1, k;

    srand(time(NULL));

    for(k = 0; k < tam; k++){
        vet[k] = rand() % 50 + 1;
    }
    
    resultado = soma(vet, i);

    printf("\n  Soma e: %d\n\n", resultado);
    
    return 0;
}

int soma(int *vet, int i){

    if(i == 0){
        return vet[i];
    }else{
        return vet[i] + soma(vet, i - 1);
    }

}