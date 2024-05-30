//Leonardo Kauer Leffa
/*Esse programa identifica a posição de n pontos em relação à circunferência.
Entrada: raio, coordenadas do centro da circunferência e quantidade de pontos a serem analisados.
Saída: A posição relativa à circunferência.*/
#include<stdio.h>
#include<locale.h>
#include<math.h>
#define N 100

float distancia(float x, float y, float xc, float yc)
{
    return sqrt(pow((x-xc),2)+pow((y-yc),2));
}

float DouFouB(float xc, float yc, float r, float x, float y)
{
    if(r>distancia(x,y,xc,yc))
        return -1;
    else if(r==distancia(x,y,xc,yc))
        return 0;
    else if(r<distancia(x,y,xc,yc))
        return 1;
}

int main(void)
{
    int n, i, teste;
    float r, xc, yc, x[N], y[N], dist[N];
    setlocale(LC_ALL,"");

    printf("Informe o raio do círculo: ");
    scanf(" %f", &r);
    printf("Informe as coordenadas x e y, respectivamente, do centro da circunferência: ");
    scanf(" %f %f", &xc, &yc);
    do{
        printf("Informe a quantidade de pontos que deseja avaliar: ");
        scanf("%d", &n);
        if((n<1)||(n>N))
            printf("Quantidade inválida!\n"); //Se não estiver entre 1 e 100, então é inválido
    }while((n<1)||(n>N));

    for(i=0;i<n;i++)
    {
        printf("Informe as coordenadas x e y, respectivamente, do ponto %d: ", i+1);
        scanf(" %f %f", &x[i], &y[i]);
        teste=DouFouB(xc,yc, r, x[i], y[i]);
        switch(teste)
        {
            case -1: printf("O ponto está dentro do círculo!\n");
                     break;
            case 0: printf("O ponto está na borda do círculo!\n");
                     break;
            case 1: printf("O ponto está fora do círculo!\n");
                     break;
        }
    }

}
