#include <stdio.h>
#include <string.h>

#define tam 1

struct dados{
    char nome[50];
    int idade;
    float salario;
    char cargo[50];
};

int main(){
    struct dados func[tam];
    int i, cont_diretor = 0;
    char cargo[50];

    for(i = 0; i < tam; i++){
        printf("\nDigite o nome, idade, salario e diretor (%d):\n", i + 1);
        scanf("%s", func[i].nome);
        scanf("%d", &func[i].idade);
        scanf("%f", &func[i].salario);
        scanf("%s", func[i].cargo);
    }

    for(i = 0; i < tam; i++){
        if(strcmp(func[i].cargo, "diretor") == 0){
            if(func[i].salario > 5000){
                cont_diretor++;
            }
        }
    }

    printf("\n%d Diretores ganham mais de R$5.000,00!!!\n\n", cont_diretor);
    
    return 0;
}

