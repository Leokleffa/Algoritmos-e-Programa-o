
//Leonardo Kauer Leffa
/*Esse programa irá converter a temperatura de celsius para fahrenheit ou vice-versa, converter milímetro para polegada ou vice-versa.
Entrada: código do comando e valor a ser convertido.
Saída: conversão.*/

#include<stdio.h>
#include<locale.h>

int main()
{
    char cod;
    float valor;
    float conv;
    setlocale(LC_ALL,"");
    printf("código\t conversão\n");
    printf("C\t °C para °F\n");
    printf("F\t °F para °C\n");
    printf("m\t mm para inch\n");
    printf("P\t inch para mm\n");
    printf("t\t para encerrar o programa\n");
    printf("\n");

    printf("Insira o código da operação:");
    scanf("%c", &cod);
    printf("\n");

    if((cod=='t')||(cod=='T'))
    {
    return 0;
    }
    else
    {
    printf("Insira o valor:");
    scanf(" %f", &valor);

    switch(cod)
    {
        case 'C': conv=32+(9*valor)/5;
                printf("Conversão: %.2f", conv);
                break;
        case 'c': conv=32+(9*valor)/5;
                printf("Conversão: %.2f", conv);
                break;
        case 'F': conv=(5*(valor-32)/9);
                printf("Conversão: %.2f", conv);
                break;
        case 'f': conv=(5*(valor-32)/9);
                printf("Conversão: %.2f", conv);
                break;
        case 'M': conv=valor/25,4;
                printf("Conversão: %.2f", conv);
                break;
        case 'm': conv=valor/25,4;
                printf("Conversão: %.2f", conv);
                break;
        case 'P': conv=valor*25,4;
                printf("Conversão: %.2f", conv);
                break;
        case 'p': conv=valor*25,4;
                printf("Conversão: %.2f", conv);
                break;
        default:printf("Código errado!");
                return 0;
    }
    }
    return 0;
}

/*Tendo como dados de entrada o tipo de conversão desejada (1-
temperaturas, 2 – unidades de medidas, 3 - encerrar o programa) e
unidade (C para Celcius, F para Fahrenheit, P para polegadas e M
para milímetros) e valor a ser convertido (admitindo aqui também a
opção de encerrar programa), efetuar o atendimento da ação
solicitada. Por exemplo, se o usuário selecionar 1 na primeira opção,
isso indica que ele quer converter temperaturas, se ele informar a
seguir C e 36, significa que ele quer converter 36 graus Celcius para
Fahrenheit. Caso ele tivesse informado F e 36, isso indicaria que ele
quer converter 36 graus Fahrenheit para Celcius.*/
