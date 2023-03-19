// Estrutura de Dados, Prova
// Questão 2: 
// Samantha Dantas Medeiros

#include <stdio.h>

void main() {
  int a, b, *p, **k;

  a = 7;
  b = 12; 

  p = &b; 
  k = &p;

  printf("O conteúdo de a: %d\nO endereço de a: %p\n\n", a, &a);
  printf("O conteúdo de b: %d\nO endereço de b: %p\n\n", b, &b);
  printf("O conteúdo p: %d\nO endereço apontado por p: %p\n\n", *p, p);
  printf("O conteúdo k: %d\nO endereço apontado por k: %p\n\n\n", **k, k);
  printf("O conteúdo k: %p\nO endereço apontado por k: %p\n\n\n", *k, k);


  printf("*k = %d\n", **k); // conteúdo apontado por k = 12

  printf("(*p) + 1 = %d\n", (*p) + 1); // conteúdo apontado por p + 1, 12 + 1 = 13

  // printf("*b = %d\n", *b); // operação inválida!
  printf("p = %p\n", p); // aponta para o endereço de b

}