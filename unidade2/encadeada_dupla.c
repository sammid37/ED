#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
typedef struct Node {
  int data;
  struct Node* prev;
  struct Node* next;
} Node;

// Função para criar um novo nó
Node* createNode(int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  if (newNode == NULL) {
    printf("Erro ao alocar memória para o nó.\n");
    exit(1);
  }
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}

// Função para inserir um nó no início da lista
Node* insertAtBeginning(Node* head, int data) {
  Node* newNode = createNode(data);
  if (head == NULL) {
    return newNode;
  }
  newNode->next = head;
  head->prev = newNode;
  return newNode;
}

// Função para inserir um nó no final da lista
Node* insertAtEnd(Node* head, int data) {
  Node* newNode = createNode(data);
  if (head == NULL) {
    return newNode;
  }
  Node* current = head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = newNode;
  newNode->prev = current;
  return head;
}

// Função para inserir um nó em uma posição específica da lista (mantendo-a ordenada)
Node* insertInOrder(Node* head, int data) {
  Node* newNode = createNode(data);

  if (head == NULL || data < head->data) {
    newNode->next = head;
    if (head != NULL) {
      head->prev = newNode;
    }
    return newNode;
  }

  Node* current = head;
  while (current->next != NULL && current->next->data < data) {
    current = current->next;
  }

  newNode->next = current->next;
  newNode->prev = current;
  if (current->next != NULL) {
    current->next->prev = newNode;
  }
  current->next = newNode;

  return head;
}

// Função para remover um nó da lista
Node* deleteNode(Node* head, Node* node) {
  if (head == NULL || node == NULL) {
    return head;
  }

  if (head == node) {
    head = node->next;
    if (head != NULL) {
      head->prev = NULL;
    }
    free(node);
    return head;
  }

  if (node->prev != NULL) {
    node->prev->next = node->next;
  }
  if (node->next != NULL) {
    node->next->prev = node->prev;
  }

  free(node);

  return head;
}

// Função para imprimir os elementos da lista
void printList(Node* head) {
  if (head == NULL) {
    printf("A lista está vazia.\n");
    return;
  }
  Node* current = head;
  printf("Lista: ");
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

// Função principal
int main() {
  Node* head = NULL;

  head = insertInOrder(head, 10);
  head = insertInOrder(head, 20);
  head = insertInOrder(head, 5);
  head = insertInOrder(head, 15);

  printList(head);

  // Remover o nó com valor 5
  Node* current = head;
  while (current != NULL && current->data != 5) {
    current = current->next;
  }
  head = deleteNode(head, current);

  printList(head);

  return 0;
}
