# Estrutura de Dados
## Unidade 1
Contém anotações e exemplos ministrados durante a unidade 1 da disciplina de Estrutura de Dados.

### 📓 Aulas
> Para mais anotações, leia os comentários dos exemplos de aula.

#### Breve revisão da Linguagem C   
* Aula 0 @ 08/02
  * Introdução aos ponteiros (C Completo e Total)
  * Operações com ponteiros
* Aula 1 @ 23/02
  * Quem são os ponteiros?
  ```c
    // declaração e atribuições de ponteiros
    int *p;
    p = &i; 

    printf("O endereço de i: %p", &i);
    printf("O endereço apontado por p: %p", p);

    printf("O conteúdo de i: %d", i);
    printf("O conteúdo de i: %d", *p);

  ```
  * Variáveis globais e locais
  * Passagem de parâmetros e por referência
  ```c
    void f(int *v) {
      *v = *v + 1;
    }

    int main(void) {
      int i = 7;
      f(&i); // i = 8
    }
  ```
* Aula 2 @ 28/02/2023
  * Estrutura FILE
    * Armazena o endereço do arquivo na memória secundária
    * Contém o tamanho do buffer que será utilizado pela memória principal, como também o tempo de descarga da informação na memória
  ``` c
  FILE *arq;
  arq = fopen("diretorio//nomefile.extensao", "modo de acesso");
  ```
  * Particularidades dos modos de acesso
    * `r` *abre* um arquivo para leitura e verifica se ele existe, caso contrário, exibe mensagem de erro
    * `r+` *abre* um arquivo para a leitura e a escrita se o mesmo existir, caso contrário, exibe mensagem de erro
    * `w` *cria* um arquivo para a escrita
    * `w+` *cria* um arquivo para a escrita e a leitura
  * `fopen` é um pedido, precisa testar
  ```c
  if (arq == NULL) { // (arq == 0) ou (!arq) 
    printf("Erro ao abrir o arquivo\n");
    return 0;
  } else {
    printf("O arquivo aberto com sucesso!\n\n");
  }

  fclose(arq); // lemmbre-se SEMPRE de fechar o(s) arquivo(s)
  ```
* Aula 3 @ 02/03/2023
  * Vetores em C, são:
    * endereço de uma sequência
    * uma sequência de vários tipos iguais
    ```c 
    int * p;
    int vetor[5] = { 11, 22, 33, 44, 55 }
    p = vetor;
    ```
  * Vetor multidimensional: armazenamento sequencial em memória
  * Passagem de vetor por parâmetro
    * Dica: prototipe sua função!
    ```c
    // importação de bibliotecas
    #include <stdio.h>
    ...

    // protipação
    int contarVogais(char *v); // protótipo

    // main
    void main() {
      // codigo da main
    }

    // implementação da função prototipada no início do programa
    int contarVogais(char *v) {
      // implementação vai aqui!
    }
    ```
    * Índice do vetor em uma função: não tem relação com o vetor ou a matriz
    * Pulo equivale ao tamanho do tipo em bytes (ex.: int = 4 bytes)
    ```c
    void eiVetor(*vv); // protótipo

    // main
    void main() {
      eiVetor(meu_vetor); // chamada da função
      // mais alguma coisa aqui
    }

    void eiVetor(*vv) {
      // como utilizar o vetor que é passado por parâmetro
      vv[n];
      // mais alguma coisa
    }
    ```

  * Strings são endereços de caracteres
    ```c
    #include <string.h> // importante!
    
    ...

    // Leitura de strings em C
    scanf("%s", nome); // ler até o caracter '\0'
    scanf("%c", &nome[0]); // ler o primeiro caracter da sequência
    ```
* Aula 4 @ 07/03/2023
  * Alocação Dinâmica de uma memória sem nome
    * Solicitar e utilizar memória durante a execução do programa
    * Objetivo de evitar desperdício, reservando de acordo com a necessidade
    * Malocar: `<tipo> *malloc(<tamanho_em_bytes>)`
    ```c
    char *v[8]; // 8 endereços de char para guardar 8 nomes
    char n[30]; // sequência máxima de 30 caracteres para cada nome
    
    int *p;
    p = (int *) malloc(sizeof(int));

    // testando se a solicitação de alocar memória foi atendida
    if(!p) printf("não alocou!\n");
    else free(p); // libera a memória que p aponta, isto não troca o valor da variável
    ```
* Aula 5 @ 09/03/2023 (✏️ em edição)
  * Structs!
  ```c
  // declaração de um tipo pessoa
  struct pessoa {
    int idade;
    char nome[30];
  }
  ```
#### Estruturas de Dados em C
> As Estruturas de Dados estudadas durante a Unidade 1 da disciplina são: Listas Estáticas e Listas Dinâmicas.

* Aula 6 @ 14/03/2023 (✏️ em edição)
  * **LISTAS**
    ```c
    // Criando um tipo ou estrutura de dado LISTA
    struct lista {
      int v[5]; // os dados da lista é um vetor de 5 elementos
      int oc; // propriedade de controle da lista
    }

    // declaração de um tipo lista na main
    struct lista l;
    ```
    * Composta por uma propriedade vetor e uma propriedade de controle
    * Uma lista é inicializada após a declaração quando a propriedade de controle recebe um valor, comumente `l.oc = -1`

### 📚 Tarefas
Cada unidade da disciplina contém ao menos 1 diretório de tarefas com o seu respectivo arquivo `README.md` o qual descreve a atividade.

### 📖 Exercícios dos Livros
Em breve.

### 📔 Prova
* Ponteiros
* Vetores
* Alocação estática
* Alocação dinâmica
* Estrutura de Dados: Lista
* Estrutura de Dados: Lista Ordenada