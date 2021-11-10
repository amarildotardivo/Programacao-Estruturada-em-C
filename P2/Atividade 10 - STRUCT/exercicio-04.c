#include <stdio.h>

#define tam 3

typedef struct dados{
    int matricula;
    char nome[50];
    float p1, p2, p3;
}tipo_aluno;

void preencherDados(tipo_aluno* aluno);
void quantAprovReprov(tipo_aluno* aluno);

int main(){
    tipo_aluno aluno[tam];
    
    preencherDados(aluno);
    quantAprovReprov(aluno);

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
void quantAprovReprov(tipo_aluno* aluno){
    int i, aprovados = 0, reprovados = 0;

    for(i = 0; i < tam; i++){
        if(aluno[i].p3 >= 6.0 ){
            aprovados++;
        }else{
            reprovados++;
        }
    }

    printf("\nAlunos Aprovados: %d - Alunos Reprovados: %d\n\n", aprovados, reprovados);
}