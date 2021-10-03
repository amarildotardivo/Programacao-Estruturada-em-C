#include <stdio.h>
#include <string.h>

int main(){
    FILE *arqEntrada;
    char palavra[15], palavraDigitada[15];
    int contaPalavra = 0;

    arqEntrada = fopen("Palavras.txt", "r");

    if(arqEntrada == NULL){
        printf("\nErro ao abrir o arquivo!\n\n");
        return 1;
    }

    printf("Entre com a palavra a ser buscada: ");
    scanf(" %s", palavraDigitada);

    while(!feof(arqEntrada)){
        fscanf(arqEntrada, " %s", palavra);

        if(strcmp(palavra, palavraDigitada) == 0){
            contaPalavra++;
        }
    }

    printf("\nA palavra %s apareceu %d vezes!\n\n", palavraDigitada, contaPalavra);

    fclose(arqEntrada);
    
    return 0;
}