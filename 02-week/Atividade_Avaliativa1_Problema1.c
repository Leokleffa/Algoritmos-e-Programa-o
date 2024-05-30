//Leonardo Kauer Leffa
/*Esse programa exibir� as informa��es da tabela, ir� ler o c�digo de cada produto, ir� ler a quantidade do produto, informar� o total a pagar e, se necess�rio, aplicar o desconto
Entrada: c�digo do produto, quantidade do produto a ser comprada.
Sa�da:valor que o usu�rio dever� pagar.*/

#include<stdio.h>
#include<locale.h>

int main()
{
    int cod, qtd;
    float val1, val2, val3;
    float valor, valorFinal;

    setlocale(LC_ALL,"");

    val1=1.50;
    val2=4.65;
    val3=6.93;

    printf("C�digo\t Produto\t Valor(un)\n");
    printf("%d\t P�o\t\t R$%.2f\n", 1,val1);
    printf("%d\t Leite(1L)\t R$%.2f\n", 2,val2);
    printf("%d\t Biscoito(300g)\t R$%.2f", 3, val3);
    printf("\n");
    printf("\nInsira o c�digo do produto:");
    scanf("%d", &cod);
    printf("\n");
    printf("Insira a quantidade do produto %d:", cod);
    scanf("%d", &qtd);

    if(cod==1)
    {
        valor=val1*qtd;
    }
    if(cod==2)
    {
        valor=val2*qtd;
    }
    if(cod==3)
    {
        valor=val3*qtd;
    }
    if(valor>50)
    {
        valor=(valor*0.98); //desconto
    }
    printf("\n");
    printf("Total a pagar: R$%.2f", valor);
    printf("\n");

    return 0;
}

/*1. Voc� deve desenvolver um programa para processar vendas em um mercado. O
mercado possui os seguintes itens, com os respectivos valores:

C�digo do produto   Produto             Valor unit�rio
1                   P�o                 R$ 1,50
2                   Leite (1 L)         R$ 4,65
3                   Biscoito(pct 300g)  R$ 6,93

O mercado oferece 2% de desconto para compras acima de R$ 50,00.
O programa deve exibir as informa��es da tabela acima para o usu�rio e pedir para
ele informar o c�digo do produto que deseja e a quantidade. Ao final, o programa
deve informar o valor que o usu�rio deve pagar (j� aplicando o desconto, se for o
caso). O programa s� deve lidar com a compra de um �nico tipo de produto por
execu��o.*/
