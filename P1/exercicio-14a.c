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
    int tamFrase;
    
    inicio:
    printf("Escreva uma frase:\n");
    scanf(" %[^\n]", frase);

    tamFrase = strlen(frase);

    if(frase > 30){
        printf("\n  A sua frase eh muito grande, digite uma frase menor que %d caracteres!!!\n\n", tam);
        goto inicio;
    }
}

int verificaLetra(char *frase, char letra){
    char *verifica;

    verifica = strchr(frase, letra);
    
    if(verifica != NULL){
        return 1;
    }else{
        return 0;        
    }
    
}