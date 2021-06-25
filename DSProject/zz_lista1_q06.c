#include "z_arvED.h"

int ed_iguais(TipoNoArv *a1, TipoNoArv *a2) {
	if (a1 == NULL && a2 == NULL) 
		return 1; // Return TRUE, as duas s�o vazias
	else
		if (a1 == NULL || a2 == NULL)
			return 0; // Return FALSE, uma � vazia e a outra n�o
		else 
		// se as duas n�o s�o vazias, checa as chaves
			if (a1->reg.chave != a1->reg.chave) 
				return 0; // Return FALSE, pois as chaves s�o diferentes
			else
				return // as duas sub-�rvores devem ser iguais
					ed_iguais(a1->esq,a2->esq) &&
					ed_iguais(a1->dir,a2->dir);
}
