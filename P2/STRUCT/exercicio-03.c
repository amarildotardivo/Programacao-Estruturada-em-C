#include <stdio.h>
#include <math.h>

#define pontos 2

typedef struct coordenadas{
    int x;
    int y;
}tipo_coord;

void preencheCoord(tipo_coord* coord);
int distancia(tipo_coord* coord);

int main(){
    tipo_coord coord[pontos];
    int resultado;

    preencheCoord(coord);

    resultado = distancia(coord);

    printf("\nA distancia entre os pontos e de: %d!\n\n", resultado);

    return 0;
}

void preencheCoord(tipo_coord* coord){
    int i;

    for(i = 0; i < pontos; i++){
        printf("\nDigite o numero de x e depois de y da coordenada(%d):\n", i + 1);
        scanf("%d", &coord[i].x);
        scanf("%d", &coord[i].y);
    }
}

int distancia(tipo_coord* coord){
    int i, x, y;
    float distancia;

    x = pow( (coord[1].x - coord[0].x), 2 );
    y = pow( (coord[1].y - coord[0].y), 2  );

    distancia = sqrt( x + y );

    return distancia;
}