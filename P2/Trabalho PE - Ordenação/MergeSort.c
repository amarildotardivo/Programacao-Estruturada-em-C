//Grupo: Amarildo Junior, Leonardo, Elias Junior
//MergeSort Ordenado de maneira Não Crescente
#include <stdio.h>
#include <time.h>
#define A 5000
#define B 10000
#define C 20000
#define D 30000

void lerVetor(FILE *arqA, FILE *arqB, FILE *arqC, FILE *arqD, int vetorA[], int vetorB[], int vetorC[], int vetorD[]);
void merge(int vetor[], int inicio, int meio, int fim, int temp[]);
void sort(int vetor[], int inicio, int fim, int temp[]);
void imprimeVetorOrdenado(int vetorA[], int vetorB[], int vetorC[], int vetorD[], FILE *arqSaida);

void inicioTempo(float *timer);
void fimTempo(float timer);

int main(){
	FILE *arqA, *arqB, *arqC, *arqD, *arqSaida;
	int vetorA[A], vetorB[B], vetorC[C], vetorD[D], inicio, fim, tempA[A], tempB[B], tempC[C], tempD[D];
	float timer;
	//Leitura dos arquivos
	lerVetor(arqA, arqB, arqC, arqD, vetorA, vetorB, vetorC, vetorD);
	//Ordenação dos vetores lidos
	inicio=0;
	fim=A-1;
	printf("\nVetor A:");
	inicioTempo(&timer);
	sort(vetorA, inicio, fim, tempA);
	fimTempo(timer);

	inicio=0;
	fim=B-1;
	printf("\nVetor B:");
	inicioTempo(&timer);
	sort(vetorB, inicio, fim, tempB);
	fimTempo(timer);

	inicio=0;
	fim=C-1;
	printf("\nVetor C:");
	inicioTempo(&timer);
	sort(vetorC, inicio, fim, tempC);
	fimTempo(timer);

	inicio=0;
	fim=D-1;
	printf("\nVetor D:");
	inicioTempo(&timer);
	sort(vetorD, inicio, fim, tempD);
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

//Ordenação utilizando MergeSort
void merge(int vetor[], int inicio, int meio, int fim, int temp[]) {
	int esquerda, direita, i;

	for(esquerda = inicio, direita = meio + 1, i = inicio; esquerda <= meio && direita <= fim; i++){
		if(vetor[esquerda] > vetor[direita]){
			temp[i] = vetor[esquerda++];
		}else{
			temp[i] = vetor[direita++];
		}
	}

	while(esquerda <= meio){
		temp[i++] = vetor[esquerda++];
	}

	while(direita <= fim){
		temp[i++] = vetor[direita++];
	}

	for(i = inicio; i <= fim; i++){
		vetor[i] = temp[i];
	}
}

void sort(int vetor[], int inicio, int fim, int temp[]){
	int meio;

	if(inicio < fim){
		meio = (inicio + fim)/2;
		sort(vetor, inicio, meio, temp);
		sort(vetor, meio+1, fim, temp);
		merge(vetor, inicio, meio, fim, temp);
	}else{
		return;
	}
}

//Impressão dos vetores já ordenados no novo arquivo.
void imprimeVetorOrdenado(int vetorA[], int vetorB[], int vetorC[], int vetorD[], FILE *arqSaida){
	int i;
	//Imprime A
	arqSaida=fopen("MergeOrdenado-A.txt", "w");
	for(i=0; i<A; i++){
		fprintf(arqSaida, "%d ", vetorA[i]);
	}
	fclose(arqSaida);
	printf("\nArquivo A impresso.");

	//Imprime B
	arqSaida=fopen("MergeOrdenado-B.txt", "w");
	for(i=0; i<B; i++){
		fprintf(arqSaida, "%d ", vetorB[i]);
	}
	fclose(arqSaida);
	printf("\nArquivo B impresso.");

	//Imprime C
	arqSaida=fopen("MergeOrdenado-C.txt", "w");
	for(i=0; i<C; i++){
		fprintf(arqSaida, "%d ", vetorC[i]);
	}
	fclose(arqSaida);
	printf("\nArquivo C impresso.");

	//Imprime D
	arqSaida=fopen("MergeOrdenado-D.txt", "w");
	for(i=0; i<D; i++){
		fprintf(arqSaida, "%d ", vetorD[i]);
	}
	fclose(arqSaida);
	printf("\nArquivo D impresso.");

}
//Funções de início e fim do calculo de tempo
void inicioTempo(float *timer){
	*timer = clock();
}

void fimTempo(float timer){
	timer = clock() - timer;
	printf("\nOrdenado em %0.3f segundos.", (timer/CLOCKS_PER_SEC));
}
