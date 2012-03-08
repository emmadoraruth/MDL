#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "ml6.h"
#include "matrix.h"
#include "display.h"
#include "z_buffer.h"
#include "draw.h"
#include "vector.h"
#include "symtab.h"


void boxy_box(struct matrix *points, double x, double y, double z, double h, double w, double d){
  add_edge(points, (int)x, (int)y, (int)z, (int)x + (int)w, (int)y, (int)z);
  add_edge(points, (int)x, (int)y, (int)z, (int)x, (int)y + (int)h, (int)z);
  add_edge(points, (int)x, (int)y, (int)z, (int)x, (int)y, (int)z + (int)d);
  add_edge(points, (int)x + (int)w, (int)y, (int)z, (int)x + (int)w, (int)y + (int)h, (int)z);
  add_edge(points, (int)x + (int)w, (int)y, (int)z, (int)x + (int)w, (int)y, (int)z + (int)d);
  add_edge(points, (int)x, (int)y + (int)h, (int)z, (int)x + (int)w, (int)y + (int)h, (int)z);
  add_edge(points, (int)x, (int)y + (int)h, (int)z, (int)x, (int)y + (int)h, (int)z + (int)d);
  add_edge(points, (int)x, (int)y, (int)z + (int)d, (int)x + (int)w, (int)y, (int)z + (int)d);
  add_edge(points, (int)x, (int)y, (int)z + (int)d, (int)x, (int)y + (int)h, (int)z + (int)d);
  add_edge(points, (int)x + (int)w, (int)y + (int)h, (int)z, (int)x + (int)w, (int)y + (int)h, (int)z + (int)d);
  add_edge(points, (int)x + (int)w, (int)y, (int)z + (int)d, (int)x + (int)w, (int)y + (int)h, (int)z + (int)d);
  add_edge(points, (int)x, (int)y + (int)h, (int)z + (int)d, (int)x + (int)w, (int)y + (int)h, (int)z + (int)d);
}


void poxy_box(struct matrix *points, double x, double y, double z, double h, double w, double d){
  //Upper Front
  add_polygon(points, (int)x, (int)y, (int)z, (int)x + (int)w, (int)y, (int)z, (int)x, (int)y + (int)h, (int)z);
  //Lower Front
  add_polygon(points, (int)x + (int)w, (int)y + (int)h, (int)z, (int)x, (int)y + (int)h, (int)z, (int)x + (int)w, (int)y, (int)z);
  //Upper Right
  add_polygon(points, (int)x + (int)w, (int)y, (int)z, (int)x + (int)w, (int)y, (int)z + (int)d, (int)x + (int)w, (int)y + (int)h, (int)z);
  //Lower Right
  add_polygon(points, (int)x + (int)w, (int)y + (int)h, (int)z + (int)d, (int)x + (int)w, (int)y + (int)h, (int)z, (int)x + (int)w, (int)y, (int)z + (int)d);
  //Upper Back
  add_polygon(points, (int)x + (int)w, (int)y, (int)z + (int)d, (int)x, (int)y, (int)z + (int)d, (int)x + (int)w, (int)y  + (int)h, (int)z + (int)d);
  //Lower Back
  add_polygon(points, (int)x, (int)y + (int)h, (int)z + (int)d, (int)x + (int)w, (int)y + (int)h, (int)z + (int)d, (int)x, (int)y, (int)z + (int)d);
  //Upper Left
  add_polygon(points, (int)x, (int)y, (int)z + (int)d, (int)x, (int)y, (int)z, (int)x, (int)y + (int)h, (int)z + (int)d);
  //Lower Left
  add_polygon(points, (int)x, (int)y + (int)h, (int)z, (int)x, (int)y + (int)h, (int)z + (int)d, (int)x, (int)y, (int)z);
  //Upper Top
  add_polygon(points, (int)x, (int)y, (int)z + (int)d, (int)x + (int)w, (int)y, (int)z + (int)d, (int)x, (int)y, (int)z);
  //Lower Top
  add_polygon(points, (int)x + (int)w, (int)y, (int)z, (int)x, (int)y, (int)z, (int)x + (int)w, (int)y, (int)z + (int)d);
  //Upper Bottom
  add_polygon(points, (int)x, (int)y + (int)h, (int)z, (int)x + (int)w, (int)y + (int)h, (int)z, (int)x, (int)y + (int)h, (int)z + (int)d);
  //Lower Bottom
  add_polygon(points, (int)x + (int)w, (int)y + (int)h, (int)z + (int)d, (int)x, (int)y + (int)h, (int)z + (int)d, (int)x + (int)w, (int)y + (int)h, (int)z);
}


