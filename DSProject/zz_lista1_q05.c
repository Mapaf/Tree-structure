#include "z_arvED.h"

int distorcida(TipoNoArv *atual) {

	if (atual == NULL) return 1; // return True
	else
		if ((atual->dir != NULL) &&
		    (atual->esq != NULL)) return 0; // return False
		else
			if ((atual->dir == NULL) &&
		    	(atual->esq == NULL)) return 1; // return True
		    else
				if (atual->dir == NULL) 
					return distorcida(atual->esq); // continua checando
				else 
					return distorcida(atual->dir); // continua checando

}
