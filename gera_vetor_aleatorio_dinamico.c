#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void vetorAleatorio(int **vetor, int *tam);

void vetorAleatorio(int **vetor, int *tam){
    int i;
    //time_t t;
    *vetor=(int*) malloc(*tam * sizeof(int));
    srand(time(NULL));
    
    for(i=0;i<*tam;i++)
        (*vetor)[i]=rand()%1000;
    //return vetor;
}

int main()
{
    int i, tamanho=10, *vetor;
    vetorAleatorio(&vetor,&tamanho);
    
    for(i=0;i<tamanho;i++)
        printf("vetor[%d]= %d\n",i, vetor[i]);
    
    free(vetor);
    return 0;
}