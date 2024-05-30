#include<stdio.h>

int main()
{
    int N, i;
    double valor;

    printf("Insira o numero de termos para a aproximacao de pi:");
    scanf("%d", &N);

    valor=0.000;

    for(i=1;i<=N;i=i+2)
    {
        valor=valor+(1.0/i);
        i=i+2;
        valor=valor-(1.0/i);
    }
    valor=valor*4.00;

    printf("%lf", valor);

    return 0;
}
