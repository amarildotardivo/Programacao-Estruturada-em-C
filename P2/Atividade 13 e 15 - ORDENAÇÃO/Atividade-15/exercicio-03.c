#include <stdio.h>

#define tam 10

void quickSort(int *vet, int ini, int fim);
void imprimir(int *vet);

int main(){
    int vet[tam] = {7, 5, 10, 2, 8, 9, 1, 4, 3, 6};
    int ini = 0, fim = tam - 1;

    printf("\nVetor antes da ordenacao:\n");
    imprimir(vet);

    printf("\nVetor depois da ordenacao(quickSort):\n");
    quickSort(vet, ini, fim);
    imprimir(vet);

    return 0;
}

void quickSort(int *vet, int ini, int fim){
    int pivo;                  

    //enquanto o inicio for manor do que o fim é permitido entrar no if para fazer as chamadas recursivas
    if (ini < fim) {                  
        //chama o particiona que vai dividir o vetor no meio
        pivo = particiona(vet, ini, fim); 
        //chama o quick sort novamente, ms apenas com os indices mais a esquerda
        quickSort(vet, ini, pivo - 1);
        //chama o quick sort novamente, ms apenas com os indices mais a direita
        quickSort(vet, pivo + 1, fim);       

    }

}

int particiona(int *vet, int ini, int fim){

    int pivo = vet[ini];
    int i = ini, j, aux;

    //realiza a iteração com os indices definidos na passgem de paratro pelo quicksort
	for(j = ini + 1; j <= fim; j++){
        //se o pivo for maior ou igual ao indice ele troca a posição do primeiro indice com o proximo
        if(vet[j] <= pivo){
            i++;

            aux = vet[i]; 
            vet[i] = vet[j]; 
            vet[j] = aux; 
        }
    }
    //ao terminar a iteração a primeira posição troca com a ultima
    aux = vet[i]; 
    vet[i] = vet[ini]; 
    vet[ini] = aux;

	return i;
}

void imprimir(int *vet){
    int i;

    for(i = 0; i < tam; i++){
       printf("%d ", vet[i]);
    }
    printf("\n\n");
}