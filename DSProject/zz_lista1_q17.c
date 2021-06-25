#include <stdlib.h>

typedef struct TipoRegQT {
	int chaveX;
	int chaveY;
	// int conteudo;
	// outros componentes //
} TipoRegQT;

typedef struct TipoNoQT {
	TipoRegQT reg;
	struct TipoNoQT *SE;
	struct TipoNoQT *SO;
	struct TipoNoQT *NE;
	struct TipoNoQT *NO;
} TipoNoQT;


int ed_arvQT_insere(TipoRegQT registro, TipoNoQT *a){
	
    TipoNoQT *defn;
	defn = (TipoNoQT *) malloc(sizeof(TipoNoQT));
	if (defn == NULL) { // Erro de alocacao
		return 2;
	} 
	defn->reg = registro;
	defn->SE = NULL;
	defn->SO = NULL;
	defn->NE = NULL;
	defn->NO = NULL;
	
    if (a == NULL) { // primeiro elemento
    	a = defn;    // insere na raiz
	} else { // insere na árvore indo para esquerda e direita
		TipoNoQT *atual = a;
		TipoNoQT *ant = NULL;
		while(atual != NULL){
			ant=atual;
			if((registro.chaveX == atual->reg.chaveX) &&
			   (registro.chaveY == atual->reg.chaveY)){ // elemento já existe
		 	 free(defn);
			 return 4;
			}
			if ((registro.chaveX >= atual->reg.chaveX) && 
		    	(registro.chaveY >= atual->reg.chaveY))
            	atual = atual->NE;
        	else
         	if ((registro.chaveX >= atual->reg.chaveX) && 
		    	(registro.chaveY < atual->reg.chaveY))
            	atual = atual->SE;
        	else
         	if ((registro.chaveX < atual->reg.chaveX) && 
		    	(registro.chaveY < atual->reg.chaveY))
            	atual = atual->SO;
        	else
        		atual = atual->NO;
		}
	if ((registro.chaveX >= atual->reg.chaveX) && 
	    (registro.chaveY >= atual->reg.chaveY))
           ant->NE = defn;
    else
    if ((registro.chaveX >= atual->reg.chaveX) && 
	    (registro.chaveY < atual->reg.chaveY))
	    ant->SE = defn;
    else
    if ((registro.chaveX < atual->reg.chaveX) && 
	    (registro.chaveY < atual->reg.chaveY))
	    ant->SO = defn;
    else
	   ant->NO = defn;	
   } 
   return 1;
}




