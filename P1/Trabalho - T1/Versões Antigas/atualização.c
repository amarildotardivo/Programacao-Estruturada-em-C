//ATUALIZAÇÃO UTILIZADA DA V2 PARA V3
int remover_contato(){
    char nome[20], telefone[20],contato[20],nome_minusculo[20];
    int i,dia, mes,auxiliar,quantidade_removida=0, verificaArquivo;

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

    FILE *arqAgenda=fopen("Agenda.txt", "r");
    if(verificaArquivo = verificaArquivoVazio(arqAgenda) == 0){
      fclose(arqAgenda);
   }

    //retorna 1 pra vazio e 0 para cheio
    

    if(quantidade_removida != 0){
        return 0;
    }else{
        return 2;
    }

}
int verificaArquivoVazio(FILE *arquivo){
    int dia, mes, cont = 0;
    char nome[20], telefone[20];

    while (fscanf(arquivo, "%s %s %d %d", nome, telefone, &dia, &mes) != EOF)
    {
        cont++;
    }

    if(cont > 0){
        return 0;
    }else{
        fclose(arquivo);
        remove("Agenda.txt");
        return 1;
    }
}