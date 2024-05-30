#include<stdio.h>
#include<locale.h>
#include<math.h>
#define N 5

float dist(float x1, float y1, float x2, float y2)//calcula a dist�ncia entre dois pontos;
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
    printf(" par de pontos mais distantes entre si � (%.2f, %.2f) e (%.2f, %.2f), cuja dist�ncia � %.2f", xp1, yp1, xp2, yp2, d);
    return 0;
}


/*a. Fa�a uma fun��o que recebe dois vetores de n�meros reais, ambos do mesmo
tamanho, onde o primeiro representa as coordenadas x e o segundo representa
as coordenadas y de um conjunto de pontos. Al�m disso, a fun��o tamb�m
deve receber o tamanho dos vetores como par�metro. A fun��o deve retornar 3
informa��es: p1, p2 e d; onde p1 e p2 s�o respectivamente as posi��es de dois
pontos nos vetores recebidos que s�o os que est�o mais distantes entre si; e d
representa a dist�ncia entre eles. A fun��o deve utilizar ponteiros para retornar
as posi��es dos pontos e deve retornar a dist�ncia via return. Considere a
utiliza��o de outras fun��es auxiliares para estruturar o programa (a habilidade
de decomposi��o em fun��es ser� avaliada). Caso existam mais de dois pontos
que estejam a esta dist�ncia m�xima, basta que a fun��o identifique um dos
pares.

b. O programa principal deve preencher os dois vetores de tamanho N,
requisitando informa��es do usu�rio para as coordenadas x e y de cada ponto.
A seguir, o programa deve utilizar a fun��o acima para identificar o par de
pontos mais distantes entre si no conjunto informado, bem como a dist�ncia
entre eles e exibir na tela as coordenadas dos pares de pontos identificados,
bem como a dist�ncia entre eles. Assuma N como 5 por conveni�ncia, mas o
programa deve funcionar para qualquer valor de N. Voc� pode usar este site
para calcular online a dist�ncia entre pontos bidimensionais.*/
