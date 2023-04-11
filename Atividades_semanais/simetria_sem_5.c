#include <stdio.h>

int pertence(int x, int tam, int* conjunto){
    
    int i;
    
    for(i=0;i<tam;i++){
        if(x==conjunto[i])
            return 1;
    }
    
    return 0;
}

void diferenca_simetrica(int tamA, int tamB, int* A, int* B){
    int i,j,f,qtd,aux=0,aux2=0;
    
    qtd = tamA + tamB;
    
    int dif[qtd];
    
    for (i=0;i<tamA; i++){
        if(!pertence(A[i], tamB, B)){
            dif[aux] = A[i];
            aux++;
        }else{
            qtd--;
        }
    }
    
    for (j=0;j<tamB; j++){
         if(!pertence(B[j], tamA, A)){
            dif[aux] = B[j];
            aux++;
        }else{
            qtd--;
        }
    }
    
    for(i=0;i<qtd-1;i++){
        for(j=i+1;j<qtd;j++){
            if(dif[i]>dif[j]){
                aux = dif[i];
                dif[i] = dif[j];
                dif[j] = aux;
            }
        }
    }
    
    for(f=0;f<qtd;f++){
        printf("%d ", dif[f]);
    }
}

int main(){
    
    int n,m,i,j;
    
    scanf("%d %d", &n, &m);
    
    int A[n],B[m];
    
    for(i=0;i<n;i++){
        scanf("%d", &A[i]);
    }
    
    for(j=0;j<m;j++){
        scanf("%d", &B[j]);
    }
    
    diferenca_simetrica(n,m,A,B);
    
    return 0;
}