// Estrutura de Dados, Tarefa 1
// Programa 1: ler dados e armazenar em arquivo
// Samantha Dantas Medeiros

#include <stdio.h>
#include <string.h>

#define LIMITE 10

// main
void main() {
  char nome[50];
  int idade, cont = 0;
  FILE *arq;

  // Abrindo arquivo para escrita+
  arq = fopen("arquivo1.txt", "w+");
  if(!arq) { // Verifica se é possível abrir o arquivo
    printf("Não abriu\n");
  }

  // Inserindo cabeçalho do arquivo
  fprintf(arq,"Nomes \t\t  Idades\n");

  // inserindo dados de 10 pessoas
  do {
    // Ler dados
    printf("[%d] Digite o seu nome: ", cont + 1);
    scanf("%s", nome); 
    printf("[%d] Digite a sua idade: ", cont + 1);
    scanf("%d", &idade);

    // insere dados no arquivo
    fprintf(arq, "%s \t\t %d\n", nome, idade);
    
    cont++;
  } while(cont < LIMITE);

  fclose(arq);
}

