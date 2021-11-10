#include <stdio.h>

int fibonacci(int position);

int main(){
    int position, result;

    printf("\nDigite a posicao de fibonacci desejada: ");
    scanf("%d", &position);

    result = fibonacci(position);

    printf("\n  Numero e: %d\n\n", result);
    
    return 0;
}

int fibonacci(int position){
    int soma = 0;

    if(position == 1 || position == 2){
        return 1;
    }else{
        soma += fibonacci(position - 2) + fibonacci(position - 1);
        return soma;
    }
}