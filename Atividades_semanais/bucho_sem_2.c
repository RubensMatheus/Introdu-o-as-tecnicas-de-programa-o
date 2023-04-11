#include <stdio.h>
int main (){
    
    int combo, money, troco, falta;

    scanf("%d\n%d", &combo, &money);

    switch (combo)
    {
    case 1 :
        if (money > 12)
        {
            troco = money - 12 ;
            printf("Troco = %d reais", troco) ;
        }
        else if (money == 12)
        {
            printf("Deu certim!") ;
        }
        else if (money < 12)
        {
            falta = 12 - money ;
            printf("Saldo insuficiente! Falta %d reais", falta);
        }
        break;
    case 2 :
        if (money > 23)
        {
            troco = money - 23 ;
            printf("Troco = %d reais", troco) ;
        }
        else if (money == 23)
        {
            printf("Deu certim!") ;
        }
        else if (money < 23)
        {
            falta = 23 - money ;
            printf("Saldo insuficiente! Falta %d reais", falta);
        }
        break;
    case 3 :
        if (money > 31)
        {
            troco = money - 31 ;
            printf("Troco = %d reais", troco) ;
        }
        else if (money == 31)
        {
            printf("Deu certim!") ;
        }
        else if (money < 31)
        {
            falta = 31 - money ;
            printf("Saldo insuficiente! Falta %d reais", falta);
        }
        break;
    case 4 :
        if (money > 28)
        {
            troco = money - 28 ;
            printf("Troco = %d reais", troco) ;
        }
        else if (money == 28)
        {
            printf("Deu certim!") ;
        }
        else if (money < 28)
        {
            falta = 28 - money ;
            printf("Saldo insuficiente! Falta %d reais", falta);
        }
        break;
    case 5 :
        if (money > 15)
        {
            troco = money - 15 ;
            printf("Troco = %d reais", troco) ;
        }
        else if (money == 15)
        {
            printf("Deu certim!") ;
        }
        else if (money < 15)
        {
            falta = 15 - money ;
            printf("Saldo insuficiente! Falta %d reais", falta);
        }
        break;
    default:
        break;
    }

    return 0;
}