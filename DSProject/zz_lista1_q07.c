#include "z_arvED.h"

/*
   n�o estou checando erros de aloca��o de mem�ria
   para fazer isto teremos bem mais trabalho
*/

TipoNoArv* copia(TipoNoArv *a) {
	
	TipoNoArv *defn;
	
	if (a == NULL) return NULL;
	else {
		defn = (TipoNoArv *) malloc(sizeof(TipoNoArv));
		defn->reg = a->reg;
		defn->esq = copia(a->esq);
		defn->dir = copia(a->dir);
		return defn;
	}
}



/*
	Vers�o com checagem de erro de aloca��o
*/
void destroi_arv(TipoNoArv *a) {
	if (a == NULL) return;
	else {
		destroi_arv(a->esq);
		destroi_arv(a->dir);
		free(a);
	}
}

/*
	Vers�o de copia com desaloca��o de mem�ria em caso de erro
*/

int copia2(TipoNoArv *origem, TipoNoArv *destino) {

	destino = NULL;
	
	if (origem == NULL) return 1; // copia bem sucedida 
	else {
		destino = (TipoNoArv *) malloc(sizeof(TipoNoArv));
		if (destino == NULL) { // Erro de alocacao
			return 2;
		}
		if (copia2(origem->esq, destino->esq) != 1) {
			free(destino); // erro de aloca��o na sub-�rvore da esq
			return 2;
		} else {
			if (copia2(origem->dir, destino->dir) != 1) {
				destroi_arv(destino->esq); // desaloca sub-�rvore da esquerda
				free(destino); // erro de aloca��o na sub-�rvore da dir
				return 2;
			} else { 
					destino->reg = origem->reg;
					return 1; // c�pia bem sucedida
				}
			}
		}
	}

