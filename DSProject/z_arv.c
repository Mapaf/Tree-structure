#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "z_arvED.h"
#include "fa_impressao.h"

int arv_init (char **args)
{
    TipoArv *defn;
  	printf("Processando %s ...\n",args[0]);
	if (arv != NULL) {
    	fprintf(stderr, "ED: estrutura jah inicializada - delete-a antes de inicializar\n");
		return 3;
	} else {
		defn = (TipoArv *) malloc(sizeof(TipoArv));
	  	if (defn == NULL) {
			fprintf(stderr, "ED: Incapaz de alocar espaco para a estrutura\n");
			return 4;
		}
	   arv = defn;
	   ed_arv_init(arv);
	   printf("Estrutura criada\n");
	   return 1;
  	}
}

int arv_insere (char **args)
{ 
    TipoRegistro *defn;
  	printf("Processando %s ...\n",args[0]);
	if (arv == NULL) {
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
				int i = ed_arv_insere(*defn,arv);
				if (i==1) printf("Registro Inserido\n");
				else printf( "ED: Erro na alocacao do no' na arvore\n" ) ;
			}
		return 1;
		}
	}
}


int arv_insere_varios (char **args){ 
    TipoRegistro *defn;
  	printf("Processando %s ...\n",args[0]);
	if (arv == NULL) {
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
				int i = ed_arv_insere(*defn,arv);
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




int arv_print_em_ordem (char **args)
{ 
  	printf("Processando %s ...\n",args[0]);
	if (arv == NULL) {
    	fprintf(stderr, "ED: arvore nao inicializada\n");
		return 1;
	} else {
		printf("Percurso em Ordem ===========================\n");
		ed_arv_emOrd(arv->raiz);
		printf("\n");
		return 1;
	}
}



int arv_print_pre_ordem (char **args)
{ 
  	printf("Processando %s ...\n",args[0]);
	if (arv == NULL) {
    	fprintf(stderr, "ED: arvore nao inicializada\n");
		return 1;
	} else {
		printf("Percurso em Pre Ordem =======================\n");
		ed_arv_preOrd(arv->raiz);
		printf("\n");
		return 1;
	}
}



int arv_print_pos_ordem (char **args)
{ 
  	printf("Processando %s ...\n",args[0]);
	if (arv == NULL) {
    	fprintf(stderr, "ED: arvore nao inicializada\n");
		return 1;
	} else {
		printf("Percurso em Pos Ordem ========================\n");
		ed_arv_posOrd(arv->raiz);
		printf("\n");
		return 1;
	}
}

int arv_num_nos (char **args)
{ 
  	printf("Processando %s ...\n",args[0]);
	if (arv == NULL) {
    	fprintf(stderr, "ED: arvore nao inicializada\n");
		return 1;
	} else {
		int nnos = ed_arv_nNos(arv->raiz);
		printf("Arvore possui %d nos\n", nnos);
		return 1;
	}
}

int arv_altura (char **args)
{ 
  	printf("Processando %s ...\n",args[0]);
	if (arv == NULL) {
    	fprintf(stderr, "ED: arvore nao inicializada\n");
		return 1;
	} else {
		int alt = ed_arv_altura(arv->raiz);
		printf("Arvore possui altura %d\n", alt);
		return 1;
	}
}


/* Busca Elemento em �rvore */
int arv_busca (char **args){ 
  	printf("Processando %s ...\n",args[0]);
	if (arv == NULL) {
    	fprintf(stderr, "ED: arv nao inicializada\n");
		return 1;
	} else {
  		if (args[1] == NULL) {
    		fprintf(stderr, "ED: esperado uma chave para busca \n");
			return 1;
 		 } else {
			int n = toString(args[1]);
			TipoRegistro reg;
			int i = ed_arv_busca(n,arv->raiz,&reg);
			if (i == 1) printf("Registro encontrado\n");
			else printf("Registro nao encontrado\n");
			}
		return 1;
		}
}


/* Remove Elemento da �rvore */
int arv_remove (char **args){
  printf("Processando %s ...\n",args[0]); 
	if (arv == NULL) {
    	fprintf(stderr, "ED: arvore nao inicializada\n");
		return 1;
	} else {
  		if (args[1] == NULL) {
    		fprintf(stderr, "ED: esperado uma chave para remocao \n");
			return 1;
 		 } else {
			int n = toString(args[1]);
			int i = ed_arv_remove(n,arv);
			if (i==1) printf("Registro removido\n");
			else printf("Registro nao encontrado\n");
			}
		return 1;
		}
}



/*
 	arv_print (n�o � trivial, entenda com cuidado)
 	
 	Imprime elementos da �rvore usando a opera��o ed_arv_visita
	 
	ed_arv_visita faz uma chamada (callback) para uma fun��o par�metro
	para cada registro encontrado na estrutura de dados
 	
	No nosso caso a fun��o par�metro � vis_imp.
	 
	Esta fun��o est� contida no arquivo fa_impressao.c  Ela imprime as
	chaves dos registros e usa uma vari�vel global para controlar quando
	registros s�o impressos por linha usando a constante ITEMSLINHA 	
*/
int arv_print(char **args)
{ 
  	printf("Processando %s ...\n",args[0]);
	if (arv == NULL) {
    	fprintf(stderr, "ED: arvore nao inicializada\n");
		return 1;
	} else {
		printf("Percurso em Call Back ============================\n");
		vis_init();
		// visita a �rvore usando de impressao vis_imp
		ed_arv_visita(arv->raiz, &vis_imp); 
		printf("\n");
		return 1;
	}
}

/*
 	arv_mult (bastante complicada n�o precisa estudar)
 	
 	Multiplica o valor de todas as chaves dos elementos da �rvore 
	usando a opera��o ed_arv_mapeia
	 
	ed_arv_mapeia faz uma chamada (callback) para uma fun��o par�metro
	para cada registro encontrado na estrutura de dados, o registro
	e' passado por refer�ncia assim ele pode ser modificado pela
	��o par�metro. Neste exemplo o valor de suas chaves sao mutiplicados
	pelo valor entrado na linha de commando
	
	usa funMul below
 		
*/

int mulVal = 1;
void setMulVal(int n){
	mulVal = n;
}
void funcMul(TipoRegistro *reg){
	(*reg).chave = (*reg).chave * mulVal;
}

int arv_mult (char **args)
{ 
    TipoRegistro *defn;
  	printf("Processando %s ...\n",args[0]);
	if (arv == NULL) {
    	fprintf(stderr, "ED: arvore nao inicializada\n");
		return 1;
	} else {
  		if (args[1] == NULL) {
    		fprintf(stderr, "ED: esperado um inteiro para multiplicar\n");
			return 1;
 		 } else {
 		 	int n = toString(args[1]);
 		 	if (n <= 0) {
    			fprintf(stderr, "ED: zero nao pode ser usado\n");
				return 1;
			  }
			setMulVal(n);
			// visita a �rvore usando a funcao de multiplica��o
			ed_arv_mapeia(arv->raiz, &funcMul); 
			return 1;
		}
	}
}



/* Busca Elemento em �rvore */
int arv_buscaRank (char **args){ 
  	printf("Processando %s ...\n",args[0]);
	if (arv == NULL) {
    	fprintf(stderr, "ED: arv nao inicializada\n");
		return 1;
	} else {
  		if (args[1] == NULL) {
    		fprintf(stderr, "ED: esperado um ranking para busca \n");
			return 1;
 		 } else {
			int n = toString(args[1]);
			if (n<=0) {
				fprintf(stderr, "ED: esperado um ranking positivo para busca \n");
				return 1;
			} else {
				TipoRegistro* reg;
				int i = ed_arv_buscaRank(n, arv->raiz, reg);
				if (i == 0) printf("Registro encontrado, R = %d \n", reg->chave);
				else printf("Registro nao encontrado\n");
			}
		}
		return 1;
		}
}

