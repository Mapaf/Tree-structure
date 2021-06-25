#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "z_a_registro.h"

/*
	Estruturas para impressão controlada
	items por linha: ITEMSLINHA
	contator: cont_imp
*/
const int ITEMSLINHA = 6;
int cont_imp;

void vis_init(){
	cont_imp = 1;
}

int vis_imp(TipoRegistro reg){
	printf("%5d ",reg.chave);
	if (cont_imp % ITEMSLINHA == 0) printf("\n");
	fflush(stdout);
	cont_imp++;
}

