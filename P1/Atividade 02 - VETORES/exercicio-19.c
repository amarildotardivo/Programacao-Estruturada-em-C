/*
19) Faça um algoritmo para ler uma palavra pelo teclado (com no máximo 15 caracteres) e verificar se ela é
Palíndrome ou não, sem utilizar qualquer estrutura de dados auxiliar. Crie e utilize um procedimento
para ler a palavra e uma função para fazer a verificação. A impressão da mensagem (se a palavra é ou não
Palíndrome) deve ser na função main.
Obs. 1: Uma palavra Palíndrome é aquela que lida de frente para trás e de trás para frente tem a mesma
sequência de caracteres. Exemplos: arara, ovo, asa, radar, matam, etc;
Obs. 2: Lembre-se que o usuário pode digitar letras maiúsculas e minúsculas.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam 15

void lerPalavra(char *palavra);
int verificaPalavra(char *palavra);

int main(){
    char palavra[tam];
    int resultado;

    lerPalavra(palavra);
    resultado = verificaPalavra(palavra);

    if(resultado == 1){
        printf("A palavra: %s - eh um Palindromo!!!\n\n", palavra);
    }else{
        printf("A palavra: %s - NAO eh um Palindromo!!!\n\n", palavra);
    }

    return 0;
}

void lerPalavra(char *palavra){
    printf("Entre com uma palavra: ");
    scanf(" %s", palavra);
}

int verificaPalavra(char *palavra){
    int tamPalavra, i, j;
    char palavraReversa[tam], l, lr;

    tamPalavra = strlen(palavra);
    j = tamPalavra - 1;

    for(i = 0; i< tamPalavra; i++){
        palavraReversa[i] = palavra[j];
        j--;
    }
    palavraReversa[i] = '\0';
    printf("Palavra Revertida: %s\n\n", palavraReversa);

    for ( i = 0; i < tamPalavra; i++){
        l = palavra[i];
        lr = palavraReversa[i];
        if(l != lr){
            return 0;
        }
    }
    
    return 1;
}