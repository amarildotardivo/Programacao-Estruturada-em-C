#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void inserir_contato();
int remover_contato();

void removeEspacos(char *nome);
int buscaContato(char *caminho);
int imprimeArquivo(char *caminho);

int imprimeAniversariante();

int verificaArquivoVazio(FILE *arquivo);

int main(){
    int verificacao = 0, auxiliar = 0, verificarAgenda;

    do{
    	printf("         AGENDA");
        printf("\n-------------------------");
        printf("\n1-Inserir um contato");
        printf("\n2-Remover um contato");
        printf("\n3-Listar os contatos");
        printf("\n4-Pesquisar um contato");
        printf("\n5-Aniversariante do mes");
        printf("\n6-Sair");
        printf("\n-------------------------\n");
        scanf("%d", &verificacao);

        switch (verificacao)
        {
        case 1:
        	printf("-----INSERINDO CONTATO-----\n");
            inserir_contato();
            printf("Contato inserido!");
            printf("\n-------------------------\n");
            
        break;

        case 2:
        	printf("-----EXCLUINDO CONTATO-----\n");
            auxiliar = remover_contato();
            
            if(auxiliar == 0){
                printf("\n      Contato removido\n");
            }else{
                if(auxiliar == 1){
                    printf("\n      Agenda nao existe! Insira ao menos 1 contato para remove-lo!\n");
                }else{
                    if(auxiliar == 2){
                        printf("\n      Contato nao encontrado\n");
                    }else{
                        printf("\n      Contato removido!\n\n     Agenda foi excluida, pois estava vazia!\n");
                    }
                }
            }
            printf("\n-------------------------\n");

        break;

        case 3:
			printf("-----IMPRIMINDO TODOS OS CONTATOS-----\n");
            verificarAgenda = imprimeArquivo("Agenda.txt");
            if(verificarAgenda == 1){
                printf("\n  Agenda ainda nao existe, adicione um contato para poder lista-los!\n\n");
            }else if(verificarAgenda == 2){
                printf("\n  Agenda Vazia! Adicione ao menos 1 contato para poder lista-los!\n\n");
            }
            printf("\n-------------------------\n");

        break;

        case 4:
			printf("-----PESQUISANDO UM CONTATO-----\n");
			verificarAgenda = buscaContato("Agenda.txt");
            if(verificarAgenda == 1){
                printf("\n  Agenda ainda nao existe, adicione um contato para poder pesquisa-los!\n\n");
            }else if(verificarAgenda == 2){
                printf("\n  Contato nao encontrado!\n\n");
            }
            printf("\n-------------------------\n");

        break;

        case 5:
            printf("-----PESQUISANDO ANIVERSARIANTE(S) DO MES-----\n");
            verificarAgenda = imprimeAniversariante();
            if(verificarAgenda == 1){
                printf("\n  Agenda ainda nao existe, adicione um contato para poder buscar os aniversariantes!\n\n");
            }else if(verificarAgenda == 2){
                printf("\n  Agenda Vazia! Adicione ao menos 1 contato para buscar aniversariantes!\n\n");
            }
            printf("\n-------------------------\n");
        break;

        }
    }while(verificacao != 6);

    

    return 0;
}

void inserir_contato(){
    char nome[20], telefone[20];
    int dia, mes;

    FILE  *arqAgenda = fopen("Agenda.txt", "a");
	
	
    printf("Digite o seu nome: \n");
    scanf(" %[^\n]s", nome);//colocado um espaço entre as aspas e o % para limpar buffer do teclado
    removeEspacos(nome);
	
    printf("Digite o telefone: \n");
    scanf(" %s", telefone);
	
	
    do{
		printf("Dia do aniversario: \n");
    	scanf("%d", &dia);
    	
	}while((dia > 31)||(dia <= 0));
    
	
	do{
		printf("Mes do aniversario: \n");
    	scanf("%d", &mes);
	}while(mes < 1 || mes > 12);
    
    
	
    fprintf(arqAgenda,"%s %s %d %d\n", nome,telefone,dia,mes);
    fclose(arqAgenda);

}

