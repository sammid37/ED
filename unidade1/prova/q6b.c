// Estrutura de Dados, Prova
// Questão 5-b e 6: Alocação Estática
// Samantha Dantas Medeiros

#include <stdio.h>

#define TAM 10

struct listaB {
  int v[TAM][TAM];
  int oc;
};

// protótipos
int criarLista(struct listaB *l);
int inserir(struct listaB*);
int tabuada(struct listaB *, int, int);

// main
void main() {
  struct listaB l;
  int x1 = 2, x2 = 6;
  
  criarLista(&l);
  inserir(&l);
  
  printf("%d * %d = %d\n", x1, x2, tabuada(&l, x1, x2)); // resultado esperado: 12

}

// implementação de funções
int criarLista(struct listaB *pl) {
  pl->oc = 0;
  return 1;
}

int inserir(struct listaB *pl) {
   // Verificando se a lista está cheia
  if(pl->oc == TAM) {
    printf("A lista está cheia, não é possível inserir");
    return 0;
  }

  for(int i = 0; i < TAM; i++) {
    for(int j = 0; j < TAM; j++) {
      pl->v[i][j] = (j+1)*(i+1);
      pl->oc++;
    }
  }

  printf("Elementos inseridos com sucesso!\n");

  return 1;
}

int tabuada(struct listaB *pl, int linha, int coluna) {
  return (pl->v[linha-1][coluna-1]);
}