void save_line(struct matrix *points, int x0, int y0, int z0, int x1, int y1, int z1){
 
  int x, y, z, d, dx, dy, switched = 0;
  double z_slope = -1;
  struct matrix *temp;

  x = x0;
  y = y0;
  z = z0;
  
  //swap points so we're always drawing left to right
  if ( x0 > x1 ) {
    x0 = x1;
    y0 = y1;
    x1 = x;
    y1 = y;
    x = x0;
    y = y0;
    z0 = z1;
    z1 = z;
    switched = 1;
  }

  //need to know dx and dy for this version
  dx = x1 - x;
  dy = y1 - y;
  if(y1 != y0)
    z_slope = (z1 - z0) / dy;
  else if(x1 != x0)
    z_slope = (z1 - z0) / dx;

  //positive slope: Octants 1, 2 (5 and 6)
  if ( dy > 0 ) {

    //slope < 1: Octant 1 (5)
    if ( dx > dy ) {
      d = 2 * dy - dx;
  
      while ( x < x1 ) {

	if(y1 != y0)
	  add_point(points, x, y, z_slope * (y - y0) + z0);
	else if(x1 != x0)
	  add_point(points, x, y, z_slope * (x - x0) + z0);

	if ( d < 0 ) {
	  x = x + 1;
	  d = d + dy;
	}
	else {
	  x = x + 1;
	  y = y + 1;
	  d = d + dy - dx;
	}
      }
    }

    //slope > 1: Octant 2 (6)
    else {
      d = dy - 2 * dx;
      while ( y < y1 ) {

	if(y1 != y0)
	  add_point(points, x, y, z_slope * (y - y0) + z0);
	else if(x1 != x0)
	  add_point(points, x, y, z_slope * (x - x0) + z0);

	if ( d > 0 ) {
	  y = y + 1;
	  d = d - dx;
	}
	else {
	  y = y + 1;
	  x = x + 1;
	  d = d + dy - dx;
	}
      }
    }
  }

  //negative slope: Octants 7, 8 (3 and 4)
  else { 

    //slope > -1: Octant 8 (4)
    if ( dx > abs(dy) ) {
      d = 2 * dy + dx;
  
      while ( x < x1 ) {

	if(y1 != y0)
	  add_point(points, x, y, z_slope * (y - y0) + z0);
	else if(x1 != x0)
	  add_point(points, x, y, z_slope * (x - x0) + z0);

	if ( d > 0 ) {
	  x = x + 1;
	  d = d + dy;
	}
	else {
	  x = x + 1;
	  y = y - 1;
	  d = d + dy + dx;
	}
      }
    }

    //slope < -1: Octant 7 (3)
    else {

      d = dy + 2 * dx;
      while ( y >= y1 ) {
	
	if(y1 != y0)
	  add_point(points, x, y, z_slope * (y - y0) + z0);
	else if(x1 != x0)
	  add_point(points, x, y, z_slope * (x - x0) + z0);

	if ( d < 0 ) {
	  y = y - 1;
	  d = d + dx;
	}
	else {
	  y = y - 1;
	  x = x + 1;
	  d = d + dy + dx;
	}
      }
    }
  }

  if(switched == 1){
    temp = new_matrix(4, points -> lastcol);
    copy_matrix(points, temp);
    for(d = temp -> lastcol - 1; d >= 0; d--){
      points -> m[0][d] = temp -> m[0][(temp -> lastcol) - d - 1];
      points -> m[1][d] = temp -> m[1][(temp -> lastcol) - d - 1];
      points -> m[2][d] = temp -> m[2][(temp -> lastcol) - d - 1];
    }
    free_matrix(temp);
  }

}


void draw_line_buffer(struct zbuff *buff, int x0, int y0, int z0, int x1, int y1, int z1, color c){
 
  int x, y, z, d, dx, dy;
  double z_slope = -1;

  x = x0;
  y = y0;
  z = z0;
  
  // printf("z (1,0) is actually: %lf\n", buff->arr[1][0].z);
  //swap points so we're always drawing left to right
  if ( x0 > x1 ) {
    x0 = x1;
    y0 = y1;
    x1 = x;
    y1 = y;
    x = x0;
    y = y0;
    z0 = z1;
    z1 = z;
  }

  //need to know dx and dy for this version
  dx = x1 - x;
  dy = y1 - y;
  if(y1 != y0)
    z_slope = (z1 - z0) / dy;
  else if(x1 != x0)
    z_slope = (z1 - z0) / dx;

  //positive slope: Octants 1, 2 (5 and 6)
  if ( dy > 0 ) {

    //slope < 1: Octant 1 (5)
    if ( dx > dy ) {
      d = 2 * dy - dx;
  
      while ( x < x1 ) {
	if(y1 != y0 && buff -> arr[x][y].z < z_slope * (y - y0) + z0){
	  buff -> arr[x][y].z = z_slope * (y - y0) + z0;
	  buff -> arr[x][y].c = c;
	}
	else if(x1 != x0 && buff -> arr[x][y].z < z_slope * (x - x0) + z0){
	  buff -> arr[x][y].z = z_slope * (x - x0) + z0;
	  buff -> arr[x][y].c = c;
	}

	if ( d < 0 ) {
	  x = x + 1;
	  d = d + dy;
	}
	else {
	  x = x + 1;
	  y = y + 1;
	  d = d + dy - dx;
	}
      }
    }

    //slope > 1: Octant 2 (6)
    else {
      d = dy - 2 * dx;
      while ( y < y1 ) {

	if(y1 != y0 && buff -> arr[x][y].z < z_slope * (y - y0) + z0){
	  buff -> arr[x][y].z = z_slope * (y - y0) + z0;
	  buff -> arr[x][y].c = c;
	}
	else if(x1 != x0 && buff -> arr[x][y].z < z_slope * (x - x0) + z0){
	  buff -> arr[x][y].z = z_slope * (x - x0) + z0;
	  buff -> arr[x][y].c = c;
	}

	if ( d > 0 ) {
	  y = y + 1;
	  d = d - dx;
	}
	else {
	  y = y + 1;
	  x = x + 1;
	  d = d + dy - dx;
	}
      }
    }
  }

  //negative slope: Octants 7, 8 (3 and 4)
  else { 

    //slope > -1: Octant 8 (4)
    if ( dx > abs(dy) ) {
      d = 2 * dy + dx;
  
      while ( x < x1 ) {

	if(y1 != y0 && buff -> arr[x][y].z < z_slope * (y - y0) + z0){
	  buff -> arr[x][y].z = z_slope * (y - y0) + z0;
	  buff -> arr[x][y].c = c;
	}
	else if(x1 != x0 && buff -> arr[x][y].z < z_slope * (x - x0) + z0){
	  buff -> arr[x][y].z = z_slope * (x - x0) + z0;
	  buff -> arr[x][y].c = c;
	}

	if ( d > 0 ) {
	  x = x + 1;
	  d = d + dy;
	}
	else {
	  x = x + 1;
	  y = y - 1;
	  d = d + dy + dx;
	}
      }
    }

    //slope < -1: Octant 7 (3)
    else {

      d = dy + 2 * dx;
      while ( y >= y1 ) {
	
	if(y1 != y0 && buff -> arr[x][y].z < z_slope * (y - y0) + z0){
	  buff -> arr[x][y].z = z_slope * (y - y0) + z0;
	  buff -> arr[x][y].c = c;
	}
	else if(x1 != x0 && buff -> arr[x][y].z < z_slope * (x - x0) + z0){
	  buff -> arr[x][y].z = z_slope * (x - x0) + z0;
	  buff -> arr[x][y].c = c;
	}

	if ( d < 0 ) {
	  y = y - 1;
	  d = d + dx;
	}
	else {
	  y = y - 1;
	  x = x + 1;
	  d = d + dy + dx;
	}
      }
    }
  }
}


