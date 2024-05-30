#include<stdio.h>
#include<locale.h>
#define NUMNINJA 1 //número de ninjas

typedef struct
{
    int Xse, Yse;
}CANTOSE;
typedef struct
{
    int Xid, Yid;
}CANTOID;
typedef struct
{
    CANTOSE cantose;
    CANTOID cantoid;
}LIMITES;

typedef struct
{
    int x, y;
}POSICAO;
typedef struct
{
    int deltaX, deltaY;
}DESLOCAMENTO;
typedef struct
{
    POSICAO posicao;
    DESLOCAMENTO desloc;
}NINJA;

void lerLimitesMap(LIMITES *limMap)
{
    printf("Informe a posição do canto superior esquerdo do mapa: ");
    scanf(" %d%d", &limMap->cantose.Xse, &limMap->cantose.Yse);
    do{
        printf("Informe a posição do canto inferior direito do mapa: ");
        scanf(" %d%d", &limMap->cantoid.Xid, &limMap->cantoid.Yid);
        if(limMap->cantoid.Xid<=limMap->cantose.Xse||limMap->cantoid.Yid<=limMap->cantose.Yse)
        {
            printf("Coordenada inválida!\n");
        }
    }while(limMap->cantoid.Xid<=limMap->cantose.Xse||limMap->cantoid.Yid<=limMap->cantose.Yse);
}

void lerPosicaoNinja(NINJA *ninja, LIMITES *limMap)
{
    do{
        printf("Informe as coordenadas x e y da posição do ninja:");
        scanf(" %d%d",&ninja->posicao.x, &ninja->posicao.y);
        if((ninja->posicao.x<limMap->cantose.Xse||ninja->posicao.x>limMap->cantoid.Xid)||(ninja->posicao.y<limMap->cantose.Yse||ninja->posicao.y>limMap->cantoid.Yid))
        {
            printf("Coordenada inválida!\n");
        }
    }while((ninja->posicao.x<limMap->cantose.Xse||ninja->posicao.x>limMap->cantoid.Xid)||(ninja->posicao.y<limMap->cantose.Yse||ninja->posicao.y>limMap->cantoid.Yid));
}

void lerDeslocamento(NINJA *ninja)
{
    do{
        printf("Informe os deslocamentos do ninja em x e y:");
        scanf(" %d%d", &ninja->desloc.deltaX, &ninja->desloc.deltaY);
        if(ninja->desloc.deltaX == 0 && ninja->desloc.deltaY == 0 || ninja->desloc.deltaX != 1 && ninja->desloc.deltaX != 0 && ninja->desloc.deltaX != -1 || ninja->desloc.deltaY != 1 && ninja->desloc.deltaY != 0 && ninja->desloc.deltaY != -1)
        //(ninja->desloc.deltaX==0&&ninja->desloc.deltaY==0)||(ninja->desloc.deltaX!=-1&&ninja->desloc.deltaX!=0&&ninja->desloc.deltaX!=1)||(ninja->desloc.deltaY!=-1&&ninja->desloc.deltaY!=0&&ninja->desloc.deltaX!=1)
        {
            printf("Deslocamento inválido!\n");
        }
    }while(ninja->desloc.deltaX == 0 && ninja->desloc.deltaY == 0 || ninja->desloc.deltaX != 1 && ninja->desloc.deltaX != 0 && ninja->desloc.deltaX != -1 || ninja->desloc.deltaY != 1 && ninja->desloc.deltaY != 0 && ninja->desloc.deltaY != -1);
}
int moveNinja(NINJA *ninja, LIMITES *limMap)
{
    if((ninja->posicao.x>limMap->cantose.Xse&&ninja->posicao.x<limMap->cantoid.Xid)&&(ninja->posicao.y>limMap->cantose.Yse&&ninja->posicao.y<limMap->cantoid.Yid))
    {
        ninja->posicao.x=ninja->posicao.x+ninja->desloc.deltaX;
        ninja->posicao.y=ninja->posicao.y+ninja->desloc.deltaY;
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int continua=1, qntdPassos=0, i;
    NINJA ninja[NUMNINJA];
    LIMITES limMap;
    setlocale(LC_ALL,"");

    lerLimitesMap(&limMap);
    for(i=0;i<NUMNINJA;i++)
    {
        printf("Ninja %d\n", i+1);
        lerPosicaoNinja(&ninja[i], &limMap);
        lerDeslocamento(&ninja[i]);
    }
    printf("Ninja se movendo...\n");
    for(i=0;i<NUMNINJA;i++)
    {
        continua=1;
        qntdPassos=0;
        while(continua==1){
            continua=moveNinja(&ninja[i], &limMap);
            if(continua==1)
            {
                qntdPassos++;
                printf("Posição do ninja %d depois do passo %d: (%d,%d)\n", i+1, qntdPassos, ninja[i].posicao.x, ninja[i].posicao.y);
            }
            else
            {
                printf("O ninja %d deu %d passos antes de encontrar o limite.\n\n", i+1,qntdPassos);
            }
        }
    }
    return 0;
}
