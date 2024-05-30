#include<stdio.h>
#include<locale.h>
#include<string.h>
#define ARQ "funcion�rios.dat"
#define maxNome 81

typedef struct
{
    char nome[maxNome];
    float salario;
}FUNCIONARIO;

void menu()
{
    printf("Incluir novo funcion�rio (1) ou sair (2)?\n");
}

int cadastrar(char nome_arq[], FUNCIONARIO *funcionario, int qntd)
{
    FILE *arquivo;
    int estado=0;
    if(!(arquivo=fopen(nome_arq,"rb+")))
    {
        printf("Erro na abertura!\n");
    }
    if(!(fwrite(funcionario, sizeof(FUNCIONARIO),1, arquivo))){
        printf("Erro de escrita\n");
        estado=0;
    }
    else{
        estado=1;
    }
    fclose(arquivo);
    return estado;
}

int main()
{
    FUNCIONARIO buffer_funcionario;
    char nomeArq[]={ARQ};
    int opcao,qntd=0;

    setlocale(LC_ALL,"");
    do{
        menu();
        scanf(" %d", &opcao);
        if(opcao==1)
        {
            do{
                printf("Informe o nome: ");
                getchar();
                gets(buffer_funcionario.nome);
                if(strlen(buffer_funcionario.nome)==0)
                {
                    printf("Nome inv�lido!\n");
                }
            }while(strlen(buffer_funcionario.nome)==0);
            do{
                printf("Informe o sal�rio: R$");
                scanf("%f", &buffer_funcionario.salario);
                if(buffer_funcionario.salario<=0)
                {
                    printf("Sal�rio inv�lido!\n");
                }
                else
                {
                    qntd++;
                    cadastrar(nomeArq, &buffer_funcionario,qntd);
                }
            }while(buffer_funcionario.salario<=0);
        }
        else if(opcao!=2)
        {
            printf("Op��o inv�lida!\n");
        }
        qntd++;
    }while(opcao!=2);
    printf("Sistema Finalizado");
    return 0;
}
