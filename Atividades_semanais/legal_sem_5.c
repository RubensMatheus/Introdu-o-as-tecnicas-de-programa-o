#include <stdio.h>

void testar_legal(int tmvetor, int* vetor){
    int cont = 0;
    
    for (int j = 1; j < tmvetor; j++)
    {
        int teste = vetor[j] - vetor[j-1];
        
        if (teste % 2 == 0 || teste == 0)
        {
            cont +=1;

        }else{

            cont = 0;
            break;
        }
                
    }

    if (cont == 0)
    {
        printf("Chato");
    }else{
        printf("Legal"); 
    }
}


int main(){
    
    int numeros, tmvetor;
    
    scanf(" %d", &tmvetor);
    int vetor[tmvetor + 1];
    
    for (int i = 0; i < tmvetor ; i++)
    {
        scanf(" %d", &vetor[i]);
    }


    testar_legal(tmvetor, vetor);
    
    return 0;
}