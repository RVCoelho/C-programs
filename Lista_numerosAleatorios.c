/* Arquivo: Numeros aleatorios
Autor: Ricardo Veiga Coelho
Data: 18/3/22
Descricao: cria lista de numeros aleatorios
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Max 11

typedef struct{
    int tam;
    int tabela[Max]
}Lista;

//interface
Lista criarListaVazia();
Lista criarListaAleatoria(int, int, int);//(quant de numeros desejados,menor numero possivel,maior numero possivel)
void mostrarLista(lista);

int main(){
    Lista L1, L2;
    L1= criarListaVazia();
    L2=criarListaAleatoria(15,100,300);

    printf("Lista L1 \n");
    mostrarLista(L1);
    printf("\n");

    printf("Lista L2 \n");
    mostrarLista(L2);

    printf("\n\n fim");
    return 0;
}

Lista criarListaVazia(){
    Lista L;
    L.tam=0;
    return L;
}

Lista criarListaAleatoria(int N, int a, int b){
    Lista L;
    int tam;
    double d;
    if(N>Max)
        L.tam = Max-1;
    else L.tam=N;
    srand((int) time(NULL));

    L.tam=tam;

}


