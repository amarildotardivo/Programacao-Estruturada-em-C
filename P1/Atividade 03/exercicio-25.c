/*
25) O grau de um vértice v, representado por d(v), em um grafo simples não-orientado
é o número de arestas incidentes (ligadas) a ele. Por exemplo, o grau do vértice 5 do
grafo G da Figura 1 é igual a 3 (d(5) = 3). Faça um algoritmo para ler pelo teclado a
matriz de adjacência A(G) de um grafo simples não-direcionado G com 10 vértices e
imprimir na tela o grau de cada vértice. Crie e utilize dois procedimentos: um para ler a
matriz pelo teclado e outro para imprimir o que se pede.
*/
#include <stdio.h>

#define tam 10

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
    int i, j, soma;
	
	for(i=0; i<tam; i++){
		soma=0;
		for(j=0; j<tam; j++){
			if(matrizAG[i][j] == 1){
				soma++;
			}
		}
		printf("O vertice %d tem grau %d\n", i + 1, soma);
	}
}