#include <stdio.h>
#include <math.h>
#include "z_arv_AVL_ED.h"

typedef struct tp_fila{
	TipoNoArvAVL *reg;
	int lug;
	int prof;
	struct tp_fila *prox;
}tp_fila;


typedef struct fila{
	tp_fila *inicio;
	tp_fila *final;
}fila;


void fila_init(fila *a){
	a->inicio = NULL;
	a->final = NULL;
}


int fila_enfila(TipoNoArvAVL *registro,int lug,int prof, fila *f){
    tp_fila *defn;
	defn = (tp_fila *) malloc(sizeof(tp_fila));
	if (defn == NULL) { 
		return 2;
	} 
	defn->reg = registro;
	defn->lug = lug;
	defn->prof = prof;
	defn->prox = NULL;
    if (f->inicio == NULL) { 
    	f->inicio = defn;
	    f->final = defn;
	} else {
		f->final->prox = defn;
		f->final = defn;
	}
	return 1;
}


int fila_des_enfila(TipoNoArvAVL **registro,int *lug,int *prof, fila *f){
	tp_fila *faux;
	
    if (f->inicio == NULL) { 
    	return 2;
	} else { 
		(*registro) = f->inicio->reg; 
		(*lug) = f->inicio->lug;
		(*prof) = f->inicio->prof;
		faux = f->inicio; 
		f->inicio = f->inicio->prox; 
		free(faux); 
		if (f->inicio == NULL) f->final = NULL;
	}
	return 1;
}


int fila_vazia(fila *f){
	
    if (f->inicio == NULL) { 
    	return 1;
	} else { 
		return 0;
	}

}


void print_nivel_recur(TipoNoArvAVL *raiz, int nivel, int esp){  
	int i;
//	if(esp%2 == 1){
//		esp = esp-1;
//	}
	
    if (raiz == NULL){
    	for(i=0;i<=esp;i++){
    	printf(" ");
	}
    	printf("x");
    	return;
	} 
         
    if (nivel == 1){
    	for(i=0;i<=esp;i++){
    	printf(" ");
	}
    printf("%d", raiz->reg.chave);
    
    
		
	}else{ 
    
        print_nivel_recur(raiz->esq, nivel-1,esp/2); 
        print_nivel_recur(raiz->dir, nivel-1,esp/2); 
        
    } 
}


void print_nivel(TipoNoArvAVL *raiz){
 
    int h = ed_arvAVL_altura(raiz); 
    int esp = pow(2,h)+1;
    int i;
    
    for (i=1; i<=h+1; i++){ 
    
        print_nivel_recur(raiz, i,esp/2); 
        printf("\n"); 
        
    } 
}   



void ed_arvAVL_init(TipoArvAVL *a)
{ 
	a->raiz = NULL;
}


int fat_balan(TipoNoArvAVL *no){
	int esq = ed_arvAVL_altura(no->esq);
	int dir = ed_arvAVL_altura(no->dir);
	return labs(esq - dir);
}


int maior(int x,int y){
	return (x>y)?x:y;
}


void rotLL(TipoNoArvAVL **raiz){
	TipoNoArvAVL *no;
	no = (*raiz)->esq;
	(*raiz)->esq = no->dir;
	no->dir = *raiz;
	
	(*raiz)->alt = maior(ed_arvAVL_altura((*raiz)->esq),ed_arvAVL_altura((*raiz)->dir)) + 1;
	no->alt = maior(ed_arvAVL_altura(no->esq),(*raiz)->alt) +1;
	*raiz = no;
	
}


void rotRR(TipoNoArvAVL **raiz){
	TipoNoArvAVL *no;
	no = (*raiz)->dir;
	(*raiz)->dir = no->esq;
	no->esq = *raiz;
	
	(*raiz)->alt = maior(ed_arvAVL_altura((*raiz)->esq),ed_arvAVL_altura((*raiz)->dir)) + 1;
	no->alt = maior(ed_arvAVL_altura(no->dir),(*raiz)->alt) +1;
	*raiz = no;
	
}


void rotLR(TipoNoArvAVL **raiz){
	rotRR(& (*raiz)->esq);
	rotLL(raiz);
}


void rotRL(TipoNoArvAVL ** raiz){
	rotLL(&(*raiz)->dir);
	rotRR(raiz);
}


int ed_arvAVL_busca(int chave, TipoNoArvAVL *atual, TipoRegistro *reg){
	while(atual != NULL){ 
      if(atual->reg.chave == chave){
       (*reg) = atual->reg; 
	   return 1;
      } else {
         if(atual->reg.chave > chave) atual = atual->esq;
         else  atual = atual->dir;			
      }
   }
   return 0;
}


