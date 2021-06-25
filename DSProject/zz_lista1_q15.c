#include "z_arvED.h"


/* versão criando uma nova árvore
   (muito simular a copia, com as mesmas considerações
   sobre tratamento de exceções de alocaçãpo de memória 
*/

TipoNoArv* espelha(TipoNoArv *a) {
	
	TipoNoArv *defn;
	
	if (a == NULL) return NULL;
	else {
		defn = (TipoNoArv *) malloc(sizeof(TipoNoArv));
		defn->reg = a->reg;
		defn->esq = espelha(a->dir);
		defn->dir = espelha(a->esq);
		return defn;
	}
}


/* versão que não copia, mas altera a própria árvore
*/

TipoNoArv* espelha2(TipoNoArv *a) {
	if (a != NULL) {
		TipoNoArv *aux;
		aux = a->esq;
		a->esq = espelha2(a->dir);
		a->dir = espelha2(aux);
	}
	return a;
}
