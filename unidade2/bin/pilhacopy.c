// Estrutura de Dados, Unidade 2 @ 24/04/2023
// Validação de sequência de parenteses, colchetes e chaves utilizando pilhas
// Samantha Dantas Medeiros (20190145598)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 16

typedef struct pilha {
  char dado[MAX];
  int topo;
} Pilha;

// Protótipos
Pilha * inicializaPilha();
int pilhaVazia(Pilha *pilha);
int pilhaCheia(Pilha *pilha);
void empilha(Pilha *pilha, char dado);
char desempilha(Pilha *pilha);
int verificaSequencia(char *sequencia);

// programa principal
int main() {
  char sequencia[MAX];

  printf("Digite uma sequência de até %d caracteres contendo apenas parênteses, colchetes e chaves:\n", MAX);
  scanf("%s", sequencia);

  // remoção do caracter '\n' do final da string
  sequencia[strcspn(sequencia, "\n")] = '\0';

  printf("Sequência %s está correta: %d\n", sequencia, verificaSequencia(sequencia));

  return 0;
}

// Implementação das funções
Pilha * inicializaPilha() {
  Pilha *pilha;
  pilha = (Pilha*) malloc (sizeof(struct pilha));
  if(pilha != NULL) {
    pilha->topo = -1;
  }
  return pilha;
}

int pilhaVazia(Pilha *pilha) {
  return (pilha->topo == -1);
}

int pilhaCheia(Pilha *pilha) {
  return (pilha->topo == MAX - 1);
}

void empilha(Pilha *pilha, char dado) {
  if (pilhaCheia(pilha)) {
    printf("Erro: pilha cheia.\n");
    exit(1);
  }
  pilha->topo++;
  pilha->dado[pilha->topo] = dado;
}

char desempilha(Pilha *pilha) {
  if (pilhaVazia(pilha)) {
    printf("Erro: pilha vazia.\n");
    exit(1);
  }
  char dado = pilha->dado[pilha->topo];
  pilha->topo--;
  return dado;
}

int verificaSequencia(char *sequencia) {
  Pilha *pilha;
  pilha = (Pilha*) malloc (sizeof(struct pilha));
  if(pilha != NULL) {
    pilha->topo = -1;
  }

  for (int i = 0; i < strlen(sequencia); i++) {
    if (sequencia[i] == '(' || sequencia[i] == '{' || sequencia[i] == '[') {
      empilha(&pilha, sequencia[i]);
    } else if (sequencia[i] == ')' || sequencia[i] == '}' || sequencia[i] == ']') {
      if (pilhaVazia(&pilha)) {
        return 0; // sequência incorreta
      }
      char topo = desempilha(&pilha);
      if ((topo == '(' && sequencia[i] != ')') ||
        (topo == '{' && sequencia[i] != '}') ||
        (topo == '[' && sequencia[i] != ']')) {
        return 0; // sequência incorreta
      }
    }
  }

  return pilhaVazia(&pilha);
}