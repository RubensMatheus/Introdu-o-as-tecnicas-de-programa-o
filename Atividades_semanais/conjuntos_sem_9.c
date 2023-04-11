#include <stdio.h>
#include <stdlib.h>

typedef struct conjuntos_sem_9
{
    int *numeros;
    int qtd_numeros;
}conjunto;

conjunto uniao(conjunto *A, conjunto *B){

    conjunto C;
    C.qtd_numeros = 0;
    int cont = 0;

    for (int i = 0; i < A->qtd_numeros; i++)
    {
        if (i == 0)
        {
            C.numeros = malloc(sizeof(int));
            C.numeros[C.qtd_numeros] = A->numeros[i];
            C.qtd_numeros += 1;
        }else{
            C.numeros = realloc(C.numeros,sizeof(int) * i+1 );
            C.numeros[C.qtd_numeros] = A->numeros[i];
            C.qtd_numeros += 1;
        }
    }

    for (int i = 0; i < B->qtd_numeros ; i++)
    {
        for (int j = 0; j < A->qtd_numeros; j++)
        {
            if (B->numeros[i] == A->numeros[j])
            {
                cont += 1;
            }   
        }
        if (cont == 0)
        {
            C.numeros = realloc(C.numeros,sizeof(int) * i+1 );
            C.numeros[C.qtd_numeros] = B->numeros[i];
            C.qtd_numeros += 1;
        }
        cont = 0;
    }
    
    if (C.qtd_numeros == 0)
    {
        printf("A união B == {vazio}\n");   
    }else{
        for (int i = 0; i < C.qtd_numeros; i++)
        {
            if (i == 0)
            {
                printf("A união B == { %d", C.numeros[i]);
            }else if (i > 0 && i < C.qtd_numeros-1)
            {
                printf(" %d", C.numeros[i]);
            }else if (i == C.qtd_numeros-1) {
                printf(" %d}\n", C.numeros[i]);
            }
        }
    }
    
    
    return C;
}

conjunto intersecao(conjunto *A, conjunto *B){

    conjunto D;
    D.qtd_numeros = 0;

    for (int i = 0; i < B->qtd_numeros ; i++)
    {
        for (int j = 0; j < A->qtd_numeros; j++)
        {
            if (A->numeros[j] == B->numeros[i])
            {
                D.numeros[D.qtd_numeros] = B->numeros[i];
                D.qtd_numeros += 1;
                break;
            }   
        }
    }
    if (D.qtd_numeros == 0)
    {
        printf("A interseção B == {vazio}");
    }else{
        for (int i = 0; i < D.qtd_numeros; i++)
        {
            if (i == 0)
            {
                printf("A interseção B == { %d", D.numeros[i]);
            }else if (i > 0 && i < D.qtd_numeros-1)
            {
                printf(" %d", D.numeros[i]);
            }else if (i == D.qtd_numeros-1){
                printf(" %d}", D.numeros[i]);
            }
        }
        
    }
    
    return D;

}

int main(){

    conjunto A;
    conjunto B;
    conjunto Cunicao;
    conjunto Dintersecao;

    scanf("%d", &A.qtd_numeros);

    for (int i = 0; i < A.qtd_numeros; i++)
    {
        if (i==0)
        {
            A.numeros = malloc(sizeof(int));
            scanf(" %d", &A.numeros[0]);
        }else{
            A.numeros = realloc(A.numeros, sizeof(int) * i+1);
            scanf(" %d", &A.numeros[i]);
        } 
    }

    scanf(" %d", &B.qtd_numeros);

    for (int i = 0; i < B.qtd_numeros; i++)
    {
        if (i==0)
        {
            B.numeros = malloc(sizeof(int));
            scanf(" %d", &B.numeros[0]);
        }else{
            B.numeros = realloc(B.numeros, sizeof(int) * i+1);
            scanf(" %d", &B.numeros[i]);
        } 
    }    
    
    if (A.qtd_numeros == 0 && B.qtd_numeros == 0)
    {
        printf("A união B == {vazio}\nA interseção B == {vazio}");
    }else{
    

    Cunicao = uniao(&A, &B);
    Dintersecao = intersecao(&A, &B);}

    // // for (int i = 0; i < Cunicao.qtd_numeros; i++)
    // // {
    // //     if (i == 0)
    // //     {
    // //         printf("A união B == { %d", Cunicao.numeros[i]);
    // //     }else if (i > 0 && i < Cunicao.qtd_numeros-1)
    // //     {
    // //         printf(" %d", Cunicao.numeros[i]);
    // //     }else if (i == Cunicao.qtd_numeros-1) {
    // //         printf(" %d}\n", Cunicao.numeros[i]);
    // //     }
    // // }
    
    // for (int i = 0; i < Cunicao->qtd_numeros; i++)
    // {
    //     printf("-%d-", Cunicao->numeros[i]);
    // }

    // // for (int i = 0; i < Dintersecao.qtd_numeros; i++)
    // // {
    // //     if (i == 0)
    // //     {
    // //         printf("A interseção B == { %d", Dintersecao.numeros[i]);
    // //     }else if (i > 0 && i < Dintersecao.qtd_numeros-1)
    // //     {
    // //         printf(" %d", Dintersecao.numeros[i]);
    // //     }else if (i == Dintersecao.qtd_numeros-1){
    // //         printf(" %d}", Dintersecao.numeros[i]);
    // //     }
    // // }

    // }

    return 0;
}