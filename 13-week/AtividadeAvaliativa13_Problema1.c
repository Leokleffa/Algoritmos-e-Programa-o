#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<locale.h>
#define LINHA 23
#define COLUNA 61
#define MAXNINJA 20
#define MAXNOME 30

typedef struct
{
    int x;
    int y;
}POSICAO;

typedef struct
{
    POSICAO player;
    POSICAO ninja[MAXNINJA];
}ELEMDINAMICOS;

int leitura(char nomeMap[], ELEMDINAMICOS *elementos, int *numNinja, char map[][COLUNA])
{
    FILE *arq;
    int i, j, estado, qntdNinja=0;
    char buffer;

    if(!(arq=fopen(nomeMap, "r")))
    {
        estado=0;
        printf("Erro ao abrir o arquivo do mapa!\n");
    }
    else
    {
        estado=1;
            for(i=0;i<LINHA;i++)
            {
                for(j=0;j<COLUNA;j++)
                {
                    buffer=getc(arq);
                    if(buffer==' '||buffer=='#'||buffer=='N'||buffer=='J'||buffer=='C'||buffer=='Z'||buffer=='X')
                    {
                        map[i][j]=buffer;
                        switch(map[i][j])
                        {
                            case 'J':
                                    elementos->player.x=j;
                                    elementos->player.y=i;
                                    break;
                            case 'N':
                                    elementos->ninja[qntdNinja].x=j;
                                    elementos->ninja[qntdNinja].y=i;
                                    qntdNinja++;
                                    break;
                        }
                    }
                }
            }
            fclose(arq);
    }
    *numNinja=qntdNinja;
    return estado;
}

void escrita(char nomePosicao[], ELEMDINAMICOS *elementos, int *qntdNinja)
{
    FILE *arquivo;
    int i, numNinja;

    numNinja=*qntdNinja;
    if(!(arquivo=fopen(nomePosicao, "w")))
    {
        printf("Erro na abertura do arquivo de Posição!\n");
    }
    else
    {
        printf("Sucesso na abertura do arquivo de Posição!\n");
        if(fprintf(arquivo, "%s %d %s %d\n", "Posição do jogador:", elementos->player.x, ",", elementos->player.y)<0)
        {
            printf("Erro na gravação da posição do jogador!\n");
        }
        else
        {
            for(i=0;i<numNinja;i++)
            {
                if(fprintf(arquivo, "%s %d %s %d %s %d\n", "Posição do ninja",i+1, ":", elementos->ninja[i].x,",", elementos->ninja[i].y)<0)
                {
                    printf("Erro na gravação da posição do ninja %d\n", i+1);
                }
            }
        }

    }
    fclose(arquivo);
}

int main()
{
    ELEMDINAMICOS elementos;
    char arqMap[MAXNOME]={"mapa.txt"}, arqPosicoes[MAXNOME]={"posicao.txt"}, map[LINHA][COLUNA];
    int i, j, numNinja=0;

    setlocale(LC_ALL,"");
    printf("Nome do arquivo do mapa(mapa1.txt):");
    gets(arqMap);
    printf("Nome do arquivo das posições(posicao.txt):");
    gets(arqPosicoes);

    i=leitura(arqMap, &elementos, &numNinja, map);
    if(i==0)
    {
        printf("Erro na leitura do arquivo do mapa!\n");
    }
    else
    {
        printf("Sucesso na leitura do arquivo do mapa!\n");
        printf("Posição do jogador: (%d, %d)\n\n", elementos.player.x, elementos.player.y);
        for(i=0;i<numNinja;i++)
        {
            printf("Posição do ninja %d: (%d,%d)\n", i+1, elementos.ninja[i].x,elementos.ninja[i].y);
        }
        printf("\n\n");
        for(i=0;i<LINHA;i++)
        {
            for(j=0;j<COLUNA;j++)
            {
                if(map[i][j]==' '||map[i][j]=='#'||map[i][j]=='N'||map[i][j]=='J'||map[i][j]=='C'||map[i][j]=='Z'||map[i][j]=='X')
                {
                    printf("%c", map[i][j]);
                }
            }
            printf("\n");
        }
        escrita(&arqPosicoes[0], &elementos, &numNinja);
    }
    return 0;
}
