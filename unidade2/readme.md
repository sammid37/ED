# Estrutura de Dados
## Unidade 2
Contém anotações e exemplos ministrados durante a unidade 2 da disciplina de Estrutura de Dados.

### 📓 Aulas
> Para mais anotações, leia os comentários dos exemplos de aula.
#### Introdução
* Aula 8 @ 23/03 
  * Correção da prova 1
#### Estrutura de Dados em C
> As Estruturas de Dados estudadas durante a Unidade 1 da disciplina são: Listas Dinâmica Encadeada.

* Aula 9 @ 28/03
  * Lista Dinâmica Encadeada: tipo de **Lista** onde cada elemento aponta para o seu sucessor.
  * Ponteiro especial para o primeiro elemento da lista e uma indicação de final de lista

  ![Representação de lista encadeada simples](https://www.ime.usp.br/~pf/algoritmos/aulas/png-from-tex/lista.png)
  * Declaração:
  ```c
  struct no {
    int dado;
    struct no *prox; // aponta para a próxima célula
  } *l;
  ```
  * O endereço de uma lista encadeada é o endereço de sua primeira célula.
  * Criação
  * Inserção
  * Remoção
  * Exibição
  ```c
  void imprime (lista *le) {
   lista *p;
   for (p = le; p != NULL; p = p->prox)
      printf ("%d\n", p->dado);
  }
  ```

* Aula 10 @ 30/03
* Aula 11 @ 04/04
  * Lista Circular (ou carrossel)

### 📚 Tarefas
Cada unidade da disciplina contém ao menos 1 diretório de tarefas com o seu respectivo arquivo `README.md` o qual descreve a atividade.

### 📖 Exercícios dos Livros
Em breve.

### 📑 Referências externas
* [Listas Encadeadas por Paulo Feofiloff (DCC-IME-USP)](https://www.ime.usp.br/~pf/algoritmos/aulas/lista.html);

### 📔 Prova
* Lista Encadeada Simples
* Lista Encadeada Dupla
* Lista Circular