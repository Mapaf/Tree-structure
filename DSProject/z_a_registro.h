/*
   Define o que é um registro nas nossas estruturas de dados
*/
#ifndef HEADER_FILE
#define HEADER_FILE

typedef int TipoChave;

typedef struct TipoRegistro {
	TipoChave chave;
	// int conteudo;
	// outros componentes //
} TipoRegistro;


/* rotinas de callback para visita e mapeamentos */
typedef int (*visitador)(TipoRegistro);
typedef void (*mapeador)(TipoRegistro *);


// void insertion_sort(int *array, int n, callback comparison);


#endif
