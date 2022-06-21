#include <stdio.h>
#include "vec3.h"

void vec3_set(double x, double y, double z, struct vec3 *result)
{
  result->x = x;
  result->y = y;
  result->z = z;
}
