#include <stdlib.h>
#include "z_a_registro.h"

typedef struct TipoNoArv {
	TipoRegistro reg;
	struct TipoNoArv *esq;
	struct TipoNoArv *dir;
} TipoNoArv;

typedef struct TipoArv {
	TipoNoArv *raiz ;
} TipoArv;

typedef TipoNoArv *ABB;
//typedef ListNode *ListNodePtr;


/*
  a arvore propriamente dita
  */
static struct TipoArv *arv = NULL;


