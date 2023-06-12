// Estrutura de Dados, Prova
// Questão 4: alocação estática
// Samantha Dantas Medeiros

#include <stdio.h>

#define TAM 11

// estrutura
struct lista {
  int v[TAM];
  int controle;
};

// protótipos
int criarLista(struct lista *);
int inserir(struct lista *, int);
void mostrarLista(struct lista *);

// main
void main() {
  struct lista l;

  criarLista(&l);

  if(!criarLista(&l)) {
    printf("Não foi possível criar a lista.\n");
    return;
  } else {
    printf("Lista criada com sucesso.\n");
  }

  // inserção
  inserir(&l, 3);
  inserir(&l, 5);
  inserir(&l, 8);
  inserir(&l, 9);
  inserir(&l, 15);
  inserir(&l, 17);
  inserir(&l, 21);
  inserir(&l, 34);
  inserir(&l, 60);
  inserir(&l, 99);

  //
  mostrarLista(&l);

  // novo elemento
  inserir(&l, 18);
  mostrarLista(&l);

  // inserir(&l, 18);

}

// implementação das funções
int criarLista(struct lista *pl) {
  pl->controle = 0;
  return 1;
}

int inserir(struct lista *pl, int valor) {
  // Verificando se a lista está cheia
  if(pl->controle == TAM) {
    printf("A lista está cheia, não é possível inserir");
    return 0;
  }

  // i corresponde a posição que vou inserir o elemento corretamente
  int j, i = 0;
  while(i < pl->controle && pl->v[i] < valor) 
    i++;

  // Percorrendo a lista e fazendo a movimentação para então inserir;
  for(j = pl->controle - 1; j >= i; j--) {
    pl->v[j+1] = pl->v[j];
  }
  pl->v[i] = valor;
  pl->controle++;

  printf("Elementos inseridos com sucesso!\n");

  return 1;
}

void mostrarLista(struct lista *pl) {
  if(pl->controle == 0) {
    printf("Lista vazia! Não há nada para exibir.\n");
    return;
  }

  for(int i=0; i < TAM; i++) {
    printf("lista, v[%d] = %d\n", i, pl->v[i]);
  }
  printf("\n");
}