//Leonardo Kauer Leffa
/*Esse programa exibirá as informações da tabela, irá ler o código de cada produto, irá ler a quantidade do produto, informará o total a pagar e, se necessário, aplicar o desconto
Entrada: código do produto, quantidade do produto a ser comprada.
Saída:valor que o usuário deverá pagar.*/

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

    printf("Código\t Produto\t Valor(un)\n");
    printf("%d\t Pão\t\t R$%.2f\n", 1,val1);
    printf("%d\t Leite(1L)\t R$%.2f\n", 2,val2);
    printf("%d\t Biscoito(300g)\t R$%.2f", 3, val3);
    printf("\n");
    printf("\nInsira o código do produto:");
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

/*1. Você deve desenvolver um programa para processar vendas em um mercado. O
mercado possui os seguintes itens, com os respectivos valores:

Código do produto   Produto             Valor unitário
1                   Pão                 R$ 1,50
2                   Leite (1 L)         R$ 4,65
3                   Biscoito(pct 300g)  R$ 6,93

O mercado oferece 2% de desconto para compras acima de R$ 50,00.
O programa deve exibir as informações da tabela acima para o usuário e pedir para
ele informar o código do produto que deseja e a quantidade. Ao final, o programa
deve informar o valor que o usuário deve pagar (já aplicando o desconto, se for o
caso). O programa só deve lidar com a compra de um único tipo de produto por
execução.*/
