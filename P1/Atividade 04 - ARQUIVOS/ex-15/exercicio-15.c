#include <stdio.h>

int main(){
    FILE *arqEntrada;
    char palavras[20];
    int contaPalavras = 0;

    arqEntrada = fopen("Texto.txt", "r");

    while(!feof(arqEntrada)){
        fscanf(arqEntrada, " %s", palavras);
        contaPalavras++;
    }

    printf("Total de Palavras: %d", contaPalavras);

    fclose(arqEntrada);
    
    return 0;
}