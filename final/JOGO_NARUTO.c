//Leonardo Kauer Leffa.

#include<stdio.h>
#include<time.h>
#include<conio2.h>
#include<windows.h>
#include<math.h>
#include<string.h>

#define LINHA 23
#define COLUNA 61
#define MAXNINJA 20
#define NOMEMAX 20
#define MAXCHAVE 10
#define MAXVIDA 3

int vida=MAXVIDA;
int continua;
int qntdShuriken=0;
int qntdNinja=0;
int qntdChaves=0;
int pontuacao=0;
int totalChave=MAXCHAVE;
int level=0;
char map[LINHA][COLUNA]; //matriz do tipo char para o mapa .

typedef struct
{
    int x, y;
    int xinicial, yinicial;
}POSICAO;
typedef struct
{
    POSICAO ninja[MAXNINJA];
    POSICAO player;
    POSICAO shuriken;
}DINAMICOS;

int lerMapa(char nomeArq[], DINAMICOS *elementos) //abertura, leitura e inicializa��es das vari�veis do mapa.
{
    FILE *arq;
    int estado=0;
    int i,j;

    totalChave=0;
    qntdNinja=0;
    if(!(arq=fopen(nomeArq, "r")))
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
                map[i][j]=getc(arq);
                switch(map[i][j])
                {
                    case 'J':
                            elementos->player.x=j;
                            elementos->player.y=i;
                            elementos->player.xinicial=j;
                            elementos->player.yinicial=i;
                            break;
                    case 'N':
                            elementos->ninja[qntdNinja].x=j;
                            elementos->ninja[qntdNinja].y=i;
                            elementos->ninja[qntdNinja].xinicial=j;
                            elementos->ninja[qntdNinja].yinicial=i;
                            qntdNinja=qntdNinja+1;
                            break;
                    case 'C':
                            totalChave=totalChave+1;
                            break;
                }
            }
        }
        fclose(arq);
    }
    return estado;
}

void inicializacao()// fun��o para de menu ao iniciar o jogo colorido simples
{
    system("cls");
    printf("\n\n");
    textcolor(CYAN);
    printf("\tNaruto, que eh controlado pelo jogador, tem como objetivo recuperar um antigo e importante pergaminho da aldeia da folha,\n");
    Sleep(1000);
    textcolor(GREEN);
    printf("\tque foi roubado e se encontra dentro de um bau numa fortaleza repleta de ninjas foras da lei.\n");
    Sleep(1000);
    textcolor(YELLOW);
    printf("\tAlem dos ninjas, ainda existem armadilhas de espinhos na fortaleza.\n");
    Sleep(1000);
    textcolor(MAGENTA);
    printf("\tO nosso personagem dispoe de shurikens espalhadas pelo seu caminho que podem ser arremessadas para causar danos nos inimigos a sua volta.\n");
    Sleep(1000);
    textcolor(CYAN);
    printf("\tTente sobreviver, recuperar o pergaminho roubado e fugir da fortaleza.\n\n\n");
    Sleep(1000);
    textcolor(RED);
    printf("\tAperte 'ENTER' para comecar o jogo\n");
    getchar(); // fun��o para pegar o ENTER e assim come�ar o jogo.
    system("cls");
}

