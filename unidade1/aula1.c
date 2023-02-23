// ED, Aula 1 @ 23/02/23
// Ponteiros

#include <stdio.h>

void main() {
  int i;
  int *p;

  p=&i;
  printf("P aponta para %p\n\n", p);

  // scanf("%d", &i); 
  scanf("%d", p); // alternativa para atribuir um valor para i

  printf("O endereço de i: %p\n", &i);
  printf("O valor de i: %d\n", i);
  printf("O valor de i: %d\n", *p); // conteúdo apontado por p

}