void draw_polygon(struct zbuff *buff, int x0, int y0, int z0, int x1, int y1, int z1, int x2, int y2, int z2, color c){
  //printf("Vertices (%d, %d, %d), (%d, %d, %d), (%d, %d, %d)\n", x0, y0, z0, x1, y1, z1, x2, y2, z2);
  int i = 0, j;
  struct matrix *temp1 = new_matrix(4, 0);
  struct matrix *temp2 = new_matrix(4, 0);
  struct matrix *temp3 = new_matrix(4, 0);

  //printf("First z is: %lf\n", buff->arr[0][0].z);

  //printf("Initialized\n");
  if(y0 <= y1 && y1 <= y2){
    //printf("Case 1\n");
    save_line(temp1, x0, y0, z0, x2, y2, z2);
    save_line(temp2, x0, y0, z0, x1, y1, z1);
    save_line(temp3, x1, y1, z1, x2, y2, z2);
  }
  else if(y0 <= y2 && y2 <= y1){
    //printf("Case 2\n");
    save_line(temp1, x0, y0, z0, x1, y1, z1);
    save_line(temp2, x0, y0, z0, x2, y2, z2);
    save_line(temp3, x2, y2, z2, x1, y1, z1);
  }
  else if(y1 <= y2 && y2 <= y0){
    //printf("Case 3\n");
    save_line(temp1, x1, y1, z1, x0, y0, z0);
    save_line(temp2, x1, y1, z1, x2, y2, z2);
    save_line(temp3, x2, y2, z2, x0, y0, z0);
  }
  else if(y1 <= y0 && y0 <= y2){
    //printf("Case 4\n");
    save_line(temp1, x1, y1, z1, x2, y2, z2);
    save_line(temp2, x1, y1, z1, x0, y0, z0);
    save_line(temp3, x0, y0, z0, x2, y2, z2);
  }
  else if(y2 <= y1 && y1 <= y0){
    //printf("Case 5\n");
    save_line(temp1, x2, y2, z2, x0, y0, z0);
    save_line(temp2, x2, y2, z2, x1, y1, z1);
    save_line(temp3, x1, y1, z1, x0, y0, z0);
  }
  else{
    //printf("Case 6\n");
    save_line(temp1, x2, y2, z2, x1, y1, z1);
    save_line(temp2, x2, y2, z2, x0, y0, z0);
    save_line(temp3, x0, y0, z0, x1, y1, z1);
  }
  //printf("Line 1: (%1.0f, %1.0f, %1.0f) to (%1.0f, %1.0f, %1.0f)\nLine 2: (%1.0f, %1.0f, %1.0f) to (%1.0f, %1.0f, %1.0f)\nLine 3: (%1.0f, %1.0f, %1.0f) to (%1.0f, %1.0f, %1.0f)\n", temp1 -> m[0][0], temp1 -> m[1][0], temp1 -> m[2][0], temp1 -> m[0][temp1 -> lastcol - 1], temp1 -> m[1][temp1 -> lastcol - 1], temp1 -> m[2][temp1 -> lastcol - 1], temp2 -> m[0][0], temp2 -> m[1][0], temp2 -> m[2][0], temp2 -> m[0][temp2 -> lastcol - 1], temp2 -> m[1][temp2 -> lastcol - 1], temp2 -> m[2][temp2 -> lastcol - 1],  temp3 -> m[0][0], temp3 -> m[1][0], temp3 -> m[2][0], temp3 -> m[0][temp3 -> lastcol - 1], temp3 -> m[1][temp3 -> lastcol - 1], temp3 -> m[2][temp3 -> lastcol - 1]);
  while(i < temp1 -> lastcol && i < temp2 -> lastcol){
    draw_line_buffer(buff, temp1 -> m[0][i], temp1 -> m[1][i], temp1 -> m[2][i], temp2 -> m[0][i], temp2 -> m[1][i], temp2 -> m[2][i], c);
    i++;
  }
  //printf("Finished Loop 1\n");
  //printf("temp1 -> lastcol: %d\ntemp2 -> lastcol: %d\n", temp1 -> lastcol, temp2 -> lastcol);
  if(i == temp1 -> lastcol && i != temp2 -> lastcol){
    //printf("First Case\n");
    j = temp3 -> lastcol - 1;
    while(i < temp2 -> lastcol && j >= 0){
      draw_line_buffer(buff, temp3 -> m[0][j], temp3 -> m[1][j], temp3 -> m[2][j], temp2 -> m[0][i], temp2 -> m[1][i], temp2 -> m[2][i], c);
      i++;
      j--;
    }
    //printf("Finished Loop 2\n");
  }
  else if(i == temp2 -> lastcol && i != temp1 -> lastcol){
    //printf("Second Case\n");
    j = 0;
    while(i < temp1 -> lastcol && j < temp3 -> lastcol){
      draw_line_buffer(buff, temp1 -> m[0][i], temp1 -> m[1][i],  temp1 -> m[2][i], temp3 -> m[0][j], temp3 -> m[1][j], temp3 -> m[2][j], c);
      i++;
      j++;
    }
    //printf("Finished Loop 3\n");
  }
  free_matrix(temp1);
  free_matrix(temp2);
  free_matrix(temp3);
  //printf("Done\n");
}


