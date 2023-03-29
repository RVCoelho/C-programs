#include <stdio.h>
#include <stdlib.h>
#include "booleano.h"

typedef struct celula{
    int item;
    struct celula * next;
}celula;

typedef struct lista{
    int tam;
    struct lista * inicio;
}lista;

lista criarLista();
void inserirInicio(lista *, int);
void inserirFim(lista *, int);
void removerInicio(lista *);
void removerFim(lista *);
void mostrarLista(lista *);
bool verificarVazio(lista *);
int obterTamanho(lista *);
int obterElemento(lista *, int);// devolve o elemento de ordem k
//celula buscarItem(lista *, int); // devolve o endereço do registro que contém o elemento y na lista

lista criarLista(){
    lista l;
    l.tam=0;
    l.inicio=NULL;
    return l;
}

void inserirInicio(lista *ap, int y){
    celula * novo;
    novo = malloc(sizeof(celula));
    novo->item = y;
    novo->next = ap->inicio;
    ap->inicio = novo;//aponta para a *CELULA*
    ap->tam = ap->tam+1;
}

void inserirFim(lista *ap, int y){
    celula *novo, *p;
    novo=malloc(sizeof(celula));
    novo->item=y;
    novo->next=NULL;
    //caso a lista esteja vazia:
    if(ap==NULL){
        novo->next = ap->inicio;
        ap->inicio = novo;
        ap->tam = ap->tam+1;
    }
    //caso a lista nao esteja vazia
    else{
        p=ap->inicio;
        while(p->next!=NULL) p=p->next;
        //novo->next = p->next;
        p->next = novo;
        ap->tam = ap->tam+1;
    }
}

void removerInicio(lista * ap){
    celula * prim, *seg;
    if(ap->inicio!=NULL){
        prim = ap->inicio;
        seg = prim->next;
        ap->inicio = seg;
        ap->tam=ap->tam-1;
        free(prim);
    }
}

void removerFim(lista *ap){
    celula * p,//pointer auxiliar
          *ult;//pointer auxiliar que aponta para a ultima celula
    if(ap->inicio!=NULL){
        p = ap->inicio;
        while(p->next!=NULL) p=p->next;
        ult=p;
        
        p=ap->inicio;
        while(p->next!=ult) p=p->next;
        p->next=NULL;

        ap->tam=ap->tam-1;
        free(ult);
    }
}

void mostrarLista(lista *ap){
    celula * p;
    p=ap->inicio;
    if(ap->inicio==NULL)  printf("lista vazia\n");
    else{    
        while(p!=NULL)  {
            printf("%d", p->item);
            p=p->next;
        }
    }
    printf("\n");
}

bool verificarVazio(lista *ap){
    bool vazio;
    if(ap->inicio==NULL) vazio=true;
    else vazio=false;
    return vazio;
}

int obterTamanho(lista *ap){
    return ap->tam;
}

int obterElemento(lista *ap, int k){
    celula *elem;
    int i;
    elem=ap->inicio;
    if(k>ap->tam) k=ap->tam;
    else if(k<0) k=0;
    for(i=0;i<k-1;i++)  elem=elem->next;
    return elem->item;
}

/*celula buscarItem(lista *ap, int y){
    celula *elem;
    elem=ap->inicio;
    //do{ elem=elem->next; }while(elem->item!=y);
    while(elem->item!=y) elem=elem->next;
    return *elem;
}*/