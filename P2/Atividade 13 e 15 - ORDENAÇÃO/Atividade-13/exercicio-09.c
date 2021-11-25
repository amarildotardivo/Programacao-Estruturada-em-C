#include <stdio.h>

#define tam 10

void bubbleSort(int *vet);
void selectionSort(int *vet);
void insertionSort(int *vet);
void quickSort(int *vet, int ini, int fim);
void imprimir(int *vet);

int main(){
    int vet[tam] = {7, 5, 10, 2, 8, 9, 1, 4, 3, 6};
    int ini = 0, fim = tam - 1;

    printf("\nVetor antes da ordenacao:\n");
    imprimir(vet);

    printf("\nVetor depois da ordenacao(bubbleSort):\n");
    bubbleSort(vet);
    imprimir(vet);

    printf("\nVetor depois da ordenacao(selectionSort):\n");
    selectionSort(vet);
    imprimir(vet);

    printf("\nVetor depois da ordenacao(insertionSort):\n");
    insertionSort(vet);
    imprimir(vet);

    printf("\nVetor depois da ordenacao(quickSort):\n");
    quickSort(vet, ini, fim);
    imprimir(vet);

    return 0;
}

void bubbleSort(int *vet){
    int i, j, aux;
    
    //controla o fim do loop
    for(i = 0; i < tam; i++){
        //percorre todo o vetor para realizar a comparação com todos os indices
        for(j = 0; j < tam - 1; j++){
            //realiza a comparação do indice atual com o próximo
            //se o atual for maior que o próximo, troca de indice no vetor
            if(vet[j] > vet[j + 1]){
                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
            }
        }
        //termina o loop e verifica todo o vetor novamente, para ordenar todas as posições corretamente
    }
}

void selectionSort(int *vet){
    int i, j, min, aux;

    //controla o fim do loop
    for(i = 0; i < tam - 1; i++){
        //recebe o primeiro valor do vetor para comparação
        min = i;
        //realiza o loop no proximo indice, para poder comparar o proximo com o min que é o atual do for i
        for(j = i + 1; j < tam; j++){
            //se o min for maior que o proximo, min = a posição para realizar a troca
            if(vet[j] < vet[min]){
                min = j;
            }
        }
        //só realizará a troca se o min não for a mesma posição da iteração principal
        if (i != min) {
            aux = vet[i];
            vet[i] = vet[min];
            vet[min] = aux;
        }
    }
}

void insertionSort(int *vet){
    int i, j, valor;

    //controla o fim do loop
    for(i = 1; i < tam; i++){
        //valor recebe o valor da posição atual da iteração principal para comparação
        valor = vet[i];
        //a iteração interna vai rodar apenas 
        //no intevalode 0 até valor ser menor do que o valor no indice da pasição da iteração
        for(j = i - 1; (j >= 0) && (valor < vet[j]); j-- ){
            //durante a iteração o indice posterior recebe inndice atual
            //enquanto o valor for menor que o indice atual e o indice for maior ou igual a 0
            vet[j+1] = vet[j];
        }
        //e finalmente, após a iteção interna o valor é atribuido a próxima posição, 
        //após o termino da iteração interna
        vet[j + 1] = valor;
    }

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