struct matrix *cull(struct matrix *points){
  int i;
  double angle;
  struct matrix *ans = new_matrix(4, 0);
  struct vector *normal, *a, *b, *view = new_vector(0, 0, -1);
  for(i = 0; i + 2 < points -> lastcol; i += 3){
    //printf("Vertices in Cull: (%3.3f, %3.3f, %3.3f),(%3.3f, %3.3f, %3.3f), (%3.3f, %3.3f, %3.3f)\n", points -> m[0][i], points -> m[1][i], points -> m[2][i], points -> m[0][i + 1], points -> m[1][i + 1], points -> m[2][i + 1], points -> m[0][i + 2], points -> m[1][i + 2], points -> m[2][i + 2]);
    a = find_vector(points -> m[0][i], points -> m[1][i], points -> m[2][i], points -> m[0][i + 1], points -> m[1][i + 1], points -> m[2][i + 1]);
    normalize(a);
    b = find_vector(points -> m[0][i + 1], points -> m[1][i + 1], points -> m[2][i + 1], points -> m[0][i + 2], points -> m[1][i + 2], points -> m[2][i + 2]);
    normalize(b);
    normal = cross(a, b);
    normalize(normal);
    normalize(view);
    angle = acos(dot(normal, view));
    //printf("a: (%3.3f, %3.3f, %3.3f)\nb: (%3.3f, %3.3f, %3.3f)\nnormal: (%3.3f, %3.3f, %3.3f)\nangle: %3.3f\n", a -> x, a -> y, a -> z, b -> x, b -> y, b -> z, normal -> x, normal -> y, normal -> z, angle);
    if(angle > .5 * M_PI && angle < 1.5 * M_PI)
      add_polygon(ans, points -> m[0][i], points -> m[1][i], points -> m[2][i], points -> m[0][i + 1], points -> m[1][i + 1], points -> m[2][i + 1], points -> m[0][i + 2], points -> m[1][i + 2], points -> m[2][i + 2]);
    //else
      //printf("CULLED!\n");
  }
  return ans;
}



void generate_circle(struct matrix *points, double r, double offx, double offy, double step){
  double d;
  for(d = 0; d <= 1; d += step)
    add_edge(points, r * cos(2 * M_PI * d) + offx, r * sin(2 * M_PI * d) + offy, 0, r * cos(2 * M_PI * d) + offx, r * sin(2 * M_PI * d) + offy, 0);
}


void render_circle(struct matrix *points, double r, double offx, double offy, double step){
  struct matrix *temp = new_matrix(4, 1);
  int i;
  generate_circle(temp, r, offx, offy, step);
  for(i = 0; i < temp -> lastcol - 2; i += 2)
    add_edge(points, temp -> m[0][i], temp -> m[1][i], temp -> m[2][i], temp -> m[0][i + 2], temp -> m[1][i + 2], temp -> m[2][i + 2]);
  i = temp -> lastcol - 2;
  add_edge(points, temp -> m[0][i], temp -> m[1][i], temp -> m[2][i], temp -> m[0][0], temp -> m[1][0], temp -> m[2][0]);
  free_matrix(temp);
}


void generate_torus_mesh(struct matrix *points, double r1, double r2, double offx, double offy, double offz, double step){
  double d, e;
  for(d = 0.0; d <= 1.0000000001; d += step)
    for(e = 0.0; e < .9999999999; e += step)
      add_point(points, r1 * cos(2 * M_PI * d) + r2 * cos(2 * M_PI * d) * cos(2 * M_PI * e) + offx, r2 * sin(2 * M_PI * e) + offy, -r1 * sin(2 * M_PI * d) - r2 * cos(2 * M_PI * e) * sin(2 * M_PI * d) + offz);
}


