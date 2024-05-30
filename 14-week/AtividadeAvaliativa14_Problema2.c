#include <stdio.h>

int contaValores(int v[], int tam, int n){
    if (tam <= 0){
        return -1;
    }
    else if(tam == 1){
        if(v[0] != n)
            return 0;
        else    
            return 1;
    }
    else{
        if(v[0] != n)
            return contaValores(v+1, tam-1, n);
        else    
            return 1 + contaValores(v+1, tam-1, n);
    }
}

int main(){
    int v[10] = {1,4,5,2,4,2,2,10,4,6};
    int tam = 10;
    int n;

    printf("Escolha um numero natural n: ");
    scanf("%d", &n);
    printf("%d\n", contaValores(v, tam, n));
    return 0;
}