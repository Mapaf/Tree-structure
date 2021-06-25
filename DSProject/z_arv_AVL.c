#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "z_arv_AVL_ED.h"
#include "fa_impressao.h"


/* inicializa Árvore */
int arvAVL_init (char **args) {
    TipoArvAVL *defn;
  	printf("Processando %s ...\n",args[0]);
	if (arvAVL != NULL) {
    	fprintf(stderr, "ED: estrutura jah inicializada - delete-a antes de inicializar\n");
		return 3;
	} else {
		defn = (TipoArvAVL *) malloc(sizeof(TipoArvAVL));
	  	if (defn == NULL) {
			fprintf(stderr, "ED: Incapaz de alocar espaco para a estrutura\n");
			return 4;
		}
	   arvAVL = defn;
	   ed_arvAVL_init(arvAVL);
	   printf("Estrutura criada\n");
	   return 1;
  	}
}


/* Busca Elemento na Árvore */
int arvAVL_busca (char **args) { 
  	printf("Processando %s ...\n",args[0]);
	if (arvAVL == NULL) {
    	fprintf(stderr, "ED: arv nao inicializada\n");
		return 1;
	} else {
  		if (args[1] == NULL) {
    		fprintf(stderr, "ED: esperado uma chave para busca \n");
			return 1;
 		 } else {
			int n = toString(args[1]);
			TipoRegistro reg;
			int i = ed_arvAVL_busca(n,arvAVL->raiz,&reg);
			if (i == 1) printf("Registro encontrado\n");
			else printf("Registro nao encontrado\n");
			}
		return 1;
		}
}


/* Insere elemento na Árvore */
int arvAVL_insere (char **args) { 
    TipoRegistro *defn;
  	printf("Processando %s ...\n",args[0]);
	if (arvAVL == NULL) {
    	fprintf(stderr, "ED: arvore nao inicializada\n");
		return 1;
	} else {
  		if (args[1] == NULL) {
    		fprintf(stderr, "ED: esperado um inteiro para inserir\n");
			return 1;
 		 } else {
			int n = toString(args[1]);
			defn = (TipoRegistro *) malloc(sizeof(TipoRegistro));
	  		if (defn == NULL) {
				fprintf(stderr, "ED: Incapaz de alocar espaco para registro\n");
				return 2;
			} else {
				defn -> chave = n;
				// Faça implementação
				int i = ed_arvAVL_insere(*defn,arvAVL);
				if (i==1) printf("Registro Inserido\n");
				else printf( "ED: Erro na alocacao do no' na arvore\n" ) ;
			}
		return 1;
		}
	}
}


/* Insere vários elementos na Árvore */
int arvAVL_insere_varios (char **args) { 
    TipoRegistro *defn;
  	printf("Processando %s ...\n",args[0]);
	if (arvAVL == NULL) {
    	fprintf(stderr, "ED: arv nao inicializada\n");
		return 1;
	} else {
  		if (args[1] == NULL) {
    		fprintf(stderr, "ED: esperado pelo menos um inteiro para insercao\n");
			return 1;
 		 };
		int j = 1;
		while(args[j] != NULL ) {
			int n = toString(args[j]);
			defn = (TipoRegistro *) malloc(sizeof(TipoRegistro));
	  		if (defn == NULL) {
				fprintf(stderr, "ED: Incapaz de alocar espaco para a estrutura\n");
				return 2;
			} else {
				defn -> chave = n;
				int i = ed_arvAVL_insere(*defn,arvAVL);
				if (i==1) printf("Registro Inserido\n");
				else {
					printf("ED: erro de alocacao, %d. param em diante nao foi inserido\n",j);
					break;
				}
				}
			j++;
		}
		return 1;
		}
}


/* Remove Elemento da Árvore */
int arvAVL_remove (char **args) {
  printf("Processando %s ...\n",args[0]); 
	if (arvAVL == NULL) {
    	fprintf(stderr, "ED: arvore nao inicializada\n");
		return 1;
	} else {
  		if (args[1] == NULL) {
    		fprintf(stderr, "ED: esperado uma chave para remocao \n");
			return 1;
 		 } else {
			int n = toString(args[1]);
			int i = ed_arvAVL_remove(n,arvAVL);
			if (i==1) printf("Registro removido\n");
			else printf("Registro nao encontrado\n");
			}
		return 1;
		}
}

int arvAVL_altura (char **args)
{ 
  	printf("Processando %s ...\n",args[0]);
	if (arvAVL == NULL) {
    	fprintf(stderr, "ED: arvore nao inicializada\n");
		return 1;
	} else {
		int alt = ed_arvAVL_altura(arvAVL->raiz);
		printf("Arvore possui altura %d\n", alt);
		return 1;
	}
}


int arvAVL_emOrd (char **args)
{ 
  	printf("Processando %s ...\n",args[0]);
	if (arvAVL == NULL) {
    	fprintf(stderr, "ED: arvore nao inicializada\n");
		return 1;
	} else {
		printf("Percurso em Ordem ===========================\n");
		ed_arvAVL_emOrd(arvAVL->raiz);
		printf("\n");
		return 1;
	}
}

int arvAVL_posOrd (char **args)
{ 
  	printf("Processando %s ...\n",args[0]);
	if (arvAVL == NULL) {
    	fprintf(stderr, "ED: arvore nao inicializada\n");
		return 1;
	} else {
		printf("Percurso em Pos Ordem ===========================\n");
		ed_arvAVL_posOrd(arvAVL->raiz);
		printf("\n");
		return 1;
	}
}


int arvAVL_preOrd (char **args)
{ 
  	printf("Processando %s ...\n",args[0]);
	if (arvAVL == NULL) {
    	fprintf(stderr, "ED: arvore nao inicializada\n");
		return 1;
	} else {
		printf("Percurso em Pre' Ordem ===========================\n");
		ed_arvAVL_preOrd(arvAVL->raiz);
		printf("\n");
		return 1;
	}
}

int arvAVL_printA(char **args)
{ 
	printf("Processando %s ...\n",args[0]);
	if (arvAVL == NULL) {
    	fprintf(stderr, "ED: arvore nao inicializada\n");
		return 1;
	} else {
		printf("Percurso em Forma A ===========================\n");
		ed_arvAVL_emNivel_A(arvAVL->raiz);
		printf("\n");
		return 1;
	}
  return 1;
}


int arvAVL_print_nivel_bonito(char **args)
{ 
	printf("Processando %s ...\n",args[0]);
	if (arvAVL == NULL) {
    	fprintf(stderr, "ED: arvore nao inicializada\n");
		return 1;
	} else {
		printf("Percurso em Forma A ===========================\n");
		print_nivel(arvAVL->raiz);
		printf("\n");
		return 1;
	}
  return 1;
}
