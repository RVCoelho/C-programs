#include <stdio.h>
#include <stdlib.h>
#include "booleano.h"

typedef struct Celula{
    int item;
    struct Celula* next;
} Celula;

typedef Celula* Pilha;

Pilha criarPilha();

unsigned char acessarTopo(Pilha *);
bool verificarPilhaVazia(Pilha *);
int obterProfundidade(Pilha *);
void mostrarPilha(Pilha *);

void pushPilha(Pilha *, int);
void popPilha(Pilha *);
void inverterPilha(Pilha *);
void copiarPilha(Pilha *, Pilha *);
void esvaziarPilha(Pilha *);

Pilha criarPilha(){
    Pilha p;
    p=NULL;
    return p;
}

void pushPilha(Pilha *ap, int y){
    Celula *cel;
    
    cel = (Celula*) malloc(sizeof(Celula));
    if(cel!=NULL){
        cel->item=y;
        cel->next=ap;
        ap=cel;
    }
}

void mostrarPilha(Pilha *P){
    Celula * cel;
    cel=P;
    if(cel==NULL)  printf("Pilha vazia\n");
    else{    
        do{
            printf("%d\n", cel->item);
            cel=cel->next;
        }while(cel!=NULL);
    }
    printf("\n");
}