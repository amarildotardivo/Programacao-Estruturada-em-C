#include <stdio.h>
#include <time.h>

#define tam 30

typedef struct produto{
    char nome[30];
    char marca[30];
    float precoTabela;
    float desconto;
    float precoFinal;
}tipo_prod;

void preencheProduto(tipo_prod* produtos);
void imprimirInfo(tipo_prod* produtos, float valor);

int main(){
    tipo_prod produtos[tam];
    float valor;

    preencheProduto(produtos);

    do{
        printf("\nEntre com um valor(Menor ou igual a R$100,00):\n");
        scanf("%f", &valor);
    }while(valor < 0 || valor > 100);

    imprimirInfo(produtos, valor);
    
    return 0;
}
void preencheProduto(tipo_prod* produtos){
    int i;

    for(i = 0; i < tam; i++){
        printf("\nDigite o Nome, Marca, Preco de Tabela, e Desconto do Produto[%d]:\n", i + 1);
        scanf("%s", produtos[i].nome);
        scanf("%s", produtos[i].marca);
        scanf("%f", &produtos[i].precoTabela);
        scanf("%f", &produtos[i].desconto);

        produtos[i].precoFinal = produtos[i].precoTabela - ( (produtos[i].desconto / 100) * produtos[i].precoTabela );
    }
}
void imprimirInfo(tipo_prod* produtos, float valor){
    int i, cont = 0;
    //a variavel v recebe 25 porcento do valor
    float v = (25/100) * valor;

    for(i = 0; i < tam; i++){
        if(produtos[i].precoFinal <= v){
            printf("\nNome Produto: %s\nPreco Final: %.2f\n", produtos[i].nome, produtos[i].precoFinal);
            cont++;
        }
    }

    if(cont == 0){
        printf("\nNenhum Produto encontrado!!!\n\n");
    }
}