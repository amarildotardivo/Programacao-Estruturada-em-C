//Grupo: Amarildo Junior, Leonardo, Elias Junior
#include <stdio.h>
#include <time.h>
#define A 5000
#define B 10000
#define C 20000
#define D 30000

void geraA(FILE *arqSaida);
void geraB(FILE *arqSaida);
void geraC(FILE *arqSaida);
void geraD(FILE *arqSaida);

int main(){
	srand(time(NULL));
	FILE *arqSaida;
	geraA(arqSaida);
	geraB(arqSaida);
	geraC(arqSaida);
	geraD(arqSaida);
	
	return 0;
}

void geraA(FILE *arqSaida){
	int vetor[A], i;
	for(i=0; i<A; i++){
		vetor[i]=rand()%10000+1;
	}
	printf("\n%d numeros gerados no arquivo A.", i);
	arqSaida=fopen("A.txt", "w");
	for(i=0; i<A; i++){
		fprintf(arqSaida, "%d ", vetor[i]);
	}
	fclose(arqSaida);
	printf("\nArquivo A.txt criado.");
}

void geraB(FILE *arqSaida){
	int vetor[B], i;
	for(i=0; i<B; i++){
		vetor[i]=rand()%10000+1;
	}
	printf("\n%d numeros gerados no arquivo B.", i);
	arqSaida=fopen("B.txt", "w");
	for(i=0; i<B; i++){
		fprintf(arqSaida, "%d ", vetor[i]);
	}
	fclose(arqSaida);
	printf("\nArquivo B.txt criado.");
}

void geraC(FILE *arqSaida){
	int vetor[C], i;
	for(i=0; i<C; i++){
		vetor[i]=rand()%10000+1;
	}
	printf("\n%d numeros gerados no arquivo C.", i);
	arqSaida=fopen("C.txt", "w");
	for(i=0; i<C; i++){
		fprintf(arqSaida, "%d ", vetor[i]);
	}
	fclose(arqSaida);
	printf("\nArquivo C.txt criado.");
}

void geraD(FILE *arqSaida){
	int vetor[D], i;
	for(i=0; i<D; i++){
		vetor[i]=rand()%10000+1;
	}
	printf("\n%d numeros gerados no arquivo D.", i);
	arqSaida=fopen("D.txt", "w");
	for(i=0; i<D; i++){
		fprintf(arqSaida, "%d ", vetor[i]);
	}
	fclose(arqSaida);
	printf("\nArquivo D.txt criado.");
}

