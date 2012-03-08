#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "vector.h"


struct vector *new_vector(double x, double y, double z){
  struct vector *ans = (struct vector *)malloc(sizeof(struct vector));
  ans -> x = x;
  ans -> y = y;
  ans -> z = z;
  return ans;
}


void normalize(struct vector *v){
  double magnitude = sqrt((v -> x * v -> x) + (v -> y * v -> y) + (v -> z * v -> z));
  v -> x = v -> x / magnitude;
  v -> y = v -> y / magnitude;
  v -> z = v -> z / magnitude;
}


double dot(struct vector *a, struct vector *b){
  return (a -> x * b -> x) + (a -> y * b -> y) + (a -> z * b -> z);
}


struct vector *cross(struct vector *a, struct vector *b){
  struct vector *ans = new_vector(((a -> y * b -> z) - (a -> z * b -> y)), ((a -> z * b -> x) - (a -> x * b -> z)), ((a -> x * b -> y) - (a -> y * b -> x)));
  return ans;
}


struct vector *find_vector(double x1, double y1, double z1, double x0, double y0, double z0){
  struct vector *ans = new_vector(x0 - x1, y0 - y1, z0 - z1);
  return ans;
}

struct vector *vs_mult(double d, struct vector *v){
  v -> x *= d;
  v -> y *= d;
  v -> z *= d;
  return v;
}

struct vector *subtraction(struct vector *a, struct vector *b){
  struct vector *difference = new_vector((a -> x) - (b -> x), (a -> y) - (b -> y), (a -> z) - (b -> z));
  return difference;
}
