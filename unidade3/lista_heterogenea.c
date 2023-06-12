#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista
struct Node {
  char id;
  void* info;
  struct Node* prox;
};

// Função para criar um novo nó
struct Node* createNode(char id, void* data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  if (newNode == NULL) {
    printf("Erro ao alocar memória para o novo nó.\n");
    exit(1);
  }
  newNode->id = id;
  newNode->info = data;
  newNode->prox = NULL;
  return newNode;
}

// Função para adicionar um elemento à lista
void addElement(struct Node** lista, char id, void* data) {
  struct Node* newNode = createNode(id, data);
  
  if (*lista == NULL) {
    *lista = newNode;
  } else {
    struct Node* aux = *lista;
    while (aux->prox != NULL) {
      aux = aux->prox;
    }
    aux->prox = newNode;
  }
}

// Função para imprimir os elementos da lista
void printList(struct Node* lista) {
  struct Node* aux = lista;
  int posicao = 1;
  while (aux != NULL) {
    switch (aux->id) {
      case 'i':
        printf("Posição: %d, Valor Inteiro: %d\n", posicao, *((int*)(aux->info)));
        break;
      case 'f':
        printf("Posição: %d, Valor Float: %.2f\n", posicao, *((float*)(aux->info)));
        break;
      case 'c':
        printf("Posição: %d, Valor Char: %c\n", posicao, *((char*)(aux->info)));
        break;
    }
    aux = aux->prox;
    posicao++;
  }
}

// Função principal
int main() {
  struct Node* lista = NULL;

  // Adicionar elementos à lista
  int intValue = 10;
  float floatValue = 3.14;
  char charValue = 'A';
  addElement(&lista, 'i', &intValue);
  addElement(&lista, 'f', &floatValue);
  addElement(&lista, 'c', &charValue);

  // Imprimir os elementos da lista
  printf("Elementos da lista:\n");
  printList(lista);

  return 0;
}
