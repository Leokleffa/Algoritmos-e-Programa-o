//Leonardo Kauer Leffa
#include<stdio.h>
#include<locale.h>
#define N 5

void bubble_sort(int vet[], int n)//Classifica o vetor vet de n posições, em ordem crescente
{
    int i, fim, continua, aux;
    fim=n-1;
    do{
        continua=0; // indica se houve alguma troca nesta passagem
        for (i=0;i<fim;i++)
        {
            if (vet[i]>vet[i+1])
            {
                aux=vet[i];
                vet[i]=vet[i+1];
                vet[i+1]=aux;
                continua=1;
            }
        }
            fim--;
    }while(continua==1); // para quando não houver troca de posicoes
}


int busca_ordenada(int vetor[], int tamanho, int valor){//ordena o vetor em ordem crescente
    int primeiro, ultimo, meio, localizacao=-1;//retorna -1 se não haver o valor no vetor;

    primeiro=0;
    ultimo=tamanho-1;
    meio=(primeiro+ultimo)/2;

    while((primeiro<=ultimo)&&localizacao==-1){
        if(vetor[meio]<valor){
            primeiro=meio+1;
        }
        else if(vetor[meio]>valor){
            ultimo=meio-1;
        }
        else{
            localizacao=meio;//retorna a localização se haver o valor no vetor;
        }
        meio=(primeiro+ultimo)/2;
    }
    return localizacao;
}


int repetidos(int v1[], int v2[], int v3[], int tamanho)
{
    int i, j, k=0, numRepetidos=0, l=0, falsoV3[tamanho], teste=0;

    bubble_sort(&v1[0], tamanho);

    bubble_sort(&v2[0], tamanho);

    for(i=0;i<tamanho;i++){
        if(busca_ordenada(&v2[0], tamanho, v1[i])!=-1){
            falsoV3[k]=v2[busca_ordenada(&v2[0], tamanho, v1[i])];
            k++;
            numRepetidos++;
        }
    }

    bubble_sort(&falsoV3[0], k);

    for(i=0;i<k+1;i++){
        for(j=0;j<l;j++){
            if(falsoV3[i]==v3[j]){
                teste=teste+1;
                break;
            }
        }

        if (j==l){
            v3[l]=falsoV3[i];
            l++;
        }
    }

    numRepetidos=numRepetidos-teste;

    return numRepetidos;
}


int main()
{
    int i, j;
    int v1[N], v2[N], v3[N], numRepetidos;

    setlocale(LC_ALL,"");

    printf("Insira os valores do vetor 1: \n");
    for(i=0;i<N;i++)
    {
        do{
            printf("Insira o valor %d: ", i+1);
            scanf(" %d", &v1[i]);
            if(v1[i]<0||v1[i]>100)
            {
                printf("Valor inválido!\n");
            }
        }while(v1[i]<0||v1[i]>100);
    }
    printf("Insira os valores do vetor 2: \n");
    for(i=0;i<N;i++)
    {
        do{
            printf("Insira o valor %d: ", i+1);
            scanf(" %d", &v2[i]);
            if(v2[i]<0||v2[i]>100)
            {
                printf("Valor inválido!\n");
            }
        }while(v2[i]<0||v2[i]>100);
    }
    numRepetidos=repetidos(&v1[0], &v2[0], &v3[0], N);
    printf("Há %d elementos não repetidos que estão simultaneamente nos vetores de interesse:\n", numRepetidos);
    for(i=0;i<numRepetidos;i++)
    {
        printf("%d\n", v3[i]);
    }
    return 0;
 }

/*Faça uma função que recebe 3 vetores (v1, v2 e v3) de números inteiros de mesmo
tamanho, e um valor inteiro que representa o tamanho deles.

A função deve retornar em v3, os elementos não repetidos que estão simultaneamente em ambos os vetores
v1 e v2. A função deve também retornar (através de return) o número de elementos
do vetor v3.

Assuma o tamanho dos vetores como N (considere 5 por conveniência),
de modo que o programa deva funcionar para qualquer valor de N.

Faça um principal programa que leia valores para preencher os vetores v1 e v2 com valores entre 0 e
100 (faça consistência),

que armazene em v3 os elementos não repetidos que se estão
simultaneamente em v1 e v2, usando a função definida acima, e exiba os elementos
do vetor v3 que representam a interseção de v1 e v2.*/
