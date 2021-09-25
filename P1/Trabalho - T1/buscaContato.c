#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

void buscaContato(char *nome, char *caminho) {
	int tam = strlen(nome);
	
	char *linha[60];
	char *nomeContato[tam];
	FILE *arquivo;
	arquivo = fopen(caminho, "r");

	while (fgets(linha, 60, arquivo) != NULL) {
		strcpy(nomeContato, linha);
		if (stricmp(toupper(nomeContato), toupper(nome)) == 0) {
			printf(linha);
		}
	}
	fclose(arquivo);
}

void imprimeArquivo(char *caminho) {
	FILE *arquivo;
	char *linha[60];
				
	arquivo = fopen(caminho, "r");
	while (fgets(linha, 60, arquivo) != NULL) {
		printf(linha);
	}
	fclose(arquivo);
}


int main()
{
	imprimeArquivo("teste.txt");
	
	char *nome[30];
	printf("%s", "Digite um nome:\n");
	fgets(nome, 30, stdin);
	
	removeEspacos(nome);
	buscaContato(nome, "teste.txt");
	system("pause");
	return(0);
}