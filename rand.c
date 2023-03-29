/* método de congruência linear
  Arquivo: ALEATORIO.c
  Autor: Ricardo Veiga Coelho
  Date: 27/01/22 14:40
  Descrição: gerador de numeros pseudoaleatorios
  exemplos m=44497, m = 127  com a = 31 e y = 1
  ciclo 14833, ciclo 64
*/

#include <stdio.h>
#define N 101

int main(){
    int a,m,y,c,aux,tam;
    int tab[N];  //o array tab armazena os números gerados aleatoriamente
    int k,cont,rep,i,fim;
//	a = 31; m = 44497; c = 0;		//em 10000 números não há repetição
//	a = 389; m = 31; c = 0;	
	a = 31; m = 127; c = 0;
	y = 1;  aux = y; cont = 0; rep = 1;	// a primeira repetição ocorre para k = 14833
	printf("\n  a = %d  m = %d  y = %d   \n\n\n",a,m,y); 
	tab[0]=N-1;  
	for(k=1;k<=N;k++){
		tab[k]=y;
//		if(y == aux) { printf("\n igual k = %d  \n",k); rep = k;}
//		cont++;
		y = (a*y + c) % m;
//		printf("%5d ",y);
		
//
// 		if(cont > 9) {
//						printf("\n ");
//						cont = 1;
//		}
	}
	cont=0;
	for(i=1;i<=N-1;i++){
		printf(" %5d ",tab[i]);
		cont++;
		if (cont > 9){
			cont = 0;
			printf("\n");
		}
	}
	fim = 0;
	k=1; tam = tab[0]; rep = 0;
	while ( (k < tam) && (fim == 0) ){
		i = k+1;
		while ( (i < tam) && (tab[i] != tab[k]) ) { i++;}
		if (tab[i] == tab[k]) {
			fim = 1;
			printf("\n\n repetidos i = %d  k = %d  \n",k,i);
			rep = tab[i];
		}
		else k++;
	}
	if (fim == 1) {
		printf("\n\n tem repetido %d \n",rep);
	}
	else printf("\n\n ok \n");
	

//    printf("\n\n\n rep = %d ",rep);
	printf("\n\n  FIM  \n");           
    return 0;
}