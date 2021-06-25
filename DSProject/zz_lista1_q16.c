#include "z_arvED.h"


int ed_arv_soma(TipoNoArv* a){
	int somaEsq, somaDir;
	if(a == NULL){
		return 0;
		}
	else {
		somaEsq = ed_arv_soma(a->esq);
		somaDir = ed_arv_soma(a->dir);
		return somaEsq + somaDir + a->reg.chave;
	}
}
