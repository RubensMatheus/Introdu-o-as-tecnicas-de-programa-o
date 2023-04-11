#include <stdio.h>
#include <string.h>

#define MAXC 11
#define MAXL 100

int main(){

    char prefixos[MAXL][MAXC];
    char sufixo[MAXL][MAXC];
    char palavra[101];
    int N, M, tamanho, tmp, tms, contig = 0,contis = 0, p, s;
    char tolerante = "tolerante";

    scanf("%d\n", &N);

    for (int i = 0; i < N; i++)
    {
        fgets(prefixos[i], MAXC, stdin);
        tamanho = strlen(prefixos[i]);
        prefixos[i][tamanho-1] = '\0';      
    }
    
    scanf("%d\n", &M);
    
    for (int i = 0; i < M; i++)
    {
        fgets(sufixo[i], MAXC, stdin);
        tamanho = strlen(sufixo[i]);
        sufixo[i][tamanho-1] = '\0';        
    }

  
    fgets(palavra, 100, stdin);
   
    tamanho = strlen(palavra);
    
    palavra[tamanho-1] = '\0';
    
    


    while (1)
    {   
        if (palavra[0] == '-')
        {
            break;
        }

        if (strcmp(tolerante, palavra) == 0)
        {
            printf("%s\n", palavra);
            fgets(palavra, 101, stdin);
            tamanho = strlen(palavra);
            palavra[tamanho-1] = '\0';
            continue;
        }
        
        
        if (N>0)
        {
            for (int i = 0; i < N; i++)
            {   
                tmp = strlen(prefixos[i]);
                //tms = strlen(sufixo[i]);
                for (int j = 0; j < tmp ; j++)
                {
                    for (int k = 0; k < tmp; k++)
                    {
                        if (prefixos[i][j] == palavra[k])
                        {
                            contig += 1;
                            break;
                        }
                    }
                }
                
            
                if (contig == tmp)
                {
                    for (int i = tmp; i < tamanho; i++)
                    {
                        
                        palavra[i-tmp] = palavra[i];
                    }   
                }
                contig = 0;       
            }
        }
        
        if (M > 0)
        {
            for (int i = 0; i < M; i++)
            {
                tms = strlen(sufixo[i]);
                for (int j = tms-1; j >= 0 ; j--)
                {
                    for (int k = tamanho-1; k > tamanho-tms-2; k--)
                    {
                        if (sufixo[i][j] == palavra[k])
                        {
                            contis += 1;
                            break;
                        }
                    }
                    
                }
                // printf("%d - %d\n", contis, tms);
                if (contis == tms)
                {
                     
                    if(tamanho-tms == 0){
                        palavra[0] = '\0';
                    }else{
                        palavra[tamanho-tms-1] = '\0';
                    }
                } 
                contis = 0;      
            }
        }        
        printf("%s\n", palavra);


        fgets(palavra, 101, stdin);
        tamanho = strlen(palavra);
        palavra[tamanho-1] = '\0';
    }
    
    return 0;
}