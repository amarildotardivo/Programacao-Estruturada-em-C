#include <stdio.h>

#define tam 2

typedef struct dados{
    int matricula;
    char pNome[50];
    float nota1, nota2, media;
}tipo_aluno;

void preencherDados(tipo_aluno* aluno);
void imprimirDados(tipo_aluno* aluno, float M);

int main(){
    tipo_aluno aluno[tam];
    float M;

    preencherDados(aluno);

    printf("\nDigite a media desejada para realizar a busca: ");
    scanf("%f", &M);
    
    imprimirDados(aluno, M);
    
    return 0;
}

void preencherDados(tipo_aluno* aluno){
    int i;

    for(i = 0; i < tam; i++){
        printf("\nDigite a Matricula, Nome, Nota P1 e Nota P2(%d):\n", i + 1);
        scanf("%d", &aluno[i].matricula);
        scanf("%s", aluno[i].pNome);
        scanf("%f", &aluno[i].nota1);
        scanf("%f", &aluno[i].nota2);

        aluno[i].media = (aluno[i].nota1 + aluno[i].nota2) / 2;
    }
}

void imprimirDados(tipo_aluno* aluno, float M){
    int i, contAprovados = 0;

    for(i = 0; i < tam; i++){
        if( aluno[i].media >= M ){
            contAprovados++;
        }
    }
    
    printf("\nA quantidade de alunos com media igual ou superior a %.2f e: %d\n\n", M, contAprovados);
}
