#include <stdio.h>
#include <stdlib.h>

int get_range(int n, int cells[n], int distancia, int usuario, int *esquerdo, int *direito){
    int qtd_celulas = 0;
    int maximo = distancia + usuario;
    int minimo = usuario - distancia;
    int *vetor;
    int aux, a = 0;

    for (int i = 0; i < n; i++)
    {
        if (cells[i] >= minimo && cells[i] <= maximo && qtd_celulas == 0)
        {
            vetor = malloc(sizeof(int));
            vetor[0] = cells[i];
            qtd_celulas += 1;
            a += 1;
        }else if (cells[i] >= minimo && cells[i] <= maximo && qtd_celulas != 0)
        {
            vetor = realloc(vetor, sizeof(int) * qtd_celulas + 1);
            vetor[qtd_celulas] = cells[i];
            qtd_celulas += 1;
            a += 1;
        }   
    }
    
    if (a != 0)
    {
        for (int i = 1; i < qtd_celulas; i++)
        {
            for (int j = 0; j < qtd_celulas-1; j++)
            {
                if (vetor[i] > vetor[i+1])
                {
                    aux = vetor[i];
                    vetor[i] = vetor[i+1];
                    vetor[i+1] = aux;
                }
            }
        }
    *esquerdo = vetor[0];
    *direito = vetor[qtd_celulas];
    free(vetor);
    }else{
        *esquerdo = 0;
        *direito = 0;
    }

    return qtd_celulas;
}


int main(){

    int num_c;
    int distancia;
    int posicao;
    int max_esquerdo;
    int max_direito;

    scanf("%d", &num_c);
    scanf(" %d", &distancia);
    scanf(" %d", &posicao);

    int celulas[num_c];

    for (int i = 0; i < num_c; i++)
    {
        scanf(" %d", &celulas[i]);
    }

    int validos = get_range(num_c, celulas, distancia, posicao, &max_esquerdo, &max_direito);

    if (max_esquerdo == 0 && max_direito == 0)
    {
        printf("USUARIO DESCONECTADO");
    }else
    {
        for (int i = 0; i < num_c; i++)
        {
            if (celulas[i] >= max_esquerdo && celulas[i] <= max_direito)
            {
                printf("%d ", celulas[i]);
            }
        }
    }
    
    return 0;
}