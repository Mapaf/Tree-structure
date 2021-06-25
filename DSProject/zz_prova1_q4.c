#include <stdio.h>
#include "z_arvED.h"


 int ed_arv_buscaRank(int rank, TipoNoArv *atual, TipoRegistro *reg) {
  
	if (atual == NULL) return rank;
	else {
		int newRank;
		newRank = ed_arv_buscaRank(rank, atual->esq, reg);
		if (newRank == 0) {
				return 0; // encontrado
		} else {
			newRank--;
			if (newRank == 0) {	// ele é o elemento procurado
				*reg = atual->reg;
				return 0; // encontrado
			} else return ed_arv_buscaRank(newRank, atual->dir, reg);
		}
	}
}
