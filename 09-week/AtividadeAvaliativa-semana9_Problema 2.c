//Leonardo Kauer Leffa
/*Esse programa calcula as coordenadas da centroide de um retângulo.
Entrada: coordenadas do ponto inferior esquerdo do retângulo e do ponto superior direito do retângulo;
Saída: coordenadas da centroide.*/
#include<stdio.h>
#include<locale.h>

void centroide(float x1, float y1, float x2, float y2, float *px, float *py) //calcula as coordenadas do centroide;
{
    *px=(x1+x2)/2;
    *py=(y1+y2)/2;
}

int main(void)
{
    float x1, y1, x2, y2, xc, yc, *px, *py;

    setlocale(LC_ALL,"");

    printf("Informe as coordenadas do ponto inferior esquerdo do retângulo: ");
    scanf(" %f %f", &x1, &y1);
    printf("Informe as coordenadas do ponto superior direito do retângulo: ");
    scanf(" %f %f", &x2, &y2);
    px=&xc;
    py=&yc;
    centroide(x1, y1, x2, y2, px, py);
    printf("O ponto centroide tem coordenadas x=%.2f e t=%.2f", *px, *py);
}
