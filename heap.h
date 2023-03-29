#include <stdio.h>
#include "booleano.h"
#define MAX 10

typedef struct{
    int tamanho;
    int tab[MAX];
}Heap;

Heap criarHeapMaxima();
void inserirHeap(Heap*,int);
void retirarHeap(Heap*);
int obterMaximo(Heap*);
void aumentarChave(Heap*,int,int);//1o param: heap, 2o param: indice a ser aumentado, 3o param: valor que sera acrescido ao elemento
void diminuirChave(Heap*,int,int);
void mostrarHeap(Heap*);
void construirHeap(Heap*,int[ ],int); // insere um a um os itens na Heap
void restaurarTotalHeap(Heap*);
void restaurarHeapAbaixo(Heap*,int,int);
void restaurarHeapAcima(Heap*,int,int);

Heap criarHeapMaxima(){
    Heap H;
    H.tamanho=0;
    return H;
}

void inserirHeap(Heap *h, int y){
    h->tamanho+=1;
    int p=h->tamanho;
    h->tab[p]=y;
}

void retirarHeap(Heap *h){

}

int obterMaximo(Heap *h){
    if(h->tamanho!=0)
        return h->tab[1];
}

void aumentarChave(Heap *h, int y, int k){
    if(h->tamanho>=y)
        h->tab[y]+=k;
}

void diminuirChave(Heap *h, int y, int k){
    if(h->tamanho>=y)
        h->tab[y]-=k;
}

void mostrarHeap(Heap *h){
    int i, tam;
    tam=h->tamanho;
    if(tam!=0){
        printf("[");
        for(i=1;i<=tam;i++)
            printf("%d, ", h->tab[i]);
        printf("]\n");
    }else printf("Heap vazia.\n");
}

/*void construirHeap(heap *h, int a[], int y){

}*/

void restaurarTotalHeap(Heap *h){
    int pai, i, j, e, d, f;
    bool fim;
    fim = false;
    pai=h->tamanho/2;
    for(i=pai;i>=1;i--){
        j=i;
        while(j<=pai && fim==false){
            e=2*j;
            d=2*j+1;
            f=e;
            if()
        }
    }
}