// ED, aula 3 @ 02/03/23
// Vetor de Vetor

#include <stdio.h>

void main() {
  int v1[5] = {1, 2, 3, 4, 5};
  int v2[5] = {11, 22, 33, 44, 55};
  
  int *p[2]; 
  int **q; // aponta para alguém que aponta para um inteiro

  /*
    As posições 0 e 1 do ponteiro para inteiro p
    apontam para os primeiros elementos dos vetores v1 e v2, respectivamente
  */
  p[0] = v1; 
  p[1] = v2;

  q = &p[0]; // aponta para o primeiro elemento apontado por *p

  // Exibindo endereços de *p, v1, v2 e **q
  printf("*p = %p\n", p);
  printf("v1 = %p\n", v1);
  printf("v2 = %p\n", v2);
  printf("**q = %p\n\n", q); // **q = *p

  // Exibindo conteúdos dos ponteiros de inteiros
  printf("*p[0] => v1[0] = %d\n", *p[0]);
  printf("*p[1] => v2[0] = %d\n", *p[1]);
  printf("**q => p[0] = %d\n\n", **q);

}