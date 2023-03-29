#include "ListaLigada.h"
#include <stdio.h>

int main(){
    lista l;
    //bool vz;
    l=criarLista();
    /*vz=verificarVazio(&l);
    if(vz=true) printf("true\n");
    else printf("false\n");
    printf("%d", vz);*/
    inserirInicio(&l, 4);
    mostrarLista(&l);
    inserirInicio(&l, 6);
    mostrarLista(&l);
    inserirFim(&l, 2);
    mostrarLista(&l);
    removerFim(&l);
    mostrarLista(&l);
    /*vz=verificarVazio(&l);
    if(vz==true) printf("true\n");
    else printf("false\n");
    int tamanho = obterTamanho(&l);
    printf("%d", tamanho);*/
    /*int elem;
    elem=obterElemento(&l, 2);
    printf("elemento na 1ª posicao: %d\n", elem);*/
    /*celula cel;
    cel=buscarItem(&l, 2);
    printf("%d", cel.item);*/
    return 0;
}