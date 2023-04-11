#include <stdio.h>

void ver_dentro(float esquerdo1, float inferior1, float direito1, float superior1, float esquerdo2, float inferior2, float direito2, float superior2){

    if (esquerdo2 > esquerdo1 && esquerdo2 < direito1 && inferior2 > inferior1 && inferior2 < superior1 && direito2 < direito1 && direito2 > esquerdo1 && superior2 < superior1 && superior2 > inferior1)
    {
        printf("(<%.2f,%.2f>,<%.2f,%.2f>) contem (<%.2f,%.2f>,<%.2f,%.2f>).\n", esquerdo1, inferior1, direito1, superior1, esquerdo2, inferior2, direito2, superior2);
    
    }else if (esquerdo2 < esquerdo1 && esquerdo2 < direito1 && inferior2 < inferior1 && inferior2 < superior1 && direito2 > direito1 && direito2 > esquerdo1 && superior2 > superior1 && superior2 > inferior1)
    {
        printf("(<%.2f,%.2f>,<%.2f,%.2f>) contem (<%.2f,%.2f>,<%.2f,%.2f>).\n", esquerdo2, inferior2, direito2, superior2, esquerdo1, inferior1, direito1, superior1);
    
    }else{
        printf("Nao posso afirmar!\n");
    }
    
    
}


int main (){
    
    float esquerdo1, inferior1, direito1, superior1, esquerdo2, inferior2, direito2, superior2;
    int cont = 1;


    scanf("%f %f %f %f", &esquerdo1, &inferior1, &direito1, &superior1);
    scanf("%f %f %f %f", &esquerdo2, &inferior2, &direito2, &superior2);

    while (cont = 1){
        ver_dentro(esquerdo1, inferior1, direito1, superior1, esquerdo2, inferior2, direito2, superior2);

        scanf("%f %f %f %f", &esquerdo2, &inferior2, &direito2, &superior2);
        if (esquerdo2 == 0 && inferior2 == 0 && direito2 == 0 && superior2 == 0)
        {
            cont += 1;
            break;
        }
    }
    
    
    
    return 0;
}