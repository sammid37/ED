#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592

// Definição das estruturas das figuras geométricas
typedef struct {
  double raio;
} Circulo;

typedef struct {
  double lado;
} Quadrado;

typedef struct {
  double base;
  double altura;
} Triangulo;

// Enumeração para identificar o tipo de figura
typedef enum {
  CIRCULO,
  QUADRADO,
  TRIANGULO
} TipoFigura;

// Estrutura do nó da lista heterogênea
typedef struct Node {
  TipoFigura tipo;
  void* figura;
  struct Node* prox;
} Node;

// Função para criar um novo nó
Node* criarNo(TipoFigura tipo, void* figura) {
  Node* novoNo = (Node*)malloc(sizeof(Node));
  if (novoNo == NULL) {
    printf("Erro ao alocar memória para o novo nó.\n");
    exit(1);
  }
  novoNo->tipo = tipo;
  novoNo->figura = figura;
  novoNo->prox = NULL;
  return novoNo;
}

// Função para inserir uma figura na lista
void inserirFigura(Node** lista, TipoFigura tipo, void* figura) {
  Node* novoNo = criarNo(tipo, figura);
  if (*lista == NULL) {
    *lista = novoNo;
  } else {
    Node* atual = *lista;
    while (atual->prox != NULL) {
      atual = atual->prox;
    }
    atual->prox = novoNo;
  }
}

// Função para calcular a área de um círculo
double calcularAreaCirculo(Circulo* circulo) {
  return PI * pow(circulo->raio, 2);
}

// Função para calcular a área de um quadrado
double calcularAreaQuadrado(Quadrado* quadrado) {
  return pow(quadrado->lado, 2);
}

// Função para calcular a área de um triângulo
double calcularAreaTriangulo(Triangulo* triangulo) {
  return (triangulo->base * triangulo->altura) / 2;
}

// Função para percorrer a lista e calcular a área de cada figura
void calcularAreasLista(Node* lista) {
  Node* atual = lista;
  while (atual != NULL) {
    switch (atual->tipo) {
      case CIRCULO:
        printf("Área do Círculo: %.2lf\n", calcularAreaCirculo((Circulo*)atual->figura));
        break;
      case QUADRADO:
        printf("Área do Quadrado: %.2lf\n", calcularAreaQuadrado((Quadrado*)atual->figura));
        break;
      case TRIANGULO:
        printf("Área do Triângulo: %.2lf\n", calcularAreaTriangulo((Triangulo*)atual->figura));
        break;
    }
    atual = atual->prox;
  }
}

// Função principal
int main() {
  Node* lista = NULL;

  // Criar figuras
  Circulo* circulo = (Circulo*)malloc(sizeof(Circulo));
  circulo->raio = 5.0;
  Quadrado* quadrado = (Quadrado*)malloc(sizeof(Quadrado));
  quadrado->lado = 3.0;
  Triangulo* triangulo = (Triangulo*)malloc(sizeof(Triangulo));
  triangulo->base = 4.0;
  triangulo->altura = 6.0;

  // Inserir figuras na lista
  inserirFigura(&lista, CIRCULO, circulo);
  inserirFigura(&lista, QUADRADO, quadrado);
  inserirFigura(&lista, TRIANGULO, triangulo);

  // Calcular áreas das figuras da lista
  calcularAreasLista(lista);

  // Liberar memória
  free(circulo);
  free(quadrado);
  free(triangulo);

  return 0;
}
