#include <stdio.h>
int main () {

    int qth, classe, nivelam;
    
    scanf("%d\n%d\n%d", &qth, &classe, &nivelam);

    switch (nivelam)
    {
    case 1:
        if (qth == 1 && classe >= 2 || qth >= 3 && classe == 1)
        {
            printf("Heróis vencerão!") ;
        }
        else{
            printf("Melhor chamar Saitama!") ;
        }
        break;
    case 2:
        if (qth == 1 && classe >= 3 || qth >= 3 && classe == 2)
        {
            printf("Heróis vencerão!") ;
        }
        else{
            printf("Melhor chamar Saitama!") ;
        }
    break;
    case 3:
        if (qth == 1 && classe >= 4 || qth >= 3 && classe ==3)
        {
            printf("Heróis vencerão!") ;
        }
        else{
            printf("Melhor chamar Saitama!") ;
        }
        break;    
    case 4:
        if (qth == 1 && classe >= 5 || qth >= 3 && classe ==4)
        {
            printf("Heróis vencerão!") ;
        }
        else{
            printf("Melhor chamar Saitama!") ;
        }
        break;
    case 5:
        if (qth == 1 && classe >= 5 )
        {
            printf("Heróis vencerão!") ;
        }
        else{
            printf("Melhor chamar Saitama!") ;
        }
        break;

    default:
        break;
    }

    return 0;
}