//Leonardo Kauer Leffa
/*Esse programa
Entrada: as popula��es de acordo com o c�digo de cada munic�pio.
Sa�da*/
#include<stdio.h>
#include<locale.h>

int main()
{
    int cod1, cod2, cod3, popRef, pop1, pop2, pop3;
    float media;


    setlocale(LC_ALL,"");
    printf("Entre com o c�digo do primeiro munic�pio:");
    scanf("%d", &cod1);
    printf("Entre com a popula��o do primeiro munic�pio:");
    scanf("%d", &pop1);
    printf("\n");

    printf("Entre com o c�digo do segundo munic�pio:");
    scanf("%d", &cod2);
    printf("Entre com a popula��o do segundo munic�pio:");
    scanf("%d", &pop2);
    printf("\n");

    printf("Entre com o c�digo do terceiro munic�pio:");
    scanf("%d", &cod3);
    printf("Entre com a popula��o do terceiro munic�pio:");
    scanf("%d", &pop3);
    printf("\n");

    printf("Informe o valor de refer�ncia:");
    scanf("%d", &popRef);
    printf("\n");

    if((pop1>popRef)||(pop2>popRef)||(pop3>popRef))
    {
        if(pop1>popRef)
        {
            printf("\n O munic�pio de c�digo %d possui popula��o acima de %d \n", cod1, popRef);
        }
        if(pop2>popRef)
        {
            printf("\n O munic�pio de c�digo %d possui popula��o acima de %d \n", cod2, popRef);
        }
        if(pop3>popRef)
        {
            printf("\n O munic�pio de c�digo %d possui popula��o acima de %d \n", cod3, popRef);
        }
    }
    else
    {
        printf("\n Nenhum munic�pio apresenta uma popula��o maior do que a %d.\n", popRef);
    }
    printf("\n");
    media=(pop1+pop2+pop3)/3;
    printf("\n A popula��o media dos tr�s munic�pios � %.2f habitantes\n", media);

    if(pop1>media)
    {
        printf("\n O munic�pio de c�digo %d possui popula��o maior do que a m�dia\n", cod1);
    }
    else
    {
        printf("\n O munic�pio de c�digo %d possui popula��o menor ou igual a m�dia\n", cod1);
    }
    if(pop2>media)
    {
        printf("\nO munic�pio de c�digo %d possui popula��o maior do que a m�dia\n", cod2);
    }
    else
    {
        printf("\n O munic�pio de c�digo %d possui popula��o menor ou igual a m�dia\n", cod2);
    }
    if(pop3>media)
    {
        printf("\n O munic�pio de c�digo %d possui popula��o maior do que a m�dia\n", cod3);
    }
    else
    {
        printf("\n O munic�pio de c�digo %d possui popula��o menor ou igual a m�dia\n", cod3);
    }

    printf("\n");

    return 0;
}


/*1. Escreva, diretamente em C, um programa que siga os passos indicados
no algoritmo abaixo, relacionado a estat�sticas populacionais:

1 Leia os c�digos identificadores (inteiros) e a popula��o de 3 munic�pios.

2 Leia um valor de refer�ncia 3 Escreva os c�digos dos munic�pios que tem
uma popula��o maior que o valor de refer�ncia. Caso n�o existam, o programa
deve informar isso.

4 Calcule e escreva a m�dia das popula��es dos 3 munic�pios.

5 Imprima na tela os c�digos dos munic�pios com popula��o menor ou
igual � m�dia.

6 Imprima na tela os c�digos dos munic�pios com popula��o maior do
que m�dia. */
