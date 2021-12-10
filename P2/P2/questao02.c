#include <stdio.h>
#include <time.h>

#define tam 30

void preencheVetor(int* numeros);
int ordenaVetor(int* numeros, int i);
int numNatural(int n);

int main(){
    int numeros[tam], i = tam - 1;

    srand(time(NULL));

    preencheVetor(numeros);
    ordenaVetor(numeros, i);


    return 0;
}
void preencheVetor(int* numeros){
    int i;

    for(i = 0; i < tam; i++){
        numeros[i] = rand() % tam + 1;
    }
}
int ordenaVetor(int* numeros, int i){
    int aux;

    if(i = 1){
        return 1;
    }
    if(numeros[i] < numeros[i - 1]){
        aux = numeros[i];
        numeros[i] = numeros[i - 1];
        numeros[i - 1] = aux;
    }else{
        return ordenaVetor(numeros, i - 1);
    }

    return ordenaVetor(numeros, i - 1);
}
int numNatural(int n){
    int i, cont = 0;

    for(i = 2; i < 100; i++){
        if(n / i){
            cont++;
            if(cont >= 2){
                return 1;
            }
        }
    }

    if(cont == 0){
        return 0;
    }
}