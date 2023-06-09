#include<stdio.h>
#include<stdlib.h>
#include<time.h>
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
    //int matriz[][]={{7,8,4},{2,1,7},{9,3,2}};
    int **matriz1 = (int **) calloc(l1, sizeof(int*));
    int **matriz2 = (int **) calloc(l2, sizeof(int*));
    int **C;
    for(i=0;i<l1;i++)
        matriz1[i]=(int *) calloc(c1,sizeof(int));
    for(i=0;i<l2;i++)
        matriz2[i]=(int *) calloc(c2,sizeof(int));
    
    srand(time(NULL));

    for(i=0;i<l1;i++){
        for(j=0;j<c1;j++)
            matriz1[i][j]=rand()%10;
    }

    for(i=0;i<l2;i++){
        for(j=0;j<c2;j++)
            matriz2[i][j]=rand()%10;
    }
    
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
