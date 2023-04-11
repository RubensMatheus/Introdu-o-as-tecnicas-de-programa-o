#include <stdio.h>
#include <string.h>

typedef struct estatisticas_sem8
{
    char nome[21];
    int marcados;
    int sofridos;
} time;

void ordenar_times(time *vetor, int tamanho){

    time aux = {0};

    for (int i = 1; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho-1; j++)
        {
            if (vetor[j].marcados < vetor[j+1].marcados)
            {
                
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
            
        }
        
    }
    
}

int main(){

    int T;
    char linha[21];

    scanf(" %d\n", &T);
    time entrada[T];

    for (int i = 0; i < T; i++)
    {
        fgets(linha, 20, stdin);
        linha[strlen(linha)-1] = '\0';
        strcpy(entrada[i].nome, linha);
        scanf(" %d\n%d\n", &entrada[i].marcados, &entrada[i].sofridos);
    }

    ordenar_times(entrada, T);

    for (int i = 0; i < T; i++)
    {
        printf("%d - %s\nGols marcados: %d\nGols sofridos: %d\n", i+1, entrada[i].nome, entrada[i].marcados, entrada[i].sofridos);
    }
    return 0;
}