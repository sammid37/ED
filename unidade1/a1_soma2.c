// ED, aula 1 @ 23/02/23
// Impressão da tabela ascii por passagem de parâmetro
//! corrigir?

#include <stdio.h>

int soma1(unsigned char v) {
  // *v = (*v) + 1; // soma na posiçaõ de memoria
  return v+1;
}

void main() {
  unsigned char i = 0;
  while (i < 256) {
    i = soma1(&i);
    printf("%d: %c\n", i, i);
  }
}