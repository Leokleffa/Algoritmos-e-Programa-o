//Leonardo Kauer Leffa
/*O programa deve processar compras de múltiplos clientes.
Entradas: código de rumo da compra, código do produto e quantidade do produto.
Saída: o programa deve exibir a tabela, o total da
compra individual e, caso ele tenha desconto, informar o total com desconto também,
quantidade de compras realizadas, total faturado no dia e média do valor das compras*/

#include<stdio.h>
#include<locale.h>
#define COD10 2.25
#define COD23 7.65
#define COD8 6.93
#define COD90 30.21
#define COD76 12.33

int main()
{
    int cod, codProd, qntditens, qntdCompradores=0;
    float valor=0, total=0, media;

    setlocale(LC_ALL,"");
    cod=codProd=3;

    do{
        printf("___________________________________________\n");
        printf(" Informe a opção (0-Sair 1-Nova compra):");
        scanf("%d", &cod);
        printf("___________________________________________\n");

        if(cod==1)
        {
            printf("Código\t Produto\t Valor unitário\n");
            printf("10 \t Pão \t\t %.2f\n", COD10);
            printf("23 \t Leite \t\t %.2f\n", COD23);
            printf("8 \t Biscoito \t %.2f\n", COD8);
            printf("90 \t Arroz \t\t %.2f\n", COD90);
            printf("76 \t Feijão \t %.2f\n", COD76);
            printf("\n");
            printf("O mercado oferece 2%% de desconto para compras acima de R$ 100,00.");
            printf("\n");
            printf("\n");

            do
            {
                printf("Informe o código do produto:");
                scanf("%d", &codProd);

                if((codProd==10||codProd==23||codProd==8||codProd==90||codProd==76))
                {
                    do{
                    printf("Informe a quantidade do produto %d: ", codProd);
                    scanf("%d", &qntditens);
                    if(qntditens<=0)
                    {
                        printf("Quantidade inválida!\n");
                    }
                    } while(qntditens<=0);
                    printf("\n");

                    switch(codProd)
                    {
                        case 10:valor=valor+qntditens*COD10;
                            break;
                        case 23:valor=valor+qntditens*COD23;
                            break;
                        case 8:valor=valor+qntditens*COD8;
                            break;
                        case 90:valor=valor+qntditens*COD90;
                            break;
                        case 76:valor=valor+qntditens*COD76;
                            break;
                    }
                }
                else if(codProd!=0)
                {
                    printf("Código inválido!\n");
                    printf("\n");
                }
            }while(codProd!=0);

            qntdCompradores=qntdCompradores+1;
            printf("\n");
            printf("Compra finalizada!\n");
            printf("Total: R$ %.2f\n", valor);

            if(valor>100)
            {
                valor=valor*0.98;//desconto
                printf("Total com desconto: R$ %.2f\n", valor);

            }
            total=total+valor;
                valor=0;
        }
        else if(cod!=0)
        {
            printf("\n");
            printf("Opção inválida!\n");
            printf("\n");
        }
        } while((cod!=0));

    media=total/qntdCompradores;

    printf("\n");
    printf("Caixa fechado!\n \n");
    printf("Estatísticas do dia:\n");
    printf("---Total faturado no dia: R$ %.2f\n", total);
    printf("---Média do valor das compras: R$%.2f\n", media);
    printf("---Quantidade de compras realizadas: %d\n", qntdCompradores);

    return 0;
}


