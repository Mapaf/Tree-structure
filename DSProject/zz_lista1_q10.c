#include <stdio.h>
#include "z_arvED.h"

/*
   Percurso DRE 
*/
void ed_arv_DRE(TipoNoArv* raiz){
    if(raiz != NULL){
      ed_arv_DRE(raiz->dir);
      printf("%d ", raiz->reg.chave);
      ed_arv_DRE(raiz->esq);
   }
}


/*
   Percurso RDE 
*/
void ed_arv_RDE(TipoNoArv* raiz){
    if(raiz != NULL){
      printf("%d ", raiz->reg.chave);
      ed_arv_RDE(raiz->dir);
      ed_arv_RDE(raiz->esq);
   }
}


/*
   Percurso DER 
*/
void ed_arv_DER(TipoNoArv* raiz){
    if(raiz != NULL){
      ed_arv_DER(raiz->dir);
      ed_arv_DER(raiz->esq);
      printf("%d ", raiz->reg.chave);
   }
}
