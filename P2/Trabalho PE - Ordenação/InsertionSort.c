//Grupo: Amarildo Junior, Leonardo, Elias Junior
//InsertionSort Ordenado de maneira Não Crescente
#include <stdio.h>
#include <time.h>
#define A 5000
#define B 10000
#define C 20000
#define D 30000

void lerVetor(FILE *arqA, FILE *arqB, FILE *arqC, FILE *arqD, int vetorA[], int vetorB[], int vetorC[], int vetorD[]);
void ordenaInsertion(int vetor[], int tam);
void imprimeVetorOrdenado(int vetorA[], int vetorB[], int vetorC[], int vetorD[], FILE *arqSaida);

void inicioTempo(float *timer);
void fimTempo(float timer);

int main(){
	FILE *arqA, *arqB, *arqC, *arqD, *arqSaida;
	int vetorA[A], vetorB[B], vetorC[C], vetorD[D];
	float timer;
	//Leitura dos arquivos
	lerVetor(arqA, arqB, arqC, arqD, vetorA, vetorB, vetorC, vetorD);
	//Ordenação dos vetores lidos
	printf("\nVetor A:");
	inicioTempo(&timer);
	ordenaInsertion(vetorA, A);
	fimTempo(timer);
	
	printf("\nVetor B:");
	inicioTempo(&timer);
	ordenaInsertion(vetorB, B);
	fimTempo(timer);
	
	printf("\nVetor C:");
	inicioTempo(&timer);
	ordenaInsertion(vetorC, C);
	fimTempo(timer);
	
	printf("\nVetor D:");
	inicioTempo(&timer);
	ordenaInsertion(vetorD, D);
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

//Ordenação utilizando InsertionSort
void ordenaInsertion(int vetor[], int tam){
	int i, j, aux, valor;
	for(i=0;i<tam;i++){
		valor=vetor[i];
		for(j=i-1;(j>=0)&&(valor>vetor[j]);j--){
			vetor[j+1]=vetor[j];
		}
		vetor[j+1]=valor;
	}
}

//Impressão dos vetores já ordenados no novo arquivo.
void imprimeVetorOrdenado(int vetorA[], int vetorB[], int vetorC[], int vetorD[], FILE *arqSaida){
	int i;
	//Imprime A
	arqSaida=fopen("InsertionOrdenado-A.txt", "w");
	for(i=0; i<A; i++){
		fprintf(arqSaida, "%d ", vetorA[i]);
	}
	fclose(arqSaida);
	printf("\nArquivo A impresso.");

	//Imprime B
	arqSaida=fopen("InsertionOrdenado-B.txt", "w");
	for(i=0; i<B; i++){
		fprintf(arqSaida, "%d ", vetorB[i]);
	}
	fclose(arqSaida);
	printf("\nArquivo B impresso.");

	//Imprime C
	arqSaida=fopen("InsertionOrdenado-C.txt", "w");
	for(i=0; i<C; i++){
		fprintf(arqSaida, "%d ", vetorC[i]);
	}
	fclose(arqSaida);
	printf("\nArquivo C impresso.");

	//Imprime D
	arqSaida=fopen("InsertionOrdenado-D.txt", "w");
	for(i=0; i<D; i++){
		fprintf(arqSaida, "%d ", vetorD[i]);
	}
	fclose(arqSaida);
	printf("\nArquivo D impresso.");

}
//Funções de Início e fim do calculo de tempo
void inicioTempo(float *timer){
	*timer = clock();
}

void fimTempo(float timer){
	timer = clock() - timer;
	printf("\nOrdenado em %0.3f segundos.", (timer/CLOCKS_PER_SEC));
}
