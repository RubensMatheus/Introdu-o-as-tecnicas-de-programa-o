#include <stdio.h>

int main(){
    
    float tempo, corrida;
    int cont, series;
    cont = 0;
    series = 0;
   
    scanf("%f", &tempo);
    
    while(1){
        scanf("%f", &corrida);
        if (corrida == -1){
            break;
        }
        if (corrida <= tempo){
            cont++;
        }
    }
    series = cont / 8;
    if (cont % 8 != 0){
        series = series + 1;
    }
    
    printf("%d %d", cont, series);
    
    return 0;
}