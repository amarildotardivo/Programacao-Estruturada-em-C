#include <stdio.h>
#include <math.h>
#include <string.h>

#define qtd_alunos 100

typedef struct alunos{
    int matricula;
    char nome[50];
    float n1, n2, media;
}tipo_aluno;

void preenche(tipo_aluno* alunos);
int buscaBinaria(tipo_aluno* alunos, char *nomeDigitado);

int main(){
    tipo_aluno alunos[qtd_alunos];
    char nomeDigitado[50];

    preenche(alunos);
    ondernar(alunos);
    imprimi(alunos);

    printf("\nEntre com o nome a ser buscado: ");
    scanf(" %s", nomeDigitado);

    if(buscaBinaria(alunos, nomeDigitado) != -1){
        printf("\nAluno EXISTE!\n\n");
    }else{
        printf("\nAluno NAO existe!\n\n");
    }

    return 0;
}

void preenche(tipo_aluno* alunos){
    int i;

    for(i = 0; i < qtd_alunos; i++){
        printf("\nDigite a matricula, nome, nota 1 e nota 2 do aluno(%d):\n", i + 1);
        scanf("%d", &alunos[i].matricula);
        scanf(" %s", alunos[i].nome);
        scanf("%f", &alunos[i].n1);
        scanf("%f", &alunos[i].n2);

        alunos[i].media = (alunos[i].n1 + alunos[i].n2)/ 2;
    }
}

void ondernar(tipo_aluno* alunos){
    int i, j;
    tipo_aluno aux;

    for(i = 0; i < qtd_alunos; i++){
        for(j = 0; j < qtd_alunos - 1; j++){
            if( strcmp(alunos[j].nome, alunos[j + 1].nome) > 0){
                aux = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = aux;
            }
        }
    }
}

int buscaBinaria(tipo_aluno *alunos, char *elem){
    int inicio, meio, final;
    
    inicio = 0;
    final = qtd_alunos - 1;
    
    while(inicio <= final){
        meio = (inicio + final) / 2;
        
        if( strcmp(elem, alunos[meio].nome) < 0 ){
            //busca na metade da esqueda: do inicio até o final(que agora é meio - 1)
            final = meio - 1;
        }
        else if(strcmp(elem, alunos[meio].nome) > 0 ){
            //busca na metade da direita: do inicio(que agora é meio + 1) até o final
            inicio = meio + 1;
        }else{
            return meio;
        }
    }
    return -1;//elemento não encontrado
}

imprimi(tipo_aluno* alunos){
    int i;

    for(i = 0; i < qtd_alunos; i++){
        printf("\nDigite a matricula: %d", alunos[i].matricula);
        printf("\nNome: %s", alunos[i].nome);
        printf("\nNota 1: %.2f", alunos[i].n1);
        printf("\nNota 2: %.2f", alunos[i].n2);
        printf("\nMedia: %.2f\n\n", alunos[i].media);
    }
}