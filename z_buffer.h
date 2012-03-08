#include "ml6.h"

struct zval{
  color c;
  double z;
};

struct zbuff{
  struct zval arr[XRES][YRES];
};
