#include <stdio.h>
#include <math.h>

#define tam 40

void lerVetores(int *v1, int *v2);
int verifica(int *v1, int *v2, int x, int y);

int main(){
    int v1[tam], v2[tam], x, y, resultado;
    
    lerVetores(v1, v2);

    do{
        printf("Entre com o valor de X (x tem que ser diferente de 0): ");
        scanf("%d", &x);

    }while(x == 0);

    do{
        printf("Entre com o valor de Y (y tem que ser diferente de 0): ");
        scanf("%d", &y);

    }while(y == 0);

    resultado = verifica(v1, v2, x, y);

    if(resultado == 1){
        printf("A condicao e verdadeira!!!");
    }else{
        printf("A condicao NAO e verdadeira!!!");
    }

    return 0;
}

void lerVetores(int *v1, int *v2){
    int i;
    printf("Entre com os %d numeros do Vetor 1:\n", tam);
    for(i = 0; i < tam; i++){
        scanf("%d", &v1[i]);
    }

    printf("Entre com os %d numeros do Vetor 2:\n", tam);
    for(i = 0; i < tam; i++){
        scanf("%d", &v2[i]);
    }
}
int verifica(int *v1, int *v2, int x, int y){
    int i, j, somar = 0, multiplicar = 1;

    for(i = 0; i < tam; i++){
        if(i % 2 != 0){
            somar += x * abs(v1[i]);
        }
    }

    for(j = 0; j < tam; j++){
        if(j % 2 == 0){
            multiplicar *= y * v2[j];
        }
    }

    if(somar <= multiplicar){
        return 1; //Retorna 1 quando a condição é verdadeira
    }else{
        return 0; //Retorna 0 quando a condição é falsa
    }
}