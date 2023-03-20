#include<stdio.h>
#include<stdlib.h>

int **multiplicaMatriz(int **matriz1, int **matriz2, int lin1, int col1, int lin2, int col2);

int **multiplicaMatriz(int **matriz1, int **matriz2, int lin1, int col1, int lin2, int col2){
    int i, j,k;
    int **C= (int **) calloc(lin1, sizeof(int *));
    for(i=0;i<lin1;i++)
        C[i] = (int *) calloc(col2, sizeof(int));
    
    for(i=0;i<lin1;i++){
        for(j=0;j<col2;j++)
            C[i][j]=0;
    }
    
    for(i=0;i<lin1;i++){
        for(j=0;j<col2;j++){
            for(k=0;k<col1;k++)
                C[i][j]+=matriz1[i][k]*matriz2[k][j];
        }
    }
    return C;
}

int main(){
    int l1=2,c1=4,i,j, l2=4, c2=3;
    int **matriz1 = (int **) calloc(l1, sizeof(int*));
    int **matriz2 = (int **) calloc(l2, sizeof(int*));
    int **C;
    for(i=0;i<l1;i++)
        matriz1[i]=(int *) calloc(c1,sizeof(int));
    for(i=0;i<l2;i++)
        matriz2[i]=(int *) calloc(c2,sizeof(int));
    
    matriz1[0][0]=7;
    matriz1[0][1]=8;
    matriz1[0][2]=4;
    matriz1[0][3]=9;
    matriz1[1][0]=2;
    matriz1[1][1]=1;
    matriz1[1][2]=7;
    matriz1[1][3]=3;
    
    matriz2[0][0]=6;
    matriz2[0][1]=9;
    matriz2[0][2]=4;
    matriz2[0][3]=2;
    matriz2[1][0]=8;
    matriz2[1][1]=4;
    matriz2[1][2]=9;
    matriz2[1][3]=4;
    matriz2[2][0]=7;
    matriz2[2][1]=3;
    matriz2[2][2]=5;
    matriz2[2][3]=1;
    
    
    for(i=0;i<l1;i++){
        printf("[ ");
        for(j=0;j<c1;j++)
            printf("%1d ", matriz1[i][j]);
        printf("]\n");
    }
    printf("\n");
    for(i=0;i<l1;i++){
        printf("[ ");
        for(j=0;j<c2;j++)
            printf("%1d ", matriz2[i][j]);
        printf("]\n");
    }
    printf("\n multiplicacao:\n");
    
    C=multiplicaMatriz(matriz1, matriz2, l1, c1, l2, c2);
    
    for(i=0;i<l1;i++){
        printf("[ ");
        for(j=0;j<c2;j++)
            printf("%3d ", C[i][j]);
        printf("]\n");
    }
    
    return 0;
}