// Estrutura de Dados, Tarefa 3
// Programa 4: Lista Estática
// Samantha Dantas Medeiros

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5
#define VAZIA (-1)

// Estrutura de Dados: lista estática
struct lista {
  int v[TAM];
  int controle; 
};

// protótipos
int criarLista(struct lista *);
int ehCheia(struct lista *);
int ehVazia(struct lista *);
int esvaziar(struct lista *);
void exibirLista(struct lista *);
int inserirItem(struct lista *, int);
int removerItem(struct lista *);

// main
void main() {
  struct lista l; // declaração

  if(!criarLista(&l)) {
    printf("Não foi possível criar a lista.\n");
  }

  ehCheia(&l);

  // criar e inserir
  printf("Preenchendo lista com %d elementos.\n", TAM);
  for(int i = 0; i < TAM; i++) {
    int valor;
    printf("Informe um valor para inserção: ");
    scanf("%d", &valor);
    inserirItem(&l, valor);
  }
  printf("\n\nExibindo lista...");
  exibirLista(&l);
 
  // ---- teste, inserir elemento a mais
  inserirItem(&l, 22);

  // remoção
  printf("\n\nRemovendo o último item da lista.\n");
  removerItem(&l);

  printf("\n\nExibindo lista...");
  exibirLista(&l);

  // Limpando a lista
  esvaziar(&l);
  exibirLista(&l);


}

// implementação
int criarLista(struct lista *pl) {
  pl -> controle = -1;
  return(1);
}

int ehCheia(struct lista *pl) {
  if(pl->controle == TAM) {
    printf("A lista está cheia.\n");
    return(1);
  }
}

int ehVazia(struct lista *pl) {
  if(pl && pl->controle == VAZIA) {
    printf("A lista está vazia.\n");
    return(1);
  } 
}

int esvaziar(struct lista *pl) {
  if(!pl) {
    printf("Não foi possível esvaziar a lista.\n");
    return(0);
  } 

  pl->controle = VAZIA;
  printf("Lista esvaziada com sucesso.\n");
  return(1);
}

void exibirLista(struct lista *pl) {
  if(!pl) return;
  for(int i=0; i<TAM; i++) {
    printf("%d\n", pl->v[i]);
  }
}

int inserirItem(struct lista *pl, int valor) {
  if(!pl || ehCheia(pl)) {
    printf("Não foi possível inserir um elemento na lista, ela já está cheia!\n");
    return(0);
  } 
    printf("Elemento inserido ao final da lista com sucesso.\n"); 
    pl->v[pl->controle] = valor;
    pl->controle++;
    return(1);
}

int removerItem(struct lista *pl) {
  if(!pl || ehVazia(pl)) {
    printf("Não há elementos para remoção.\n");
    return(0);
  } 

  pl->controle--;
  return(1);
}
