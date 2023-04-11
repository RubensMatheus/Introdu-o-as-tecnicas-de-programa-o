#include <stdio.h>

void compute_votos(int n, int votos[n], int *mais_votado, int *segundo_mais_votado){

    int aux;
    int vetor[n];
    int cont = 0;

    aux = 0;
    int a = 0;
    for(int j = 0; j < n; j++){
        for (int i = 0; i < n; i++)
        {
            if (votos[j] == votos[i])
            {
                cont += 1;
            }
        }
        if (cont > aux)
        {
            *mais_votado = votos[j];
            a = cont;
            aux = cont;
        }
        cont = 0;
    }

    aux = 0;
    for(int j = 0; j < n; j++){
        for (int i = 0; i < n; i++)
        {
            if (votos[j] == votos[i])
            {
                cont += 1;
            }
        }
        if (cont > aux && cont < a)
        {
            *segundo_mais_votado = votos[j];
            aux = cont;
        }
        cont = 0;
    }
    

}

int main(){

    int N;
    int mais;
    int segundo;

    scanf("%d", &N);

    int votos[N];
    for (int i = 0; i < N; i++)
    {
        scanf(" %d", &votos[i]);
    }
    
    compute_votos(N, votos, &mais, &segundo);

    printf("%d %d", mais, segundo);

    return 0;
}