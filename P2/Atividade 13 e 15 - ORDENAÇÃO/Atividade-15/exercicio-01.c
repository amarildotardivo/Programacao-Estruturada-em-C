#include <stdio.h>

#define tam 15

void preenche(int *vet);
void quickSort(int *vet, int inicio, int fim);
void imprimi(int *vet);

int main(){
    int vet[tam], inicio = 0, fim = tam - 1;
    
    preenche(vet);
    printf("\nVetor nao ordenado:\n");
    imprimi(vet);

    quickSort(vet, inicio, fim);
    printf("\nVetor ordenado:\n");
    imprimi(vet);

    return 0;
}

void preenche(int *vet){
    int i;

    for(i = 0; i < tam; i++){
        printf("\nInsira o numero %d: ", i + 1);
        scanf("%d", &vet[i]);
    }

}

void quickSort(int *vet, int ini, int fim){
    int pivo;                  

    if (ini < fim) {                  
        pivo = particiona(vet, ini, fim); 
        quickSort(vet, ini, pivo - 1);      
        quickSort(vet, pivo + 1, fim);       
    }

}

int particiona(int *vet, int ini, int fim){
    int pivo = vet[ini];
    int i = ini, j, aux;

    for(j = ini + 1; j <= fim; j++){
        if(vet[j] <= pivo){
            i++;

            aux = vet[i]; 
            vet[i] = vet[j]; 
            vet[j] = aux; 
        }
    }

    aux = vet[i]; 
    vet[i] = vet[ini]; 
    vet[ini] = aux;

    return i;
}

void imprimi(int *vet){
    int i;

    for(i = 0; i < tam; i++){
       printf("%d ", vet[i]);
    }
    printf("\n\n");
}