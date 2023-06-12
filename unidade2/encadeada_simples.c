#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
typedef struct Node {
  int data;
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
  newNode->next = NULL;
  return newNode;
}

// Função para inserir um nó no início da lista
Node* insertAtBeginning(Node* head, int data) {
  Node* newNode = createNode(data);
  newNode->next = head;
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
  return head;
}

// Função para inserir um nó em uma posição específica da lista
Node* insertAtPosition(Node* head, int data, int position) {
  if (position <= 0) {
    printf("Posição inválida.\n");
    return head;
  }
  if (position == 1) {
    return insertAtBeginning(head, data);
  }
  Node* newNode = createNode(data);
  Node* current = head;
  int count = 1;
  while (current != NULL && count < position - 1) {
    current = current->next;
    count++;
  }
  if (current == NULL) {
    printf("Posição inválida.\n");
    return head;
  }
  newNode->next = current->next;
  current->next = newNode;
  return head;
}

// Função para remover o primeiro nó da lista
Node* deleteFirstNode(Node* head) {
  if (head == NULL) {
    printf("A lista está vazia.\n");
    return NULL;
  }
  Node* temp = head->next;
  free(head);
  return temp;
}

// Função para remover o último nó da lista
Node* deleteLastNode(Node* head) {
  if (head == NULL) {
    printf("A lista está vazia.\n");
    return NULL;
  }
  if (head->next == NULL) {
    free(head);
    return NULL;
  }
  Node* current = head;
  while (current->next->next != NULL) {
    current = current->next;
  }
  free(current->next);
  current->next = NULL;
  return head;
}

// Função para remover um nó de uma posição específica da lista
Node* deleteAtPosition(Node* head, int position) {
  if (position <= 0) {
    printf("Posição inválida.\n");
    return head;
  }
  if (position == 1) {
    return deleteFirstNode(head);
  }
  Node* current = head;
  int count = 1;
  while (current != NULL && count < position - 1) {
    current = current->next;
    count++;
  }
  if (current == NULL || current->next == NULL) {
    printf("Posição inválida.\n");
    return head;
  }
  Node* temp = current->next;
  current->next = current->next->next;
  free(temp);
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

Node* insertInOrder(Node* head, int data) {
  Node* newNode = createNode(data);

  if (head == NULL || data < head->data) {
    newNode->next = head;
    return newNode;
  }

  Node* current = head;
  while (current->next != NULL && current->next->data < data) {
    current = current->next;
  }

  newNode->next = current->next;
  current->next = newNode;

  return head;
}


// Função principal
int main() {
  Node* head = NULL;

  head = insertAtEnd(head, 10);
  head = insertAtEnd(head, 20);
  head = insertAtBeginning(head, 5);
  head = insertAtPosition(head, 15, 2);

  printList(head);

  head = insertInOrder(head, 10);
  head = insertInOrder(head, 20);
  head = insertInOrder(head, 5);
  head = insertInOrder(head, 15);

  printList(head);

  head = deleteFirstNode(head);
  head = deleteLastNode(head);
  head = deleteAtPosition(head, 2);

  printList(head);

  return 0;
}
