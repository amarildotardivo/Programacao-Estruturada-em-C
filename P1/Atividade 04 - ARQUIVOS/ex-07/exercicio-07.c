#include <stdio.h>
#include <string.h>

int main(){
    FILE *arqEntrada, *arqSaida;
    char nomeCidade[20], destino[20];
    int km;
    float consumo, custo, vv, ln; 
    // vv -> valor da viagem | ln -> listros necessarios

    arqEntrada = fopen("Distancias.txt", "r");
    arqSaida = fopen("Gastos.txt", "w");

    if(arqEntrada == NULL){
        printf("\nErro ao tentar abrir o arquivo Distancias!\n\n");
        return 1;
    }

    printf("Qual o destino?\n");
    scanf(" %s", destino);

    printf("Qual o consumo em km/l do seu veiculo?\n");
    scanf(" %f", &consumo);

    printf("Quanto custa o litro do combustivel?\n");
    scanf(" %f", &custo);

    while(!feof(arqEntrada)){
        fscanf(arqEntrada, "%s %d", nomeCidade, &km);
        
        if(strcmp(destino, nomeCidade) == 0){
            ln = km / consumo;
            vv = ln * custo;

            fprintf(arqSaida, "%s %.2flitros R$%.2f", nomeCidade, ln, vv);

            return 1; //retorna 1 para interromper o processamento, pois o destino já foi encontrado e processado
        }
        
    }
    
    fclose(arqEntrada);
    fclose(arqSaida);

    return 0;
}