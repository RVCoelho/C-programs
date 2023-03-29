#define Max 10
#define Sinal 0
#define fantasma -9999.99
#include "Booleano.h"
#include <time.h>
#include <stdlib.h>

typedef struct {
      int topo;
      int tabela[Max];
} Pilha;

void criarPilhaVazia(Pilha *);
float acessarTopo(Pilha *);
bool PilhaVazia(Pilha *);
void pushPilha(Pilha *, int);
void popPilha(Pilha *);
Pilha inverter(Pilha, int);
int contarPilha(Pilha, int);
Pilha construirPilha(int);

Pilha inverter(Pilha *ap, int n){
     Pilha *aux; aux->topo = Sinal;
     if (ap->topo != Sinal)
     {
          for (int i = 0; i < n; i++)
          {
               int topoAux = aux->topo;
               int topoAp = ap->topo;
               //passa o valor no topo da pilha ap para o fim da pilha auxiliar
               aux->tabela[topoAux] = ap->tabela[topoAp];
               aux->topo = topoAux+1;
               //retira um valor do topo da pilha ap
               ap->topo = topoAp-1;
          }
     }
     //return aux
}

int contarPilha(Pilha *ap, int val){
     int cont; cont = 0;
     int k, j; k = ap->topo;
     while (ap->tabela[k] != val) {
          ap->topo = k-1;
          cont++;
     }
     return cont;
}

Pilha construirPilha(int n){
     srand((int) time(NULL));
     Pilha *p; p->topo = Sinal;
     int k = p->topo;
     if (n <= Max)
     {
          for (int i = 0; i < n; i++)
          {
               int num = (rand() % Max-1);
               p->tabela[k] = num;
               p->topo = k + 1;
          }
     }
}

void criarPilhaVazia(Pilha *ap){
     ap->topo = Sinal;
}


float acessarTopo(Pilha *ap){
    int k;
    float y;
    if (ap->topo == Sinal) y = fantasma;
    else {k = ap->topo - 1; y = ap->tabela[k];}
    return y;
}     

bool PilhaVazia(Pilha *ap){
     bool vazia;
     if (ap->topo == Sinal) vazia = true; else vazia = false;
     return vazia;
}

void pushPilha(Pilha *ap, int y){
     int k; 
     if(ap->topo != Max){
                 k = ap->topo;
                 ap->tabela[k] = y;
                 ap->topo = k + 1;
     }
}

void popPilha(Pilha *ap){
     int k;
     if (ap->topo != Sinal){
                   k = ap->topo;
                   ap->topo = k-1;
     }                   
}