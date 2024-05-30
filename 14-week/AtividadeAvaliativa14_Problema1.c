#include <stdio.h>

int somaDigitos(int num){
    if (num < 0){
        return -1;
    }
    else if(num > 0 && num < 10){
        return num;
    }
    else{
        int digito = num % 10;
        return  digito + somaDigitos((num - digito)/10);
    }
}

int main(){
    int num;
    printf("Escolha um numero natural ter a soma de seus digitos: ");
    scanf("%d", &num);
    printf("A soma dos digitos de %d e: %d\n", num, somaDigitos(num));
    return 0;
}