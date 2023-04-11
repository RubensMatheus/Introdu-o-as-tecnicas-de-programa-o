#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int testePalindromo(char *palavra){

    int tamanho = strlen(palavra);

    char auxiliar[100] = {0};
    int aux = 0;

    for (int i = 0; i < tamanho+1; i++)
    {
        if (palavra[i] == '\0') break;
        if (palavra[i] == ' ') continue;
        auxiliar[aux] = palavra[i];
        aux++;
    }
    
    int cont = 0;
    
    tamanho = strlen(auxiliar);

    if (auxiliar[0] == '\0')
    {
        return 1;
    }else{
        for (int i = 0; i < tamanho; i++)
        {
            if (auxiliar[i] == auxiliar[tamanho-(i+1)])
            {
                auxiliar[i] = ' ';
                auxiliar[tamanho-(i+1)] = ' ';
                testePalindromo(auxiliar);
                return 1;
            }else{
                return 0;
            }
        }
    }
}

int palindromo(char *entrada){
    if (testePalindromo(entrada) == 1)
    {
        return 1;
    }else
    {
        return 0;
    }
}

int main(){

    char palavra[100];

    fgets(palavra, 99, stdin);
    int tamanho = strlen(palavra);

    if(palindromo(palavra) == 1){
        printf("O texto \"%s\" é palíndromo", palavra);
    }else{
        printf("O texto \"%s\" não é palíndromo", palavra);
    }

    return 0;
}