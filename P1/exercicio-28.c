/*
28) Considere o vetor V com 50 números inteiros gerados aleatoriamente de 1 a 100. Faça um algoritmo que
modifique V de modo que:
Crie e utilize três procedimentos: um para preencher o vetor, outro para modificá-lo e o terceiro para
realizar a impressão do vetor antes e depois da modificação.
Obs.: Não é permitido utilizar qualquer estrutura de dados auxiliar.
*/
#include <stdio.h>

#define tam 50

void preencheV(int *v);
void modificaV(int *v);
void imprimiV(int *v);

int main(){
    int v[tam];
    
    srand(time(NULL));

    preencheV(v);
    imprimiV(v);
    modificaV(v);
    imprimiV(v);

    return 0;
}

void preencheV(int *v){
    int i;
    for(i = 0; i < tam; i++){
        v[i] = rand() % 100 + 1;
    }
}
void modificaV(int *v){
    int i, j, soma = 0;

    for(i = 0; i < tam; i++){
        for(j = 0; j < tam; j++){
            if(i != j){
                soma += v[j];
            }
        }
        v[i] = soma;
    }
}
void imprimiV(int *v){
    int i;
    printf("Impressao do Vetor: ");
    for(i = 0; i < tam; i++){
        printf("%d ", v[i]);
    }
    printf("\n\n");
}