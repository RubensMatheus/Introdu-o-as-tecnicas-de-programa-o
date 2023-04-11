#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct crud_sem_10
{
    char *nome;
    int idade;
    char sexo;
    int excluido;
}cadastro;

cadastro criar(char *Nome, int Idade, char Sexo){

    cadastro aux;
    int tamanho = strlen(Nome);

    aux.nome = malloc(sizeof(char) * tamanho+1);

    strcpy(aux.nome, Nome);
    aux.idade = Idade;
    aux.sexo = Sexo;
    aux.excluido = 0;

    return aux;
}

void inserir(cadastro *vetor, cadastro aux, int cont){

    if (cont == 0)
    {
        vetor = malloc(sizeof(cadastro));
        vetor[cont] = aux;
        printf("%s, %d, %c\n", vetor[cont].nome, vetor[cont].idade, vetor[cont].sexo);
    }else{
        vetor = realloc(vetor, sizeof(cadastro) * cont+1);
        vetor[cont] = aux;
        printf("%s, %d, %c\n", vetor[cont].nome, vetor[cont].idade, vetor[cont].sexo);
    } 

    free(aux.nome);
}

void deletar (cadastro aux, cadastro *vetor, int cont){


    for (int i = 0; i < cont; i++)
    {
        if (strcmp(vetor[i].nome, aux.nome) == 0 && vetor[i].idade == aux.idade && vetor[i].sexo == aux.sexo)
        {
            vetor[i].excluido = 1;
        }
    }

    free(aux.nome);
}

void imprimir(cadastro *vetor, int cont){

    for (int i = 0; i < cont; i++)
    {
        if (vetor[i].excluido == 0)
        {
            printf("%s,%d,%c\n", vetor[i].nome, vetor[i].idade, vetor[i].sexo);
        }   
    }
}


int main(){

    cadastro *crud;
    cadastro aux;
    char comando, Nome[50], Sexo;
    int  Idade, cont = 0, tamanho, a = 1;

    while (a != 0)
    {

        scanf("%c\n", &comando);
    
        switch (comando)
        {
        case 'i':

            fgets(Nome, 49, stdin);
            tamanho = strlen(Nome);
            Nome[tamanho-1] = '\0';


            scanf(" %d\n%c", &Idade, &Sexo);

            aux = criar(Nome, Idade, Sexo);
            
            inserir(crud, aux, cont);
            cont += 1;        
            break;

        case 'd':

            fgets(Nome, 49, stdin);
            tamanho = strlen(Nome);
            Nome[tamanho-1] = '\0';

            scanf(" %d\n%c", &Idade, &Sexo);
            if (cont > 0)
            {
                deletar(criar(Nome, Idade, Sexo), crud, cont);
            }
            printf("1");    
            break;
        case 'p':
            imprimir(crud, cont);
            a = 0;
            break;
        default:
            break;
        }
    }

    free(crud);
    
    
    return 0;
}