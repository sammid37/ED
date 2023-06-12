#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* left;
  struct Node* right;
} Node;

// Função para criar um novo nó
Node* createNode(int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

// Função para calcular a altura de uma árvore binária
int calculateHeight(Node* root) {
  if (root == NULL) {
      return 0;
  } else {
      int leftHeight = calculateHeight(root->left);
      int rightHeight = calculateHeight(root->right);
      return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
  }
}

// Função principal
int main() {
  // Construção da árvore binária
  Node* root = createNode(1);
  root->left = createNode(2);
  root->right = createNode(3);
  root->left->left = createNode(4);
  root->left->right = createNode(5);
  root->right->left = createNode(6);
  root->right->right = createNode(7);

  // Cálculo da altura da árvore binária
  int height = calculateHeight(root);

  printf("A altura da árvore binária é: %d\n", height);

  return 0;
}
