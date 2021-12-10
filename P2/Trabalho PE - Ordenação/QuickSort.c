//Grupo: Amarildo Junior, Leonardo, Elias Junior
//QuickSort Ordenado de maneira Não Crescente
#include <stdio.h>
#include <time.h>
#define A 5000
#define B 10000
#define C 20000
#define D 30000

void lerVetor(FILE *arqA, FILE *arqB, FILE *arqC, FILE *arqD, int vetorA[], int vetorB[], int vetorC[], int vetorD[]);
void ordenaQuick(int vetor[],int ini, int fim);
void imprimeVetorOrdenado(int vetorA[], int vetorB[], int vetorC[], int vetorD[], FILE *arqSaida);
int particiona(int vetor[], int ini, int fim);

void inicioTempo(float *timer);
void fimTempo(float timer);

int main(){
	FILE *arqA, *arqB, *arqC, *arqD, *arqSaida;
	int vetorA[A], vetorB[B], vetorC[C], vetorD[D], ini=0, fim;
	float timer;
	//Leitura dos arquivos
	lerVetor(arqA, arqB, arqC, arqD, vetorA, vetorB, vetorC, vetorD);
	//Ordenação dos vetores lidos
	printf("\nVetor A:");
	fim=A-1;
	inicioTempo(&timer);
	ordenaQuick(vetorA, ini, fim);
	fimTempo(timer);

	printf("\nVetor B:");
	fim=B-1;
	inicioTempo(&timer);
	ordenaQuick(vetorB, ini, fim);
	fimTempo(timer);

	printf("\nVetor C:");
	fim=C-1;
	inicioTempo(&timer);
	ordenaQuick(vetorC, ini, fim);
	fimTempo(timer);

	printf("\nVetor D:");
	fim=D-1;
	inicioTempo(&timer);
	ordenaQuick(vetorD, ini, fim);
	fimTempo(timer);
	//Impressão em novos arquivos de maneira ordenada
	imprimeVetorOrdenado(vetorA, vetorB, vetorC, vetorD, arqSaida);

	return 0;
}

//Leitura dos arquivos em vetor para ordenação
void lerVetor(FILE *arqA, FILE *arqB, FILE *arqC, FILE *arqD, int vetorA[], int vetorB[], int vetorC[], int vetorD[]){
	//Leitura A
	int i=0;
	arqA=fopen("A.txt", "r");
	while(!feof(arqA)){
		fscanf(arqA, "%d", &vetorA[i]);
		i++;
	}
	fclose(arqA);
	printf("\nArquivo A lido.");
	//Leitura B
	i=0;
	arqB=fopen("B.txt", "r");
	while(!feof(arqB)){
		fscanf(arqB, "%d", &vetorB[i]);
		i++;
	}
	fclose(arqB);
	printf("\nArquivo B lido.");
	//Leitura C
	i=0;
	arqC=fopen("C.txt", "r");
	while(!feof(arqC)){
		fscanf(arqC, "%d", &vetorC[i]);
		i++;
	}
	fclose(arqC);
	printf("\nArquivo C lido.");
	//Leitura D
	i=0;
	arqD=fopen("D.txt", "r");
	while(!feof(arqD)){
		fscanf(arqD, "%d", &vetorD[i]);
		i++;
	}
	fclose(arqD);
	printf("\nArquivo D lido.");
}

//Ordenação utilizando QuickSort
void ordenaQuick(int vetor[], int ini, int fim){
	int pivo;
	if(ini<fim){
		pivo=particiona(vetor, ini, fim);
		ordenaQuick(vetor, ini, pivo-1);
		ordenaQuick(vetor, pivo+1, fim);
	}
}

int particiona(int vetor[], int ini, int fim){
	int pivo=vetor[ini], i=ini, j, aux;
	for(j = ini+1; j <= fim; j++){
		if(vetor[j] >= pivo){
			i++;
			aux=vetor[i]; 
			vetor[i]=vetor[j]; 
			vetor[j]=aux; 
		}
	}
	aux=vetor[i]; 
	vetor[i]=vetor[ini]; 
	vetor[ini]=aux;

	return i;
}

//Impressão dos vetores já ordenados no novo arquivo.
void imprimeVetorOrdenado(int vetorA[], int vetorB[], int vetorC[], int vetorD[], FILE *arqSaida){
	int i;
	//Imprime A
	arqSaida=fopen("QuickOrdenado-A.txt", "w");
	for(i=0; i<A; i++){
		fprintf(arqSaida, "%d ", vetorA[i]);
	}
	fclose(arqSaida);
	printf("\nArquivo A impresso.");

	//Imprime B
	arqSaida=fopen("QuickOrdenado-B.txt", "w");
	for(i=0; i<B; i++){
		fprintf(arqSaida, "%d ", vetorB[i]);
	}
	fclose(arqSaida);
	printf("\nArquivo B impresso.");

	//Imprime C
	arqSaida=fopen("QuickOrdenado-C.txt", "w");
	for(i=0; i<C; i++){
		fprintf(arqSaida, "%d ", vetorC[i]);
	}
	fclose(arqSaida);
	printf("\nArquivo C impresso.");

	//Imprime D
	arqSaida=fopen("QuickOrdenado-D.txt", "w");
	for(i=0; i<D; i++){
		fprintf(arqSaida, "%d ", vetorD[i]);
	}
	fclose(arqSaida);
	printf("\nArquivo D impresso.");

}
//Funções de início e fim do cálculo de tempo
void inicioTempo(float *timer){
	*timer = clock();
}

void fimTempo(float timer){
	timer = clock() - timer;
	printf("\nOrdenado em %0.3f segundos.", (timer/CLOCKS_PER_SEC));
}
