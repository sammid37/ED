#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura da fila
typedef struct Queue {
    int capacity;
    int size;
    int front;
    int rear;
    int* array;
} Queue;

// Função para criar uma nova fila
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Erro ao alocar memória para a fila.\n");
        exit(1);
    }
    queue->capacity = capacity;
    queue->size = 0;
    queue->front = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    if (queue->array == NULL) {
        printf("Erro ao alocar memória para o array da fila.\n");
        exit(1);
    }
    return queue;
}

// Função para verificar se a fila está vazia
int isEmpty(Queue* queue) {
    return queue->size == 0;
}

// Função para verificar se a fila está cheia
int isFull(Queue* queue) {
    return queue->size == queue->capacity;
}

// Função para inserir um elemento no final da fila
void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Erro: Fila cheia. Não é possível inserir mais elementos.\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
    printf("Elemento %d inserido na fila.\n", item);
}

// Função para remover o elemento do início da fila
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Erro: Fila vazia. Não é possível remover elementos.\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

// Função para acessar o elemento do início da fila sem removê-lo
int front(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Erro: Fila vazia. Não há elementos para acessar.\n");
        return -1;
    }
    return queue->array[queue->front];
}

// Função para imprimir os elementos da fila
void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("A fila está vazia.\n");
        return;
    }
    printf("Fila: ");
    int count = 0;
    int index = queue->front;
    while (count < queue->size) {
        printf("%d ", queue->array[index]);
        index = (index + 1) % queue->capacity;
        count++;
    }
    printf("\n");
}

// Função principal
int main() {
    Queue* queue = createQueue(5);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printQueue(queue);

    printf("Elemento removido: %d\n", dequeue(queue));

    printQueue(queue);

    printf("Elemento da frente da fila: %d\n", front(queue));

    return 0;
}
