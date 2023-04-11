#include <stdio.h>

int ehPar (int num){
    int resposta;
    if (num%2 == 0)
    {
        resposta = 1;
    }
    else
    {
        resposta = 0;
    }
    return resposta;
}

int main (){
    int num, final;

    scanf("%d", &num);
    final = ehPar(num);
    if (final == 1)
    {
        printf("true");
    }else
    {
        printf("false");
    }
}