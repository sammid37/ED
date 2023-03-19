// Estrutura de Dados, Prova
// Questão 5-b e 6: Alocação Dinâmica
// Samantha Dantas Medeiros

#include <stdio.h>
#include <stdlib.h>

#define TAM 10

// protótipo
int tabuada(int **matriz, int linha, int coluna);

// main
void main() {

  int **matriz;
  int i, j;
  int x1 = 2, x2 = 6;

  // alocando memória para cada as 'linhas' e 'colunas' da matriz
  matriz = (int **) malloc(TAM * sizeof(int *));
  for(i = 0; i < TAM; i++) {
    matriz[i] = (int *) malloc(TAM * sizeof(int));
  }

  // verificando alocamento
  if(!matriz) {
    printf("Não foi possível alocar memória!\n");
    return;
  }

  // preenchendo a matriz normalmente...
  for(i = 0; i < TAM; i++) {
    for(j = 0; j < TAM; j++) {
      matriz[i][j] = (j+1)*(i+1);
    }
  }

  // exibindo a matriz
  for(i = 0 ; i < TAM; i++) {
    for(j = 0; j < TAM; j++) {
      printf("v[%d][%d] = %d\n", i, j, matriz[i][j]);
    }
  }

  // tabuada
  printf("%d * %d = %d\n", x1, x2, tabuada(matriz, x1, x2)); // resultado esperado: 12

  // liberando a memória das 'colunas' e então das 'linhas' da matriz
  for(i = 0; i < TAM; i++) {
    free(matriz[i]);
  }
  free(matriz);
}

int tabuada(int **matriz, int linha, int coluna) {
  if(matriz == NULL) return 0;
  return (matriz[linha-1][coluna-1]);
}
