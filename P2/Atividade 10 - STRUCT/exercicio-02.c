#include <stdio.h>

#define tam 20
#define salMinimo 880.00

typedef struct conta{
    int numero;
    char nome[50];
    float saldo;
}tipo_conta;

void preencheDados(tipo_conta* corrente);
int salariosMin(tipo_conta* corrente);

int main(){
    tipo_conta corrente[tam];
    int resultado;

    preencheDados(corrente);
    resultado = salariosMin(corrente);

    printf("\n%d clientes tem saldo de no maximo 3 salarios minimos!\n\n", resultado);

    return 0;
}

void preencheDados(tipo_conta* corrente){
    int i;

    for(i = 0; i < tam; i++){
        printf("\nDigite o numero da conta, nome e saldo (%d):\n", i + 1);
        scanf("%d", &corrente[i].numero);
        scanf("%s", corrente[i].nome);
        scanf("%f", &corrente[i].saldo);
    }
}

int salariosMin(tipo_conta* corrente){
    int i, cont_saldo = 0;

    for(i = 0; i < tam; i++){
        if(corrente[i].saldo <= (3 * salMinimo) ){
            cont_saldo++;
        }
    }

    return cont_saldo;
}