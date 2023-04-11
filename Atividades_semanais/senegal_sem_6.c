#include <stdio.h>

int calcular_aposta(int largura, int altura, int bandeira[altura][largura], int inicial, char cor){
    
    int div_a = largura / 3;
    int div_b = div_a * 2;
    int soma = 0;
    int ini1 = inicial + 1;
    int ini2 = inicial + 2;
    int ini3 = inicial + 3;


    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura; j++)
        {
            if (j < div_a)
            {
                bandeira[i][j] = ini1;
            }
            else if (j >= div_a && i < div_b) 
            {
                bandeira[i][j] = ini2;
            }
            if (j >= div_b)
            {
                bandeira[i][j] = ini3;
            }            
        }
    }

    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura; j++)
        {
            switch (cor)
            {
            case 'G':
                if (bandeira[i][j] == ini1)
                {
                soma += bandeira[i][j];
                }
                break;
            case 'Y':
                if (bandeira[i][j] == ini2) 
                {
                soma += bandeira[i][j];
                }
                break;
            case 'R':
                if(bandeira[i][j] == ini3){
                soma += bandeira[i][j];
                }
                break;
            default:
                soma = 0;
                break;
            } 
        }        
    }
    return soma;   
}

int main(){

    int largura, inicial;
    char cor;

    scanf(" %d %d %c", &largura, &inicial, &cor);
    int altura = (largura * 2) / 3;
    int bandeira[largura][altura];
    
    int final = calcular_aposta(largura, altura, bandeira, inicial, cor);

    printf("%d", final);
    return 0;
}