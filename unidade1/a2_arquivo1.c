#include <stdio.h>
void main() {
  FILE *arq;
  char dado;

  arq=fopen("a2_arquivo1.c", "r");
  if(!arq) {
    printf("Não foi possível abrir o arquivo solicitado.\n");
  }

  fscanf(arq, "%c", &dado);
  while(!feof(arq)) {
    printf("%c", dado);
    fscanf(arq, "%c", &dado);
  }
  
  printf("\n");

  /*

  // arquivo: dados.txt
  //fscanf(arq, "%d", &dado);
  
  Caso a variável dado seja int, é possível armazenar o primeiro número no arquivo, exemplo 23

  Caso a variável dado seja char, ela só vai armazenar o primeiro character, neste caso '2'
  */
 fclose(arq);
}