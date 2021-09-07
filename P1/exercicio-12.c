/*
12) Faça um algoritmo que leia uma frase (considerando os espaços) com no máximo 50 caracteres e imprima
esta mesma frase sem os espaços. Crie e utilize dois procedimentos: um para ler a frase e outro para a
impressão da mesma sem os espaços.
*/
#include <stdio.h>

#define tam 50

void preencheFrase(char *frase);
void imprimiFraseSemEspaco(char *frase);

int main(){
    char frase[tam];

    preencheFrase(frase);
    imprimiFraseSemEspaco(frase);

    return 0;
}
void preencheFrase(char *frase){
    printf("Escreva uma frase:\n");
    scanf("%[^\n]", frase);
}
void imprimiFraseSemEspaco(char *frase){
    int i, tamFrase;
    
    tamFrase = strlen(frase);

    for(i = 0; i < tamFrase; i++){
        if(frase[i] != ' '){
            printf("%c", frase[i]);
        }
    }
}