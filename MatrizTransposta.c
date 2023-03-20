#include<stdio.h>
#include<stdlib.h>

int **geraTransposta(int **matriz, int lin, int col);

int **geraTransposta(int **matriz, int lin, int col){
    int i, j;
    int **transposta = (int **) calloc(lin, sizeof(int *));
    for(i=0;i<lin;i++)
        transposta[i] = (int *) calloc(col, sizeof(int));
    
    for(i=0;i<lin;i++){
        for(j=0;j<col;j++)
            transposta[i][j]=matriz[j][i];
    }
    return transposta;
}

int main()
{
    int l=3,c=3,i,j;
    //int matriz[][]={{7,8,4},{2,1,7},{9,3,2}};
    int **matriz = (int **) calloc(l, sizeof( int*));
    
    int **transposta;
    for(i=0;i<l;i++)
        matriz[i]=(int *) calloc(c,sizeof(int));
    matriz[0][0]=7;
    matriz[0][1]=8;
    matriz[0][2]=4;
    matriz[1][0]=2;
    matriz[1][1]=1;
    matriz[1][2]=7;
    matriz[2][0]=9;
    matriz[2][1]=3;
    matriz[2][2]=2;
    
    for(i=0;i<l;i++){
        printf("[ ");
        for(j=0;j<c;j++)
            printf("%d ", matriz[i][j]);
        printf("]\n");
    }
    printf("\n");
    transposta=geraTransposta(matriz, l, c);
    
    for(i=0;i<l;i++){
        printf("[ ");
        for(j=0;j<c;j++)
            printf("%d ", transposta[i][j]);
        printf("]\n");
    }
    
    return 0;
}
