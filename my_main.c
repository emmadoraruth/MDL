#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "z_buffer.h"
#include "my_main.h"

void print_knobs(){
  int i;
  printf("--------------------------------------\nID\t\tName\t\tValue\n");
  for(i = 0; i < lastsym; i++)
    if(symtab[i].type == SYM_VALUE)
      printf("%d\t\t%s\t\t%6.2f\n", i, symtab[i].name, symtab[i].s.value);
}

void move(stack *hay, int i, double knobby){
  matrix_mult_reverse(&hay -> matrices[hay -> top], make_translate(op[i].op.move.d[0] * knobby, op[i].op.move.d[1] * knobby, op[i].op.move.d[2] * knobby));
}

void scale(stack *hay, int i, double knobby){
  matrix_mult_reverse(&hay -> matrices[hay -> top], make_scale(op[i].op.scale.d[0] * knobby, op[i].op.scale.d[1] * knobby, op[i].op.scale.d[2] * knobby));
}

void rotate(stack *hay, int i, double knobby){
  if(op[i].op.rotate.axis == 0)
    matrix_mult_reverse(&hay -> matrices[hay -> top], make_rotX(op[i].op.rotate.degrees * knobby));
  else if(op[i].op.rotate.axis == 1)
    matrix_mult_reverse(&hay -> matrices[hay -> top], make_rotY(op[i].op.rotate.degrees * knobby));
  else
    matrix_mult_reverse(&hay -> matrices[hay -> top], make_rotZ(op[i].op.rotate.degrees * knobby));
}

void pass_one(){
  int i, b = 0, f = 0, v = 0;
  for(i = 0; i < lastop; i++)
    switch (op[i].opcode){
    case BASENAME:
      strncpy(basename, op[i].op.basename.p -> name, sizeof(basename));
      b++;
      break;
    case FRAMES:
      frames = op[i].op.frames.num_frames;
      f++;
      break;
    case VARY:
      v++;
      varies++;
      break;
    }
  if(v > 0){
    if(b == 0)
      printf("Error: No Basename\n");
    if(f == 0)
      printf("Error: No Frames\n");
  }
  if(b > 1)
    printf("Error: Conflicting Basenames\n");
  if(f > 1)
    printf("Error: Conflicting Numbers of Frames\n");
  //printf("Frames in pass1 = %d\n", frames);

}

struct knob_value * add_knob_value(char k_name[64], double k_value, struct knob_value *array, int type){
  struct knob_value *new = (struct knob_value *)malloc(sizeof(struct knob_value));
  new -> value = k_value;
  strcpy (new -> name, k_name);
  new -> next = array;
  new -> animagus = type;
  array = new;
  return array;
}

struct knob_value * get_knob(char k_name[64], int frame){
  struct knob_value *temp;
  temp = frame_values[frame];
  while(temp != NULL){
    if(!strncmp(temp -> name, k_name, 64))
       return temp;
       temp = temp -> next;
  }
  return temp;
} 

void pass_two(){

  int i, j, start, end;
  double step, curr_val;
  frame_values = (struct knob_value **)malloc(frames * sizeof(struct knob_value *));
  for(i = 0; i < frames; i++)
    frame_values[i] = NULL;
  struct knob_value *temp;

  for(i = 0; i < lastop; i++)
    switch(op[i].opcode){
    case VARY:
      start = op[i].op.vary.start_frame;
      end = op[i].op.vary.end_frame;
      step = (op[i].op.vary.end_val - op[i].op.vary.start_val) / (end - start);
      curr_val = op[i].op.vary.start_val;

      //Preceding Frames
      for(j = start - 1; j >= 0; j--){
	temp = get_knob(op[i].op.vary.p -> name, j);
	if(temp == NULL)
	  frame_values[j] = add_knob_value(op[i].op.vary.p -> name, curr_val, frame_values[j], 2);
	else if(temp -> animagus == 2)
	  temp -> value = curr_val;
	else
	  break;
	//printf("Value at frame %d is %6.2f for knob %s\n", j, curr_val, op[i].op.vary.p -> name);
      }

      //printf("Current Value: %6.2f\n", curr_val);

      //Varied Frames
      for(j = start; j <= end; j++){
	temp = get_knob(op[i].op.vary.p -> name, j);
	if(temp == NULL)
	  frame_values[j] = add_knob_value(op[i].op.vary.p -> name, curr_val, frame_values[j], 0);
	else if(temp -> animagus == 0){
	  printf("Error: Overlapping Varies\n");
	  break;
	}
	else{
	  temp -> value = curr_val;
	  temp -> animagus = 0;
	}
	//printf("Value at frame %d is %6.2f for knob %s\n", j, curr_val, op[i].op.vary.p -> name);
	curr_val += step;
      }

      //printf("Current Value: %6.2f\n", curr_val);

      //Proceding Frames
      curr_val -= step;
      for(j = end + 1; j < frames; j++){
	temp = get_knob(op[i].op.vary.p -> name, j);
	if(temp == NULL)
	  frame_values[j] = add_knob_value(op[i].op.vary.p -> name, curr_val, frame_values[j], 1);
	else if(temp -> animagus != 0){
	  temp -> value = curr_val;
	  temp -> animagus = 1;
	}
	else
	  break;
	//printf("Value at frame %d is %6.2f for knob %s\n", j, curr_val, op[i].op.vary.p -> name);
      }

      break;
    }
}

