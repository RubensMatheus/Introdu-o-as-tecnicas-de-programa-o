#include <stdio.h>

void classificar_planetas(int total, int agua, int hostis, int deserto, int vegetacao){
    if (hostis == 0 && agua >= total*0.5 && vegetacao >= total*0.2)  
    {
        printf("Planeta Classe M");
    }else if (hostis >= 1)
    {
        printf("Planeta Hostil");
    }else if (agua >= total*0.85)
    {
        printf("Planeta Aquático");
    }else if (deserto >= total*0.60)
    {
        printf("Planeta Desértico");
    }else if (vegetacao >= total*0.65)
    {
        printf("Planeta Selvagem");
    }else{
        printf("Planeta Inóspito");
    }
 
}


int main(){

    int N, M;
    int cont_til, cont_x, cont_cir, cont_ast, cont_pon ;
    cont_til = cont_x = cont_cir = cont_ast = cont_pon = 0;

    scanf(" %d %d", &N, &M);
    char raio[N][M];
    int total = M * N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf(" %c", &raio[i][j]);

            if (raio[i][j] == '~')
            {
                cont_til += 1;
            }else if (raio[i][j] == 'X')
            {
                cont_x += 1;
            }else if (raio[i][j] == '^')
            {
                cont_cir += 1;
            }else if (raio[i][j] == '*')
            {
                cont_ast += 1;
            }else if (raio[i][j] == '.')
            {
                cont_pon += 1;
            }             
        }        
    }

    classificar_planetas(total, cont_til, cont_x, cont_cir, cont_ast);    
    return 0;
}