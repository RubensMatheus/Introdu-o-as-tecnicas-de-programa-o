#include <stdio.h>
#include <string.h>

typedef struct bairro_sem_9
{
    int idchapa;
    char nomechapa[20];
    int qtd_votos;

}chapa;

int compute_votos(int num_votos, int votos[num_votos], int num_partidos,
    chapa partidos[num_partidos], chapa *mais_votado, chapa *segundo_votado){

    int aux = 0,validos = 0, ajuda;
    int vetor[num_partidos];
    float p1, p2, validos2 = 0.00;

    for (int i = 0; i < num_votos; i++)
    {
        for (int j = 0; j < num_partidos; j++)
        {
            if (partidos[j].idchapa == votos[i])
            {
                validos +=1;
                validos2 += 1;
                break;
            }
        }
    }
    
    for (int i = 0; i < num_partidos; i++)
    {
        for (int j = 0; j < num_votos; j++)
        {
            if (partidos[i].idchapa == votos[j])
            {
                aux +=1 ;
            }
        }
        partidos[i].qtd_votos = aux;
        aux = 0;
    }

    for (int i = 0; i < num_partidos; i++)
    {
        vetor[i] = partidos[i].qtd_votos;
    }
    

    for (int i = 1; i < num_partidos; i++)
    {
        for (int j = 0; j < num_partidos-1; j++)
        {
            if(vetor[j] < vetor[j+1]){
                ajuda = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = ajuda;
            }
        }
    }

    for (int i = 0; i < num_partidos; i++)
    {
        if (partidos[i].qtd_votos == vetor[0])
        {
            mais_votado = &partidos[i];
        }else if (partidos[i].qtd_votos == vetor[1])
        {
            segundo_votado = &partidos[i];
        }       
    }


    p1 = (mais_votado->qtd_votos*100)/validos2;
    p2 = (segundo_votado->qtd_votos*100)/validos2;

    printf("VENCEDOR: %s (%d votos = %.2f%)\n", mais_votado->nomechapa, mais_votado->qtd_votos, p1);
    printf("VICE: %s (%d votos = %.2f%)", segundo_votado->nomechapa, segundo_votado->qtd_votos, p2);
    return validos;
}

int main(){

    int N, M, tamanho;
    float p1, p2;

    chapa *mais_votado = NULL;
    chapa *segun_votado = NULL;

    scanf("%d", &N);

    chapa eleicoes[N];

    for (int i = 0; i < N; i++)
    {   
        scanf(" %d ", &eleicoes[i].idchapa);
        fgets(eleicoes[i].nomechapa, 20, stdin);
        tamanho = strlen(eleicoes[i].nomechapa);
        eleicoes[i].nomechapa[tamanho-1] = '\0';    
    }
    
    scanf(" %d", &M);
    int votos[M];

    for (int i = 0; i < M; i++)
    {
        scanf(" %d", &votos[i]);
    }

    int a = compute_votos(M, votos, N, eleicoes, mais_votado, segun_votado);

    p1 = (mais_votado->qtd_votos*100)/a;
    p2 = (segun_votado->qtd_votos*100)/a;

    printf("%d\n", mais_votado->qtd_votos);

    // printf("VENCEDOR: %s (%d votos = %.2f-)\n", mais_votado->nomechapa, mais_votado->qtd_votos, p1);
    // printf("VICE: %s (%d votos = %f-)", segun_votado->nomechapa, segun_votado->qtd_votos, p2);
    
    return 0;
}