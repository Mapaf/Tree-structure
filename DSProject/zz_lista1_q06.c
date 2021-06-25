#include "z_arvED.h"

int ed_iguais(TipoNoArv *a1, TipoNoArv *a2) {
	if (a1 == NULL && a2 == NULL) 
		return 1; // Return TRUE, as duas são vazias
	else
		if (a1 == NULL || a2 == NULL)
			return 0; // Return FALSE, uma é vazia e a outra não
		else 
		// se as duas não são vazias, checa as chaves
			if (a1->reg.chave != a1->reg.chave) 
				return 0; // Return FALSE, pois as chaves são diferentes
			else
				return // as duas sub-árvores devem ser iguais
					ed_iguais(a1->esq,a2->esq) &&
					ed_iguais(a1->dir,a2->dir);
}
