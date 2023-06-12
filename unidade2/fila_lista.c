// ED, aula 9 @ 28/03/23
// Filas (Simples) com Lista

#include <stdio.h>
#include <stdlib.h>

// constantes
#define N 100

// Estruturas
typedef struct lista Lista;
struct lista {
  int info;
  struct lista* prox;
};

typedef struct fila Fila;
struct fila {
  Lista* ini;
  Lista* fim;
};


// Protótipos
Fila* fila_cria(void);
void fila_insere(Fila* f, int v);
int fila_retira(Fila* f);
int fila_vazia(Fila* f);
void fila_libera(Fila* f);
void fila_imprime(Fila* f);


// Main
void main() {
  Fila* f = fila_cria();

  fila_insere(f, 10);
  fila_insere(f, 20);
  fila_insere(f, 30);
  fila_insere(f, 40);

  printf("Primeiro elemento: %d\n", fila_retira(f));
  printf("Segundo elemento: %d\n\n", fila_retira(f));
  
  printf("Configutação da fila:\n");
  fila_imprime(f);

  fila_libera(f);
}

// Implementações
int fila_vazia(Fila* f) { return (f->ini == NULL); }
void fila_libera(Fila* f) { 
  Lista* l = f->ini;

  /*
    Vai liberando gradualmente os elementos da lista l
    com auxilio de uma lista auxiliar que armazena
    o próximo elemento de l
  */
  while(l != NULL) {
    Lista* aux = l->prox;
    free(l);
    l = aux;
  }

  free(f);
}

Fila* fila_cria(void) {
  Fila* f = (Fila*) malloc(sizeof(Fila)); // aloca
  f->ini = f->fim = NULL; // posicao inicial
  
  return f;
}

void fila_imprime(Fila* f) {
  Lista* l;
  for(l=f->ini; l != NULL; l=l->prox) {
    printf("%d\n", l->info);
  }
}

void fila_insere(Fila* f, int v) {
  // aloca Lista
  Lista* l = (Lista*) malloc(sizeof(Lista));
  l->info = v;
  l->prox = NULL;

  if(f->fim != NULL) { // verifica se a fila não esta vazia
    f->fim->prox = l;
  } else { // fila vazia
    f->ini = l;
  }
  f->fim = l; // fila aponta para novo elemento

  printf("Elemento inserindo com sucesso.\n");
}

int fila_retira(Fila* f) {
  Lista* l;
  int v;

  if(fila_vazia(f)) {
    printf("Operação indisponível.\nA fila está vazia.\n");
    exit(1);
  }

  // retira elemento do inicio
  l = f->ini;
  v = l->info;

  // verifica se a fila ficou vazia
  if(f->ini == NULL) {
    f->fim = NULL;
  }

  free(l);
  return v;
}