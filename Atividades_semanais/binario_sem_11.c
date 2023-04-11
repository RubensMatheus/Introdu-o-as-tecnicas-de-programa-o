#include <stdio.h>

int transformarBinario(int num){

    int resto;

    if (num <1)
    {
        return 0;
    }else{
        resto = num % 2;
        num = num / 2;
        transformarBinario(num);
        printf("%d", resto);
    }
    
}


int main(){

    int num;

    scanf("%d", &num);

    if (num == 0)
    {
        printf("0");
    }else{
        transformarBinario(num);
    }

    return 0;
}