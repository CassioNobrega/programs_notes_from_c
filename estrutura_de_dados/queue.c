#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void add_queue(struct Node **ponteiro, int data);
void remove_queue(struct Node **ponteiro);
void update_queue(struct Node *ponteiro, int old_number, int new_number);
void get_queue(struct Node *ponteiro);


int main ()
{

  struct Node *_queue = NULL;

  add_queue(&_queue, 10);
  add_queue(&_queue, 20);
  add_queue(&_queue, 30);

  update_queue(_queue, 310, 1);

  remove_queue(&_queue);
  remove_queue(&_queue);
  remove_queue(&_queue);

  get_queue(_queue);

  return 0;
};


void add_queue (struct Node **ponteiro, int data) 
{
  struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = data;
  new_node->next = NULL;
  if(ponteiro){
    new_node->next = *ponteiro;
  };
  *ponteiro = new_node;
}


void remove_queue (struct Node **ponteiro) 
{
  if(*ponteiro)
  {
    struct Node *aux;
    aux = *ponteiro;
    if (aux->next)
    {
      while (aux->next->next)
      {
        aux = aux->next;
      }
      free(aux->next);
      aux->next = NULL;
    } else 
    {
      free(*ponteiro);
      *ponteiro = NULL;
    }
    printf("Nó removido com sucesso\n");
  } else
    {
      printf("\nFILA VAZIA!\nNenhum no removido\n\n");
    };
};


void update_queue (struct Node *ponteiro, int old_number, int new_number)
{
  if (ponteiro)
  {
    struct Node *aux;
    aux = ponteiro;
    while (aux)
    {
      if (aux->data == old_number)
      {
        aux->data = new_number;
        printf("Número %d alterado para %d com sucesso\n", old_number, new_number);
      };
      aux = aux->next;
    };
  }
};


void get_queue (struct Node *ponteiro) 
{
  if (ponteiro)
  {
    struct Node *aux;
    aux = ponteiro;
    while (aux)
    {
      printf("%d\n", aux->data);
      aux = aux->next;
    }
  } else {
      printf("FILA VAZIA\n");
    };
};
