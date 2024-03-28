
// Incluir biblioteca de entrada e saída de dados
// scanf e printf
#include <stdio.h>

// Incluir biblioteca para alocação de memória dinâmica
// malloc e exit
#include <stdlib.h>

// Defino um tipo de estrutura chamada nó
typedef struct Node
{
  int value;

  // A estrutura Node deve apontar pro ponteiro next
  struct Node *next;
} Node;

// Declarada um ponteiro head e informando que seu valor é nulo
// Isso é o topo de Node tá zerado
Node *head = NULL;

// Void é uma função que retorna um valor sem tipo específico
// Criar a função que não possui retorno pra adicionar um nó com o value
// A função apernas modifica a lista encadeada
void addNode(int value)
{
  // Aloca memoria suficiente pra alocar em Node
  Node *newNode = (Node *)malloc(sizeof(Node));
  // Salva o valor
  newNode->value = value;
  // Proxima posição do nó
  newNode->next = head;
  // O head é igual a newNode
  head = newNode;
}

// Void é uma função que não retorna nenhum
// Criar uma função pra imprimir a lista
void printList()
{
  // Aponto o head para o ponteiro de Node
  Node *temp = head;

  // Enquanto o ponteiro for diferente de null
  // Enquanto ouver nó ele excuta o bloco de código
  while (temp != NULL)
  {
    // Exibir
    printf("%d ", temp->value);
    // Atribuir temp ao next
    temp = temp->next;
  }
  // Dar um espaço entre cada nó exibido
  printf("\n");
}

int main()
{
  // Adicionar o nó
  addNode(10);
  // Adicionar o nó
  addNode(20);
  // Exibir a lista
  printList();
  // Liberar a execução
  return 0;
}
