// ED, aula 0 @ 08/02/23
// Impressão da tabela ascii com apenas uma var do tipo char

#include <stdio.h>

void imprime(unsigned char v) {
  printf("%d: %c\n", v, v);
}

void main() {
  unsigned char i; // modificador para char ir de 0 à 255

  for(i = 0; i < 255; i++) {
    imprime(i);
  }
  imprime(i); // para imprimir o último
}