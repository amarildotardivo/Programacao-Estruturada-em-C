#include <stdio.h>
#include <time.h>

#define LIN 7
#define COL 3

void preencheM(int m[][COL]);
void calculaTransp(int m[][COL], int t[][LIN]);
void imprimiM(int t[][COL]);

int main(){
    int m[LIN][COL], t[COL][LIN];

    preencheM(m);
    calculaTransp(m, t);
    imprimiM(m);
    imprimiM(t);
    
    return 0;
}
void preencheM(int m[][COL]){
    int i, j;

    srand(time(NULL));

    for(i = 0; i < LIN; i++)
        for(j = 0; j < COL; j++){
            m[i][j] = rand() % 25 + 1;
        }
}
void calculaTransp(int m[][COL], int t[][LIN]){
    int i, j;

    for(i = 0; i < LIN; i++)
        for(j = 0; j < COL; j++){
            t[j][i] = m[i][j];            
        }
}
void imprimiM(int t[][COL]){
    int i, j;
    printf("Matriz:\n");
    for(i = 0; i < LIN; i++){
        for(j = 0; j < COL; j++){
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}