void draw() // fun��o que desenha os itens de mapa e as estatisticas de jogo.
{
    int i, j;

    system("cls");
    for(i=0; i<LINHA; i++)// codigo definido para desenhar apenas at� linha a at� 23.
    {
        for(j=0; j<COLUNA; j++)// codigo definido para desenhar apenas at� a coluna 61.
        {
            switch(map[i][j])
            {
                case ' ':
                case 'n': printf(" "); //usado na mudan�a de posi��o dos ninjas.
                          break;
                case '#': textcolor(WHITE); // cores pra deixar o mapa melhor apresentavel.
                          printf("%c", 219);
                          break;
                case 'J': textcolor(YELLOW);
                          printf("%c", 207);
                          textcolor(WHITE);
                          break;
                case 'N': textcolor(BLUE);
                          printf("%c", 254);
                          textcolor(WHITE);
                          break;
                case 'X': textcolor(RED);
                          printf("%c", 30);
                          textcolor(WHITE);
                          break;
                case 'C': textcolor(LIGHTGREEN);
                          printf("C");
                          textcolor(WHITE);
                          break;
                case 'Z': textcolor(LIGHTGRAY);
                          printf("%c", 15);
                          textcolor(WHITE);
                          break;
                case 'v': textcolor(LIGHTGRAY); //shuriken em movimento
                          printf("%c", 15);
                          textcolor(WHITE);
                          break;
            }
        }
        printf("\n");
    }
    printf("Nivel %d\n", level+1);
    printf("Pontuacao: %d\n", pontuacao);
    printf("Vidas: ");
    for(i=0;i<vida;i++)//representa quantas vidas restam
    {
        textcolor(RED);
        printf("%c", 3);
        textcolor(WHITE);
    }
    printf("\t Shurikens: %d ", qntdShuriken);
    for(i=0;i<qntdShuriken;i++)//representa quantas shurikens prontas para serem lan�adas
    {
        textcolor(LIGHTGRAY);
        printf("%c", 15); //estilo mais estilizado para aparecer um elemento da tabela ascii que representa as shurikens.
        textcolor(WHITE);
    }
    printf("\t Chaves: %d ", qntdChaves);
    for(i=0;i<qntdChaves;i++) //representa quantas chaves coletadas
    {
        textcolor(YELLOW);
        printf("C"); //estilo mais estilizado para aparecer um elemento da tabela ascii que representa as chaves do mapa.
        textcolor(WHITE);
    }
}

void playerShuriken(DINAMICOS *elementos, int memx, int memy) // fun��o para o movimento da shuriken do plauer e caso acerte algum ninja inimigo.
{
    if(qntdShuriken>0)
    {
        elementos->shuriken.x=elementos->player.x+memx;
        elementos->shuriken.y=elementos->player.y+memy;
        qntdShuriken--;
        if(map[elementos->shuriken.y+memy][elementos->shuriken.x+memx]==' '||map[elementos->shuriken.y+memy][elementos->shuriken.x+memx]=='n')
        {
            map[elementos->shuriken.y][elementos->shuriken.x]='v';
            draw();
            map[elementos->shuriken.y][elementos->shuriken.x]=' ';
            draw();
            while(map[elementos->shuriken.y+memy][elementos->shuriken.x+memx]==' '||map[elementos->shuriken.y+memy][elementos->shuriken.x+memx]=='n')
            {
                elementos->shuriken.x=elementos->shuriken.x+memx;
                elementos->shuriken.y=elementos->shuriken.y+memy;
            }
            map[elementos->shuriken.y][elementos->shuriken.x]='v';
            draw();
            map[elementos->shuriken.y][elementos->shuriken.x]=' ';
        }
        if(map[elementos->shuriken.y+memy][elementos->shuriken.x+memx]=='N') //caso acerte algum ninja a pontua��o aumenta e o ninja � derrotado
        {
            pontuacao+=20;// soma de 20 pontos para cada inimigo morto pelo jogador.
            map[elementos->shuriken.y+memy][elementos->shuriken.x+memx]=' ';
        }
    }
}

