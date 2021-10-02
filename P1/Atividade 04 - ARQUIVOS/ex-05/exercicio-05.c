#include <stdio.h>

int main(){
    FILE *arqEntrada, *arqSaida;
    char nomeCidade[20];
    int km;
    float consumo, custo, vv, ln; 
    // vv -> valor da viagem | ln -> listros necessarios

    arqEntrada = fopen("Distancias.txt", "r");
    arqSaida = fopen("Gastos.txt", "w");

    if(arqEntrada == NULL){
        printf("\nErro ao tentar abrir o arquivo Distancias!\n\n");
        return 1;
    }

    printf("Qual o consumo em km/l do seu veiculo?\n");
    scanf(" %f", &consumo);

    printf("Quanto custa o litro do combustivel?\n");
    scanf(" %f", &custo);

    while(!feof(arqEntrada)){
        fscanf(arqEntrada, "%s %d", nomeCidade, &km);
        
        ln = km / consumo;
        vv = ln * custo;

        fprintf(arqSaida, "Cidade: %s Litros: %.2fL Valor: R$%.2f\n", nomeCidade, ln, vv);
    }
    
    fclose(arqEntrada);
    fclose(arqSaida);

    return 0;
}