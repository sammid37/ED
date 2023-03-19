// Estrutura de Dados, Prova
// Questão 8
// Samantha Dantas Medeiros

#include <stdio.h>

#define TAM 100

struct lista {
  int v[TAM];
  int controle;
};

// protótipos
int soma_todos(struct lista*);
int criarLista(struct lista *l);
int inserir(struct lista*);

void main() {
  struct lista l;
  
  criarLista(&l);
  inserir(&l);

  int resultado = soma_todos(&l);

  printf("Soma: %d\n", resultado);
}

// implementação de funções
int criarLista(struct lista *pl) {
  pl->controle = 0;
  return 1;
}

int inserir(struct lista *pl) {
   // Verificando se a lista está cheia
  if(pl->controle == TAM) {
    printf("A lista está cheia, não é possível inserir");
    return 0;
  }

  for(int i = 0; i < TAM; i++) {
    pl->v[i] = 5;
    pl->controle++;
  }

  printf("Elementos inseridos com sucesso!\n");

  return 1;
}

int soma_todos(struct lista *pl) {
  int soma = 0; 
  for(int i = 0; i < TAM; i++) {
    soma += pl->v[i];
  }

  return soma;
}