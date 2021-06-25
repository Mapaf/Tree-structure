#include "z_arvED.h"

/*
   não estou checando erros de alocação de memória
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
	Versão com checagem de erro de alocação
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
	Versão de copia com desalocação de memória em caso de erro
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
			free(destino); // erro de alocação na sub-árvore da esq
			return 2;
		} else {
			if (copia2(origem->dir, destino->dir) != 1) {
				destroi_arv(destino->esq); // desaloca sub-árvore da esquerda
				free(destino); // erro de alocação na sub-árvore da dir
				return 2;
			} else { 
					destino->reg = origem->reg;
					return 1; // cópia bem sucedida
				}
			}
		}
	}

