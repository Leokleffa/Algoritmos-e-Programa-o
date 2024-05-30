//Leonardo Kauer Leffa
/*É um sistema para gerenciar contas bancárias
Entrada: saldos iniciais, códigos de operação, códigos de contas para o fluxo e o valor a ser movimentado;
Saída: Atualização da conta de acordo com os comandos.*/

#include<stdio.h>
#include<locale.h>
#define QTD 3

int main()
{
    int i, codConta,codOp, codDestino;
    float saldo[QTD], valor;

    setlocale(LC_ALL,"");

    for(i=0;i<QTD;i++)
    {
        printf("Informe o saldo inicial da conta de código %d:", i);
        scanf("%f", &saldo[i]);
    }
    printf("\n");
    do{
            printf("Opção\t operação\n");
            printf("0\t sair do sistema\n");
            printf("1\t saldo\n");
            printf("2\t depósito\n");
            printf("3\t saque\n");
            printf("4\t transferência\n");
            printf("\n");
            printf("Informe a opção desejada:");
            scanf("%d", &codOp);
            switch(codOp)
            {
                case 0: break;
                case 1: printf("Informe o código da conta:");
                        scanf(" %d", &codConta);
                        if((codConta>=0)&&(codConta<=QTD))
                        {
                            printf("saldo atual da conta %d é R$ %.2f \n", codConta, saldo[codConta]);
                        }
                        else
                        {
                            printf("Código inválido!\n");
                        }
                        break;
                case 2: printf("Informe o código da conta:");
                        scanf(" %d", &codConta);
                        if((codConta>=0)&&(codConta<=QTD))
                        {
                            printf("Informe o valor a ser depositado na conta %d:", codConta);
                            scanf(" %f", &valor);
                            if(valor>0)
                            {
                                saldo[codConta]=saldo[codConta]+valor;
                                printf("Operação efetuada com sucesso!\n");
                                printf("saldo atual da conta %d é R$%.2f \n", codConta, saldo[codConta]);
                            }
                            else
                            {
                                printf("Valor inválido!\n");
                            }
                        }
                        else
                        {
                            printf("Código inválido!\n");
                        }
                        break;
                case 3: printf("Informe o código da conta:");
                        scanf(" %d", &codConta);
                        if((codConta>=0)&&(codConta<=QTD))
                        {
                            printf("Informe o valor a ser sacado na conta %d:", codConta);
                            scanf(" %f", &valor);
                            if(valor>0)
                            {
                                if((valor<saldo[codConta])&&(valor>0))
                                {
                                    saldo[codConta]=saldo[codConta]-valor;
                                    printf("Operação efetuada com sucesso!\n");
                                    printf("saldo atual da conta %d é R$%.2f \n", codConta, saldo[codConta]);
                                }
                                else
                                {
                                    printf("Saldo insuficiente!\n");
                                }
                            }
                            else
                            {
                                printf("Valor inválido!\n");
                            }
                        }
                        else
                        {
                            printf("Código inválido!\n");
                        }
                        break;
                case 4: printf("Informe o código da conta de origem:");
                        scanf(" %d", &codConta);
                        if((codConta>=0)&&(codConta<=QTD))
                        {
                           printf("Informe o código da conta de destino:");
                           scanf(" %d", &codDestino);
                           if((codDestino>=0)&&(codDestino<=QTD)&&(codDestino!=codConta))
                           {
                               printf("Informe o valor a ser transferido: ");
                               scanf(" %f", &valor);
                               if(valor>0)
                               {
                                   if(valor<saldo[codConta])
                                   {
                                        saldo[codConta]=saldo[codConta]-valor;
                                        saldo[codDestino]=saldo[codDestino]+valor;
                                        printf("Operação efetuada com sucesso!\n");
                                        printf("saldo atual da conta %d (origem) é R$ %.2f \n", codConta, saldo[codConta]);
                                   }
                                   else
                                   {
                                       printf("Saldo insuficiente!\n");
                                   }
                                }
                                else
                                {
                                    printf("Valor inválido!\n");
                                }
                           }
                           else
                           {
                               printf("Código de destino inválido!\n");
                           }
                        }
                        else
                        {
                            printf("Código de origem inválido!\n");
                        }
                        break;
                default: printf("Opção inválida!\n");
            }
            printf("\n");
    }while(codOp!=0);
    printf("sistema finalizado!\n");
    return 0;
}


/*Você deve desenvolver um sistema para gerenciar contas bancárias.
Suponha que o banco tenha QTD contas. Assuma que QTD seja 3 por conveniência, embora o programa
deva funcionar para qualquer valor de QTD (utilize constante nomeada, ou seja #define
QTD 3).

Os saldos das contas são representados por vetores de números reais.
O código de cada conta é a posição do vetor.
O programa deve inicialmente ler os saldos iniciais das contas bancárias.
A seguir, ele deve continuamente ler uma das opções e efetuar a x'operação correspondente:

0-Sair do sistema: O programa para de ler opções e exibe a mensagem “sistema
finalizado”.

1-Saldo: O programa deve ler o código da conta a informar o saldo da conta. Caso
o código seja inválido, deve-se informar isso e voltar a exibir o menu de opções.

2-Depósito: O programa deve ler o código da conta e um valor maior que zero
para depositar, efetuar a operação, atualizar o saldo e exibir o novo saldo. Caso o
código ou o valor sejam inválidos deve-se exibir uma mensagem informando isso e
voltar a exibir o menu de opções.

3-Saque: O programa deve ler o código da conta e um valor maior que zero para
sacar, efetuar a operação, atualizar o saldo e exibir o novo saldo. Caso o saldo seja
insuficiente, deve-se informar isso sem efetivar o saque, e voltar a exibir o menu
de opções. Caso o código ou o valor sejam inválidos deve-se exibir uma mensagem
informando isso e voltar a exibir o menu de opções.

4-Transferência: O programa deve ler o código da conta de origem, o código da
conta de destino e um valor maior que zero para transferir, efetuar a operação,
atualizar os saldos de ambas as contas e exibir o novo saldo da conta de origem.
Caso o saldo da conta de origem seja insuficiente, deve-se informar isso, sem
efetivar a transferência, e voltar a exibir o menu de opções. Caso os códigos ou o
valor sejam inválidos deve-se exibir uma mensagem informando isso e voltar a
exibir o menu de opções.*/
