#include <stdio.h>
#include <string.h>

#define tamFrase 50
#define tamPalavra 10

int main(){
    char frase[tamFrase], palavra[tamPalavra], p[tamPalavra], f[tamFrase];
    int i, j = 0, len, cont = 0, encontrou = 0;

    printf("Entre com a frase: \n");
    scanf(" %[^\n]s", frase);

    printf("Entre com a palavra:\n");
    scanf(" %[^\n]s", palavra);

    len = strlen(frase);

    for(i = 0; i < len; i++){
        if(tolower(frase[i]) == tolower(palavra[j])){
            cont++;
            j++;
            if( cont == strlen(palavra) ){
                encontrou++;
                cont = 0;
                j = 0;
                i--;
            }
        }else{
            cont = 0;
            j = 0;
        }
    }

    printf("\nA palavra %s aparece %d vezes na frase.\n\n", palavra, encontrou);

    return 0;
}