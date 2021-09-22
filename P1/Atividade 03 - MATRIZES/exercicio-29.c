/*
29) Faça um algoritmo para ler pelo teclado a matriz de adjacência A(D) de um dígrafo
simples D com 10 vértices e imprimir na tela todos os ciclos elementares de
comprimento 3 presentes em D. Crie e utilize dois procedimentos: um para ler a matriz
de adjacência A(D) pelo teclado e outro para imprimir na tela o que se pede.
Obs.: Exemplos de ciclos elementares de comprimento 3 (representados pela sequência
de vértices) presentes no grafo D da Figura 2: 1-2-5-1; 2-5-1-2; 5-1-2-5.
*/
#include <stdio.h>

#define tam 5

void lerAD(int matrizAD[][tam]);
void imprimiCiclos(int matrizAD[][tam]);

int main(){
    int matrizAD[tam][tam];

    lerAD(matrizAD);
    imprimiCiclos(matrizAD);    

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

void imprimiCiclos(int matrizAD[][tam]){
    int i, j ,k, h;

    printf("Ciclos:\n");
    for(i = 0; i < tam; i++){
		for(j = 0; j < tam; j++){
            if(matrizAD[i][j] == 1){
                
                for(k = 0; k < tam; k++){
                    if(matrizAD[j][k] == 1){
                        
                        for(h = 0; h < tam; h++){
                            if(matrizAD[k][h] == 1){
                                if(h == i){
                                    printf("%d - %d - %d - %d\n",h + 1, j + 1, k + 1, h + 1);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}