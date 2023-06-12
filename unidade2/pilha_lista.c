#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

typedef struct {
  Node* top;
} Stack;

// Função para criar uma pilha vazia
Stack* createStack() {
  Stack* stack = (Stack*)malloc(sizeof(Stack));
  stack->top = NULL;
  return stack;
}

// Função para verificar se a pilha está vazia
int isEmpty(Stack* stack) {
  return stack->top == NULL;
}

// Função para empilhar um elemento
void push(Stack* stack, int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = stack->top;
  stack->top = newNode;
}

// Função para desempilhar um elemento
int pop(Stack* stack) {
    if (isEmpty(stack)) {
      printf("A pilha está vazia.\n");
      exit(1);
    }
    int data = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

// Função para obter o elemento no topo da pilha
int peek(Stack* stack) {
    if (isEmpty(stack)) {
      printf("A pilha está vazia.\n");
      exit(1);
    }
    return stack->top->data;
}

// Função principal
int main() {
    Stack* stack = createStack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("Elemento no topo: %d\n", peek(stack));

    while (!isEmpty(stack)) {
      printf("Elemento desempilhado: %d\n", pop(stack));
    }

    return 0;
}
