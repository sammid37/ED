#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 15

// protótipo
int verificaSequenciaRecursiva(char *, int);

// programa principal
void main() {
  char sequencia[MAX];

  printf("Digite uma sequência de até %d caracteres contendo apenas parênteses, colchetes e chaves:\n", MAX);
  scanf("%s", sequencia);

  printf("Sequência %s está correta: %d\n", sequencia, verificaSequenciaRecursiva(sequencia, 0));
}

int verificaSequenciaRecursiva(char *sequencia, int indice) {
  // Caso base: índice atingiu o fim da sequência
  if (sequencia[indice] == '\0') {
    return 1; // sequência válida
  }
  
  char caractere = sequencia[indice];
  
  // Verifica se o caractere atual é um parêntese, colchete ou chave de abertura
  if (caractere == '(' || caractere == '[' || caractere == '{') {
    // Chama a função recursivamente para verificar o restante da sequência
    int resultado = verificaSequenciaRecursiva(sequencia, indice + 1);
    
    // Verifica se a sub-sequência a partir do próximo índice é válida
    if (resultado == 0) {
      return 0; // sequência inválida
    }
    
    // Verifica o caractere seguinte para fechar o parêntese, colchete ou chave
    char fechamento;
    switch (caractere) {
      case '(':
        fechamento = ')';
        break;
      case '[':
        fechamento = ']';
        break;
      case '{':
        fechamento = '}';
        break;
    }
    
    // Verifica se o caractere seguinte é o fechamento correspondente
    if (sequencia[indice + 1] == fechamento) {
      // Chama a função recursivamente para verificar o restante da sequência
      return verificaSequenciaRecursiva(sequencia, indice + 2);
    } else {
      return 0; // sequência inválida
    }
  }
  
  // Se o caractere atual é um parêntese, colchete ou chave de fechamento, a sequência é inválida
  return 0;
}