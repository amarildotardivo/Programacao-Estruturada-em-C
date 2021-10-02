#include <stdio.h>

int main(){
    FILE *arqEntrada, *arqA, *arqR;
    char nome[20];
    float media;

    arqEntrada = fopen("Medias.txt", "r");
    arqA = fopen("Aprovados.txt", "w");
    arqR = fopen("Reprovados.txt", "w");

    if(arqEntrada == NULL){
        printf("\nEro ao abrir o arquivo Medias!\n\n");
        return 1;
    }

    while (!feof(arqEntrada)){
        fscanf(arqEntrada, "%s %f", nome, &media);

        if(media >= 7.0){
            fprintf(arqA, "%s %.1f\n", nome, media);
        }else{
            fprintf(arqR, "%s %.1f\n", nome, media);
        }
    }
    
    fclose(arqEntrada);
    fclose(arqA);
    fclose(arqR);
    
    return 0;
}