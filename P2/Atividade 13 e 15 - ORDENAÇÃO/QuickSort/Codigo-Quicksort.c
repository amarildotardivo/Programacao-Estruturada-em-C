#include <stdio.h>

#define TAM 10

void quickSort(int *vet, int ini, int fim);
int particiona(int *vet, int ini, int fim);

int main(){

    int vetor[TAM] = {6, 2, 1, 10, 9, 4, 5, 7, 3, 8}, 
        i, inicio = 0, fim = TAM-1;

    printf("\n\nVetor ANTES da ordenacao:  ");
    for(i = 0; i < TAM; i++)
        printf(" %d", vetor[i]);  
    
    quickSort(vetor, inicio, fim);

    printf("\n\nVetor DEPOIS da ordenacao: ");
    for(i = 0; i < TAM; i++)
        printf(" %d", vetor[i]);


    printf("\n\n");

    return 0;
}


void quickSort(int *vet, int ini, int fim){

   int pivo;                  

   if (ini < fim) {                  

      pivo = particiona(vet, ini, fim); 
      quickSort(vet, ini, pivo-1);      
      quickSort(vet, pivo+1, fim);       

   }

}

int particiona(int *vet, int ini, int fim){

	int pivo = vet[ini], i = ini, j, aux;

	for(j = ini+1; j <= fim; j++){

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

