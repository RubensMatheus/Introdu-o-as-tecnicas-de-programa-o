#include <stdio.h>
#include <string.h>

void descobrir_chave(char* cifrada, char * KP, int* chave){
    int cont = 0, contb = -1;
    int a[200], b[200];
    const char S[] = {'0','1','2','3','4','5','6','7','8','9',
        'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O',
        'P','Q','R','S','T','U','V','W','X','Y','Z','.',',','?',' ','\0'};

    for (int i = 0; i < strlen(cifrada); i++)
    {
        for (int j = 0; j < strlen(S); j++)
        {
            if (cifrada[i] =! S[j])
            {
                cont += 1;
            }else{
                a[i] = cont;
            }            
        }
        cont = 0;        
    }

    for (int i = 0; i < strlen(KP); i++)
    {
        for (int j = 0; j < strlen(S); j++)
        {
            if (KP[i] =! S[j])
            {
                cont += 1;
            }else{
                b[i] = cont;
            }            
        }
        cont = 0;        
    }

    for (int i = 0; i <  strlen(cifrada)-4 ; i++)
    {
        for (int j = 0; j < strlen(KP)-4; j++)
        {
            if (a[i] - b[j] == a[i+4] - b[j+4])
            {
                contb += 1;
                chave[contb] = a[i] - b[j];
                break;
            }else{
                contb = -1;
            }        
        }
        if (contb == 3)
        {
            break;
        }        
    }

    for (int i = 0; i < 4; i++)
    {
        printf("%d ", chave[i]);
    }
    
}




int main(){

    const char S[] = {'0','1','2','3','4','5','6','7','8','9',
        'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O',
        'P','Q','R','S','T','U','V','W','X','Y','Z','.',',','?',' ','\0'};

    char cifrada[201];
    char KP[200] = "QUE A FORCA ESTEJA COM VOCE";

    fgets(cifrada, 200, stdin);
    int tamanho = strlen(cifrada);
    cifrada[tamanho-1] = '\0';

    int a[4];

    descobrir_chave(cifrada, KP, a);
    return 0;
}