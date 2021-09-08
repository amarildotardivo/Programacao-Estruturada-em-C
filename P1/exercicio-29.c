/*
29) Considere o vetor V com n números inteiros lidos pelo teclado, sendo n = 30. Faça um algoritmo para ler
pelo teclado na função main o número inteiro k (1 ≤ k ≤ 4) e imprimir o que se pede na expressão abaixo:

Crie e utilize um procedimento para ler o vetor e uma função para retornar o que se pede. A impressão
desta informação deve ser realizada na função main.
Obs.: Não é permitido utilizar qualquer estrutura de dados auxiliar.
*/
#include <stdio.h>

#define n 30

void lerVetor(int *v);
int maiorSomatorio(int *v, int k);

int main(){
    int v[n], k, resultado;

    printf("Entre com um numero de 1 a 4: ");
    scanf("%d", &k);

    lerVetor(v);
    resultado = maiorSomatorio(v, k);

    printf("O maiorSomatorio numero da soma é: %d\n", resultado);
    
    return 0;
}

void lerVetor(int *v){
    int i;

    printf("entre com os numeros do vetor:\n");
    for(i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
}
int maiorSomatorio(int *v, int k){
    int i, j, soma, maiorSoma = 0;

    for(i = 0; i <= n - k; i++){
        soma = 0;
        for(j = i; j <= i + (k - 1); j++){
            soma += v[j];
        }
        if(soma > maiorSoma){
            maiorSoma = soma;
        }
    }

    return maiorSoma;
}