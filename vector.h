struct vector{
  double x;
  double y;
  double z;
};

struct vector *new_vector(double x, double y, double z);
void normalize(struct vector *v);
double dot(struct vector *a, struct vector *b);
struct vector *cross(struct vector *a, struct vector *b);
struct vector *find_vector(double x1, double y1, double z1, double x0, double y0, double z0);
struct vector *vs_mult(double d, struct vector *v);
struct vector *subtraction(struct vector *a, struct vector *b);
