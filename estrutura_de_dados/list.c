#include <stdio.h>
#include <stdlib.h>

// Struct do objeto node
struct Node {
    struct Node *next;
    int data;
};

// Funcao de inserir na lista do tipo Node
struct Node* insert(struct Node *p, int data) {    
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = p;
    return new_node;
};

// Funcao de inserir na lista do tipo void
void insert_void(struct Node **p, int data) {
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    if (*p != NULL) {
      new_node->next = *p;
    }
    *p = new_node;
};

// Funcao de ver lista encadeada
void get_list(struct Node *p) {
  struct Node *aux;
  aux = p;
  while (aux != NULL) {
    printf("%d ", aux->data);
    aux = aux->next;
  };
  printf("\n");
};

int main(){

  // Instancias de ponteiro do struct Node
  struct Node *lista1 = NULL , *lista2 = NULL;
  
  // Incersao na lista 1 com funcao de tipo Node
  lista1 = insert(lista1, 121);
  lista1 = insert(lista1, 451);
  lista1 = insert(lista1, 31);
  
  // Chamada a funcao get para lista 1
  get_list(lista1);

  // Incersao na lista 2 com funcao de tipo void
  insert_void(&lista2, 121);
  insert_void(&lista2, 122);
  insert_void(&lista2, 123);

  // Chamada a funcao get para lista 2
  get_list(lista2);

  return 0;
};