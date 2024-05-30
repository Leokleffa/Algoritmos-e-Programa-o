#include<stdio.h>
#include<locale.h>
#include<math.h>
#define N 5

float dist(float x1, float y1, float x2, float y2)//calcula a distância entre dois pontos;
{
    float d;
    d=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    return sqrt(d);
}
float maiorDist(float x[], float y[], int tamanho, float *xp1, float *yp1, float *xp2, float *yp2)
{
    int i,j;
    float d;

    d=dist(x[0], y[0], x[1], y[1]);
    *xp1=x[0];
    *yp1=y[0];
    *xp2=x[1];
    *yp2=y[1];
    for(i=0;i<tamanho;i++)
    {
        for(j=0;j<tamanho;j++)
        {
            if(i!=j)
            {
                if(d<dist(x[i], y[i], x[j], y[j]))
                {
                    d=dist(x[i], y[i], x[j], y[j]);
                    *xp1=x[i];
                    *yp1=y[i];
                    *xp2=x[j];
                    *yp2=y[j];
                }
            }
        }
    }
    return d;
}

int main()
{
    int i,j;
    float xp1, yp1, xp2, yp2, d, x[N], y[N];

    setlocale(LC_ALL,"");

    for(i=0;i<N;i++)
    {
        printf("Informe as coordenadas x e y do ponto %d:", i+1);
        scanf(" %f %f", &x[i],&y[i]);
    }
    d=maiorDist(&x[0], &y[0], N, &xp1, &yp1, &xp2, &yp2);
    printf(" par de pontos mais distantes entre si é (%.2f, %.2f) e (%.2f, %.2f), cuja distância é %.2f", xp1, yp1, xp2, yp2, d);
    return 0;
}


/*a. Faça uma função que recebe dois vetores de números reais, ambos do mesmo
tamanho, onde o primeiro representa as coordenadas x e o segundo representa
as coordenadas y de um conjunto de pontos. Além disso, a função também
deve receber o tamanho dos vetores como parâmetro. A função deve retornar 3
informações: p1, p2 e d; onde p1 e p2 são respectivamente as posições de dois
pontos nos vetores recebidos que são os que estão mais distantes entre si; e d
representa a distância entre eles. A função deve utilizar ponteiros para retornar
as posições dos pontos e deve retornar a distância via return. Considere a
utilização de outras funções auxiliares para estruturar o programa (a habilidade
de decomposição em funções será avaliada). Caso existam mais de dois pontos
que estejam a esta distância máxima, basta que a função identifique um dos
pares.

b. O programa principal deve preencher os dois vetores de tamanho N,
requisitando informações do usuário para as coordenadas x e y de cada ponto.
A seguir, o programa deve utilizar a função acima para identificar o par de
pontos mais distantes entre si no conjunto informado, bem como a distância
entre eles e exibir na tela as coordenadas dos pares de pontos identificados,
bem como a distância entre eles. Assuma N como 5 por conveniência, mas o
programa deve funcionar para qualquer valor de N. Você pode usar este site
para calcular online a distância entre pontos bidimensionais.*/
