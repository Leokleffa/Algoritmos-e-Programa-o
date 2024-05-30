//Leonardo Kauer Leffa
/*Esse programa irá calcular o preço a pagar de acordo com a hora de entrada e saída.
Entrada:Hora da entrada e hora da saída.
Saída:Preço a pagar ou aviso que o carro ficará guinchado.*/

#include<stdio.h>
#include<locale.h>
#include<math.h>

#define Hpreco1 25,00
#define Hpreco2 45,00
#define Hpreco3 15,00

int main()
{
    int DIAent, Hent, MINent, DIAsaida, Hsaida, MINsaida, MINtotal, teto;
    float MaisDe2h;
    float apagar;

    setlocale(LC_ALL,"");

    printf("Insira o dia do mês, a hora e os minutos da entrada (Separados por espaço):");
    scanf("%d %d %d", &DIAent, &Hent, &MINent);
    printf("\n");

     printf("Insira o dia do mês, a hora e os minutos da saída (Separados por espaço):");
    scanf("%d %d %d", &DIAsaida, &Hsaida, &MINsaida);
    printf("\n");

    if(DIAent==DIAsaida)
    {
        MINtotal=(60*Hsaida+MINsaida)-(60*Hent+MINent);

        if((MINtotal>0)&&(MINtotal<=60))
        {
            apagar=Hpreco1;
        }
        else if((MINtotal>60)&&(MINtotal<=120))
        {
            apagar=Hpreco2;
        }
        else if((MINtotal>120)&&(MINtotal<=1440))
        {
            MaisDe2h=MINtotal/60;
            teto=ceil(MaisDe2h);
            apagar=Hpreco2+Hpreco3*(teto-2);
        }
    }
    else
    {
        printf("\nMinutos totais: %d \n", MINtotal);
        printf("\n");
    }

    printf("\n a pagar: %.2f", apagar);
    return 0;
}




/*3. (Desafio) A tabela de preços de um estacionamento de um aeroporto é a seguinte:

 • 1 hora: R$ 25,00
 • 2 horas: R$ 45,00
 • Horas adicional (acima de duas horas): R$ 15,00

Faça um programa que obtenha do usuário o horário de entrada e o horário de saída do
estacionamento (ambos em horas e minutos inteiros) e calcule o valor devido pelo
proprietário do carro. Note que o carro pode entrar em um dia e sair no outro. Mas o
carro só pode permanecer estacionado por menos de 24 horas. Se um carro fica estacionado
por 24 horas ou mais ele é guinchado. E considere que o número de horas é sempre arredondado
para cima. Por exemplo, se um carro fica estacionado por uma hora e um minuto, ele paga por
duas horas. O dono do estacionamento é bastante rígido e intolerante.*/