int ed_arvAVL_insere(TipoRegistro registro, TipoNoArvAVL** raiz){
	int res;
	int valor = registro.chave;
	if(*raiz == NULL){
		TipoNoArvAVL *novo;
		novo = (struct TipoNoArvAVL*)malloc(sizeof(struct TipoNoArvAVL));
		if(novo == NULL){
			return 0;
		}
		novo->reg = registro;
		novo->alt = 0;
		novo->dir = NULL;
		novo->esq = NULL;
		*raiz = novo;
		return 1;
	}else{
		TipoNoArvAVL *atual = *raiz;
		if(valor < atual->reg.chave){
			if((res = ed_arvAVL_insere(registro, &(atual->esq))) == 1){
				if(fat_balan(atual) >= 2){
					if(valor < (*raiz)->esq->reg.chave){
						rotLL(raiz);
					}else{
						rotLR(raiz);
					}
				}
			}
		}else{
			if(valor > atual->reg.chave){
				if((res = ed_arvAVL_insere(registro, &(atual->dir))) == 1){
					if(fat_balan(atual) >= 2){
						if(valor > (*raiz)->dir->reg.chave){
							rotRR(raiz);
						}else{
							rotRL(raiz);
						}	
					}
				}
			}else{
				return 0;
			}
		}
		atual->alt = maior(ed_arvAVL_altura(atual->esq),ed_arvAVL_altura(atual->dir)) + 1;
		return res;
	}
}


TipoNoArvAVL * Minbusca(TipoNoArvAVL *a){
	TipoNoArvAVL *atu,*ant;
	ant = a;
	atu = a->esq;
	while(atu != NULL){
		ant =atu;
		atu = atu->esq;
	}	
	return ant;
}


int ed_arvAVL_remove(int valor, TipoNoArvAVL** raiz){
	int res;
	if(*raiz == NULL){
		printf("valor %d nao foi encontrado",valor);
		return 0;
	}
	if(valor < (*raiz)->reg.chave){
		if((res = ed_arvAVL_remove(valor , &(*raiz)->esq)) == 1){
			if(fat_balan(*raiz) >= 2){
				if(ed_arvAVL_altura((*raiz)->dir->esq) <= ed_arvAVL_altura((*raiz)->dir->dir)){
					rotRR(raiz);
				}else{
					rotRL(raiz);
				}	
			}	
		}
	}else if(valor > (*raiz)->reg.chave){
		if((res = ed_arvAVL_remove(valor , &(*raiz)->dir)) == 1){
			if(fat_balan(*raiz) >= 2){
				if(ed_arvAVL_altura((*raiz)->esq->dir) <= ed_arvAVL_altura((*raiz)->esq->esq)){
					rotLL(raiz);
				}else{
					rotLR(raiz);
				}
			}
		}
	}else{
		if(((*raiz)->esq == NULL) || ((*raiz)->dir == NULL)){
			TipoNoArvAVL *velho = *raiz;
			if((*raiz)->esq != NULL){
				*raiz = (*raiz)->esq;
			}else{
				*raiz = (*raiz)->dir;
				free(velho);
			}
		}else{
			TipoNoArvAVL *at = Minbusca((*raiz)->dir);
			(*raiz)->reg.chave = at->reg.chave;
			ed_arvAVL_remove((*raiz)->reg.chave,&(*raiz)->dir);
			if(fat_balan(*raiz) >= 2){
				if(ed_arvAVL_altura((*raiz)->esq->dir) <= ed_arvAVL_altura((*raiz)->esq->esq)){
					rotLL(raiz);
				}else{
					rotLR(raiz);
				}
			}
		}
		return 1;
	}
	return res;
}


int ed_arvAVL_altura(TipoNoArvAVL* no){
	
	if(no == NULL){
		return -1;
	}else{
		return no->alt;
	}
	
}

void ed_arvAVL_emNivel_A(TipoNoArvAVL* raiz){
	if(raiz != NULL){
		fila f;
		TipoNoArvAVL* no;
		fila_init(&f);
		fila_enfila(raiz,0,1,&f);
		while(! fila_vazia(&f)){
			int lug,prof,esq,dir;
			fila_des_enfila(&no,&lug,&prof,&f);
			printf("%d(Altura:%d Profundidade:%d) ", no->reg.chave,prof,lug);
			esq = 2*lug;
			dir = esq+1;
			prof++;
			if(no->esq != NULL){
				fila_enfila(no->esq,esq,prof,&f);
			}
			if(no->dir != NULL){
				fila_enfila(no->dir,dir,prof,&f);
			}
		}
	}
}


/*
   Percurso em ordem que imprime chave do no' 
*/
void ed_arvAVL_emOrd(TipoNoArvAVL* raiz){
    if(raiz != NULL){
      ed_arvAVL_emOrd(raiz->esq);
      printf("%d ", raiz->reg.chave);
      ed_arvAVL_emOrd(raiz->dir);
   }
}


/*
   Percurso em pos ordem que imprime chave do no'
*/
void ed_arvAVL_posOrd(TipoNoArvAVL* raiz){
    if(raiz != NULL){
      ed_arvAVL_posOrd(raiz->esq);
      ed_arvAVL_posOrd(raiz->dir);
      printf("%d ", raiz->reg.chave);
   }
}


/*
   Percurso em pre' ordem que imprime chave do no 
*/
void ed_arvAVL_preOrd(TipoNoArvAVL* raiz){
    if(raiz != NULL){
      printf("%d ", raiz->reg.chave);
      ed_arvAVL_preOrd(raiz->esq);
      ed_arvAVL_preOrd(raiz->dir);
   }
}

