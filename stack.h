#include "matrix.h"

struct stack{
  int top;
  struct matrix matrices[256];
}typedef stack;

stack *sinit();
void push(stack *hay);
void pop(stack *hay);