void render_torus_mesh(struct matrix *points, double r1, double r2, double offx, double offy, double offz, double step){
  struct matrix *temp = new_matrix(4, 1);
  generate_torus_mesh(temp, r1, r2, offx, offy, offz, step);
  double d = 1.0 / step;
  int i, j, k = (int)d;
  for(i = 0; i < k; i++){
    for(j = 0; j < k - 1; j++){
      //Horizontal Lines
      //Usual Case
      if(i < k - 1)
	add_edge(points, temp -> m[0][i * k + j],  temp -> m[1][i * k + j],  temp -> m[2][i * k + j], temp -> m[0][(i + 1) * k + j],  temp -> m[1][(i + 1) * k + j],  temp -> m[2][(i + 1) * k + j]);
      //Last Line Case
      else
	add_edge(points, temp -> m[0][i * k + j], temp -> m[1][i * k + j], temp -> m[2][i * k + j], temp -> m[0][j], temp -> m[1][j], temp -> m[2][j]);
      //Vertical Lines
      //Usual Case
      add_edge(points, temp -> m[0][i * k + j],  temp -> m[1][i * k + j],  temp -> m[2][i * k + j], temp -> m[0][i * k + j + 1],  temp -> m[1][i * k + j + 1],  temp -> m[2][i * k + j + 1]);
    }
    //Last Line Case
      add_edge(points, temp -> m[0][(i + 1) * k - 1], temp -> m[1][(i + 1) * k - 1], temp -> m[2][(i + 1) * k - 1], temp -> m[0][i * k], temp -> m[1][i * k], temp -> m[2][i * k]);
  }
  free_matrix(temp);
}


void render_polygonal_torus(struct matrix *points, double r1, double r2,
			  double offx, double offy, double offz, double step){
  struct matrix * temp = new_matrix(4, 1);
  generate_torus_mesh(temp, r1, r2, offx, offy, offz, step);
  int i, j;
  double k1 = 1.0/step;
  int k = (int)k1;
  for(j = 0; j < k; j ++){
    for(i = 0; i < k - 1; i++){
      add_polygon(points,
		  temp->m[0][i + (j * k)], temp->m[1][i + (j * k)], temp->m[2][i + (j * k)],
		  temp->m[0][i + k + (j * k)], temp->m[1][i + k + (j * k)], temp->m[2][i + k + (j * k)],
		  temp->m[0][i + 1 + (j * k)], temp->m[1][i + 1 + (j * k)], temp->m[2][i + 1 + (j * k)]);
      add_polygon(points,
		  temp->m[0][i + k + 1 + (j * k)], temp->m[1][i + k + 1 + (j * k)], temp->m[2][i + k + 1 + (j * k)],
		  temp->m[0][i + 1 + (j * k)], temp->m[1][i + 1 + (j * k)], temp->m[2][i + 1 + (j * k)],
		  temp->m[0][i + k + (j * k)], temp->m[1][i + k + (j * k)], temp->m[2][i + k + (j * k)]);
    }
    add_polygon(points,
		temp->m[0][i + (j * k)], temp->m[1][i + (j * k)], temp->m[2][i + (j * k)],
		temp->m[0][i + k + (j * k)], temp->m[1][i + k + (j * k)], temp->m[2][i + k + (j * k)],
		temp->m[0][i + 1 - k + (j * k)], temp->m[1][i + 1 - k + (j * k)], temp->m[2][i + 1 - k + (j * k)]);
    add_polygon(points,
		temp->m[0][i + 1 - k + (j * k)], temp->m[1][i + 1 - k + (j * k)], temp->m[2][i + 1 - k + (j * k)],
		temp->m[0][i + k + (j * k)], temp->m[1][i + k + (j * k)], temp->m[2][i + k + (j * k)],
		temp->m[0][i + 1 + (j * k)], temp->m[1][i + 1 + (j * k)], temp->m[2][i + 1 + (j * k)]);
  }

}


