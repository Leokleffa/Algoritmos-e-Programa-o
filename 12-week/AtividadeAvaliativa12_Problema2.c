#include<stdio.h>
#include<locale.h>
#include<string.h>
#define ARQ "funcionários.dat"
#define ATUALIZADOS "atualizados.dat"
#define maxNome 81

typedef struct
{
    char nome[maxNome];
    float salario;
}FUNCIONARIO;

void atualiza(FUNCIONARIO *buffer_funcionario, float percentual)
{
    buffer_funcionario->salario=(buffer_funcionario->salario)*(1+(percentual/100));
}

void linha()
{
    printf("_________________________________\n");
}

int main()
{
    FILE *arquivo, *atualizado;
    FUNCIONARIO buffer_funcionario;
    float percentual;
    char arq_funcionarios[]={ARQ}, arq_atualizados[]={ATUALIZADOS};
    int i,aux;

    setlocale(LC_ALL,"");

    printf("Informe o percentual do aumento salarial: ");
    scanf(" %f", &percentual);

    printf("Funcionários:\n\n");

    do
    {
        if(!(atualizado=fopen(arq_atualizados, "rb+")))
        {
            printf("Erro na abertura do arquivo de escrita!\n");
        }
        else
        {
            if(!(arquivo=fopen(arq_funcionarios, "rb")))
            {
                printf("Erro na abertura do arquivo de leitura!\n");
            }
            else
            {
                if(fread(&buffer_funcionario, sizeof(FUNCIONARIO), 1, arquivo)==1)
                {
                    fseek(arquivo,sizeof(FUNCIONARIO),i*sizeof(FUNCIONARIO));
                    linha();
                    printf("Nome: %s\n", buffer_funcionario.nome);
                    printf("Salário anterior: R$%.2f\n", buffer_funcionario.salario);
                    atualiza(&buffer_funcionario, percentual);
                    printf("Salário atualizado: R$%.2f\n", buffer_funcionario.salario);
                    linha();
                    if(fwrite(&buffer_funcionario.salario, sizeof(FUNCIONARIO), 1, arquivo)==0)
                    {
                        printf("Erro na escrita do salário atualizado!\n");
                    }
                }
                else
                {
                    printf("Erro na leitura!\n");
                }
                fclose(atualizado);
                fclose(arquivo);
            }
        }
    }while(feof(arquivo)!=0);
    return 0;
}
