#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da árvore
struct Node {
  int data;
  struct Node* left;
  struct Node* right;
};

// Função para criar um novo nó
struct Node* createNode(int data, struct Node* left, struct Node* right) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  if (newNode == NULL) { 
    printf("Erro ao alocar memória para o novo nó.\n");
    exit(1);
  }
  newNode->data = data;
  newNode->left = left;
  newNode->right = right;
  return newNode;
}

// Função para inserir um valor na árvore
struct Node* insertNode(struct Node* root, int data) {

  if(!root) { // chegou na folha
    return createNode(data, NULL, NULL);
  } else {
    if(data < root->data) {
      root->left = insertNode(root->left, data);
    } else {
      root->right = insertNode(root->right, data);
    }
  }
  return root;
}

// Função para imprimir o conteúdo da árvore
void printNode(struct Node* root) {
  if(root) {
    printf("%d ", root->data);
    printNode(root->left);
    printNode(root->right);
  } else {
    return;
  }
}

struct Node* clearNode(struct Node* root) {
  if(root) {
    root->left = clearNode(root->left);
    root->right = clearNode(root->right);
    free(root);
    return(0);
  } else {
    return(0);
  }
}

// Função para buscar um valor na árvore
struct Node* searchNode(struct Node* root, int data) {
  if (root == NULL || root->data == data) {
    return root;
  }
  if (data < root->data) {
    return searchNode(root->left, data);
  } else {
    return searchNode(root->right, data);
  }
}

// Função para encontrar o nó com o valor mínimo na árvore
struct Node* findMinNode(struct Node* root) {
  struct Node* current = root;
  while (current->left != NULL) {
    current = current->left;
  }
  return current;
}

// Função para remover um valor da árvore
struct Node* deleteNode(struct Node* root, int data) {
  if (root == NULL) {
    return root;
  }
  if (data < root->data) {
    root->left = deleteNode(root->left, data);
  } else if (data > root->data) {
    root->right = deleteNode(root->right, data);
  } else {
    if (root->left == NULL) {
      struct Node* temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct Node* temp = root->left;
      free(root);
      return temp;
    }
    struct Node* temp = findMinNode(root->right);
    root->data = temp->data;
    root->right = deleteNode(root->right, temp->data);
  }
  return root;
}

// Função para realizar uma rotação simples à esquerda
struct Node* rotateLeft(struct Node* root) {
  struct Node* newRoot = root->right;
  root->right = newRoot->left;
  newRoot->left = root;
  return newRoot;
}

// Função para realizar uma rotação simples à direita
struct Node* rotateRight(struct Node* root) {
  struct Node* newRoot = root->left;
  root->left = newRoot->right;
  newRoot->right = root;
  return newRoot;
}

// Função para imprimir a árvore em ordem (in-order traversal)
void inOrderTraversal(struct Node* root) {
  if (root != NULL) {
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
  }
}

// Função para calcular a altura de uma árvore binária
int calculateHeight(struct Node* root) {
  if (root == NULL) {
      return 0;
  } else {
      int leftHeight = calculateHeight(root->left);
      int rightHeight = calculateHeight(root->right);
      return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
  }
}

// Função para verificar se a árvore está balanceada
int isBalanced(struct Node* root) {
  if (root == NULL) {
    return 1;
  }

  int leftHeight = calculateHeight(root->left);
  int rightHeight = calculateHeight(root->right);
  int balanceFactor = abs(leftHeight - rightHeight);

  if (balanceFactor <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
    return 1;
  }

  return 0;
}


// Função principal
int main() {
  struct Node* root = NULL;

  // Inserir valores na árvore
  root = insertNode(root, 50);
  root = insertNode(root, 30);
  root = insertNode(root, 70);
  root = insertNode(root, 20);
  root = insertNode(root, 40);

  // Imprimir a árvore em ordem
  printf("Árvore em ordem: ");
  inOrderTraversal(root);
  printf("\n");

  // Buscar um valor na árvore
  int value = 40;
  struct Node* foundNode = searchNode(root, value);
  if (foundNode != NULL) {
    printf("Valor %d encontrado na árvore.\n", value);
  } else {
    printf("Valor %d não encontrado na árvore.\n", value);
  }

  // Remover um valor da árvore
  int valueToRemove = 30;
  root = deleteNode(root, valueToRemove);
  printf("Valor %d removido da árvore.\n", valueToRemove);

  // Imprimir a árvore atualizada em ordem
  printf("Árvore atualizada em ordem: ");
  inOrderTraversal(root);
  printf("\n");

  // Realizar uma rotação simples à esquerda
  root = rotateLeft(root);
  printf("Árvore após a rotação à esquerda: ");
  inOrderTraversal(root);
  printf("\n");

  // Realizar uma rotação simples à direita
  root = rotateRight(root);
  printf("Árvore após a rotação à direita: ");
  inOrderTraversal(root);
  printf("\n");

  return 0;
}