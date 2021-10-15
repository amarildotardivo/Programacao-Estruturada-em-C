#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tam 30

void preenche(int *vet);
void imprimi(int *vet);

int main(){
    int vet[tam];

    preenche(vet);
    imprimi(vet);

    return 0;
}

void preenche(int *vet){
    int i;

    srand(time(NULL));
    
    for(i = 0; i < tam; i++){
        vet[i] = rand() % 500 + 1;
    }
}

void imprimi(int *vet){
    int i, j, cont;
    FILE *arqSaida;

    arqSaida = fopen("Resultado.txt", "w");

    for(i = 0; i <= tam; i++){
        cont = 0;
        if(vet[i] != 0){
            for(j = 0; j <= tam; j++){
                if( vet[i] == vet[j]){
                    cont++;
                }
            }
            fprintf(arqSaida, "Quantidade do número %d: %d\n", vet[i], cont);
        
            for(j = 0; j < tam; j++){
                if( vet[i] == vet[j] ){
                    vet[j] = 0;
                }
            }
        }

    }

    fclose(arqSaida);
}