int remover_contato(){
    char nome[20], telefone[20],contato[20],nome_minusculo[20];
    int i,dia, mes,auxiliar,quantidade_removida=0;

    FILE *arqAgenda=fopen("Agenda.txt", "r");

    if(arqAgenda == NULL)
        return 1;

    printf("Insira o nome do contato a ser removido: \n");
    scanf(" %s", contato);
    
    auxiliar = strlen(contato);
    
    for(i = 0; i < auxiliar; i++){
        contato[i] = tolower(contato[i]); 
    }

    FILE *arqAgenda2=fopen("Agenda2.txt","w");

    while(fscanf(arqAgenda,"%s %s %d %d\n", nome, telefone, &dia, &mes)!=EOF){
        
        strcpy(nome_minusculo,nome);
        auxiliar = strlen(nome);

        for(i = 0; i < auxiliar; i++){
            nome_minusculo[i] = tolower(nome_minusculo[i]);
        }

        auxiliar = strcmp(contato, nome_minusculo);
        if(auxiliar == 0){
            if(quantidade_removida > 0){
                fprintf(arqAgenda2,"%s %s %d %d\n", nome,telefone,dia,mes);
            }else{
                quantidade_removida++;
            }
        }else{
            fprintf(arqAgenda2,"%s %s %d %d\n", nome,telefone,dia,mes);
        }
    }
   
   
   	fclose(arqAgenda); 
    fclose(arqAgenda2);

    remove("Agenda.txt");
    rename("Agenda2.txt","Agenda.txt");

    arqAgenda=fopen("Agenda.txt", "r");
    
    //retorna 1 pra vazio e 0 para cheio
    if(verificaArquivoVazio(arqAgenda) == 0){
      fclose(arqAgenda);
   }else{
       return 3;
   }

    

    if(quantidade_removida != 0){
        return 0;
    }else{
        return 2;
    }

}

int buscaContato(char *caminho) {
	char nome[20], contato[20], telefone[20];
    int dia, mes, encontrouContato = 0;
	FILE *arquivo;

	arquivo = fopen(caminho, "r");
    if(arquivo == NULL){
        return 1;
    }

	printf("\nDigite um nome:\n");
	scanf(" %[^\n]s", nome);
    removeEspacos(nome);
	
    while(fscanf(arquivo,"%s %s %d %d\n", contato, telefone, &dia, &mes) != EOF) {
		if (strncasecmp(contato, nome, strlen(nome) - 1) == 0) {
			printf("\n      %s %s %d %d\n", contato, telefone, dia, mes);
            encontrouContato++;
		}
	}

    rewind(arquivo);
	fclose(arquivo);

    //retora 2 - se não encotrar nenhum contato com o nome digitado
    if(encontrouContato > 0){
        return 0;
    }else{
        return 2;        
    }
}


int imprimeArquivo(char *caminho) {
	FILE *arquivo;
	char contato[20], telefone[20];
	int dia, mes;
				
	arquivo = fopen(caminho, "r");
    if(arquivo == NULL){
        return 1;
    }

	while(fscanf(arquivo,"%s %s %d %d\n", contato, telefone, &dia, &mes) != EOF) {
		printf("%s %s %d %d\n", contato, telefone, dia, mes);
	}

    rewind(arquivo);
	fclose(arquivo);

    return 0;
}

void removeEspacos(char *nome) {
	int i;
	int j = 0;
	int tam = strlen(nome);
	for (i = 0; i < tam; i++) {
		while ((i + j) < tam - 1 && nome[i + j] == ' ') {
			j++;
		}
		nome[i] = nome[i + j];
		if (i+j > tam) {
			nome[i] = '\0';
		}
	}
}

int imprimeAniversariante(){
    FILE *arqEntrada;
    int dia, mes, mesDigitado, mesEncontrado = 0;
    char nome[20], telefone[20];
    
    
    arqEntrada = fopen("Agenda.txt", "r");
    if(arqEntrada == NULL){
        return 1;//retorna 1 para arquivo não existe
    }

    printf("Digite o mes: ");
    scanf("%d", &mesDigitado);

    while(fscanf(arqEntrada, "%s %s %d %d", nome, telefone, &dia, &mes) != EOF){

        if(mes == mesDigitado ){
            printf("\n  %s %s %d %d\n", nome, telefone, dia, mes);
            mesEncontrado++;
        }
    }

    //verifica se o mes digitado pelo usuário não existe nos contatos
    if(mesEncontrado == 0){
        printf("\n  Nao ha nenhum contato que faz aniversario no mes %d!\n", mesDigitado);
    }

    rewind(arqEntrada);
    fclose(arqEntrada);
    return 0;
}

//retorna 0 - se arquivo cheio
//retorna 1 - se arquivo vazio
int verificaArquivoVazio(FILE *arquivo){
    int dia, mes;
    char nome[20], telefone[20];

    while (fscanf(arquivo, "%s %s %d %d", nome, telefone, &dia, &mes) != EOF){
        return 0;
    }

    fclose(arquivo);
    remove("Agenda.txt");
    return 1;
}