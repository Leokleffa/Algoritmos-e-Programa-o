//Esse programa ir� calcular a dist�ncia percorrida na corrida de acordo com a contagem m�dia de passos
//Entrada: n�mero de passos no primeiro minuto, no �ltimo minuto, n�mero de horas e minutos corridos e a medida m�dia cada passo.
//Sa�da: dist�ncia, em km, percorrida nessa corrida

#include<stdio.h>
#include <locale.h>
#include<math.h>

int main()
{
    int nPassos0, nPassosF, horas, minutos, medidaPasso, horaParaMinuto, tempoTotal;
    float media, dist;

        setlocale(LC_ALL,"");

        printf("Informe o n�mero de passos dados no primeiro minuto:");
        scanf("%d", &nPassos0);
        printf("Informe o n�mero de passos dados no �ltimo minuto:");
        scanf(" %d", &nPassosF);
        printf("Informe, respectivamente, quantas horas e, ap�s o espa�o, quantos minutos de corrida foram feitos:\n");
        scanf(" %d%d", &horas,&minutos);
        printf("Informe a medida m�dia, em cent�metros, de cada passo seu:");
        scanf(" %d", &medidaPasso);

        media=(nPassos0+nPassosF)/2.0; //n�mero m�dio de passos por minuto
        horaParaMinuto=horas*60; //convers�o de hora para minuto
        tempoTotal=minutos+horaParaMinuto; //total de minutos corridos
        dist=(float)(media*tempoTotal*medidaPasso)/100000;
        printf("Dist�ncia percorrida:");
        printf("%.2f km", dist);

        return 0;
}
