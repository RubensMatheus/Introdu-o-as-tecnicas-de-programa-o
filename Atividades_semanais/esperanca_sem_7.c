#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define tamMAX 201
#define tamCHAVE 21

int confere_chave(char*chave){
    int tamanho,valor;
   
    fgets(chave, tamCHAVE-1, stdin);
    chave[strlen(chave)-1] = '\0';
    valor = atoi(chave);
    
    if(valor<0 || valor>9999){
        printf("Chave invalida!");
            return 1;
        }
   return 0;
}

int confere_msg(char * msgP,const char * S){
    
    int tamanho, confereP;
    char * teste;
    fgets(msgP, tamMAX-1, stdin);
    tamanho = strlen(msgP);
    msgP[tamanho-1] = '\0';
    
   for(int i=0;i<tamanho-1;i++){
       confereP=0;
       teste = strchr(S,msgP[i]);
       if(strchr(S,msgP[i])==NULL){
           printf("Caractere invalido na entrada!");
            return 1;
       }
    }
    
    return 0;
}

int main(){
    
    char chaveK[tamCHAVE] = {0};
    char msgP[tamMAX] = {0};
    int count,vchave;
    
    const char S[] = {'0','1','2','3','4','5','6','7','8','9',
        'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O',
        'P','Q','R','S','T','U','V','W','X','Y','Z','.',',','?',' ','\0'};
        
   if(confere_chave(chaveK) || confere_msg(msgP, S)){
       return 0;
    }

    int chaveNova[strlen(msgP)];
    char P[strlen(msgP)];
       
    count=0;
       
    for(int i=0;i<strlen(msgP);i++){
        chaveNova[i] = chaveK[count] - '0';
        count++;
        if(count==4)
            count = 0;
    }
    
    for(int i=0;i<strlen(msgP);i++){
        for(int j=0;j<strlen(S);j++){
          if(msgP[i] == S[j]){
              if(j+chaveNova[i]>strlen(S)-1)
                P[i] = S[(j+chaveNova[i])%(strlen(S)-1)-1];
              else
                P[i] = S[j+chaveNova[i]];
              
           }
        }
    }  
    
    P[strlen(msgP)] = '\0';
    
    printf("%s", P);
    
    return 0;
}