void render_polygonal_sphere(struct matrix *points, double r,
			   double offx, double offy, double offz, double step){
  struct matrix * temp = new_matrix(4, 1);
  generate_sphere_mesh(temp, r, offx, offy, offz, step);
  // printf("R = %3.3f, offx = %3.3f, offy = %3.3f, offz = %3.3f\n", r, offx, offy, offz);
  int i, j;
  double k1 = 1.0/step;
  int k = (int)k1;
  //printf("K = %d\n", k);
  for(j = 0; j < k/2; j ++){
    for(i = 0; i < k - 1; i++){
      if(i < k/4 || i >= 3*k/4){
	add_polygon(points,
		    temp->m[0][i + (j * k)], temp->m[1][i + (j * k)], temp->m[2][i + (j * k)],
		    temp->m[0][i + k + (j * k)], temp->m[1][i + k + (j * k)], temp->m[2][i + k + (j * k)],
		    temp->m[0][i + 1 + (j * k)], temp->m[1][i + 1 + (j * k)], temp->m[2][i + 1 + (j * k)]);
	add_polygon(points,
		    temp->m[0][i + k + 1 + (j * k)], temp->m[1][i + k + 1 + (j * k)], temp->m[2][i + k + 1 + (j * k)],
		    temp->m[0][i + 1 + (j * k)], temp->m[1][i + 1 + (j * k)], temp->m[2][i + 1 + (j * k)],
		    temp->m[0][i + k + (j * k)], temp->m[1][i + k + (j * k)], temp->m[2][i + k + (j * k)]);
      }
      else{
	add_polygon(points,
		    temp->m[0][i + (j * k)], temp->m[1][i + (j * k)], temp->m[2][i + (j * k)],
		    temp->m[0][i + 1 + (j * k)], temp->m[1][i + 1 + (j * k)], temp->m[2][i + 1 + (j * k)],
		    temp->m[0][i + k + 1 + (j * k)], temp->m[1][i + k + 1 + (j * k)], temp->m[2][i + k + 1 + (j * k)]);

	add_polygon(points,
		    temp->m[0][i + k + 1 + (j * k)], temp->m[1][i + k + 1 + (j * k)], temp->m[2][i + k + 1 + (j * k)],
		    temp->m[0][i + k + (j * k)], temp->m[1][i + k + (j * k)], temp->m[2][i + k + (j * k)],
		    temp->m[0][i + (j * k)], temp->m[1][i + (j * k)], temp->m[2][i + (j * k)]);
      }
    }
    if(i < k/4 || i >= 3*k/4){
      add_polygon(points,
		  temp->m[0][i + (j * k)], temp->m[1][i + (j * k)], temp->m[2][i + (j * k)],
		  temp->m[0][i + k + (j * k)], temp->m[1][i + k + (j * k)], temp->m[2][i + k + (j * k)],
		  temp->m[0][i + 1 - k + (j * k)], temp->m[1][i + 1 - k + (j * k)], temp->m[2][i + 1 - k + (j * k)]);
      add_polygon(points,
		  temp->m[0][i + 1 + (j * k)], temp->m[1][i + 1 + (j * k)], temp->m[2][i + 1 + (j * k)],
		  temp->m[0][i + 1 - k + (j * k)], temp->m[1][i + 1 - k + (j * k)], temp->m[2][i + 1 - k + (j * k)],
		  temp->m[0][i + k + (j * k)], temp->m[1][i + k + (j * k)], temp->m[2][i + k + (j * k)]);
    }
  }
}


void render_sphere_mesh(struct matrix *points, double r, double offx, double offy, double offz, double step){
  struct matrix *temp = new_matrix(4, 1);
  generate_sphere_mesh(temp, r, offx, offy, offz, step);
  double d = 1.0 / step;
  int i, j, k = (int)d;
  //Horixontal Lines
  for(i = 0; i < k; i++)
    for(j = 0; j < k - 1; j++){
      //Usual Case
      if(i < k - 1)
	add_edge(points, temp -> m[0][i * k + j],  temp -> m[1][i * k + j],  temp -> m[2][i * k + j],
		 temp -> m[0][(i + 1) * k + j],  temp -> m[1][(i + 1) * k + j],  temp -> m[2][(i + 1) * k + j]);
      //Last Line Case
      else
	add_edge(points, temp -> m[0][i * k + j], temp -> m[1][i * k + j], temp -> m[2][i * k + j],
		 temp -> m[0][j], temp -> m[1][j], temp -> m[2][j]);
    }
  //Vertical Lines
  for(i = 0; i < k / 2; i++){
    for(j = 0; j < k - 1; j++)
      //Usual Case
      add_edge(points, temp -> m[0][i * k + j],  temp -> m[1][i * k + j],  temp -> m[2][i * k + j],
	       temp -> m[0][i * k + j + 1],  temp -> m[1][i * k + j + 1],  temp -> m[2][i * k + j + 1]);
    //Last Line Case
    add_edge(points, temp -> m[0][(i + 1) * k - 1], temp -> m[1][(i + 1) * k - 1], temp -> m[2][(i + 1) * k - 1],
	     temp -> m[0][i * k], temp -> m[1][i * k], temp -> m[2][i * k]);
  }
  free_matrix(temp);
}


void generate_sphere_mesh(struct matrix *points, double r, double offx, double offy, double offz, double step){
  double d, e;
  for(d = 0.0; d < 0.9999999999; d += step)
    for(e = 0.0; e < 0.9999999999; e += step)
      add_point(points, r * cos(2 * M_PI * d) * cos(2 * M_PI * e) + offx, r * sin(2 * M_PI * e) + offy, -r * cos(2 * M_PI * e) * sin(2 * M_PI * d) + offz);
}


/*======== void add_point() ==========
Inputs:   struct matrix * points
         int x
         int y
         int z 
Returns: 
adds point (x, y, z) to points and increment points.lastcol
if points is full, should call grow on points
====================*/
void add_point(struct matrix * points, int x, int y, int z){
  if(points -> lastcol == points -> cols)
    grow_matrix(points, points -> cols + 1);
  points -> m[0][points -> lastcol] = x;
  points -> m[1][points -> lastcol] = y;
  points -> m[2][points -> lastcol] = z;
  points -> m[3][points -> lastcol] = 1;
  (points -> lastcol)++;
}


