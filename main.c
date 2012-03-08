#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "matrix.h"
#include "ml6.h"
#include "display.h"
#include "draw.h"

void parse_nums(double vals[], char buffer[]){
  char *prev, *curr = buffer;
  int i = 0;
  while(curr){
    prev = strsep(&curr, " ");
    sscanf(prev, "%lf", &vals[i]);
    i++;
  }
}

int main(){

  struct matrix *points = new_matrix(4, 1);
  struct matrix *transform = new_matrix(4, 4);
  ident(transform);
  char input[64];
  char command;
  double args[6];
  screen s;
  color c;
  c.green = 128;
  clear_screen(s);

  while(1){

    fgets(input, sizeof(input), stdin);
    *(strchr(input, '\n')) = 0;
    printf("\tCommand Read\n");
    command = input[0];

    if(command == 'q')
      break;
    else if(command == 'w'){
      printf("\tClearing\n");
      free_matrix(transform);
      free_matrix(points);
      points = new_matrix(4, 1);
      transform = new_matrix(4, 4);
      ident(transform);
    }
    else if(command == 'i'){
      printf("\tCreating Identity\n");
      ident(transform);
    }
    else if(command == 'a'){
      printf("\tApplying\n");
      matrix_mult(transform, points);
    }
    else if(command == 'v'){
      printf("\tDisplaying\n");
      clear_screen(s);
      draw_lines(points, s, c);
      display(s);
    }

    else{
      fgets(input, sizeof(input), stdin);
      *(strchr(input, '\n')) = 0;
      if(command != 'g')
	parse_nums(args, input);
      if(command == 'l'){
	printf("\tLine\n");
	add_edge(points, args[0], args[1], args[2], args[3], args[4], args[5]);
      }
      else if(command == 's'){
	printf("\tScaling\n");
	matrix_mult(make_scale(args[0], args[1], args[2]), transform);
      }
      else if(command == 't'){
	printf("\tTranslating\n");
	matrix_mult(make_translate(args[0], args[1], args[2]), transform);
      }
      else if(command == 'x'){
	printf("\tRotating in X\n");
	matrix_mult(make_rotX(args[0]), transform);
      }
      else if(command == 'y'){
	printf("\tRotating in Y\n");
	matrix_mult(make_rotY(args[0]), transform);
      }
      else if(command == 'z'){
	printf("\tRotating in Z\n");
	matrix_mult(make_rotZ(args[0]), transform);
      }
      else if(command == 'c'){
	printf("\tCircle\n");
	render_circle(points, args[0], args[1], args[2], args[3]);
      }
      else if(command == 'm'){
	printf("\tMunchkin\n");
	render_sphere_mesh(points, args[0], args[1], args[2], .05);
      }
      else if(command == 'd'){
	printf("\tDoughnut\n");
	render_torus_mesh(points, args[0], args[1], args[2], args[3], .05);
      }
      else if(command == 'g'){
	printf("\tSaving\n");
	clear_screen(s);
	draw_lines(points, s, c);
	save_extension(s, input);
      }
    }

  }

  free_matrix(points);
  free_matrix(transform);

  return 42;

}