void controle(char keypress, int x, int y, int *dx, int *dy, int *memx, int *memy, DINAMICOS *elementos) //fun��o dos controles do jogador e fun��es de teclado.
{
    char buffer;
    int i;
    *dx=0; //deslocamento x para cada tecla pressionada
    *dy=0; //deslocamento y para cada tecla pressionada
    if((GetAsyncKeyState(VK_LEFT)||keypress=='a'||keypress=='A')&&map[y][x-1]!='#'){ //seta para esquerda ou a letra A para esquerda com fun��o de impacto com a parede '#'.
        switch(map[y][x-1])
        {
            case 'X':
            case 'N': vida--; // se o ninja atacar ou o jogador passar por uma armadilha, perde uma vida e os elementos din�micos voltam as posi��es iniciais.
                      map[elementos->player.y][elementos->player.x]=' ';
                      elementos->player.x=elementos->player.xinicial;
                      elementos->player.y=elementos->player.yinicial;
                      map[elementos->player.y][elementos->player.x]='J';
                      for(i=0;i<qntdNinja; i++)
                      {
                          if(map[elementos->ninja[i].y][elementos->ninja[i].x]=='N')
                          {
                              map[elementos->ninja[i].y][elementos->ninja[i].x]='n';
                              elementos->ninja[i].x=elementos->ninja[i].xinicial;
                              elementos->ninja[i].y=elementos->ninja[i].yinicial;
                              map[elementos->ninja[i].y][elementos->ninja[i].x]='N';
                          }
                      }
                      break;
            case 'C': pontuacao+=50; //soma mais 50 na pontua��o das chaves
                      qntdChaves++; // aumenta o valor da chaves coletadas
            default: *dx=-1;
                     *dy=0;
                     *memx=-1; //mem�ria do movimento x para as shurikens
                     *memy=0; //mem�ria do movimento x para as shurikens
                     break;
        }
    }
    else if((GetAsyncKeyState(VK_UP)||keypress=='w'||keypress=='W')&&map[y-1][x]!='#') //seta para cima ou a letra A para cima.
    {
        switch(map[y-1][x])
        {
            case 'X':
            case 'N': vida--;
                      map[elementos->player.y][elementos->player.x]=' ';
                      elementos->player.x=elementos->player.xinicial;
                      elementos->player.y=elementos->player.yinicial;
                      map[elementos->player.y][elementos->player.x]='J';
                      for(i=0;i<qntdNinja; i++)
                      {
                          if(map[elementos->ninja[i].y][elementos->ninja[i].x]=='N')
                          {
                              map[elementos->ninja[i].y][elementos->ninja[i].x]='n';
                              elementos->ninja[i].x=elementos->ninja[i].xinicial;
                              elementos->ninja[i].y=elementos->ninja[i].yinicial;
                              map[elementos->ninja[i].y][elementos->ninja[i].x]='N';
                          }
                      }
                      break;
            case 'C': pontuacao+=50;
                      qntdChaves++;
            default: *dx=0;
                     *dy=-1;
                     *memx=0;
                     *memy=-1;
                     break;
        }
    }
    else if((GetAsyncKeyState(VK_RIGHT)||keypress=='d'||keypress=='D')&&map[y][x+1]!='#') //seta para direita ou a letra D para direita
    {
        switch(map[y][x+1])
        {
            case 'X':
            case 'N': vida--;
                      map[elementos->player.y][elementos->player.x]=' ';
                      elementos->player.x=elementos->player.xinicial;
                      elementos->player.y=elementos->player.yinicial;
                      map[elementos->player.y][elementos->player.x]='J';
                      for(i=0;i<qntdNinja; i++)
                      {
                          if(map[elementos->ninja[i].y][elementos->ninja[i].x]=='N')
                          {
                              map[elementos->ninja[i].y][elementos->ninja[i].x]='n';
                              elementos->ninja[i].x=elementos->ninja[i].xinicial;
                              elementos->ninja[i].y=elementos->ninja[i].yinicial;
                              map[elementos->ninja[i].y][elementos->ninja[i].x]='N';
                          }
                      }
                      break;
            case 'C': pontuacao+=50;
                      qntdChaves++;
            default: *dx=1;
                     *dy=0;
                     *memx=1;
                     *memy=0;
                     break;
        }
    }
    else if((GetAsyncKeyState(VK_DOWN)||keypress=='s'||keypress=='S')&&map[y+1][x]!='#') //seta para baixo ou a letra S para baixo
    {
        switch(map[y+1][x])
        {
            case 'X':
            case 'N': vida--;
                      map[elementos->player.y][elementos->player.x]=' ';
                      elementos->player.x=elementos->player.xinicial;
                      elementos->player.y=elementos->player.yinicial;
                      map[elementos->player.y][elementos->player.x]='J';
                      for(i=0;i<qntdNinja; i++)
                      {
                          if(map[elementos->ninja[i].y][elementos->ninja[i].x]=='N')
                          {
                              map[elementos->ninja[i].y][elementos->ninja[i].x]='n';
                              elementos->ninja[i].x=elementos->ninja[i].xinicial;
                              elementos->ninja[i].y=elementos->ninja[i].yinicial;
                              map[elementos->ninja[i].y][elementos->ninja[i].x]='N';
                          }
                      }
                      break;
            case 'C': pontuacao+=50;
                      qntdChaves++;
            default: *dx=0;
                     *dy=1;
                     *memx=0;
                     *memy=1;
                     break;
        }
    }
    else if(GetAsyncKeyState(VK_TAB)) //pause dentro do jogo
    {
        system("cls");
        buffer=' ';
        do{
            printf("N - novo jogo\n");
            printf("V - voltar\n");
            printf("Q - sair do jogo\n");
            scanf(" %c", &buffer);

            switch(buffer){
               case 'n': continua=-1; break;
               case 'N': continua=-1; break;
               case 'q': continua=0; break;
               case 'Q': continua=0; break;
               case 'v': break;
               case 'V': break;
               default: buffer=' '; break;
            }
        }while(buffer==' ');
    }
}

