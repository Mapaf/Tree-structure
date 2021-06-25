#include <stdlib.h>
#include "z_a_registro.h"

typedef struct TipoNoArvAVL {
	TipoRegistro reg;
	struct TipoNoArvAVL *esq;
	struct TipoNoArvAVL *dir;
	int alt;
} TipoNoArvAVL;

typedef struct TipoArvAVL {
	TipoNoArvAVL *raiz ;
} TipoArvAVL;

typedef TipoNoArvAVL *AVL;
//typedef ListNode *ListNodePtr;


/*
  a arvore propriamente dita
  */
static struct TipoArvAVL *arvAVL = NULL;
