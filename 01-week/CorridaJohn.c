//Esse programa irá calcular a distância percorrida na corrida de acordo com a contagem média de passos
//Entrada: número de passos no primeiro minuto, no último minuto, número de horas e minutos corridos e a medida média cada passo.
//Saída: distância, em km, percorrida nessa corrida

#include<stdio.h>
#include <locale.h>
#include<math.h>

int main()
{
    int nPassos0, nPassosF, horas, minutos, medidaPasso, horaParaMinuto, tempoTotal;
    float media, dist;

        setlocale(LC_ALL,"");

        printf("Informe o número de passos dados no primeiro minuto:");
        scanf("%d", &nPassos0);
        printf("Informe o número de passos dados no último minuto:");
        scanf(" %d", &nPassosF);
        printf("Informe, respectivamente, quantas horas e, após o espaço, quantos minutos de corrida foram feitos:\n");
        scanf(" %d%d", &horas,&minutos);
        printf("Informe a medida média, em centímetros, de cada passo seu:");
        scanf(" %d", &medidaPasso);

        media=(nPassos0+nPassosF)/2.0; //número médio de passos por minuto
        horaParaMinuto=horas*60; //conversão de hora para minuto
        tempoTotal=minutos+horaParaMinuto; //total de minutos corridos
        dist=(float)(media*tempoTotal*medidaPasso)/100000;
        printf("Distância percorrida:");
        printf("%.2f km", dist);

        return 0;
}