void Player(DINAMICOS *elementos, int dx, int dy) //fun��o respons�vel pelo movimento do player
{
    map[elementos->player.y][elementos->player.x]=' ';
    if(map[elementos->player.y+dy][elementos->player.x+dx]=='Z')
        qntdShuriken++;
    elementos->player.x=elementos->player.x+dx;
    elementos->player.y=elementos->player.y+dy;
    map[elementos->player.y][elementos->player.x]='J';

}

void Ninja(DINAMICOS *elementos)// fun��o para o ninja se movimentar sozinho de forma aleatoria e atacar o player quando poss�vel.
{
    int i, j, aux1, aux2, varredorax, varredoray;

    for(i=0;i<qntdNinja;i++)// limitado a 20 ninjas inimigos
    {
        if(map[elementos->ninja[i].y][elementos->ninja[i].x]=='N')
        {
            aux1=(int)pow(-1,(rand()%2))*rand()%2; //aritm�tica modular, rand()%2 resultar� em 0 ou 1
            aux2=(int)pow(-1,(rand()%2))*rand()%2; //fun��o pow � respons�vel pelo sinal do deslocamento
            if(map[elementos->ninja[i].y+aux1][elementos->ninja[i].x+aux2]==' '||map[elementos->ninja[i].y+aux1][elementos->ninja[i].x+aux2]=='n')
            {
                map[elementos->ninja[i].y][elementos->ninja[i].x]=' ';
                elementos->ninja[i].x=elementos->ninja[i].x+aux2;
                elementos->ninja[i].y=elementos->ninja[i].y+aux1;
                map[elementos->ninja[i].y][elementos->ninja[i].x]='N';
                varredorax=elementos->ninja[i].x;
                varredoray=elementos->ninja[i].y;
                while(map[varredoray+aux1][varredorax+aux2]==' ')//detecta quando encontra algo diferente do espa�o ' '
                {
                    varredoray+=aux1;
                    varredorax+=aux2;
                }
                if(map[varredoray+aux1][varredorax+aux2]=='J')//detecta se vai acertar a shuriken no player
                {
                    vida--; //analogo ao sistema de perda de vida da fun��o controle
                    map[elementos->ninja[i].y+aux1][elementos->ninja[i].x+aux2]='v';
                    draw();
                    map[elementos->ninja[i].y+aux1][elementos->ninja[i].x+aux2]=' ';
                    draw();
                    map[varredoray+aux1][varredorax+aux2]='v';
                    draw();
                    map[varredoray+aux1][varredorax+aux2]==' ';
                    map[elementos->player.y][elementos->player.x]=' ';
                    elementos->player.x=elementos->player.xinicial;
                    elementos->player.y=elementos->player.yinicial;
                    map[elementos->player.y][elementos->player.x]='J';
                    for(j=0;j<qntdNinja; j++)
                    {
                        if(map[elementos->ninja[j].y][elementos->ninja[j].x]=='N')
                        {
                            map[elementos->ninja[j].y][elementos->ninja[j].x]='n';
                            elementos->ninja[j].x=elementos->ninja[j].xinicial;
                            elementos->ninja[j].y=elementos->ninja[j].yinicial;
                            map[elementos->ninja[j].y][elementos->ninja[j].x]='N';
                        }
                    }
                    break;
                }
            }
        }
    }
}

