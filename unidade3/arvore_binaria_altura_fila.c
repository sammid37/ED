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
      int height = 0;
      int levelNodes;
      Node** queue = (Node**)malloc(sizeof(Node*));
      queue[0] = root;
      
      while (1) {
          levelNodes = 0;
          
          while (1) {
              if (height >= 1 && levelNodes == 0) {
                  // Todos os nós de um nível foram visitados, portanto a altura é atualizada
                  free(queue);
                  return height;
              }
              
              Node* currentNode = queue[0];
              levelNodes++;
              
              if (currentNode->left != NULL) {
                  queue = (Node**)realloc(queue, (levelNodes + 1) * sizeof(Node*));
                  queue[levelNodes] = currentNode->left;
              }
              
              if (currentNode->right != NULL) {
                  queue = (Node**)realloc(queue, (levelNodes + 1) * sizeof(Node*));
                  queue[levelNodes] = currentNode->right;
              }
              
              // Remover o nó atual da fila
              for (int i = 0; i < levelNodes; i++) {
                  queue[i] = queue[i + 1];
              }
              
              // Verificar se existem mais nós na fila
              if (levelNodes == 0) {
                  break;
              }
          }
          
          height++;
      }
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
