#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nome[4];
    float populacao;
    float idh;
}paises;

// função para adicionar o paises lidos

void adicionaPais(paises *vetor,char *nomeDoPais, int popu, float IDH, int cont){
    if (cont == 0){
        vetor = malloc(sizeof(paises) * (cont +1));
    }else{
        vetor = realloc(vetor, sizeof(paises) * (cont +1));
    }
    strcpy(vetor[cont].nome, nomeDoPais);
    vetor[cont].populacao = popu;
    vetor[cont].idh = IDH;
}

// calcular a media dos dados dos paisesvcada dado um numero

float media(int identificador, paises *vetor, int cont){
    float media = 0;

    if (identificador == 0){
        for (int i = 0; i < cont; i++){
            media += vetor[i].populacao;
        }
        media = media/(cont+1);
    }else{
        for (int i = 0; i < cont; i++){
            media += vetor[i].idh;
        }
        media = media/(cont+1);
    }
    
    return media;    
}


void populacaoABaixo(paises *vetor, paises *abxpopu,int cont){
    float med = media(0, vetor, cont);
    int aux = 0;

    for (int i = 0; i < cont; i++){
        if (vetor[i].populacao < med){
            if (aux == 0){
                abxpopu = malloc(sizeof(paises) * (aux+1));
            }else{
                abxpopu = realloc(abxpopu, sizeof(paises) * (aux+1));
            }
            abxpopu[aux] = vetor[i];
            aux += 1;
        }
    }
}

void idhABaixo(paises *vetor, paises *abxidh,int cont){
    float med = media(1, vetor, cont);
    int aux = 0;

    for (int i = 0; i < cont; i++){
        if (vetor[i].populacao < med){
            if (aux == 0){
                abxidh = malloc(sizeof(paises) * (aux+1));
            }else{
                abxidh = realloc(abxidh, sizeof(paises) * (aux+1));
            }
            abxidh[aux] = vetor[i];
            aux += 1;
        }
    }
}


int main(){

    int a = 1, cont = 0;
    char nomeDoPais[4];
    float popu, mediapopu, mediaidh, IDH;
    paises *todos;
    paises *abaixoPopulacao;
    paises *abaixoidh;

    while (a)
    {
        scanf("%s", nomeDoPais);
        if (strcmp(nomeDoPais, "---") == 0){
            a = 0;
            break;
        }
        scanf(" %f %f", &popu, &IDH);

        adicionaPais(todos, nomeDoPais, popu, IDH, cont);
        cont += 1;
        //printf("%s-%f-%f", nomeDoPais, popu, IDH);
                
    }
    
    populacaoABaixo(todos, abaixoPopulacao, cont);
    idhABaixo(todos, abaixoidh, cont);

    printf("%f", abaixoPopulacao[0].populacao);
    

    free(todos);
    free(abaixoidh);
    free(abaixoidh);
    
    return 0;
}