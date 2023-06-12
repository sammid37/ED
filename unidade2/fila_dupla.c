// Estrutura de Dados
// Fila Dupla

#include <stdio.h>
#include <stdlib.h>

// constantes
#define N 100

// Estruturas
struct lista2 {
  int info;
  struct lista2* ant;
  struct lista2* prox;
};
typedef struct lista2 Lista2;

struct fila2 {
  Lista2* ini;
  Lista2* fim;
};
typedef struct fila2 Fila2;

// Protótipos
Fila2* fila_cria(void);

void fila_insere(Fila2* f, int v);
void fila_insere_ini(Fila2* f, int v);
void fila_insere_fim(Fila2* f, int v);
static Lista2* ins2_ini(Lista2* ini, int v); // aux
static Lista2* ins2_fim(Lista2* fim, int v); // aux

int fila_retira(Fila2* f);
int fila_retira_ini(Fila2* f); 
int fila_retira_fim(Fila2* f); 
static Lista2* ret2_ini(Lista2* ini); // aux
static Lista2* ret2_fim(Lista2* fim); // aux

int fila_vazia(Fila2* f);

void fila_libera(Fila2* f);

void fila_imprime(Fila2* f);

// Main
void main() {}

// Implementações das Funções
// INSERÇÃO
void fila2_insere_ini(Fila2* f, int v) {
  f->ini = ins2_fim(f->ini, v);
  if(f->fim == NULL) {
    f->fim = f->ini;
  }
}
void fila2_insere_fim(Fila2* f, int v) {
  f->fim = ins2_fim(f->fim, v);
  if(f->ini == NULL) {
    f->ini = f->fim;
  }
}
static Lista2* ins2_ini(Lista2* ini, int v){
  Lista2* l = (Lista2*) malloc(sizeof(Lista2));
  l->info = v;
  l->prox = ini;
  l->ant = NULL;
  // verifica se a lista não está vazia
  if(ini != NULL) {
    ini->ant = l;
  } 

  return l;
}
static Lista2* ins2_fim(Lista2* fim, int v){
  Lista2* l = (Lista2*) malloc(sizeof(Lista2));
  l->info = v;
  l->prox = NULL;
  l->ant = fim;
  // verifica se a lista não está vazia
  if(fim != NULL) {
    fim->prox = l;
  } 

  return l;
}


// REMOÇÃO
int fila_retira_ini(Fila2* f){
  int v;
  if(fila2_vazia(f)) {
    printf("Fila vazia.\n");
    exit(1);
  }
  v = f->ini->info;
  f->ini = ret2_ini(f->ini);
  if(f->ini == NULL){
    f->fim = NULL;
  }
  return v;
}
int fila_retira_fim(Fila2* f){
  int v;
  if(fila2_vazia(f)) {
    printf("Fila vazia.\n");
    exit(1);
  }
  v = f->fim->info;
  f->fim = ret2_ini(f->fim);
  if(f->fim == NULL){
    f->ini = NULL;
  }
  return v;
}
static Lista2* ret2_ini(Lista2* ini){
  Lista2* l = ini->prox;
  // verifica se a lista não ficou vazia
  if(l != NULL) {
    l->ant = NULL;
  }
  free(ini);
  return l;
}
static Lista2* ret2_fim(Lista2* fim){
  Lista2* l = fim->prox;
  // verifica se a lista não ficou vazia
  if(l != NULL) {
    l->prox = NULL;
  }
  free(fim);
  return l;
}