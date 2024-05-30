//Leonardo Kauer Leffa
/*Esse programa ir� fornecer o saldo atualizado de uma conta banc�ria,
ap�s a realiza��o de uma de 3 opera��es banc�rias poss�veis (dep�sito,
saque ou transfer�ncia).

Entrada:o saldo inicial da conta, um c�digo de opera��o (1- dep�sito,
2-saque, 3-transfer�ncia) e um valor a ser operado (depositado, sacado
ou transferido).

Sa�da: atualiza��o do saldo da conta.*/


#include<stdio.h>
#include<locale.h>
int main()
{
    int cod, conta;
    float saldo, operacao;

    setlocale(LC_ALL,"");
    printf("C�digo\t Opera��o\n");
    printf(" 1\t Dep�sito\n");
    printf(" 2\t Saque\n");
    printf(" 3\t Transfer�ncia\n");
    printf("\n");
    printf("Insira o c�digo da opera��o desejada:");
    scanf("%d", &cod);
    printf("\n");

    if((cod==1)||(cod==2)||(cod==3))
    {
        printf("Insira o saldo inicial: R$");
        scanf("%f", &saldo);
        printf("\n");
        printf("Insira o valor da opera��o: R$");
        scanf("%f", &operacao);
        printf("\n");

        if(cod==1)
        {
            saldo=saldo+operacao;
        }
        else if((cod==2)&&(saldo>=operacao))
        {
            saldo=saldo-operacao;
        }
        else if((cod==3)&&(saldo>=operacao))
        {
            saldo=saldo-operacao;
            printf("Informe o n�mero da conta destino:");
            scanf("%d", &conta);
            printf("\n");
            printf("R$ %.2f para a conta: %d", operacao, conta);
        }
        else
        {
            printf("saldo insuficiente para realizar a opera��o\n");
        }

        printf("\nSaldo atual: R$ %.2f", saldo);
    }
    else
    {
        printf("C�digo inv�lido!");
    }
    printf("\n");

    return 0;
}
/*2. Escreva um programa que fornece o saldo atualizado de uma conta
banc�ria, ap�s a realiza��o de uma de 3 opera��es banc�rias poss�veis
(dep�sito, saque ou transfer�ncia). O programa receber�, como dados, o
saldo inicial da conta, um c�digo de opera��o (1- dep�sito, 2-saque, 3-
transfer�ncia) e um valor a ser operado (depositado, sacado ou transferido).
No caso da opera��o de transfer�ncia, o programa tamb�m deve ler um
valor inteiro que representa o n�mero da conta para a qual o valor ser�
transferido (mas nada � feito com este c�digo, no momento). O programa
deve efetuar a opera��o, atualizando o saldo da conta. Nas opera��es de
saque e transfer�ncia, caso o valor operado seja superior ao saldo, a
opera��o n�o � realizada e � exibida uma mensagem informando �saldo
insuficiente para realizar a opera��o�. O saldo nunca deve ficar negativo por
meio dessas opera��es.*/
