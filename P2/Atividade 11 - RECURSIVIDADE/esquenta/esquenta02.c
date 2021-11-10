#include <stdio.h>
#include <math.h>

int somaCubos(int n);

int main(){
    int n = 4, resultado;

    resultado = somaCubos(n);

    printf("\n%d\n\n", resultado);
    
    return 0;
}

int somaCubos(int n){

    if(n == 1){
        return 1;

    }else{
        return pow(n, 3) + somaCubos(n - 1);
    }
}