#include <stdio.h>
#include <time.h>
#include <string.h>

#define tam 4

typedef struct funcionario{
    char primeiroNome[11];
    int idade;
    char cargo[11];
    float salario;
}tipo_func;

void preencheDados(tipo_func* funcionarios);
void ordena(tipo_func* funcionarios);
void imprimir(tipo_func* funcionarios);

int main(){
    tipo_func funcionarios[tam];

    preencheDados(funcionarios);
    printf("\nANTES DA ORDENACAO:\n");
    imprimir(funcionarios);

    ordena(funcionarios);
    printf("\nDEPOIS DA ORDENACAO:\n");
    imprimir(funcionarios);
    
    return 0;
}
void preencheDados(tipo_func* funcionarios){
    int i;

    for(i = 0; i < tam; i++){
        printf("\nDigite o Primeiro Nome, idade, cargo e salario do funcionario[%d]:\n", i + 1);
        scanf("%s", funcionarios[i].primeiroNome);
        scanf("%d", &funcionarios[i].idade);
        scanf("%s", funcionarios[i].cargo);
        scanf("%f", &funcionarios[i].salario);
    }
}
void ordena(tipo_func* funcionarios){
    int i, j, min, idade;
    char primeiroNome[11], cargo[11];
    float salario;
    srand(time(NULL));

    for(i = tam - 1; i > 0; i--){
        min = rand() % i;
        for(j = i - 1; j >= 0; j--){
            if(funcionarios[j].salario < funcionarios[min].salario){
                min = j;
            }
        }
        if(i != min){
            //troca nome
            strcpy(primeiroNome, funcionarios[i].primeiroNome);
            strcpy(funcionarios[i].primeiroNome, funcionarios[min].primeiroNome);
            strcpy(funcionarios[min].primeiroNome, primeiroNome);

            //troca idade
            idade = funcionarios[i].idade;
            funcionarios[i].idade = funcionarios[min].idade;
            funcionarios[min].idade = idade; 

            //troca cargo
            strcpy(cargo, funcionarios[i].cargo);
            strcpy(funcionarios[i].cargo, funcionarios[min].cargo);
            strcpy(funcionarios[min].cargo, cargo);

            //troca salario
            salario = funcionarios[i].salario;
            funcionarios[i].salario = funcionarios[min].salario;
            funcionarios[min].salario = salario; 
        }
    }
}
void imprimir(tipo_func* funcionarios){
    int i;
    for(i = 0; i < tam; i++){
        printf("\nPrimeiro Nome: %s\nIdade: %d\nCargo: %s\nSalario: %.2f\n", funcionarios[i].primeiroNome, funcionarios[i].idade, funcionarios[i].cargo, funcionarios[i].salario);
    }
}