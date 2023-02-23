#include <stdio.h>

int main(void) {
  int x = 6;

  int *p1, *p2;

  p1 = &x; // p1 recebe o endereço de x
  p2 = p1; // p2 tbm recebe o endereço de x

  printf("%p\n", p2);
  printf("%p\n\n", p1);

  // Aritmétrica de ponteiros
  /*
    Supondo que o endereço de x é 2000
    p1 possui o valor do endereço, 2000
    quando é incrementado, o valor passa a ser 2004, 
    correspondente aos 4 bytes do tipo int
  */
  p1++; // incremento do endereço 
  printf("%p\n", p1);

  p1--;
  printf("%p\n", p1);
  p1--;
  printf("Valor original: %p\n", p1);

  p1++;
  p1 = p1 + 12;

  printf("p1 + 12 = %p\n", p1);
}