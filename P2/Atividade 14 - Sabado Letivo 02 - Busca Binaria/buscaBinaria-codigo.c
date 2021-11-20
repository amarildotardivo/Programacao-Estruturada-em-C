#include <stdio.h>
#include <math.h>

int main(){
    int *v, n, elem;

    buscaBinária(v, n, elem);

    return 0;
}

int buscaBinária(int *v, int n, int elem){
    int i, inicio, meio, final;
    inicio = 0;final = n - 1;
    while(inicio <= final){
        meio = (inicio + final) / 2;
        
        if(elem < v[meio]){
            //busca na metade da esqueda: do inicio até o final(que agora é meio - 1)
            final = meio - 1;
        }
        else if(elem > v[meio]){
            //busca na metade da direita: do inicio(que agora é meio + 1) até o final
            inicio = meio + 1;
        }else{
            return meio;
        }
    }
    return -1;//elemento não encontrado
}