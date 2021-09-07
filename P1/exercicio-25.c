/*
25) Considere um vetor com 100 números lidos pelo teclado. Faça um algoritmo que imprima todos os números
que aparecem somente uma vez no vetor. Crie e utilize dois procedimentos: uma para preencher o vetor e
outro para imprimir o que se pede. Exemplo com um vetor de 10 números:
Vetor: {3, 1, 9, 8, 3, 10, 1, 5, 9, 1}
Números que aparecem somente uma vez: 8, 10, 5
Obs.: Não é permitido utilizar qualquer estrutura de dados auxiliar.
*/
#include <stdio.h>

#define tam 5

void preencheVetor(int *vetor);
void imprimiNumNaoRepetidos(int *vetor);

int main(){
    int vetor[tam];

    preencheVetor(vetor);
    imprimiNumNaoRepetidos(vetor);

    return 0;
}

void preencheVetor(int *vetor){
    int i;
    
    printf("Entre com os %d numeros do vetor: \n", tam);
    for(i = 0; i < tam; i++){
        scanf("%d", &vetor[i]);
    }

}
void imprimiNumNaoRepetidos(int *vetor){
    int i, j, contador = 0;

    printf("Numeros nao repetidos:\n");
    for(i = 0; i < tam; i++){
        for(j = 0; j < tam - 1; j++){
            
            if(i != j && vetor[i] == vetor[j]){
                contador++;
            }
        }
        if(contador == 0){
            printf("%d ", vetor[i]);
        }else{
            contador = 0;
        }
    }
}