#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int nlim, ncol;
    int **mat;
} Matrix;

Matrix* createMatrix(int nlin, int ncol){
    
    Matrix *saida = malloc(sizeof(Matrix));

    saida->ncol = ncol;

    saida->nlim = nlin;
    saida->ncol = ncol;

    saida->mat = malloc(sizeof(int*) * nlin);

    for (int i = 0; i < nlin; i++)
    {
        saida->mat[i] = malloc(sizeof(int) * ncol);
    }
    return saida;
}

void readMatrix(Matrix *m){
    
    for (int i = 0; i < m->nlim; i++)
    {
        for (int j = 0; j < m->ncol; j++)
        {
            scanf(" %d", &m->mat[i][j]);
        }       
    }
}

void printMatrix(Matrix *m){
    for (int i = 0; i < m->nlim; i++)
    {
        for (int j = 0; j < m->ncol; j++)
        {
            if (j < m->ncol-1)
            {
                printf("%d ", m->mat[i][j]);
            }else{
                printf("%d\n", m->mat[i][j]);
            }
        }       
    }
}

void destroyMatrix(Matrix **m){

    for (int i = 0; i < (*m)->nlim; i++)
    {
        free((*m)->mat[i]);
    }

    free(*m);
    *m = NULL;
}

int main(){
    int lin, col;
    Matrix* mat;

    scanf("%i %i", &lin, &col);
    mat = createMatrix(lin, col);
    readMatrix(mat);
    printMatrix(mat);
    destroyMatrix(&mat);
    if (mat == NULL)
    {
        printf("OK\n");
    }
    return 0;
}
