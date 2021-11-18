//5) INSERTIONSORT
#include <stdio.h>

#define tam 15

void preenche(int *vet);
void ordena(int *vet);
void imprimi(int *vet);

int main(){
    int vet[tam];
    
    preenche(vet);
    printf("\nVetor nao ordenado:\n");
    imprimi(vet);

    ordena(vet);
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
void ordena(int *vet){
    int i, j, valor;

    for(i = 1; i < tam; i++){
        valor = vet[i];
        for(j = i - 1; (j >= 0) && (valor < vet[j]); j-- ){
            vet[j+1] = vet[j];
        }
        vet[j + 1] = valor;
    }

}
void imprimi(int *vet){
    int i;

    for(i = 0; i < tam; i++){
       printf("%d ", vet[i]);
    }
    printf("\n\n");
}