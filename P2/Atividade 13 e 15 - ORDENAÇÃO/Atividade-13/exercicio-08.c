//8) QUICKSORT
#include <stdio.h>
#include <time.h>

#define tam 20

void preenche(int *vet);
void quickSort(int *vet, int ini, int fim);
void imprimi(int *vet);

int main(){
    int vet[tam], ini = 0, fim = tam - 1;
    
    srand(time(NULL));

    preenche(vet);
    printf("\nVetor antes da ordenacao:\n");
    imprimi(vet);

    printf("\nVetor depois da ordenacao:\n");
    quickSort(vet, ini, fim);
    imprimi(vet);

    return 0;
}

void preenche(int *vet){
    int i;

    for(i = 0; i < tam; i++){
        vet[i] = rand() % 30 + 1;
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