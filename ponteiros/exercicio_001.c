#include <stdio.h>


int main(){


  int CONST_A=10, 
      CONST_B=11, 
      CONST_RESULT,
      *p1, 
      *p2;

  p1=&CONST_A;
  p2=&CONST_B;

  CONST_RESULT = *p1 + *p2;

  printf("%d\n", CONST_RESULT);

  return 0;


};