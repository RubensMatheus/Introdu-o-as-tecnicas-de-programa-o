#include <stdio.h>

int perfeito (int x ){

    int soma, cont;
    soma = 0; 
    cont = 1;

    while (cont < x)
    {
        if (x % cont == 0)
        {
            soma += cont ;
        }
    
        cont += 1;
    }
    
    
    if (soma == x)
    {
        return 1;
    }else
    {
        return 0;
    }
    
    

}

int main(){
    

    int N, x;

    scanf("%d", &N);


    for (int i = 0; i < N; i++)
    {
        scanf("%d", &x);
        if (perfeito(x) == 1)
        {
            printf("%d eh perfeito\n", x);
        }else{
            printf("%d nao eh perfeito\n", x);
        }
        
    }
    

    return 0;
}