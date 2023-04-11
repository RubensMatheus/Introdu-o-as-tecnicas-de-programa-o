#include <stdio.h>

int main() {
    
    int numero_entrada, contador_S = 0, contador_C =0, contador_L =0, total;
    char tipo;
    
    scanf("%d",&numero_entrada);
    
    for(int a = 0; a<numero_entrada; a++) {
        
        do {
            
            scanf("%c",&tipo);
            
            switch(tipo) {
                
                case 'S':
                    contador_S++;
                    break;
                case 'C':
                    contador_C++;
                    break;
                case 'L':
                    contador_L++;
                    break;
                default: break;    
            }
            
        } while(tipo != 'F');
    }
    total = contador_S + contador_C + contador_L;
    printf("%d %d %d %d", contador_C, contador_S, contador_L, total);
    
    return 0;    
}