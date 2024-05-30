//Leonardo Kauer Leffa
/*O programa informará a média do peso e da altura das 3 pessoas e a
quantidade e quais pessoas que devem ser monitoradas.
Entrada: peso referência, altura referência, peso e altura de 3 pessoas diferentes;
Saída: a média do peso, a média da altura e a quantidade de pessoas que devem ser monitoradas.
*/

#include<stdio.h>
#include<locale.h>

int main()
{
    float pesoRef, alturaRef, peso1, altura1, peso2, altura2, peso3, altura3, pessoa1, pessoa2, pessoa3;
    float mediaPeso, mediaAltura;
    int qntdMonitoradas;

    setlocale(LC_ALL,"");

    pessoa1=0;
    pessoa2=0;
    pessoa3=0;

    printf("Informe o peso(kg) de referência:");
    scanf("%f", &pesoRef);
    printf("\n");
    printf("Informe a altura(m) de referência:");
    scanf(" %f",&alturaRef);
    printf("\n");
    printf("Informe o peso (kg) e, após o espaço, a altura (m) da pessoa 1:");
    scanf(" %f %f",&peso1,&altura1);
    printf("\n");
    printf("Informe o peso (kg) e, após o espaço, a altura (m) da pessoa 2:");
    scanf(" %f %f",&peso2,&altura2);
    printf("\n");
    printf("Informe o peso (kg) e, após o espaço, a altura (m) da pessoa 3:");
    scanf(" %f %f",&peso3,&altura3);
    printf("\n");

    mediaPeso=(peso1+peso2+peso3)/3;
    mediaAltura=(altura1+altura2+altura3)/3;

    printf("A média dos pesos das pessoas é: %.2f kg", mediaPeso);
    printf("\n");
    printf("A média das alturas das pessoas é: %.2f m", mediaAltura);
    printf("\n");

    if((peso1>pesoRef)&&(altura1<alturaRef))
    {
        printf("\n Pessoa 1 deve ser monitorada.");
        pessoa1=1;
    }
    if((peso2>pesoRef)&&(altura2<alturaRef))
    {
        printf("\n Pessoa 2 deve ser monitorada.");
        pessoa2=1;
    }
    if((peso3>pesoRef)&&(altura3<alturaRef))
    {
        printf("\n Pessoa 3 deve ser monitorada.");
        pessoa3=1;
    }
    qntdMonitoradas=pessoa1+pessoa2+pessoa3;
    printf("\n Quantidade de pessoas que devem ser monitoradas: %d", qntdMonitoradas);
    printf("\n");
    return 0;
}
/*2. Faça um programa para auxiliar em uma pesquisa de saúde pública do ministério
da saúde. O programa pedir para o usuário informar um peso de referência e uma
altura de referência. A seguir, o programa deve ler o peso e a altura de 3 pessoas
diferentes. O programa deve informar a média do peso e da altura das 3 pessoas e a
quantidade de pessoas que devem ser monitoradas. As pessoas que devem ser
monitoradas são aquelas que possuem simultaneamente peso acima do peso de
referência e altura abaixo da altura de referência.

Exemplo de execução:

Informe o peso de referência: 75.5
Informe a altura de referência: 1.70
Informe o peso (kg) e a altura (m) da pessoa 1: 80.7 1.55
Informe o peso (kg) e a altura (m) da pessoa 2: 92.3 1.67
Informe o peso (kg) e a altura (m) da pessoa 3: 70.2 1.75
A média dos pesos das pessoas é: 81.07 kg
A média das alturas das pessoas é: 1.66 m
Quantidade de pessoas que devem ser monitoradas: 2*/
