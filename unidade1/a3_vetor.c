// ED, aula 3 @ 02/03/23
// Vetores

#include <stdio.h>

void main() {
  int *p; 
  int v[5] = {11, 22, 33, 44, 55};
  p = v;

  // Endereços do ponteiro para inteiro p e o vetor de inteiros v
  printf("p = %p\n", p);
  printf("vetor = %p\n\n", v);

  // Endereço dos elementos do vetor v
  // Entre um elemento e outro, há uma distância de 4 bytes (referente ao tipo inteiro)
  printf("&v[0] = %p\n", &v[0]);
  printf("&v[1] = %p\n", &v[1]);
  printf("&v[2] = %p\n\n", &v[2]);

  // Acessando elementos de um vetor pelo índice ou pelo ponteiro que aponta para ele
  printf("v[1] = %d\n", v[1]);
  printf("*(p+1) => v[1] = %d\n", *(p+1));
  printf("*(p+2) => v[2] = %d\n\n", *(p+2));

}