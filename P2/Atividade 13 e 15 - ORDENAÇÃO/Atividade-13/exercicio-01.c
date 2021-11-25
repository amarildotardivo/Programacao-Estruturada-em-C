//1) BUBLESORT

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
    int i, j, aux;

    for(i = 0; i < tam; i++){
        for(j = 0; j < tam - 1; j++){
            if(vet[j] > vet[j + 1]){
                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
            }
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