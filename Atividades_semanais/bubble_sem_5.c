#include <stdio.h>


void bubble_sort(int tmvetor, int* vetor){
    
    int continua, aux;

    do
    {
        continua = 0;
        for (int i = 0; i < tmvetor - 1; i++){
        if (vetor[i] > vetor[i+1])
        {
            aux = vetor[i];
            vetor[i] = vetor[i+1];
            vetor[i+1] = aux;
            continua += 1;
        }
        
        }
        if (continua != 0){
            for (int i = 0; i < tmvetor ; i++){
                if (i == tmvetor - 1)
                {
                    printf("%d\n", vetor[i]);
                }else{
                
                    printf("%d ", vetor[i]);
                }
            }
        }    
    } while (continua != 0); 
        
    
}


int main(){
    int tmvetor;
    
    scanf(" %d", &tmvetor);
    int vetor[tmvetor];

    for (int i = 0; i < tmvetor ; i++)
    {
        scanf(" %d", &vetor[i]);
    }
    
    for (int i = 0; i < tmvetor ; i++){
        if (i == tmvetor - 1)
        {
            printf("%d\n", vetor[i]);
        }else{
        
            printf("%d ", vetor[i]);
        }
    }
    

    bubble_sort(tmvetor, vetor);

    return 0;
}