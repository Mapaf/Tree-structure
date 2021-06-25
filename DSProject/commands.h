/*
  Function Declarations for builtin shell commands:
 */
// int lsh_cd(char **args);
int lsh_help(char **args);		// Comandos Básicos da Shell
int lsh_exit(char **args);
int lsh_sobre(char **args);
int ts_init(char **args);		// Tabela Sequencial
int ts_print(char **args);
int ts_destroy(char **args);
int ts_insere(char **args);
int ts_busca(char **args);
int ts_remove(char **args);
int ts_insere_varios(char **args);
int fi_init(char **args);		// Fila
int fi_enfile(char **args);
int fi_desenfile(char **args);
int fi_print(char **args);
int arv_init(char **args);		// Arvore Binaria
int arv_insere(char **args);
int arv_insere_varios(char **args);
int arv_print_em_ordem(char **args);
int arv_print_pre_ordem(char **args);
int arv_print_pos_ordem(char **args);
int arv_print(char **args);
int arv_altura(char **args);
int arv_num_nos(char **args);
int arv_busca(char **args);
int arv_remove(char **args);
int arv_mult(char **args);
int arv_buscaRank(char **args);
int arvAVL_init(char **args);		// Arvore AVL
int arvAVL_busca(char **args);
int arvAVL_insere(char **args);
int arvAVL_insere_varios(char **args);
int arvAVL_remove(char **args);
int arvAVL_altura(char **args);
int arvAVL_printA(char **args);
int arvAVL_emOrd(char **args);
int arvAVL_preOrd(char **args);
int arvAVL_posOrd(char **args);
int arvAVL_print_nivel_bonito(char **args);
/*
  List of builtin commands, followed by their corresponding functions.
 */
char *builtin_str[] = {
//  "cd",
  "help",		// Comandos Básicos da Shell
  "exit",
  "creditos",
  "ts-init", 			// Tabela Sequencial
  "ts-print",
  "ts-destroi",
  "ts-insere",
  "ts-busca",
  "ts-remove",
  "ts-insere-varios",
  "fi-init", 			// Fila
  "fi-enfile",
  "fi-desenfile",
  "fi-print",
  "arv-init",			// Arvore Binaria
  "arv-insere",
  "arv-insere-varios",
  "arv-print-emOrd",
  "arv-print-preOrd",
  "arv-print-posOrd",
  "arv-print",
  "arv-altura",
  "arv-num-nos",
  "arv-busca",
  "arv-remove",
  "arv-mul",
  "arv-busca-rank",
  "avl-init",			// Arvore AVL
  "avl-busca",			
  "avl-insere",
  "avl-insere-varios",
  "avl-remove",
  "avl-altura",
  "avl-printA",
  "avl-print-emOrd",
  "avl-print-preOrd",
  "avl-print-posOrd",
  "avl-print-bonito"
};

int (*builtin_func[]) (char **) = {
//  &lsh_cd,
  &lsh_help,		// Comandos Básicos da Shell
  &lsh_exit,
  &lsh_sobre,
  &ts_init,			// Tabela Sequencial
  &ts_print,
  &ts_destroy,
  &ts_insere,
  &ts_busca,
  &ts_remove,
  &ts_insere_varios,
  &fi_init,				// Fila
  &fi_enfile,
  &fi_desenfile,
  &fi_print,
  &arv_init,			// Arvore Binaria
  &arv_insere,
  &arv_insere_varios,
  &arv_print_em_ordem,
  &arv_print_pre_ordem,
  &arv_print_pos_ordem,
  &arv_print,
  &arv_altura,
  &arv_num_nos,
  &arv_busca,
  &arv_remove,
  &arv_mult,
  &arv_buscaRank,
  &arvAVL_init,			// Arvore AVL
  &arvAVL_busca,
  &arvAVL_insere,
  &arvAVL_insere_varios,
  &arvAVL_remove,
  &arvAVL_altura,
  &arvAVL_printA,
  &arvAVL_emOrd,
  &arvAVL_preOrd,
  &arvAVL_posOrd,
  &arvAVL_print_nivel_bonito
};

