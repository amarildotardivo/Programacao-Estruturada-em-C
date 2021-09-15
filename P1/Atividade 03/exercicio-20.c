/*
20) Faça um algoritmo que leia uma matriz 10 x 3, onde as linhas representam os
alunos e as colunas as 3 provas de cada aluno. Em seguida, imprima a maior nota e a
menor nota da prova 1, da prova 2 e da prova 3. Crie e utilize dois procedimentos: um
para ler a matriz e outro para imprimir as informações.
*/
#include <stdio.h>

#define LIN 10
#define COL 3

void lerM(int matriz[][COL]);
void imprimirNotas(int matriz[][COL]);

int main(){
    int matriz[LIN][COL];

    lerM(matriz);
    imprimirNotas(matriz);

    return 0;
}

void lerM(int matriz[][COL]){
    int i, j;

    printf("Entre com as %d notas dos %d alunos: \n", COL, LIN);
    for(i = 0; i < LIN; i++){
        for(j = 0; j < COL; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
}
void imprimirNotas(int matriz[][COL]){
    int i, j, maiorNota;

    for(j = 0; j < COL; j++){
        maiorNota = 0;
        for(i = 0; i < LIN; i++){
            if(matriz[i][j] > maiorNota)
                maiorNota = matriz[i][j];
        }
        printf("Nota P%d: %d\n", j + 1, maiorNota);
    }
}