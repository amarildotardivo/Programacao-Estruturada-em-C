/*
18) Faça um algoritmo que leia duas frases (de no máximo 20 caracteres cada uma) e imprima se as frases
possuem o mesmo comprimento, bem como se são exatamente iguais (posição i de uma frase é igual à posição
i da outra) ou diferentes no conteúdo (caso contrário). Exemplo:
Frase 1: Brasil Hexa 2010
Frase 2: Brasil! Hexa 2010!
Resultado: As duas frases são de tamanhos diferentes. As duas frases possuem conteúdo distintos.
Obs.: Considere que as frases não iniciam e nem terminam com espaço, bem como só existe um único espaço
entre as palavras das frases.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define tam 20

void lerfrases(char *frase1, char *frase2);

int main(){
    char frase1[tam], frase2[tam];
    
    lerfrases(frase1, frase2);

    if(strcmp(frase1, frase2) == 0){
        printf("As duas frases sao de tamanhos iguais. As duas frases possuem o mesmo conteudo.");
    }else{
        printf("As duas frases sao de tamanhos diferentes. As duas frases possuem conteudo distintos.");
    }

    return 0;
}

void lerfrases(char *frase1, char *frase2){

    printf("Entre com a primeira frase:\n");
    scanf(" %[^\n]", frase1);

    printf("Entre com a primeira frase:\n");
    scanf(" %[^\n]", frase2);
}