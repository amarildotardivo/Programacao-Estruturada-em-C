#include <stdio.h>

#define tam 20

struct conta{
    int numero;
    char nome[50];
    float saldo;
};

int main(){
    struct conta corrente[tam];
    int i, cont_saldo = 0;

    for(i = 0; i < tam; i++){
        printf("\nDigite o numero da conta, nome e saldo (%d):\n", i + 1);
        scanf("%d", &corrente[i].numero);
        scanf("%s", corrente[i].nome);
        scanf("%f", &corrente[i].saldo);
    }
    
    for(i = 0; i < tam; i++){
        if(corrente[i].saldo > 1000.00){
            cont_saldo++;
        }
    }

    printf("\n%d clientes tem saldo maior do que R$1.000,00!\n\n", cont_saldo);

    return 0;
}