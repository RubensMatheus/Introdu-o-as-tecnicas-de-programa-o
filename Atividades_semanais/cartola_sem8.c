#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct cartola
{
    char *time;
    int vitorias;
    int empates;
    int derrotas;
    int gol_f;
    int gol_s;
} entrada; 

entrada receber(char *linha){
    entrada aux;
    char* parte;

    parte = strtok(linha, ";");
    aux.time = malloc(sizeof(char) * strlen(parte) + 1);
    strcpy(aux.time, parte);

    parte = strtok(NULL, "\n");

    sscanf(parte, "%d %d %d %d %d", &aux.vitorias, &aux.empates, &aux.derrotas, &aux.gol_f, &aux.gol_s);

    return aux;

}

int main(){

    int T;
    int* parte;
    char linha[201];
    // entrada geral[20] = {0};

    scanf("%d", &T);

    entrada geral[50] = {0};

    for (int i = 0; i < T; i++)
    {
        geral[i] = receber(linha);
    }

    for (int i = 0; i < T; i++)
    {
        printf("%s - %d - %d - %d - %d - %d\n", geral[i].time, geral[i].vitorias, geral[i].empates, geral[i].derrotas, geral[i].gol_f, geral[i].gol_s);
    }
        

    return 0;
}