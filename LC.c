/*                */
/* Arquivo: 
   Autores: Gabriel Cavalcanti Francisco
   		    Gabriel Sales Costa
   		    Ricardo Veiga Coelho
   Date: 20/05/22 08:16
   Descricao: 
   
*/
#include <stdlib.h>
#include "booleano.h"
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

Lista criarLista(){
	Lista A;
	A = NULL;
	return A;
}

bool listaVazia(Lista p){
	bool b;
	if(p==NULL) b=true;
	else b=false;
	return b;
}

void mostrarLista(Lista p){		// a partir do primeiro
	Lista apont;
	int k;
	if(p == NULL) 
	printf("lista vazia \n");
	else{ 
		printf("\n lista = ");
		apont= p;
		do {
			k = apont->valor;
			printf(" %d ", k);
			apont= apont->next;
		} while(apont!= p);
	}
	printf("\n");
}

//guardar ponteiro em uma variavel auxiliar para poder usar free()
void Insere(Lista A, int val){
	Celula *prox; prox = malloc(sizeof(Celula));
	prox->valor = val;
	
	A->next = prox;
}



int main(){
	return 0;
}