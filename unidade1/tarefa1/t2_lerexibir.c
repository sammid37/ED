// Estrutura de Dados, Tarefa 1
// Programa 2: abrir arquivo para leitura e exibir quantos registros possuem idade > 18
// Samantha Dantas Medeiros

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {

  FILE *arq;
  char linha[100];
  char *nome, *idade_str;
  int idade;
  int cont = 0;

  // Abrindo arquivo para leitura
  arq = fopen("arquivo1.txt", "r");
  if(!arq) { // Verifica se é possível abrir o arquivo
    printf("Não abriu\n");
  }

  // Lendo arquivo enquanto não chega ao seu fim
  while (fgets(linha, sizeof(linha), arq)) {
    // Separando a linha do arquivo pelas tabulações
    nome = strtok(linha, "\t\t");
    idade_str = strtok(NULL, "\t\t");

    // convertendo armazendo a idade str como inteiro
    idade = atoi(idade_str); 

    // verificando 
    if (idade > 18) {
      printf("%s é maior de idade!\n", nome);
      cont++;
    }

  }

  printf("\nExistem %d pessoas com mais de 18 anos.\n", cont);

 fclose(arq);
}