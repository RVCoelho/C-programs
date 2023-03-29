#include <stdio.h>
#include <stdlib.h>
#define max 4
#define hashCode(k,M) (k%1000)%M

int main(){
    char *chave, *valor;
    char *codigo;
    int i,k,hc,M;
    char* LISTA[max]={"RA0029574", "YUCAI", "RA00297501", "BRUNO"};
        printf("\n chave        valor - hashCode \n\n");
        for(i=0;i<=2;i=i+2){
            chave=LISTA[i];
            valor=LISTA[i+1];

            k=convRA(chave);

            M=37;

            hc=hashCode(k,M);
        }
}

int convRA(char ch){
    if(strlen(ch)!=9)
        printf("RA invalido!");
    else if()
}