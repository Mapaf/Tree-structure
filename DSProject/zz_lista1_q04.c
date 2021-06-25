#include "z_arvED.h"


/*
   Resposta para questão 4
*/

TipoNoArv* localiza(int x, TipoNoArv *atual) {
	
	TipoNoArv* reg;
	
	if (atual == NULL) return NULL;
	else
		if (atual->reg.chave == x) return atual;
		else {
			reg = localiza(x,atual->esq);
			if (reg == NULL) return localiza(x,atual->dir);
			else return reg;
		};
}
