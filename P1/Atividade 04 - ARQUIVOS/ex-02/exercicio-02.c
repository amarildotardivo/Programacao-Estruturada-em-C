#include <stdio.h>

int main(){
    FILE *arqEntrada, *arqSaida;
    float n1, n2, n3;

    arqEntrada = fopen("Notas.txt", "r");
    arqSaida = fopen("Situacao.txt", "w");

    if(arqEntrada == NULL){
        printf("\nErro na abertura do arquivo Notas!\n\n");
        return 1;
    }

    while(!feof(arqEntrada)){
        fscanf(arqEntrada, "%f %f %f", &n1, &n2, &n3);

        if( (n1 + n2 + n3)/3 >= 5.0){
            fprintf(arqSaida, "%.1f A\n", (n1 + n2 + n3)/3);
        }else{
            fprintf(arqSaida, "%.1f R\n", (n1 + n2 + n3)/3);
        }
    }
    
    fclose(arqEntrada);
    fclose(arqSaida);

    return 0;
}