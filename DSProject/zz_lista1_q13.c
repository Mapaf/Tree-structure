#include <stdio.h>
#include "z_arvEncED.h"


/*
	Atravessamento em Pre-Ordem da Árvore Costurada
*/
void ed_arvEnc_PreOrd(TipoNoArvEnc *raiz){
	TipoNoArvEnc *anterior,*atual;
	
	atual = raiz;
	do{
		anterior = NULL;
		while(atual != NULL) { // vá para esquerda
			anterior = atual;
			printf("%d ", anterior->reg.chave); // visita no'
			atual = atual->esq;
		} // vai para ponta esquerda da sub-arvore
		if (anterior != NULL) { // se não é raiz
			atual = anterior->dir;   // vai para direita
			while (atual != NULL && atual->enc) {
				printf("%d ", atual->reg.chave);
				anterior = atual;
				atual = atual->dir;
			};
		}
	} while (anterior != NULL);
}

