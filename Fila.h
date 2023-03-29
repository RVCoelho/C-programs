/* Arquivo: Fila.h
   Autor: RICARDO VEIGA COELHO
   Date: 05/05/2022
   Descrição:  implementacao de funcoes de construcao, de acesso e de manipulacao de filas
*/

//diretivas
#include <stdio.h>
#include "booleano.h"

#define MaxFila 1000
#define sinal -1 //pode ser qualquer valor abaixo de 0
#define fantasma -1 //pode ser qualquer valor abaixo de 1

typedef struct{
    int inicio;
    int fim;
    char Vetor[MaxFila];
} Fila;

//interface
Fila criarFila();
bool FilaVazia(Fila);
unsigned char acessarPrimeiro(Fila);
Fila pushFila(Fila, char);
Fila popFila(Fila);
Fila esvaziarFila(Fila);
void mostrarFila(Fila);

//implementação
Fila criarFila(){
    Fila f;
    f.inicio= sinal;
    f.fim= sinal;
    return f;
}

bool FilaVazia(Fila f){
    bool vazia;
    vazia = false;
    if(f.inicio== sinal) vazia = true;
    return vazia;
}

unsigned char acessarPrimeiro(Fila f) {
    int p;
    char y;
    y = fantasma; 
    if( f.inicio!= sinal) {
        p = f.inicio;
        y = f.Vetor[p];
    }
    return y;
}

Fila pushFila(Fila f, char y) {
    int seg;
    seg= (f.fim+ 1) % MaxFila;
    if(seg!= f.inicio) {
        f.Vetor[seg] = y;
        if( f.inicio== sinal ) f.inicio= seg;
        f.fim= seg;
    }
    return f;
}

Fila popFila(Fila f) {
    int seg;
    if( f.inicio!= sinal ) {
        if( f.inicio== f.fim) {
            f.inicio= sinal;
            f.fim= sinal;
        }
        else{
            seg=(f.inicio+ 1) % MaxFila;
            f.inicio= seg;
        }
    }
    return f;
}

Fila esvaziarFila(Fila f){
    f.inicio=sinal;
    return f;
}

void mostrarFila(Fila f){
    int frente = f.inicio, tras = f.fim;
    if(f.inicio==sinal) printf("Fila vazia\n");
    if(frente<=tras){
        while(frente<=tras){
            printf("%d ", f.Vetor[frente]);
            frente++;
        }
    }
    else{
        while(frente<MaxFila-1){
            printf("%c ", f.Vetor[frente]);
            frente++;
        }
        frente=0;
        while(frente<=tras){
            printf("%c ", f.Vetor[frente]);
            frente++;
        }
    }
    printf("\n");
}