void gameOver()//fun��o para caso perca o jogo.
{
    system("cls");
    printf("\n\n\n");
    textcolor(RED);
    printf("\t\t\tGAME OVER!\n\n\n");
    textcolor(WHITE);
    printf("\t\tAperte 'Enter' para sair");
    getchar();
}

void winner()// fun��o para caso ganhe o jogo.
{
    system("cls");
    printf("\n\n\n");
    textcolor(RED);
    printf("\t\t\tWINNER!\n\n\n");
    textcolor(WHITE);
    printf("\t\tAperte 'Enter' para sair");
    getchar();
}

void menuContinua()// fun��o para recome�ar ou sair quando acaba o jogo.
{
    printf("Aperte: \n");
    printf("1 - Recomecar \n");
    printf("2 - Sair \n");
    scanf(" %d", &continua);
}

int main()
{
    DINAMICOS elementos;
    char keypress, auxLevel[10], arqMap[NOMEMAX]={"mapa1.txt"}; // string que puxa a o arquivo do mapa.
    int  i,LevelAux;
    int  dx=0, dy=0, memx, memy;

    do{
        vida=MAXVIDA;
        level=0;
        qntdNinja=0;
        qntdShuriken=0;
        qntdChaves=0;
        pontuacao=0;
        continua=1;
        totalChave=MAXCHAVE;
        inicializacao();
        while(vida>=0 && continua==1)// continua apenas se tiver vidas
        {
            if(lerMapa(arqMap, &elementos)==0)//leitura do mapa
                break;
            else
            {
                srand(time(NULL));
                draw();
                while(vida>=0&&totalChave-qntdChaves!=0&&continua==1)
                {
                    if(kbhit()){ //caso pressione alguma tecla
                        keypress=getch();
                    }
                    else{
                        keypress=' ';
                    }
                    controle(keypress, elementos.player.x, elementos.player.y, &dx, &dy, &memx, &memy, &elementos);
                    if(GetAsyncKeyState(VK_SPACE)) //se apertar espa�o e tiver no invent�rio, o player lan�ar� uma shuriken
                        playerShuriken(&elementos, memx, memy);
                    Player(&elementos, dx, dy);
                    Ninja(&elementos);
                    Sleep(100);
                    draw();
                }
                if(totalChave-qntdChaves==0)
                {
                    level++;// fun��o para caso tenha mapas disponiveis carregar.
                    LevelAux=level+1;
                    itoa(LevelAux, auxLevel, 10); //inteiro para string
                    strcpy(arqMap, "mapa");  // passa "mapa" para a string arqMap
                    strcat(arqMap, auxLevel);  //concatena o numero do mapa para a string arqMap
                    strcat(arqMap, ".txt");  //concatena a extens�o do mapa para a string arqMap
                    qntdChaves=0;
                }
            }
        }
        if(vida<=0)// perdeu
        {
            gameOver();
            menuContinua();
        }

        else if(continua!=-1&&continua!=0)// ganhou
        {
            winner();
            menuContinua();
        }
    }while(continua==1 || continua==-1);// fun��o para recome�ar ou sair quando acaba o jogo.
    return 0;
}
