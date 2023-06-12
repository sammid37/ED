#include <stdio.h>
#include <stdlib.h>

struct no {
  int info;
  struct no *esq, *dir;
} *A, *aux;

// prototipo 
struct no* criar_arvore(int v, struct no* e, struct no* d);
void mostrar_arvore(struct no*);

void main () {
  struct no *arvore;
  arvore = 0;
  arvore = criar_arvore(7,0,0);
  arvore->esq = criar_arvore(5,0,0);
  arvore->dir = criar_arvore(9,0,0);
  // arvore->dir = criar_arvore(11,arvore,0); // loop infinito em mostrar

  mostrar_arvore(arvore);
  arvore = 0; // limpa a arvore, jeito sujo
}

// implementação
struct no* criar_arvore(int valor, struct no *fesq, struct no *fdir) {
  struct no *novo;
  novo = (struct no*) malloc(sizeof(struct no));

  if(!novo) return 0;
  novo->info = valor;
  novo->esq = fesq;
  novo->dir = fdir;

  return novo;
}

void mostrar_arvore(struct no* raiz) {
  if(raiz) {
    printf("%d ", raiz->info);
    mostrar_arvore(raiz->esq);
    mostrar_arvore(raiz->dir);
  } else { 
    return;
  }
}