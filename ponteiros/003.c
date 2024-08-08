#include <stdio.h>

typedef struct dma dma_struct;

struct dma {
  int dia, mes, ano;
};

int main(){
  
  dma_struct const_, *pointer_;

  const_.ano = 2024;
  const_.mes = 07;
  const_.dia = 22;

  pointer_ = &const_;

  printf("dia %d\nmes %d\nano %d\n", const_.dia, const_.mes, const_.ano);
  printf("ponteiro dma: %d\n", (void *)pointer_);
  printf("ponteiro do ponteiro: %d\n", (void *)&pointer_);
  

  return 0;
};