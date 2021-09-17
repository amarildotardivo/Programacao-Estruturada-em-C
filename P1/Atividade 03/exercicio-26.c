/*
26) Um grafo simples não-direcionado G é k-regular se todos os vértices têm grau k.
Faça um algoritmo para ler pelo teclado a matriz de adjacência A(G) de um grafo
simples não-direcionado G com 15 vértices e imprimir na tela se G é ou não um grafo
k-regular. Em caso verdadeiro, imprima também o valor de k. Crie e utilize dois
procedimentos: um para ler a matriz pelo teclado e outro para imprimir o que se pede.
*/
#include <stdio.h>

#define tam 15

void lerAG(int matrizAG[][tam]);
void imprimirAG(int matrizAG[][tam]);

int main(){
    int matrizAG[tam][tam];

    lerAG(matrizAG);
    imprimirAG(matrizAG);

    return 0;
}

void lerAG(int matrizAG[][tam]){
    int i, j;

    for(i = 0; i < tam; i++){
		for(j = 0; j < tam; j++){
			printf("digite o numero para a posicao [%d][%d] da Matriz A(G):", i, j);
			scanf("%d", &matrizAG[i][j]);
		}
	}
}

void imprimirAG(int matrizAG[][tam]){
    int i, j, aux =0, cont=0, soma;
	
	for(i = 0; i < tam; i++){
		soma = 0;
		for(j = 0; j < tam; j++){
			if(matrizAG[i][j] == 1){
				soma++;
			}
		}
		if(i == 0){
			aux = soma;
		}
		if(aux != soma){
			cont++;
		}
	}
	if(cont == 0){
		printf("Grafo e k-regular valor de K-%d ",aux);

	}else{
		printf("Grafo nao e k-regular");
	}
}