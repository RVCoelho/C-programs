#include <stdio.h>
#include "PilhaEncadeada.h"

int main(){
    Pilha p;
    p=criarPilha();
    pushPilha(&p, 1);
    mostrarPilha(&p);
    return 0;
}