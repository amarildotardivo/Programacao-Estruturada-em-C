#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//Procedimento criado lowercase deixa a string em caixa baixa, so chamar lowercase(<string desejada>), como e vetor e por padrao referencia.
//Lembrem que sera testado no linux logo systen("cls") e system("pause") nao funciona, e preciso system("clear") e getchar(); . 

void inserir_contato();
int remover_contato();

int main(){
    int verificacao = 0, auxiliar = 0;

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

        break;
        case 4:

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