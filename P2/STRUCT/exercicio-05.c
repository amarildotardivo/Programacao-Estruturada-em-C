#include <stdio.h>
#include <string.h>

#define tam 3

typedef struct dados{
    int matricula;
    char nome[50];
    float p1, p2, p3;
}tipo_aluno;

void preencherDados(tipo_aluno* aluno);
void imprimirDados(tipo_aluno* aluno, char* nomeDigitado);

int main(){
    tipo_aluno aluno[tam];
    char nomeDigitado[50];
    
    preencherDados(aluno);

    printf("\nDigite o nome de algum aluno: ");
    scanf("%s", nomeDigitado);
    
    imprimirDados(aluno, nomeDigitado);

    return 0;
}

void preencherDados(tipo_aluno* aluno){
    int i;

    for(i = 0; i < tam; i++){
        printf("\nDigite a Matricula, Nome, Nota P1 e Nota P2(%d):\n", i + 1);
        scanf("%d", &aluno[i].matricula);
        scanf("%s", aluno[i].nome);
        scanf("%f", &aluno[i].p1);
        scanf("%f", &aluno[i].p2);

        aluno[i].p3 = (aluno[i].p1 + aluno[i].p2) / 2;
    }
}

void imprimirDados(tipo_aluno* aluno, char* nomeDigitado){
    int i;

    for(i = 0; i < tam; i++){
        if(strcmp(nomeDigitado, aluno[i].nome) == 0){
            printf("\nAluno: %s - Matricula(%d)\nNota P1: %.2f\nNota P2: %.2f\nNota P3: %.2f\n\n", aluno[i].nome, aluno[i].matricula, aluno[i].p1, aluno[i].p2, aluno[i].p3);
        }
    }
}