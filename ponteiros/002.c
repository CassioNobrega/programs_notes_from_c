#include <stdio.h>


int main(){


  //valor é a varivel que sera apontada pelo ponteiro//
  int valor = 1;

  //declaracao de ponteiro nulo//
  int *ponteiro = NULL;

  //atribuindo endereco da variavel para o ponteiro//
  ponteiro = &valor;

  //visualizando variavel//
  printf("VARIAVEL:%d\n", valor);

  //visualizando endereco da variavel valor//
  printf("ENDERECO VALOR:%d\n", (void*)ponteiro);

  //visualizando endereco do ponteiro//
  printf("ENDERECO PONTEIRO:%d\n", (void*)&ponteiro);

  return 0;
};
