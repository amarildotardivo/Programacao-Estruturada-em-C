#include <stdio.h>
#include <stdlib.h>

#define n 3
#define m 5
#define l 4

void lerM(FILE *MatrizA, int mA[][m], FILE *MatrizB, int mB[][m]);
void transp(int mB[][m], int mBT[][l]);
void calc(int mA[][m], int mBT[][l], int mC[][l]);

int primos(int num);
void imprimeQtPrimos(int quantPrimos);

int main(){
    FILE *MatrizA, *MatrizB;
    int mA[n][m], mB[l][m], mBT[m][l], mC[n][l];

    MatrizA = fopen("MatrizA.txt", "r");
    if(MatrizA == NULL){
        printf("\nErro ao abrir o arquivo!\n\n");
        return 1;
    }

    MatrizB = fopen("MatrizB.txt", "r");
    if(MatrizB == NULL){
        printf("\nErro ao abrir o arquivo!\n\n");
        return 1;
    }

    lerM(MatrizA, mA,MatrizB, mB);
    transp(mB, mBT);
    calc(mA, mBT, mC);
    
    fclose(MatrizA);
    fclose(MatrizB);

    return 0;
}

void lerM(FILE *MatrizA, int mA[][m], FILE *MatrizB, int mB[][m]){
    int i, j, num;
    
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            fscanf(MatrizA, "%d", &num);
            mA[i][j] = num;
        }
    }

    for(i = 0; i < l; i++){
        for(j = 0; j < m; j++){
            fscanf(MatrizB, "%d", &num);
            mB[i][j] = num;
        }
    }
}
void transp(int mB[][m], int mBT[][l]){
    int i, j;

    for(i = 0; i < l; i++){
        for(j = 0; j < m; j++){
            
            mBT[j][i] = mB[i][j];
        }
    }
}
void calc(int mA[][m], int mBT[][l], int mC[][l]){
    int i, j, k, soma, qtPrimos = 0;

    for(i = 0; i < n; i++){
        for(j = 0; j < l; j++){
            soma = 0;
            for(k = 0; k < m; k++){
                soma += mA[i][k] * mBT[k][j];
            }
            mC[i][j] = soma;
        }
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < l; j++){
            qtPrimos += primos(mC[i][j]);
        }
    }

    imprimeQtPrimos(qtPrimos);
}

int primos(int num){
    int i, k = 1, cont = 0;

    while(k <= num){
        if( (num % k) == 0){
            cont++;
        }
        k++;
    }

    if(cont <= 2){
        //se o numero for primo retorna 1
        return 1;
    }else{
        return 0;
    }
        

}

void imprimeQtPrimos(int quantPrimos){
    printf("\nQuantidade de Primos na Matriz C: %d\n\n", quantPrimos);
}