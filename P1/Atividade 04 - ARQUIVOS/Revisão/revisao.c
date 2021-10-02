#include <stdio.h>

int maxMin(FILE *arqEntrada);
int quantAprovados(FILE *arqEntrada);
int mediaReprovados(FILE *arqEntrada);

int main(){
    FILE *arqEntrada;

    arqEntrada = fopen("Notas.txt", "r");

    if(arqEntrada == NULL){
        printf("\nErro na abertura do arquivo!\n\n");
        return 1;
    }

    maxMin(arqEntrada);
    quantAprovados(arqEntrada);
    mediaReprovados(arqEntrada);
    
    fclose(arqEntrada);

    return 0;
}

int maxMin(FILE *arqEntrada){
    float min, max, nota;
    FILE *arqSaida;

    
    fscanf(arqEntrada, "%f", &nota);
    max = nota;

    while(! feof(arqEntrada)){
        fscanf(arqEntrada, "%f", &nota);

        if(nota > max){
            max = nota;
        }
    }

    rewind(arqEntrada);

    fscanf(arqEntrada, "%f", &nota);
    min = nota;

    while(! feof(arqEntrada)){
        fscanf(arqEntrada, "%f", &nota);

        if(nota < min){
            min = nota;
        }
    }

    arqSaida = fopen("Resultado.txt", "w");
    
    fprintf(arqSaida, "Nota Max = %.2f \nNota Min = %.2f\n", max, min);

    fclose(arqSaida);
}

int quantAprovados(FILE *arqEntrada){
    rewind(arqEntrada);

    int cont = 0;
    float nota;
    FILE *arqSaida;

    while(!feof(arqEntrada)){
        fscanf(arqEntrada, "%f", &nota);
        if(nota >= 7.0){
            cont++;
        }
    }

    arqSaida = fopen("Aprovados.txt", "w");

    fprintf(arqSaida, "Aprovados: %d", cont);
    
    fclose(arqSaida);

}

int mediaReprovados(FILE *arqEntrada){
    rewind(arqEntrada);

    float nota, soma = 0.0, media;
    int cont = 0;
    FILE *arqSaida;

    while(!feof(arqEntrada)){
        fscanf(arqEntrada, "%f", &nota);
        
        if(nota < 7.0){
            soma += nota;
            cont++;
        }
    }
    media = soma/cont;

    arqSaida = fopen("Reprovados.txt", "w");
    
    fprintf(arqSaida, "Media dos reprovados: %.2f", media);

    fclose(arqSaida);

}
