#include "z_arvED.h"


/* vers�o criando uma nova �rvore
   (muito simular a copia, com as mesmas considera��es
   sobre tratamento de exce��es de aloca��po de mem�ria 
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


/* vers�o que n�o copia, mas altera a pr�pria �rvore
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
