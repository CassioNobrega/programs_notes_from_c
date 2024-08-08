#include <stdio.h>
#include <stdlib.h>


struct Node {
  int data;
  struct Node *next;
};


void add_stack(struct Node **p, int data) {
  struct Node *new_node = malloc(sizeof(struct Node)), *aux;
  new_node->data = data;
  new_node->next = NULL;
  if(*p){
    new_node->next = *p;
    }
  *p = new_node;

};

void remove_stack(struct Node **ponteiro){
  struct Node *aux = *ponteiro;
  if(ponteiro){
    *ponteiro = aux->next;
  } else {
    printf("PILHA VAZIA\n");
  };
};

void get_stack(struct Node *p) {
  struct Node *aux;
  aux = p;
  while (aux != NULL) {
    printf("%d ", aux->data);
    aux = aux->next;
  };
  printf("\n");
};

int main() {
  // Instancias de ponteiro do struct Node
  struct Node *pilha1 = NULL;
  
  // Incersao na pilha 1 com funcao de tipo Node
  add_stack(&pilha1, 121);
  add_stack(&pilha1, 451);
  add_stack(&pilha1, 31);

  // Remocao na pilha 1 com funcao de tipo Node
  remove_stack(&pilha1);

  // Chamada a funcao get para pilha 1
  get_stack(pilha1);


  return 0;

};
