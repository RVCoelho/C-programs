#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int **somaMatriz(int **matriz1, int **matriz2, int lin, int col);

int **somaMatriz(int **matriz1, int **matriz2, int lin, int col){
    int i, j;
    int **c= (int **) calloc(lin, sizeof(int *));
    for(i=0;i<lin;i++)
        c[i] = (int *) calloc(col, sizeof(int));
    
    for(i=0;i<lin;i++){
        for(j=0;j<col;j++)
            c[i][j]=matriz1[i][j]+matriz2[i][j];
    }
    return c;
}
int main()
{
    int l=2,c=4,i,j;
    //int matriz[][]={{7,8,4},{2,1,7},{9,3,2}};
    int **matriz1 = (int **) calloc(l, sizeof(int*));
    int **matriz2 = (int **) calloc(l, sizeof(int*));
    int **soma;
    for(i=0;i<l;i++)
        matriz1[i]=(int *) calloc(c,sizeof(int));
    for(i=0;i<l;i++)
        matriz2[i]=(int *) calloc(c,sizeof(int));

    srand(time(NULL));

    for(i=0;i<l;i++){
        for(j=0;j<c;j++)
            matriz1[i][j]=rand()%10;
    }

    for(i=0;i<l;i++){
        for(j=0;j<c;j++)
            matriz2[i][j]=rand()%10;
    }

    for(i=0;i<l;i++){
        printf("[ ");
        for(j=0;j<c;j++)
            printf("%2d ", matriz1[i][j]);
        printf("]\n");
    }
    printf("\n");
    for(i=0;i<l;i++){
        printf("[ ");
        for(j=0;j<c;j++)
            printf("%2d ", matriz2[i][j]);
        printf("]\n");
    }
    printf("\nsoma:\n");
    
    soma=somaMatriz(matriz1, matriz2, l, c);
    
    for(i=0;i<l;i++){
        printf("[ ");
        for(j=0;j<c;j++)
            printf("%2d ", soma[i][j]);
        printf("]\n");
    }
    
    return 0;
}
