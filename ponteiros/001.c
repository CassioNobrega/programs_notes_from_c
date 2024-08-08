#include <stdio.h>

int main(){


  //valor é a varivel que sera apontada pelo ponteiro//
  int valor = 1;

  //declaracao de ponteiro//
  int *ponteiro;
  //declaracao de ponteiro nulo//
  int *ponteiro_nulo = NULL;

  //atribuindo endereco da variavel para o ponteiro//
  ponteiro = &valor;

  //visualizando//
  printf("VARIAVEL:%d\n", valor);
  printf("ENDERECO PONTEIRO:%d\n", ponteiro);
  printf("ENDERECO PONTEIRO NULO:%d\n", ponteiro_nulo);

  return 0;


};