#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//Procedimento criado lowercase deixa a string em caixa baixa, so chamar lowercase(<string desejada>), como e vetor e por padrao referencia.
//Lembrem que sera testado no linux logo systen("cls") e system("pause") nao funciona, e preciso system("clear") e getchar(); . 

void inserir_contato();
int remover_contato();

void removeEspacos(char *nome);
void buscaContato(char *caminho);
void imprimeArquivo(char *caminho);

int imprimiAniversariante();

int main(){
    int verificacao = 0, auxiliar = 0;
	char *nome[20];

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
		system("clear");
		system("cls");
       	

        switch (verificacao)
        {
        case 1:
        	printf("-----INSERINDO CONTATO-----\n");
            inserir_contato();
            printf("Contato inserido!");
            printf("\n-------------------------\n");
            system("pause");
			system("cls");
            
        break;

        case 2:
        	printf("-----EXCLUINDO CONTATO-----\n");
            auxiliar = remover_contato();
            
            if(auxiliar == 0){
                printf("\nContato removido\n");
            }else{
                if(auxiliar == 1){
                    printf("\nAgenda Vazia\n");
                }else{
                    if(auxiliar == 2){
                        printf("\nContato nao encontrado\n");
                    }
                }
            }
            printf("\n-------------------------\n");
			system("pause");
			system("cls");
        break;

        case 3:
			printf("-----IMPRIMINDO TODOS OS CONTATOS-----\n");
            imprimeArquivo("Agenda.txt");
            printf("\n-------------------------\n");
			system("pause");
			system("cls");
        break;

        case 4:
			printf("-----PESQUISANDO UM CONTATO-----\n");
			buscaContato("Agenda.txt");
            printf("\n-------------------------\n");
			system("pause");
			system("cls");
        break;

        case 5:
            printf("-----ANIVERSARIANTE(S) DO MES-----\n");
            auxiliar = imprimiAniversariante();
            if(auxiliar == 1){
                printf("\nAgenda ainda não existe, adicione um contato para poder buscar os aniversariantes!\n\n");
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
	fflush(stdin);
	
    printf("Digite o seu nome: \n");
    scanf("%s", nome);
	fflush(stdin);
    printf("Digite o telefone: \n");
    scanf("%s", telefone);
	fflush(stdin);
	
    do{
		printf("Dia do aniversario: \n");
    	scanf("%d", &dia);
    	fflush(stdin);
	}while((dia > 31)||(dia <= 0));
    
	fflush(stdin);
	do{
		printf("Mes do aniversario: \n");
    	scanf("%d", &mes);
	}while(mes < 1 || mes > 12);
    
    
	fflush(stdin);
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
    scanf("%s", contato);
    
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

    if(quantidade_removida != 0){
        return 0;
    }else{
        return 2;
    }
}

void buscaContato(char *caminho) {
	char nome[20];
	printf("%s", "\nDigite um nome:\n");
	scanf("%s", nome);
	fflush(stdin);
	removeEspacos(nome);

	char contato[20], telefone[20];
	int dia, mes;
	
	FILE *arquivo;
	arquivo = fopen(caminho, "r");

	while(fscanf(arquivo,"%s %s %d %d\n", contato, telefone, &dia, &mes) != EOF) {
		if (strncasecmp(contato, nome, strlen(nome) - 1) == 0) {
			printf("%s %s %d %d\n", contato, telefone, dia, mes);
		}
	}
	fclose(arquivo);
}

void imprimeArquivo(char *caminho) {
	FILE *arquivo;
	char contato[20], telefone[20];
	int dia, mes;
				
	arquivo = fopen(caminho, "r");
	while(fscanf(arquivo,"%s %s %d %d\n", contato, telefone, &dia, &mes) != EOF) {
		printf("%s %s %d %d\n", contato, telefone, dia, mes);
	}
	fclose(arquivo);
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

int imprimiAniversariante(){
    FILE *arqEntrada;
    int dia, mes, mesDigitado, mesEncontrado = 0;
    char nome[20], telefone[20];
    
    arqEntrada = fopen("Agenda.txt", "r");
    if(arqEntrada == NULL){
        return 1;
    }

    printf("Digite o mas: ");
    scanf("%d", &mesDigitado);

    while(fscanf(arqEntrada, "%s %s %d %d", nome, telefone, &dia, &mes) != EOF){

        if(mes == mesDigitado ){
            printf("%s %s %d %d\n", nome, telefone, dia, mes);
            mesEncontrado++;
        }
    }

    if(mesEncontrado > 0){
        printf("\n  Nao ha nenhum contato que faz aniversario no mes %d!\n", mesDigitado);
    }

    return 0;

}
