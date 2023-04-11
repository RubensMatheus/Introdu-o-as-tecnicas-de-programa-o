#include <stdio.h>
#include <stdlib.h>

void sort(int *vetor, int cont){

    int aux;

    for (int i = 1; i < cont; i++)
    {
        for (int j = 0; j < cont-1; j++)
        {
            if (vetor[j] > vetor[j+1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
}

void imprimir(int *lista, int cont){
    for (int i = 0; i < cont; i++)
    {
        printf("%d ", lista[i]);
    }
    
}

int main(){

    int *lista;
    int cont = 0;
    char espaco;
    

    while (1)
    {
        if (cont == 0)
        {
            lista = malloc(sizeof(int));
            scanf("%d%c", &lista[cont], &espaco);
            if (espaco != ' ')
            {
                break;
            }
            
            cont += 1;

        }else{
            lista = realloc(lista, sizeof(int) * cont+1);
            scanf("%d%c", &lista[cont], &espaco);
            if(lista[cont] == -9999) break;
            cont += 1;
            if (espaco != ' ')
            {
                break;
            }
        }
    }

    if (cont == 0)
    {
        printf("%d", lista[cont]);
    }else if(cont == 1)
    {   
        printf("%d %d", lista[1], lista[0]);
    }else{
    
        sort(lista, cont);
        imprimir(lista, cont);
    }
    
    free(lista);

    return 0;
}