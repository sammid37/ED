#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista
typedef struct Node {
  int data;
  struct Node* next;
} Node;

// Função para criar um novo nó
Node* createNode(int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  if (newNode == NULL) {
    printf("Erro ao alocar memória para o novo nó.\n");
    exit(1);
  }
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Função para inserir um nó no início da lista
Node* insertAtBeginning(Node* head, int data) {
  Node* newNode = createNode(data);
  if (head == NULL) {
    newNode->next = newNode;
    return newNode;
  }
  newNode->next = head->next;
  head->next = newNode;
  return head;
}

// Função para inserir um nó no final da lista
Node* insertAtEnd(Node* head, int data) {
  Node* newNode = createNode(data);
  if (head == NULL) {
    newNode->next = newNode;
    return newNode;
  }
  newNode->next = head->next;
  head->next = newNode;
  return newNode;
}

// Função para imprimir os elementos da lista
void printList(Node* head) {
  if (head == NULL) {
    printf("A lista está vazia.\n");
    return;
  }
  Node* current = head->next;
  printf("Lista: ");
  do {
    printf("%d ", current->data);
    current = current->next;
  } while (current != head->next);
  printf("\n");
}

// Função principal
int main() {
  Node* head = NULL;

  // Inserir elementos na lista circular
  head = insertAtEnd(head, 10);
  head = insertAtEnd(head, 20);
  head = insertAtEnd(head, 30);
  head = insertAtBeginning(head, 5);

  // Imprimir a lista circular
  printList(head);

  return 0;
}
