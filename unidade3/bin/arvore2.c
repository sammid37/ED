// ED, aula árovres @ 04/05/2023
// Árvores Binárias
// Implementação das funções de criar, exibir e limpar

#include <stdio.h>
#include <stdlib.h>

// estruturas
struct no {
  int info;
  struct no* esq;
  struct no* dir;
};

// protótipos
struct no* criarvazia_arvore(void);
struct no* criar_arvore(int, struct no*, struct no*);
struct no* limpar_arvore(struct no*);
void mostrar_arvore(struct no*);

// main
void main() {
  // *arvore, *novo, *aux; // arvore, novo elemento e auxiliar para percorrer a árvore
  struct no* arvore;
  arvore = criarvazia_arvore();
  arvore = criar_arvore(3, 0, 0);
  mostrar_arvore(arvore);
}

// implementação
struct no* criarvazia_arvore(void) {
  return NULL;
}

struct no* criar_arvore(int v, struct no* esq, struct no* dir){
  struct no* novo = (struct no*) malloc(sizeof(struct no));
  novo->info = v;
  novo->esq = esq;
  novo->dir = dir;
  return novo;
}
struct no* limpar_arvore(struct no* no)  {
   if (no != NULL) {
    limpar_arvore(no->esq);
    limpar_arvore(no->dir);
    free(no);
    return NULL;
  }
}
void mostrar_arvore(struct no* no) {
  if (no != NULL) {
    printf("%d ", no->info);
    mostrar_arvore(no->esq);
    mostrar_arvore(no->dir);
  }
}