#include <stdio.h>
#include <string.h>

int main (){

    char procurar[50];
    char padrao[50];

    int contp = 0,contpadrao = 0, certo = 0;
    int inicial = 0, diferente = 0;

    
    fgets(procurar, 49, stdin);
    fgets(padrao, 49, stdin);
    int tamanho1 = strlen(procurar);
    int tamanho2 = strlen(padrao);

    while (1)
    {
        if (procurar[contp] == padrao[contpadrao] )
        {
            printf("%c ", procurar[contp]);
            certo += 1;
            contp += 1;
            contpadrao += 1;
            if (contpadrao == 0)
            {
                inicial = contp;
            }
            
        }else {
            printf("%c ", procurar[contp]);
            printf("não\n");

            // For para vasculhar as letras que foram checadas até o momente e ver se tem uma diferen das exigidas na padrão
            for (int i = inicial; i <= contp; i++)
            {
                for (int j = 0; j < tamanho2; j++)
                {
                    if (procurar[i] == padrao[j])
                    {
                        diferente += 1;
                        break;
                    }
                }                
            }

            
            if (diferente != (contp - inicial) +1 && diferente != 0 && contp - inicial + 1 != 0)
            {
                contp = inicial + diferente + 1;
                inicial += diferente + 1;
                contpadrao = 0;
                certo = 0;
                diferente = 0;
            }else{
                contp = inicial + 1;
                inicial += 1;
                contpadrao = 0;
                certo = 0;
                diferente = 0;
            }
        }


        if (certo == tamanho2)
        {
            printf("sim\n");
            printf("Achei o padrão no índice %d", inicial); 
            break;           
        }
        if (tamanho1 - contp == tamanho2 && certo == 0)
        {
            printf("Não achei o padrão");
            break;
        }
        
    }
    
    return 0;

}