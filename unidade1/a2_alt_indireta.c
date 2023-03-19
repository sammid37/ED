// ED, aula 2 @ 28/02/23
// Alteração de uma variável por meio de um ponteiro e uma função sem retorno

#include <stdio.h>

void f(int *v) {
  *v = *v +1; // *v += 1;
}

int main(void) {
  int i = 7;
  f(&i);

  printf("O valor de i agora é: %d\n", i);
}