void set_knobs(){
  int i = 0;
  double j;
  char kid[8];
  while(i != -1){
    print_knobs();
    printf("Enter ID of Knob to Set (-1 to Stop): ");
    fgets(kid, sizeof(kid), stdin);
    *(strchr(kid, '\n')) = 0;
    sscanf(kid, "%d", &i);
    printf("Scanned\n");
    if(i != -1){
      printf("Enter New Value for %s: \n", symtab[i].name);
      fgets(kid, sizeof(kid), stdin);
      *(strchr(kid, '\n')) = 0;
      sscanf(kid, "%lf", &j);
      set_value(lookup_symbol(symtab[i].name), j);
    }
  }
}

void box(stack *hay, struct matrix *shape, screen *s, color *c, int i, struct zbuff *buff){
  struct constants *constant = (struct constants *)malloc(sizeof(struct constants));
  int j;
  poxy_box(shape, op[i].op.box.d0[0], op[i].op.box.d0[1], op[i].op.box.d0[2], op[i].op.box.d1[0], op[i].op.box.d1[1], op[i].op.box.d1[2]);
  matrix_mult(&hay -> matrices[hay -> top], shape);
  if(op[i].op.box.constants == NULL)
    for(j = 0; j < 3; j++){
      constant -> r[j] = 1;
      constant -> g[j] = 1;
      constant -> b[j] = 1;
      constant -> red = 0;
      constant -> green = 0;
      constant -> blue = 0;
    }
  else
    constant = lookup_symbol(op[i].op.box.constants -> name) -> s.c;
  draw_polygons(shape, *s, *c, constant, buff);
}

void torus(stack *hay, struct matrix *shape, screen *s, color *c, int i, struct zbuff *buff){
  struct constants *constant = (struct constants *)malloc(sizeof(struct constants));
  int j;
  render_polygonal_torus(shape, op[i].op.torus.r0, op[i].op.torus.r1, op[i].op.torus.d[0], op[i].op.torus.d[1], op[i].op.torus.d[2], .05);
  matrix_mult(&hay -> matrices[hay -> top], shape);
  if(op[i].op.torus.constants == NULL)
    for(j = 0; j < 3; j++){
      constant -> r[j] = 1;
      constant -> g[j] = 1;
      constant -> b[j] = 1;
      constant -> red = 0;
      constant -> green = 0;
      constant -> blue = 0;
    }
  else
    constant = lookup_symbol(op[i].op.torus.constants -> name) -> s.c;
  draw_polygons(shape, *s, *c, constant, buff);
}

void sphere(stack *hay, struct matrix *shape, screen *s, color *c, int i, struct zbuff *buff){
  struct constants *constant = (struct constants *)malloc(sizeof(struct constants));
  int j;
  render_polygonal_sphere(shape, op[i].op.sphere.r, op[i].op.sphere.d[0], op[i].op.sphere.d[1], op[i].op.sphere.d[2], .05);
  matrix_mult(&hay -> matrices[hay -> top], shape);
  if(op[i].op.sphere.constants == NULL)
    for(j = 0; j < 3; j++){
      constant -> r[j] = 1;
      constant -> g[j] = 1;
      constant -> b[j] = 1;
      constant -> red = 0;
      constant -> green = 0;
      constant -> blue = 0;
    }
  else
    constant = lookup_symbol(op[i].op.sphere.constants -> name) -> s.c;
  draw_polygons(shape, *s, *c, constant, buff);
}

