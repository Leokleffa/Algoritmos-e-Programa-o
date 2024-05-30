//Leonardo Kauer Leffa
/*Esse programa irá fornecer o saldo atualizado de uma conta bancária,
após a realização de uma de 3 operações bancárias possíveis (depósito,
saque ou transferência).

Entrada:o saldo inicial da conta, um código de operação (1- depósito,
2-saque, 3-transferência) e um valor a ser operado (depositado, sacado
ou transferido).

Saída: atualização do saldo da conta.*/


#include<stdio.h>
#include<locale.h>
int main()
{
    int cod, conta;
    float saldo, operacao;

    setlocale(LC_ALL,"");
    printf("Código\t Operação\n");
    printf(" 1\t Depósito\n");
    printf(" 2\t Saque\n");
    printf(" 3\t Transferência\n");
    printf("\n");
    printf("Insira o código da operação desejada:");
    scanf("%d", &cod);
    printf("\n");

    if((cod==1)||(cod==2)||(cod==3))
    {
        printf("Insira o saldo inicial: R$");
        scanf("%f", &saldo);
        printf("\n");
        printf("Insira o valor da operação: R$");
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
            printf("Informe o número da conta destino:");
            scanf("%d", &conta);
            printf("\n");
            printf("R$ %.2f para a conta: %d", operacao, conta);
        }
        else
        {
            printf("saldo insuficiente para realizar a operação\n");
        }

        printf("\nSaldo atual: R$ %.2f", saldo);
    }
    else
    {
        printf("Código inválido!");
    }
    printf("\n");

    return 0;
}
/*2. Escreva um programa que fornece o saldo atualizado de uma conta
bancária, após a realização de uma de 3 operações bancárias possíveis
(depósito, saque ou transferência). O programa receberá, como dados, o
saldo inicial da conta, um código de operação (1- depósito, 2-saque, 3-
transferência) e um valor a ser operado (depositado, sacado ou transferido).
No caso da operação de transferência, o programa também deve ler um
valor inteiro que representa o número da conta para a qual o valor será
transferido (mas nada é feito com este código, no momento). O programa
deve efetuar a operação, atualizando o saldo da conta. Nas operações de
saque e transferência, caso o valor operado seja superior ao saldo, a
operação não é realizada e é exibida uma mensagem informando “saldo
insuficiente para realizar a operação”. O saldo nunca deve ficar negativo por
meio dessas operações.*/
