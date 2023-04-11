#include   <stdio.h>

int main() {
    
    char escala ;
    double temp, cel, far, kel ;
    
    scanf("%lf\n%c", &temp, &escala);

    if (escala == 'C')
    {
        cel = temp;
        far = (cel * 1.8) +32;
        kel = cel + 273.15;
    }

    else if (escala == 'F')
    {
        far = temp;
        cel = (far-32)/1.8 ;
        kel = ((far-32)/1.8)+273.15 ; 
    }

    else if (escala = 'K')
    {
        kel = temp ;
        cel = kel - 273.15 ;
        far = ((kel - 273.15)*1.8) + 32 ;

    }
    
    printf("Celsius: %.2lf \nFarenheit: %.2lf \nKelvin: %.2lf\n", cel, far, kel) ;
    
    

    return 0;
}