/*======== void draw_lines() ==========
Inputs:   struct matrix * points
         screen s
         color c 
Returns: 
Go through points 2 at a time and call draw_line to add that line
to the screen
====================*/
void draw_lines(struct matrix * points, screen s, color c){
  int i, j = 0;
  for(i = 0; i + 1 <= points -> lastcol; i += 2){
    if(j % 3 == 0){
      c.red = 0;
      c.blue = 0;
      c.green = 200;
    }
    else if(j % 3 == 1){
      c.red = 0;
      c.blue = 200;
      c.green = 0;
    }
    else{
      c.red = 200;
      c.blue = 0;
      c.green = 0;
    }
    draw_line((int)points -> m[0][i], (int)points -> m[1][i], (int)points -> m[0][i + 1], (int)points -> m[1][i + 1], s, c);
    j++;
  }
}


void draw_polygons(struct matrix *points, screen s, color c, struct constants *constant, struct zbuff *buff){  
  int i = 0, j = 0;
  //printf("~~~~~~~~~\n");
  //printf("Vertices: (%d, %d, %d), (%d, %d, %d), (%d, %d, %d)\n", (int)points -> m[0][0], (int)points -> m[1][0], (int)points -> m[2][0], (int)points -> m[0][1], (int)points -> m[1][1], (int)points -> m[2][1], (int)points -> m[0][2], (int)points -> m[1][2], (int)points -> m[2][2]);
  points = cull(points);
  for(i = 0; i + 2 < points -> lastcol; i += 3){
    //printf("Entering For Loop\n");
    /*
      if(j % 6 == 0){
      c.red = 0;
      c.blue = 50;
      c.green = 150;
      }
      else if(j % 6 == 1){
      c.red = 50;
      c.blue = 150;
      c.green = 0;
      }
      else if(j % 6 == 2){
      c.red = 150;
      c.blue = 0;
      c.green = 50;
      }
      else if(j % 6 == 3){
      c.red = 0;
      c.blue = 150;
      c.green = 50;
      }
      else if(j % 6 == 4){
      c.red = 50;
      c.blue = 0;
      c.green = 150;
      }
      else{
      c.red = 150;
      c.blue = 50;
      c.green = 0;
      }
    */
    //printf("Color Set\n");
    c = illumination(
		     (int)points -> m[0][i], (int)points -> m[1][i], (int)points -> m[2][i],
		     (int)points -> m[0][i + 1], (int)points -> m[1][i + 1], (int)points -> m[2][i + 1],
		     (int)points -> m[0][i + 2], (int)points -> m[1][i + 2], (int)points -> m[2][i + 2],
		     constant -> r[0], constant -> g[0], constant -> b[0],
		     constant -> r[1], constant -> g[1], constant -> b[1],
		     constant -> r[2], constant -> g[2], constant -> b[2],
		     constant -> red, constant -> green, constant -> blue);
    draw_polygon(buff,
		 (int)points -> m[0][i], (int)points -> m[1][i], (int)points -> m[2][i],
		 (int)points -> m[0][i + 1], (int)points -> m[1][i + 1], (int)points -> m[2][i + 1],
		 (int)points -> m[0][i + 2], (int)points -> m[1][i + 2], (int)points -> m[2][i + 2], c);
    //printf("Polygon Drawn\n");
    j++;
  }
  for(i = 0; i < XRES; i++)
    for(j = 0; j < YRES; j++)
      plot(s, buff -> arr[i][j].c, i, j);
  //printf("\n");
}


  /*======== void add_edge() ==========
    Inputs:   struct matrix * points
    int x0, int y0, int z0, int x1, int y1, int z1
    Returns: 
    add the line connecting (x0, y0, z0) to (x1, y1, z1) to points
    should call add_point
    ====================*/
  void add_edge(struct matrix * points, 
		int x0, int y0, int z0, 
		int x1, int y1, int z1){
    add_point(points, x0, y0, z0);
    add_point(points, x1, y1, z1);
  }


  void add_polygon(struct matrix *points, int x0, int y0, int z0, int x1, int y1, int z1, int x2, int y2, int z2){
    add_point(points, x0, y0, z0);
    add_point(points, x1, y1, z1);
    add_point(points, x2, y2, z2);
  }


  /*======== void draw_line() ==========
    Inputs:  int x0
    int y0
    int x1
    int y1
    screen s
    color c 
    Returns: 
    draws the line connecting (x0, y0) to (x1, y1) to screen s using color c
    ====================*/

void draw_line(int x0, int y0, int x1, int y1, screen s, color c){
 
  int x, y, d, dx, dy;

  x = x0;
  y = y0;
  
  //swap points so we're always draing left to right
  if ( x0 > x1 ) {
    x = x1;
    y = y1;
    x1 = x0;
    y1 = y0;
  }

  //need to know dx and dy for this version
  dx = x1 - x;
  dy = y1 - y;

  //positive slope: Octants 1, 2 (5 and 6)
  if ( dy > 0 ) {

    //slope < 1: Octant 1 (5)
    if ( dx > dy ) {
      d = 2 * dy - dx;
  
      while ( x < x1 ) {
	plot(s, c, x, y);

	if ( d < 0 ) {
	  x = x + 1;
	  d = d + dy;
	}
	else {
	  x = x + 1;
	  y = y + 1;
	  d = d + dy - dx;
	}
      }
    }

    //slope > 1: Octant 2 (6)
    else {
      d = dy - 2 * dx;
      while ( y < y1 ) {

	plot(s, c, x, y );
	if ( d > 0 ) {
	  y = y + 1;
	  d = d - dx;
	}
	else {
	  y = y + 1;
	  x = x + 1;
	  d = d + dy - dx;
	}
      }
    }
  }

  //negative slope: Octants 7, 8 (3 and 4)
  else { 

    //slope > -1: Octant 8 (4)
    if ( dx > abs(dy) ) {
      d = 2 * dy + dx;
  
      while ( x < x1 ) {

	plot(s, c, x, y);

	if ( d > 0 ) {
	  x = x + 1;
	  d = d + dy;
	}
	else {
	  x = x + 1;
	  y = y - 1;
	  d = d + dy + dx;
	}
      }
    }

    //slope < -1: Octant 7 (3)
    else {

      d = dy + 2 * dx;
      while ( y >= y1 ) {
	
	plot(s, c, x, y );
	if ( d < 0 ) {
	  y = y - 1;
	  d = d + dx;
	}
	else {
	  y = y - 1;
	  x = x + 1;
	  d = d + dy + dx;
	}
      }
    }
  }
}


