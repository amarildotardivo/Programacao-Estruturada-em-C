//3) SELECTIONSORT
#include <stdio.h>

#define tam 15

void preencher(int *vet);
void ondernar(int *vet);
void troca(int *vet);
void imprimir(int *vet);

int main(){
    int vet[tam];
    
    preencher(vet);
    printf("\nVetor antes da ordenacao:\n");
    imprimir(vet);

    printf("\nVetor depois da ordenacao:\n");
    ondernar(vet);
    imprimir(vet);

    return 0;
}

void preencher(int *vet){
    int i;

    for(i = 0; i < tam; i++){
        printf("\nInsira o numero %d: ", i + 1);
        scanf("%d", &vet[i]);
    }
}

void ondernar(int *vet){
    int i, j, min, aux;

    for(i = 0; i < tam - 1; i++){
        min = i;
        for(j = i + 1; j < tam; j++){
            if(vet[j] < vet[min]){
                min = j;
            }
        }
        if (i != min) {
            aux = vet[i];
            vet[i] = vet[min];
            vet[min] = aux;
        }
    }
}
void imprimir(int *vet){
    int i;

    for(i = 0; i < tam; i++){
       printf("%d ", vet[i]);
    }
    printf("\n\n");
}