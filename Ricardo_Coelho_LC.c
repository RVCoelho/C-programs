#include <stdlib.h>
#include "Booleano.h"

#define ghost -1
typedef struct Celula{
    int valor;
    struct Celula* next;
} Celula;
typedef Celula* Lista;

Lista criarLista();
int determinarTamanho(Lista);
bool listaVazia(Lista);
void mostrarLista(Lista);
Celula* buscarItem(Lista, int);
int obterItemK(Lista, int);
void Insere(Lista, int);
void removerItem(Lista, int);
void esvaziarLista(Lista);