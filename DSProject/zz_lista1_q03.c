#include "z_arvED.h"
#include "z_tabelaSequencialED.h"


/*
   Implementa Questão 3 da Lista
   Faz tudo inclusive a Fila
*/


typedef struct ElemFila {
	int dir;
	int esq;
} ElemFila;

typedef struct TipoNoFila2 {
	ElemFila reg;
	struct TipoNoFila2 *prox;
} TipoNoFila2;

typedef struct Fila {
	TipoNoFila2 *inicio ;
	TipoNoFila2 *fim ;
} Fila;

void init_fila(Fila *f)
{ 
  	f->inicio = NULL;
	f->fim = NULL;
}

int enfila_fila(ElemFila registro, Fila *f){
    TipoNoFila2 *defn;
	defn = (TipoNoFila2 *) malloc(sizeof(TipoNoFila2));
	if (defn == NULL) { // Erro de alocacao
		return 2;
	} 
	defn->reg = registro;
	defn->prox = NULL;
    if (f->inicio == NULL) { // primeiro elemento
    	f->inicio = defn;
	    f->fim = defn;
	} else {
		f->fim->prox = defn;
		f->fim = defn;
	}
	return 1;
}

int desenfila_fila(ElemFila *registro, Fila *f){
	
	TipoNoFila2 *faux;
	
    if (f->inicio == NULL) { // fila vazia
    	return 2;
	} else { // remove elemento
		(*registro) = f->inicio->reg; // copia o conteudo pra registro
		faux = f->inicio; 
		f->inicio = f->inicio->prox; // ajusta o inicio para o proximo no'
		free(faux); // remove o nó
		if (f->inicio == NULL) f->fim = NULL;
	}
	return 1; // retorna sucesso
}


int vazia_fila(Fila *f){
	
    if (f->inicio == NULL) { // fila vazia
    	return 1;
	} else { 
		return 0;
	}

}

/*
   Questão 3 da LIsta
*/

TipoNoArv* ed_arv_ins_tab(TipoTabela *ts){
	
	TipoNoArv *minhaArvore = NULL;
	
	if (ts->n == 0) return minhaArvore; // Se tabela vazia, arvore nula
	else {
		int esq,dir;
		Fila f;
		ElemFila ef;
		
		init_fila(&f); // inicializa uma fila
		
		ef.esq = 1;
		ef.dir = ts->n;
		enfila_fila(ef,&f); // enfileira o menor e maior indice da TS
		
		while (! vazia_fila(&f)) { // acaba se não há mais ninguém
			int i, newdir, newesq;
			desenfila_fila(&ef, &f);
			esq = ef.esq;
			dir = ef.dir;
			i = (esq + dir) / 2; // pega o meio
			
			ed_arv_ins(ts->item[i],minhaArvore); // insere ba árvore
			
			newdir = i-1;
			newesq = i+1;
			if (newesq <= dir) { // ainda há números de inserção à direita
				ef.esq = newesq;
				ef.dir = dir;
				enfila_fila(ef,&f);
			};
			if (newdir >= esq) { // ainda há números de inserção à esquerda
				ef.esq = esq;
				ef.dir = newdir;
				enfila_fila(ef,&f);
			};
		}
		return minhaArvore;
	}
} 

int ed_arv_ins(TipoRegistro registro, TipoNoArv *a){
    TipoNoArv *defn;
	defn = (TipoNoArv *) malloc(sizeof(TipoNoArv));
	if (defn == NULL) { // Erro de alocacao
		return 2;
	} 
	defn->reg = registro;
	defn->esq = NULL;
	defn->dir = NULL;
	
    if (a == NULL) { // primeiro elemento
    	a = defn;    // insere na raiz
	} else { // insere na árvore indo para esquerda e direita
		TipoNoArv *atual = a;
		TipoNoArv *ant = NULL;
		while(atual != NULL){
			ant=atual;
			if(registro.chave == atual->reg.chave){ // elemento já existe
		 	 free(defn);
			 return 4;
			}
		if(registro.chave > atual->reg.chave)
            atual = atual->dir;
         else
            atual = atual->esq;
		}
    if(registro.chave > ant->reg.chave) ant->dir = defn;
    else ant->esq = defn;
   } 
   return 1;
}

