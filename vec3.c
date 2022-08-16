#include <stdio.h>
#include <math.h>
#include "vec3.h"

void vec3_set(double x, double y, double z, vec3 *result)
{
  result->x = x;
  result->y = y;
  result->z = z;
}

void vec3_copy(vec3 *v, vec3 *result)
{
  result->x = v->x;
  result->y = v->y;
  result->z = v->z;
}

void vec3_add(vec3 *v, vec3 *w, vec3 *result)
{
  result->x = v->x + w->x;
  result->y = v->y + w->y;
  result->z = v->z + w->z;
}

void vec3_sub(vec3 *v, vec3 *w, vec3 *result)
{
  result->x = v->x - w->x;
  result->y = v->y - w->y;
  result->z = v->z - w->z;
}

void vec3_mul(vec3 *v, vec3 *w, vec3 *result)
{
  result->x = v->x * w->x;
  result->y = v->y * w->y;
  result->z = v->z * w->z;
}

void vec3_div(vec3 *v, vec3 *w, vec3 *result)
{
  result->x = v->x / w->x;
  result->y = v->y / w->y;
  result->z = v->z / w->z;
}

void vec3_mulscalar(vec3 *v, double t, vec3 *result)
{
  result->x = v->x * t;
  result->y = v->y * t;
  result->z = v->z * t;
}

void vec3_divscalar(vec3 *v, double t, vec3 *result)
{
  result->x = v->x / t;
  result->y = v->y / t;
  result->z = v->z / t;
}

double vec3_dot(vec3 *v, vec3 *w)
{
  double result = v->x * w->x + v->y * w->y + v->z * w->z;
  return result;
}

double vec3_len_squared(vec3 *v)
{
  double result = vec3_dot(v, v);
  return result;
}

double vec3_len(vec3 *v)
{
  double result = sqrt(vec3_len_squared(v));
  return result;
}

void vec3_unit(vec3 *v, vec3 *result)
{
  double len = vec3_len(v);
  vec3_divscalar(v, len, result);
}

void vec3_cross(vec3 *v, vec3 *w, vec3 *result)
{
  result->x = v->y * w->z - v->z * w->y;
  result->y = v->z * w->x - v->x * w->z;
  result->z = v->x * w->y - v->y * w->x;
}

void colour_print(FILE *os, colour *c)
{
  int ir = (int)(255.999 * c->x);
  int ig = (int)(255.999 * c->y);
  int ib = (int)(255.999 * c->z);

  fprintf(os, "%d %d %d\n", ir, ig, ib);
}
