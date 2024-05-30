//Leonardo Kauer Leffa
/*um programa que simula o deslocamento de um objeto
(representado por um par de coordenadas) em um espaço retangular.
Entrada: as coordenadas cartesianas dos pontos P1(x1,y1), P2(x2,y2) e P3(x3,y3),
um valor positivo que representa o passo de deslocamento e uma direção de
deslocamento e efetuar o deslocamento do objeto, alterando e informando a sua nova
posição.
Saída: a posição atual do objeto e quantos movimentos o objeto realizou para sair
do perímetro.*/

#include<stdio.h>
#include<locale.h>
#include<ctype.h>

int main()
{
    char comando;
    int qntdMov;
    float x1, x2, y1, y2, x, y, passo;

    setlocale(LC_ALL,"");

    printf("Informe as coordenadas do ponto P1:");
    scanf("%f %f", &x1, &y1);

    printf("Informe as coordenadas do ponto P2:");
    scanf(" %f %f", &x2, &y2);

    if((x1<x2)&&(y1<y2))
    {
        printf("Informe as coordenadas do objeto:");
        scanf(" %f %f", &x, &y);

        if((x>=x1)&&(x<=x2)&&(y>=y1)&&(y<=y2))
        {
            printf("Informe o passo de deslocamento:");
            scanf(" %f", &passo);

            if(passo>0)
            {
                while((x>=x1)&&(x<=x2)&&(y>=y1)&&(y<=y2))
                {
                    printf("Informe a direção:");
                    scanf(" %c", &comando);
                    printf("\n");
                    comando=toupper(comando);
                    switch(comando)
                    {
                        case 'A': x=x-passo;
                                break;
                        case 'D': x=x+passo;
                                break;
                        case 'S': y=y-passo;
                                break;
                        case 'W': y=y+passo;
                                break;
                        default: printf("Direção inválida\n");
                    }

                    if((comando=='A')||(comando=='D')||(comando=='S')||(comando=='W'))
                    {
                        printf("Nova posição: (%.2f,%.2f)\n", x, y);
                    }
                    qntdMov++;
                }
                printf("O objeto saiu do perímetro definido realizando %d movimentos.\n", qntdMov);
            }
            else
            {
                printf("O passo deve ser maior do que zero!");
            }
        }
        else
        {
            printf("As coordenadas iniciais do objeto devem permanecer no perímetro definido pelo retângulo\n");
        }
    }
    else
    {
        printf("As coordenadas x e y de P2 devem ser maiores que as coordenadas x e y de P1!\n");
    }

    return 0;
}

/*Você deve elaborar um programa que simula o deslocamento de um objeto
(representado por um par de coordenadas) em um espaço retangular. O programa deve
inicialmente ler 4 valores reais que representam respectivamente as coordenadas
cartesianas dos pontos P1(x1,y1) e P2(x2,y2). Onde P1 representa o ponto do canto
inferior esquerdo de um retângulo e P2 representa o ponto superior direito deste
retângulo. Logo, as coordenadas x e y de P2 devem ser maiores que as coordenadas x e y
de P1, respectivamente. A seguir, o programa deve ler dois valores que representam as
coordenadas de um ponto P3(x3,y3), que representa a posição inicial deste objeto. A
seguir, o programa deve ler um valor positivo que representa o passo de deslocamento. A
seguir, o programa deve continuamente pedir para o usuário informar uma direção de
deslocamento e efetuar o deslocamento do objeto, alterando e informando a sua nova
posição. O programa deve finalizar quando o objeto sair do perímetro definido pelo
retângulo, exibindo uma mensagem que indica isso. Assuma que para sair do perímetro, o
objeto deve ter uma posição fora dos limites. Se estiver exatamente sobre o limite ele é
considerado dentro do perímetro. As direções são representadas pelas seguintes teclas:
 A(a): anda para a esquerda, conforme o passo definido.
 D(d): anda para a direita, conforme o passo definido.
 S(s): anda para baixo, conforme o passo definido.
 W(w): anda para a cima, conforme o passo definido.
Caso o usuário informe uma direção inválida o programa deve informar isso e continuar
a execução exibindo a posição atual e executando a próxima iteração.
Caso o usuário informe algum dos valores inciais (P1,P2,P3 e passo, inválidos, o
programa deve ser encerrado, com uma mensagem informando que aquela informação é
inválida). Não é necessário deixar o programa repetindo para coletar as informações
válidas.
Ao fim do programa, ele deve informar quantos movimentos o objeto realizou para sair
do perímetro.*/
