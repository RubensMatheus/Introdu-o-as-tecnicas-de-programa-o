#include <stdio.h>

// retorna verdadeiro se número é divisível por divisor e falso em caso contrario
int testa_divisor(int numero, int divisor){

    if (numero % divisor == 0)
    {
        return 1;
    }else{
        return 0;
    }
}

// retorna a soma dos divisores de value no intervalo [1, value)
int soma_divisores(int value){
    
    int soma, cont;
    soma = 0; 
    cont = 1;

    while (cont < value)
    {
        if (testa_divisor(value, cont) == 1)
        {
            soma += cont ;
        }
    
        cont += 1;
    }
    
    return soma ;
}

// retorna verdadeiro se a é amido de b e falso em caso contrario
int testa_amigos(int a, int b){
    
    if (a == soma_divisores(b) && b == soma_divisores(a) && a != b)
    {
        return 1;
    }else{
        return 0 ;
    }
}

// recebe dois intervalos naturais L1 = [A,B] e L2 = [C, D]
// apresenra todos os valores em L1 que possuem ao menos um amido em L2.
int main(){
    
    int A, B, C, D;
    int cont = 0;

    scanf("%d %d", &A, &B);
    scanf("%d %d", &C, &D);
    
    for (int i = A; i < B; i++)
    {
        for (int j = C; j < D; j++)
        {
            if (testa_amigos(i, j) == 1)
            {
                printf("O %d possui um amigo!\n", i);
                cont += 1;
            }
        }
        
    }
    if (cont == 0)
    {
        printf("Os intervalos nao apresentam amigos!");
    }
    
    
    
    return 0;
}