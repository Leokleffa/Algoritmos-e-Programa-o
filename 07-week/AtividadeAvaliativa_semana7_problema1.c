#include<stdio.h>
#include<locale.h>
#include<string.h>
#define P 3
#define F 3
#define TAM 50

int main()
{
    char nome[P][TAM];
    int cod[P], qntd[F][P], p, f, i=0, soma=0, qntdTotal[P]={0};
    float preco[P], media[P];

    setlocale(LC_ALL,"");

    for(p=0;p<P;p++)
    {
        printf("Insira o nome do produto: ");
        fflush(stdin);
        gets(nome[p]);
        printf("Insira código do/a %s: ", nome[p]);
        fflush(stdin);
        scanf("%d", &cod[p]);
        printf("Insira preço do/a %s: ", nome[p]);
        fflush(stdin);
        scanf("%f", &preco[p]);
    }
    for(f=0;f<F;f++)
    {
        for(p=0;p<P;p++)
        {
            printf("Informe a quantidade do produto ( %s) na filial %d: ", nome[p], f);
            fflush(stdin);
            scanf("%d", &qntd[f][p]);
        }

    }
    do{
        printf("Insira o nome do produto: ");
        fflush(stdin);
        gets(nome[P]);
        for(p=0;p<P;p++)
        {
            if(strcasecmp(nome[P],nome[p])==0)
            {
                p=i;
            }
            else
            {
               i=-1;
            }
        }
        if(i==-1)
        {
            printf("Nome de produto inválido!\n");
        }
    }while(i==-1);
    printf("Código: %d \t Preço: %.2f\n", cod[i], preco[i]);

    do{
        printf("Insira o código do produto: ");
        fflush(stdin);
        scanf("%d", &cod[P]);
        for(p=0;p<P;p++)
        {
            if(cod[P]==cod[p])
            {
                p=i;
            }
            else
            {
                i=-1;
            }
        }
        if(i==-1)
        {
            printf("Código do produto inválido!\n");
        }
    }while(i==-1);
    printf("Nome: %s \t Preço: %.2f\n", nome[i], preco[i]);

    printf("Médias de unidades vendidas de cada produto por filial: \n");
    for(p=0;p<P;p++)
    {
        for(f=0;f<F;f++)
        {
            qntdTotal[p]=qntdTotal[p]+qntd[f][p];
        }
        media[p]=(float)qntdTotal[p]/F;
    }

    for(p=0;p<P;p++)
    {
        for(f=0;f<F;f++)
        {
            printf("%s \t Código: %d \t Preço: %.2f \t Média: ", nome[p], cod[p], preco[p], media[p] );
        }
    }

    return 0;
}


/*O mercado das semanas anteriores cresceu e agora se tornou um hipermercado
(vendendo inclusive itens de lojas de departamento),

possuindo F filiais e vendendo P produtos.

Você deve elaborar um programa que auxilie o mercado a analisar as vendas
das filiais do mercado ao final de um mês. Ou seja, o programa só deve lidar com a
quantidade vendida por cada loja de cada produto em um dado mês.

 O programa deve:
 Pedir para o usuário informar o nome (máximo de 50 caracteres) de cada um dos
P produtos da loja.
 Pedir para o usuário informar o preço de cada um dos P produtos. Assuma que o
preço é o mesmo em todas as filiais.
 Pedir para o usuário informar o código de cada um dos P produtos. Assuma que o
código de um produto é o mesmo em todas as filiais.
 Pedir para o usuário informar a quantidade de cada produto que foi vendida por
cada filial no mês.
 Pedir para o usuário informar o nome de um produto e exibir o código e o preço
deste produto. Caso o nome informado seja inválido, o programa deve realizar a
consistência, só prosseguindo quando o usuário informar um nome válido.
 Pedir para o usuário informar um código de produto e exibir na tela o nome do
produto e o total de unidades vendidas deste produto considerando as vendas de
todas as filiais. Se o usuário informar um código inválido, o programa deve
realizar a consistência, só prosseguindo quando o usuário informar um código
válido.
 Determinar e exibir a média de unidades vendidas de cada produto por filial,
exibindo o nome do produto, seu código, seu preço e a média vendida.
 Determinar e exibir o faturamento total de cada filial no mês, considerando o total
de produtos vendidos de cada tipo e seu preço.
 Determinar o produto que representou o maior faturamento (considerando total de
unidades vendidas em todas as lojas e os preços dos produtos) e exibir seu nome e
código e o total faturado com vendas deste produto. Caso mais de um produto
ficar empatado, seu programa deve exibir todos que atingiram esse faturamento
máximo.
Considere, por conveniência, P como 3 e F como 3 também, embora o programa deva
funcionar normalmente (e de forma consistente) caso o valor dessas constantes seja
alterado.*/
