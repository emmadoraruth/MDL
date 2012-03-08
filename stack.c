#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"
#include "stack.h"

stack *sinit(){
  stack *hay = malloc(sizeof(stack));
  hay -> matrices[0] = *new_matrix(4, 4);
  ident(&hay -> matrices[0]);
  hay -> top = 0;
  //printf("Initialized: %d\n", hay -> top);
  //print_matrix(&hay -> matrices[hay -> top]);
  return hay;
}

void push(stack *hay){
  hay -> top ++;
  hay -> matrices[hay -> top] = *new_matrix(4, 4);
  copy_matrix(&hay -> matrices[hay -> top - 1], &hay -> matrices[hay -> top]);
  //printf("pushed: %d\n", hay -> top);
  //print_matrix(&hay -> matrices[hay -> top]);
}

void pop(stack *hay){
  hay -> top --;
  ident(&hay -> matrices[hay -> top]);
  //printf("popped: %d\n", hay -> top);
  //print_matrix(&hay -> matrices[hay -> top]);
}