color calc_ambient(double kr, double kg, double kb){
  double ar, ag, ab;
  int i;
  color c;
  for(i = 0; i < lastsym; i++)
    if(symtab[i].type == 4 && !strcmp(symtab[i].name, "ambience")){
      ar = symtab[i].s.l -> c[0];
      ag = symtab[i].s.l -> c[1];
      ab = symtab[i].s.l -> c[2];
      break;
    }
  c.red = ar * kr;
  c.green = ag * kg;
  c.blue = ab * kb;
  return c;
}


color calc_diffuse(double x0, double y0, double z0, double x1, double y1, double z1, double x2, double y2, double z2, double kr, double kg, double kb){
  int i, x, y, z;
  double angle, dr, dg, db;
  color c;
  struct vector *a = find_vector(x0, y0, z0, x1, y1, z1), *b = find_vector(x1, y1, z1, x2, y2, z2), *normal, *light;
  normalize(a);
  normalize(b);
  normal = cross(a, b);
  normalize(normal);
  for(i = 0; i < lastsym; i++)
    if(symtab[i].type == 4 && strcmp(symtab[i].name, "ambience")){
      dr = symtab[i].s.l -> c[0];
      dg = symtab[i].s.l -> c[1];
      db = symtab[i].s.l -> c[2];
      x = symtab[i].s.l -> l[0];
      y = symtab[i].s.l -> l[1];
      z = symtab[i].s.l -> l[2];
      break;
    }
  light = find_vector(x, y, z, (x0 + x1 + x2) / 3, (y0 + y1 + y2) / 3, (z0 + z1 + z2) / 3);
  normalize(light);
  angle = dot(normal, light);
  c.red= -1 * dr * kr * angle;
  c.green = -1 * dg * kg * angle;
  c.blue = -1 * db * kb * angle;
  return c;
}


color calc_specular(double x0, double y0, double z0, double x1, double y1, double z1, double x2, double y2, double z2, double kr, double kg, double kb){
  int i, x, y, z;
  double angle, sr, sg, sb;
  color c;
  struct vector *a = find_vector(x0, y0, z0, x1, y1, z1), *b = find_vector(x1, y1, z1, x2, y2, z2), *normal, *light, *temp, *view = new_vector(0, 0, -1);
  normalize(a);
  normalize(b);
  normal = cross(a, b);
  normalize(normal);
  for(i = 0; i < lastsym; i++)
    if(symtab[i].type == 4 && strcmp(symtab[i].name, "ambience")){
      sr = symtab[i].s.l -> c[0];
      sg = symtab[i].s.l -> c[1];
      sb = symtab[i].s.l -> c[2];
      x = symtab[i].s.l -> l[0];
      y = symtab[i].s.l -> l[1];
      z = symtab[i].s.l -> l[2];
      break;
    }
  light = find_vector(x, y, z, (x0 + x1 + x2) / 3, (y0 + y1 + y2) / 3, (z0 + z1 + z2) / 3);
  normalize(light);
  angle = 2 * dot(normal, light);
  temp = vs_mult(angle, normal);
  temp = subtraction(temp, light);
  angle = pow(dot(temp, view), 2);
  c.red = sr * kr * angle;
  c.green = sg * kg * angle;
  c.blue = sb * kb * angle;
  return c;
}


color illumination(double x0, double y0, double z0, double x1, double y1, double z1, double x2, double y2, double z2, double ar, double ag, double ab, double dr, double dg, double db, double sr, double sg, double sb, double kr, double kg, double kb){
  color c, a = calc_ambient(ar, ag, ab), d = calc_diffuse(x0, y0, z0, x1, y1, z1, x2, y2, z2, dr, dg, db), s = calc_specular(x0, y0, z0, x1, y1, z1, x2, y2, z2, sr, sg, sb);
  //printf("d.r = %d, a.r = %d, s.r = %d, d.g = %d, a.g = %d, s.g = %d, d.b = %d, a.b = %d, s.b = %d\n", d.red, a.red, s.red, d.green, a.green, s.green, d.blue, a.blue, s.blue);
  c.red =  (s.red) + (a.red) + (d.red) + (int)kr;
  c.green = (s.green) + (a.green) + (d.green) + (int)kg;
  c.blue = (s.blue) + (a.blue) + (d.blue) + (int)kb;
  //printf("Red: %d, Green: %d, Blue: %d\n", c.red, c.green, c.blue);
  return c;
}
