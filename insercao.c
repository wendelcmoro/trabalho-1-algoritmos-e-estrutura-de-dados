#include "biblioteca.h"

/* -------------------------------------------------------------------------- */
/* ordena v[a..b] pelo método da seleção e devolve v */

int busca_binaria(int x,int v[],int a,int b){
	if (a>b)
		return (a-1);
	int m=(a+b)/2;
	if (compara(x,v[m])==0)
		return m;
	if (compara(x,v[m])<0)
		return busca_binaria(x,v,a,m-1);
	return busca_binaria(x,v,m+1,b);
}

int *insere(int v[], int a, int b) {
	int p=busca_binaria(v[b],v,a,b-1);
	int i=b;
	while (i>p+1){
		troca(v,i,i-1);
		i=i-1;
	}
  return v;
}

int *insercao(int v[], unsigned int a, unsigned int b) {
	if (a>=b)
		return (v);
	insercao(v,a,b-1);
	insere(v,a,b);
  return v;
}
