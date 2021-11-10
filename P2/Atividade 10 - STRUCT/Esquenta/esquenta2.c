#include <stdio.h>

#define tam 2

struct dados{
    char nome[50];
    int idade;
    float salario;
};

int main(){
    struct dados func[tam];
    int i; 
    float soma = 0.0;

    for(i = 0; i < tam; i++){
        printf("\nDigite o nome, idade e salario (%d):\n", i + 1);
        scanf("%s", func[i].nome);
        scanf("%d", &func[i].idade);
        scanf("%f", &func[i].salario);
    }
    
    for(i = 0; i < tam; i++){
        if(func[i].idade >= 20){
            soma += func[i].salario;
        }
    }

    printf("\nA soma dos salarios e R$%.2f!\n\n", soma);
    
    return 0;
}

