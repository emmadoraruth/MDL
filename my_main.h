#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "matrix.h"
#include "ml6.h"
#include "display.h"
#include "symtab.h"
#include "draw.h"
#include "parser.h"
#include "y.tab.h"
#include "stack.h"

struct knob_value{
  char name[64];
  double value;
  struct knob_value *next;
  int animagus;
};

int frames = -1;
int varies = 0;
char basename[64];
struct knob_value **frame_values;

void print_knobs();
void set_knobs();
struct knob_value *add_knob_value(char k_name[64], double k_value, struct knob_value *array, int type);
struct knob_value *get_knob(char k_name[64], int frame);

void move(stack *hay, int i, double knobby);
void scale(stack *hay, int i, double knobby);
void rotate(stack *hay, int i, double knobby);

void sphere(stack *hay, struct matrix *shape, screen *s, color *c, int i, struct zbuff *buff);
void torus(stack *hay, struct matrix *shape, screen *s, color *c, int i, struct zbuff *buff);
void box(stack *hay, struct matrix *shape, screen *s, color *c, int i, struct zbuff *buff);

void pass_one();
void pass_two();

void my_main();
