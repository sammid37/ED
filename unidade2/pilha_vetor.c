#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
  int* array;
  int top;
} Stack;

// Função para criar uma pilha vazia
Stack* createStack() {
  Stack* stack = (Stack*)malloc(sizeof(Stack));
  stack->array = (int*)malloc(MAX_SIZE * sizeof(int));
  stack->top = -1;
  return stack;
}

// Função para verificar se a pilha está vazia
int isEmpty(Stack* stack) {
  return stack->top == -1;
}

// Função para verificar se a pilha está cheia
int isFull(Stack* stack) {
  return stack->top == MAX_SIZE - 1;
}

// Função para empilhar um elemento
void push(Stack* stack, int data) {
  if (isFull(stack)) {
    printf("A pilha está cheia.\n");
    exit(1);
  }
  stack->top++;
  stack->array[stack->top] = data;
}

// Função para desempilhar um elemento
int pop(Stack* stack) {
  if (isEmpty(stack)) {
    printf("A pilha está vazia.\n");
    exit(1);
  }
  int data = stack->array[stack->top];
  stack->top--;
  return data;
}

// Função para obter o elemento no topo da pilha
int peek(Stack* stack) {
  if (isEmpty(stack)) {
    printf("A pilha está vazia.\n");
    exit(1);
  }
  return stack->array[stack->top];
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
