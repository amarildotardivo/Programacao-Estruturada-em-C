#include <stdio.h>

int fatorial(int num);

int main(){
    int num = 5, resultado;

    resultado = fatorial(num);

    printf("\n%d\n\n", resultado);

    return 0;
}

int fatorial(int num){

    if(num < 2){
        return 1;

    }else{
        return num * fatorial(num - 1);
    }
}