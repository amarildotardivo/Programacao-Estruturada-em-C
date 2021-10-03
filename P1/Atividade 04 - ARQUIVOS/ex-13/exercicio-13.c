#include <stdio.h>

int main(){
    FILE *arqEntrada, *arqSaida;
    char nomeCidade[20];
    int  populacao, maiorPop;

    arqEntrada = fopen("Cidades.txt", "r");
    arqSaida = fopen("Populacao.txt", "w");

    if(arqEntrada == NULL){
        printf("\nErro ao abrir o arquivo!\n\n");
        return 1;
    }
    
    fscanf(arqEntrada, "%s %d", nomeCidade, &populacao);
    maiorPop = populacao;

    while (!feof(arqEntrada)){
        fscanf(arqEntrada, "%s %d", nomeCidade, &populacao);
        
        if(populacao > maiorPop){
            maiorPop = populacao;
        }
    }

    rewind(arqEntrada);

    while (!feof(arqEntrada)){
        fscanf(arqEntrada, "%s %d", nomeCidade, &populacao);
        if(populacao == maiorPop){
            fprintf(arqSaida, "%s %d", nomeCidade, populacao);
        }
    }

    fclose(arqEntrada);
    fclose(arqSaida);    
    
    return 0;
}