void print_frames(struct knob_value **array){
  int i;
  struct knob_value *temp;
  for(i = 0; i < frames; i++){
    printf("Frame: %d\n", i);
    temp = array[i];
    while(temp){
      printf("Knob %s has value %6.2f\n", temp -> name, temp -> value);
      temp = temp -> next;
    }
  }
}

void set_frame(struct knob_value **array, int frame){
  struct knob_value *temp;
  temp = array[frame];
  while(temp){
      set_value(lookup_symbol(temp -> name), temp -> value);
      temp = temp -> next;
  }
}


void my_main(){

  stack *hay = sinit();
  struct matrix *temp = new_matrix(4, 1);
  int i, j, k, l;
  screen s;
  clear_screen(s);
  color c;
  c.red = 85;
  c.blue = 85;
  c.green = 85;
  char name[64];
  struct zbuff *buff = (struct zbuff *)malloc(sizeof(struct zbuff));
  for(k = 0; k < XRES; k++){
    for(l = 0; l < YRES; l++){
      buff -> arr[k][l].c.red = 0;
      buff -> arr[k][l].c.blue = 0;
      buff -> arr[k][l].c.green = 0;
      buff -> arr[k][l].z = -1 * pow(2, 10);
    }
  }

  pass_one();
  int temp2 = frames;
  //printf("Frames = %d\n", frames);
  if(varies)
    pass_two();
  else
    set_knobs();
  //printf("Frames: %d\nBasename: %s\n", frames, basename);
  //print_frames(frame_values);

  if(frames == -1)
    frames = 1;

  for(j = 0; j < frames; j++){

    for(k = 0; k < XRES; k++){
      for(l = 0; l < YRES; l++){
	buff -> arr[k][l].c.red = 0;
	buff -> arr[k][l].c.blue = 0;
	buff -> arr[k][l].c.green = 0;
	buff -> arr[k][l].z = -1 * pow(2, 10);
      }
    }

    if(varies)
      set_frame(frame_values, j);

    for(i = 0; i < lastop; i++){
      switch (op[i].opcode){
      case POP:
	pop(hay);
	break;
      case PUSH:
	push(hay);
	break;
      case MOVE:
	if(op[i].op.move.p != NULL)
	  move(hay, i, (lookup_symbol(op[i].op.move.p -> name) -> s).value);
	else
	  move(hay, i, 1);
	//printf("Moved: %d\n", hay -> top);
	break;
      case SCALE:
	if(op[i].op.scale.p != NULL)
	  scale(hay, i, (lookup_symbol(op[i].op.scale.p -> name) -> s).value);
	else
	  scale(hay, i, 1);
	//printf("Scaled: %d\n", hay -> top);
	break;
      case ROTATE:
	if(op[i].op.rotate.p != NULL)
	  rotate(hay, i, (lookup_symbol(op[i].op.rotate.p -> name) -> s).value);
	else
	  rotate(hay, i, 1);
	//printf("Rotated: %d\n", hay -> top);
	break;
      case SPHERE:
	//printf("Sphere\n");
	sphere(hay, temp, &s, &c, i, buff);
	free_matrix(temp);
	temp = new_matrix(4, 1);
	break;
      case TORUS:
	//printf("Torus\n");
	torus(hay, temp, &s, &c, i, buff);
	free_matrix(temp);
	temp = new_matrix(4, 1);
	break;
      case BOX:
	//printf("Box\n");
	box(hay, temp, &s, &c, i, buff);
	free_matrix(temp);
	temp = new_matrix(4, 1);
	break;
      case DISPLAY:
	//printf("Displayed\n");
	display(s);
	break;
      case SAVE:
	//printf("Saved\n", j);
	save_extension(s, op[i].op.save.p -> name);
	break;
      case SET:
	set_value(lookup_symbol(op[i].op.set.p -> name), op[i].op.set.p -> s.value);
      case LIGHT:
	break;
      case AMBIENT:
	break;
      case CONSTANTS:
	break;
      }
    }

    if(temp2 != -1){
      sprintf(name, "%s%04d", basename, j);
      save_extension(s, name);
      printf("SAVING FRAME %s\n", name);

    }
    clear_screen(s);

  }

}
