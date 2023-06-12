// Estrutura de Dados
// Filas (Simples) com Vetor

#include <stdio.h>
#include <stdlib.h>

// constantes
#define N 100

// Estrutura
typedef struct fila Fila;
struct fila {
  int n;
  int ini;
  int vetor[N];
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

  printf("\nPrimeiro elemento: %d\n", fila_retira(f));
  printf("Segundo elemento: %d\n\n", fila_retira(f));
  
  printf("Configutação da fila:\n");
  fila_imprime(f);

  fila_libera(f);
}

// Implementações
int fila_vazia(Fila* f) { return (f->n == 0); }
void fila_libera(Fila* f) { free(f); }
void fila_imprime(Fila* f) {
  for(int i = 0; i < f->n; i++) {
    printf("%d\n", f->vetor[(f->ini + i) % N]);
  }
}

Fila* fila_cria(void) {
  Fila* f = (Fila*) malloc(sizeof(Fila)); // aloca
  f->n = 0; // fila vazia
  f->ini = 0; // posicao inicial
  
  return f;
}


void fila_insere(Fila* f, int v) {
  int fim;
  
  // verifica se a fila esta cheia
  if(f->n == N) {
    printf("Capacidade excedida.\n");
    exit(1);
  }

  // inserindo na próxima posição livre
  fim = (f->ini + f->n) % N;
  f->vetor[fim] = v;
  f->n++;

  printf("Elemento inserindo com sucesso.\n");
}

int fila_retira(Fila* f) {
  int v;
  if(fila_vazia(f)) {
    printf("Operação indisponível.\nA fila está vazia.\n");
    exit(1);
  }

  // retira elemento do inicio
  v = f->vetor[f->ini];
  f->ini = (f->ini + 1) % N;
  f->n--;

  return v;
}