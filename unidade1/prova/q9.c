// Estrutura de Dados, Prova
// Questão 9
// Samantha Dantas Medeiros

#include <stdio.h>

#define TAM 5

// estrutura
struct lista {
  int valor[TAM];
  int n;
};

// main
void main() {
  struct lista l;
  int valor[TAM] = {8, 4, 11, 7, 0};

  int i, j, aux;
  for (i=0; i<l.n-1; i++) {
    for (j=i+1; j<=l.n; j++) {
      if (l.valor[j]<l.valor[i]) {
        aux = l.valor[i];
        l.valor[i] = l.valor[j];
        l.valor[j] = aux;
      }
    }
  }

}
