#include <stdio.h>

int main(){
    
    int corrida, salto, lancamento, equipes, qtatletas, i;
    char auxi ;
    corrida = salto = lancamento = 0 ;

    scanf("%d", &equipes) ;

    for ( i = 0; i < equipes; i++)
    {
        do
        {
            scanf("%c", &auxi) ;

            switch (equipes)
            {
            case 'S':
                salto++;
                break;
            case 'C':
                corrida++;
                break;
            case 'L':
                lancamento++;
                break;
            
            default:
                break;
            }
        } while (auxi != 'F');
        
    }
    qtatletas = salto + corrida + lancamento ;    
    printf("%d %d %d %d", corrida, salto, lancamento, qtatletas) ;

    return 0;
}