// Estrutura de Dados, Tarefa 1
// Programa 3: abrir arquivo para leitura, ordenar os nomes com suas respectivas idades e armazenar em um novo arquivo
// Samantha Dantas Medeiros

#include <stdio.h>
#include <string.h>

void main() {
  FILE *arqr, *arqw;
  char linha[100];
  char *nome, *idade_str;
  int idade;

  // Abrindo arquivos para leitura e escrita+
  arqr = fopen("arquivo1.txt", "r");
  arqw = fopen("arquivo2.txt", "w+");

  if(!arqr && !arqw) { // Verifica se é possível abrir os arquivos
    printf("Não abriu\n");
  }

  // Escrevendo no arquivo de escrita+
  fprintf(arqw, "Nomes \t\t Idades\n");


  // percorrendo o arquivo original 
  while (fgets(linha, sizeof(linha), arqr)) {
    // Separando a linha do arquivo pelas tabulações
    nome = strtok(linha, "\t\t");
    idade_str = strtok(NULL, "\t\t");

    idade = atoi(idade_str); 
    
  }


  // fechando arquivos abertos para leitura e escrita
  fclose(arqr);
  fclose(arqw);
}