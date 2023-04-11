#include <stdio.h>
#include <string.h>

typedef struct CRUD_sem8
{
    char nome[50];
    int idade;
    char sexo[3];
    int excluido;

} pessoa;

pessoa criar(char name[51], int age, char sex[3] ){

    pessoa aux;

    strcpy(aux.nome, name);
    aux.idade = age;
    strcpy(aux.sexo, sex);
    aux.excluido = 0;

    return aux;
}

void inserir(pessoa *vetor, pessoa aux, int cont){

    vetor[cont] = aux;
    
}  

void deletar(pessoa aux, pessoa *vetor, int cont){

    for (int i = 0; i < cont; i++)
    {   
        if (aux.idade == vetor[i].idade && strcmp(aux.nome, vetor[i].nome) == 0 && strcmp(aux.sexo, vetor[i].sexo) == 0)
        {
            vetor[i].excluido = 1;
            break;            
        }   
    }
   
}

void imprimir(pessoa *vetor, int cont){
    for (int i = 0; i < cont; i++)
    {
        if (vetor[i].excluido == 0)
        {
            printf("%s,%d,%s\n", vetor[i].nome, vetor[i].idade, vetor[i].sexo);
        }
    }    
}

int main(){

    pessoa dados[100];

    char comando;
    int conta = 0;
    char nome[51];
    int idade;
    char sexo[3];
    int a = 1;
    pessoa aux;
    
    
    while (a != 0)
    {
        scanf("%c\n", &comando);
        switch (comando)
        {
        case 'i':
            fgets(nome, 50, stdin);
            nome[strlen(nome)-1] = '\0';

            scanf(" %d\n", &idade);

            fgets(sexo, 3, stdin);
            sexo[strlen(sexo)-1] = '\0';


            inserir(dados, criar(nome, idade, sexo), conta);
            conta += 1;
            break;
        case 'd':
                
            fgets(nome, 50, stdin);
            nome[strlen(nome)-1] = '\0';

            scanf(" %d\n", &idade);

            fgets(sexo, 3, stdin);
            sexo[strlen(sexo)-1] = '\0';
            if(conta > 0){
                aux = criar(nome, idade, sexo);
                
                deletar(aux, dados, conta);
            }

            break;
        case 'p':
            imprimir(dados, conta);
            a = 0;
            break;
        default:
            break;
        }    
    }   
    
    return 0;
}