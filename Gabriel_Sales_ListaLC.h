//GRUPO 12 - LISTA CIRCULAR
/*                */
/* Arquivo: 
   Autor: GABRIEL SALES COSTA, Ricardo Veiga Coelho
   Date: 20/05/22 09:22
   Descrição: 
   
*/

#define ghost -1
#include "booleano.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
	int valor;
	struct Celula* next;
	
} Celula;

typedef Celula* Lista;

Lista criarLista();
int determinarTamanho(Lista p);
bool listaVazia(Lista);
void mostrarLista(Lista);
Celula* buscarItem(Lista, int);
int obterItemK(Lista, int); 
Lista insere(Lista, int); 
Lista removerItem(Lista, int);
Lista esvaziarLista(Lista); //free() em todas as celulas
 
int main(){
	
	Lista A = criarLista();
	bool vazia = listaVazia(A);
	
	if(vazia == true)
		printf("\nvazia\n");
		
	A = insere(A, 4);
	A = insere(A, 1);
	A = insere(A, 2);
	A = insere(A, 5);
	A = insere(A, 7);
	A = insere(A, 6);
	A = insere(A, 3);
	A = insere(A, 10);
	A = insere(A, 8);
	A = insere(A, 9);

	mostrarLista(A);
	
	int tam = determinarTamanho(A);
	
	printf("\n%d\n", tam);
	
	int item = obterItemK(A, 4);
	
	printf("\n%d\n", item);
	
	A = removerItem(A, 10);
	
	mostrarLista(A);
	return 0;
}

Lista criarLista(){
	Lista A;
	A = NULL;
	
	return A;
}

int determinarTamanho(Lista p){
	int tamanho = 0;
	Lista apontador;
	
	if(p != NULL){
		apontador = p;
		
		do{
			apontador = apontador->next;
			tamanho++;
			
		} while(apontador != p);	
	}
	
	return tamanho;
}

bool listaVazia(Lista p){
	bool vazia = false;
	
	if(p == NULL)
		vazia = true;
	
	return vazia;	
}

void mostrarLista(Lista p){
	Lista apontador;
	
	if(p != NULL){
		apontador = p;
		
		do{
			int n = apontador->valor;
			printf(" %d ", n);
			
			apontador = apontador->next;
		} while(apontador != p);
	}
	else
		printf("\n Lista vazia \n");
}

Celula* buscarItem(Lista p, int item){
	Lista apontador;
	Celula *novo;
	
	if(p != NULL){
		apontador = p;
		
		do{
			apontador = apontador->next;	
		} while(apontador != p && apontador->valor != item);
		
		novo = apontador;
	}
	
	else{
		novo = NULL;
	}
	return novo;
}

int obterItemK(Lista p, int pos){
	Lista apontador;
	int item;
	int k = 1;
	
	if(p != NULL){
		apontador = p;
		
		do{
			apontador = apontador->next;
			k++;
		} while(apontador != p && k != pos);
		
		item = apontador->valor;
	}
	
	return item;
}

Lista insere(Lista p, int item){
	Lista apontador;
	Celula *novo;
	novo = malloc(sizeof(Celula));
	novo->valor = item;

	if(p == NULL){ 
		novo->next = novo;
		p = novo;
	}
	else{
		//inserir no inicio e mudar a ligacao do ultimo
		novo->next = p;
		apontador = p;
		
		do {
			apontador = apontador->next;
		} while(apontador->next != p);
		
		apontador->next = novo;
		
		p = novo;
	}	
	
	return p;
}

Lista removerItem(Lista p, int item){
	Lista apontador, anterior;
	
	if(p != NULL){
		apontador = p;
		
		do{
			anterior = apontador;
			apontador = apontador->next;
		} while(apontador->next != p && apontador->valor != item);
				
		anterior->next = apontador->next;
		free(apontador);	
	}
	
	return p;
}

//esvaziarLista() -> free() em todas as celulas
Lista esvaziarLista(Lista p){
	Lista apontador, anterior;
	
	if(p != NULL){
		apontador = p;
		
		do{
			anterior = apontador;
			apontador = apontador->next;
			free(anterior);
		}while(apontador != p);
		
		free(apontador);
		p = NULL;
	}
	
	return p;
}
