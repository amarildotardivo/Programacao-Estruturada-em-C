/*
28) Faça um algoritmo para ler pelo teclado a matriz de adjacência A(D) de um dígrafo
simples D com 20 vértices e preencher a matriz de adjacência R(D’) de um dígrafo
simples D’, onde D’ possui os arcos reversos de D. Ou seja, D’ possui o arco (i,j) se, e
somente se, o arco (j,i) pertence a D. Crie e utilize dois procedimentos: um para ler a
matriz de adjacência A(D) pelo teclado e outro para preencher a matriz de adjacência
R(D’).
*/
#include <stdio.h>

#define tam 15

void lerAD(int matrizAD[][tam]);
void preencheRD(int matrizAD[][tam], int matrizRD[][tam]);

int main(){
    int matrizAD[tam][tam], matrizRD[tam][tam];
    
    lerAD(matrizAD);
    preencheRD(matrizAD, matrizRD);

    return 0;
}

void lerAD(int matrizAD[][tam]){
    int i, j;

    for(i = 0; i < tam; i++){
		for(j = 0; j < tam; j++){
			printf("digite o numero para a posicao [%d][%d] da Matriz A(G):", i, j);
			scanf("%d", &matrizAD[i][j]);
		}
	}
}

void preencheRD(int matrizAD[][tam], int matrizRD[][tam]){
    int i, j;

    for(i = 0; i < tam; i++){
		for(j = 0; j < tam; j++){
            matrizRD[j][i] = matrizAD[i][j];
        }
    }
}