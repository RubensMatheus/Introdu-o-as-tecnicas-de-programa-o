#include <string.h>
#include <stdio.h>

int pac_man(int lin, int col, char mapa[lin][col], int x,int y, int * cont){
   
    if(x-1>=0 && mapa[x-1][y]=='.'){
        mapa[x-1][y]=' ';
        (*cont)++;
        pac_man(lin,col,mapa,x-1,y,cont);
    }
    
    if(y-1>=0 && mapa[x][y-1]=='.'){
        mapa[x][y-1]=' ';
        (*cont)++;
        pac_man(lin,col,mapa,x,y-1,cont);
    }
    
   if(x+1<lin && mapa[x+1][y]=='.'){
        mapa[x+1][y]=' ';
        (*cont)++;
        pac_man(lin,col,mapa,x+1,y,cont);
    }
    
    if(y+1<col && mapa[x][y+1]=='.'){
        mapa[x][y+1]=' ';
        (*cont)++;
        pac_man(lin,col,mapa,x,y+1,cont);
    }
    
    return 0;
}

int main(){
    int lin,col,posx,posy,chegou;
    int cont=0;
    
    scanf("%d\n%d\n", &lin,&col);
    
    char mapa[lin][col];
    
    for(int i=0;i<lin;i++)
        for(int j=0;j<col;j++){
            scanf("%c\n", &mapa[i][j]);
            if(mapa[i][j]=='C'){
                posx = i;
                posy = j;
            }
        }
        
    pac_man(lin,col,mapa,posx,posy,&cont);
     
    printf("Total de bolinhas devoradas: %d\n",cont);
    printf("Mapa final:\n");
     
    for(int i=0;i<lin;i++){
        for(int j=0;j<col;j++){
            printf("%c", mapa[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}