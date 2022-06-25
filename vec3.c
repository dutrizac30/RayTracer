#include <stdio.h>
#include <math.h>
#include "vec3.h"

void vec3_set(double x, double y, double z, vec3 *result)
{
  result->x = x;
  result->y = y;
  result->z = z;
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
  return v->x * w->x + v->y * w->y + v->z * w->z;
}

double vec3_length_squared(vec3 *v)
{
  return vec3_dot(v, v);
}

double vec3_length(vec3 *v)
{
  return sqrt(vec3_length_squared(v));
}

void vec3_unit(vec3 *v, vec3 *r)
{
  vec3_divscalar(v, vec3_length(v), r);
}

void vec3_cross(vec3 *v, vec3 *w, vec3 *result)
{
  result->x = v->y * w->z - v->z * w->y;
  result->y = v->x * w->z - v->z * w->x;
  result->z = v->x * w->y - v->y * w->x;
}
