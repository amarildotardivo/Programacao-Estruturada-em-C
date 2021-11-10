#include <stdio.h>

int calcular(int a, int b);

int main(){
    int a, b, resultado;

    printf("\nEntre com a base: ");
    scanf("%d", &a);

    printf("\nEntre com o expoente: ");
    scanf("%d", &b);

    resultado = calcular(a, b);

    printf("\n  %d elevado a %d e: %d\n\n",a, b, resultado);

    return 0;
}

int calcular(int a, int b){
    int valor;

    if(b == 0){
        return 1;
    }else{
        return a * calcular(a, b - 1);
    }
}