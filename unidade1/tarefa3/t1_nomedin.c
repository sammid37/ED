// Estrutura de Dados, Tarefa 3
// Programa 1: nomes dinâmicos
// Samantha Dantas Medeiros

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 102 // contando os caracteres especiais '\n' e '\0'
#define QTD_NOMES 10

// protótipos
void lerNomes(char ***nomes, int qtd); // ***nomes & que aponta para a matriz de nomes
void exibirNomes(char **nomes, int qtd);
void liberarMatriz(char **matriz, int qtd);

// main
int main() {
  char **nomes = NULL;

  lerNomes(&nomes, QTD_NOMES);
  liberarMatriz(nomes, QTD_NOMES);
  exibirNomes(nomes, QTD_NOMES);

  return 0;
}

// implementação das funções
void lerNomes(char ***nomes, int qtd) {
  char nome[MAX_CHAR]; // armazena cada nome que será inserido na matriz

  if((*nomes) == NULL) {
    // alocando memória sizeof(char) * qtd de nomes inseridos na matriz 
    (*nomes) = (char **) malloc(sizeof(char *) * qtd);

    // verificando solicitação de alocação de memória
    if((*nomes) == NULL) {
      printf("Não foi possível alocar memória da matriz 'char ** nomes'.\n");
      return;
    }
  }

  // lendo nomes e preenchendo na matriz
  for (int i = 0; i < qtd; i ++) {
    printf("Informe o nome nº%d: ", i+1);
    scanf("%[^\n]%*c", nome); // ler até o fim da linha, retirando o caracter \n

    // alocando espaço de acordo com o nome digitado para inserir na matriz
    (*nomes)[i] = (char *) malloc(sizeof(char) * (strlen(nome) + 1));

    // verificando solicitação de alocação de memória
     if((*nomes)[i] == NULL) {
      printf("Não foi possível alocar memória de 'char* nomes[%d]'.\n", i);
      return;
    }

    // inserindo nome na matriz de nomes
    strcpy((*nomes)[i], nome);
  }
}

void exibir(char **nomes, int qtd) {
    if (nomes == NULL) return;

    for (int i = 0; i < qtd && nomes[i] != NULL; i++) {
      printf("Nome %d: %s\n", i+1, nomes[i]);
    }
}

void liberarMatriz(char **matriz, int qtd) {
    if (matriz == NULL) return;

    for (int i = 0; i < qtd && matriz[i] != NULL; i++) {
      free(matriz[i]);
    }

    free(matriz);
}