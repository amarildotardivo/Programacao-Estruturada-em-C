#include <stdio.h>
#define tam 15

void imprimiPares(int num[]);
void preencheVet(int num[]);
int main(){
	
	int num[tam];
	
	preencheVet(num);
	
	imprimiPares(num);
	
	return 0;
}
void preencheVet(int num[]){
	int i;
	
	printf("entre com 15 numeros: \n");
	for(i = 0; i < tam; i++){
		scanf("%d", &num[i]);
	}
}
void imprimiPares(int num[]){
	int i;
	
	for(i = 0; i<tam; i += 2){
		printf("%d ", num[i]);	
	}
}
