/*
14) Faça um algoritmo que leia uma frase (considerando os espaços) com no máximo 30 caracteres e verifique
se uma letra (lida pelo teclado na função main) existe na frase. Crie e utilize um procedimento para ler a
frase e uma função para a verificação. A impressão da informação tem que ser feita na função main.
Obs.: Lembre-se que o usuário pode digitar letras maiúsculas e minúsculas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam 30

void preencheFrase(char *frase);
int verificaLetra(char *frase, char letra);

int main(){
    char frase[tam], letra;
    int sinal;

    preencheFrase(frase);

    printf("Entre com uma Letra: ");
    scanf(" %c", &letra);

    sinal = verificaLetra(frase, letra);

    if(sinal == 1){
        printf("A letra: %c - existe na frase!!!\n\n", letra);
    }else{
        printf("A letra: %c - NAO existe na frase!!!\n\n", letra);
    }

    return 0;
}

void preencheFrase(char *frase){
    printf("Escreva uma frase:\n");
    scanf(" %[^\n]", frase);
}

int verificaLetra(char *frase, char letra){
    char l;
    int i, tamanhoFrase;

    tamanhoFrase = strlen(frase);

    for(i = 0; i < tamanhoFrase; i++){
        l = frase[i];
        if(l == letra){
            return 1;
        }
    }

    return 0;   
    
}