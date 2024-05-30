//Leonardo Kauer Leffa
/*É um programa que lê N valores reais e os armazena em um vetor
de N posições, e, assim, faz operações no vetor;
Entrada: valores do vetor e número para a primeira posição;
Saída: a exibição do vetor a cada operação.*/
#include<stdio.h>
#include<locale.h>
#include<math.h>
#define N 10

int main()
{
    int i;
    float valor[N], soma=0, num, media, maisProx, dist;

    setlocale(LC_ALL,"");

    for(i=0;i<N;i++)
    {
        printf("Insira o valor %d:", i+1);
        scanf("%f", &valor[i]);
    }
    printf("\n");
    printf("Exibindo os valores do vetor original:\n");
    for(i=0;i<N;i++)
    {
        printf("%.1f \t", valor[i]);
    }
    printf("\n");
    printf("Informe um valor:");
    scanf("%f", &num);
    printf("Exibindo o novo vetor com deslocamento:\n");
    for(i=N;i>=0;i--)
    {
       if(i!=0)
       {
           valor[i]=valor[i-1];
       }
       else
       {
           valor[0]=num;
       }
    }
    for(i=0;i<N;i++)
    {
        printf("%.1f \t", valor[i]);
    }
    printf("\n");
    printf("Exibindo o novo vetor com substituições:\n");
    for(i=0;i<N;i++)
    {
        if(i%2==1)
        {
            valor[i]=i;
        }
        printf("%.1f \t", valor[i]);
        soma=soma+valor[i];
    }
    printf("\n");
    media=soma/N;
    printf("A média dos elementos do vetor é: %.2f\n", media);
    printf("\n");
    dist=(abs(valor[i]-media));
    for(i=0;i<N;i++)
    {
            if(dist>(abs(valor[i]-media)))
            {
                maisProx=valor[i];
                dist=(abs(valor[i]-media));
            }
            else if(dist==(abs(valor[0]-media)))
            {
                maisProx=valor[0];
            }
    }
    printf("O elemento mais próximo da média é %.1f\n", maisProx);
    return 0;
}


/*Você deve construir um programa que lê N valores reais e os armazena em um vetor
de N posições.
Considere N como 10 (como constante nomeada, ou seja, #define N 10),

mas o programa deve funcionar para qualquer valor de N (caso eu altere o valor da
constante, o programa deve funcionar normalmente).

Alternativamente, você pode preencher este vetor aleatoriamente (pode definir um intervalo de início e fim dos
números se quiser).

A seguir, o programa deve fazer o seguinte (todas as operações são realizadas sobre o mesmo vetor):

 Exibir todos os valores do vetor na mesma linha separados por tabulação (‘\t’).

 Pedir para o usuário ler um novo valor e inserir este valor na primeira posição do
vetor, deslocando todos os elementos para as posições subsequentes
(deslocamento para a direita). O último elemento é perdido. Exibir o vetor
resultante novamente.

 Alterar todos os elementos que estão em posições ímpares do vetor pelo índice da
posição. Ou seja, o elemento que está na posição 1 é substituído por 1, e assim
sucessivamente. Exibir o vetor resultante novamente.

 Calcular e exibir a média dos valores da última versão do vetor.

 Identificar e exibir o valor da última versão do vetor que está mais próximo da
média calculada anteriormente. Caso mais de um elemento satisfaça essa
condição, exibir apenas um deles (mas fique à vontade para exibir todos).*/
