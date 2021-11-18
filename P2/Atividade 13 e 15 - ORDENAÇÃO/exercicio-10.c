#include <stdio.h>

#define qtd_func 2

typedef struct func{
    char nome[50];
    int idade;
    float salario;
    char cargo[50];
}tipo_func;

void preencher(tipo_func* func);
void ondernar(tipo_func* func);
void imprimir(tipo_func* func);

int main(){
    tipo_func func[qtd_func];
    
    preencher(func);
    printf("\nSTRUCT NAO ORDENADO:\n");
    imprimir(func);

    ondernar(func);
    printf("\nSTRUCT ORDENADO:\n");
    imprimir(func);

    return 0;
}
void preencher(tipo_func *func){
    int i;

    for(i = 0; i < qtd_func; i++){
        printf("\nInsira o nome do funcionario(%d): ", i + 1);
        scanf(" %[^\n]s", func[i].nome);

        printf("\nInsira a idade do funcionario(%d): ", i + 1);
        scanf("%d", &func[i].idade);

        printf("\nInsira a salario do funcionario(%d): ", i + 1);
        scanf(" %f", &func[i].salario);

        printf("\nInsira a cargo do funcionario(%d): ", i + 1);
        scanf(" %[^\n]s", func[i].cargo);
    }
}

void ondernar(tipo_func *func){
    int i, j, min;
    tipo_func aux;

    for(i = 0; i < qtd_func - 1; i++){
        min = i;
        for(j = i + 1; j < qtd_func; j++){
            if( func[j].idade < func[min].idade){
                min = j;
            }
        }
        if (i != min) {
            aux = func[i];
            func[i] = func[min];
            func[min] = aux;
        }
    }
}

void imprimir(tipo_func* func){
    int i;

    for(i = 0; i < qtd_func; i++){
        printf("\nNome: %s\n", func[i].nome);
        printf("\nIdade: %d\n", func[i].idade);
        printf("\nSalario: %.2f\n", func[i].salario);
        printf("\nCargo: %s\n\n", func[i].cargo);
    }
}