//Leonardo Kauer Leffa

#include<stdio.h>
#include<locale.h>
void coeficientes(float xmaior, float ymaior, float xmenor, float ymenor, float *coefAng, float *coefLinear)
{
    xmaior=(ymaior-ymenor)/(xmaior-xmenor);
    *coefAng=xmaior;
    printf("%f\n", *coefAng);
    *coefLinear=ymaior-xmaior*xmaior;
    printf("%f\n", *coefLinear);
}
int main()
{
    float x1, y1, x2, y2, xmaior, xmenor, ymaior, ymenor, ang=0, linear=0;

    printf("Insira as coordenadas do ponto 1: ");
    fflush(stdin);
    scanf("%f%f", &x1, &y1);
    do{
        printf("Insira as coordenadas do ponto 2: ");
        fflush(stdin);
        scanf(" %f%f", &x2, &y2);
        if(x1==x2&&y1==y2)
        {
            printf("Ponto 1 igual ao ponto 2.\n");
        }
    }while(x1==x2&&y1==y2);
        if(x1==x2)
        {
            printf("Não é possível determinar seus coeficientes, pois assume a forma x=%.2f.", x1);
        }
    else
    {
        if(x1>x2)
        {
            x1=xmaior;
            y1=ymaior; //não necessariamente o y será maior, mas ele se refere ao xmaior.
            x2=xmenor;
            y2=ymenor;
        }
        else
        {
            x2=xmaior;
            y2=ymaior; //não necessariamente o y será maior, mas ele se refere ao xmaior.
            x1=xmenor;
            y1=ymenor;
        }
        coeficientes(xmaior, ymaior, xmenor, ymenor, &ang, &linear);
        printf("Coeficiente angular: %f \t Coeficiente linear: %f\n", ang, linear);
        printf("Equação da reta: y=%.2fx+%.2f", ang, linear);
    }
    return 0;
}
