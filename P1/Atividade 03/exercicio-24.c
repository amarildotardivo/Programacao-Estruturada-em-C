/*
24) Faça um algoritmo para, primeiro, ler pelo teclado todos os 30 números naturais
(maiores do que 1) da matriz M4x5 e, em seguida, imprimir na tela a quantidade de
números primos que M possui. Crie e utilize dois procedimentos: um para ler a matriz
e outro para calcular e imprimir a quantidade de números primos. Crie e utilize também
uma função que retorna 1, se um número natural for primo, ou retorna 0, caso contrário.
*/
#include <stdio.h>

#define lin 2
#define col 3

void lerM(int matriz[][col]);
int verificaPrimo(int primo);
void calcPrintM(int matriz[][col]);

int main(){
    int matriz[lin][col];

    lerM(matriz);
    calcPrintM(matriz);
    
    return 0;
}

void lerM(int matriz[][col]){
    int i, j;

    printf("Entre com numeros naturais maiores do que 1:\n");
    for(i = 0; i < lin; i++){
        j = 0;
        do{
            scanf("%d", &matriz[i][j]);
            if(matriz[i][j] > 1 && matriz[i][j] <= 30){
                j++;
            }else{
                printf("Entre com um numero maior do que 1 e menor ou igual a 30!!!\n");
            }

        }while(j < col);
    }

    printf("\nMatriz:\n");
    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int verificaPrimo(int primo){
    int i, contaResto = 0;

    for(i = 1; i <= primo; i++){
        if(primo % i == 0){
            contaResto++;
        }
    }

    if(contaResto == 2){
        return 1;

    }else{
        return 0;

    }
}

void calcPrintM(int matriz[][col]){
    int i, j, contaPrimo = 0;

    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            if(verificaPrimo(matriz[i][j]) == 1){
                contaPrimo++;
            }
        }
    }

    printf("Primos: %d\n\n", contaPrimo);
}