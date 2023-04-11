#include <stdio.h>

int main(){
    
    int num, unidade = 0, dezena = 0, centena = 0, milhar = 0, unim = 0, unid = 0;
    scanf("%d", &num);

    if (num >= 1 && num <= 100000)
    {
        if (num < 10)
        {
            unidade = num ;
            printf("%d", unidade);
        }
        else if (num > 9 && num < 100)
        {
            unidade = num % 10;
            dezena = num / 10 ;
            printf("%d\n%d", dezena, unidade);
        }
        else if (num > 99 && num < 1000)
        {
            unidade = num % 10 ;
            dezena = (num / 10) % 10 ;
            centena = (num / 100) % 10 ;
            printf("%d\n%d\n%d", centena, dezena, unidade);
        }
        else if (num > 999 && num < 10000)
        {
            unidade = num % 10 ;
            dezena = (num / 10) % 10 ;
            centena = (num / 100) % 10 ;
            milhar = (num / 1000) % 10;
            printf("%d\n%d\n%d\n%d", milhar, centena, dezena, unidade);
        }
        else if (num > 9999 && num < 100000)
        {
            unidade = num % 10 ;
            dezena = (num / 10) % 10 ;
            centena = (num / 100) % 10 ;
            milhar = (num / 1000) % 10;
            unim = (num / 10000) % 10;
            printf("%d\n%d\n%d\n%d\n%d", unim, milhar, centena, dezena, unidade);
        }
        else{
            unidade = num % 10 ;
            dezena = (num / 10) % 10 ;
            centena = (num / 100) % 10 ;
            milhar = (num / 1000) % 10;
            unim = (num / 10000) % 10;
            unid = (num/100000) % 10;
            printf("%d\n%d\n%d\n%d\n%d\n%d", unid, unim, milhar, centena, dezena, unidade);
        }
    }
    
    
    return 0 ;
}