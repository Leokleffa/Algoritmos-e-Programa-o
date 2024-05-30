//Leonardo Kauer Leffa
/*� um sistema para gerenciar contas banc�rias
Entrada: saldos iniciais, c�digos de opera��o, c�digos de contas para o fluxo e o valor a ser movimentado;
Sa�da: Atualiza��o da conta de acordo com os comandos.*/

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
        printf("Informe o saldo inicial da conta de c�digo %d:", i);
        scanf("%f", &saldo[i]);
    }
    printf("\n");
    do{
            printf("Op��o\t opera��o\n");
            printf("0\t sair do sistema\n");
            printf("1\t saldo\n");
            printf("2\t dep�sito\n");
            printf("3\t saque\n");
            printf("4\t transfer�ncia\n");
            printf("\n");
            printf("Informe a op��o desejada:");
            scanf("%d", &codOp);
            switch(codOp)
            {
                case 0: break;
                case 1: printf("Informe o c�digo da conta:");
                        scanf(" %d", &codConta);
                        if((codConta>=0)&&(codConta<=QTD))
                        {
                            printf("saldo atual da conta %d � R$ %.2f \n", codConta, saldo[codConta]);
                        }
                        else
                        {
                            printf("C�digo inv�lido!\n");
                        }
                        break;
                case 2: printf("Informe o c�digo da conta:");
                        scanf(" %d", &codConta);
                        if((codConta>=0)&&(codConta<=QTD))
                        {
                            printf("Informe o valor a ser depositado na conta %d:", codConta);
                            scanf(" %f", &valor);
                            if(valor>0)
                            {
                                saldo[codConta]=saldo[codConta]+valor;
                                printf("Opera��o efetuada com sucesso!\n");
                                printf("saldo atual da conta %d � R$%.2f \n", codConta, saldo[codConta]);
                            }
                            else
                            {
                                printf("Valor inv�lido!\n");
                            }
                        }
                        else
                        {
                            printf("C�digo inv�lido!\n");
                        }
                        break;
                case 3: printf("Informe o c�digo da conta:");
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
                                    printf("Opera��o efetuada com sucesso!\n");
                                    printf("saldo atual da conta %d � R$%.2f \n", codConta, saldo[codConta]);
                                }
                                else
                                {
                                    printf("Saldo insuficiente!\n");
                                }
                            }
                            else
                            {
                                printf("Valor inv�lido!\n");
                            }
                        }
                        else
                        {
                            printf("C�digo inv�lido!\n");
                        }
                        break;
                case 4: printf("Informe o c�digo da conta de origem:");
                        scanf(" %d", &codConta);
                        if((codConta>=0)&&(codConta<=QTD))
                        {
                           printf("Informe o c�digo da conta de destino:");
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
                                        printf("Opera��o efetuada com sucesso!\n");
                                        printf("saldo atual da conta %d (origem) � R$ %.2f \n", codConta, saldo[codConta]);
                                   }
                                   else
                                   {
                                       printf("Saldo insuficiente!\n");
                                   }
                                }
                                else
                                {
                                    printf("Valor inv�lido!\n");
                                }
                           }
                           else
                           {
                               printf("C�digo de destino inv�lido!\n");
                           }
                        }
                        else
                        {
                            printf("C�digo de origem inv�lido!\n");
                        }
                        break;
                default: printf("Op��o inv�lida!\n");
            }
            printf("\n");
    }while(codOp!=0);
    printf("sistema finalizado!\n");
    return 0;
}


/*Voc� deve desenvolver um sistema para gerenciar contas banc�rias.
Suponha que o banco tenha QTD contas. Assuma que QTD seja 3 por conveni�ncia, embora o programa
deva funcionar para qualquer valor de QTD (utilize constante nomeada, ou seja #define
QTD 3).

Os saldos das contas s�o representados por vetores de n�meros reais.
O c�digo de cada conta � a posi��o do vetor.
O programa deve inicialmente ler os saldos iniciais das contas banc�rias.
A seguir, ele deve continuamente ler uma das op��es e efetuar a x'opera��o correspondente:

0-Sair do sistema: O programa para de ler op��es e exibe a mensagem �sistema
finalizado�.

1-Saldo: O programa deve ler o c�digo da conta a informar o saldo da conta. Caso
o c�digo seja inv�lido, deve-se informar isso e voltar a exibir o menu de op��es.

2-Dep�sito: O programa deve ler o c�digo da conta e um valor maior que zero
para depositar, efetuar a opera��o, atualizar o saldo e exibir o novo saldo. Caso o
c�digo ou o valor sejam inv�lidos deve-se exibir uma mensagem informando isso e
voltar a exibir o menu de op��es.

3-Saque: O programa deve ler o c�digo da conta e um valor maior que zero para
sacar, efetuar a opera��o, atualizar o saldo e exibir o novo saldo. Caso o saldo seja
insuficiente, deve-se informar isso sem efetivar o saque, e voltar a exibir o menu
de op��es. Caso o c�digo ou o valor sejam inv�lidos deve-se exibir uma mensagem
informando isso e voltar a exibir o menu de op��es.

4-Transfer�ncia: O programa deve ler o c�digo da conta de origem, o c�digo da
conta de destino e um valor maior que zero para transferir, efetuar a opera��o,
atualizar os saldos de ambas as contas e exibir o novo saldo da conta de origem.
Caso o saldo da conta de origem seja insuficiente, deve-se informar isso, sem
efetivar a transfer�ncia, e voltar a exibir o menu de op��es. Caso os c�digos ou o
valor sejam inv�lidos deve-se exibir uma mensagem informando isso e voltar a
exibir o menu de op��es.*/
