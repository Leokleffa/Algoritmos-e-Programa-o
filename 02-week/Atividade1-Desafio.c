//Leonardo Kauer Leffa

#include<stdio.h>
#include<math.h>
#include<locale.h>

int main()
{
    float x1, x2, x3, y1, y2, y3, dist12, dist13, dist23, semiperimetro;
    float area;

    setlocale(LC_ALL,"Portuguese");

    printf("Informe as coordenadas x e, após o espaço, y do ponto 1:");
    scanf("%f %f", &x1, &y1);
    printf("\n");
    printf("Informe as coordenadas x e, após o espaço, y do ponto 2:");
    scanf("%f %f", &x2, &y2);
    printf("\n");
    printf("Informe as coordenadas x e, após o espaço, y do ponto 3:");
    scanf("%f %f", &x3, &y3);
    printf("\n");

    dist12=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
    dist13=sqrt(pow(x1-x3,2)+pow(y1-y3,2));
    dist23=sqrt(pow(x2-x3,2)+pow(y2-y3,2));

    semiperimetro=(dist12+dist13+dist23)/2;

    area=sqrt(abs(semiperimetro*(dist12-semiperimetro)*(dist13-semiperimetro)*(dist23-semiperimetro))); //fórmula de Heron

    if(area==0)
    {
        printf("Os pontos P1, P2 e P3 não formam um triângulo.");
    }
    else
    {
        printf("Área do triângulo: %.2f em unidades de área", area);
    }
    return 0;
}

/*Escrever um programa que lê um conjunto de 6 valores:
X1, Y1,
X2, Y2,
X3, Y3,

que representam as coordenadas cartesianas de 3 pontos: P1(X1, Y1), P2(X2, Y2), P3(X3, Y3).
Calcule a distância euclidiana entre P1 e P2, P1 e P3, P2 e P3.
A distância euclidiana entre um par de pontos (cada qual com suas coordenadas x e y) é
determinada pela seguinte fórmula:

d(P1,P2) = √[(X 1−X2)^2+(Y 1−Y 2)^2]

Se os segmentos de reta formam um triângulo, calcular e escrever a área deste triângulo.

Exemplo de execução:
Informe as coordenadas x e y do ponto 1: 0.0 0.0
Informe as coordenadas x e y do ponto 2: 10.0 0.0
Informe as coordenadas x e y do ponto 3: 5.0 5.0
Área do triângulo: 25.0*/
