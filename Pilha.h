/* Arquivo: Pilha.h
   Autor: RICARDO VEIGA COELHO
   Date: 29/04/2022
   Descrição:  implementacao de funcoes de construcao, de acesso e de manipulacao de pilhas
    ***os elementos da pilha são colocados a partir da posição 0 do array
*/

//diretivas
#include <stdio.h>
#include "booleano.h"
#include "Fila.h"

#define MaxPilha 1000
#define sinal -1 //pode ser qualquer valor abaixo de 0
#define fantasma -1 //pode ser qualquer valor abaixo de 1

typedef struct {
    int topo;
    unsigned char Vetor[MaxPilha];
} Pilha;

//interface
Pilha criarPilha();
bool PilhaVazia(Pilha);
unsigned char acessarTopo(Pilha);
Pilha pushPilha(Pilha, int);
Pilha popPilha(Pilha);
Pilha esvaziarPilha(Pilha);
void mostrarPilha(Pilha);
Pilha inverter(Pilha, int);

//implementação
Pilha criarPilha(){
    Pilha p;
    p.topo=sinal;
    return p;
}

bool pilhaVazia(Pilha A){
	bool vazia = false;
	
	if(A.topo == sinal)
		vazia = true;
		
	return vazia;
}

int acessarTopo(Pilha p){
    int n;
    if(p.topo!=sinal){
        n=p.Vetor[p.topo];
        return n;
    }
    else return fantasma;
}

Pilha pushPilha(Pilha p, int n){
    if(p.topo!=MaxPilha-1){
        p.topo++;
        p.Vetor[p.topo]=n;
    }
    return p;
}

Pilha popPilha(Pilha p){
    if(p.topo!=sinal) p.topo--;
    return p;
}

Pilha esvaziarPilha(Pilha p){
    p.topo=sinal;
    return p;
}

void mostrarPilha(Pilha p){
    int n;
    n=p.topo;
    //printf("Tamanho da pilha: %d\n", n);
    if(n==sinal) printf("Pilha vazia\n");
    else{
        for(int i=0;i<=n;i++)
            printf("%c", p.Vetor[i]);
        printf("\n");
    }
}

/*Pilha inverter(Pilha p, int n){
    Pilha aux;
    aux.topo=sinal;
    char ch;
    int i, j;
    j=p.topo;
    if(p.topo!=sinal){
        for(i=0;i<=p.topo-n;i++) aux.Vetor[i]=p.Vetor[i];//copia o comeco da pilha original ate antes do inicio da inversao
        //aux.topo=p.topo-n;
        for(i=p.topo-n;i<p.topo;i++){
            aux.Vetor[j]=p.Vetor[i+1];
            j--;
        }
        aux.topo=p.topo;
    }
    return aux;
}*/
