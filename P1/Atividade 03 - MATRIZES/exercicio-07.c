// m[i][j] == m[j][i]

#include <stdio.h>
#include <time.h>

#define tam 6

void preencheM(int m[][tam]);
int verificaSimetria(int m[][tam]);

int main(){
    int m[tam][tam], resultado;

    //preencheM(m);
    resultado = verificaSimetria(m);

    if(resultado == 1){
        printf("A matriz e simetrica");
    }else{
        printf("A matriz NAO e simetrica");
    }

    return 0;
}

void preencheM(int m[][tam]){
    int i, j;

    srand(time(NULL));

    for(i = 0; i < tam; i++)
        for(j = 0; j < tam; j++){
            m[i][j] = rand() % 50 + 1;
        }
}
int verificaSimetria(int m[][tam]){
    int i, j;
    
    for(i = 0; i < tam - 1; i++){
        for(j = i + 1; j < tam; j++){
            if(m[i][j] != m[j][i]){
                return 0;
            }
        }
    }

    return 1;
}