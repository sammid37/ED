// ED, aula 4 @ 07/03/23
// Alocação dinâmica

#include <stdio.h>
#include <stdlib.h>

void main(){
  int *p;

  printf("(ANTES da alocação) p = %p\n", p); // nil

  p = (int *) malloc(sizeof(int)); // alocando

  // Verificando se a alocação foi realizada com sucesso
  if (p==0) {
    printf("Não foi possível alocar memória.\n");
    return;
  }

  printf("(DEPOIS da alocação) p = %p\n\n", p);

  // Apontando a valores com *p = <num>
  printf("Valor apontado por p = %d\n", *p); // lixo
  
  *p = 7;
  printf("Valor apontado por p = %d\n", *p); // 7

  free(p); // libera espaço, importante!
  
  /*
  // ! CUIDADO. RISCO DE TELA AZUL ABAIXO 👀
  // Se formos verificar o valor apontado por p após o free, é possível encontrarmos lixo de memória
  
  printf("\nValor de p = %p", p); // 0 ou lixo
  printf("\nValor apontado por p = %d", *p); // 7 
  
  *p=10;
  printf("\nValor apontado por p = %d", *p); // lixo ou 10

  */

}