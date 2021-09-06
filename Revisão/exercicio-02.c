#include <stdio.h>
#define tam 5

void preencheVet(int num[]);
void imprimiInverso(int num[]);

int main(){
	
	int num[tam];
	
	preencheVet(num);
	
	imprimiInverso(num);
	
	return 0;
}
void preencheVet(int num[]){
	int i;
	
	printf("entre com 15 numeros: \n");
	for(i = 0; i < tam; i++){
		scanf("%d", &num[i]);
	}
}
void imprimiInverso(int num[]){
	int i;
	
	for(i = tam - 1; i>= 0; i--){
		printf("%d ", num[i]);	
	}
}
