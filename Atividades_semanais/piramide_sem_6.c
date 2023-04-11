#include <stdio.h>

int main(){
    int largura;

    scanf(" %d", &largura);

    int piramide[largura][largura];

    int x = 0, cont = 0 ;
    

    do
    {
        for (int i= x; i < largura; i++)
        {
            for (int j = x; j < largura; j++)
            {
                piramide[i][j] = cont+1;
            }
            
        }
        x++;
        largura--;
        cont++;
        
    } while (cont <= largura/2.0);
    
    for (int i = 0; i < largura; i++)
    {
        for (int j = 0; j < largura; j++)
        {
            if (j == largura-1)
            {
                printf("%d\n", piramide[i][j]);
            }else{
                printf("%d ", piramide[i][j]);
            }
            
        }
        
    }
    

    return 0;
}