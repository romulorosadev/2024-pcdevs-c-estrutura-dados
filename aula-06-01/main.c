// Biblioteca para entrada/saída de dados
// printf
#include <stdio.h>

// Biblioteca para alocação de memória dinâmica
// malloc e exit
#include <stdlib.h>

// Biblioteca manipulação de strings
// strcpy
#include <string.h>

// Definição da estrutura do nó da lista
typedef struct Contact
{
  char name[50];
  char phone[15];
  // Ponteiro para outra estrutura Contact
  // Elo entre o Contato atual e o próximo
  struct Contact *next;
} Contact;

// Função para criar um novo contato
// 2 ponteiros (char e phone) e aponta pra um ponteiro Contact
Contact *createContact(char *name, char *phone)
{
  // Alocando contact num novo Contato
  Contact *newContact = (Contact *)malloc(sizeof(Contact));
  // Verificando se o contato está null
  if (newContact == NULL)
  {
    printf("Erro ao alocar na memória.");
    exit(1);
  }
  // Copia a string
  strcpy(newContact->name, name);
  strcpy(newContact->phone, phone);
  newContact->next = NULL;
  return newContact;
}

// Função para adicionar um contato no final da lista
// **head ponteiro duplo - Cabeça da lista
void addContact(Contact **head, char *name, char *phone)
{
  //
  Contact *newContact = createContact(name, phone);
  if (*head == NULL)
  {
    *head = newContact;
    return;
  }
  Contact *temp = *head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }

  temp->next = newContact;
}

// Função para exibir todos os contatos da lista
void displayContacts(Contact *head)
{
  printf("Lista de contatos:\n");
  while (head != NULL)
  {
    printf("Nome: %s, Telefone: %s\n", head->name, head->phone);
    head = head->next;
  }
  printf("\n");
}

int main()
{
  Contact *contactList = NULL;
  char name[50];
  char phone[15];
  int numContacts;

  // Solicitar a entrada dos dados
  printf("Quantos contatos deseja adicionar? ");
  // Armazenar o dado para que seja manipulado
  scanf("%d", &numContacts);

  // Loop pra percorrer numContacts
  // Enquanto a quantidade for menor que o numero de contatos desejados executar o bloco de código
  for (int i = 0; i < numContacts; i++)
  {
    // Solicitar a entrada dos dados
    printf("Digite o nome do contato: ");
    // Armazenar o dado para que seja manipulado
    scanf("%s", name);
    // Solicitar a entrada dos dados
    printf("Digite o número de telefone do contato: ");
    // Armazenar o dado para que seja manipulado
    scanf("%s", phone);

    // Adicionar o contato na lista com name e phone
    addContact(&contactList, name, phone);
  }
  // Exibir Contatos com base na contactList
  displayContacts(contactList);

  return 0;
}
