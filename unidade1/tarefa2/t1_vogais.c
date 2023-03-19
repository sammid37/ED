// Estrutura de Dados, Tarefa 2
// Programa 1: contagem de vogais
// Samantha Dantas Medeiros

#include <stdio.h>
#include <string.h>

int contarVogais(char *v); // protótipo

void main() {
  char frase[] = "Tu Es eternamente responsAvel pela memOria que alocas!";
  int qtd_vogais = contarVogais(frase);

  printf("A quantidade de vogais na frase \'%s\' é de %d.\n", frase, qtd_vogais);
}

int contarVogais(char *v) {
  int qtd_vogais = 0;

  // Enquanto não encontra o final da string, conta vogais
  while (*v != '\0') {
    switch (*v){
      case 'A':
      case 'a':
      case 'E':
      case 'e':
      case 'I':
      case 'i':
      case 'O':
      case 'o':
      case 'U':
      case 'u':
        qtd_vogais = qtd_vogais + 1;
        break;
    }
    v++;
  }
  return qtd_vogais;
}