#include <stdio.h>
#include <math.h>

int hiperfatorial(int num);

int main(){
    int num, resultado;

    printf("\nEntre com um numero: ");
    scanf("%d", &num);

    resultado = hiperfatorial(num);

    printf("\nHipefatorial e: %d\n\n", resultado);
    
    return 0;
}

int hiperfatorial(int num){

    if(num == 1){
        return 1;

    }else{
        return pow(num, num) * hiperfatorial(num - 1);
    }
}